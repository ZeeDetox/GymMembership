#ifndef COMMANDS_H_INCLUDED
#define COMMANDS_H_INCLUDED


#include <stdio.h>
#include <string.h>
#include <time.h>

#include "Structures.h"
#include "Fonctions.h"



/*-------------------------------------------------------------------*/
void commandMessage(void){
    printf("Notre liste de commandes...\n\n");
    printf("-----------------------------------------------\n");
    printf("-----         Espace inscription          -----\n");
    printf("---     !menu (pour afficher le menu)       ---\n");
    printf("---     !inscription (pour s'inscrir)       ---\n");
    printf("---                                         ---\n");
    printf("-----            Espace client            -----\n");
    printf("---  !horaires (pour afficher les horaires) ---\n");
    printf("---  !entrer (poue entrer s'entra%cner)      ---\n", 140);
    printf("---  !sortir (poue sortir de la salle)      ---\n");
    printf("-----------------------------------------------\n");
    printf("\n\n");
}
/*-------------------------------------------------------------------*/


/*-------------------------------------------------------------------------*/
void horairesMessage(void){
    printf("-------------[Nos horaires d'ouverture]-------------\n");
    printf("- Du lundi au vendredi...                           \n");
    printf("    10h -> 13h                                      \n");
    printf("    15h -> 22h                                      \n");
    printf("- Samedi...                                         \n");
    printf("    11h -> 14h                                      \n");
    printf("- Dimanche...                                       \n");
    printf("    Ferm%c                                          \n", 130);
    printf("----------------------------------------------------\n\n\n");
}
/*-------------------------------------------------------------------------*/



/*===========================================================================*/
void menuMessage(void){
    printf("|==================================================|\n");
    printf("|                      M E N U                     |\n");
    printf("|==================================================|\n");
    printf("|                                                  |\n");
    printf("| > Nos tarifs:                                    |\n");
    printf("|     - Enfant -> 300 DH/Mois                      |\n");
    printf("|     - Jeune  -> 400 DH/Mois                      |\n");
    printf("|     - Adulte -> 600 DH/Mois                      |\n");
    printf("|                                                  |\n");
    printf("|                                                  |\n");
    printf("| > Nos r%cductions de saison:                      |\n", 130);
    printf("|     - Hiver   (H): -20%%                          |\n");
    printf("|     - Ete     (E): -25%%                          |\n");
    printf("|     - Automne (A): -15%%                          |\n");
    printf("|                                                  |\n");
    printf("|                                                  |\n");
    printf("| > Nos r%cductions sur certains quartiers:         |\n", 130);
    printf("|     -  Maarif   (1): -1%%                         |\n");
    printf("|     -  Lissasfa (2): -1.5%%                       |\n");
    printf("|     -  Bourgone (3): -2%%                         |\n");
    printf("|     -  Gauthier (4): -3%%                         |\n");
    printf("|                                                  |\n");
    printf("|                                                  |\n");
    printf("| > Nos 'pack famille' (pour adulte):              |\n");
    printf("|     - 0 %c 2 enfant(s) -> -5%%                     |\n", 133);
    printf("|     (-6%% avec partenaire)                        |\n");
    printf("|     - 3+ enfant(s)    -> -10%%                    |\n");
    printf("|     (-15%% avec partenaire)                       |\n");
    printf("|                                                  |\n");
    printf("|==================================================|\n");
    printf("|==================================================|\n\n\n");
}
/*===========================================================================*/



/*==========================================================================================================*/
void addClient(Client *cl){    
    signed char cl_nom_prenom[256], cl_prenom[256], cl_nom[256];
    signed char cl_tel[16], cl_email[128], cl_is_married[8] = "non", avec_partenaire[8], cl_sexe[8];
    int cl_age, cl_nbr_enfants = 0, cl_quartier = 0; 

    signed char paiement[8];
    char saison, quartier;
    float reduction_quartier, reduction_saison, reduction_famille = 0, prix_reduction;
    float client_prix_club, client_prix_total;

    signed char accord_tennis[8], accord_basket[8], accord_piscine[8], accord_volleyball[8], accord_football[8];
    float prix_sports, reduction_sports, prix_total_sports;
    

    printf("\n> Donnez votre pr%cnom: ", 130); scanf("%s", cl_prenom);
    strcpy(cl_prenom, strcat(cl_prenom, " "));
    printf("> Donnez votre nom: "); scanf("%s", cl_nom);
    strcpy(cl_nom_prenom, strlwr(strcat(cl_prenom, cl_nom)));


    if(!seekClient("clients.txt", cl_nom_prenom)){
        // Inscription disponible...

        printf("> Veuillez maintenant donner votre num%cro de t%cl%cphone: ", 130, 130, 130); scanf("%s", cl_tel);
        strcpy(cl -> numero_tel, cl_tel);
        printf("> Votre adress e-mail: "); scanf("%s", cl_email);
        strcpy(cl -> e_mail, cl_email);
        printf("> Votre sexe (Homme / Femme): "); scanf("%s", cl_sexe);
        strlwr(strcpy(cl -> sexe, cl_sexe));

        printf("> Veuillez indiquer la saison (voir menu): "); scanf(" %c", & saison);
        switch(saison){
            case 'H': reduction_saison = 0.2; break;
            case 'E': reduction_saison = 0.25; break;
            case 'A': reduction_saison = 0.15; break;
            default: reduction_saison = 0; break;
        }

        printf("> Veuillez indiquer le num%cro de votre quartier indiqu%c dans le menu (s'il y en a): ", 130, 130); scanf(" %c", & quartier);
        switch(quartier){
            case '1': reduction_quartier = 0.01; break;
            case '2': reduction_quartier = 0.015; break;
            case '3': reduction_quartier = 0.02; break;
            case '4': reduction_quartier = 0.03; break;
            default: reduction_quartier = 0; break;
        }

        printf("> Indiquez votre %cge: ", 131); scanf("%d", & cl_age);    
        if(cl_age){
            if(cl_age <= 12){
                client_prix_club = 300;
            } else if(cl_age < 25){
                client_prix_club = 400;
            } else {
                client_prix_club = 600;
                printf("> Etes-vous marri%c(e)? ", 130); scanf("%s", cl_is_married);    
                if(!strcmp(cl_is_married, "oui")){
                    printf("- Donnez le nombre d'enfants voulant s'inscrir: "); scanf("%d", & cl_nbr_enfants);    
                    if(cl_nbr_enfants){
                        printf("- Allez-vous emener votre partenaire avec vous? "); scanf("%s", avec_partenaire);
                        if(cl_nbr_enfants <= 2){
                            if(!strcmp(avec_partenaire, "oui")){
                                reduction_famille = 0.06;
                                client_prix_club = (client_prix_club * 2) + (300 * cl_nbr_enfants);
                            } else {
                                reduction_famille = 0.05;
                                client_prix_club = client_prix_club + (300 * cl_nbr_enfants);
                            }
                        }
                        if(cl_nbr_enfants > 2 && cl_nbr_enfants <= 5){
                            if(!strcmp(avec_partenaire, "oui")){
                                reduction_famille = 0.15;
                                client_prix_club = (client_prix_club * 2) + (300 * cl_nbr_enfants);
                            } else {
                                reduction_famille = 0.1;
                                client_prix_club = client_prix_club + (300 * cl_nbr_enfants);
                            }
                        } 
                        if(cl_nbr_enfants > 5){
                            if(!strcmp(avec_partenaire, "oui")){
                                client_prix_club = client_prix_club * 2;
                            }
                        }
                    }    
                }             
                           
            }
        }
        else{
            client_prix_club = 600;
        }                    

        cl -> nbr_enfants = cl_nbr_enfants;        
        cl -> age = cl_age;
        strcpy(cl -> is_married, cl_is_married);


        Sports prix = {0, 0, 0, 0, 0};
        printf("\n> On propose certains sports aussi: \n");
        printf("> Voulez-vous vous inscrir au tennis? "); scanf("%s", accord_tennis);
        strlwr(accord_tennis);
        if(!strcmp(accord_tennis, "oui") || !strcmp(accord_tennis, "ok")){
            prix.tennis = 2000;
        }
        printf("> Voulez-vous vous inscrir au basket? "); scanf("%s", accord_basket);
        strlwr(accord_basket);
        if(!strcmp(accord_basket, "oui") || !strcmp(accord_basket, "ok")){
            prix.basket = 1200;
        }
        printf("> Voulez-vous vous inscrir %c la piscine? ", 133); scanf("%s", accord_piscine);
        strlwr(accord_piscine);
        if(!strcmp(accord_piscine, "oui") || !strcmp(accord_piscine, "ok")){
            prix.piscine = 800;
        }
        printf("> Voulez-vous vous inscrir au volleyball? "); scanf("%s", accord_volleyball);
        strlwr(accord_volleyball);
        if(!strcmp(accord_volleyball, "oui") || !strcmp(accord_volleyball, "ok")){
            prix.volleyball = 1000;
        }
        printf("> Voulez-vous vous inscrir au football? "); scanf("%s", accord_football);
        strlwr(accord_football);
        if(!strcmp(accord_football, "oui") || !strcmp(accord_football, "ok")){
            prix.football = 1600;
        }
        prix_sports = prix.tennis + prix.basket + prix.piscine + prix.volleyball + prix.football;
        if(prix_sports <= 4000){
            reduction_sports = 0.08;
        } else if(prix_sports > 4000 && prix_sports <= 4500){
            reduction_sports = 0.1;
        } else {
            reduction_sports = 0.125;
        }


        prix_reduction =  (client_prix_club * (reduction_quartier + reduction_saison + reduction_famille));
        prix_total_sports = (prix_sports - (1 - reduction_sports));
        client_prix_total = (client_prix_club - prix_reduction + prix_total_sports);

        printf("\n\n=> Votre facture totale s'%cl%cve %c: %.3f DH/Mois.", 130, 138, 133, client_prix_total);
        printf("\n=> Etes vous pr%cts %c payer? ", 136, 133); scanf("%s", paiement);

        // Ajout du nouveau client(e) & sauvegarde de son profil...
        FILE *cl_write_file = NULL; 
        cl_write_file = fopen("clients.txt", "a");
        if(!strcmp(strlwr(paiement), "oui")){
            do{
                fprintf(cl_write_file, "{\n");
                fprintf(cl_write_file, "  Nom & prénom du client : %s\n", cl_nom_prenom);
                fprintf(cl_write_file, "  Sexe du client         : %s\n", cl -> sexe);
                fprintf(cl_write_file, "  Âge du client          : %d\n", cl -> age);
                fprintf(cl_write_file, "  Client marrié          : %s\n", cl -> is_married);
                fprintf(cl_write_file, "  Nombre d'enfants       : %d\n", cl -> nbr_enfants);
                fprintf(cl_write_file, "  Téléphone du client    : %s\n", cl -> numero_tel);
                fprintf(cl_write_file, "  Adress e-mail client   : %s\n", cl -> e_mail);
                fprintf(cl_write_file, "}\n\n");
            } while(cl_write_file == NULL); 
            printf("\nPaiement effectu%c...", 130);
            printf("\nProfile sauvegard%c...", 130);
            printf("\n\nBienvenue %c club %s ! Veuillez passer de bons moments !!\n\n", 133, cl_nom_prenom);  
        }                
        fclose(cl_write_file);        
    } else {
        printf("\n> Le client %s existe d%cja...\n", cl_nom_prenom, 130);
    }
    strcpy(cl_nom_prenom, "");
}
/*==========================================================================================================*/



/*==========================================================================================================*/
void clientEntrer(void){
    signed char cl_sexe[8], jour[16];
    signed char cl_nom_prenom[256], cl_prenom[256], cl_nom[256];
    int heure = 0;

    printf("\n> Donnez votre pr%cnom: ", 130); scanf("%s", cl_prenom);
    strcpy(cl_prenom, strcat(cl_prenom, " "));
    printf("> Donnez votre nom: "); scanf("%s", cl_nom);
    strcpy(cl_nom_prenom, strlwr(strcat(cl_prenom, cl_nom)));

    if(!seekClient("clients.txt", cl_nom_prenom)){
        printf("\n> Vous n'%ctes pas encore client...", 136);
        printf("\nTapez '!inscription' pour s'inscrir puis pouvoir entrer...");
    } else {
        if(clientOutside(cl_nom_prenom)){
            printf("\n> Donnez le jour: "); scanf("%s", jour);
            if((!strcmp(strlwr(jour), "lundi")) || (!strcmp(strlwr(jour), "mardi")) || (!strcmp(strlwr(jour), "mercredi")) || (!strcmp(strlwr(jour), "jeudi")) || (!strcmp(strlwr(jour), "vendredi"))){
                printf("\n> Donnez l'heure (sans minutes ni secondes)... "); scanf("%d", &heure);
                if(heure >= 0 && heure < 24){
                    if((heure >= 10 && heure < 13) || (heure >= 15 && heure < 22)){
                        verifyEntry(cl_nom_prenom, cl_sexe);          
                    } else {
                        printf("\n> La salle est ferm%ce actuellement (consultez les horaires '!horaires')...", 130);
                    }                
                } else {
                    printf("\n> Cette heure n'existe pas...");
                }
            }
            if((!strcmp(strlwr(jour), "samedi"))){
                printf("\n> Donnez l'heure (sans minutes ni secondes)... "); scanf("%d", &heure);
                if(heure >= 0 && heure < 24){
                    if(heure >= 11 && heure < 14){
                        verifyEntry(cl_nom_prenom, cl_sexe);
                    } else {
                        printf("\n> La salle est ferm%ce actuellement (consultez les horaires '!horaires')...", 130);
                    }                
                } else {
                    printf("\n> Cette heure n'existe pas...");
                }
            }  
            if((!strcmp(strlwr(jour), "dimanche"))){
                printf("\n> La salle est ferm%ce le Dimanche...", 130);            
            }            
        } else {
            printf("\n> Vous %ctes d%cja %c l'int%crieur...", 136, 130, 133, 130);
        }

    }        
    



}
/*==========================================================================================================*/


/*==========================================================================================================*/
void clientSortir(void){
    signed char cl_prenom[256], cl_nom[256];
    signed char cl_nom_prenom[256], cl_sexe[8];

    printf("\n> Donnez votre pr%cnom: ", 130); scanf("%s", cl_prenom);
    strcpy(cl_prenom, strcat(cl_prenom, " "));
    printf("> Donnez votre nom: "); scanf("%s", cl_nom);
    strcpy(cl_nom_prenom, strlwr(strcat(cl_prenom, cl_nom)));

    if(clientOutside(cl_nom_prenom)){
        if(!seekClient("clients.txt", cl_nom_prenom)){
            printf("\n> Vous n'%ctes pas encore client...");
            printf("\nTapez '!inscription' pour s'inscrir puis pouvoir entrer...");
        } else {
            verifyExit(cl_nom_prenom, cl_sexe);
        }        
    } else {
        printf("\n> Vous %ctes d%cja %c l'ext%crieur...", 136, 130, 133, 130);
    }

}
/*==========================================================================================================*/



#endif // COMMANDS_H_INCLUDED