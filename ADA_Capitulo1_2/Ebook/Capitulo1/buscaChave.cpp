#include <iostream>
#include <vector>

int main()
{
    std::vector<int> vetor = {25, 57, 48, 37, 12, 92, 86, 33}; // complexidade O(1)
        // melhor caso
    int chave1 = 25; // complexidade O(1)
    for (int i = 0; i < vetor.size(); i++) // complexidade O(n)
    {
        if (vetor[i] == chave1) // comparação complexidade O(1)
        {
            std::cout << "Chave encontrada na posicao: " << i << std::endl; // complexidade O(1)
            break;                                                          // complexidade O(1)
        }
        std::cout << "Chave nao encontrada - posicao: " << i++ << std::endl; // complexidade O(1)
    }
    // pior caso
    int chave2 = 33; // complexidade O(1)
    for (int i = 0; i < vetor.size(); i++) // complexidade O(n)
    {
        if (vetor[i] == chave2) // comparação complexidade O(1)
        {
            std::cout << "Chave encontrada na posicao: " << i << std::endl; // complexidade O(1)
            break;                                                          // complexidade O(1)
        }
        std::cout << "Chave nao encontrada - posicao: " << i << std::endl; // complexidade O(1)
    }
    return 0;
}