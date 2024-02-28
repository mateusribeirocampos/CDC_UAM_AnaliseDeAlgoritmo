#include <iostream>

int fatorial(int n) { // complexidade O(n) - custo theta(n)
    if (n == 0) { // caso base - complexidade O(1) - custo theta(1)
        return 1; // fatorial de 0 é 1 - complexidade O(1) - custo theta(1)
    } else { // caso recursivo - complexidade O(n) - custo theta(1)
        return n * fatorial(n - 1); // fatorial de n é n * fatorial de n - 1 - complexidade O(n) - custo theta(n)
    }
}

int main() {
    std::cout << "Digite um numero para calcular o fatorial: ";
    int n;
    std::cin >> n;

    // Visualização do fatorial de cada número
    for (int i = 1; i <= n; ++i) {
        std::cout << "Fatorial de " << i << " = " << fatorial(i) << std::endl;
    }
    return 0;
}