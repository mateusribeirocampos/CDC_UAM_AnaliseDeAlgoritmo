#include <iostream>
#include <vector>
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

int main() {
    vector<int> vetor = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int n = vetor.size();
    int min = 0, max = n - 1;
    int x = 11;

    buscaBinaria(vetor, min, max, x);

    return 0;
}