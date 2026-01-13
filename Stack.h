#ifndef STACK_H
#define STACK_H

typedef struct Stack{
    unsigned int taille;
    unsigned int plafond;
    int* Stack;
}stack;

int est_vide_Stack(stack* s);

int affiche_Stack(stack* s);

stack* init_stack(int taille);

int ajout_stack(stack* s,int x);

int ajout_tab_stack(stack* s,int* x,int taille_tab);

int retirer_stack(stack* s,int* x);

int Top_Stack(stack* s);

void free_Stack(stack* s);


#endif