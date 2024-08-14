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
MEMCPY_SOURCES = memcpy.c
MEMCPY_BINARY = memcpy
STRCAT_SOURCES = strcat.c
STRCAT_BINARY = strcat
STRCHR_SOURCES = strchr.c
STRCHR_BINARY = strchr
STRCMP_SOURCES = strcmp.c
STRCMP_BINARY = strcmp
STRCPY_SOURCES = strcpy.c
STRCPY_BINARY = strcpy
STRDUP_SOURCES = strdup.c
STRDUP_BINARY = strdup
STRLEN_SOURCES = strlen.c
STRLEN_BINARY = strlen
STRNCAT_SOURCES = strncat.c
STRNCAT_BINARY = strncat
STRNCMP_SOURCES = strncmp.c
STRNCMP_BINARY = strncmp
STRNCPY_SOURCES = strncpy.c
STRNCPY_BINARY = strncpy
STRPBRK_SOURCES = strpbrk.c
STRPBRK_BINARY = strpbrk
STRRCHR_SOURCES = strrchr.c
STRRCHR_BINARY = strrchr
STRSTR_SOURCES = strstr.c
STRSTR_BINARY = strstr
STRTOK_R_SOURCES = strtok_r.c
STRTOK_R_BINARY = strtok_r

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
all: clang-format $(MEMCPY_BINARY) $(STRCAT_BINARY) $(STRCHR_BINARY) $(STRCMP_BINARY) $(STRCPY_BINARY) \
     $(STRDUP_BINARY) $(STRLEN_BINARY) $(STRNCAT_BINARY) $(STRNCMP_BINARY) $(STRNCPY_BINARY) \
     $(STRPBRK_BINARY) $(STRRCHR_BINARY) $(STRSTR_BINARY) $(STRTOK_R_BINARY) analyze clang-tidy cppcheck

# Build rules for each binary
$(MEMCPY_BINARY): $(MEMCPY_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(MEMCPY_BINARY) $(MEMCPY_SOURCES)

$(STRCAT_BINARY): $(STRCAT_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(STRCAT_BINARY) $(STRCAT_SOURCES)

$(STRCHR_BINARY): $(STRCHR_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(STRCHR_BINARY) $(STRCHR_SOURCES)

$(STRCMP_BINARY): $(STRCMP_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(STRCMP_BINARY) $(STRCMP_SOURCES)

$(STRCPY_BINARY): $(STRCPY_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(STRCPY_BINARY) $(STRCPY_SOURCES)

$(STRDUP_BINARY): $(STRDUP_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(STRDUP_BINARY) $(STRDUP_SOURCES)

$(STRLEN_BINARY): $(STRLEN_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(STRLEN_BINARY) $(STRLEN_SOURCES)

$(STRNCAT_BINARY): $(STRNCAT_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(STRNCAT_BINARY) $(STRNCAT_SOURCES)

$(STRNCMP_BINARY): $(STRNCMP_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(STRNCMP_BINARY) $(STRNCMP_SOURCES)

$(STRNCPY_BINARY): $(STRNCPY_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(STRNCPY_BINARY) $(STRNCPY_SOURCES)

$(STRPBRK_BINARY): $(STRPBRK_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(STRPBRK_BINARY) $(STRPBRK_SOURCES)

$(STRRCHR_BINARY): $(STRRCHR_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(STRRCHR_BINARY) $(STRRCHR_SOURCES)

$(STRSTR_BINARY): $(STRSTR_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(STRSTR_BINARY) $(STRSTR_SOURCES)

$(STRTOK_R_BINARY): $(STRTOK_R_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(STRTOK_R_BINARY) $(STRTOK_R_SOURCES)

# Analyze rule to analyze all sources
analyze:
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(MEMCPY_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(STRCAT_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(STRCHR_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(STRCMP_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(STRCPY_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(STRDUP_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(STRLEN_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(STRNCAT_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(STRNCMP_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(STRNCPY_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(STRPBRK_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(STRRCHR_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(STRSTR_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(STRTOK_R_SOURCES) -c

# Clang-tidy rule to lint all sources
clang-tidy:
	clang-tidy $(MEMCPY_SOURCES) $(STRCAT_SOURCES) $(STRCHR_SOURCES) $(STRCMP_SOURCES) $(STRCPY_SOURCES) \
	$(STRDUP_SOURCES) $(STRLEN_SOURCES) $(STRNCAT_SOURCES) $(STRNCMP_SOURCES) $(STRNCPY_SOURCES) \
	$(STRPBRK_SOURCES) $(STRRCHR_SOURCES) $(STRSTR_SOURCES) $(STRTOK_R_SOURCES) \
	-quiet -checks='*,-cert-err33-c,-clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling,-readability-identifier-length,-llvmlibc-restrict-system-libc-headers,-cppcoreguidelines-init-variables,-altera-unroll-loops,-llvm-header-guard,-cppcoreguidelines-avoid-magic-numbers,-readability-magic-numbers' -- $(CFLAGS)

# Cppcheck rule to perform static analysis on all sources
cppcheck:
	cppcheck --enable=all --inconclusive --inline-suppr --suppress=missingIncludeSystem --checkers-report=$(CHECKER_REPORT_FILE) --quiet \
	$(MEMCPY_SOURCES) $(STRCAT_SOURCES) $(STRCHR_SOURCES) $(STRCMP_SOURCES) $(STRCPY_SOURCES) \
	$(STRDUP_SOURCES) $(STRLEN_SOURCES) $(STRNCAT_SOURCES) $(STRNCMP_SOURCES) $(STRNCPY_SOURCES) \
	$(STRPBRK_SOURCES) $(STRRCHR_SOURCES) $(STRSTR_SOURCES) $(STRTOK_R_SOURCES)

clang-format:
	clang-format -i -- $(MEMCPY_SOURCES) $(STRCAT_SOURCES) $(STRCHR_SOURCES) $(STRCMP_SOURCES) $(STRCPY_SOURCES) \
	$(STRDUP_SOURCES) $(STRLEN_SOURCES) $(STRNCAT_SOURCES) $(STRNCMP_SOURCES) $(STRNCPY_SOURCES) \
	$(STRPBRK_SOURCES) $(STRRCHR_SOURCES) $(STRSTR_SOURCES) $(STRTOK_R_SOURCES)

# Clean rule to remove binaries and reports
clean:
	rm -f $(MEMCPY_BINARY) $(STRCAT_BINARY) $(STRCHR_BINARY) $(STRCMP_BINARY) $(STRCPY_BINARY) \
	$(STRDUP_BINARY) $(STRLEN_BINARY) $(STRNCAT_BINARY) $(STRNCMP_BINARY) $(STRNCPY_BINARY) \
	$(STRPBRK_BINARY) $(STRRCHR_BINARY) $(STRSTR_BINARY) $(STRTOK_R_BINARY)
	rm -f $(CHECKER_REPORT_FILE)
	rm -rf $(REPORT_DIR)
	find . -name '*.plist' -delete
	find . -name '*.o' -delete
