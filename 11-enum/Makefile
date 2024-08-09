ifeq ($(CC),cc)
    CC = gcc
endif

CFLAGS = -Wall -Wextra -Werror -pedantic -Wconversion -Wshadow -Wformat=2 -Winit-self -Wswitch-default \
         -Wswitch-enum -Wfloat-equal -Wcast-align -Wpointer-arith -Wmissing-prototypes -Wstrict-prototypes \
         -Wundef -Wstrict-overflow=5 -Wwrite-strings -Wredundant-decls -Winline -Wvla -Wdouble-promotion \
         -Wdeclaration-after-statement
SANITIZERS = -fsanitize=address -fsanitize=undefined -fsanitize=leak
SUPPORTED_SANITIZERS =
CHECKER_REPORT_FILE = cppcheck-report.txt
REPORT_DIR = scan-results
SOURCES = main.c
BINARY = enum

# Attempt to compile with each sanitizer to check support
CHECK_SANITIZER = \
	$(shell echo "int main(){}" > sanitizer_check.c; \
	if $(CC) $(1) sanitizer_check.c -o /dev/null > /dev/null 2>&1; then echo $(1); fi; \
	rm -f sanitizer_check.c)

SUPPORTED_SANITIZERS += $(call CHECK_SANITIZER,-fsanitize=address)
SUPPORTED_SANITIZERS += $(call CHECK_SANITIZER,-fsanitize=undefined)
SUPPORTED_SANITIZERS += $(call CHECK_SANITIZER,-fsanitize=leak)

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

all: $(BINARY) analyze clang-tidy cppcheck

$(BINARY): $(SOURCES)
	$(CC) -std=c17 $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(BINARY) $(SOURCES)

analyze:
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(SOURCES) -c

clang-tidy:
	clang-tidy $(SOURCES) -quiet -checks='*,-cert-err33-c,-clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling,-readability-identifier-length,-llvmlibc-restrict-system-libc-headers,-cppcoreguidelines-init-variables,-altera-unroll-loops,-llvm-header-guard' -- $(CFLAGS)

cppcheck:
	cppcheck --enable=all --inconclusive --suppress=missingIncludeSystem --checkers-report=$(CHECKER_REPORT_FILE) $(SOURCES)

clean:
	rm -f $(BINARY)
	rm -f $(CHECKER_REPORT_FILE)
	rm -rf $(REPORT_DIR)
	find . -name '*.plist' -delete
	find . -name '*.o' -delete
