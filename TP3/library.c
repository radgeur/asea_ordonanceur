#include "library.h"

struct cmd_s commands [4] = {
    {"ps", fonctionPS, 	"Afficher la liste des processus"},
    {"ls",  fonctionLS,	"Afficher liste des repertoires"},
    {"cat",  fonctionCAT,	"Afficher le contenu des fichiers"},
    {"compute", fonctionCompute,	"Fonction de calcul"}
};

void execute(const char *name){
    unsigned int i = 0;
    while (i<(sizeof(commands)/sizeof(commands[0])) && (strcmp(name, commands[i].name) != 0))
  	i++;
    if(i<(sizeof(commands)/sizeof(commands[0])))
	(commands[i].func)();
    else
	printf("command not found \n");
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
    int n, first = 0, second = 1, next, c;
 
    printf("Entrez le nombre de termes\n");
    scanf("%d",&n);
 
    printf("Premiers %d termes de la serie de Fibonacci sont :\n",n);
 
    for ( c = 0 ; c < n ; c++ )
	{
	    if ( c <= 1 )
		next = c;
	    else
		{
		    next = first + second;
		    first = second;
		    second = next;
		}
	    printf("%d\n",next);
	}
    return 0;
}
