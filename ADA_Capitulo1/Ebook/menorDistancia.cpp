/*Procedimento computacional simples para a obtenção da menor*/ 
/*distância entre os valores qualquer de chaves de um vetor*/

#include <iostream>
#include <vector>
#include <cmath>

int main() {
    std::vector<int> vetor = {21, 200, 3, 99, 756, 368, 84, 451, 6987};
    
    // Inicialize a distância com um valor grande o suficiente
    int distancia = std::numeric_limits<int>::max();

    // Tamanho do vetor
    int n = vetor.size();

    std::cout << "Vetor: ";
    for (int i = 0; i < n; i++) {
        std::cout << vetor[i] << " ";
    }
    std::cout << std::endl;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            std::cout << "Comparando " << vetor[i] << " com " << vetor[j] << std::endl;
            // Use abs() para calcular a diferença absoluta
            int diferenca = std::abs(vetor[i] - vetor[j]);
            std::cout << "Diferenca absoluta: " << diferenca << std::endl;
            if (diferenca < distancia) {
                distancia = diferenca;
                std::cout << "Nova menor distancia: " << distancia << std::endl;
            }	
        }
    }
    
    std::cout << "A menor distancia entre os elementos do vetor eh: " << distancia << std::endl;

    return 0;
}

