#include <iostream>
#include <vector>
#include <chrono>

void imprimirVetor(std::vector<int> vetor)
{
    for (int i = 0; i < vetor.size(); i++)
    {
        std::cout << " |" << vetor[i] << "| ";
    }
}

void ordenacaoPorInsercaoDireta(std::vector<int> &vetor)
{
    int i, j, chave;
    // Loop para percorrer o vetor a partir do segundo elemento (índice 1)
    for (i = 1; i < vetor.size(); i++)
    {// Armazena o valor do elemento atual na variável "chave"
        chave = vetor[i];
        std::cout << "\n\nChave: " << chave << std::endl;
        // Define o índice do elemento anterior ao elemento atual
        j = i - 1;
        std::cout << "Indice do elemento anterior: " << j << std::endl;
        // Loop para encontrar a posição correta para inserir o elemento "chave"
        while (j >= 0 && vetor[j] < chave)
        {
            // Desloca o elemento na posição "i" para a posição "i + 1"
            vetor[j + 1] = vetor[j];
            std::cout << "vetor[j + 1] = vetor[j]: |" << vetor[j + 1] << "| " << std::endl;
            // Decrementa o índice "i" para analisar o elemento anterior
            j--;
        }
        // Insere o elemento "chave" na posição correta
        vetor[j + 1] = chave;
        std::cout << "\n\nVetor[j + 1] = chave: |" << vetor[j + 1] << "| " << std::endl;
        imprimirVetor(vetor);
    }
}

int main()
{
    std::vector<int> vetor = {5, 4, 3, 2, 1};

    imprimirVetor(vetor);

    // Obtenha o tempo de início antes de chamar a função selectionSort
    auto start = std::chrono::high_resolution_clock::now();

    ordenacaoPorInsercaoDireta(vetor);

    // Obtenha o tempo de término após a função selectionSort retornar
    auto end = std::chrono::high_resolution_clock::now();

    // Calcule a diferença entre o tempo de término e o tempo de início, isso dará a duração da execução da função selectionSort
    std::chrono::duration<double> diff = end-start;

    std::cout << "\n\nVetor ordenado: ";
    imprimirVetor(vetor);

    // Imprima a duração da execução da função selectionSort
    std::cout << "Tempo de execucao: " << diff.count() << std::endl; // complexidade O(1)

    return 0;
}