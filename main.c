#include <stdio.h>
#include <string.h>

#include "Structures.h"
#include "Commands.h"


int main()
{
    signed char command[32];

    commandMessage();
    Bool connected = TRUE;
    while(connected){            
        Client cl = {};

        printf("\n\nEntrez une commande: "); scanf("%s", command);

        if(!strcmp(command, "!menu")){
            menuMessage();
        }

        if(!strcmp(command, "!horaires")){
            horairesMessage();
        }

        if(!strcmp(command, "!inscription")){
            addClient(&cl);
        }

        if(!strcmp(command, "!entrer")){
            clientEntrer();
        }

        if(!strcmp(command, "!sortir")){
            clientSortir();
        }

        if(!strcmp(command, "!exit")){
            connected = FALSE;
        }
    }
    return 0;
}