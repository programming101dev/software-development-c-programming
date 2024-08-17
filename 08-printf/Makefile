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
ESCAPE_SEQUENCES_SOURCES = escape-sequences.c
ESCAPE_SEQUENCES_BINARY = escape-sequences
FORMAT_SPECIFIERS_SOURCES = format-specifiers.c
FORMAT_SPECIFIERS_BINARY = format-specifiers
PRECISION_SPECIFIERS_SOURCES = precision-specifiers.c
PRECISION_SPECIFIERS_BINARY = precision-specifiers
LENGTH_MODIFIERS_SOURCES = length-modifiers.c
LENGTH_MODIFIERS_BINARY = length-modifiers
DYNAMIC_WIDTH_AND_PRECISION_SOURCES = dynamic-width-and-precision.c
DYNAMIC_WIDTH_AND_PRECISION_BINARY = dynamic-width-and-precision
JUSTIFICATION_SPECIFIERS_SOURCES = justification-specifiers.c
JUSTIFICATION_SPECIFIERS_BINARY = justification-specifiers
FLAGS_SOURCES = flags.c
FLAGS_BINARY = flags
FPRINTF_SOURCES = fprintf.c
FPRINTF_BINARY = fprintf

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
all: clang-format $(ESCAPE_SEQUENCES_BINARY) $(FORMAT_SPECIFIERS_BINARY) $(PRECISION_SPECIFIERS_BINARY) $(LENGTH_MODIFIERS_BINARY) $(DYNAMIC_WIDTH_AND_PRECISION_BINARY) $(JUSTIFICATION_SPECIFIERS_BINARY) $(FLAGS_BINARY) $(FPRINTF_BINARY) analyze clang-tidy cppcheck

# Build rules for each binary
$(ESCAPE_SEQUENCES_BINARY): $(ESCAPE_SEQUENCES_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(ESCAPE_SEQUENCES_BINARY) $(ESCAPE_SEQUENCES_SOURCES)

$(FORMAT_SPECIFIERS_BINARY): $(FORMAT_SPECIFIERS_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(FORMAT_SPECIFIERS_BINARY) $(FORMAT_SPECIFIERS_SOURCES)

$(PRECISION_SPECIFIERS_BINARY): $(PRECISION_SPECIFIERS_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(PRECISION_SPECIFIERS_BINARY) $(PRECISION_SPECIFIERS_SOURCES)

$(LENGTH_MODIFIERS_BINARY): $(LENGTH_MODIFIERS_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(LENGTH_MODIFIERS_BINARY) $(LENGTH_MODIFIERS_SOURCES)

$(DYNAMIC_WIDTH_AND_PRECISION_BINARY): $(DYNAMIC_WIDTH_AND_PRECISION_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(DYNAMIC_WIDTH_AND_PRECISION_BINARY) $(DYNAMIC_WIDTH_AND_PRECISION_SOURCES)

$(JUSTIFICATION_SPECIFIERS_BINARY): $(JUSTIFICATION_SPECIFIERS_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(JUSTIFICATION_SPECIFIERS_BINARY) $(JUSTIFICATION_SPECIFIERS_SOURCES)

$(FLAGS_BINARY): $(FLAGS_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(FLAGS_BINARY) $(FLAGS_SOURCES)

$(FPRINTF_BINARY): $(FPRINTF_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(FPRINTF_BINARY) $(FPRINTF_SOURCES)

analyze: $(ESCAPE_SEQUENCES_BINARY) $(FORMAT_SPECIFIERS_BINARY) $(PRECISION_SPECIFIERS_BINARY) $(LENGTH_MODIFIERS_BINARY) $(DYNAMIC_WIDTH_AND_PRECISION_BINARY) $(JUSTIFICATION_SPECIFIERS_BINARY) $(FLAGS_BINARY) $(FPRINTF_BINARY)
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(ESCAPE_SEQUENCES_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(FORMAT_SPECIFIERS_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(PRECISION_SPECIFIERS_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(LENGTH_MODIFIERS_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(DYNAMIC_WIDTH_AND_PRECISION_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(JUSTIFICATION_SPECIFIERS_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(FLAGS_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(FPRINTF_SOURCES) -c

clang-tidy:
	clang-tidy -quiet --warnings-as-errors=* -checks='*,-cert-err33-c,-clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling,-readability-identifier-length,-llvmlibc-restrict-system-libc-headers,-cppcoreguidelines-init-variables,-altera-unroll-loops,-llvm-header-guard,-cppcoreguidelines-avoid-magic-numbers,-readability-magic-numbers,-misc-unused-parameters,-android-cloexec-dup,-android-cloexec-open,-android-cloexec-creat,-android-cloexec-fopen,-bugprone-easily-swappable-parameters,-altera-id-dependent-backward-branch' \
	$(ESCAPE_SEQUENCES_SOURCES) $(FORMAT_SPECIFIERS_SOURCES) $(PRECISION_SPECIFIERS_SOURCES) $(LENGTH_MODIFIERS_SOURCES) $(DYNAMIC_WIDTH_AND_PRECISION_SOURCES) $(JUSTIFICATION_SPECIFIERS_SOURCES) $(FLAGS_SOURCES) $(FPRINTF_SOURCES) \
	-- $(CFLAGS)

cppcheck:
	cppcheck --enable=all --error-exitcode=1 --inconclusive --check-level=exhaustive --inline-suppr --suppress=missingIncludeSystem --checkers-report=$(CHECKER_REPORT_FILE) --quiet \
	$(ESCAPE_SEQUENCES_SOURCES) $(FORMAT_SPECIFIERS_SOURCES) $(PRECISION_SPECIFIERS_SOURCES) $(LENGTH_MODIFIERS_SOURCES) $(DYNAMIC_WIDTH_AND_PRECISION_SOURCES) $(JUSTIFICATION_SPECIFIERS_SOURCES) $(FLAGS_SOURCES) $(FPRINTF_SOURCES)

clang-format:
	clang-format -i -- $(ESCAPE_SEQUENCES_SOURCES) $(FORMAT_SPECIFIERS_SOURCES) $(PRECISION_SPECIFIERS_SOURCES) $(LENGTH_MODIFIERS_SOURCES) $(DYNAMIC_WIDTH_AND_PRECISION_SOURCES) $(JUSTIFICATION_SPECIFIERS_SOURCES) $(FLAGS_SOURCES) $(FPRINTF_SOURCES)

clean:
	rm -f $(ESCAPE_SEQUENCES_BINARY) $(FORMAT_SPECIFIERS_BINARY) $(PRECISION_SPECIFIERS_BINARY) $(LENGTH_MODIFIERS_BINARY) $(DYNAMIC_WIDTH_AND_PRECISION_BINARY) $(JUSTIFICATION_SPECIFIERS_BINARY) $(FLAGS_BINARY) $(FPRINTF_BINARY)
	rm -f $(CHECKER_REPORT_FILE)
	rm -rf $(REPORT_DIR)
	find . -name '*.plist' -delete
	find . -name '*.o' -delete
