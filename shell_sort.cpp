#include <iostream>
#include <stdlib.h>
#include <string>
#define TAM 10

using namespace std;

void imprime_vetor(int vetor[]){

    int i;

    cout << "\n";

    for(i = 0; i < TAM; i++){
        cout << "|" << vetor[i] << "| ";
    }
}

void shell_sort(int vetor[TAM]){

    int h = 1;

    int i, j, atual;

    while(h < TAM){
        h = 3*h+1;
    }

    while(h > 1){

        h = h/3;

        for(i = h; i < TAM; i++){

        atual = vetor[i];

        j = i - h;

        while( (j >=0) && (atual < vetor[j])){

            vetor[j + h] = vetor[j];

            j = j - h;
        }

     vetor[j + h] = atual;

     imprime_vetor(vetor);


    }
}



}


int main(){

    int vetor[TAM] = {10,9,8,7,6,5,4,3,2,1};

    shell_sort(vetor);

    imprime_vetor(vetor);

    return 0;
}
