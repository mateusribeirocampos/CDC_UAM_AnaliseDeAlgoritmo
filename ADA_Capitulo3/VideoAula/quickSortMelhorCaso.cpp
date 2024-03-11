#include <iostream>
#include <vector>
#include <time.h>
#include <chrono>

using namespace std;

void imprimirVetor(vector<int> vetor, int n)
{
    cout << "[";
    for (int i = 0; i < n; i++)
    {
        cout << vetor[i];
        if (i < n - 1)
        {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

int partition(vector<int> &vetor, int inicio, int fim)
{
    int pivo, pivo_indice, i;

    // O pivô é o último elemento
    pivo = vetor[fim];
    cout << "O pivo eh o ultimo elemento" << endl;
    cout << "pivo: " << pivo << " = " << "Vetor[fim]: "<< vetor[fim] << endl;

    // pivo_indice é o índice do pivô
    pivo_indice = inicio - 1;
    cout << "pivo_indice: " << pivo_indice << " = " << "inicio - 1: "<< inicio - 1 << endl;

    // percorre o vetor da esquerda para a direita
    for (i = inicio; i < fim; i++)
    {
        // se o elemento atual for menor ou igual ao pivô
        if (vetor[i] <= pivo)
        {
            cout << "Se vetor[" << i << "]: " << vetor[i] << " <= pivo: " << pivo << endl;
            // faz a troca dos elementos o que seria o swap
            pivo_indice++;
            cout << "pivo_indice: " << pivo_indice << ", indice (i): " << i << endl;
            int aux = vetor[i];
            cout << "aux: " << aux << ", indice (i): " << i << endl;
            vetor[i] = vetor[pivo_indice];
            cout << "vetor[i]: " << vetor[i] << ", indice (i): " << i << endl;
            vetor[pivo_indice] = aux;
            cout << "vetor[pivo_indice]: " << vetor[pivo_indice] << ", indice (i): " << i << endl;

            // imprime o vetor a cada troca
            // primeira troca
            imprimirVetor(vetor, vetor.size());
        }
    }
    // troca o pivô com o elemento da posição pivo_indice
    // atribui o valor do pivo para a posição pivo_indice + 1
    int aux = vetor[pivo_indice + 1];
    cout << "aux: " << aux << ", indice (pivo_indice + 1): " << pivo_indice + 1 << endl;
    // atribui o valor do vetor[fim] para a posição pivo_indice + 1
    vetor[pivo_indice + 1] = vetor[fim];
    cout << "vetor[pivo_indice + 1]: " << vetor[pivo_indice + 1] << ", indice (pivo_indice + 1): " << pivo_indice + 1 << endl;
    // atribui o valor do vetor[pivo_indice + 1] para a posição fim
    vetor[fim] = aux;
    cout << "vetor[fim]: " << vetor[fim] << ", indice (fim): " << fim << endl << endl;

    // imprime o vetor a cada troca
    imprimirVetor(vetor, vetor.size());

    return pivo_indice + 1;
    cout << endl << endl;
}

void quickSort(vector<int> &vetor, int inicio, int fim)
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
    vector<int> vetor = {5, 3, 4, 1, 2};

    // imprime vetor desordenado
    imprimirVetor(vetor, vetor.size());
    cout << endl;

    // Obtenha o tempo de início antes de chamar a função selectionSort
    auto start = std::chrono::high_resolution_clock::now();

    // chama a função quickSort
    quickSort(vetor, 0, vetor.size() - 1);

    // Obtenha o tempo de término após a função selectionSort retornar
    auto end = chrono::high_resolution_clock::now();

    // Calcule a diferença entre o tempo de término e o tempo de início, isso dará a duração da execução da função selectionSort
    chrono::duration<double> diff = end-start;

    // imprime vetor ordenado
    imprimirVetor(vetor, vetor.size());

    // Imprima a duração da execução da função selectionSort
    cout << "Tempo de execucao: " << diff.count() << " s\n";

    return 0;
}