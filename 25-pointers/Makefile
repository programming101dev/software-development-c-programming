# Compiler and flags
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

# Source and binary definitions
NULL_POINTER_SOURCES = null-pointer.c
NULL_POINTER_BINARY = null-pointer
ARRAY_ARITHMETIC_SOURCES = array-arithmetic.c
ARRAY_ARITHMETIC_BINARY = array-arithmetic
PASSING_SOURCES = passing.c
PASSING_BINARY = passing
DANGLING_SOURCES = dangling.c
DANGLING_BINARY = dangling
DIFFERENCE_SOURCES = difference.c
DIFFERENCE_BINARY = difference
POINTERS_SOURCES = pointers.c
POINTERS_BINARY = pointers
ARRAYS_SOURCES = arrays.c
ARRAYS_BINARY = arrays

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
all: clang-format $(NULL_POINTER_BINARY) $(ARRAY_ARITHMETIC_BINARY) $(PASSING_BINARY) $(DANGLING_BINARY) $(DIFFERENCE_BINARY) $(POINTERS_BINARY) $(ARRAYS_BINARY) analyze clang-tidy cppcheck

# Build rules for each binary
$(NULL_POINTER_BINARY): $(NULL_POINTER_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(NULL_POINTER_BINARY) $(NULL_POINTER_SOURCES)

$(ARRAY_ARITHMETIC_BINARY): $(ARRAY_ARITHMETIC_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(ARRAY_ARITHMETIC_BINARY) $(ARRAY_ARITHMETIC_SOURCES)

$(PASSING_BINARY): $(PASSING_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(PASSING_BINARY) $(PASSING_SOURCES)

$(DANGLING_BINARY): $(DANGLING_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(DANGLING_BINARY) $(DANGLING_SOURCES)

$(DIFFERENCE_BINARY): $(DIFFERENCE_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(DIFFERENCE_BINARY) $(DIFFERENCE_SOURCES)

$(POINTERS_BINARY): $(POINTERS_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(POINTERS_BINARY) $(POINTERS_SOURCES)

$(ARRAYS_BINARY): $(ARRAYS_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(ARRAYS_BINARY) $(ARRAYS_SOURCES)

# Analyze rule to analyze all sources
analyze:
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(NULL_POINTER_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(ARRAY_ARITHMETIC_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(PASSING_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(DANGLING_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(DIFFERENCE_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(POINTERS_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(ARRAYS_SOURCES) -c

# Clang-tidy rule to lint all sources
clang-tidy:
	clang-tidy -quiet --warnings-as-errors=* -checks='*,-cert-err33-c,-clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling,-readability-identifier-length,-llvmlibc-restrict-system-libc-headers,-cppcoreguidelines-init-variables,-altera-unroll-loops,-llvm-header-guard,-cppcoreguidelines-avoid-magic-numbers,-readability-magic-numbers,-misc-unused-parameters,-android-cloexec-dup,-android-cloexec-open,-android-cloexec-creat,-android-cloexec-fopen,-bugprone-easily-swappable-parameters,-altera-id-dependent-backward-branch,-altera-struct-pack-align' \
    $(NULL_POINTER_SOURCES) $(ARRAY_ARITHMETIC_SOURCES) $(PASSING_SOURCES) $(DANGLING_SOURCES) $(DIFFERENCE_SOURCES) $(POINTERS_SOURCES) $(ARRAYS_SOURCES) \
    -- $(CFLAGS)

# Cppcheck rule to perform static analysis on all sources
cppcheck:
	cppcheck --enable=all --error-exitcode=1 --inconclusive --check-level=exhaustive --inline-suppr --suppress=missingIncludeSystem --checkers-report=$(CHECKER_REPORT_FILE) --quiet \
	$(NULL_POINTER_SOURCES) $(ARRAY_ARITHMETIC_SOURCES) $(PASSING_SOURCES) $(DANGLING_SOURCES) $(DIFFERENCE_SOURCES) $(POINTERS_SOURCES) $(ARRAYS_SOURCES)

# Clang-format rule to format all sources
clang-format:
	clang-format -i -- $(NULL_POINTER_SOURCES) $(ARRAY_ARITHMETIC_SOURCES) $(PASSING_SOURCES) $(DANGLING_SOURCES) $(DIFFERENCE_SOURCES) $(POINTERS_SOURCES) $(ARRAYS_SOURCES)

# Clean rule to remove binaries and reports
clean:
	rm -f $(NULL_POINTER_BINARY) $(ARRAY_ARITHMETIC_BINARY) $(PASSING_BINARY) $(DANGLING_BINARY) $(DIFFERENCE_BINARY) $(POINTERS_BINARY) $(ARRAYS_BINARY)
	rm -f $(CHECKER_REPORT_FILE)
	rm -rf $(REPORT_DIR)
	find . -name '*.plist' -delete
	find . -name '*.o' -delete
	find . -name '*.dSYM' -exec rm -rf {} +
