#ifndef MLLC_H_INCLUDED
#define MLLC_H_INCLUDED

 typedef struct Maillon{
    int num_ligne;
    int pos;
    char mot[25];
    struct Maillon* suivant;

}Maillon;

typedef   Maillon* ptrM;

void init(ptrM P);

ptrM allouer();

void liberer(ptrM p);

ptrM suiv(ptrM p);


void aff_suiv(ptrM p, ptrM q);


void aff_mot(ptrM p, char* val);


void aff_pos_ligne(ptrM p, int i);


void aff_num_ligne(ptrM p, int i);


#endif // MLLC_H_INCLUDED
