#include <iostream>
#include <vector>
using namespace std;

void imprimirVetor(const vector<int> &vetor)
{
    cout << "[";
    for (auto i = 0; i < vetor.size(); i++)
    {
        cout << vetor[i];
        if (i < vetor.size() - 1)
        {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

vector<int> countingSort(const vector<int> &vetor)
{
    int tamanhoVetor = vetor.size();
    cout << "Tamanho do vetor: " << tamanhoVetor << endl;

    // Encontrar o maior elemento no vetor.
    int maiorElemento = 0;
    for (auto i = 0; i < tamanhoVetor; i++)
    {
        if (vetor[i] > maiorElemento)
        {
            maiorElemento = vetor[i];
            cout << "Maior elemento: " << maiorElemento << endl;
        }
    }

    // Inicializar o vetor de contagem com o tamanho adequado e preenchê-lo com zeros.
    vector<int> vetorContagem(maiorElemento + 1, 0);
    cout << "Tamanho do vetor de contagem: " << vetorContagem.size() << endl;

    // Contar a ocorrência de cada elemento no vetor original.
    for (int i = 0; i < tamanhoVetor; i++)
    {
        vetorContagem[vetor[i]]++;
    }

    // Calcular as posições corretas de cada elemento no vetor ordenado.
    for (int i = 1; i < vetorContagem.size(); i++)
    {
        vetorContagem[i] += vetorContagem[i - 1];
    }

    // Construir o vetor ordenado.
    vector<int> vetorOrdenado(tamanhoVetor);
    for (int i = tamanhoVetor - 1; i >= 0; i--)
    {
        vetorOrdenado[vetorContagem[vetor[i]] - 1] = vetor[i];
        vetorContagem[vetor[i]]--;
    }
    return vetorOrdenado;
}

int main()
{
    vector<int> vetor = {2, 5, 3, 0, 2, 3, 0, 3};

    // Ordenar o vetor utilizando counting sort.
    vector<int> vetorOrdenado = countingSort(vetor);

    // Imprimir o vetor original e o vetor ordenado.
    cout << "Vetor original: ";
    imprimirVetor(vetor);
    cout << "Vetor ordenado: ";
    imprimirVetor(vetorOrdenado);

    return 0;
}