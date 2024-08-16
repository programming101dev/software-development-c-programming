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
ARROW_OPERATOR_SOURCES = arrow-operator.c
ARROW_OPERATOR_BINARY = arrow-operator
BY_POINTER_SOURCES = by-pointer.c
BY_POINTER_BINARY = by-pointer
BY_VALUE_SOURCES = by-value.c
BY_VALUE_BINARY = by-value
DOT_OPERATOR_SOURCES = dot-operator.c
DOT_OPERATOR_BINARY = dot-operator
DYNAMIC_SOURCES = dynamic.c
DYNAMIC_BINARY = dynamic
NESTED_ACCESS_SOURCES = nested-access.c
NESTED_ACCESS_BINARY = nested-access
NESTED_SOURCES = nested.c
NESTED_BINARY = nested
NESTED_MEMORY_SOURCES = nested-memory.c
NESTED_MEMORY_BINARY = nested-memory
STRUCT_SOURCES = struct.c
STRUCT_BINARY = struct
TYPEDEF_SOURCES = typedef.c
TYPEDEF_BINARY = typedef

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
all: clang-format $(ARROW_OPERATOR_BINARY) $(BY_POINTER_BINARY) $(BY_VALUE_BINARY) $(DOT_OPERATOR_BINARY) \
     $(DYNAMIC_BINARY) $(NESTED_ACCESS_BINARY) $(NESTED_BINARY) $(NESTED_MEMORY_BINARY) $(STRUCT_BINARY) \
     $(TYPEDEF_BINARY) analyze clang-tidy cppcheck

# Build rules for each binary
$(ARROW_OPERATOR_BINARY): $(ARROW_OPERATOR_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(ARROW_OPERATOR_BINARY) $(ARROW_OPERATOR_SOURCES)

$(BY_POINTER_BINARY): $(BY_POINTER_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(BY_POINTER_BINARY) $(BY_POINTER_SOURCES)

$(BY_VALUE_BINARY): $(BY_VALUE_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(BY_VALUE_BINARY) $(BY_VALUE_SOURCES)

$(DOT_OPERATOR_BINARY): $(DOT_OPERATOR_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(DOT_OPERATOR_BINARY) $(DOT_OPERATOR_SOURCES)

$(DYNAMIC_BINARY): $(DYNAMIC_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(DYNAMIC_BINARY) $(DYNAMIC_SOURCES)

$(NESTED_ACCESS_BINARY): $(NESTED_ACCESS_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(NESTED_ACCESS_BINARY) $(NESTED_ACCESS_SOURCES)

$(NESTED_BINARY): $(NESTED_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(NESTED_BINARY) $(NESTED_SOURCES)

$(NESTED_MEMORY_BINARY): $(NESTED_MEMORY_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(NESTED_MEMORY_BINARY) $(NESTED_MEMORY_SOURCES)

$(STRUCT_BINARY): $(STRUCT_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(STRUCT_BINARY) $(STRUCT_SOURCES)

$(TYPEDEF_BINARY): $(TYPEDEF_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(TYPEDEF_BINARY) $(TYPEDEF_SOURCES)

# Analyze rule to analyze all sources
analyze:
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(ARROW_OPERATOR_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(BY_POINTER_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(BY_VALUE_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(DOT_OPERATOR_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(DYNAMIC_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(NESTED_ACCESS_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(NESTED_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(NESTED_MEMORY_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(STRUCT_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(TYPEDEF_SOURCES) -c

# Clang-tidy rule to lint all sources
clang-tidy:
	clang-tidy -quiet --warnings-as-errors=* -checks='*,-cert-err33-c,-clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling,-readability-identifier-length,-llvmlibc-restrict-system-libc-headers,-cppcoreguidelines-init-variables,-altera-unroll-loops,-llvm-header-guard,-cppcoreguidelines-avoid-magic-numbers,-readability-magic-numbers,-misc-unused-parameters,-android-cloexec-dup,-android-cloexec-open,-android-cloexec-creat,-android-cloexec-fopen,-bugprone-easily-swappable-parameters' \
	$(ARROW_OPERATOR_SOURCES) $(BY_POINTER_SOURCES) $(BY_VALUE_SOURCES) $(DOT_OPERATOR_SOURCES) $(DYNAMIC_SOURCES) $(NESTED_ACCESS_SOURCES) $(NESTED_SOURCES) $(NESTED_MEMORY_SOURCES) $(STRUCT_SOURCES) $(TYPEDEF_SOURCES) \
   	-- $(CFLAGS)

# Cppcheck rule to perform static analysis on all sources
cppcheck:
	cppcheck --enable=all --error-exitcode=1 --inconclusive --check-level=exhaustive --inline-suppr --suppress=missingIncludeSystem --checkers-report=$(CHECKER_REPORT_FILE) --quiet \
	$(ARROW_OPERATOR_SOURCES) $(BY_POINTER_SOURCES) $(BY_VALUE_SOURCES) $(DOT_OPERATOR_SOURCES) \
	$(DYNAMIC_SOURCES) $(NESTED_ACCESS_SOURCES) $(NESTED_SOURCES) $(NESTED_MEMORY_SOURCES) $(STRUCT_SOURCES) \
	$(TYPEDEF_SOURCES)

clang-format:
	clang-format -i -- $(ARROW_OPERATOR_SOURCES) $(BY_POINTER_SOURCES) $(BY_VALUE_SOURCES) $(DOT_OPERATOR_SOURCES) \
	$(DYNAMIC_SOURCES) $(NESTED_ACCESS_SOURCES) $(NESTED_SOURCES) $(NESTED_MEMORY_SOURCES) $(STRUCT_SOURCES) \
	$(TYPEDEF_SOURCES)

# Clean rule to remove binaries and reports
clean:
	rm -f $(ARROW_OPERATOR_BINARY) $(BY_POINTER_BINARY) $(BY_VALUE_BINARY) $(DOT_OPERATOR_BINARY) \
	$(DYNAMIC_BINARY) $(NESTED_ACCESS_BINARY) $(NESTED_BINARY) $(NESTED_MEMORY_BINARY) $(STRUCT_BINARY) \
	$(TYPEDEF_BINARY)
	rm -f $(CHECKER_REPORT_FILE)
	rm -rf $(REPORT_DIR)
	find . -name '*.plist' -delete
	find . -name '*.o' -delete
	find . -name '*.dSYM' -exec rm -rf {} +
