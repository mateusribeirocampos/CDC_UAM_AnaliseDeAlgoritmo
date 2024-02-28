#include <iostream>

int function(int n){
    if(n == 0) {
        return 1; // Complexidade: O(1)
    } else {
        int resultado = 0; // Complexidade: O(1)
        for(int i = 0; i < n; i++) { // Complexidade: O(n)
            resultado = function(n - 1) * 2; // Recorrência: T(n) = 2T(n - 1) + 1
        }
        return resultado; // Complexidade: O(1)
    }
}

int main(){
    int n;
    std::cout << "Digite um numero: " << std::endl;
    std::cin >> n;

    function(n); // Chamada da função

    for(int i = 0; i < n; i++) {
        std::cout << "function = " << function(i) << std::endl; // Chamadas da função dentro do loop
    }

    return 0;
}
