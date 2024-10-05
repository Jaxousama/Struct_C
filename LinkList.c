#include <stdio.h>
#include <stdlib.h>


typedef struct Node{
    int donnee;
    struct Node* next;
}Cell;


int affiche(Cell* c){
    if(c==NULL){
        printf("Erreur liste vide");
        return -1;
    }
    if(c->next == NULL){
        printf("%d\n",c->donnee);
    }
    printf("%d",c->donnee);
    c=c->next;
    while(c != NULL){
        printf("->%d",c->donnee);
        c = c->next;
    }
    printf("\n");
    return 0;
}

Cell* init(int x){
    Cell* c = malloc(sizeof(Cell));
    c->donnee = x;
    return c;
}

int ajout_Cell_Queue(Cell* c,int x){
    if(c==NULL){
        printf("Erreur liste vide");
        return -1;
    }
    Cell* c_2 = init(x);
    while (c->next != NULL){
        c = c->next;
    }
    c->next = c_2;
    return 0;
}

int ajout_Cell_Tete(Cell** c,int x){
    if(c==NULL){
        printf("Erreur liste vide");
        return -1;
    }
    Cell* c_2 ;
    c_2 = init(x);
    c_2->next = (*c);
    (*c) = c_2;
}

int supprimer_Queue(Cell* c){
    if(c==NULL){
        printf("Erreur liste vide");
        return -1;
    }
    if(c->next == NULL){
        printf("Erreur pas de suivant");
        return -1;
    }

    Cell* Actuel =c;
    Cell* Suivant =c->next;

    while (Suivant->next != NULL){
        Actuel = Suivant;
        Suivant = Suivant->next;
    }

    Actuel->next = NULL;
    return 0;
}

int supprimer_tete(Cell** c){
    if((*c)==NULL){
        printf("Erreur liste vide");
        return -1;
    }
    if((*c)->next == NULL){
        printf("Erreur pas de suivant");
        return -1;
    }
    *c=(*c)->next;
}

int recherche_LinkList(Cell* c,int x){
    if(c == NULL){
        printf("Erreur liste vide");
        return -1;
    }
    Cell* Actuel = c;
    while(Actuel->donnee == x && Actuel != NULL){
        Actuel = Actuel -> next;
    }
    if(Actuel == NULL){
        printf("Pas trouvé");
    }
    printf("Trouvé");
    return 1;
}

int main(){
    Cell* c =init(3);
    affiche(c);
    ajout_Cell_Tete(&c,45);
    affiche(c);
    supprimer_tete(&c);
    ajout_Cell_Tete(&c,45);
    ajout_Cell_Tete(&c,55);
    affiche(c);
}