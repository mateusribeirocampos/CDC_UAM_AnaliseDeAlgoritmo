#include <iostream>
#include <vector>
#include <chrono>

// complexidade O(n)
void imprimirVetor(std::vector<int> vetor)
{
    std::cout << std::endl; // complexidade O(1)
    for (int i = 0; i < vetor.size(); i++) // complexidade O(n)
    {
        std::cout << " |" << vetor[i] << "| "; // complexidade O(1)
    }
}
// complexidade O(n^2)
void bubbleSort(std::vector<int> &vetor) {
    int i, j, aux; // complexidade atribuição O(1)
    for (i = 0; i < vetor.size(); i++) { // complexidade O(n)
        for (j = 0; j < vetor.size() - 1; j++) { // complexidade O(n)
            if (vetor[j] > vetor[j + 1]) { // comparação complexidade O(1)
                aux = vetor[j]; // complexidade O(1)
                vetor[j] = vetor[j + 1]; // complexidade O(1)
                vetor[j + 1] = aux; // complexidade O(1)
                std::cout << "Troca: " << vetor[j] << " com " << vetor[j + 1] << std::endl; // complexidade O(1)
            }
            // remover a ordenação desnecessária
            if (vetor[j] < vetor[j + 1]) { // comparação complexidade O(1)
                std::cout << "Nao troca: " << vetor[j] << " com " << vetor[j + 1] << std::endl; // complexidade O(1)
            }
            // Para verificar o passo a passo do ordenamento
            imprimirVetor(vetor);
        }
    }
}
// complexidade total O(n^2)
int main(){
    std::vector<int> vetor = {2, 3, 5, 1, 4}; // complexidade O(1)

    imprimirVetor(vetor); // complexidade O(n)
    std::cout << std::endl; // complexidade O(1)

    // Obtenha o tempo de início antes de chamar a função selectionSort
    auto start = std::chrono::high_resolution_clock::now();

    bubbleSort(vetor);  // complexidade O(n^2)
    std::cout << "\nVetor ordenado: " << std::endl; // complexidade O(1)

    // Obtenha o tempo de término após a função selectionSort retornar
    auto end = std::chrono::high_resolution_clock::now();

    // Calcule a diferença entre o tempo de término e o tempo de início, isso dará a duração da execução da função selectionSort
    std::chrono::duration<double> diff = end-start;

    imprimirVetor(vetor); // complexidade O(n)

    // Imprima a duração da execução da função selectionSort
    std::cout << "Tempo de execucao: " << diff.count() << std::endl; // complexidade O(1)

    // complexidade total O(n^2)

    return 0;
}