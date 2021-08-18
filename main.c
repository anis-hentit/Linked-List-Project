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

printf("\nWelcome:\n");

	L= creation_liste("ft.txt");

     printf("\nThe List has been created using the file ft\n");
      do{

	printf("-------------------------------------------------------\n");
     printf("1-Print the List\n");
     printf("2-Compute the size of the List\n");
     printf("3-Look for a word\n");
     printf("4-Look and replace All\n");
     printf("5-Look for a line\n");
     printf("6-Insert a word\n");
     printf("7-Insert a line\n");
     printf("8-Delete the first occurrence of a word\n");
     printf("9-Delete all the occurrences of a word\n");
     printf("10-Delete a line\n");
     printf("11-Sort the list in alphabetical order\n");
     printf("12-Save the list in a file\n");
     printf("-------------------------------------------------\n");

       printf("\nEnter your choice\n");



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
         printf("\nThe number is:%d\n",calculeNombreMot(L));
        printf("\n");
        break;
       case 3:
        printf("\nGive the name to look for\n");
      lc(str);
       lc(str);
        rechercher_mot( L,str);
        break;
       case 4:
        printf("\nGive the word to replace with\n");
        lc(mot);
        lc(mot);
       printf("\nGive the word to replace\n");
        lc(str);
       Rechercher_Remplacer (L,str,mot);
       printf("\nHere is the list after the operation\n");
       imprimerLLC(L);
       break;
       case 5:
        printf("\nGive the index of the line\n");
        scanf("%d",&integer);
        RechercherLigne(L,integer);
        break;
       case 6:
      printf("\nGive the word to insert\n");
     lc(str);
     lc(str);
      printf("\nGive the index of the line\n");
      scanf("%d",&integer);
      printf("\nGive the position of the word\n");
      scanf("%d",&position);
     inserer_mot(&L,str, integer,position,0);
     printf("\n Here is the list after the operation\n");
     imprimerLLC(L);

     break;
       case 7:
    printf("\nEnter the string to insert\n");
     lc(ligne);
     lc(ligne);
    printf("\n Enter the position where to insert the string\n");
    scanf("%d",&integer);
    inserer_ligne(&L, integer, ligne);
    printf("\n Here is the list after modification\n");
    imprimerLLC(L);
    break;
       case 8:
           printf("\nGive the word to delete\n");
          lc(mot);
           lc(mot);
           if(supprimer_Mot(&L,mot)==1){
           printf("\nHere is the list after modification\n");
           imprimerLLC(L);}else printf("\nThe word doesnt exist\n");
           break;
       case 9:
        printf("\nGive the word to delete\n");
        lc(mot);
        lc(mot);
        if(supprimerTouteOcc(&L, mot)==1){
        printf("\nHere is the list after the operation\n");
        imprimerLLC(L);}
        else printf("\nThe word doesnt exist\n");
        break;

       case 10:
        printf("\nGive the index of the line to delete\n");
        scanf("%d",&integer);
        if(supprimerLigne(&L,integer)==1)
        {
            printf("\n Here is the list after the operation\n");
            imprimerLLC(L);
        }
        break;
       case 11:
        triLLCAlpha(L);
        printf("\nHere is the list after the sort\n");
        imprimerLLC(L);
        break;
       case 12:
        printf("\nGive the name of the file where to save to .txt\n");
         lc(str);
        lc(str);
        Sauv_LLC(L,str);
        printf("\nThe file has been created\n");
        break;

}
do{
printf("\n Do you want to do something else? enter 1 for <Yes> or 0 for <NO>\n");
scanf("%d",&boucle);
}while(boucle!=1&&boucle!=0);



      }while(boucle==1);







    return 0;
}
