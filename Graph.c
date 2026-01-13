#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"


graph* Init_Graph(int sommet){
    if(sommet<0){
        printf("Error create Graph");
        return NULL;
    }
    graph* g = malloc(sizeof(graph));
    g->nb_sommets = sommet;
    g->matrix_arc = malloc(sommet * sizeof(int*));
    for(int i = 0;i<sommet;i++){
        g->matrix_arc[i] = malloc(sommet * sizeof(int));
    }
    for(int i = 0; i<sommet;i++){
        for(int j = 0;j<sommet;j++){
            g->matrix_arc[i][j] = 0;
        }
    }
    return g;
}


int Add_Arc(graph* g, char x, char y){
    if((x<'A'|| x>'Z') || (y<'A' || y>'Z')){
        printf("Erreur x or y");
        return -1;
    }
    if(Graph_empty(g)){
        return -1;
    }
    x = x - 'A';
    y = y - 'A';
    g->matrix_arc[x][y] = 1;
    g->matrix_arc[y][x] = 1;
    return 1;
}

int Remove_Arc(graph* g, char x, char y){
    
    if((x<'A'|| x>'Z') || (y<'A' || y>'Z')){
        printf("Erreur x or y");
        return -1;
    }
    if(Graph_empty(g)){
        return -1;
    }
    x = x - 'A';
    y = y - 'A';
    g->matrix_arc[x][y] = 0;
    g->matrix_arc[y][x] = 0;
    return 1;
}


void Print_Graph(graph* g){
    if(Graph_empty(g)){
        return;
    }
    printf(" ");
    for(int i = 0; i< g->nb_sommets; i++){
        printf("%c",'A'+ i);
    }
    printf("\n");
    for(int i = 0; i<g->nb_sommets;i++){
        printf("%c",'A' + i);
        for(int j = 0; j<g->nb_sommets;j++){
            printf("%d",g->matrix_arc[i][j]);
        }
        printf("\n");
    }
}


int Graph_empty(graph* g){
    if(g == NULL){
        return -1;
    }
    if(g->nb_sommets <= 0){
        return 1;
    }
    return 0;
}

void Free_Graph(graph* g){
    for( int i = 0; i<g->nb_sommets; i++){
        free(g->matrix_arc[i]);
    }
    free(g->matrix_arc);
}

int main(){
    graph* g = Init_Graph(7);
    Add_Arc(g,'A','D');
    Add_Arc(g,'A','A');
    Print_Graph(g);
    Free_Graph(g);
}

