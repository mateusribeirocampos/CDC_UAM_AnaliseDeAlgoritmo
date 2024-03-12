#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

int buscaBinaria(vector<int> &vetor, int min, int max, int x) {
    if(min > max) {
        cout << "Elemento nao encontrado" << endl;
        return -1;
    }
    int meio = (min + max) / 2;
    if(vetor[meio] == x) {
        cout << "Elemento " << x << " encontrado na posicao " << meio << endl;
        return meio;
    } else if(vetor[meio] < x) {
        return buscaBinaria(vetor, meio + 1, max, x); // Added missing argument "x"
    } else {
        return buscaBinaria(vetor, min, meio - 1, x); // Added missing argument "x"
    }
    
}

void imprimirIndice(int indice, int n) {
        cout << "[";
    for(indice = 0; indice < n; indice++){
        cout << indice;
        if(indice < n - 1){
            cout << ", ";
        }
    }
    cout << "]" << endl;
    
}

void imprimirVetor(vector<int> &vetor, int min, int max){
    cout << "[";
    for(int i = min; i < max; i++){
        cout << vetor[i];
        if(i < max - 1){
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

int main() {
    vector<int> vetor = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int n = vetor.size();
    int min = 0, max = n - 1;
    int x = 11;
    int indice = 0;


    imprimirVetor(vetor, min, max);
    imprimirIndice(indice, n);

    auto inicioExecucao = chrono::high_resolution_clock::now();

    buscaBinaria(vetor, min, max, x);

    auto fimExecucao = chrono::high_resolution_clock::now();
    chrono::duration<double> diff = fimExecucao - inicioExecucao;

    cout << "Tempo de execucao: " << chrono::duration_cast<chrono::nanoseconds>(fimExecucao - inicioExecucao).count() << " ns" << endl;

    return 0;
}