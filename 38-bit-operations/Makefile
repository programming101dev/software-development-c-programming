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
AND_SOURCES = and.c
AND_BINARY = and
BIT_MASKING_SOURCES = bit-masking.c
BIT_MASKING_BINARY = bit-masking
ERROR_HANDLING_SOURCES = error-handling.c
ERROR_HANDLING_BINARY = error-handling
NOT_SOURCES = not.c
NOT_BINARY = not
OR_SOURCES = or.c
OR_BINARY = or
SETTING_AND_CLEARING_SOURCES = setting-and-clearing.c
SETTING_AND_CLEARING_BINARY = setting-and-clearing
SHIFT_LEFT_SOURCES = shift-left.c
SHIFT_LEFT_BINARY = shift-left
SHIFT_RIGHT_SOURCES = shift-right.c
SHIFT_RIGHT_BINARY = shift-right
SIGNED_INT_SOURCES = signed-int.c
SIGNED_INT_BINARY = signed-int
TOGGLING_SOURCES = toggling.c
TOGGLING_BINARY = toggling
UNSIGNED_INT_SOURCES = unsigned-int.c
UNSIGNED_INT_BINARY = unsigned-int
XOR_SOURCES = xor.c
XOR_BINARY = xor

# Attempt to compile with each sanitizer to check support
CHECK_SANITIZER = \
    $(shell echo "int main(){}" > sanitizer_check.c; \
    if $(CC) $(1) sanitizer_check.c -o /dev/null > /dev/null 2>&1; then echo $(1); fi; \
    rm -f sanitizer_check.c)

# Loop over the SANITIZERS and add supported ones to SUPPORTED_SANITIZERS
define LOOP_SANITIZERS
    $(foreach sanitizer,$(SANITIZERS),\
        $(eval SUPPORTED_SANITIZERS += $(call CHECK_SANITIZER,$(sanitizer))))
endef

$(eval $(LOOP_SANITIZERS))

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
all: clang-format $(AND_BINARY) $(BIT_MASKING_BINARY) $(ERROR_HANDLING_BINARY) $(NOT_BINARY) $(OR_BINARY) \
     $(SETTING_AND_CLEARING_BINARY) $(SHIFT_LEFT_BINARY) $(SHIFT_RIGHT_BINARY) $(SIGNED_INT_BINARY) \
     $(TOGGLING_BINARY) $(UNSIGNED_INT_BINARY) $(XOR_BINARY) analyze clang-tidy cppcheck

# Build rules for each binary
$(AND_BINARY): $(AND_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(AND_BINARY) $(AND_SOURCES)

$(BIT_MASKING_BINARY): $(BIT_MASKING_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(BIT_MASKING_BINARY) $(BIT_MASKING_SOURCES)

$(ERROR_HANDLING_BINARY): $(ERROR_HANDLING_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(ERROR_HANDLING_BINARY) $(ERROR_HANDLING_SOURCES)

$(NOT_BINARY): $(NOT_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(NOT_BINARY) $(NOT_SOURCES)

$(OR_BINARY): $(OR_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(OR_BINARY) $(OR_SOURCES)

$(SETTING_AND_CLEARING_BINARY): $(SETTING_AND_CLEARING_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(SETTING_AND_CLEARING_BINARY) $(SETTING_AND_CLEARING_SOURCES)

$(SHIFT_LEFT_BINARY): $(SHIFT_LEFT_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(SHIFT_LEFT_BINARY) $(SHIFT_LEFT_SOURCES)

$(SHIFT_RIGHT_BINARY): $(SHIFT_RIGHT_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(SHIFT_RIGHT_BINARY) $(SHIFT_RIGHT_SOURCES)

$(SIGNED_INT_BINARY): $(SIGNED_INT_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(SIGNED_INT_BINARY) $(SIGNED_INT_SOURCES)

$(TOGGLING_BINARY): $(TOGGLING_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(TOGGLING_BINARY) $(TOGGLING_SOURCES)

$(UNSIGNED_INT_BINARY): $(UNSIGNED_INT_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(UNSIGNED_INT_BINARY) $(UNSIGNED_INT_SOURCES)

$(XOR_BINARY): $(XOR_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(XOR_BINARY) $(XOR_SOURCES)

# Analyze rule to analyze all sources
analyze:
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(AND_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(BIT_MASKING_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(ERROR_HANDLING_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(NOT_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(OR_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(SETTING_AND_CLEARING_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(SHIFT_LEFT_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(SHIFT_RIGHT_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(SIGNED_INT_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(TOGGLING_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(UNSIGNED_INT_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(XOR_SOURCES) -c

# Clang-tidy rule to lint all sources
clang-tidy:
	clang-tidy -quiet --warnings-as-errors=* -checks='*,-cert-err33-c,-clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling,-readability-identifier-length,-llvmlibc-restrict-system-libc-headers,-cppcoreguidelines-init-variables,-altera-unroll-loops,-llvm-header-guard,-cppcoreguidelines-avoid-magic-numbers,-readability-magic-numbers,-misc-unused-parameters,-android-cloexec-dup,-android-cloexec-open,-android-cloexec-creat,-android-cloexec-fopen,-bugprone-easily-swappable-parameters,-altera-id-dependent-backward-branch' \
	$(AND_SOURCES) $(BIT_MASKING_SOURCES) $(ERROR_HANDLING_SOURCES) $(NOT_SOURCES) $(OR_SOURCES) $(SETTING_AND_CLEARING_SOURCES) $(SHIFT_LEFT_SOURCES) $(SHIFT_RIGHT_SOURCES) $(SIGNED_INT_SOURCES) $(TOGGLING_SOURCES) $(UNSIGNED_INT_SOURCES) $(XOR_SOURCES) \
	-- $(CFLAGS)

# Cppcheck rule to perform static analysis on all sources
cppcheck:
	cppcheck --enable=all --error-exitcode=1 --inconclusive --check-level=exhaustive --inline-suppr --suppress=missingIncludeSystem --checkers-report=$(CHECKER_REPORT_FILE) --quiet \
	$(AND_SOURCES) $(BIT_MASKING_SOURCES) $(ERROR_HANDLING_SOURCES) $(NOT_SOURCES) $(OR_SOURCES) \
	$(SETTING_AND_CLEARING_SOURCES) $(SHIFT_LEFT_SOURCES) $(SHIFT_RIGHT_SOURCES) $(SIGNED_INT_SOURCES) \
	$(TOGGLING_SOURCES) $(UNSIGNED_INT_SOURCES) $(XOR_SOURCES)

clang-format:
	clang-format -i -- $(AND_SOURCES) $(BIT_MASKING_SOURCES) $(ERROR_HANDLING_SOURCES) $(NOT_SOURCES) $(OR_SOURCES) \
	$(SETTING_AND_CLEARING_SOURCES) $(SHIFT_LEFT_SOURCES) $(SHIFT_RIGHT_SOURCES) $(SIGNED_INT_SOURCES) \
	$(TOGGLING_SOURCES) $(UNSIGNED_INT_SOURCES) $(XOR_SOURCES)

# Clean rule to remove binaries and reports
clean:
	rm -f $(AND_BINARY) $(BIT_MASKING_BINARY) $(ERROR_HANDLING_BINARY) $(NOT_BINARY) $(OR_BINARY) \
	$(SETTING_AND_CLEARING_BINARY) $(SHIFT_LEFT_BINARY) $(SHIFT_RIGHT_BINARY) $(SIGNED_INT_BINARY) \
	$(TOGGLING_BINARY) $(UNSIGNED_INT_BINARY) $(XOR_BINARY)
	rm -f $(CHECKER_REPORT_FILE)
	rm -rf $(REPORT_DIR)
	find . -name '*.plist' -delete
	find . -name '*.o' -delete
	find . -name '*.dSYM' -exec rm -rf {} +
