#pragma once
#include <iostream>

typedef struct L_list{
    int valor;
    L_list *prox = NULL;
    void (*push)(L_list ** head, int val);
    void (*push_back)(L_list ** head, int val);
    int (*pop)(L_list ** head);
    void (*sus)();
};
L_list* initList(int valor);
L_list *array_to_list(int *v, int n);
void free_all(L_list **head);

void bubble_sort(L_list **head);
int size(L_list **head);