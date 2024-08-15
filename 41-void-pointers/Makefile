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
FUNCTION_POINTERS_SOURCES = function-pointers.c
FUNCTION_POINTERS_BINARY = function-pointers
TYPE_SAFETY_SOURCES = type-safety.c
TYPE_SAFETY_BINARY = type-safety
VOID_POINTER_SOURCES = void-pointer.c
VOID_POINTER_BINARY = void-pointer

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
all: clang-format $(FUNCTION_POINTERS_BINARY) $(TYPE_SAFETY_BINARY) $(VOID_POINTER_BINARY) analyze clang-tidy cppcheck

# Build rules for each binary
$(FUNCTION_POINTERS_BINARY): $(FUNCTION_POINTERS_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(FUNCTION_POINTERS_BINARY) $(FUNCTION_POINTERS_SOURCES)

$(TYPE_SAFETY_BINARY): $(TYPE_SAFETY_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(TYPE_SAFETY_BINARY) $(TYPE_SAFETY_SOURCES)

$(VOID_POINTER_BINARY): $(VOID_POINTER_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(VOID_POINTER_BINARY) $(VOID_POINTER_SOURCES)

# Analyze rule to analyze all sources
analyze:
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(FUNCTION_POINTERS_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(TYPE_SAFETY_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(VOID_POINTER_SOURCES) -c

# Clang-tidy rule to lint all sources
clang-tidy:
	clang-tidy -quiet --warnings-as-errors=* -checks='*,-cert-err33-c,-clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling,-readability-identifier-length,-llvmlibc-restrict-system-libc-headers,-cppcoreguidelines-init-variables,-altera-unroll-loops,-llvm-header-guard,-cppcoreguidelines-avoid-magic-numbers,-readability-magic-numbers,-misc-unused-parameters,-android-cloexec-dup,-android-cloexec-open,-android-cloexec-creat,-android-cloexec-fopen,-bugprone-easily-swappable-parameters' \
	$(FUNCTION_POINTERS_SOURCES) $(TYPE_SAFETY_SOURCES) $(VOID_POINTER_SOURCES) \
	-- $(CFLAGS)

# Cppcheck rule to perform static analysis on all sources
cppcheck:
	cppcheck --enable=all --error-exitcode=1 --inconclusive --check-level=exhaustive --inline-suppr --suppress=missingIncludeSystem --checkers-report=$(CHECKER_REPORT_FILE) --quiet \
	$(FUNCTION_POINTERS_SOURCES) $(TYPE_SAFETY_SOURCES) $(VOID_POINTER_SOURCES)

clang-format:
	clang-format -i -- $(FUNCTION_POINTERS_SOURCES) $(TYPE_SAFETY_SOURCES) $(VOID_POINTER_SOURCES)

# Clean rule to remove binaries and reports
clean:
	rm -f $(FUNCTION_POINTERS_BINARY) $(TYPE_SAFETY_BINARY) $(VOID_POINTER_BINARY)
	rm -f $(CHECKER_REPORT_FILE)
	rm -rf $(REPORT_DIR)
	find . -name '*.plist' -delete
	find . -name '*.o' -delete
