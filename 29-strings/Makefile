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
ARRAY_DECLARATION_SOURCES = array-declaration.c
ARRAY_DECLARATION_BINARY = array-declaration
HAS_NULL_BYTE_SOURCES = has-null-byte.c
HAS_NULL_BYTE_BINARY = has-null-byte
MISSING_NULL_BYTE_SOURCES = missing-null-byte.c
MISSING_NULL_BYTE_BINARY = missing-null-byte
ITERATION_SOURCES = iteration.c
ITERATION_BINARY = iteration
READ_ONLY_SOURCES = read-only.c
READ_ONLY_BINARY = read-only

# Attempt to compile with each sanitizer to check support
CHECK_SANITIZER = \
    $(shell echo "int main(){}" > sanitizer_check.c; \
    if $(CC) $(1) sanitizer_check.c -o /dev/null > /dev/null 2>&1; then echo $(1); fi; \
    rm -f sanitizer_check.c)

# Loop over the SANITIZERS and add supported ones to SUPPORTED_SANITIZERS
define LOOP_SANITIZERS
    $(foreach sanitizer,$(SANITIZERS),\
        $(eval SUPPORTED_SANITIZERS += $(call CHECK_SANITIZER,$(sanitizer))))
endef

$(eval $(LOOP_SANITIZERS))

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
all: clang-format $(ARRAY_DECLARATION_BINARY) $(HAS_NULL_BYTE_BINARY) $(MISSING_NULL_BYTE_BINARY) $(ITERATION_BINARY) $(READ_ONLY_BINARY) analyze clang-tidy cppcheck

# Build rules for each binary
$(ARRAY_DECLARATION_BINARY): $(ARRAY_DECLARATION_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(ARRAY_DECLARATION_BINARY) $(ARRAY_DECLARATION_SOURCES)

$(HAS_NULL_BYTE_BINARY): $(HAS_NULL_BYTE_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(HAS_NULL_BYTE_BINARY) $(HAS_NULL_BYTE_SOURCES)

$(MISSING_NULL_BYTE_BINARY): $(MISSING_NULL_BYTE_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(MISSING_NULL_BYTE_BINARY) $(MISSING_NULL_BYTE_SOURCES)

$(ITERATION_BINARY): $(ITERATION_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(ITERATION_BINARY) $(ITERATION_SOURCES)

$(READ_ONLY_BINARY): $(READ_ONLY_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(READ_ONLY_BINARY) $(READ_ONLY_SOURCES)

# Analyze rule to analyze all sources
analyze:
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(ARRAY_DECLARATION_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(HAS_NULL_BYTE_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(MISSING_NULL_BYTE_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(ITERATION_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(READ_ONLY_SOURCES) -c

# Clang-tidy rule to lint all sources
clang-tidy:
	clang-tidy -quiet --warnings-as-errors=* -checks='*,-cert-err33-c,-clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling,-readability-identifier-length,-llvmlibc-restrict-system-libc-headers,-cppcoreguidelines-init-variables,-altera-unroll-loops,-llvm-header-guard,-cppcoreguidelines-avoid-magic-numbers,-readability-magic-numbers,-misc-unused-parameters,-android-cloexec-dup,-android-cloexec-open,-android-cloexec-creat,-android-cloexec-fopen,-bugprone-easily-swappable-parameters,-altera-id-dependent-backward-branch,-altera-struct-pack-align' \
	$(ARRAY_DECLARATION_SOURCES) $(HAS_NULL_BYTE_SOURCES) $(MISSING_NULL_BYTE_SOURCES) $(ITERATION_SOURCES) $(READ_ONLY_SOURCES) \
	-- $(CFLAGS)

# Cppcheck rule to perform static analysis on all sources
cppcheck:
	cppcheck --enable=all --error-exitcode=1 --inconclusive --check-level=exhaustive --inline-suppr --suppress=missingIncludeSystem --checkers-report=$(CHECKER_REPORT_FILE) --quiet \
	$(ARRAY_DECLARATION_SOURCES) $(HAS_NULL_BYTE_SOURCES) $(MISSING_NULL_BYTE_SOURCES) $(ITERATION_SOURCES) $(READ_ONLY_SOURCES)

clang-format:
	clang-format -i -- $(ARRAY_DECLARATION_SOURCES) $(HAS_NULL_BYTE_SOURCES) $(MISSING_NULL_BYTE_SOURCES) $(ITERATION_SOURCES) $(READ_ONLY_SOURCES)

# Clean rule to remove binaries and reports
clean:
	rm -f $(ARRAY_DECLARATION_BINARY) $(HAS_NULL_BYTE_BINARY) $(MISSING_NULL_BYTE_BINARY) $(ITERATION_BINARY) $(READ_ONLY_BINARY)
	rm -f $(CHECKER_REPORT_FILE)
	rm -rf $(REPORT_DIR)
	find . -name '*.plist' -delete
	find . -name '*.o' -delete
	find . -name '*.dSYM' -exec rm -rf {} +
