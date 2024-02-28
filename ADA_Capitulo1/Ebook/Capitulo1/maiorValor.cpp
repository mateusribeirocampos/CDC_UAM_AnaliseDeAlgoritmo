#include <iostream>
#include <vector>

int main(){
    std::vector<int> vetor = {1, 200, 3, 99, 756};

    // Inicializa a variável maior com o primeiro valor do vetor
    int maior = vetor[0];
    // Percorre o vetor
    for (int i = 1; i < vetor.size(); i++) {
        // Se o valor atual do vetor for maior que o valor armazenado na variável maior
        if (vetor[i] > maior) {
            // Atualiza a variável maior
            maior = vetor[i];
        }
    }
    std::cout << "O maior valor do vetor eh: " << maior << std::endl;
    return 0;
}