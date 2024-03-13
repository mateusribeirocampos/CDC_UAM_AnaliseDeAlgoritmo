#include <iostream>
#include <vector>

using namespace std;

void countingSort(vector<int>& D, vector<int>& A, int tam_mem, int max_iter) {
    // Inicialize o vetor de contagem C
    vector<int> C(tam_mem, 0);
    
    // Contagem do número de atualizações para cada página
    for (int i = 0; i < max_iter; ++i) {
        C[A[i]] += 1;
    }
    
    // Atualize o vetor de contagem para conter as posições finais das páginas
    for (int i = 1; i < tam_mem; ++i) {
        C[i] += C[i - 1];
    }
    
    // Crie um vetor auxiliar para armazenar a ordenação temporária das páginas
    vector<int> Temp(max_iter);
    for (int i = max_iter - 1; i >= 0; --i) {
        Temp[C[A[i]] - 1] = D[i];
        C[A[i]] -= 1;
    }
    
    // Copie as páginas ordenadas de volta para o vetor original D
    for (int i = 0; i < max_iter; ++i) {
        D[i] = Temp[i];
    }
}

int main() {
    // Exemplo de uso
    vector<int> D = {3, 1, 4, 2}; // Identificadores das páginas de memória
    vector<int> A = {0, 1, 1, 2}; // Número de vezes que cada página foi atualizada
    int tam_mem = 4; // Tamanho do vetor D
    int max_iter = 4; // Número máximo de iterações
    
    // Ordenar o vetor D de acordo com o número de vezes que cada página foi atualizada
    countingSort(D, A, tam_mem, max_iter);
    
    // Imprimir o vetor D ordenado
    cout << "Páginas de memória ordenadas: ";
    for (int i = 0; i < tam_mem; ++i) {
        cout << D[i] << " ";
    }
    cout << endl;
    
    return 0;
}
