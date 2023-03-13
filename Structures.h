#ifndef STRUCTURES_H_INCLUDED
#define STRUCTURES_H_INCLUDED



/*==========================================*/
typedef enum Bool {
    FALSE, 
    TRUE
} Bool;
/*==========================================*/
typedef struct ClientInfo {
    signed char prenom[256];
    signed char nom[256];
    signed char sexe[8];
    int age; 
    signed char is_married[8]; 
    int nbr_enfants;
    signed char numero_tel[16];
    signed char e_mail[128];

} Client;
/*==========================================*/
typedef struct PrixSports {
    int tennis;
    int basket;
    int piscine;
    int volleyball;
    int football;
} Sports;
/*==========================================*/



#endif // STRUCTURES_H_INCLUDED