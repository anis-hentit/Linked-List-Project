#include <stdio.h>
#include <stdlib.h>
#include"MLLC.h"
#include"Operation.h"
#include<string.h>
void init(ptrM p) {
    p = NULL;
}

ptrM allouer() {

    ptrM p=NULL;
    p=(ptrM)malloc(sizeof(Maillon));
    return p;

}

void liberer(ptrM p) {
    free(p);
}






ptrM suiv(ptrM p) {
    return p->suivant;
}
char* valeur(ptrM k) {
    return k->mot;
}


void aff_suiv(ptrM p, ptrM q) {
    p->suivant = q;
}

void aff_mot(ptrM p, char* mot) {
	strcpy(p->mot,mot);
}

void aff_num_ligne(ptrM p, int i) {
	p->num_ligne = i;
}

void aff_pos_ligne(ptrM p, int i) {
	p->pos = i;
}
