#include <stdio.h>
#include <stdlib.h>
#include"fonction.h"

int main ()
{

    int* tab;
    int *tmp;
    int val,n,choix,flag;
    const int p=0;

    int continue_partie  =0;
    do{ 
        printf("entrer la taille de votre tableau\n");
        scanf("%d",&n);
        tab=alloue_espace(n);
        tmp=alloue_espace(n);



        /* REMPLISSAGE DU TABLEAU */
        printf("\t\t\tCOMMENT VOULEZ VOUS REMPLIR LE TABLEAU\n\n1-> Par la machine\n2-> manuellement\n");
        do
        {
            printf("Votre choix\n");
            scanf("%d",&choix);
        }while(choix != 1 && choix != 0);    
        if(choix == 1){
            tab=genere(tab,n);
            print_tab(n,tab);

        }else{
            tab=fill_tab(n,tab);
            print_tab(n,tab);
        }



        /*TRI DU TABLEAU AVEC LES DIFFERENTES FONCTIONS DE TRI*/
        printf("\t\t\tCOMMENT VOULEZ TRIER LE TABLEAU\n");
        printf("1-> tri insertion\n2-> tri selection\n3-> tri bulle\n4-> tri rapide\n5-> tri fusion\n6-> tri bitonnique\n");
        do
        {
        printf("votre choix\n");
        scanf("%d",&choix);
        }while( choix <1 || choix >7);
        if(choix == 1){
            tri_insertion(tab,n);
            printf("trie\n");
            print_tab(n,tab);
            printf("\n");
        }else if(choix == 2){
            tri_selection(tab,n);
            printf("trie\n");
            print_tab(n,tab);
            printf("\n");
        }else if( choix == 3){
            tri_bulle(tab,n);
            printf("trie\n");
            print_tab(n,tab);
            printf("\n");
        }else if( choix == 4){
            triRapid(tab, p, n-1);
            printf("trie\n");
            print_tab(n,tab);
            printf("\n");
        }else if(choix == 5){
            triFusion(p,n-1,tab,tmp);
            printf("trie\n");
            print_tab(n,tab);
            printf("\n");
        }else{
            tri_bitonnique(tab,n);
            printf("trie\n");
            print_tab(n,tab);
            printf("\n");
        }


    /* RECHERCE DES ELEMTS DANS LE TABLEAU  EN FONCTION DES AL
        GORITHME DE TRI UTILISE PLUS HAUT*/

        printf("entrer la valeur de l'ellements a rechercher\n");
        scanf("%d",&val);
        printf("\t\t\tPAR QUELLE RECHERCHE VOULEZ VOUS RECHERCCHER UN ELMTS\n1-> dichotomique\n2-> sequentielle\n");
        do{
        printf("VOTRE CHOIX\n");
        scanf("%d",&choix);
        }while(choix != 1 && choix != 2);
        if(choix == 1){
            recherche_dichotomique(tab,n,val);
        }else {
            recherche_sequentielle(tab,n,val);
        }

        printf("\t\t\tAUTRE CHOSES A REALISER ???....?\n\n");
        printf("1-> indice de la premiere occurence d'une valeur \n2-> indice de la derniere occurence d'une valeur\n3-> nomre d'occurences d'une valeur\n");
        do{ 
            printf("votre choix\n");
            scanf("%d",&choix);
        }while(choix != 1 && choix != 2 && choix != 3);
        printf("entrer la valeur de l'elmts pour le traitement\n");
        scanf("%d",&val);
        if(choix == 1){
            flag=premiere_occurence(tab,n,val);
        }else if(choix == 2){
            flag=derniere_occurences(tab,n,val);
        }else {
            flag=nbre_occurences(tab,n,val);

        }

        free(tab);
        free(tmp);

        printf("voulez vous reccomencer le recommencer\nsi oui taper:\n1-> pour recommencer\n0-> pour quitter\n");
        printf("votre choix\n");
        scanf("%d",&continue_partie);
    }while( continue_partie == 1);    
    return 0;
}