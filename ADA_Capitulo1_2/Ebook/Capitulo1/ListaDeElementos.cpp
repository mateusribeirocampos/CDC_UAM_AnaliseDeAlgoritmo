#include <iostream>
#include <vector>

int main(){
    std::vector<int> vetor = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};

    std::cout << vetor[2] << std::endl;
    std::cout << vetor[5] << std::endl;

    for (int i = 0; i < vetor.size(); i++){
        std::cout << vetor[i] << " ";
    }
    return 0;
}