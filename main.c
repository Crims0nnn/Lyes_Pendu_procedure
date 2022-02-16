#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAILLECHAINE 255



//PROCEDURE
void Long_mot(int *, char[]);
void Affichage_pendu(int);
void Votre_mot(char [], char []);
void Lire_lettre(int *,char[],char []);
void Compteur_de_vie (int, int *, int *);
void Ecrire_le_mot( char [], char []);
//FONCTION



int main(){
    int Statut_jeu=0, n_vie=10, n_k=0;
    char s_mot[TAILLECHAINE], c_lettre, s_mot_2[TAILLECHAINE];

    Votre_mot(s_mot, s_mot_2);

    while (Statut_jeu == 0) {

        Affiche_pendu(n_vie);

        Ecrire_le_mot(s_mot, s_mot_2);

        Lire_lettre(&n_k, s_mot, s_mot_2);

        Compteur_de_vie(n_k, &n_vie, &Statut_jeu);
    }
    printf("Vous avez perdu le mot était %s \n", s_mot);
    return 0;
}

/************************************************************************************
BUT: Stockage de la longueur du mot

ENTRER:/

SORTIE:n est la variable ou la longueur du mot et stocker

DESCRIPTION:Cette procédure permet d'obtenir la longueur du mot a trouver
*************************************************************************************/

void Long_mot(int *n,char s_mot[TAILLECHAINE]){

    *n=strlen(s_mot);
}

/************************************************************************************
BUT: Entrer le mot a faire deviner

ENTRER:Un mot (chaine de caractere)

SORTIE:/

DESCRIPTION:Cette procédure permet d'entrer le mot a faire deviner
*************************************************************************************/

void Votre_mot(char s_mot[TAILLECHAINE], char s_mot_2[TAILLECHAINE]){

    int n_i, n_j;

    do {
        printf("Veuillez saisir un mot \n");
        scanf("%s", s_mot);
    }while (strlen(s_mot) > TAILLECHAINE-1);

    Long_mot(&n_i, s_mot);

    for (n_j=0;n_j < n_i;n_j++) {
        s_mot_2[n_j] = s_mot[n_j];
    }
}

/************************************************************************************
BUT: Affiche l'état actuelle du pendu

ENTRER:/

SORTIE:Affiche le pendu

DESCRIPTION:Cette procédure permet d'afficher le pendu au fur et a mesure
*************************************************************************************/

void Affiche_pendu(int n_vie){
    switch(n_vie){                              //Boucle switch qui a pour parametre n_vie
            case 10: printf("\n");break;            //N'affiche rien car la vie est au max
            case 9:  printf("_|__\n");break;        //Affiche le debut du pendu en fonction de la vie
            case 8:  printf(" ""|\n");              //Affiche la suite du pendu en fonction de la vie
                     printf(" ""|\n");
                     printf(" ""|\n");
                     printf(" ""|\n");
                     printf("_|__\n");break;
            case 7:  printf("___________\n");       //Affiche la suite du pendu en fonction de la vie
                     printf(" ""|\n");
                     printf(" ""|\n");
                     printf(" ""|\n");
                     printf(" ""|\n");
                     printf("_|__\n");break;
            case 6:  printf("___________\n");       //Affiche la suite du pendu en fonction de la vie
                     printf(" ""|     |\n");
                     printf(" ""|\n");
                     printf(" ""|\n");
                     printf(" ""|\n");
                     printf("_|__\n");break;
            case 5:  printf("___________\n");       //Affiche la suite du pendu en fonction de la vie
                     printf(" ""|     |\n");
                     printf(" ""|     O\n");
                     printf(" ""|\n");
                     printf(" ""|\n");
                     printf("_|__\n");break;
            case 4:  printf("___________\n");       //Affiche la suite du pendu en fonction de la vie
                     printf(" ""|     |\n");
                     printf(" ""|     O\n");
                     printf(" ""|     |\n");
                     printf(" ""|\n");
                     printf("_|__\n");break;
            case 3:  printf("___________\n");       //Affiche la suite du pendu en fonction de la vie
                     printf(" ""|     |\n");
                     printf(" ""|     O\n");
                     printf(" ""|    /|\n");
                     printf(" ""|\n");
                     printf("_|__\n");break;
            case 2:  printf("___________\n");       //Affiche la suite du pendu en fonction de la vie
                     printf(" ""|     |\n");
                     printf(" ""|     O\n");
                     printf(" ""|    /|\\\n");
                     printf(" ""|\n");
                     printf("_|__\n");break;
            case 1:  printf("___________\n");       //Affiche la suite du pendu en fonction de la vie
                     printf(" ""|     |\n");
                     printf(" ""|     O\n");
                     printf(" ""|    /|\\\n");
                     printf(" ""|    /\n");
                     printf("_|__\n");break;
            case 0:  printf("___________\n");       //Affiche la fin du pendu car la vie a atteint 0
                     printf(" ""|     |\n");
                     printf(" ""|     O\n");
                     printf(" ""|    /|\\ \n");
                     printf(" ""|    / \\ \n");
                     printf("_|__ \n");break;
                    }
}
/************************************************************************************
BUT: Demande a l'utilisateur un caractere

ENTRER:un caractere

SORTIE:/

DESCRIPTION:Cette procédure demande a l'utilisateur un caractère
*************************************************************************************/
void Lire_lettre(int *n_k, char s_mot[TAILLECHAINE], char s_mot2[TAILLECHAINE]){

    int n_j, n_i;
    char c_lettre;

    Long_mot(&n_i, s_mot);

    printf("\nVeuillez saisir une lettre\n");
    scanf(" %c", &c_lettre);
    *n_k=0;
    for (n_j=0;n_j < n_i;n_j++) {
        if (c_lettre == s_mot2[n_j]) {
            s_mot2[n_j]= '0';
            *n_k=1;
        }
    }
}
/**********************************************************************************************
BUT: Compare le caractere avec le mot

ENTRER:le caractere qui a était entrer par l'utilisateur opparavant

SORTIE:affiche soit la lettre soit un morceau du pendu

DESCRIPTION:Permet de donner l'information a l'utilisateur si il a trouver une lettre ou non
**********************************************************************************************/
void Ecrire_le_mot(char s_mot[TAILLECHAINE], char s_mot_2[TAILLECHAINE]){

    int n_k, n_j, n_i;
    char c_lettre;

    Long_mot(&n_i, s_mot);

    n_k=0;
    for (n_j=0;n_j < n_i;n_j++) {
        c_lettre = s_mot_2[n_j];
        if (c_lettre == '0') {
            printf("%c ", s_mot[n_j]);
        }else{
            printf("_ ");
            n_k++;
        }
    }
    if (n_k <= 0) {
        printf("\n Bravo vous avez trouver le mot!\n");
        exit(0);
    }
}

/***********************************************************************
BUT:Permet au main de savoir la vie du joueur

ENTRER:/

SORTIE:donne l'information au autre procédure (comme affichage du pendu)

DESCRIPTION:Permet de savoir le nombre de vie
***********************************************************************/
void Compteur_de_vie(int n_k, int *n_vie, int *Statut_jeu){
    if (n_k == 0) {
        *n_vie=*n_vie-1;

        if (*n_vie == 0) {
            *Statut_jeu=1;
        }
    }
}
