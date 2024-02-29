#include <iostream>
#include <vector>

void imprimeVetor(std::vector<int> vetor) {
    // percorrendo o vetor
    for(int i = 0; i < vetor.size(); i++) {
        // imprimindo o valor do vetor na posição i
        std::cout << " |" << vetor[i] << "| ";
    }
    // quebrando a linha
    std::cout << std::endl;
}

void selectionSort(std::vector<int> &vetor) {
    // estabelendo o tamanho do vetor
    int tamanhoVetor = vetor.size(); // complexidade O(1)

    // percorrendo o vetor para ordenar 
    for(int i = 0; i < tamanhoVetor - 1; i++) { // complexidade O(n)

        // estabelendo o menor valor
        int menor = i; // complexidade O(1)
        std::cout << "Menor valor: " << vetor[menor] << std::endl;

        // percorrendo o vetor para encontrar o menor valor e trocar de posição com o valor atual do vetor
        // j = i + 1 para não comparar o mesmo valor
        // j < tamanhoVetor para não acessar um valor que não existe
        for(int j = i + 1; j < tamanhoVetor; j++) { // complexidade O(n)
            // se o valor do vetor na posição j for menor que o valor do vetor na posição menor
            if(vetor[j] < vetor[menor]) { // complexidade O(1)

                // o menor valor passa a ser o valor na posição j
                menor = j; // complexidade O(1)
                std::cout << "Menor valor: " << vetor[menor] << std::endl;
            }
        }
        // troca de posição
        // std::swap(vetor[i], vetor[menor]);
        // ao inves de usar a função swap, poderia ser feito da seguinte forma:
        int aux = vetor[i]; // complexidade O(1)
        vetor[i] = vetor[menor]; // complexidade O(1)
        vetor[menor] = aux; // complexidade O(1)
        // imprimindo o vetor a cada troca
        std::cout << "Vetor apos a troca: " << std::endl;
        imprimeVetor(vetor);
    }
}

int main () {   
    // estabelendo um vetor de inteiros
    std::vector<int> vetor = {20, 12, 10, 15, 2};
    
    // imprimindo o vetor desordenado
    imprimeVetor(vetor);
    // chamando a função selectionSort
    selectionSort(vetor);

    // imprimindo o vetor ordenado
    imprimeVetor(vetor);

    // A complexidade total seria a soma e o aninhamento de dois loopings
    // O(n) * O(n) = O(n^2)
    // Então, o Selection Sort tem complexidade O(n^2)

    return 0;
}