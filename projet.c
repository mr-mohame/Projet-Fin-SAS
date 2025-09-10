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
    
    
};
///////////////////////////////////////////////////////////////////////////////////////////////////
//==================================================les fonctions=================================

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
//+++++++++++++++++++++++++++ foncation Afficher la liste de tous les joueurs+++++++++++++++++++++++++++++
//les fonction de tri afficher 
//tri par ordre alphabétique (Nom).
void triNom(struct joueurs J){
    for(int i=0; i<J.nJoueurs-1;i++){
        int min_alph=i;
        for(int j=i+1; j<J.nJoueurs; j++){
            if(strcmp(J.nom[i], J.nom[min_alph])<0){
                min_alph=j;
            }
        }
        char tempNom[taille], tempPrenom[taille], tempPoste[taille];
        int tempMaillot, tempAge, tempButs, tempId;
        //change les info
        strcpy(tempNom, J.nom[i]);
        strcpy(J.nom[i], J.nom[min_alph]);
        strcpy(J.nom[min_alph], tempNom);

        strcpy(tempPrenom, J.prenom[i]);
        strcpy(J.prenom[i], J.prenom[min_alph]);
        strcpy(J.prenom[min_alph], tempPrenom);

        tempMaillot=J.numeroMaillot[i];
        J.numeroMaillot[i]=J.numeroMaillot[min_alph];
        J.numeroMaillot[min_alph]=tempMaillot;

        strcpy(tempPoste, J.poste[i]);
        strcpy(J.poste[i], J.poste[min_alph]);
        strcpy(J.poste[min_alph], tempPoste);

        tempAge=J.age[i];
        J.age[i]=J.age[min_alph];
        J.age[min_alph]=tempAge;

        tempButs=J.buts[i];
        J.buts[i]=J.buts[min_alph];
        J.buts[min_alph]=tempButs;

        tempId=J.id[i];
        J.id[i]=J.id[min_alph];
        J.id[min_alph]=tempId;
    }
}
//tri par age.
void triAge(struct joueurs J){
    for(int i=0;i<J.nJoueurs; i++){
        int min_age=i;
        for(int j=i+1; j<J.nJoueurs; j++){
            if(J.age[j]<J.age[min_age]){
                min_age=j;
            }
        }
        char tempNom[taille], tempPrenom[taille], tempPoste[taille];
        int tempMaillot, tempAge, tempButs, tempId;
        strcpy(tempNom, J.nom[i]);
        strcpy(J.nom[i], J.nom[min_age]);
        strcpy(J.nom[min_age], tempNom);

        strcpy(tempPrenom, J.prenom[i]);
        strcpy(J.prenom[i], J.prenom[min_age]);
        strcpy(J.prenom[min_age], tempPrenom);

        tempMaillot=J.numeroMaillot[i];
        J.numeroMaillot[i]=J.numeroMaillot[min_age];
        J.numeroMaillot[min_age]=tempMaillot;

        strcpy(tempPoste, J.poste[i]);
        strcpy(J.poste[i], J.poste[min_age]);
        strcpy(J.poste[min_age], tempPoste);

        tempAge=J.age[i];
        J.age[i]=J.age[min_age];
        J.age[min_age]=tempAge;

        tempButs=J.buts[i];
        J.buts[i]=J.buts[min_age];
        J.buts[min_age]=tempButs;

        tempId=J.id[i];
        J.id[i]=J.id[min_age];
        J.id[min_age]=tempId;

    }
}
// Afficher les joueurs par poste.
// l'affichage des joueurs
void afficherJoueurs(struct joueurs J) {
    for(int i = 0; i < J.nJoueurs; i++) {
        printf("%d: %s %s, Maillot: %d, Poste: %s, Age: %d, Buts: %d, ID: %d\n",
            i + 1,
            J.nom[i],
            J.prenom[i],
            J.numeroMaillot[i],
            J.poste[i],
            J.age[i],
            J.buts[i],
            J.id[i]);
    }
}


//+++++++++++++++++++++++++++ foncation Modifier un joueur  joueurs+++++++++++++++++++++++++++++
//Modifier le poste d’un joueur.
struct joueurs modifierPoste(struct joueurs J, int idCherche){
    int trouve=0;
    for(int i=0; i<J.nJoueurs; i++){
        if(J.id[i]==idCherche){
            printf("ancien information : %s %s %d %s %d %d %d\n",J.nom[i], J.prenom[i], J.numeroMaillot[i], J.poste[i], J.age[i], J.buts[i], J.id[i]);
            printf("=====modifier la poste======\n");
            choisirPoste(J.poste[i]);
            printf("le nouveau poste est: %s\n", J.poste[i]);
            trouve=1;
            break;
        }
    }
    if(trouve==0){
        printf("joueur non trouve.\n");
    }
    return J;
}


int main(){
    struct joueurs Joueurs;
    struct joueurs J;
    Joueurs.nJoueurs = 0;
    int choix, choixAjoute, choixAffiche, choixModifier;
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
        //===========================================switch des case de menu principal=========================================
        switch(choix){
            //_____________________Ajouter les joueur Menu Principal________________________ 
            case 1:
            do{
                printf("++++++++++++++++++++Menu ajouter les joueur++++++++++++++++++++\n");
                printf("1- Ajouter un seul joueur : \n");
                printf("2- Ajouter un pleusieur joueurs : \n");
                printf("0- Retour : \n");

                printf("Enter le choix d'ajouter : ");
                scanf("%d", &choixAjoute);
                switch(choixAjoute){
                    //1er cas pour ajouter un seul joueur
                    case 1:{
                    int ajoute=1;
                    printf("++++++++++++++++++++Ajouter un seul joueur++++++++++++++++++++\n");
                    Joueurs=ajouterJoueurs(Joueurs, 1);
                    break;
                    }

                    //2eme cas pour ajouter pleusieur joueurs
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

             
            //__________________________Afficher la liste de tous les joueurs_______________________________
            case 2:
            //1er cas pour affichers joueurs par tri
            do{
                printf("++++++++++++++++++++Menu Afficher la liste de tous les joueurs++++++++++++++++++++\n");
                printf("1- Afficher la liste de tous les joueurs par ordre alphabétique (Nom): \n");
                printf("2- Afficher la liste de tous les joueurs par âge: \n");
                printf("3- Afficher les joueurs par poste: \n");
                printf("0- Retour : \n");

                printf("Enter le choix d'affichage : ");
                scanf("%d", &choixAffiche);

                switch(choixAffiche){
                    //case 1 pour tri par nom
                    case 1:{
                    printf("++++++++++++++++++++la liste de tous les joueurs par ordre alphabétique++++++++++++++++++++\n");
                    triNom(Joueurs);
                    afficherJoueurs(Joueurs);
                    break;}
                    //case 2 pour tri par age
                    case 2:
                    printf("++++++++++++++++++++la liste de tous les joueurs par âge++++++++++++++++++++\n");
                    triAge(Joueurs);
                    break;
                    //case 3 pour tri par age
                    case 3:
                    printf("++++++++++++++++++++la liste de tous les joueurs par poste++++++++++++++++++++\n");

                    break;

                    case 0:
                    printf("Retour au menu principal\n");
                    break;

                    default:
                    printf("Choix invalide!\n");

                }
            }while(choixAffiche!=0);
            break;


            //_____________________Modifier les joueur Menu Principal________________________ 
            case 3:
            do{
                printf("++++++++++++++++++++Menu modifier++++++++++++++++++++\n");
                printf("1- Modifier le poste d’un joueur: \n");
                printf("2- Modifier l’âge d’un joueur: \n");
                printf("3- Modifier le nombre de buts marqués par un joueur: \n");
                printf("0- Retour : \n");

                printf("Enter le choix modifier : ");
                scanf("%d", &choixModifier);

                switch(choixModifier){
                    //case 1 Modifier le poste
                    
                    case 1:{
                    int idCherche;
                    printf("+++++++++++++ la modifier le poste d’un joueur++++++++++++\n");
                    printf("saisir l'id de joueur modifier: ");
                    scanf("%d", &idCherche);
                    Joueurs=modifierPoste(Joueurs, idCherche);
                    break;
                    }

                    //case 2 Modifier l’âge
                    case 2:{
                    printf("+++++++++++++la modifier l’âge d’un joueur++++++++++++\n");
                    break;
                    }

                    //case 3 nombre de buts
                    case 3:
                    printf("+++++++++++++la modifier le nombre de buts marqués par un joueur++++++++++++\n");
                    break;

                    //Retour
                    case 0:
                    printf("+++++++++++++Retour au menu principal++++++++++++++++++++\n");
                    break;

                    default:
                    printf("Choix invalide!\n");
                }


            }while(choixModifier!=0);
            break;

            default:
            printf("Choix invalide!\n");   
        }
        
    }while(choix!=0);

}