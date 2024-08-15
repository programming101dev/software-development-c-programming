ifeq ($(CC),cc)
    CC = gcc
endif

CFLAGS = -std=c17 -D_POSIX_C_SOURCE=200809L -D_XOPEN_SOURCE=700 -D_DARWIN_C_SOURCE -D_DEFAULT_SOURCE -D__BSD_VISIBLE \
		 -Wall -Wextra -Werror -pedantic -Wconversion -Wshadow -Wformat=2 -Winit-self -Wswitch-default \
         -Wswitch-enum -Wfloat-equal -Wcast-align -Wpointer-arith -Wmissing-prototypes -Wstrict-prototypes \
         -Wundef -Wstrict-overflow=5 -Wwrite-strings -Wredundant-decls -Winline -Wvla -Wdouble-promotion \
         -Wdeclaration-after-statement
SANITIZERS = -fsanitize=address -fsanitize=undefined -fsanitize=leak
SUPPORTED_SANITIZERS =
CHECKER_REPORT_FILE = cppcheck-report.txt
REPORT_DIR = scan-results

# Source and binary definitions for the new set of files
ACCESSING_ARGS_SOURCES = accessing-args.c
ACCESSING_ARGS_BINARY = accessing-args
ARGS_SOURCES = args.c
ARGS_BINARY = args
EXIT_CODE_SOURCES = exit-code.c
EXIT_CODE_BINARY = exit-code
NO_ARGS_SOURCES = no-args.c
NO_ARGS_BINARY = no-args
SUM_SOURCES = sum.c
SUM_BINARY = sum
SUM_ERROR_HANDLING_SOURCES = sum-error-handling.c
SUM_ERROR_HANDLING_BINARY = sum-error-handling
SUM_SINGLE_RETURN_SOURCES = sum-single-return.c
SUM_SINGLE_RETURN_BINARY = sum-single-return

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
all: clang-format $(ACCESSING_ARGS_BINARY) $(ARGS_BINARY) $(EXIT_CODE_BINARY) $(NO_ARGS_BINARY) $(SUM_BINARY) \
     $(SUM_ERROR_HANDLING_BINARY) $(SUM_SINGLE_RETURN_BINARY) analyze clang-tidy cppcheck

# Build rules for each binary
$(ACCESSING_ARGS_BINARY): $(ACCESSING_ARGS_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(ACCESSING_ARGS_BINARY) $(ACCESSING_ARGS_SOURCES)

$(ARGS_BINARY): $(ARGS_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(ARGS_BINARY) $(ARGS_SOURCES)

$(EXIT_CODE_BINARY): $(EXIT_CODE_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(EXIT_CODE_BINARY) $(EXIT_CODE_SOURCES)

$(NO_ARGS_BINARY): $(NO_ARGS_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(NO_ARGS_BINARY) $(NO_ARGS_SOURCES)

$(SUM_BINARY): $(SUM_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(SUM_BINARY) $(SUM_SOURCES)

$(SUM_ERROR_HANDLING_BINARY): $(SUM_ERROR_HANDLING_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(SUM_ERROR_HANDLING_BINARY) $(SUM_ERROR_HANDLING_SOURCES)

$(SUM_SINGLE_RETURN_BINARY): $(SUM_SINGLE_RETURN_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(SUM_SINGLE_RETURN_BINARY) $(SUM_SINGLE_RETURN_SOURCES)

# Analyze rule to analyze all sources
analyze:
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(ACCESSING_ARGS_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(ARGS_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(EXIT_CODE_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(NO_ARGS_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(SUM_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(SUM_ERROR_HANDLING_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(SUM_SINGLE_RETURN_SOURCES) -c

# Clang-tidy rule to lint all sources
clang-tidy:
	clang-tidy -quiet --warnings-as-errors=* -checks='*,-cert-err33-c,-clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling,-readability-identifier-length,-llvmlibc-restrict-system-libc-headers,-cppcoreguidelines-init-variables,-altera-unroll-loops,-llvm-header-guard,-cppcoreguidelines-avoid-magic-numbers,-readability-magic-numbers,-misc-unused-parameters,-android-cloexec-dup,-android-cloexec-open,-android-cloexec-creat,-android-cloexec-fopen,-bugprone-easily-swappable-parameters' \
	$(ACCESSING_ARGS_SOURCES) $(ARGS_SOURCES) $(EXIT_CODE_SOURCES) $(NO_ARGS_SOURCES) $(SUM_SOURCES) $(SUM_ERROR_HANDLING_SOURCES) $(SUM_SINGLE_RETURN_SOURCES) \
	-- $(CFLAGS)

# Cppcheck rule to perform static analysis on all sources
cppcheck:
	cppcheck --enable=all --error-exitcode=1 --inconclusive --check-level=exhaustive --inline-suppr --suppress=missingIncludeSystem --checkers-report=$(CHECKER_REPORT_FILE) --quiet \
	$(ACCESSING_ARGS_SOURCES) $(ARGS_SOURCES) $(EXIT_CODE_SOURCES) $(NO_ARGS_SOURCES) \
	$(SUM_SOURCES) $(SUM_ERROR_HANDLING_SOURCES) $(SUM_SINGLE_RETURN_SOURCES)

clang-format:
	clang-format -i -- $(ACCESSING_ARGS_SOURCES) $(ARGS_SOURCES) $(EXIT_CODE_SOURCES) $(NO_ARGS_SOURCES) \
	$(SUM_SOURCES) $(SUM_ERROR_HANDLING_SOURCES) $(SUM_SINGLE_RETURN_SOURCES)

# Clean rule to remove binaries and reports
clean:
	rm -f $(ACCESSING_ARGS_BINARY) $(ARGS_BINARY) $(EXIT_CODE_BINARY) $(NO_ARGS_BINARY) $(SUM_BINARY) \
	$(SUM_ERROR_HANDLING_BINARY) $(SUM_SINGLE_RETURN_BINARY)
	rm -f $(CHECKER_REPORT_FILE)
	rm -rf $(REPORT_DIR)
	find . -name '*.plist' -delete
	find . -name '*.o' -delete
