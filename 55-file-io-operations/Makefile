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
FGETC_SOURCES = fgetc.c
FGETC_BINARY = fgetc
FGETS_SOURCES = fgets.c
FGETS_BINARY = fgets
FPUTC_SOURCES = fputc.c
FPUTC_BINARY = fputc
FPUTS_SOURCES = fputs.c
FPUTS_BINARY = fputs
FREAD_SOURCES = fread.c
FREAD_BINARY = fread
FWRITE_SOURCES = fwrite.c
FWRITE_BINARY = fwrite
MODES_SOURCES = modes.c
MODES_BINARY = modes

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
all: clang-format $(FGETC_BINARY) $(FGETS_BINARY) $(FPUTC_BINARY) $(FPUTS_BINARY) $(FREAD_BINARY) $(FWRITE_BINARY) $(MODES_BINARY) analyze clang-tidy cppcheck

# Build rules for each binary
$(FGETC_BINARY): $(FGETC_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(FGETC_BINARY) $(FGETC_SOURCES)

$(FGETS_BINARY): $(FGETS_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(FGETS_BINARY) $(FGETS_SOURCES)

$(FPUTC_BINARY): $(FPUTC_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(FPUTC_BINARY) $(FPUTC_SOURCES)

$(FPUTS_BINARY): $(FPUTS_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(FPUTS_BINARY) $(FPUTS_SOURCES)

$(FREAD_BINARY): $(FREAD_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(FREAD_BINARY) $(FREAD_SOURCES)

$(FWRITE_BINARY): $(FWRITE_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(FWRITE_BINARY) $(FWRITE_SOURCES)

$(MODES_BINARY): $(MODES_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(MODES_BINARY) $(MODES_SOURCES)

# Analyze rule to analyze all sources
analyze:
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(FGETC_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(FGETS_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(FPUTC_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(FPUTS_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(FREAD_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(FWRITE_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(MODES_SOURCES) -c

# Clang-tidy rule to lint all sources
clang-tidy:
	clang-tidy -quiet --warnings-as-errors=* -checks='*,-cert-err33-c,-clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling,-readability-identifier-length,-llvmlibc-restrict-system-libc-headers,-cppcoreguidelines-init-variables,-altera-unroll-loops,-llvm-header-guard,-cppcoreguidelines-avoid-magic-numbers,-readability-magic-numbers,-misc-unused-parameters,-android-cloexec-dup,-android-cloexec-open,-android-cloexec-creat,-android-cloexec-fopen,-bugprone-easily-swappable-parameters,-misc-include-cleaner' \
	$(FGETC_SOURCES) $(FGETS_SOURCES) $(FPUTC_SOURCES) $(FPUTS_SOURCES) $(FREAD_SOURCES) $(FWRITE_SOURCES) $(MODES_SOURCES) \
  	-- $(CFLAGS)

# Cppcheck rule to perform static analysis on all sources
cppcheck:
	cppcheck --enable=all --error-exitcode=1 --inconclusive --check-level=exhaustive --inline-suppr --suppress=missingIncludeSystem --checkers-report=$(CHECKER_REPORT_FILE) --quiet \
	$(FGETC_SOURCES) $(FGETS_SOURCES) $(FPUTC_SOURCES) $(FPUTS_SOURCES) $(FREAD_SOURCES) $(FWRITE_SOURCES) $(MODES_SOURCES)

clang-format:
	clang-format -i -- $(FGETC_SOURCES) $(FGETS_SOURCES) $(FPUTC_SOURCES) $(FPUTS_SOURCES) $(FREAD_SOURCES) $(FWRITE_SOURCES) $(MODES_SOURCES)

# Clean rule to remove binaries and reports
clean:
	rm -f $(FGETC_BINARY) $(FGETS_BINARY) $(FPUTC_BINARY) $(FPUTS_BINARY) $(FREAD_BINARY) $(FWRITE_BINARY) $(MODES_BINARY)
	rm -f $(CHECKER_REPORT_FILE)
	rm -rf $(REPORT_DIR)
	find . -name '*.plist' -delete
	find . -name '*.o' -delete
