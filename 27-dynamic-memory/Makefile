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
CALLOC_SOURCES = calloc.c
CALLOC_BINARY = calloc
CORRECT_SIZE_SOURCES = correct-size.c
CORRECT_SIZE_BINARY = correct-size
DANGLING_POINTER_SOURCES = dangling-pointer.c
DANGLING_POINTER_BINARY = dangling-pointer
DOUBLE_FREE_SOURCES = double-free.c
DOUBLE_FREE_BINARY = double-free
ERROR_HANDLING_SOURCES = error-handling.c
ERROR_HANDLING_BINARY = error-handling
LIFETIME_SOURCES = lifetime.c
LIFETIME_BINARY = lifetime
MALLOC_FREE_SOURCES = malloc-free.c
MALLOC_FREE_BINARY = malloc-free
MEMORY_LEAK_SOURCES = memory-leak.c
MEMORY_LEAK_BINARY = memory-leak
PAIRING_ALLOC_FREE_SOURCES = pairing-alloc-free.c
PAIRING_ALLOC_FREE_BINARY = pairing-alloc-free
REALLOC_SOURCES = realloc.c
REALLOC_BINARY = realloc
RESOURCE_HANDLING_SOURCES = resource-handling.c
RESOURCE_HANDLING_BINARY = resource-handling

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
all: clang-format $(CALLOC_BINARY) $(CORRECT_SIZE_BINARY) $(DANGLING_POINTER_BINARY) $(DOUBLE_FREE_BINARY) \
     $(ERROR_HANDLING_BINARY) $(LIFETIME_BINARY) $(MALLOC_FREE_BINARY) $(MEMORY_LEAK_BINARY) \
     $(PAIRING_ALLOC_FREE_BINARY) $(REALLOC_BINARY) $(RESOURCE_HANDLING_BINARY) analyze clang-tidy cppcheck

# Build rules for each binary
$(CALLOC_BINARY): $(CALLOC_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(CALLOC_BINARY) $(CALLOC_SOURCES)

$(CORRECT_SIZE_BINARY): $(CORRECT_SIZE_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(CORRECT_SIZE_BINARY) $(CORRECT_SIZE_SOURCES)

$(DANGLING_POINTER_BINARY): $(DANGLING_POINTER_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(DANGLING_POINTER_BINARY) $(DANGLING_POINTER_SOURCES)

$(DOUBLE_FREE_BINARY): $(DOUBLE_FREE_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(DOUBLE_FREE_BINARY) $(DOUBLE_FREE_SOURCES)

$(ERROR_HANDLING_BINARY): $(ERROR_HANDLING_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(ERROR_HANDLING_BINARY) $(ERROR_HANDLING_SOURCES)

$(LIFETIME_BINARY): $(LIFETIME_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(LIFETIME_BINARY) $(LIFETIME_SOURCES)

$(MALLOC_FREE_BINARY): $(MALLOC_FREE_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(MALLOC_FREE_BINARY) $(MALLOC_FREE_SOURCES)

$(MEMORY_LEAK_BINARY): $(MEMORY_LEAK_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(MEMORY_LEAK_BINARY) $(MEMORY_LEAK_SOURCES)

$(PAIRING_ALLOC_FREE_BINARY): $(PAIRING_ALLOC_FREE_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(PAIRING_ALLOC_FREE_BINARY) $(PAIRING_ALLOC_FREE_SOURCES)

$(REALLOC_BINARY): $(REALLOC_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(REALLOC_BINARY) $(REALLOC_SOURCES)

$(RESOURCE_HANDLING_BINARY): $(RESOURCE_HANDLING_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(RESOURCE_HANDLING_BINARY) $(RESOURCE_HANDLING_SOURCES)

# Analyze rule to analyze all sources
analyze:
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(CALLOC_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(CORRECT_SIZE_SOURCES) -c
# have to turn this off to get it to commpile
#	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(DANGLING_POINTER_SOURCES) -c
# have to turn this off to get it to commpile
#	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(DOUBLE_FREE_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(ERROR_HANDLING_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(LIFETIME_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(MALLOC_FREE_SOURCES) -c
# have to turn this off to get it to commpile
#	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(MEMORY_LEAK_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(PAIRING_ALLOC_FREE_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(REALLOC_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(RESOURCE_HANDLING_SOURCES) -c

# Clang-tidy rule to lint all sources
clang-tidy:
	clang-tidy -quiet --warnings-as-errors=* -checks='*,-cert-err33-c,-clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling,-readability-identifier-length,-llvmlibc-restrict-system-libc-headers,-cppcoreguidelines-init-variables,-altera-unroll-loops,-llvm-header-guard,-cppcoreguidelines-avoid-magic-numbers,-readability-magic-numbers,-misc-unused-parameters,-android-cloexec-dup,-android-cloexec-open,-android-cloexec-creat,-android-cloexec-fopen,-bugprone-easily-swappable-parameters,-altera-id-dependent-backward-branch' \
	$(CALLOC_SOURCES) $(CORRECT_SIZE_SOURCES) $(DANGLING_POINTER_SOURCES) $(DOUBLE_FREE_SOURCES) $(ERROR_HANDLING_SOURCES) $(LIFETIME_SOURCES) $(MALLOC_FREE_SOURCES) $(MEMORY_LEAK_SOURCES) $(PAIRING_ALLOC_FREE_SOURCES) $(REALLOC_SOURCES) $(RESOURCE_HANDLING_SOURCES) \
    -- $(CFLAGS)

# Cppcheck rule to perform static analysis on all sources
cppcheck:
	cppcheck --enable=all --error-exitcode=1 --inconclusive --check-level=exhaustive --inline-suppr --suppress=missingIncludeSystem --checkers-report=$(CHECKER_REPORT_FILE) --quiet \
	$(CALLOC_SOURCES) $(CORRECT_SIZE_SOURCES) $(DANGLING_POINTER_SOURCES) $(DOUBLE_FREE_SOURCES) \
	$(ERROR_HANDLING_SOURCES) $(LIFETIME_SOURCES) $(MALLOC_FREE_SOURCES) $(MEMORY_LEAK_SOURCES) \
	$(PAIRING_ALLOC_FREE_SOURCES) $(REALLOC_SOURCES) $(RESOURCE_HANDLING_SOURCES)

clang-format:
	clang-format -i -- $(CALLOC_SOURCES) $(CORRECT_SIZE_SOURCES) $(DANGLING_POINTER_SOURCES) $(DOUBLE_FREE_SOURCES) \
	$(ERROR_HANDLING_SOURCES) $(LIFETIME_SOURCES) $(MALLOC_FREE_SOURCES) $(MEMORY_LEAK_SOURCES) \
	$(PAIRING_ALLOC_FREE_SOURCES) $(REALLOC_SOURCES) $(RESOURCE_HANDLING_SOURCES)

# Clean rule to
clean:
	rm -f $(CALLOC_BINARY) $(CORRECT_SIZE_BINARY) $(DANGLING_POINTER_BINARY) $(DOUBLE_FREE_BINARY) $(ERROR_HANDLING_BINARY) $(LIFETIME_BINARY) $(MALLOC_FREE_BINARY) $(MEMORY_LEAK_BINARY) $(PAIRING_ALLOC_FREE_BINARY) $(REALLOC_BINARY) $(RESOURCE_HANDLING_BINARY)
	rm -f $(CHECKER_REPORT_FILE)
	rm -rf $(REPORT_DIR)
	find . -name '*.plist' -delete
	find . -name '*.o' -delete
	find . -name '*.dSYM' -exec rm -rf {} +
