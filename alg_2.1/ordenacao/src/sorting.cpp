#include "sorting.h"
#include <iostream>

void bubble_sort(int n, int* v){
    
    int temp;

    for (int j = 0; j < n; j++)
    for (int i = 0; i < n -1; i++){
        if(v[i] > v[i+1]){
            temp = v[i];
            v[i] = v[i+1];
            v[i+1] = temp;
        }
    }
}

void insertion_sort(int n, int* v){

    int x, j;

    for (int i = 1; i < n; i++){
        x = v[i];

        for (j = i; j >=0 && v[j] >= x; j--){
            v[j] = v[j-1];
        }
        v[j+1] = x;

        // for (int k = 0; k < n; k++){
        //     std::cout << v[k] << ",";
        // }
        // std::cout << "\n";
    }
}

void selection_sort(int n, int* v){
    
    int min, temp;
    bool isOrd = true;

    for (int i = 0; i < n; i++)
    {
        isOrd = true;
        min = i;

        for (int j = min; j < n; j++){
            if (v[min] > v[j]){
                min = j;
            }
        }

        temp = v[i];
        v[i] = v[min];
        v[min] = temp;

        // for (int k = 0; k < n -1; k++){
        //     if (v[k] > v[k+1]){
        //         isOrd = false;
        //         break;
        //     }
        // }
        // if(isOrd)
        //     return;
         
    }

}

void intercala(int inicio, int meio, int fim, int* v){
    
    int i = inicio, s = meio, f = fim;
    int p[fim - inicio];
    int c = 0;

    std::cout<<"Inter: \n";
    std::cout<<"inicio: "<<inicio;
    std::cout<<"\nmeio:"<<meio;
    std::cout<<"\nfim:"<<fim << "\n";
    for (int k = i; k < meio; k++)
    {
        std::cout << v[k] << " ";
    }
    std::cout << " // ";

    for (int k = s; k < fim; k++)
    {
        std::cout << v[k] << " ";
    }
    std::cout << "\n";

    while (i < meio && s < fim ){

        if (v[i] < v[s]){
            p[c] = v[i];
            i++;
        }
        else{
            p[c] = v[s];
            s++;
        }
        c++;
    }

    while (i < meio)
    {
        p[c] = v[i];
        i++;
        c++;
    }
    while (s < fim)
    {
        p[c] = v[s];
        s++;
        c++;
    }

    for (int k = 0; k < c; k++){
        std::cout<<p[k]<< ",";
    }
    std::cout<<"\n";

    for (i = inicio; i < fim; i++){
        v[i] = p[i - inicio];
    }
    
}

void merge_sort(int c, int f, int *v){

    int metade;

    std::cout<< "c:"<< c << " f:" << f << "\n";
    for (int i = c; i < f; i++)
    {
        std::cout << v[i] << " ";
    }
    std::cout <<"\n------------------\n";
    
    if (c < f - 1){
        metade = (c + f) / 2;

        merge_sort(c, metade, v);
        merge_sort(metade, f, v);
        intercala(c, metade, f, v);
    }
    
}

void quick_sort(int c, int f, int *v){
    
    if( c >= f){
        return;
    }

    // for(int k = c; k < f; k++){
    //     std::cout << v[k] << " ";
    // }
    // std::cout<<"\n";

    int pivot = v[f - 1];
    int i = c;
    int men = c - 1, mai;
    int temp;
    
    while(i < f){
        if(v[i] < pivot){
            men++;
            
            temp = v[i];
            v[i] = v[men];
            v[men] = temp;
        }
        i++;
    }
    v[f - 1] = v[men+1];
    v[men+1] = pivot;

    for (int k = c; k < men+1; k++){
        std::cout << v[k] << " ";
    }
    std::cout << " | " << v[men+1] << " | ";

    for (int k = men+2; k < f; k++){
        std::cout << v[k] << " ";
    }
    std::cout<<"\n";

    quick_sort(c, men+1, v);
    quick_sort(men+2, f, v);
}

void stalin_sort(int *n, int *v){
    
    int tam = 0;
    int w[*n];

    w[0] = v[0];
    for (int i = 1; i < *n; i++){
        if(v[i] >= w[tam]){
            tam++;
            w[tam] = v[i];
        }
    }

    for (int i = 0; i <= tam; i++){
        v[i] = w[i];
    }
    *n = tam;
}