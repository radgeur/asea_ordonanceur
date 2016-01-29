#ifndef _CTX_
#define _CTX_

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "./hw/hw.h"

#define CTX_MAGIC 0xCAFEBABE

typedef void (func_t) (void *);

enum ctx_state_e {CTX_INIT, CTX_EXEQ, CTX_END, CTX_BLOQ};

struct ctx_s {
  unsigned int ctx_magic;
  void *ctx_esp;
  void *ctx_ebp;
  char *ctx_base;
  enum ctx_state_e ctx_state;
  func_t *ctx_F;
  void * ctx_args;
  struct ctx_s * next_ctx;
  struct ctx_s * next_ctx_bloque;
};

struct ctx_s *current_ctx;
struct ctx_s *ctx_ring;

extern void init_ctx(struct ctx_s *ctx, int stack_size, func_t *f, void *args);

extern void switch_to_ctx (struct ctx_s *ctx);

extern void create_ctx(int stack_size, func_t *f, void *args);

extern void yield();

extern void start_sched();

#endif
