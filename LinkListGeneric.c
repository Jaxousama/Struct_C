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

List* init_list(FuncFree freefct, FuncCompare cmpfct, FunPrint printfct){
    List* l = malloc(sizeof(List));

    l->freefunc = freefct;
    l->cmpfunc = cmpfct;
    l->printfunc = printfct;
    l->head = NULL;
    return l;
}

Cell* init_Cell(void* data){
    Cell* c = malloc(sizeof(Cell));
    c->data = data;
    c->next = NULL;
    return c;
}

void free_List(List* l){
    Cell* current = l->head;
    Cell* next = current->next;
    while(current != NULL){
        if(l->freefunc!=NULL){
            l->freefunc(current->data);
        }
        free(current);
        current = next;
        next = next->next;
    }
    free(l);
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

int remove_first_occurence(List* l, void* data){
    if(LinkList_empty(l)){
        return -1;
    }
    if(data == NULL){
        return -1;
    }

    int index = find_Elem(l,data);

    remove_Index(l,index);

    return 1;
}

/*
find_Elem(List* l,void* data)
return the index of data if data is in the list 
args:
-List* l -> the list where we search for data
-void* data -> data search in the list
return:
index -> the index of the data
-1 -> if data was not found
-2 -> if data == NULL
*/

int find_Elem(List* l,void* data){
    if(LinkList_empty(l)){
        return 0;
    }
    if(data == NULL){
        return -2;
    }
    
    Cell* current = l->head;
    int index = 0;
    while(!(l->cmpfunc(current->data,data))){
        current = current->next;
        if(current==NULL){
            return -1;
        }
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


/*
void print_test(void* t){
    printf("%d\n",*(int*)t);
}

int compare_test(void* aa, void *bb){
    
}


int main(){
    List* l;
    int t = 7;
    int test = 8;
    l=init_list(NULL,(FuncCompare)compare_test,(FunPrint)print_test);
    add_Head(l,&t);
    add_Head(l,&test);
    print_LinkList(l);
}
*/