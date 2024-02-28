#include <iostream>

int fib(int n){ // T(n) = T(n-1) + T(n-2) + theta(1)
    if (n == 1 || n == 2) { // caso base - complexidade O(1) - custo theta(1)
        return 1; // fibonacci de 1 e 2 é 1 - complexidade O(1) - custo theta(1)
    } else { // caso recursivo - complexidade O(n) - custo theta(1)
        return fib(n - 1) + fib(n - 2); // fibonacci de n é fibonacci de n - 1 + fibonacci de n - 2 - complexidade O(n) - custo theta(n)
    }
}

int main(){
    int n;
    std::cout << "Digite um numero para calcular o fibonacci: ";
    std::cin >> n;


    std::cout << "Sequencia de Fibonacci ate " << n << ":" << std::endl;
    for (int i = 1; i <= n; ++i) {
        std::cout << "Fibonacci de " << i << " = " << fib(i) << std::endl;
    }

    return 0;
}