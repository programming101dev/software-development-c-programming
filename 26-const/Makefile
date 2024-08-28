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
CONST_ARRAY_PARAMETER_SOURCES = const-array-parameter.c
CONST_ARRAY_PARAMETER_BINARY = const-array-parameter

CONST_POINTER_PARAMETER_SOURCES = const-pointer-parameter.c
CONST_POINTER_PARAMETER_BINARY = const-pointer-parameter

CONST_POINTER_TO_CONST_DATA_SOURCES = const-pointer-to-const-data.c
CONST_POINTER_TO_CONST_DATA_BINARY = const-pointer-to-const-data

CONST_POINTER_TO_NON_CONST_DATA_SOURCES = const-pointer-to-non-const-data.c
CONST_POINTER_TO_NON_CONST_DATA_BINARY = const-pointer-to-non-const-data

CONST_VALUE_PARAMETER_SOURCES = const-value-parameter.c
CONST_VALUE_PARAMETER_BINARY = const-value-parameter

CONST_VARIABLE_SOURCES = const-variable.c
CONST_VARIABLE_BINARY = const-variable

GLOBAL_SOURCES = global.c
GLOBAL_BINARY = global

POINTER_TO_CONST_DATA_SOURCES = pinter-to-const-data.c
POINTER_TO_CONST_DATA_BINARY = pinter-to-const-data

RETURN_SOURCES = return.c
RETURN_BINARY = return

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
all: clang-format $(CONST_ARRAY_PARAMETER_BINARY) $(CONST_POINTER_PARAMETER_BINARY) $(CONST_POINTER_TO_CONST_DATA_BINARY) \
     $(CONST_POINTER_TO_NON_CONST_DATA_BINARY) $(CONST_VALUE_PARAMETER_BINARY) $(CONST_VARIABLE_BINARY) \
     $(GLOBAL_BINARY) $(POINTER_TO_CONST_DATA_BINARY) $(RETURN_BINARY) \
     analyze clang-tidy cppcheck

# Build rules for each binary
$(CONST_ARRAY_PARAMETER_BINARY): $(CONST_ARRAY_PARAMETER_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(CONST_ARRAY_PARAMETER_BINARY) $(CONST_ARRAY_PARAMETER_SOURCES)

$(CONST_POINTER_PARAMETER_BINARY): $(CONST_POINTER_PARAMETER_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(CONST_POINTER_PARAMETER_BINARY) $(CONST_POINTER_PARAMETER_SOURCES)

$(CONST_POINTER_TO_CONST_DATA_BINARY): $(CONST_POINTER_TO_CONST_DATA_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(CONST_POINTER_TO_CONST_DATA_BINARY) $(CONST_POINTER_TO_CONST_DATA_SOURCES)

$(CONST_POINTER_TO_NON_CONST_DATA_BINARY): $(CONST_POINTER_TO_NON_CONST_DATA_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(CONST_POINTER_TO_NON_CONST_DATA_BINARY) $(CONST_POINTER_TO_NON_CONST_DATA_SOURCES)

$(CONST_VALUE_PARAMETER_BINARY): $(CONST_VALUE_PARAMETER_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(CONST_VALUE_PARAMETER_BINARY) $(CONST_VALUE_PARAMETER_SOURCES)

$(CONST_VARIABLE_BINARY): $(CONST_VARIABLE_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(CONST_VARIABLE_BINARY) $(CONST_VARIABLE_SOURCES)

$(GLOBAL_BINARY): $(GLOBAL_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(GLOBAL_BINARY) $(GLOBAL_SOURCES)

$(POINTER_TO_CONST_DATA_BINARY): $(POINTER_TO_CONST_DATA_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(POINTER_TO_CONST_DATA_BINARY) $(POINTER_TO_CONST_DATA_SOURCES)

$(RETURN_BINARY): $(RETURN_SOURCES)
	$(CC) $(CFLAGS) $(SUPPORTED_SANITIZERS) -o $(RETURN_BINARY) $(RETURN_SOURCES)

# Analyze rule to analyze all sources
analyze:
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(CONST_ARRAY_PARAMETER_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(CONST_POINTER_PARAMETER_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(CONST_POINTER_TO_CONST_DATA_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(CONST_POINTER_TO_NON_CONST_DATA_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(CONST_VALUE_PARAMETER_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(CONST_VARIABLE_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(GLOBAL_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(POINTER_TO_CONST_DATA_SOURCES) -c
	$(ANALYZER) $(ANALYZER_FLAGS) $(CC) $(CFLAGS) $(ANALYSIS_FLAGS) $(RETURN_SOURCES) -c

# Clang-tidy rule to lint all sources
clang-tidy:
	clang-tidy -quiet --warnings-as-errors=* -checks='*,-cert-err33-c,-clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling,-readability-identifier-length,-llvmlibc-restrict-system-libc-headers,-cppcoreguidelines-init-variables,-altera-unroll-loops,-llvm-header-guard,-cppcoreguidelines-avoid-magic-numbers,-readability-magic-numbers,-misc-unused-parameters,-android-cloexec-dup,-android-cloexec-open,-android-cloexec-creat,-android-cloexec-fopen,-bugprone-easily-swappable-parameters,-altera-id-dependent-backward-branch,-altera-struct-pack-align' \
    $(CONST_ARRAY_PARAMETER_SOURCES) $(CONST_POINTER_PARAMETER_SOURCES) $(CONST_POINTER_TO_CONST_DATA_SOURCES) \
    $(CONST_POINTER_TO_NON_CONST_DATA_SOURCES) $(CONST_VALUE_PARAMETER_SOURCES) $(CONST_VARIABLE_SOURCES) \
    $(GLOBAL_SOURCES) $(POINTER_TO_CONST_DATA_SOURCES) $(RETURN_SOURCES) -- $(CFLAGS)

# Cppcheck rule to perform static analysis on all sources
cppcheck:
	cppcheck --enable=all --error-exitcode=1 --inconclusive --check-level=exhaustive --inline-suppr --suppress=missingIncludeSystem --checkers-report=$(CHECKER_REPORT_FILE) --quiet \
	$(CONST_ARRAY_PARAMETER_SOURCES) $(CONST_POINTER_PARAMETER_SOURCES) $(CONST_POINTER_TO_CONST_DATA_SOURCES) \
	$(CONST_POINTER_TO_NON_CONST_DATA_SOURCES) $(CONST_VALUE_PARAMETER_SOURCES) $(CONST_VARIABLE_SOURCES) \
	$(GLOBAL_SOURCES) $(POINTER_TO_CONST_DATA_SOURCES) $(RETURN_SOURCES)

clang-format:
	clang-format -i -- $(CONST_ARRAY_PARAMETER_SOURCES) $(CONST_POINTER_PARAMETER_SOURCES) $(CONST_POINTER_TO_CONST_DATA_SOURCES) \
	$(CONST_POINTER_TO_NON_CONST_DATA_SOURCES) $(CONST_VALUE_PARAMETER_SOURCES) $(CONST_VARIABLE_SOURCES) \
	$(GLOBAL_SOURCES) $(POINTER_TO_CONST_DATA_SOURCES) $(RETURN_SOURCES)

# Clean rule to remove binaries and reports
clean:
	rm -f $(CONST_ARRAY_PARAMETER_BINARY) $(CONST_POINTER_PARAMETER_BINARY) $(CONST_POINTER_TO_CONST_DATA_BINARY) $(CONST_POINTER_TO_NON_CONST_DATA_BINARY) $(CONST_VALUE_PARAMETER_BINARY) $(CONST_VARIABLE_BINARY) $(GLOBAL_BINARY) $(POINTER_TO_CONST_DATA_BINARY) $(RETURN_BINARY)
	rm -f $(CHECKER_REPORT_FILE)
	rm -rf $(REPORT_DIR)
	find . -name '*.plist' -delete
	find . -name '*.o' -delete
	find . -name '*.dSYM' -exec rm -rf {} +
