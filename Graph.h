#ifndef GRAPH_H
#define GRAPH_H

typedef struct Graph {
    unsigned int nb_sommets;
    int** matrix_arc;
}graph;

graph* Init_Graph(int sommet);

int Add_Arc(graph* g, char x, char y);

int Remove_Arc(graph* g, char x, char y);

void Print_Graph(graph* g);

int Graph_empty(graph* g);

#endif