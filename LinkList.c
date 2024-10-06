#include <stdio.h>
#include <stdlib.h>


typedef struct Node{
    int donnee;
    struct Node* next;
}Cell;

int est_vide_LinkList(Cell* c){
    if(c == NULL || c ==0){
        return 1;
    }
    return 0;
}

int affiche(Cell* c){
    if(est_vide_LinkList(c)){
        printf("Vide\n");
        return -1;
    }
    if(c->next == NULL){
        printf("%d\n",c->donnee);
        return 0;
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

int ajout_Cell_Queue(Cell** c,int x){
    if(est_vide_LinkList((*c))){
        (*c) = init(x);
        return 0;
    }
    Cell* c_2 = init(x);
    while ((*c)->next != NULL){
        (*c) = (*c)->next;
    }
    (*c)->next = c_2;
    return 0;
}

int ajout_Cell_Tete(Cell** c,int x){
    if(est_vide_LinkList((*c))){
        (*c) = init(x);
        return 0;
    }
    Cell* c_2 ;
    c_2 = init(x);
    c_2->next = (*c);
    (*c) = c_2;
}

int supprimer_Queue(Cell* c){
    if(est_vide_LinkList(c)){
        printf("Erreur liste vide");
        return -1;
    }
    if(c->next == NULL){
        free(c);
        return 0;
    }

    Cell* Actuel =c;
    Cell* Suivant =c->next;

    while (Suivant->next != NULL){
        Actuel = Suivant;
        Suivant = Suivant->next;
    }
    Actuel->next = NULL;
    free(Suivant);
    return 0;
}

int supprimer_tete(Cell** c){
    if(est_vide_LinkList((*c))){
        printf("Erreur liste vide");
        return -1;
    }
    *c=(*c)->next;
}

int recherche_LinkList(Cell* c,int x){
    if(est_vide_LinkList(c)){
        printf("Erreur liste vide");
        return -1;
    }

    Cell* Actuel = c;

    while(Actuel->donnee == x && Actuel != NULL){
        Actuel = Actuel -> next;
    }
    if(Actuel == NULL){
        printf("Pas trouvé");
        return 0;
    }

    printf("Trouvé");
    return 1;
}


int supprimer_first_Occurence(Cell** c, int x){
    if(est_vide_LinkList((*c))){
        printf("Erreur liste vide\n");
        return -1;
    }

    Cell* Actuel = (*c);
    Cell* Suivant = (*c)->next;

    if(Actuel->donnee == x){
        if(supprimer_tete(c) == -1){return -1;};
        return 1;
    }

    while (Suivant != NULL){
        if(Suivant->donnee == x){
            Actuel->next = Suivant->next;
            free(Suivant);
            return 0;
        }
        Suivant = Suivant->next;
        Actuel = Actuel->next;
    }

    printf("Pas trouvé\n");
    return -1;

}

int supprimer_all_Occurence(Cell** c,int x){
    if(est_vide_LinkList((*c))){
        printf("Erreur liste vide\n");
        return -1;
    }
    

    while((*c)!= NULL && (*c)->donnee == x){
        *c=(*c)->next;
    }

    if((*c) == NULL){
        return 0;
    }

    Cell* Actuel = (*c);
    Cell* Suivant = (*c)->next;
    
    while (Suivant != NULL){
        if((Suivant->donnee == x)){
            Actuel->next = Suivant->next;
            free(Suivant);
            Suivant = Actuel->next;
        }
        else{
            Suivant = Suivant->next;
            Actuel = Actuel->next;
        }
    }
    

    return 0;
}

int main(){
    Cell* c =NULL ;

    ajout_Cell_Tete(&c,45);
    affiche(c);
    supprimer_first_Occurence(&c,45);
    affiche(c);
    
}