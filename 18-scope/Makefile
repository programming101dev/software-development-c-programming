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
BLOCK_SCOPE_SOURCES = block-scope.c
BLOCK_SCOPE_BINARY = block-scope
EXTERN_VARIABLES_SOURCES = extern-variables.c extern.c
EXTERN_VARIABLES_HEADERS = extern.h
EXTERN_VARIABLES_BINARY = extern-variables
FILE_SCOPE_SOURCES = file-scope.c
FILE_SCOPE_BINARY = file-scope
FUNCTION_SCOPE_SOURCES = function-scope.c
FUNCTION_SCOPE_BINARY = function-scope
SHADOWING_SOURCES = shadowing.c
SHADOWING_BINARY = shadowing
SMALLEST_SCOPE_SOURCES = smallest-scope.c
SMALLEST_SCOPE_BINARY = smallest-scope
STATIC_VARIABLES_INSIDE_FUNCTIONS_SOURCES = static-variables-inside-functions.c
STATIC_VARIABLES_INSIDE_FUNCTIONS_BINARY = static-variables-inside-functions

# Attempt to compile with each sanitizer to check support
CHECK_SANITIZER = \
    $(shell echo "int main(){}" > sanitizer_check.c; \
    if $(CC) $(1) sanitizer_check.c -o /dev/null > /dev/null 2>&1; then echo $(1); fi; \
    rm -f sanitizer_check.c)

SUPPORTED_SANITIZERS += $(call CHECK_SANITIZER,-fsanitize=address)
SUPPORTED_SANITIZERS += $(call CHECK_SANITIZER,-fsanitize=undefined)
SUPPORTED_SANITIZERS += $(call CHECK_SANITIZER,-fsanitize=leak)

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
all: clang-format $(BLOCK_SCOPE_BINARY) $(EXTERN_VARIABLES_BINARY) $(FILE_SCOPE_BINARY) \
     $(FUNCTION_SCOPE_BINARY) $(SHADOWING_BINARY) $(SMALLEST_SCOPE_BINARY) \
     $(STATIC_VARIABLES_INSIDE_FUNCTIONS_BINARY) analyze clang-tidy cppcheck

# Build rules for each binary
$(BLOCK_SCOPE_BINARY): $(BLOCK_SCOPE_SOURCES)
	$(CC) -std=c17 $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(BLOCK_SCOPE_BINARY) $(BLOCK_SCOPE_SOURCES)

$(EXTERN_VARIABLES_BINARY): $(EXTERN_VARIABLES_SOURCES) $(EXTERN_VARIABLES_HEADERS)
	$(CC) -std=c17 $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(EXTERN_VARIABLES_BINARY) $(EXTERN_VARIABLES_SOURCES)

$(FILE_SCOPE_BINARY): $(FILE_SCOPE_SOURCES)
	$(CC) -std=c17 $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(FILE_SCOPE_BINARY) $(FILE_SCOPE_SOURCES)

$(FUNCTION_SCOPE_BINARY): $(FUNCTION_SCOPE_SOURCES)
	$(CC) -std=c17 $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(FUNCTION_SCOPE_BINARY) $(FUNCTION_SCOPE_SOURCES)

$(SHADOWING_BINARY): $(SHADOWING_SOURCES)
	$(CC) -std=c17 $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(SHADOWING_BINARY) $(SHADOWING_SOURCES)

$(SMALLEST_SCOPE_BINARY): $(SMALLEST_SCOPE_SOURCES)
	$(CC) -std=c17 $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(SMALLEST_SCOPE_BINARY) $(SMALLEST_SCOPE_SOURCES)

$(STATIC_VARIABLES_INSIDE_FUNCTIONS_BINARY): $(STATIC_VARIABLES_INSIDE_FUNCTIONS_SOURCES)
	$(CC) -std=c17 $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(STATIC_VARIABLES_INSIDE_FUNCTIONS_BINARY) $(STATIC_VARIABLES_INSIDE_FUNCTIONS_SOURCES)

# Analyze rule to analyze all sources and headers
analyze:
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(BLOCK_SCOPE_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(EXTERN_VARIABLES_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(FILE_SCOPE_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(FUNCTION_SCOPE_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(SHADOWING_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(SMALLEST_SCOPE_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(STATIC_VARIABLES_INSIDE_FUNCTIONS_SOURCES) -c

# Clang-tidy rule to lint all sources and headers
clang-tidy:
	clang-tidy -quiet --warnings-as-errors=* -checks='*,-cert-err33-c,-clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling,-readability-identifier-length,-llvmlibc-restrict-system-libc-headers,-cppcoreguidelines-init-variables,-altera-unroll-loops,-llvm-header-guard,-cppcoreguidelines-avoid-magic-numbers,-readability-magic-numbers,-misc-unused-parameters,-android-cloexec-dup,-android-cloexec-open,-android-cloexec-creat,-android-cloexec-fopen,-bugprone-easily-swappable-parameters' \
    $(BLOCK_SCOPE_SOURCES) $(EXTERN_VARIABLES_SOURCES) $(EXTERN_VARIABLES_HEADERS) $(FILE_SCOPE_SOURCES) \
	$(FUNCTION_SCOPE_SOURCES) $(SHADOWING_SOURCES) $(SMALLEST_SCOPE_SOURCES) $(STATIC_VARIABLES_INSIDE_FUNCTIONS_SOURCES) -- $(CFLAGS)

# Cppcheck rule to perform static analysis on all sources and headers
cppcheck:
	cppcheck --enable=all --error-exitcode=1 --inconclusive --check-level=exhaustive --inline-suppr --suppress=missingIncludeSystem --checkers-report=$(CHECKER_REPORT_FILE) --quiet \
	$(BLOCK_SCOPE_SOURCES) $(EXTERN_VARIABLES_SOURCES) $(EXTERN_VARIABLES_HEADERS) $(FILE_SCOPE_SOURCES) \
	$(FUNCTION_SCOPE_SOURCES) $(SHADOWING_SOURCES) $(SMALLEST_SCOPE_SOURCES) $(STATIC_VARIABLES_INSIDE_FUNCTIONS_SOURCES)

clang-format:
	clang-format -i -- $(BLOCK_SCOPE_SOURCES) $(EXTERN_VARIABLES_SOURCES) $(EXTERN_VARIABLES_HEADERS) $(FILE_SCOPE_SOURCES) \
                    	$(FUNCTION_SCOPE_SOURCES) $(SHADOWING_SOURCES) $(SMALLEST_SCOPE_SOURCES) $(STATIC_VARIABLES_INSIDE_FUNCTIONS_SOURCES)

# Clean rule to remove binaries and reports
clean:
	rm -f $(BLOCK_SCOPE_BINARY) $(EXTERN_VARIABLES_BINARY) $(FILE_SCOPE_BINARY) \
	      $(FUNCTION_SCOPE_BINARY) $(SHADOWING_BINARY) $(SMALLEST_SCOPE_BINARY) \
	      $(STATIC_VARIABLES_INSIDE_FUNCTIONS_BINARY)
	rm -f $(CHECKER_REPORT_FILE)
	rm -rf $(REPORT_DIR)
	find . -name '*.plist' -delete
	find . -name '*.o' -delete
