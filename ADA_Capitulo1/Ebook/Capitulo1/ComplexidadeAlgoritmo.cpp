#include <iostream>

// Função para realizar uma pesquisa linear em um array
void pesquisaLinear(int array[], int n, int chave) {
    // Percorre todo o array
    for (int i = 0; i < n; i++) {
        // Se o elemento atual do array for igual à chave
        if (array[i] == chave) {
            // Imprime a posição do elemento encontrado e retorna
            std::cout << "Elemento encontrado no indice " << i << std::endl;
            return;
        }
    }
    // Se a função chegar até aqui, significa que a chave não foi encontrada no array
    std::cout << "Elemento nao encontrado" << std::endl;
}

int main() {
    // Define um array de inteiros
    int array[] = {1, 2, 3, 4, 5};
    // Calcula o número de elementos no array
    int n = sizeof(array) / sizeof(array[0]);
    // Define a chave a ser procurada no array
    int chave = 4;

    // Chama a função de pesquisa linear
    pesquisaLinear(array, n, chave);

    return 0;
}