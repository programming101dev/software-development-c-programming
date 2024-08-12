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
BOOLEAN_VALUES_SOURCES = boolean-values.c
BOOLEAN_VALUES_BINARY = boolean-values
LOGICAL_AND_SOURCES = logical-and.c
LOGICAL_AND_BINARY = logical-and
LOGICAL_OR_SOURCES = logical-or.c
LOGICAL_OR_BINARY = logical-or
LOGICAL_NOT_SOURCES = logical-not.c
LOGICAL_NOT_BINARY = logical-not
SHORT_CIRCUIT_SOURCES = short-circuit-evaluation.c
SHORT_CIRCUIT_BINARY = short-circuit-evaluation
COMBINING_BOOLEAN_SOURCES = combining-boolean-operations.c
COMBINING_BOOLEAN_BINARY = combining-boolean-operations

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
all: clang-format $(BOOLEAN_VALUES_BINARY) $(LOGICAL_AND_BINARY) $(LOGICAL_OR_BINARY) $(LOGICAL_NOT_BINARY) \
     $(SHORT_CIRCUIT_BINARY) $(COMBINING_BOOLEAN_BINARY) analyze clang-tidy cppcheck

# Build rules for each binary
$(BOOLEAN_VALUES_BINARY): $(BOOLEAN_VALUES_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(BOOLEAN_VALUES_BINARY) $(BOOLEAN_VALUES_SOURCES)

$(LOGICAL_AND_BINARY): $(LOGICAL_AND_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(LOGICAL_AND_BINARY) $(LOGICAL_AND_SOURCES)

$(LOGICAL_OR_BINARY): $(LOGICAL_OR_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(LOGICAL_OR_BINARY) $(LOGICAL_OR_SOURCES)

$(LOGICAL_NOT_BINARY): $(LOGICAL_NOT_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(LOGICAL_NOT_BINARY) $(LOGICAL_NOT_SOURCES)

$(SHORT_CIRCUIT_BINARY): $(SHORT_CIRCUIT_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(SHORT_CIRCUIT_BINARY) $(SHORT_CIRCUIT_SOURCES)

$(COMBINING_BOOLEAN_BINARY): $(COMBINING_BOOLEAN_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(COMBINING_BOOLEAN_BINARY) $(COMBINING_BOOLEAN_SOURCES)

# Analyze rule to analyze all sources
analyze:
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(BOOLEAN_VALUES_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(LOGICAL_AND_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(LOGICAL_OR_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(LOGICAL_NOT_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(SHORT_CIRCUIT_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(COMBINING_BOOLEAN_SOURCES) -c

# Clang-tidy rule to lint all sources
clang-tidy:
	clang-tidy $(BOOLEAN_VALUES_SOURCES) $(LOGICAL_AND_SOURCES) $(LOGICAL_OR_SOURCES) $(LOGICAL_NOT_SOURCES) \
	$(SHORT_CIRCUIT_SOURCES) $(COMBINING_BOOLEAN_SOURCES) \
	-quiet -checks='*,-cert-err33-c,-clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling,-readability-identifier-length,-llvmlibc-restrict-system-libc-headers,-cppcoreguidelines-init-variables,-altera-unroll-loops,-llvm-header-guard' -- $(CFLAGS)

# Cppcheck rule to perform static analysis on all sources
cppcheck:
	cppcheck --enable=all --inconclusive --inline-suppr --suppress=missingIncludeSystem --checkers-report=$(CHECKER_REPORT_FILE) --quiet \
	$(BOOLEAN_VALUES_SOURCES) $(LOGICAL_AND_SOURCES) $(LOGICAL_OR_SOURCES) $(LOGICAL_NOT_SOURCES) \
	$(SHORT_CIRCUIT_SOURCES) $(COMBINING_BOOLEAN_SOURCES)

clang-format:
	clang-format -i -- $(BOOLEAN_VALUES_SOURCES) $(LOGICAL_AND_SOURCES) $(LOGICAL_OR_SOURCES) $(LOGICAL_NOT_SOURCES) \
	$(SHORT_CIRCUIT_SOURCES) $(COMBINING_BOOLEAN_SOURCES)

# Clean rule to remove binaries and reports
clean:
	rm -f $(BOOLEAN_VALUES_BINARY) $(LOGICAL_AND_BINARY) $(LOGICAL_OR_BINARY) $(LOGICAL_NOT_BINARY) \
	$(SHORT_CIRCUIT_BINARY) $(COMBINING_BOOLEAN_BINARY)
	rm -f $(CHECKER_REPORT_FILE)
	rm -rf $(REPORT_DIR)
	find . -name '*.plist' -delete
	find . -name '*.o' -delete
