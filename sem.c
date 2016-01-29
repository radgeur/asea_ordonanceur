#include "sem.h"

void sem_init(struct sem_s * sem,unsigned int val){
  sem->cpt = val;
  sem->first_ctx_bloque=NULL;
}

void sem_down(struct sem_s * sem){
  irq_disable();
  sem->cpt--;
  if(sem->cpt<0){
    current_ctx->ctx_state = CTX_BLOQ;
    current_ctx->next_ctx_bloque = sem->first_ctx_bloque;
    sem->first_ctx_bloque = current_ctx;
    irq_enable();
    yield();
  }
  else{
    irq_enable();
  }
}

void sem_up(struct sem_s * sem){
  irq_disable();
  sem->cpt++;
  if(sem->cpt<=0){
    sem->first_ctx_bloque->ctx_state =CTX_EXEQ;
    sem->first_ctx_bloque=sem->first_ctx_bloque->next_ctx_bloque;
  }
  irq_enable();
}
