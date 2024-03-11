#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;

void imprimirVetor(const vector<int>& vetor)
{
    cout << "[";
    for (auto it = vetor.begin(); it != vetor.end(); ++it)
    {
        cout << *it;
        if (next(it) != vetor.end())
        {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

int partition(vector<int>& vetor, int inicio, int fim)
{
    int pivo = vetor[fim];
    int pivo_indice = inicio - 1;

    for (int i = inicio; i < fim; i++)
    {
        if (vetor[i] <= pivo)
        {
            pivo_indice++;
            swap(vetor[pivo_indice], vetor[i]);
        }
    }
    swap(vetor[pivo_indice + 1], vetor[fim]);

    return pivo_indice + 1;
}

void quickSort(vector<int>& vetor, int inicio, int fim)
{
    if (inicio < fim)
    {
        int pivo = partition(vetor, inicio, fim);
        quickSort(vetor, inicio, pivo - 1);
        quickSort(vetor, pivo + 1, fim);
    }
}

int main()
{
    vector<int> vetor = {3, 1, 5, 2, 4};

    cout << "Vetor desordenado: ";
    imprimirVetor(vetor);
    cout << endl;

    auto start = chrono::high_resolution_clock::now();

    quickSort(vetor, 0, vetor.size() - 1);

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> diff = end - start;

    cout << "Vetor ordenado: ";
    imprimirVetor(vetor);
    cout << "Tempo de execucao: " << diff.count() << " segundos" << endl;

    return 0;
}
