#ifndef _LIBRARY_
#define _CTX_

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

typedef int (fct)();

struct cmd_s{
    char * name;
    fct * func;
    char *help;
};

extern void execute(const char *name);
extern void loop(void);
extern int fonctionPS();
extern int fonctionLS();
extern int fonctionCAT();
extern int fonctionCompute();

#endif
