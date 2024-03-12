#include <iostream>
#include <vector>
#include <algorithm>

// Função para resolver o problema usando o algoritmo guloso
void resolverProblemaGuloso(std::vector<int>& elementos) {
    // Ordena os elementos em ordem não decrescente
    std::sort(elementos.begin(), elementos.end());

    // Variável para armazenar a solução
    std::vector<int> solucao;

    // Percorre os elementos em ordem crescente
    for (int i = 0; i < elementos.size(); i++) {
        // Verifica se o elemento atual pode ser adicionado à solução
        if (solucao.empty() || elementos[i] > solucao.back()) {
            solucao.push_back(elementos[i]);
        }
    }

    // Imprime a solução
    std::cout << "Solucao: [";
    for (int i = 0; i < solucao.size(); i++) {
        std::cout << solucao[i];
        if(i < solucao.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]";
    std::cout << std::endl;
}

int main() {
    // Vetor de elementos
    std::vector<int> elementos = {5, 3, 8, 2, 9, 1};

    // Chama a função para resolver o problema
    resolverProblemaGuloso(elementos);

    return 0;
}