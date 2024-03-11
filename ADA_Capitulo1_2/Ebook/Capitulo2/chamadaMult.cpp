#include <iostream>

int chamadaFunc(int n){
    if(n == 0) {
        return 1; // Complexidade: O(1)
    } else {
        return chamadaFunc(n - 1) * 2; // Recorrência: T(n) = 2T(n - 1) + 1
    }
}
int main(){
    int n;
    std::cout << "Digite um numero: " << std::endl;
    std::cin >> n;

    chamadaFunc(n); // Chamada da função

    for(int i = 0; i < n; i++) {
        std::cout << "chamadaFunc = " << chamadaFunc(i) << std::endl; // Chamadas da função dentro do loop
    }

    return 0;
}