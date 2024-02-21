#include <iostream>
#include <vector>

int main(){
    std::vector<int> vetor = {5, 2, 4, 6, 1, 3};
    int n = vetor.size(); // n é o tamanho do vetor, neste caso, 6

    // Neste loop externo, estamos percorrendo o vetor a partir do primeiro elemento até o penúltimo.
    // O motivo de percorrer até n-1 é que quando chegarmos ao último elemento,
    // o vetor já estará completamente ordenado.
    for (int i = 0; i < n-1; i++) {

        // Neste loop interno, estamos percorrendo o vetor da direita para a esquerda,
        // começando do último elemento e indo até o elemento i+1.
        // O motivo de começar em n-1 e ir até i+1 é que após cada iteração do loop externo,
        // o maior elemento do vetor já estará na posição correta.
        for (int j = n - 1; j >= i + 1; j--){
            // Aqui estamos comparando o elemento atual com o elemento anterior,
            // e se o elemento atual for menor que o elemento anterior, trocamos os dois.
            if (vetor[j] < vetor[j - 1]){
                int auxiliar = vetor[j];
                vetor[j] = vetor[j - 1];
                vetor[j - 1] = auxiliar;
            }
            // Apenas para visualização do progresso do algoritmo, imprimimos os índices i e j.
            std::cout << "i: " << i << " j: " << j << std::endl;
        }
        // Após cada iteração do loop externo, imprimimos o elemento na posição i.
        // Isso nos ajuda a visualizar como o vetor está sendo ordenado passo a passo.
        std::cout << vetor[i] << " " << std::endl;
    }
    std::cout << std::endl;
    // Após ordenar o vetor, imprimimos o vetor ordenado.
    for (int i = 0; i < n; i++){
        std::cout << vetor[i] << " ";
    }

    return 0;
}
