#include<stdio.h> 
#include <string.h> 
#include <stdbool.h> 
// +++++++++++++++++++++++++++define les joueurs+++++++++++++++++++++++++++ 
#define MAX_joueurs 100
#define taille 50
// +++++++++++++++++++++++++++struct les joueurs+++++++++++++++++++++++++++
struct joueurs {
    int id[MAX_joueurs];
    char nom[MAX_joueurs][taille];
    char prenom[MAX_joueurs][taille];
    int numeroMaillot[MAX_joueurs];
    char poste[MAX_joueurs][taille];
    int age[MAX_joueurs];
    int buts[MAX_joueurs];
    int nJoueurs;
    int nextID;
    
};
//+++++++++++++++++++++++++++les foncations+++++++++++++++++++++++++++
//+++++++++++++++++++++++++++ foncation d'ajouter+++++++++++++++++++++++++++
struct joueurs ajouterJoueurs(struct joueurs J, int ajoute){
    if(J.nJoueurs+ajoute>MAX_joueurs){
        printf("la liste est plein.\n");
        return J;
    }
    for(int j=0; j<ajoute; j++){
        int i=J.nJoueurs;
        printf("======joueur %d:======\n", j+1);
        printf("ajouter le nom de %d joueur: ",j+1);
        scanf("%s", J.nom[i]);

        printf("ajouter le prenom de %d joueur: ",j+1);
        scanf("%s", J.prenom[i]);

        printf("ajouter le numero de maillot de %d joueur: ",j+1);
        scanf("%d", &J.numeroMaillot[i]);

        printf("ajouter le poste de %d joueur: ",j+1);
        scanf("%s", J.poste[i]);

        printf("ajouter l'age de %d joueur: ",j+1);
        scanf("%d", &J.age[i]);

        printf("ajouter le buts de joueur: ");
        scanf("%d", &J.buts[i]);

        J.id[J.nJoueurs]=J.nextID;
        printf("l'id de %d joueur est : %d\n", j+1, J.id[J.nJoueurs]);
        J.nJoueurs++;
        J.nextID++;
        
    }
    return J;
    
}
//+++++++++++++++++++++++++++ foncation d'afficher+++++++++++++++++++++++++++++
struct joueurs ajouterJoueurs(struct joueurs J){

}





int main(){
    struct joueurs Joueurs;
    struct joueurs J;
    Joueurs.nJoueurs = 0;
    Joueurs.nextID = 1001;
    int choix, choixAjoute;
    ;

    do{
        //le menu de choix
        printf("++++++++++++++++++++Menu Principal++++++++++++++++++++\n");
        printf("1- Ajouter les joueur : \n");
        printf("2- Afficher la liste de tous les joueurs : \n");
        printf("3- Modifier les joueur : \n");
        printf("4- Supprimer un joueur : \n");
        printf("5- Rechercher un joueur : \n");
        printf("6- Afficher les statistiques : \n");
        printf("0- Quitter : \n");
        //Enter le choix de menu principal
        printf("++++++++++++++++++++choix++++++++++++++++++++\n");
        printf("Enter le choix : ");
        scanf("%d", &choix);
        //switch des case de menu principal
        switch(choix){
            //1er cas pour ajouter des joueurs
            case 1:
            do{
                printf("++++++++++++++++++++Menu ajouter les joueur++++++++++++++++++++\n");
                printf("1- Ajouter un seul joueur : \n");
                printf("2- Ajouter un pleusieur joueurs : \n");
                printf("0- Retour : \n");

                printf("Enter le choix d'ajouter : ");
                scanf("%d", &choixAjoute);
                switch(choixAjoute){
                    case 1:{
                    int ajoute=1;
                    printf("++++++++++++++++++++Ajouter un seul joueur++++++++++++++++++++\n");
                    Joueurs=ajouterJoueurs(Joueurs, 1);
                    break;
                    }

                    case 2:{
                    printf("++++++++++++++++++++Ajouter pleusieur joueurs++++++++++++++++++++\n");
                    int ajoute=2;
                    printf("Combien des joueurs voulez vous ajouter ? ");
                    scanf("%d", &ajoute);
                    Joueurs=ajouterJoueurs(Joueurs, ajoute);
                    break;
                    }
                    case 0:
                    printf("Retour au menu principal\n");
                    break;

                    default:
                    printf("Choix invalide!\n");
                }
            }while(choixAjoute!=0);
            break;

            case 2:
            //1er cas pour affichers des joueurs
            break;

            default:
            printf("Choix invalide!\n");   
        }
    }while(choix!=0);

}