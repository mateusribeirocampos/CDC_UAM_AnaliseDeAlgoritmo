#include <iostream>

// Função recursiva que calcula o valor de func(n)
// Complexidade:
// T(n) = 2T(n/2) + O(n)
// Onde:
//   - T(n/2) é o tempo para calcular func(n/2) recursivamente
//   - O(n) é o tempo para iterar sobre o loop for
int func(int n) {
    int resp = 0, z = 0;
    if (n == 0) {
        resp = 1;
    } else {
        // A função é chamada duas vezes com argumento n/2
        // Portanto, a complexidade desta parte é 2T(n/2)
        resp = func(n/2) + func(n/2);
    }
    // O loop for executa n vezes, portanto, tem complexidade O(n)
    for(int i = 0; i < n; i++) {
        z = resp + 1;
    }
    return z;
}

int main() {
    int n;
    std::cout << "Digite um numero: " << std::endl;
    std::cin >> n;

    func(n); // Chamada recursiva

    // Iteração sobre os valores de func(i) para i variando de 0 a n-1
    for(int i = 0; i < n; i++) {
        std::cout << "func = " << func(i) << std::endl;
    }

    return 0;
}
