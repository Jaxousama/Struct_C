#ifndef LINKLIST_H
#define LINKLIST_H

typedef struct Node{
    int donnee;
    struct Node* next;
}Cell;

int est_vide_LinkList(Cell* c);

int affiche_Linklist(Cell* c);

Cell* init(int x);

int ajout_Cell_Queue(Cell** c,int x);

int ajout_Cell_Tete(Cell** c,int x);

int supprimer_Queue(Cell* c);

int supprimer_Tete(Cell** c);

int recherche_LinkList(Cell* c,int x);

int supprimer_first_Occurence(Cell** c, int x);

int supprimer_all_Occurence(Cell** c,int x);

#endif