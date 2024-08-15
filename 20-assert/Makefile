ifeq ($(CC),cc)
    CC = gcc
endif

CFLAGS = -std=c17 -Wall -Wextra -Werror -pedantic -Wconversion -Wshadow -Wformat=2 -Winit-self -Wswitch-default \
         -Wswitch-enum -Wfloat-equal -Wcast-align -Wpointer-arith -Wmissing-prototypes -Wstrict-prototypes \
         -Wundef -Wstrict-overflow=5 -Wwrite-strings -Wredundant-decls -Winline -Wvla -Wdouble-promotion \
         -Wdeclaration-after-statement
SANITIZERS = -fsanitize=address -fsanitize=undefined -fsanitize=leak
SUPPORTED_SANITIZERS =
CHECKER_REPORT_FILE = cppcheck-report.txt
REPORT_DIR = scan-results

# Source and binary definitions for the new set of files
ASSERT_SOURCES = assert.c
ASSERT_BINARY = assert
PRECONDITIONS_SOURCES = preconditions.c
PRECONDITIONS_BINARY = preconditions
POSTCONDITIONS_SOURCES = postconditions.c
POSTCONDITIONS_BINARY = postconditions
INVARIANT_SOURCES = invariant.c
INVARIANT_BINARY = invariant
ERROR_HANDLING_SOURCES = error-handling.c
ERROR_HANDLING_BINARY = error-handling

# Attempt to compile with each sanitizer to check support
CHECK_SANITIZER = \
    $(shell echo "int main(){}" > sanitizer_check.c; \
    if $(CC) $(1) sanitizer_check.c -o /dev/null > /dev/null 2>&1; then echo $(1); fi; \
    rm -f sanitizer_check.c)

SUPPORTED_SANITIZERS +=$(call CHECK_SANITIZER,-fsanitize=address)
SUPPORTED_SANITIZERS +=$(call CHECK_SANITIZER,-fsanitize=undefined)
SUPPORTED_SANITIZERS +=$(call CHECK_SANITIZER,-fsanitize=leak)

ifeq ($(CC), gcc)
	ANALYSIS_FLAGS = -fanalyzer
	ANALYZER =
	ANALYZER_FLAGS =
else ifeq ($(CC), clang)
    CFLAGS += -Wdocumentation -Wshorten-64-to-32 -Wconstant-conversion -Wnullable-to-nonnull-conversion
	ANALYSIS_FLAGS = --analyze
	ANALYZER = scan-build
 	ANALYZER_FLAGS = -disable-checker unix.Malloc -disable-checker deadcode.DeadStores -disable-checker core.StackAddressEscape -plist-html -o $(REPORT_DIR) --status-bugs
endif

# All rule to build all binaries, analyze, and run cppcheck
all: clang-format $(ASSERT_BINARY) $(PRECONDITIONS_BINARY) $(POSTCONDITIONS_BINARY) $(INVARIANT_BINARY) $(ERROR_HANDLING_BINARY) analyze clang-tidy cppcheck

# Build rules for each binary
$(ASSERT_BINARY): $(ASSERT_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(ASSERT_BINARY) $(ASSERT_SOURCES)

$(PRECONDITIONS_BINARY): $(PRECONDITIONS_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(PRECONDITIONS_BINARY) $(PRECONDITIONS_SOURCES)

$(POSTCONDITIONS_BINARY): $(POSTCONDITIONS_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(POSTCONDITIONS_BINARY) $(POSTCONDITIONS_SOURCES)

$(INVARIANT_BINARY): $(INVARIANT_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(INVARIANT_BINARY) $(INVARIANT_SOURCES)

$(ERROR_HANDLING_BINARY): $(ERROR_HANDLING_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(ERROR_HANDLING_BINARY) $(ERROR_HANDLING_SOURCES)

# Analyze rule to analyze all sources
analyze:
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(ASSERT_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(PRECONDITIONS_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(POSTCONDITIONS_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(INVARIANT_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(ERROR_HANDLING_SOURCES) -c

# Clang-tidy rule to lint all sources
clang-tidy:
	clang-tidy -quiet --warnings-as-errors=* -checks='*,-cert-err33-c,-clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling,-readability-identifier-length,-llvmlibc-restrict-system-libc-headers,-cppcoreguidelines-init-variables,-altera-unroll-loops,-llvm-header-guard,-cppcoreguidelines-avoid-magic-numbers,-readability-magic-numbers,-misc-unused-parameters,-android-cloexec-dup' \
    $(ASSERT_SOURCES) $(PRECONDITIONS_SOURCES) $(POSTCONDITIONS_SOURCES) $(INVARIANT_SOURCES) $(ERROR_HANDLING_SOURCES) \
    -- $(CFLAGS)

# Cppcheck rule to perform static analysis on all sources
cppcheck:
	cppcheck --enable=all --error-exitcode=1 --inconclusive --check-level=exhaustive --inline-suppr --suppress=missingIncludeSystem --checkers-report=$(CHECKER_REPORT_FILE) --quiet --quiet \
	$(ASSERT_SOURCES) $(PRECONDITIONS_SOURCES) $(POSTCONDITIONS_SOURCES) $(INVARIANT_SOURCES) $(ERROR_HANDLING_SOURCES)

clang-format:
	clang-format -i -- $(ASSERT_SOURCES) $(PRECONDITIONS_SOURCES) $(POSTCONDITIONS_SOURCES) $(INVARIANT_SOURCES) $(ERROR_HANDLING_SOURCES)

# Clean rule to remove binaries and reports
clean:
	rm -f $(ASSERT_BINARY) $(PRECONDITIONS_BINARY) $(POSTCONDITIONS_BINARY) $(INVARIANT_BINARY) $(ERROR_HANDLING_BINARY)
	rm -f $(CHECKER_REPORT_FILE)
	rm -rf $(REPORT_DIR)
	find . -name '*.plist' -delete
	find . -name '*.o' -delete
