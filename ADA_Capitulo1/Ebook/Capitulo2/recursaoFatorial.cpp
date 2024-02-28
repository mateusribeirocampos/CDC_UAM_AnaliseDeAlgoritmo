#include <iostream>
#include <vector>

// Função recursiva para calcular o fatorial de um número
int fatorial(int n) {
    // Caso base: se n é 0 ou 1, o fatorial é 1
    if (n == 0 || n == 1) {
        return 1;
    } else {
        // Caso recursivo: fatorial(n) = n * fatorial(n-1)
        return n * fatorial(n - 1);
    }
}

// Função para calcular o fatorial de cada número no vetor e imprimir o resultado
void funcaoFatorial(std::vector<int>& vetor, int index) {
    // Verifica se o índice está dentro dos limites do vetor
    if (index < vetor.size()) {
        // Calcula o fatorial do número atual e imprime o resultado
        std::cout << "Fatorial de " << vetor[index] << " = " << fatorial(vetor[index]) << std::endl;
        // Chama a função recursivamente para o próximo número no vetor
        funcaoFatorial(vetor, index + 1);
    }
}

int main() {
    std::vector<int> vetor = {1, 3, 5};
    funcaoFatorial(vetor, 0); // Inicia a função recursiva com o índice 0
    
    return 0;
}
