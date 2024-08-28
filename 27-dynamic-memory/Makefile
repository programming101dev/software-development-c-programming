# Default compiler check
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
ALLOC_FREE_DIFFERENT_FUNCTIONS_SOURCES = alloc-free-different-functions.c
ALLOC_FREE_DIFFERENT_FUNCTIONS_BINARY = alloc-free-different-functions

ERROR_HANDLING_SOURCES = error-handling.c
ERROR_HANDLING_BINARY = error-handling

ALLOC_FREE_SAME_FUNCTION_SOURCES = alloc-free-same-function.c
ALLOC_FREE_SAME_FUNCTION_BINARY = alloc-free-same-function

GLOBAL_SOURCES = global.c
GLOBAL_BINARY = global

CALLOC_SOURCES = calloc.c
CALLOC_BINARY = calloc

MALLOC_FREE_SOURCES = malloc-free.c
MALLOC_FREE_BINARY = malloc-free

MEMORY_LEAK_SOURCES = memory-leak.c
MEMORY_LEAK_BINARY = memory-leak

DANGLING_POINTER_SOURCES = dangling-pointer.c
DANGLING_POINTER_BINARY = dangling-pointer

NULL_AFTER_FREE_SOURCES = null-after-free.c
NULL_AFTER_FREE_BINARY = null-after-free

DOUBLE_FREE_SOURCES = double-free.c
DOUBLE_FREE_BINARY = double-free

REALLOC_SOURCES = realloc.c
REALLOC_BINARY = realloc

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
all: clang-format $(ALLOC_FREE_DIFFERENT_FUNCTIONS_BINARY) $(ERROR_HANDLING_BINARY) $(ALLOC_FREE_SAME_FUNCTION_BINARY) \
     $(GLOBAL_BINARY) $(CALLOC_BINARY) $(MALLOC_FREE_BINARY) $(MEMORY_LEAK_BINARY) \
     $(DANGLING_POINTER_BINARY) $(NULL_AFTER_FREE_BINARY) $(DOUBLE_FREE_BINARY) $(REALLOC_BINARY) \
     analyze clang-tidy cppcheck

# Build rules for each binary
$(ALLOC_FREE_DIFFERENT_FUNCTIONS_BINARY): $(ALLOC_FREE_DIFFERENT_FUNCTIONS_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(ALLOC_FREE_DIFFERENT_FUNCTIONS_BINARY) $(ALLOC_FREE_DIFFERENT_FUNCTIONS_SOURCES)

$(ERROR_HANDLING_BINARY): $(ERROR_HANDLING_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(ERROR_HANDLING_BINARY) $(ERROR_HANDLING_SOURCES)

$(ALLOC_FREE_SAME_FUNCTION_BINARY): $(ALLOC_FREE_SAME_FUNCTION_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(ALLOC_FREE_SAME_FUNCTION_BINARY) $(ALLOC_FREE_SAME_FUNCTION_SOURCES)

$(GLOBAL_BINARY): $(GLOBAL_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(GLOBAL_BINARY) $(GLOBAL_SOURCES)

$(CALLOC_BINARY): $(CALLOC_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(CALLOC_BINARY) $(CALLOC_SOURCES)

$(MALLOC_FREE_BINARY): $(MALLOC_FREE_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(MALLOC_FREE_BINARY) $(MALLOC_FREE_SOURCES)

$(MEMORY_LEAK_BINARY): $(MEMORY_LEAK_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(MEMORY_LEAK_BINARY) $(MEMORY_LEAK_SOURCES)

$(DANGLING_POINTER_BINARY): $(DANGLING_POINTER_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(DANGLING_POINTER_BINARY) $(DANGLING_POINTER_SOURCES)

$(NULL_AFTER_FREE_BINARY): $(NULL_AFTER_FREE_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(NULL_AFTER_FREE_BINARY) $(NULL_AFTER_FREE_SOURCES)

$(DOUBLE_FREE_BINARY): $(DOUBLE_FREE_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(DOUBLE_FREE_BINARY) $(DOUBLE_FREE_SOURCES)

$(REALLOC_BINARY): $(REALLOC_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(REALLOC_BINARY) $(REALLOC_SOURCES)

# Analyze rule to analyze all sources
analyze:
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(ALLOC_FREE_DIFFERENT_FUNCTIONS_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(ERROR_HANDLING_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(ALLOC_FREE_SAME_FUNCTION_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(GLOBAL_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(CALLOC_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(MALLOC_FREE_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(MEMORY_LEAK_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(DANGLING_POINTER_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(NULL_AFTER_FREE_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(DOUBLE_FREE_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(REALLOC_SOURCES) -c

# Clang-tidy rule to lint all sources
clang-tidy:
	clang-tidy -quiet --warnings-as-errors=* -checks='*,-cert-err33-c,-clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling,-readability-identifier-length,-llvmlibc-restrict-system-libc-headers,-cppcoreguidelines-init-variables,-altera-unroll-loops,-llvm-header-guard,-cppcoreguidelines-avoid-magic-numbers,-readability-magic-numbers,-misc-unused-parameters,-android-cloexec-dup,-android-cloexec-open,-android-cloexec-creat,-android-cloexec-fopen,-bugprone-easily-swappable-parameters,-altera-id-dependent-backward-branch,-altera-struct-pack-align' \
    $(ALLOC_FREE_DIFFERENT_FUNCTIONS_SOURCES) $(ERROR_HANDLING_SOURCES) $(ALLOC_FREE_SAME_FUNCTION_SOURCES) \
    $(GLOBAL_SOURCES) $(CALLOC_SOURCES) $(MALLOC_FREE_SOURCES) $(MEMORY_LEAK_SOURCES) \
    $(DANGLING_POINTER_SOURCES) $(NULL_AFTER_FREE_SOURCES) $(DOUBLE_FREE_SOURCES) $(REALLOC_SOURCES) -- $(CFLAGS)

# Cppcheck rule to perform static analysis on all sources
cppcheck:
	cppcheck --enable=all --error-exitcode=1 --inconclusive --check-level=exhaustive --inline-suppr --suppress=missingIncludeSystem --checkers-report=$(CHECKER_REPORT_FILE) --quiet \
	$(ALLOC_FREE_DIFFERENT_FUNCTIONS_SOURCES) $(ERROR_HANDLING_SOURCES) $(ALLOC_FREE_SAME_FUNCTION_SOURCES) \
    $(GLOBAL_SOURCES) $(CALLOC_SOURCES) $(MALLOC_FREE_SOURCES) $(MEMORY_LEAK_SOURCES) \
    $(DANGLING_POINTER_SOURCES) $(NULL_AFTER_FREE_SOURCES) $(DOUBLE_FREE_SOURCES) $(REALLOC_SOURCES)

clang-format:
	clang-format -i -- $(ALLOC_FREE_DIFFERENT_FUNCTIONS_SOURCES) $(ERROR_HANDLING_SOURCES) $(ALLOC_FREE_SAME_FUNCTION_SOURCES) \
    $(GLOBAL_SOURCES) $(CALLOC_SOURCES) $(MALLOC_FREE_SOURCES) $(MEMORY_LEAK_SOURCES) \
    $(DANGLING_POINTER_SOURCES) $(NULL_AFTER_FREE_SOURCES) $(DOUBLE_FREE_SOURCES) $(REALLOC_SOURCES)

# Clean rule to remove binaries and reports
clean:
	rm -f $(ALLOC_FREE_DIFFERENT_FUNCTIONS_BINARY) $(ERROR_HANDLING_BINARY) $(ALLOC_FREE_SAME_FUNCTION_BINARY) \
	$(GLOBAL_BINARY) $(CALLOC_BINARY) $(MALLOC_FREE_BINARY) $(MEMORY_LEAK_BINARY) \
	$(DANGLING_POINTER_BINARY) $(NULL_AFTER_FREE_BINARY) $(DOUBLE_FREE_BINARY) $(REALLOC_BINARY)
	rm -f $(CHECKER_REPORT_FILE)
	rm -rf $(REPORT_DIR)
	find . -name '*.plist' -delete
	find . -name '*.o' -delete
	find . -name '*.dSYM' -exec rm -rf {} +
