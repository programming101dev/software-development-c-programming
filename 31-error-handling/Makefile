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
CHECKING_RETURN_VALUES_SOURCES = checking-return-values.c
CHECKING_RETURN_VALUES_BINARY = checking-return-values
GOTO_CLEANUP_SOURCES = goto-cleanup.c
GOTO_CLEANUP_BINARY = goto-cleanup
PERROR_SOURCES = perror.c
PERROR_BINARY = perror
STRERROR_R_SOURCES = strerror_r.c
STRERROR_R_BINARY = strerror_r

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
all: clang-format $(CHECKING_RETURN_VALUES_BINARY) $(GOTO_CLEANUP_BINARY) $(PERROR_BINARY) $(STRERROR_R_BINARY) analyze clang-tidy cppcheck

# Build rules for each binary
$(CHECKING_RETURN_VALUES_BINARY): $(CHECKING_RETURN_VALUES_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(CHECKING_RETURN_VALUES_BINARY) $(CHECKING_RETURN_VALUES_SOURCES)

$(GOTO_CLEANUP_BINARY): $(GOTO_CLEANUP_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(GOTO_CLEANUP_BINARY) $(GOTO_CLEANUP_SOURCES)

$(PERROR_BINARY): $(PERROR_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(PERROR_BINARY) $(PERROR_SOURCES)

$(STRERROR_R_BINARY): $(STRERROR_R_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(STRERROR_R_BINARY) $(STRERROR_R_SOURCES)

# Analyze rule to analyze all sources
analyze:
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(CHECKING_RETURN_VALUES_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(GOTO_CLEANUP_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(PERROR_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(STRERROR_R_SOURCES) -c

# Clang-tidy rule to lint all sources
clang-tidy:
	clang-tidy -quiet --warnings-as-errors=* -checks='*,-cert-err33-c,-clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling,-readability-identifier-length,-llvmlibc-restrict-system-libc-headers,-cppcoreguidelines-init-variables,-altera-unroll-loops,-llvm-header-guard,-cppcoreguidelines-avoid-magic-numbers,-readability-magic-numbers,-misc-unused-parameters,-android-cloexec-dup,-android-cloexec-open,-android-cloexec-creat,-android-cloexec-fopen,-bugprone-easily-swappable-parameters,-altera-id-dependent-backward-branch,-altera-struct-pack-align' \
	$(CHECKING_RETURN_VALUES_SOURCES) $(GOTO_CLEANUP_SOURCES) $(PERROR_SOURCES) $(STRERROR_R_SOURCES) \
	-- $(CFLAGS)

# Cppcheck rule to perform static analysis on all sources
cppcheck:
	cppcheck --enable=all --error-exitcode=1 --inconclusive --check-level=exhaustive --inline-suppr --suppress=missingIncludeSystem --checkers-report=$(CHECKER_REPORT_FILE) --quiet \
	$(CHECKING_RETURN_VALUES_SOURCES) $(GOTO_CLEANUP_SOURCES) $(PERROR_SOURCES) $(STRERROR_R_SOURCES)

clang-format:
	clang-format -i -- $(CHECKING_RETURN_VALUES_SOURCES) $(GOTO_CLEANUP_SOURCES) $(PERROR_SOURCES) $(STRERROR_R_SOURCES)

# Clean rule to remove binaries and reports
clean:
	rm -f $(CHECKING_RETURN_VALUES_BINARY) $(GOTO_CLEANUP_BINARY) $(PERROR_BINARY) $(STRERROR_R_BINARY)
	rm -f $(CHECKER_REPORT_FILE)
	rm -rf $(REPORT_DIR)
	find . -name '*.plist' -delete
	find . -name '*.o' -delete
	find . -name '*.dSYM' -exec rm -rf {} +
