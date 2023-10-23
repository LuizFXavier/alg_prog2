#include <iostream>
#include "L_list.h"

int main() {

    L_list *lista = (L_list *) malloc(sizeof(L_list));
    lista = initList(0);
    lista->sus();

    int t = 4;
    int vec[t] = {4,3,5,1};

    L_list *lol = array_to_list(vec, t);

    for (int i = 1; i < 5; i++){

        lista->push(&lista, i);
        // lista->sus();
        // std::cout<<lista->valor<<"\n";
    }
    // std::cout<<lol->pop(&lol)<<"\n";
    // std::cout<<lol->pop(&lol)<<"\n";
    // std::cout<<lista->pop(&lista)<<"\n";

    lol->push_back(&lol, 2);
    L_list *atual = lol;

    while (atual != NULL)
    {
        std::cout<<atual->valor<<" ";
        atual = atual->prox;
    }
    std::cout<<"\n";

    bubble_sort(&lol);
    
    atual = lol;

    while (atual != NULL)
    {
        std::cout<<atual->valor<<" ";
        atual = atual->prox;
    }

    std::cout<<"\n"<<size(&lol);

    std::cout<<"\n";

    // std::cout<<lista->valor<<"\n";

    free_all(&lista);
    free_all(&lol);

    return 0;
}