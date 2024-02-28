#include <iostream>
#include <vector>

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
    std::vector<int> vetor = {31, 41, 59, 26, 41, 58};

    imprimirVetor(vetor);

    ordenacaoPorInsercaoDireta(vetor);

    std::cout << "\n\nVetor ordenado: ";
    imprimirVetor(vetor);

    return 0;
}