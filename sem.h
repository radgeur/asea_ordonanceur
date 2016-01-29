#ifndef _SEM_
#define _SEM_

#include "ctx.h"

struct sem_s{
  int cpt;
  struct ctx_s * first_ctx_bloque;
};

extern void sem_init(struct sem_s * sem, unsigned int val);

extern void sem_down(struct sem_s * sem);

extern void sem_up(struct sem_s * sem);

#endif
