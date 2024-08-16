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
READ_SOURCES = read.c
READ_BINARY = read
READ_FULLY_SOURCES = read_fully.c
READ_FULLY_BINARY = read_fully
SPECIFIC_TYPE_SOURCES = specific-type.c
SPECIFIC_TYPE_BINARY = specific-type
WRITE_SOURCES = write.c
WRITE_BINARY = write
WRITE_FULLY_SOURCES = write-fully.c
WRITE_FULLY_BINARY = write-fully

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
all: clang-format $(READ_BINARY) $(READ_FULLY_BINARY) $(SPECIFIC_TYPE_BINARY) $(WRITE_BINARY) $(WRITE_FULLY_BINARY) analyze clang-tidy cppcheck

# Build rules for each binary
$(READ_BINARY): $(READ_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(READ_BINARY) $(READ_SOURCES)

$(READ_FULLY_BINARY): $(READ_FULLY_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(READ_FULLY_BINARY) $(READ_FULLY_SOURCES)

$(SPECIFIC_TYPE_BINARY): $(SPECIFIC_TYPE_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(SPECIFIC_TYPE_BINARY) $(SPECIFIC_TYPE_SOURCES)

$(WRITE_BINARY): $(WRITE_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(WRITE_BINARY) $(WRITE_SOURCES)

$(WRITE_FULLY_BINARY): $(WRITE_FULLY_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(WRITE_FULLY_BINARY) $(WRITE_FULLY_SOURCES)

# Analyze rule to analyze all sources
analyze:
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(READ_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(READ_FULLY_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(SPECIFIC_TYPE_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(WRITE_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(WRITE_FULLY_SOURCES) -c

# Clang-tidy rule to lint all sources
clang-tidy:
	clang-tidy -quiet --warnings-as-errors=* -checks='*,-cert-err33-c,-clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling,-readability-identifier-length,-llvmlibc-restrict-system-libc-headers,-cppcoreguidelines-init-variables,-altera-unroll-loops,-llvm-header-guard,-cppcoreguidelines-avoid-magic-numbers,-readability-magic-numbers,-misc-unused-parameters,-android-cloexec-dup,-android-cloexec-open,-android-cloexec-creat,-android-cloexec-fopen,-bugprone-easily-swappable-parameters,-misc-include-cleaner' \
	$(READ_SOURCES) $(READ_FULLY_SOURCES) $(SPECIFIC_TYPE_SOURCES) $(WRITE_SOURCES) $(WRITE_FULLY_SOURCES) \
   	-- $(CFLAGS)

# Cppcheck rule to perform static analysis on all sources
cppcheck:
	cppcheck --enable=all --error-exitcode=1 --inconclusive --check-level=exhaustive --inline-suppr --suppress=missingIncludeSystem --checkers-report=$(CHECKER_REPORT_FILE) --quiet \
	$(READ_SOURCES) $(READ_FULLY_SOURCES) $(SPECIFIC_TYPE_SOURCES) $(WRITE_SOURCES) $(WRITE_FULLY_SOURCES)

clang-format:
	clang-format -i -- $(READ_SOURCES) $(READ_FULLY_SOURCES) $(SPECIFIC_TYPE_SOURCES) $(WRITE_SOURCES) $(WRITE_FULLY_SOURCES)

# Clean rule to remove binaries and reports
clean:
	rm -f $(READ_BINARY) $(READ_FULLY_BINARY) $(SPECIFIC_TYPE_BINARY) $(WRITE_BINARY) $(WRITE_FULLY_BINARY)
	rm -f $(CHECKER_REPORT_FILE)
	rm -rf $(REPORT_DIR)
	find . -name '*.plist' -delete
	find . -name '*.o' -delete
