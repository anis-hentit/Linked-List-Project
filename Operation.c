#include <stdio.h>
#include <stdlib.h>
#include"MLLC.h"
#include"Operation.h"
#include<string.h>

char* lc(char*tab)
{
    char str [256];int i=0;

  gets(str);

    while(str[i]) {
     str[i]=tolower(str[i]);
      i++;
   }

strcpy(tab,str);



    return str;}



















ptrM creation_liste(const char*nom)
{
    FILE* f = fopen(nom, "r");

    ptrM p = NULL, q = NULL, tete = NULL;int i=0;


      char sep[] = " \n\t!?*%(){}[]=+'#_-";

    if (f == NULL) {
        return NULL;
    }
    else {
        char line[255];

        char* mot ;
        int ligne = 0, pos;
        p =allouer();

        while (fgets(line, 255, f)!= NULL){

            ligne++;i=0;

            mot = strtok(line, sep);

              while(mot!=NULL&& mot[i] ) {
     mot[i]=tolower(mot[i]);
      i++;
   }
            pos = 0;
            while (mot != NULL){
                pos++;
                p = allouer();


                if (tete == NULL){
                    tete = p;
                    aff_mot(tete,mot);
                    aff_suiv(tete,NULL);
                   }
                else{
                    aff_mot(p,mot);
                    aff_suiv(q,p);
                   }
                aff_num_ligne(p,ligne);
                aff_pos_ligne(p,pos);
                q = p;
                mot = strtok(NULL,sep);
                i=0;
                while( mot!=NULL&&mot[i] ) {
     mot[i]=tolower(mot[i]);
      i++;
   }
                };

        }
        aff_suiv(q,NULL);
        fclose(f);

        return tete;
    }
}


void imprimerLLC(ptrM L)

{
     ptrM p=L;

              if(p==NULL)printf("la tete est a null\n");
         else{


                      while(p!=NULL){


                                     printf("\nMot:%s, Position:%d, Numero ligne:%d\n",p->mot,p->pos,p->num_ligne);


                                                 p=suiv(p);


}

}
}

int calculeNombreMot(ptrM L)
{
    ptrM p=L;
    int cpt=0;


    while(p!=NULL)
    {
        cpt++;

        p=suiv(p);

    }

    return cpt;

}

int rechercher_mot(ptrM L,char* mot)
{
    int exist = 0; int occ=0;ptrM p=L;

    while (p!=NULL)
    {
        if (strcmp(p->mot,mot)==0)
        {
            exist = 1;
            occ++;

            printf("\nle mot  '%s' se trouve dans la ligne %d et la position %d \n\n", mot, p->num_ligne, p->pos);
        }
        p = suiv(p);
    }
    printf(" Le mot %s  apparait %d fois \n \n",mot,occ);
    return exist;
}

int Rechercher_Remplacer (ptrM L,char*motR,char*nouveauMot)
{
    ptrM p=L;


if(rechercher_mot(L,motR)==1)
    {
       while(p!=NULL)
       {
           if(strcmp(p->mot,motR)==0)
           {
               strcpy(p->mot,nouveauMot);
           }
           p=suiv(p);

       }


    }else printf("le mot n'existe pas \n");




return 0;

}

int Sauv_LLC(ptrM L, char* dir)
{

    FILE* f = fopen(dir, "a");
    int ligne;

    while (L!=NULL)
    {
        ligne = L->num_ligne;


        while (L!=NULL && L->num_ligne == ligne)
        {
            fprintf(f,L->mot);
            if (suiv(L) != NULL && suiv(L)->num_ligne == ligne)
                fputs(" ", f);
            L = suiv(L);

        }
     fprintf(f, "\n");
    }
    fclose(f);

return 0;
}

 int RechercherLigne(ptrM L,int ligne)

 {
     ptrM p=L;int cpt=0;

     while(p!=NULL && p->num_ligne!=ligne)
     {

         p=suiv(p);
     }

                   if(p!=NULL)
                {

                 printf("Voici les mots de la ligne numero: %d\n\n",ligne);

                while(p!=NULL && p->num_ligne==ligne)
                {
                    printf(" '%s ', ",p->mot);
                    cpt++;

                       p=suiv(p);           }return cpt;






                }else{ printf("La ligne n'existe pas\n"); return 0;}






 }







void inserer_mot(ptrM* L, char* mot, int ligne, int pos, int mode)
{
    ptrM k = allouer(),q = NULL,p = *L;

    while (p != NULL)
    {

        if (pos == 1 && ligne == 1){
            aff_mot(k, mot);
            aff_num_ligne(k, 1);
            aff_pos_ligne(k, 1);
            aff_suiv(k, p);
            *L = k;
            break;
        }
        if (p->num_ligne == ligne && p->pos == pos){
            aff_mot(k, mot);
            aff_num_ligne(k, ligne);
            aff_pos_ligne(k, pos);
            aff_suiv(q, k);
            aff_suiv(k, p);
            break;
        }
        if (p->num_ligne > ligne){
            aff_mot(k, mot);
            aff_suiv(k, p);
            aff_num_ligne(k, q->num_ligne);
            aff_pos_ligne(k, q->pos+1);
            aff_suiv(q, k);break;

        }
        q = p;
        p = suiv(p);

    }

    if (p == NULL){
        {
            aff_mot(k, mot);
            aff_num_ligne(k, (q->num_ligne)+1);
            aff_pos_ligne(k, 1);
            aff_suiv(k, NULL);
            aff_suiv(q, k);
        }


    }

    else {
        if (mode == 0)
            {
        while ( p!= NULL&&p->num_ligne == ligne)
        {
            aff_pos_ligne(p, p->pos+1);
            p = suiv(p);
        }
        }
        else{
            while (p!=NULL)
            {
                aff_num_ligne(p, p->num_ligne+1);
                p = suiv(p);
            }
        }

    }
    }



void inserer_ligne(ptrM *L, int ligne, char*str)
{
    char* mot = strtok(str, " \n");
    int pos = 1, mode = 1;
    while (mot != NULL)
    {
        inserer_mot(L, mot, ligne, pos, mode);

        mot = strtok(NULL, " \n");

        pos++;

        mode = 0;
    }
}





int supprimer_Mot(ptrM* L, char* mot)
{
    ptrM p=*L,q;ptrM s=NULL;
    int supprime=0;



    while(p!=NULL && supprime==0)
    {
        if(strcmp(p->mot,mot)==0)
        { supprime=1;
            if(p==*L)
           {s=suiv(p);
               if(s!=NULL && p->num_ligne==(s->num_ligne))
               {
                    while(s!=NULL&&s->num_ligne==p->num_ligne)
                    {
                        s->pos--;
                        s=suiv(s);

                    }}else{
                        while(s!=NULL){

                        s->num_ligne--;
                        s=suiv(s);}
                    }

            *L=suiv(p);
              free(p);
           supprime=1;

           }else
           {
               s=suiv(p);
               if(s!=NULL && p->num_ligne==(s->num_ligne))
               {
                    while(s!=NULL && s->num_ligne==p->num_ligne)
                    {
                        s->pos--;
                        s=suiv(s);

                    }}else{
                        while(s!=NULL){

                        s->num_ligne--;
                        s=suiv(s);}
                    }

              aff_suiv(q,suiv(p));
               free(p);
                supprime=1;

           }
        }
        q=p;
        p=suiv(p);


    }

return supprime;
}




int supprimer_motavecpos(ptrM*L,int ligne,int pos)
{

    ptrM p ,q,s;int supprime=0;

    p=*L;

    while(p!=NULL&&p->num_ligne!=ligne&&p->pos!=pos)
    {  q=p;
        p=suiv(p);
    }
while(p!=NULL&&supprime==0){

if(p->num_ligne==ligne&&p->pos==pos){
if(p==*L)
           {
               s=suiv(p);
               if(s!=NULL && ligne==(s->num_ligne))
               {
                    while(s!=NULL&&s->num_ligne==ligne)
                    {
                        s->pos--;
                        s=suiv(s);

                    }

                    }else{
                        while(s!=NULL){

                        s->num_ligne--;
                        s=suiv(s);}
                    }

            *L=suiv(p);
              free(p);
              supprime=1;

               }


              else
                {
               s=suiv(p);
               if(s!=NULL && s->num_ligne==(ligne))
               {
                    while(s!=NULL && s->num_ligne==ligne)
                    {
                        s->pos--;
                        s=suiv(s);

                    }}else{
                        while(s!=NULL){

                        s->num_ligne--;
                        s=suiv(s);}
                    }

              aff_suiv(q,suiv(p));
               free(p);
                supprime=1;



           }



        }
        q=p;
        p=suiv(p);


    }


return supprime;
}



int supprimerLigne(ptrM*L,int ligne)
{
    int pos=1;int nbr=1;int cpt=1;int supprime=0;

      if(RechercherLigne(*L,ligne)!=0){
       nbr=RechercherLigne(*L,ligne);

    while(supprimer_motavecpos(L, ligne,pos)==1 && cpt<nbr)
    {

cpt++;
supprime=1;

    }




      }




return supprime;


}

int supprimerTouteOcc(ptrM* L, char* mot)
 {

     int ok = 0;
     while (supprimer_Mot(L, mot) == 1){ok = 1;}
     return ok;
 }



  int triLLCAlpha(ptrM L)
 {  ptrM p = NULL, q = L,  ptr = NULL;
     char*min = L->mot,
     temp[25];




     while(suiv(q)!=NULL)
     {
         p = q;


         while(p !=NULL)
         {
             if (strcmp(min, p->mot) >0)
             {
                 min = p->mot;
                 ptr = p;
             }

             p = suiv(p);

         }

         if (q->mot != min)
         {
            strcpy(temp, q->mot);
            aff_mot(q, min);
            aff_mot(ptr, temp);
         }



         q = suiv(q);
        min=q->mot;

     }

return 0;
 }
