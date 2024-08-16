ifeq ($(CC),cc)
    CC = gcc
endif

CFLAGS = -std=c17 -g -D_POSIX_C_SOURCE=200809L -D_XOPEN_SOURCE=700 -D_DARWIN_C_SOURCE -D_DEFAULT_SOURCE -D__BSD_VISIBLE \
		 -Wall -Wextra -Werror -pedantic -Wconversion -Wshadow -Wformat=2 -Winit-self -Wswitch-default \
         -Wswitch-enum -Wfloat-equal -Wcast-align -Wpointer-arith -Wmissing-prototypes -Wstrict-prototypes \
         -Wundef -Wstrict-overflow=5 -Wwrite-strings -Wredundant-decls -Winline -Wvla -Wdouble-promotion \
         -Wdeclaration-after-statement
SANITIZERS = -fsanitize=address -fsanitize=undefined -fsanitize=leak
SUPPORTED_SANITIZERS =
CHECKER_REPORT_FILE = cppcheck-report.txt
REPORT_DIR = scan-results

# Source and binary definitions for the new set of files
INITIALIZATION_SOURCES = initialization.c
INITIALIZATION_BINARY = initialization
INVALID_MEMORY_ACCESS_SOURCES = invalid-memory-access.c
INVALID_MEMORY_ACCESS_BINARY = invalid-memory-access
MEMORY_LEAK_SOURCES = memory-leak.c
MEMORY_LEAK_BINARY = memory-leak
MISSING_FREE_CONDITIONAL_SOURCES = missing-free-conditional.c
MISSING_FREE_CONDITIONAL_BINARY = missing-free-conditional
MISSING_FREE_LOOP_SOURCES = missing-free-loop.c
MISSING_FREE_LOOP_BINARY = missing-free-loop
NULL_CHECK_SOURCES = null-check.c
NULL_CHECK_BINARY = null-check
USE_AFTER_FREE_SOURCES = use-after-free.c
USE_AFTER_FREE_BINARY = use-after-free

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
all: clang-format $(INITIALIZATION_BINARY) $(INVALID_MEMORY_ACCESS_BINARY) $(MEMORY_LEAK_BINARY) \
     $(MISSING_FREE_CONDITIONAL_BINARY) $(MISSING_FREE_LOOP_BINARY) $(NULL_CHECK_BINARY) $(USE_AFTER_FREE_BINARY) \
     analyze clang-tidy cppcheck

# Build rules for each binary
$(INITIALIZATION_BINARY): $(INITIALIZATION_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(INITIALIZATION_BINARY) $(INITIALIZATION_SOURCES)

$(INVALID_MEMORY_ACCESS_BINARY): $(INVALID_MEMORY_ACCESS_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(INVALID_MEMORY_ACCESS_BINARY) $(INVALID_MEMORY_ACCESS_SOURCES)

$(MEMORY_LEAK_BINARY): $(MEMORY_LEAK_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(MEMORY_LEAK_BINARY) $(MEMORY_LEAK_SOURCES)

$(MISSING_FREE_CONDITIONAL_BINARY): $(MISSING_FREE_CONDITIONAL_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(MISSING_FREE_CONDITIONAL_BINARY) $(MISSING_FREE_CONDITIONAL_SOURCES)

$(MISSING_FREE_LOOP_BINARY): $(MISSING_FREE_LOOP_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(MISSING_FREE_LOOP_BINARY) $(MISSING_FREE_LOOP_SOURCES)

$(NULL_CHECK_BINARY): $(NULL_CHECK_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(NULL_CHECK_BINARY) $(NULL_CHECK_SOURCES)

$(USE_AFTER_FREE_BINARY): $(USE_AFTER_FREE_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(USE_AFTER_FREE_BINARY) $(USE_AFTER_FREE_SOURCES)

# Analyze rule to analyze all sources
analyze:
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(INITIALIZATION_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(INVALID_MEMORY_ACCESS_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(MEMORY_LEAK_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(MISSING_FREE_CONDITIONAL_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(MISSING_FREE_LOOP_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(NULL_CHECK_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(USE_AFTER_FREE_SOURCES) -c

# Clang-tidy rule to lint all sources
clang-tidy:
	clang-tidy -quiet --warnings-as-errors=* -checks='*,-cert-err33-c,-clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling,-readability-identifier-length,-llvmlibc-restrict-system-libc-headers,-cppcoreguidelines-init-variables,-altera-unroll-loops,-llvm-header-guard,-cppcoreguidelines-avoid-magic-numbers,-readability-magic-numbers,-misc-unused-parameters,-android-cloexec-dup,-android-cloexec-open,-android-cloexec-creat,-android-cloexec-fopen,-bugprone-easily-swappable-parameters' \
	$(INITIALIZATION_SOURCES) $(INVALID_MEMORY_ACCESS_SOURCES) $(MEMORY_LEAK_SOURCES) $(MISSING_FREE_CONDITIONAL_SOURCES) $(MISSING_FREE_LOOP_SOURCES) $(NULL_CHECK_SOURCES) $(USE_AFTER_FREE_SOURCES) \
	-- $(CFLAGS)

# Cppcheck rule to perform static analysis on all sources
cppcheck:
	cppcheck --enable=all --error-exitcode=1 --inconclusive --check-level=exhaustive --inline-suppr --suppress=missingIncludeSystem --checkers-report=$(CHECKER_REPORT_FILE) --quiet \
	$(INITIALIZATION_SOURCES) $(INVALID_MEMORY_ACCESS_SOURCES) $(MEMORY_LEAK_SOURCES) \
	$(MISSING_FREE_CONDITIONAL_SOURCES) $(MISSING_FREE_LOOP_SOURCES) $(NULL_CHECK_SOURCES) $(USE_AFTER_FREE_SOURCES)

clang-format:
	clang-format -i -- $(INITIALIZATION_SOURCES) $(INVALID_MEMORY_ACCESS_SOURCES) $(MEMORY_LEAK_SOURCES) \
	$(MISSING_FREE_CONDITIONAL_SOURCES) $(MISSING_FREE_LOOP_SOURCES) $(NULL_CHECK_SOURCES) $(USE_AFTER_FREE_SOURCES)

# Clean rule to remove binaries and reports
clean:
	rm -f $(INITIALIZATION_BINARY) $(INVALID_MEMORY_ACCESS_BINARY) $(MEMORY_LEAK_BINARY) \
	$(MISSING_FREE_CONDITIONAL_BINARY) $(MISSING_FREE_LOOP_BINARY) $(NULL_CHECK_BINARY) $(USE_AFTER_FREE_BINARY)
	rm -f $(CHECKER_REPORT_FILE)
	rm -rf $(REPORT_DIR)
	find . -name '*.plist' -delete
	find . -name '*.o' -delete
