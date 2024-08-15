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
IF_STATEMENT_SOURCES = if-statement.c
IF_STATEMENT_BINARY = if-statement
ELSE_STATEMENT_SOURCES = else-statement.c
ELSE_STATEMENT_BINARY = else-statement
IF_ELSE_STATEMENT_SOURCES = if-else-statement.c
IF_ELSE_STATEMENT_BINARY = if-else-statement
NESTED_CONDITIONALS_SOURCES = nested-conditionals.c
NESTED_CONDITIONALS_BINARY = nested-conditionals
SWITCH_STATEMENT_SOURCES = switch-statement.c
SWITCH_STATEMENT_BINARY = switch-statement
TERNARY_OPERATOR_SOURCES = ternary-operator.c
TERNARY_OPERATOR_BINARY = ternary-operator

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
all: clang-format $(IF_STATEMENT_BINARY) $(ELSE_STATEMENT_BINARY) $(IF_ELSE_STATEMENT_BINARY) $(NESTED_CONDITIONALS_BINARY) \
     $(SWITCH_STATEMENT_BINARY) $(TERNARY_OPERATOR_BINARY) analyze clang-tidy cppcheck

# Build rules for each binary
$(IF_STATEMENT_BINARY): $(IF_STATEMENT_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(IF_STATEMENT_BINARY) $(IF_STATEMENT_SOURCES)

$(ELSE_STATEMENT_BINARY): $(ELSE_STATEMENT_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(ELSE_STATEMENT_BINARY) $(ELSE_STATEMENT_SOURCES)

$(IF_ELSE_STATEMENT_BINARY): $(IF_ELSE_STATEMENT_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(IF_ELSE_STATEMENT_BINARY) $(IF_ELSE_STATEMENT_SOURCES)

$(NESTED_CONDITIONALS_BINARY): $(NESTED_CONDITIONALS_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(NESTED_CONDITIONALS_BINARY) $(NESTED_CONDITIONALS_SOURCES)

$(SWITCH_STATEMENT_BINARY): $(SWITCH_STATEMENT_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(SWITCH_STATEMENT_BINARY) $(SWITCH_STATEMENT_SOURCES)

$(TERNARY_OPERATOR_BINARY): $(TERNARY_OPERATOR_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(TERNARY_OPERATOR_BINARY) $(TERNARY_OPERATOR_SOURCES)

# Analyze rule to analyze all sources
analyze:
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(IF_STATEMENT_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(ELSE_STATEMENT_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(IF_ELSE_STATEMENT_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(NESTED_CONDITIONALS_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(SWITCH_STATEMENT_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(TERNARY_OPERATOR_SOURCES) -c

# Clang-tidy rule to lint all sources
clang-tidy:
	clang-tidy -quiet --warnings-as-errors=* -checks='*,-cert-err33-c,-clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling,-readability-identifier-length,-llvmlibc-restrict-system-libc-headers,-cppcoreguidelines-init-variables,-altera-unroll-loops,-llvm-header-guard,-cppcoreguidelines-avoid-magic-numbers,-readability-magic-numbers,-misc-unused-parameters,-android-cloexec-dup,-android-cloexec-open,-android-cloexec-creat,-android-cloexec-fopen,-bugprone-easily-swappable-parameters' \
	$(IF_STATEMENT_SOURCES) $(ELSE_STATEMENT_SOURCES) $(IF_ELSE_STATEMENT_SOURCES) $(NESTED_CONDITIONALS_SOURCES) $(SWITCH_STATEMENT_SOURCES) $(TERNARY_OPERATOR_SOURCES) \
	-- $(CFLAGS)

# Cppcheck rule to perform static analysis on all sources
cppcheck:
	cppcheck --enable=all --error-exitcode=1 --inconclusive --check-level=exhaustive --inline-suppr --suppress=missingIncludeSystem --checkers-report=$(CHECKER_REPORT_FILE) --quiet \
	$(IF_STATEMENT_SOURCES) $(ELSE_STATEMENT_SOURCES) $(IF_ELSE_STATEMENT_SOURCES) $(NESTED_CONDITIONALS_SOURCES) \
	$(SWITCH_STATEMENT_SOURCES) $(TERNARY_OPERATOR_SOURCES)

clang-format:
	clang-format -i -- $(IF_STATEMENT_SOURCES) $(ELSE_STATEMENT_SOURCES) $(IF_ELSE_STATEMENT_SOURCES) $(NESTED_CONDITIONALS_SOURCES) $(SWITCH_STATEMENT_SOURCES) $(TERNARY_OPERATOR_SOURCES)

# Clean rule to remove binaries and reports
clean:
	rm -f $(IF_STATEMENT_BINARY) $(ELSE_STATEMENT_BINARY) $(IF_ELSE_STATEMENT_BINARY) $(NESTED_CONDITIONALS_BINARY) \
	$(SWITCH_STATEMENT_BINARY) $(TERNARY_OPERATOR_BINARY)
	rm -f $(CHECKER_REPORT_FILE)
	rm -rf $(REPORT_DIR)
	find . -name '*.plist' -delete
	find . -name '*.o' -delete
