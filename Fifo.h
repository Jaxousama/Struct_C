#ifndef FIFO_H
#define FIFO_H

typedef struct Fifo {
    unsigned int plafond;
    unsigned int taille;
    int cursor;
    int* fifo;
}fifo;

int est_vide_Fifo(fifo* f);

int afficher(fifo* f);

fifo* init_fifo(int taille);

int ajout_fifo(fifo* f,int x);

int ajout_tab_fifo(fifo* f,int* x,int taille_tab);

int retirer_fifo(fifo* f,int* x);

int top_Fifo(fifo* f);

void free_Fifo(fifo* f);

#endif