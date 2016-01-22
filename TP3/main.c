#include "ctx.h"
#include "./hw/hw.h"
#include "sem.h"
#include <string.h>
#include "library.h"

void f_ping(void *arg);
void f_pong(void *arg);
void producteur(void *arg);
void consommateur(void *arg);

struct sem_s * mutex;
struct sem_s * fullSem;
struct sem_s * emptySem;

int main(int argc, char *argv[])
{
    /*capture the command(s)*/
    char command[50], esperluete;
    int i = 0;
    scanf("%50s", command);
    /*while(command[i] != '\0'){
	esperluete = command[i];
	i++;
    }
    printf("%c\n", esperluete);*/
    execute(command);

    /*start the schedule*/
    start_sched();
    exit(EXIT_SUCCESS);
}

