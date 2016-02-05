Dans l'ordonnanceur, attendre un input, le capturer, s'il n'y a pas de & lancer la commande dans le même contexte que celui courant, sinon lancer dans un autre contexte.
Si la commmande n'existe pas -> return "command not found"
On doit pouvoir faire compute & "Entrée" ps

Faire les méthodes suivantes : 
    -ps -> affiche les différents contextes
    -compute -> lance un calcul qui effectue un certain temps
    -cat -> lis un fichier
    -ls -> affiche les fichiers du répertoire courant
    
Faire deux fichiers de test:
    -le premier qui lance un formatage et un read en meme temps par exemple qui montre que l'on a régler les problèmes d'accès concurences au disque
    -le deuxième qui montre qu'un compute tout seul n'a pas un temps très différent d'un compute en parallère d'un format.
