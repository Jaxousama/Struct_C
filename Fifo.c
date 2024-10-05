#include <stdio.h>
#include <stdlib.h>



typedef struct Fifo {
    unsigned int plafond;
    unsigned int taille;
    int cursor;
    int* fifo;
}fifo;


int est_vide_Fifo(fifo* f){
    if(f->cursor==-1 ||f->taille==f->cursor){
        return 1;
    }
    return 0;
}

int afficher(fifo* f){
    if(f==NULL){
        printf("Fifo inexistante\n");
        return -1;
    }
    if(est_vide_Fifo(f)==1){
        printf("Fifo Vide\n");
        return -1;
    }
    printf("*******Bas de la Fifo*******\n");
    for(int i=0;i<f->taille-f->cursor;i++){
        printf("%d\n",f->fifo[i]);
    }
    printf("*******Haut de la Fifo*******\n");
    return 0;
}

fifo* init_fifo(int taille){
    if(taille<=0){
        printf("Taille inférieur a zero");
        return NULL;
    }
    fifo* f = malloc(sizeof(fifo));
    f->cursor = -1;
    f->taille = 0;
    f->plafond = taille;
    f->fifo = malloc(sizeof(int)*f->plafond);
    return f;
}

int ajout_fifo(fifo* f,int x){
    if(f == NULL){
        printf("Fifo inexistante\n");
        return -1;
    }
    if(f->taille == f->plafond){
        f->plafond = f->plafond * 2;
        f->fifo = (int*)realloc( f->fifo , sizeof(int) * f->plafond);
    }
    if(f->cursor == -1){f->cursor = 0;}
    f->fifo[f->taille] = x;
    f->taille += 1;
    return 0;
}

int ajout_tab_fifo(fifo* f,int* x,int taille_tab){
    if(f == NULL || taille_tab<=0 || x == NULL){
        printf("Probleme ajout\n");
        return -1;
    }
    if(f->taille+taille_tab >= f->plafond){
        f->plafond = f->plafond * 2;
        f->fifo = (int*)realloc( f->fifo , sizeof(int) * f->plafond);
    }
    if(f->cursor == -1){f->cursor = 0;}
    for(int i=0;i<taille_tab;i++){
        f->fifo[f->taille] = x[i];
        f->taille += 1;
    }
    return 0;
}

int retirer_fifo(fifo* f,int* x){
    if(f == NULL){
        printf("Fifo inexistante\n");
        return -1;
    }
    if(est_vide_Fifo(f)==1){
        printf("erreur Fifo vide\n");
        return -1;   
    }
    *x = f->fifo[f->cursor];
    f->cursor += 1;
    return 0;
}

int top_Fifo(fifo* f){
    if(f == NULL){
        printf("Fifo Innexistant");
        return -1;
    }
    if(est_vide_Fifo(f)==1){
        printf("Fifo Vide\n");
        return -1;
    }
    printf("Prochain élément : %d\n",f->fifo[f->cursor]);
    return 0;
}

void free_Fifo(fifo* f){
    free(f->fifo);
    free(f);
    printf("La fifo a bien été free\n");
}


int main(){
    fifo* f = init_fifo(1);
    ajout_fifo(f,12);
    ajout_fifo(f,3);
    ajout_fifo(f,2);
    ajout_fifo(f,1);
    top_Fifo(f);
    afficher(f); 
    free_Fifo(f);  
}