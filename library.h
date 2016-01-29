#ifndef _LIBRARY_
#define _LIBRARY_

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "ctx.h"

typedef int (fct)();

struct cmd_s{
    char * name;
    func_t *func;
    char *help;
};

extern func_t *execute(const char *name);
extern void loop(void);
extern void fonctionPS();
extern void fonctionLS();
extern void fonctionCAT();
extern void fonctionCompute();

#endif
