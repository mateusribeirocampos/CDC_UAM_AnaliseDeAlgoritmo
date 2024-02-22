/*1 = 1^2*/
/*1 + 3 = 2^2*/
/*1 + 3 + 5 = 3^2*/
/*1 + 3 + 5 + 7 = 4^2*/

#include <iostream>

int main() {
    int n;
    std::cout << "Digite um numero inteiro: ";
    std::cin >> n;

    int soma = 0;
    for (int i = 0; i < n; i++) {
        soma += 2 * i + 1; // Adiciona o próximo número ímpar à soma
        std::cout << "1"; // Começa a impressão da sequência com "1"
        for (int j = 0; j < i; j++) {
            std::cout << " + " << 2 * j + 3; // Imprime os números ímpares subsequentes
        }
        std::cout << " = " << soma << " = " << (i + 1) << "^2" << std::endl; // Imprime a soma e o quadrado do número de termos
    }
    return 0;
}

