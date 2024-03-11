#include <iostream>
#include <vector>

int main(){
    std::vector<int> vetor = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};

    for(int j = 0; j < vetor.size(); j++){
        std::cout << vetor[j] << " ";
    }
    std::cout << std::endl;
    return 0;
}