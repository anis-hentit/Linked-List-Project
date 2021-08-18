#include <stdio.h>
#include <stdlib.h>
#include"Operation.h"
#include"MLLC.h"
#include"string.h"


int main()
{



    char str[25];
    char mot[25];
    char ligne[256];
    int choix;
    int boucle=0;
    int integer;
    int position;


	ptrM L;

printf("\nBienvenue:\n");

	L= creation_liste("ft.txt");

     printf("\nLa liste a etait creer a partir du fichier ft\n");
      do{

	printf("-------------------------------------------------------\n");
     printf("1-Imprimer la liste\n");
     printf("2-Calculer la taille de la liste\n");
     printf("3-Rechercher un mot\n");
     printf("4-Rechercher et Remplacer tout\n");
     printf("5-Rechercher une ligne\n");
     printf("6-Inserer un mot\n");
     printf("7-Inserer une ligne\n");
     printf("8-Supprimer la premier occurence d'un mot\n");
     printf("9-Supprimer toute les OCC d'un mot\n");
     printf("10-Supprimer une ligne\n");
     printf("11-Trier LLC par ordre alphabetique\n");
     printf("12-Sauvgarder LLC dans un fichier\n");
     printf("-------------------------------------------------\n");

       printf("\nEntrer votre choix\n");



       do{
       scanf("%d",&choix);
       }while(choix>12||choix<1);


       switch(choix)
       {
       case 1:
       imprimerLLC(L);
        printf("\n");
        break;
       case 2:
         printf("\nle nombre de mot est:%d\n",calculeNombreMot(L));
        printf("\n");
        break;
       case 3:
        printf("\nDonner le mot a rechercher\n");
      lc(str);
       lc(str);
        rechercher_mot( L,str);
        break;
       case 4:
        printf("\nDonner le mot a introduire\n");
        lc(mot);
        lc(mot);
       printf("\nDonner le mot a remplacer\n");
        lc(str);
       Rechercher_Remplacer (L,str,mot);
       printf("\nVoici la LLC apres modification\n");
       imprimerLLC(L);
       break;
       case 5:
        printf("\nDonner le numero de la ligne\n");
        scanf("%d",&integer);
        RechercherLigne(L,integer);
        break;
       case 6:
      printf("\nDonner le mot a inserer\n");
     lc(str);
     lc(str);
      printf("\nDonner la ligne \n");
      scanf("%d",&integer);
      printf("\nDonner la position du mot\n");
      scanf("%d",&position);
     inserer_mot(&L,str, integer,position,0);
     printf("\n Voici la LLC apres modification\n");
     imprimerLLC(L);

     break;
       case 7:
    printf("\nEntrer la chaine de caractere a inserer\n");
     lc(ligne);
     lc(ligne);
    printf("\n Entrer la position ou inserer la ligne\n");
    scanf("%d",&integer);
    inserer_ligne(&L, integer, ligne);
    printf("\n Voici le texte apres modification\n");
    imprimerLLC(L);
    break;
       case 8:
           printf("\nDonner le mot a supprimer\n");
          lc(mot);
           lc(mot);
           if(supprimer_Mot(&L,mot)==1){
           printf("\nVoici le texte apres modification\n");
           imprimerLLC(L);}else printf("\nLe mot n'existe pas\n");
           break;
       case 9:
        printf("\nDonner le mot a supprimer\n");
        lc(mot);
        lc(mot);
        if(supprimerTouteOcc(&L, mot)==1){
        printf("\nVoici le texte apres modification\n");
        imprimerLLC(L);}
        else printf("\nLe mot n'existe pas\n");
        break;

       case 10:
        printf("\nDonner le numero de ligne a supprimer\n");
        scanf("%d",&integer);
        if(supprimerLigne(&L,integer)==1)
        {
            printf("\n Voici le texte apres modification\n");
            imprimerLLC(L);
        }
        break;
       case 11:
        triLLCAlpha(L);
        printf("\nVoici la liste apres trie\n");
        imprimerLLC(L);
        break;
       case 12:
        printf("\nDonner le nom du fichier ou sauvgarder avec l'extention .txt\n");
         lc(str);
        lc(str);
        Sauv_LLC(L,str);
        printf("\nLe fichier a ete creer\n");
        break;

}
do{
printf("\n Vouler vous faire autre chose? entrer 1 pour <OUI> ou 0 pour <NON>\n");
scanf("%d",&boucle);
}while(boucle!=1&&boucle!=0);



      }while(boucle==1);







    return 0;
}
