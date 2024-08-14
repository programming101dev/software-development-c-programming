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
FOR_LOOP_SOURCES = for-loop.c
FOR_LOOP_BINARY = for-loop
WHILE_LOOP_SOURCES = while-loop.c
WHILE_LOOP_BINARY = while-loop
DO_LOOP_SOURCES = do-loop.c
DO_LOOP_BINARY = do-loop
BREAK_STATEMENT_SOURCES = break-statement.c
BREAK_STATEMENT_BINARY = break-statement
CONTINUE_STATEMENT_SOURCES = continue-statement.c
CONTINUE_STATEMENT_BINARY = continue-statement
NESTED_LOOPS_SOURCES = nested-loops.c
NESTED_LOOPS_BINARY = nested-loops
NESTED_CONDITIONALS_SOURCES = nested-conditionals.c
NESTED_CONDITIONALS_BINARY = nested-conditionals

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
 	ANALYZER_FLAGS = -plist-html -o $(REPORT_DIR)
endif

# All rule to build all binaries, analyze, and run cppcheck
all: clang-format $(FOR_LOOP_BINARY) $(WHILE_LOOP_BINARY) $(DO_LOOP_BINARY) $(BREAK_STATEMENT_BINARY) \
     $(CONTINUE_STATEMENT_BINARY) $(NESTED_LOOPS_BINARY) $(NESTED_CONDITIONALS_BINARY) analyze clang-tidy cppcheck

# Build rules for each binary
$(FOR_LOOP_BINARY): $(FOR_LOOP_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(FOR_LOOP_BINARY) $(FOR_LOOP_SOURCES)

$(WHILE_LOOP_BINARY): $(WHILE_LOOP_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(WHILE_LOOP_BINARY) $(WHILE_LOOP_SOURCES)

$(DO_LOOP_BINARY): $(DO_LOOP_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(DO_LOOP_BINARY) $(DO_LOOP_SOURCES)

$(BREAK_STATEMENT_BINARY): $(BREAK_STATEMENT_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(BREAK_STATEMENT_BINARY) $(BREAK_STATEMENT_SOURCES)

$(CONTINUE_STATEMENT_BINARY): $(CONTINUE_STATEMENT_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(CONTINUE_STATEMENT_BINARY) $(CONTINUE_STATEMENT_SOURCES)

$(NESTED_LOOPS_BINARY): $(NESTED_LOOPS_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(NESTED_LOOPS_BINARY) $(NESTED_LOOPS_SOURCES)

$(NESTED_CONDITIONALS_BINARY): $(NESTED_CONDITIONALS_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(NESTED_CONDITIONALS_BINARY) $(NESTED_CONDITIONALS_SOURCES)

# Analyze rule to analyze all sources
analyze:
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(FOR_LOOP_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(WHILE_LOOP_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(DO_LOOP_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(BREAK_STATEMENT_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(CONTINUE_STATEMENT_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(NESTED_LOOPS_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(NESTED_CONDITIONALS_SOURCES) -c

# Clang-tidy rule to lint all sources
clang-tidy:
	clang-tidy $(FOR_LOOP_SOURCES) $(WHILE_LOOP_SOURCES) $(DO_LOOP_SOURCES) $(BREAK_STATEMENT_SOURCES) \
	$(CONTINUE_STATEMENT_SOURCES) $(NESTED_LOOPS_SOURCES) $(NESTED_CONDITIONALS_SOURCES) \
	-quiet -checks='*,-cert-err33-c,-clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling,-readability-identifier-length,-llvmlibc-restrict-system-libc-headers,-cppcoreguidelines-init-variables,-altera-unroll-loops,-llvm-header-guard,-cppcoreguidelines-avoid-magic-numbers,-readability-magic-numbers' -- $(CFLAGS)

# Cppcheck rule to perform static analysis on all sources
cppcheck:
	cppcheck --enable=all --inconclusive --check-level=exhaustive -inline-suppr --suppress=missingIncludeSystem --checkers-report=$(CHECKER_REPORT_FILE) --quiet \
	$(FOR_LOOP_SOURCES) $(WHILE_LOOP_SOURCES) $(DO_LOOP_SOURCES) $(BREAK_STATEMENT_SOURCES) \
	$(CONTINUE_STATEMENT_SOURCES) $(NESTED_LOOPS_SOURCES) $(NESTED_CONDITIONALS_SOURCES)

clang-format:
	clang-format -i -- $(FOR_LOOP_SOURCES) $(WHILE_LOOP_SOURCES) $(DO_LOOP_SOURCES) $(BREAK_STATEMENT_SOURCES) \
	$(CONTINUE_STATEMENT_SOURCES) $(NESTED_LOOPS_SOURCES) $(NESTED_CONDITIONALS_SOURCES)

# Clean rule to remove binaries and reports
clean:
	rm -f $(FOR_LOOP_BINARY) $(WHILE_LOOP_BINARY) $(DO_LOOP_BINARY) $(BREAK_STATEMENT_BINARY) \
	$(CONTINUE_STATEMENT_BINARY) $(NESTED_LOOPS_BINARY) $(NESTED_CONDITIONALS_BINARY)
	rm -f $(CHECKER_REPORT_FILE)
	rm -rf $(REPORT_DIR)
	find . -name '*.plist' -delete
	find . -name '*.o' -delete
