#include "ctx.h"
#include "sem.h"
#include <string.h>
#include "library.h"
#include "disk/lib_hardware.h"

int main(int argc, char *argv[])
{
    /*capture the command(s)*/
    char scanCommand[50], esperluete;
    char * command;
    int i = 0;

    if(init_hardware("hardware.ini") == 0) {
	fprintf(stderr, "Error in hardware initialization\n");
	exit(EXIT_FAILURE);
    }

    /* Interrupt handlers */
    for(i=0; i<16; i++)
	IRQVECTOR[i] = empty_it;

    /* Allows all IT */
    _mask(1);
    chk_hda();

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
	    create_ctx(16384, execute(scanCommand), NULL);
	    i=0;
	    scanf("%50s", scanCommand);
	    while(scanCommand[i] != '\0'){
		esperluete = scanCommand[i];
		i++;
	    }	    
	}
	command = strtok(scanCommand, "&");
	strcpy(scanCommand, command);
	func_t * toexec = execute(scanCommand);
	toexec(NULL);
    }
    else{
	func_t * toexec = execute(scanCommand);
	toexec(NULL);
	printf("coucou\n");
    }
	
    /*start the schedule*/
    start_sched();
    exit(EXIT_SUCCESS);
}

