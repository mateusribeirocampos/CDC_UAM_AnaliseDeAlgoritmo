/*Permuta */
/* p = n(n - 1)(n - 2)...(n + k + 1)*/

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // permutação de 3 elementos
    std::vector<int> vetor = {1, 2, 3};
    do {
        for (int i = 0; i < vetor.size(); i++) {
            std::cout << vetor[i] << " ";
        }
        std::cout << std::endl;
    } while (std::next_permutation(vetor.begin(), vetor.end()));
    return 0;
}