#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"


int est_vide_Stack(stack* s){
    if(s->taille==0){
        return 1;
    }
    return 0;
}

int affiche_Stack(stack* s){
    if(s == NULL){
        printf("Stack inexistante\n");
        return -1;
    }
    if(est_vide_Stack(s)==1){
        printf("Stack Vide\n");
        return -1;
    }
    printf("*******Haut de la Stack*******\n");
    for(int i=s->taille;i!=0;i--){
        printf("%d\n",s->Stack[i-1]);
    }
    printf("*******Bas de la Stack*******\n");
    return 0;
}

stack* init_stack(int taille){
    if(taille<=0){
        printf("taille stack impossible");
        return NULL;
    }
    stack* s;
    s = malloc(sizeof(stack));
    s->taille = 0;
    s->plafond = taille;
    s->Stack = malloc(sizeof(int) * s->plafond);
    return s;
}

int ajout_stack(stack* s,int x){
    if(s == NULL){
        printf("Stack inexistante\n");
        return -1;
    }
    if(s->taille==s->plafond){
        s->plafond = s->plafond * 2;
        s->Stack = (int*)realloc(s->Stack , sizeof(int) * s->plafond);
    }
    s->Stack[s->taille] = x;
    s->taille++;
    return 0;
}

int ajout_tab_stack(stack* s,int* x,int taille_tab){
    if(s==NULL||x==NULL||taille_tab<=0){
        printf("Probleme ajout\n");
        return -1;
    }
    if(s->taille+taille_tab >= s->plafond){
        s->plafond = s->plafond * 2;
        s->Stack = (int*)realloc( s->Stack , sizeof(int) * s->plafond);
    }
    for(int i=0;i<taille_tab;i++){
        s->Stack[s->taille] = x[i];
        s->taille += 1;
    }
    return 0;
}

int retirer_stack(stack* s,int* x){
    if(s == NULL){
        printf("Stack inexistante\n");
        return -1;
    }
    if(est_vide_Stack(s)==1){
        printf("Stack vide\n");
        return -1;
    }
    *x = s->Stack[s->taille-1];
    s->taille--;
    return 0;
}

int Top_Stack(stack* s){
    if(s == NULL){
        printf("Stack inexistante\n");
        return -1;
    }
    if(est_vide_Stack(s)==1){
        printf("Stack vide\n");
        return -1;
    }
    printf("Prochain élement:%d\n",s->Stack[s->taille-1]);
    return 0;
}

void free_Stack(stack* s){
    free(s->Stack);
    free(s);
    printf("La Stack a bien était free\n");
}

int main(){
    stack* s = init_stack(20);
    ajout_stack(s,4);
    ajout_stack(s,5);
    ajout_stack(s,6);
    int x;
    affiche_Stack(s);
    retirer_stack(s,&x);
    affiche_Stack(s);
    printf("%d\n",est_vide_Stack(s));
    Top_Stack(s);
    free_Stack(s);
    return 0;
}