#include<stdio.h> 
#include <string.h> 
#include <stdbool.h> 
#include<stdlib.h> // pour le rand
#include <time.h>
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
    //int nextID;
};
//+++++++++++++++++++++++++++les foncations+++++++++++++++++++++++++++
//+++++++++++++++++++++++++++ foncation d'ajouter+++++++++++++++++++++++++++


// fonction dajouter poste (gardien, défenseur, milieu, attaquant).
void choisirPoste(char poste[]){
    int choix;
    int valid=0;
    while(valid==0){
        printf("choisir le poste de joueur: \n");
        printf("1- gardien.\n");
        printf("2- défenseur.\n");
        printf("3- milieu.\n");
        printf("4- attaquant.\n");
        printf("Enter le choix.\n");
        scanf("%d", &choix);
        if(choix==1){
            strcpy(poste, "Gardien\n"); 
            valid = 1;
        }else if(choix==2){
            strcpy(poste, "défenseur\n"); 
            valid = 1;
        }else if(choix==3){
            strcpy(poste, "milieu\n"); 
            valid = 1;
        }else if(choix==4){
            strcpy(poste, "attaquant\n"); 
            valid = 1;
        }else{
            printf("choix non valid.\n");
        }
    }
    

}
struct joueurs ajouterJoueurs(struct joueurs J, int ajoute){
    if(J.nJoueurs+ajoute>MAX_joueurs){
        printf("la liste est plein.\n");
        return J;
    }
    //int numDebut = J.nJoueurs + 1;
    for(int j=0; j<ajoute; j++){
        int i=J.nJoueurs;
        printf("======joueur %d:======\n", i + 1);
        printf("ajouter le nom de joueur : ");
        scanf("%s", J.nom[i]);

        printf("ajouter le prenom de joueur : ");
        scanf("%s", J.prenom[i]);

        printf("ajouter le numero de maillot de joueur : ");
        scanf("%d", &J.numeroMaillot[i]);

        choisirPoste(J.poste[i]);
        printf("le poste de joueur : %s", J.poste[i]);
        
        printf("ajouter l'age de joueur : ");
        scanf("%d", &J.age[i]);

        printf("ajouter le buts de joueur : ");
        scanf("%d", &J.buts[i]);

        int id;
        int existe=0;
        do{
            id=(rand()%9000)+1000;
            existe=0;
                //verifier l'id
            for(int d=0; d<J.nJoueurs; d++){
                if(J.id[d]==id){
                    existe=1;
                    break;
                }
            }
        }while(existe); // recommencer ranr que l'id existe deja
        J.id[i]=id;
        printf("l'id de joueur : %d\n", J.id[i]);
       // J.nextID++;
        J.nJoueurs++;  
    }
    return J;
    
}
//+++++++++++++++++++++++++++ foncation d'afficher+++++++++++++++++++++++++++++
//struct joueurs afficherJoueurs(struct joueurs J){

//}





int main(){
    struct joueurs Joueurs;
    struct joueurs J;
    Joueurs.nJoueurs = 0;
    //Joueurs.nextID=1001;
    int choix, choixAjoute;
    srand(time(NULL));

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