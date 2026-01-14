#include <stdio.h>
#include <stdlib.h>
#include "LinkListGeneric.h"



int LinkList_empty(List* l){
    if(l->head == NULL){
        return 1;
    }
    return 0;
}

void print_LinkList(List* l){
    if(LinkList_empty(l)){
        return;
    }

    Cell* current = l->head;

    int index = 0;

    while(current != NULL){
        printf("Index : %d\n",index);
        l->printfunc(current->data);
        current= current->next;
        index++;
    }
}

List* init(void* data, FuncFree freefct, FuncCompare cmpfct, FunPrint printfct){
    List* l = malloc(sizeof(List));
    Cell* c = init_Cell(data);

    l->freefunc = freefct;
    l->cmpfunc = cmpfct;
    l->printfunc = printfct;
    l->head = c; 
    return l;
}

Cell* init_Cell(void* data){
    Cell* c = malloc(sizeof(Cell));
    c->data = data;
    c->next = NULL;
    return c;
}

int add_Head(List* l,void* data){
    Cell* c = init_Cell(data);

    if(LinkList_empty(l)){
        l->head = c;
        return 1;
    }
    
    c->next = l->head;
    l->head = c;
    return 1;
}

int add_Last(List* l,void* data){
    Cell* c = init_Cell(data);

    if(LinkList_empty(l)){
        l->head = c;
        return 1;
    }

    Cell* current = l->head;
    Cell* next = l->head->next;

    while(next != NULL){
        current = next;
        next = next->next;
    }
    current->next = c;
    return 1;
}

int remove_Head(List *l){
    if(LinkList_empty(l)){
        return 0;
    }
    if(l->head->next == NULL){
        l->freefunc(l->head->data);
        free(l->head);
        l->head = NULL;
        return 1;
    }
    Cell* next = l->head->next;
    l->freefunc(l->head->data);
    free(l->head);
    l->head = next;
    return 1;

}

int remove_Last(List *l){
    if(LinkList_empty(l)){
        return 0;
    }
    if(l->head->next == NULL){
        l->freefunc(l->head->data);
        free(l->head);
        l->head = NULL;
        return 1;
    }

    Cell* current = l->head;
    Cell* next = l->head->next;

    while(next->next != NULL){
        current = next;
        next = next->next;
    }

    current->next = NULL;
    l->freefunc(next->data);
    free(next);
    return 1;
}

int remove_Index(List* l, int index){
    if(index<0){
        return 0;
    }
    if(LinkList_empty(l)){
        return 0;
    }
    if(index == 0){
        return remove_Head(l);
    }

    Cell* current = l->head;
    Cell* next = l->head->next;

    for(int i = 0;i<index-1;i++){
        current = next;
        next = next->next;
    }

    current->next = next->next;
    l->freefunc(next->data);
    free(next);
    return 1;
}

int find_Elem(List* l,void* data){
    if(LinkList_empty(l)){
        return -1;
    }
    if(data == NULL){
        return -1;
    }
    
    Cell* current = l->head;

    int index = 0;

    while(!(l->cmpfunc(current->data,data))){
        if(current==NULL){
            return -1;
        }
        current = current->next;
        index++;
    }

    return index;
}

typedef struct _test{
    int x;
    int y;
}test;

test* init_teststruct(int x, int y){
    test* t = malloc(sizeof(test));
    t->x = x;
    t->y = y;
    return t;
}

void print_test(void* t){
    test* test = t;
    printf("%d\n",test->x);
    printf("%d\n",test->y);
}

int compare_test(void* aa, void *bb){
    test* a = aa;
    test* b = bb;
    if((a->x==b->x)&&(a->y == b->y)){
        return 1;
    }
    return 0;
}


int main(){
    List* l;
    test* t = init_teststruct(5,7);
    test* test = init_teststruct(7,8);
    l=init(t,NULL,(FuncCompare)compare_test,(FunPrint)print_test);
    add_Head(l,test);
    print_LinkList(l);
    printf("%d\n",find_Elem(l,test));
    
}