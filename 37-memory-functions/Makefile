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

# Source and binary definitions for each file
DEEP_COPY_SOURCES = deep-copy.c
DEEP_COPY_BINARY = deep-copy

MEMCMP_SOURCES = memcmp.c
MEMCMP_BINARY = memcmp

MEMMOVE_SOURCES = memmove.c
MEMMOVE_BINARY = memmove

SHALLOW_COPY_SOURCES = shallow-copy.c
SHALLOW_COPY_BINARY = shallow-copy

MEMCHR_SOURCES = memchr.c
MEMCHR_BINARY = memchr

MEMCPY_SOURCES = memcpy.c
MEMCPY_BINARY = memcpy

MEMSET_SOURCES = memset.c
MEMSET_BINARY = memset

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
all: clang-format $(DEEP_COPY_BINARY) $(MEMCMP_BINARY) $(MEMMOVE_BINARY) $(SHALLOW_COPY_BINARY) \
	$(MEMCHR_BINARY) $(MEMCPY_BINARY) $(MEMSET_BINARY) analyze clang-tidy cppcheck

# Build rules for each binary
$(DEEP_COPY_BINARY): $(DEEP_COPY_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(DEEP_COPY_BINARY) $(DEEP_COPY_SOURCES)

$(MEMCMP_BINARY): $(MEMCMP_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(MEMCMP_BINARY) $(MEMCMP_SOURCES)

$(MEMMOVE_BINARY): $(MEMMOVE_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(MEMMOVE_BINARY) $(MEMMOVE_SOURCES)

$(SHALLOW_COPY_BINARY): $(SHALLOW_COPY_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(SHALLOW_COPY_BINARY) $(SHALLOW_COPY_SOURCES)

$(MEMCHR_BINARY): $(MEMCHR_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(MEMCHR_BINARY) $(MEMCHR_SOURCES)

$(MEMCPY_BINARY): $(MEMCPY_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(MEMCPY_BINARY) $(MEMCPY_SOURCES)

$(MEMSET_BINARY): $(MEMSET_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(MEMSET_BINARY) $(MEMSET_SOURCES)

# Analyze rule to analyze all sources
analyze:
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(DEEP_COPY_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(MEMCMP_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(MEMMOVE_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(SHALLOW_COPY_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(MEMCHR_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(MEMCPY_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(MEMSET_SOURCES) -c

# Clang-tidy rule to lint all sources
clang-tidy:
	clang-tidy -quiet --warnings-as-errors=* -checks='*,-cert-err33-c,-clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling,-readability-identifier-length,-llvmlibc-restrict-system-libc-headers,-cppcoreguidelines-init-variables,-altera-unroll-loops,-llvm-header-guard,-cppcoreguidelines-avoid-magic-numbers,-readability-magic-numbers,-misc-unused-parameters,-android-cloexec-dup,-android-cloexec-open,-android-cloexec-creat,-android-cloexec-fopen,-bugprone-easily-swappable-parameters,-altera-id-dependent-backward-branch,-altera-struct-pack-align' \
	$(DEEP_COPY_SOURCES) $(MEMCMP_SOURCES) $(MEMMOVE_SOURCES) $(SHALLOW_COPY_SOURCES) $(MEMCHR_SOURCES) $(MEMCPY_SOURCES) $(MEMSET_SOURCES) \
	-- $(CFLAGS)

# Cppcheck rule to perform static analysis on all sources
cppcheck:
	cppcheck --enable=all --error-exitcode=1 --inconclusive --check-level=exhaustive --inline-suppr --suppress=missingIncludeSystem --checkers-report=$(CHECKER_REPORT_FILE) --quiet \
	$(DEEP_COPY_SOURCES) $(MEMCMP_SOURCES) $(MEMMOVE_SOURCES) $(SHALLOW_COPY_SOURCES) $(MEMCHR_SOURCES) $(MEMCPY_SOURCES) $(MEMSET_SOURCES)

clang-format:
	clang-format -i -- $(DEEP_COPY_SOURCES) $(MEMCMP_SOURCES) $(MEMMOVE_SOURCES) $(SHALLOW_COPY_SOURCES) $(MEMCHR_SOURCES) $(MEMCPY_SOURCES) $(MEMSET_SOURCES)

# Clean rule to remove binaries and reports
clean:
	rm -f $(DEEP_COPY_BINARY) $(MEMCMP_BINARY) $(MEMMOVE_BINARY) $(SHALLOW_COPY_BINARY) $(MEMCHR_BINARY) $(MEMCPY_BINARY) $(MEMSET_BINARY)
	rm -f $(CHECKER_REPORT_FILE)
	rm -rf $(REPORT_DIR)
	find . -name '*.plist' -delete
	find . -name '*.o' -delete
	find . -name '*.dSYM' -exec rm -rf {} +
