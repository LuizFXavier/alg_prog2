#include "L_list.h"

void push(L_list ** head, int val){

    L_list * new_item;
    new_item = initList(val);

    new_item->prox = *head;
    *head = new_item;
}

int pop(L_list ** head){

    int valor = -1;

    if(*head == NULL){
        return valor;
    }

    L_list *next = (*head)->prox;
    valor = (*head)->valor;
    free(*head);
    *head = next;

    return valor;
}

void sos(){
    std::cout<<"sus\n";
}

void push_back(L_list ** head, int val){

    L_list * new_item;
    new_item = initList(val);

    L_list *atual = *head;
    L_list *certo = atual;

    while (atual != NULL)
    {
        certo = atual;
        atual = atual->prox;
    }

    certo->prox = new_item;

}

L_list* initList(int valor){

    L_list* lista = (L_list *) malloc(sizeof(L_list));
    lista->valor = valor;
    lista->sus = sos;
    lista->push = push;
    lista->pop = pop;
    lista->push_back = push_back;
    return lista;
}

L_list *array_to_list(int *v, int n){

    L_list *lista = initList(v[0]);

    for (int i = 1; i < n; i++){
        lista->push(&lista, v[i]);
    }

    return lista;
}



void free_all(L_list **head){
    L_list * temp;

    while (*head != NULL)
    {
        temp = *head;
        *head = (*head)->prox;
        free(temp);
    }
    
}


void bubble_sort(L_list **head){
    L_list *ultimo = NULL;
    int temp;

    if ((*head)->prox == NULL){
        return;
    }

    while (ultimo != *head)
    {
        L_list *atual = *head;
        while (atual->prox != ultimo)
        {
            if(atual->valor > atual->prox->valor){
                temp = atual->valor;
                atual->valor = atual->prox->valor;
                atual->prox->valor = temp;
            }
            atual = atual->prox;
        }
        ultimo = atual;
    }
    
}

void selection_sort(L_list **head){
    
}

int size(L_list **head){

    L_list *atual = *head;
    int tam = 0;

    while (atual != NULL)
    {
        tam++;
        atual = atual->prox;
    }
    return tam;
}