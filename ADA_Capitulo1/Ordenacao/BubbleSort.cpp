#include <iostream>
#include <vector>

int main (){
    std::vector<int> vetor = {5, 2, 4, 6, 1, 3};
    int n = vetor.size(); // n é o tamanho do vetor, neste caso, 6

    // Este loop percorre o vetor a partir do segundo elemento até o último.
    // O motivo de começar em j=1 é que não há necessidade de comparar o primeiro elemento consigo mesmo.
    for (int j = 1; j < n; j++){
        int chave = vetor[j]; // A chave é o elemento atual que será inserido na posição correta.
        int i = j - 1;

        // Este loop while desloca os elementos maiores que a chave uma posição à frente
        // para abrir espaço para a inserção da chave na posição correta.
        // Ele continua até encontrar a posição correta para a chave ou chegar ao início do vetor.
        while (i >= 0 && vetor[i] > chave) {
            vetor[i + 1] = vetor[i]; // Desloca o elemento para a direita.
            i = i - 1;
        }
        // Insere a chave na posição correta encontrada no loop while.
        vetor[i + 1] = chave;
    }

    // imprimindo o vetor ordenado
    for (int i = 0; i < n; i++){
        std::cout << vetor[i] << " ";
    }

    return 0;
}
