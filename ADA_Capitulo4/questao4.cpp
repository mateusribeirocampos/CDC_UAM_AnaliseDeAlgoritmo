/*Algoritmo Ordenação Linear Simplificada

Entrada: Um vetor A de n inteiros cujos valores são 1 ou 2.

Saída: Vetor A com os valores ordenados de forma não-decrescente

1. Defina k ← 0

2. para i ← 1 até n faça

3.        se A[ i ] = 1, então k ← k + 1

4. para i ← 1 até k faça

5.        A[ i ] ← 1

6. para i ← k + 1 até n faça

7.         A[ i ] ← 2

8. retorna A*/

#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

vector<int> ordenacaoSimples(vector<int> vetor)
{
    int k = 0;
    for (int i = 0; i < vetor.size(); i++)
    {
        if (vetor[i] == 1)
        {
            k++;
        }
    }
    for (int i = 0; i < k; i++)
    {
        vetor[i] = 1;
    }
    for (int i = k + 1; i < vetor.size(); i++)
    {
        vetor[i] = 2;
    }
    return vetor;
}

void imprimirVetor(vector<int> vetor)
{
    cout << "[";
    for (int i = 0; i < vetor.size(); i++)
    {
        cout << vetor[i];
        if (i < vetor.size() - 1)
        {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

int main()
{
    vector<int> vetor = {1, 2, 1, 1, 2, 1, 1};

    auto inicioExecucao = chrono::high_resolution_clock::now();

    vetor = ordenacaoSimples(vetor);
    
    imprimirVetor(vetor);

    auto fimExecucao = chrono::high_resolution_clock::now();
    cout << "Tempo de execucao: " << chrono::duration_cast<chrono::nanoseconds>(fimExecucao - inicioExecucao).count() << " ns" << endl;

    return 0;
}