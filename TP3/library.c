#include "library.h"

struct cmd_s commands [4] = {
    {"ps", fonctionPS, 	"Afficher la liste des processus"},
    {"ls",  fonctionLS,	"Afficher liste des repertoires"},
    {"cat",  fonctionCAT,	"Afficher le contenu des fichiers"},
    {"compute", fonctionCompute,	"Fonction de calcul"}
};

void execute(const char *name){
    int i = 0;
    while (i<4 && (strcmp(name, commands[i].name) != 0))
  	i++;
    (commands[i].func)();
}

void loop(void){
    char name[64];

    while (printf("> "), scanf("%62s", name) == 1)
  	execute(name) ;
}



int fonctionPS(){
    printf ("L'identifiant du processus est %d\n", (int) getpid ());
    return 0;
}



int fonctionLS(){
    int return_value;
    return_value = system("ls");
    return return_value;
}



int fonctionCAT(){
    int return_value;
    return_value = system ("cat");
    return return_value;
}



int fonctionCompute(){
    int return_value1=10,return_value2=42;
    int result = return_value1+return_value2;

    return result;
}
