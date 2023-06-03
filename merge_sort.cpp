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

void merge(int vetor[TAM], int indiceEsquerdo, int meio, int indiceDireito){

    int i, j, k;
    int n1 = meio - indiceEsquerdo + 1;
    int n2 = indiceDireito - meio;

    int vetorEsquerdo[n1], vetorDireito[n2];

    for(i = 0; i < n1; i++){
        vetorEsquerdo[i] = vetor[indiceEsquerdo + i];
    }

     for(j = 0; j < n2; j++){
        vetorDireito[j] = vetor[meio + 1 + j];
    }

    i = 0;
    j = 0;
    k = indiceEsquerdo;

    while(i < n1 && j < n2){

        if(vetorEsquerdo[i] <= vetorDireito[j]){

            vetor[k] = vetorEsquerdo[i];

            i++;
        }else{
            vetor[k] = vetorDireito[j];

            j++;
        }

        k++;
    }

    while(i < n1){
        vetor[k] = vetorEsquerdo[i];
        i++;
        k++;
    }
    while(j < n2){
        vetor[k] = vetorDireito[j];
        j++;
        k++;
}
}


void merge_sort(int vetor[TAM], int indiceEsquerdo, int indiceDireito){

    if(indiceEsquerdo < indiceDireito){

        int meio = indiceEsquerdo + (indiceDireito - indiceEsquerdo) / 2;

        merge_sort(vetor, indiceEsquerdo, meio);
        merge_sort(vetor, meio+1, indiceDireito);

        merge(vetor, indiceEsquerdo, meio, indiceDireito);


    }

}



int main(){

    int vetor[TAM] = {10,9,8,7,6,5,4,3,2,1};

    imprime_vetor(vetor);

    merge_sort(vetor, 0, TAM - 1);

    imprime_vetor(vetor);

    return 0;
}
