/*Procedimento computacional simples para a obtenção da menor*/ 
/*distância entre os valores qualquer de chaves de um vetor*/

#include <iostream>
#include <vector>
#include <cmath>

int main() {
    // Define um vetor de inteiros com valores predefinidos
    std::vector<int> vetor = {50, 100, 200, 300, 400, 500};
    
    // Inicialize a distância com um valor grande o suficiente
    int distancia = std::numeric_limits<int>::max();

    // Tamanho do vetor
    int n = vetor.size();

    // Imprime o vetor
    std::cout << "Vetor: ";
    for (int i = 0; i < n; i++) {
        std::cout << vetor[i] << " ";
    }
    std::cout << std::endl;

    // Itera sobre todos os pares de elementos do vetor
    // i varia de 0 até n - 2 para garantir que haja pelo menos um elemento após i
    for (int i = 0; i < n - 1; i++) {
        // j varia de i + 1 até n - 1 para evitar repetições e comparações desnecessárias
        for (int j = i + 1; j < n; j++) {
            // Imprime os elementos que estão sendo comparados
            std::cout << "Comparando " << vetor[i] << " com " << vetor[j] << std::endl;
            // Calcula a diferença absoluta entre os elementos
            int diferenca = std::abs(vetor[i] - vetor[j]);
            // Imprime a diferença absoluta
            std::cout << "Diferenca absoluta: " << diferenca << std::endl;
            // Atualiza a menor distância se a diferença absoluta for menor do que a distância atual
            if (diferenca < distancia) {
                distancia = diferenca;
                std::cout << "Nova menor distancia: " << distancia << std::endl;
            }	
        }
    }
    
    // Imprime a menor distância encontrada
    std::cout << "A menor distancia entre os elementos do vetor eh: " << distancia << std::endl;

    return 0;
}


