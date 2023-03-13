#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "Structures.h"

/*------------------------*/
int static nb_homme = 0;
int static nb_femme = 0;
/*------------------------*/



/*----------------------------------------------------*/
int seekClient(char *file_name, Client *full_name){
    FILE *file = NULL;
    int b = 2048;
    Bool registred = FALSE;
    char temp[b];

    if((fopen_s(&file, file_name, "r")) != NULL){
        return (-1);
    }

	while(fgets(temp, sizeof(temp), file) != NULL) {
		if((strstr(temp, full_name)) != NULL) {
			registred = TRUE;
		}
	}

    if(file){
        fclose(file);
    }

    return registred;
}
/*----------------------------------------------------*/

/*=================================================================================*/
void seekClientGender(Client *full_name, Client *cl_sexe){
    FILE *file = NULL;
    int b = 2048;
    signed char temp[b];
    signed char file_name[] = "clients.txt";

    if(!seekClient(file_name, full_name)){
        printf("\n> Vous n'%ctes pas encore client pour entrer...", 136);
        printf("\nPour s'inscrir, veuillez tapez la commande '!inscription'...");        
    } else {
        if((fopen_s(&file, file_name, "r")) != NULL){
            return (-1);
        }
        while(fgets(temp, sizeof(temp), file) != NULL){
            if((strstr(temp, full_name)) != NULL){ 
                fgets(temp, sizeof(temp), file);
                if(strstr(temp , "homme")){
                    strcpy(cl_sexe, "homme");
                } else if(strstr(temp, "femme")){
                    strcpy(cl_sexe, "femme");
                } else {
                    printf("\n> Veuillez donner votre sexe (Homme / Femme)..."); 
                    scanf("%s", cl_sexe);
                    strcpy(cl_sexe, strlwr(cl_sexe));
                }
            }
        }
    }
}
/*=================================================================================*/


/*==================================================================================*/
int verifyEntry(Client *full_name, Client *cl_sexe){
    seekClientGender(full_name, cl_sexe);
    if(!strcmp(cl_sexe, "homme")){
        if(nb_homme >= 40){
            printf("> D%csol%c, la salle supporte le nombre max d'hommes...", 130, 130);
            printf("Veuillez revenir plus tard...");                    
        } else {
            nb_homme += 1;
            printf("> Vous pouvez entrer dans la salle...Bon entra%cnement!", 140);
            printf("\n> Nombre d'hommes dans la salle: %d", nb_homme);                  
        }
    }
    if(!strcmp(cl_sexe, "femme")){
        if(nb_femme >= 40){
            printf("> D%csol%c, la gym supporte le nombre max de femmes...", 130, 130);
            printf("\nVeuillez revenir plus tard..."); 
        } else {
            nb_femme += 1;
            printf("> Vous pouvez entrer dans la gym...Bon entra%cnement!", 140); 
            printf("\n> Nombre de femmes dans la gym: %d", nb_femme);
        }
    }        
}
/*==================================================================================*/


/*============================================================================*/
int verifyExit(Client *full_name, Client *cl_sexe){
    seekClientGender(full_name, cl_sexe);
    if(!strcmp(cl_sexe, "homme")){
        nb_homme -= 1;
        printf("\n> Le client %s est sorti...", full_name);
        printf("\n> Nombre d'hommes dans la salle: %d", nb_femme);  
    } else {
        printf("\n> Vous n'%ctes pas dans la salle pour sortir...", 136);
    }
    if(!strcmp(cl_sexe, "femme")){
        nb_femme -= 1;
        printf("\n> La cliente %s est sortie...", full_name);
        printf("\n> Nombre de femmes dans la gym: %d", nb_femme);
    }
}
/*============================================================================*/



#endif // FONCTIONS_H_INCLUDED