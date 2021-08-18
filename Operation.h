#ifndef OPERATION_H_INCLUDED
#define OPERATION_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include"MLLC.h"
#include"Operation.h"

ptrM creation_liste(const char*nom);
void imprimerLLC(ptrM L);
char* lc(char*tab);
int calculeNombreMot(ptrM L);
int rechercher_mot(ptrM L,char* mot);
int Rechercher_Remplacer (ptrM L,char*motR,char*nouveauMot);
int Sauv_LLC(ptrM L, char* dir);
int RechercherLigne(ptrM L,int ligne);
void inserer_mot(ptrM* L, char* mot, int ligne, int pos, int mode);
void inserer_ligne(ptrM *L, int ligne, char*str);
int supprimer_Mot(ptrM* L, char* mot);
int supprimer_motavecpos(ptrM*L,int ligne,int pos);
int supprimerLigne(ptrM*L,int ligne);
int supprimerTouteOcc(ptrM* L, char* mot);
 int triLLCAlpha(ptrM L);

#endif // OPERATION_H_INCLUDED
