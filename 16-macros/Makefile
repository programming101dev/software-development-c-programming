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
OBJECT_LIKE_MACRO_SOURCES = object-like-macro.c
OBJECT_LIKE_MACRO_BINARY = object-like-macro
FUNCTION_LIKE_MACRO_SOURCES = function-like-macro.c
FUNCTION_LIKE_MACRO_BINARY = function-like-macro
UNSAFE_MACRO_SOURCES = unsafe-macro.c
UNSAFE_MACRO_BINARY = unsafe-macro
SAFE_MACRO_SOURCES = safe-macro.c
SAFE_MACRO_BINARY = safe-macro
CONST_VARIABLES_SOURCES = const-variables.c
CONST_VARIABLES_BINARY = const-variables
INLINE_FUNCTIONS_SOURCES = inline-functions.c
INLINE_FUNCTIONS_BINARY = inline-functions
STRINGIFICATION_SOURCES = stringification.c
STRINGIFICATION_BINARY = stringification
CONCATENATION_SOURCES = concatenation.c
CONCATENATION_BINARY = concatenation
BUILTIN_MACROS_SOURCES = builtin-macros.c
BUILTIN_MACROS_BINARY = builtin-macros

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
all: clang-format $(OBJECT_LIKE_MACRO_BINARY) $(FUNCTION_LIKE_MACRO_BINARY) $(UNSAFE_MACRO_BINARY) $(SAFE_MACRO_BINARY) $(CONST_VARIABLES_BINARY) $(INLINE_FUNCTIONS_BINARY) $(STRINGIFICATION_BINARY) $(CONCATENATION_BINARY) $(BUILTIN_MACROS_BINARY) analyze clang-tidy cppcheck

# Build rules for each binary
$(OBJECT_LIKE_MACRO_BINARY): $(OBJECT_LIKE_MACRO_SOURCES)
	$(CC) -std=c17 $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(OBJECT_LIKE_MACRO_BINARY) $(OBJECT_LIKE_MACRO_SOURCES)

$(FUNCTION_LIKE_MACRO_BINARY): $(FUNCTION_LIKE_MACRO_SOURCES)
	$(CC) -std=c17 $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(FUNCTION_LIKE_MACRO_BINARY) $(FUNCTION_LIKE_MACRO_SOURCES)

$(UNSAFE_MACRO_BINARY): $(UNSAFE_MACRO_SOURCES)
	$(CC) -std=c17 $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(UNSAFE_MACRO_BINARY) $(UNSAFE_MACRO_SOURCES)

$(SAFE_MACRO_BINARY): $(SAFE_MACRO_SOURCES)
	$(CC) -std=c17 $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(SAFE_MACRO_BINARY) $(SAFE_MACRO_SOURCES)

$(CONST_VARIABLES_BINARY): $(CONST_VARIABLES_SOURCES)
	$(CC) -std=c17 $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(CONST_VARIABLES_BINARY) $(CONST_VARIABLES_SOURCES)

$(INLINE_FUNCTIONS_BINARY): $(INLINE_FUNCTIONS_SOURCES)
	$(CC) -std=c17 $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(INLINE_FUNCTIONS_BINARY) $(INLINE_FUNCTIONS_SOURCES)

$(STRINGIFICATION_BINARY): $(STRINGIFICATION_SOURCES)
	$(CC) -std=c17 $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(STRINGIFICATION_BINARY) $(STRINGIFICATION_SOURCES)

$(CONCATENATION_BINARY): $(CONCATENATION_SOURCES)
	$(CC) -std=c17 $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(CONCATENATION_BINARY) $(CONCATENATION_SOURCES)

$(BUILTIN_MACROS_BINARY): $(BUILTIN_MACROS_SOURCES)
	$(CC) -std=c17 $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(BUILTIN_MACROS_BINARY) $(BUILTIN_MACROS_SOURCES)

analyze:
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(OBJECT_LIKE_MACRO_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(FUNCTION_LIKE_MACRO_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(UNSAFE_MACRO_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(SAFE_MACRO_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(CONST_VARIABLES_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(INLINE_FUNCTIONS_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(STRINGIFICATION_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(CONCATENATION_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(BUILTIN_MACROS_SOURCES) -c

clang-tidy:
	clang-tidy -quiet --warnings-as-errors=* -checks='*,-cert-err33-c,-clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling,-readability-identifier-length,-llvmlibc-restrict-system-libc-headers,-cppcoreguidelines-init-variables,-altera-unroll-loops,-llvm-header-guard,-cppcoreguidelines-avoid-magic-numbers,-readability-magic-numbers,-misc-unused-parameters,-android-cloexec-dup' \
	$(OBJECT_LIKE_MACROS_SOURCES) $(FUNCTION_LIKE_MACROS_SOURCES) $(UNSAFE_MACRO_SOURCES) $(SAFE_MACRO_SOURCES) $(CONST_VARIABLES_SOURCES) $(INLINE_FUNCTIONS_SOURCES) $(STRINGIFICATION_SOURCES) $(CONCATENATION_SOURCES) $(BUILTIN_MACROS_SOURCES) \
	-- $(CFLAGS)

cppcheck:
	cppcheck --enable=all --error-exitcode=1 --inconclusive --check-level=exhaustive --inline-suppr --suppress=missingIncludeSystem --checkers-report=$(CHECKER_REPORT_FILE) --quiet \
	$(OBJECT_LIKE_MACRO_SOURCES) $(FUNCTION_LIKE_MACRO_SOURCES) $(UNSAFE_MACRO_SOURCES) $(SAFE_MACRO_SOURCES) $(CONST_VARIABLES_SOURCES) $(INLINE_FUNCTIONS_SOURCES) $(STRINGIFICATION_SOURCES) $(CONCATENATION_SOURCES) $(BUILTIN_MACROS_SOURCES)

clang-format:
	clang-format -i -- $(OBJECT_LIKE_MACRO_SOURCES) $(FUNCTION_LIKE_MACRO_SOURCES) $(UNSAFE_MACRO_SOURCES) $(SAFE_MACRO_SOURCES) $(CONST_VARIABLES_SOURCES) $(INLINE_FUNCTIONS_SOURCES) $(STRINGIFICATION_SOURCES) $(CONCATENATION_SOURCES) $(BUILTIN_MACROS_SOURCES)

clean:
	rm -f $(OBJECT_LIKE_MACRO_BINARY) $(FUNCTION_LIKE_MACRO_BINARY) $(UNSAFE_MACRO_BINARY) $(SAFE_MACRO_BINARY) $(CONST_VARIABLES_BINARY) $(INLINE_FUNCTIONS_BINARY) $(STRINGIFICATION_BINARY) $(CONCATENATION_BINARY) $(BUILTIN_MACROS_BINARY)
	rm -f $(CHECKER_REPORT_FILE)
	rm -rf $(REPORT_DIR)
	find . -name '*.plist' -delete
	find . -name '*.o' -delete
