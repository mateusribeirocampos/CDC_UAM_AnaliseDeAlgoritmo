#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

void imprimirVetor(vector<int> &vetor, int n)
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

long long merge(vector<int> &vetor, int inicio, int meio, int fim)
{
    int meioEsquerda = meio - inicio + 1;
    int direitaMeio = fim - meio;

    // Vetores temporários
    vector<int> esquerda(meioEsquerda), direita(direitaMeio);

    // Copia os dados para os vetores temporários esquerda[] e direita[]
    for (int i = 0; i < meioEsquerda; i++)
    {
        esquerda[i] = vetor[inicio + i];
    }
    for (int j = 0; j < direitaMeio; j++)
    {
        direita[j] = vetor[meio + 1 + j];
    }

    // Mescla os vetores temporários de volta para o vetor
    int i = 0; // Índice inicial do primeiro subvetor
    int j = 0; // Índice inicial do segundo subvetor
    int k = inicio; // Índice inicial do subvetor mesclado
    long long inversoes = 0; // Contador de inversões

    while (i < meioEsquerda && j < direitaMeio)
    {
        if (esquerda[i] <= direita[j])
        {
            vetor[k] = esquerda[i];
            i++;
        }
        else
        {
            vetor[k] = direita[j];
            j++;
            // Se um elemento de esquerda for maior que um elemento de direita,
            // todos os elementos restantes de esquerda são maiores que o elemento de direita
            // contador de inversões é incrementado pelo número de elementos restantes em esquerda
            inversoes += meioEsquerda - i;
        }
        k++;
    }

    // Copia os elementos restantes de esquerda[], se houver
    while (i < meioEsquerda)
    {
        vetor[k] = esquerda[i];
        i++;
        k++;
    }

    // Copia os elementos restantes de direita[], se houver
    while (j < direitaMeio)
    {
        vetor[k] = direita[j];
        j++;
        k++;
    }

    // retorna o número de inversões
    return inversoes;
}

long long mergeSort(vector<int> &vetor, int inicio, int fim)
{
    long long inversoes = 0;

    if (inicio < fim)
    {
        // Encontra o ponto médio
        int meio = inicio + (fim - inicio) / 2;

        // Ordena a primeira e a segunda metade e conta as inversões
        inversoes += mergeSort(vetor, inicio, meio);
        inversoes += mergeSort(vetor, meio + 1, fim);

        // Mescla as metades ordenadas e conta as inversões incrementando o contador
        inversoes += merge(vetor, inicio, meio, fim);
    }

    return inversoes;
}

int main() {
    vector<int> vetor = {3, 1, 5, 2, 4};
    int n = vetor.size();

    cout << "Vetor desordenado: ";
    imprimirVetor(vetor, n);

    auto start = chrono::high_resolution_clock::now();

    // Merge Sort com contador de inversões
    long long inversoes = mergeSort(vetor, 0, n - 1);

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> diff = end - start;

    cout << "Vetor ordenado: ";
    imprimirVetor(vetor, n);

    cout << "Numero de inversoes: " << inversoes << endl;
    cout << "Tempo de execucao: " << diff.count() << " s" << endl;
    
    return 0;
}
