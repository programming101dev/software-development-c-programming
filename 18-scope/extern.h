#ifndef EXTERN_H
#define EXTERN_H

void example(void);

extern int shared_var;    // NOLINT(cppcoreguidelines-avoid-non-const-global-variables)

#endif    // EXTERN_H
