#ifndef GRAPH_H
#define GRAPH_H
#include "LinkListGeneric.h"
#include "GraphLinkList.h"

typedef struct Edges {
    char vertices_x;
    char vertices_y;
    int values;
}Edges;

List* Init_Graph();

void free_Graph(List* l);

Edges* Init_Edges(char x, char y, int values);

void free_Edges(void* _e);

void print_Graph(List *l);

int Add_Edges(List* l, char x, char y, int values);

int Remove_Edges(List* l, char x, char y, int values);

int Graph_empty(List* l);

int Compare_Edges(void* _x,void* _y);

void Print_Edges(void* _e);

#endif
