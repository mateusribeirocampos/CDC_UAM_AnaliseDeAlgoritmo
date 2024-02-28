#include <iostream>

int fatorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * fatorial(n - 1);
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