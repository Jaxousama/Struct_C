#ifndef LINKLIST_H
#define LINKLIST_H

typedef void(*FuncFree)(void *);
typedef int(*FuncCompare)(void *a, void *b);
typedef void(*FunPrint)(void *);



typedef struct Node{
    void* data;
    struct Node* next;
}Cell;

typedef struct _list{
    Cell* head;
    FuncFree freefunc;
    FuncCompare cmpfunc;
    FunPrint printfunc;
}List;

int LinkList_empty(List* l);

void print_LinkList(List* l);

List* init_list(FuncFree freefct, FuncCompare cmpfct, FunPrint printfct);

Cell* init_Cell(void* data);

void free_List(List* l);

int add_Head(List* l,void* data);

int add_Last(List* l,void* data);

int remove_Head(List *l);

int remove_Last(List *l);

int remove_Index(List* l, int index);

int remove_first_occurence(List* l, void* data);

int find_Elem(List* l,void* data);

#endif