#include <stdio.h>
#include <stdlib.h>
#include "GraphLinkList.h"



List* Init_Graph(){
    List* l = init_list(&free_Edges,&Compare_Edges,&Print_Edges);
    return l;
}

Edges* Init_Edges(char x, char y, int values){
    Edges* e = malloc(sizeof(Edges));
    e->vertices_x = x;
    e->vertices_y = y;
    e->values = values;
    return e;
}

void free_Graph(List* l){
    free_List(l);
}

void free_Edges(void* _e){
    Edges* e = _e;
    free(e);
}

void print_Graph(List *l){
    print_LinkList(l);
}

int Add_Edges(List* l, char x, char y, int values){
    Edges* e = Init_Edges(x,y,values);
    if(find_Elem(l,e) == -2){
        return -1;
    }
    add_Head(l,e);
    return 1;
}

int Remove_Edges(List* l, char x, char y, int values){
    Edges* e = Init_Edges(x,y,values);
    return remove_first_occurence(l,e);
}

int Graph_empty(List* l){
    return LinkList_empty(l);
}

int Compare_Edges(void* _x,void* _y){
    Edges* x = _x;
    Edges* y = _y;
    if((x->vertices_x==y->vertices_x )&&(x->vertices_y==y->vertices_y)&& (x->values == y->values)){
        return 1;
    }
    return 0;
}

void Print_Edges(void* _e){
    Edges* e = _e;
    printf("%c--%d--%c\n",e->vertices_x,e->values,e->vertices_y);
}

int main(){
    List* g = Init_Graph();
    Add_Edges(g,'A','B',6);
    Add_Edges(g,'A','C',9);
    Remove_Edges(g,'A','B',8);
    print_Graph(g);
}

