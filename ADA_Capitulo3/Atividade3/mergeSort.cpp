#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

// Função para imprimir o vetor
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

void imprimirSubVetoresEsquerda(vector<int> &vetor, int inicio, int meio)
{
    cout << "Subvetor esquerda: [";
    for (int i = inicio; i <= meio; i++)
    {
        cout << vetor[i];
        if (i < meio)
        {
            cout << ", ";
        }
    }
    cout << "]" << endl << endl;
}

void imprimirSubVetorDireita(vector<int> &vetor, int meio, int fim)
{
    cout << "Subvetor direita: [";
    for (int i = meio + 1; i <= fim; i++)
    {
        cout << vetor[i];
        if (i < fim)
        {
            cout << ", ";
        }
    }
    cout << "]" << endl << endl;
}

// Função para mesclar dois subvetores ordenados em um único subvetor ordenado
void merge(vector<int> &vetor, int inicio, int meio, int fim)
{
    // Calcula o tamanho dos subvetores temporários
    int tamanhoEsquerda = meio - inicio + 1; // Tamanho do subvetor temporário para os elementos da metade esquerda
    int tamanhoDireita = fim - meio; // Tamanho do subvetor temporário para os elementos da metade direita

    cout << "Tamanho esquerda: " << tamanhoEsquerda << " Tamanho direita: " << tamanhoDireita << endl;

    // Cria vetores temporários para armazenar os elementos das metades esquerda e direita
    vector<int> subvetorEsquerda(tamanhoEsquerda);
    vector<int> subvetorDireita(tamanhoDireita);

    imprimirSubVetorDireita(vetor, inicio, meio);
    imprimirSubVetoresEsquerda(vetor, meio, fim);

    // Copia os elementos das metades esquerda e direita para os vetores temporários
    for (int i = 0; i < tamanhoEsquerda; i++)
    {
        subvetorEsquerda[i] = vetor[inicio + i];
        cout << endl << "Subvetor esquerda: " << subvetorEsquerda[i] << endl;
    }
    for (int j = 0; j < tamanhoDireita; j++)
    {
        subvetorDireita[j] = vetor[meio + 1 + j];
        cout << endl << "Subvetor direita: " << subvetorDireita[j] << endl;
    }

    // Índices iniciais dos subvetores temporários e do vetor mesclado
    int indiceEsquerda = 0; // Índice inicial do subvetor temporário para a metade esquerda
    int indiceDireita = 0; // Índice inicial do subvetor temporário para a metade direita
    int indiceMesclado = inicio; // Índice inicial do vetor mesclado

    // Mescla os subvetores temporários de volta para o vetor original
    while (indiceEsquerda < tamanhoEsquerda && indiceDireita < tamanhoDireita)
    {
        if (subvetorEsquerda[indiceEsquerda] <= subvetorDireita[indiceDireita])
        {
            // Se o elemento da metade esquerda for menor ou igual ao elemento da metade direita,
            // copia o elemento da metade esquerda para o vetor original e avança para o próximo elemento da metade esquerda
            vetor[indiceMesclado] = subvetorEsquerda[indiceEsquerda];
            indiceEsquerda++;
        }
        else
        {
            // Se o elemento da metade direita for menor que o elemento da metade esquerda,
            // copia o elemento da metade direita para o vetor original e avança para o próximo elemento da metade direita
            vetor[indiceMesclado] = subvetorDireita[indiceDireita];
            indiceDireita++;
        }
        indiceMesclado++; // Avança para o próximo índice do vetor mesclado
    }

    // Copia os elementos restantes do subvetor esquerdo, se houver
    while (indiceEsquerda < tamanhoEsquerda)
    {
        vetor[indiceMesclado] = subvetorEsquerda[indiceEsquerda];
        indiceEsquerda++;
        indiceMesclado++;
    }

    // Copia os elementos restantes do subvetor direito, se houver
    while (indiceDireita < tamanhoDireita)
    {
        vetor[indiceMesclado] = subvetorDireita[indiceDireita];
        indiceDireita++;
        indiceMesclado++;
    }
}

// Função principal do Merge Sort
void mergeSort(vector<int> &vetor, int inicio, int fim)
{
    if (inicio < fim)
    {
        // Calcula o ponto médio do vetor
        int meio = inicio + (fim - inicio) / 2;

        cout << "Meio do vetor: " << meio << endl << endl;

        // Chama a função mergeSort recursivamente para ordenar as duas metades do vetor
        cout << "Chamada recursiva para a metade esquerda do vetor" << endl;
        cout << "Inicio: " << inicio << " Meio: " << meio << endl;
        mergeSort(vetor, inicio, meio);

        cout << "Chamada recursiva para a metade direita do vetor" << endl;
        cout << "Meio + 1: " << meio + 1 << " Fim: " << fim << endl;
        mergeSort(vetor, meio + 1, fim);

        // Mescla as metades ordenadas para obter o vetor completamente ordenado
        cout << "Mesclando as metades ordenadas" << endl;
        cout << "Inicio: " << inicio << " Meio: " << meio << " Fim: " << fim << endl;
        merge(vetor, inicio, meio, fim);
    }
}

int main() {
    vector<int> vetor = {3, 1, 5, 2, 4};
    int n = vetor.size();

    cout << "Vetor desordenado: ";
    imprimirVetor(vetor, n);

    auto start = chrono::high_resolution_clock::now();

    // Chama a função mergeSort para ordenar o vetor
    mergeSort(vetor, 0, n - 1);

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> diff = end - start;

    cout << "Vetor ordenado: ";
    imprimirVetor(vetor, n);

    cout << "Tempo de execucao: " << diff.count() << " s" << endl;
    
    return 0;
}