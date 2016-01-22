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
    char scanCommand[50], esperluete;
    char * command;
    int i = 0;

    /*catch the command to execute*/
    scanf("%50s", scanCommand);

    /*test if the last character of the string is '&'*/
    while(scanCommand[i] != '\0'){
	esperluete = scanCommand[i];
	i++;
    }

    /*execute the commands*/
    if(esperluete == '&') {
	while(esperluete == '&') {
	    command = strtok(scanCommand, "&");
	    strcpy(scanCommand, command);
	    execute(scanCommand);
	    i=0;
	    scanf("%50s", scanCommand);
	    while(scanCommand[i] != '\0'){
		esperluete = scanCommand[i];
		i++;
	    }	    
	}
	command = strtok(scanCommand, "&");
	strcpy(scanCommand, command);
	execute(scanCommand);
    }else
	execute(scanCommand);

    /*start the schedule*/
    start_sched();
    exit(EXIT_SUCCESS);
}

