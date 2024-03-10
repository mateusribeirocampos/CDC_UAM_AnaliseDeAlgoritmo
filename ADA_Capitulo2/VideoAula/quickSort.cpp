// Last Update: 2024-03-10 11:20:00
/*___________________________________________________________________________________________________________*/
/* Quick sort é uma opção onde apresenta eficiëncia maior do que os métodos Insertion Sort e bubble sort,    */
/* pois em seu melhor caso o comportamento assintótico é Θ(nlog2n), Θ(n) no caso médio e pior caso Θ(n^2)    */
/*                                                                                                           */
/*                                 Implementação do QuickSort em C++                                         */
/*                                 Autor: Mateus Campos - www.GeeksBr.com e Marcos Castro em C               */
/*                                                                                                           */
/*___________________________________________________________________________________________________________*/

#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

// imprimindo o vetor ordenado
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

// função para trocar dois elementos de posição
void troca(vector<int> &vetor, int i, int j)
{
    int aux = vetor[i];
    vetor[i] = vetor[j];
    vetor[j] = aux;

    // imprime o vetor a cada troca
    imprimirVetor(vetor, vetor.size());
}

int particiona(vector<int> &vetor, int inicio, int fim)
{
    int pivo, pivo_indice, i;

    // O pivô é o último elemento
    pivo = vetor[fim];

    // pivo_indice é o índice do pivô
    pivo_indice = inicio;

    // percorre o vetor da esquerda para a direita
    for (i = inicio; i < fim; i++) 
    {
        // se o elemento atual for menor ou igual ao pivô
        if (vetor[i] <= pivo) 
        {
            // faz a troca dos elementos
            troca(vetor, i, pivo_indice);
            pivo_indice++;
        }
    }

    // troca o pivô com o elemento da posição pivo_indice
    troca(vetor, pivo_indice, fim);

    // retorna o índice do pivô
    return pivo_indice;
}

int particiona_random(vector<int> &vetor, int inicio, int fim)
{
    // gera um número aleatório entre inicio e fim
    int pivo_indice = inicio + rand() % (fim - inicio + 1);

    // faz a troca para colocar o pivô no final do vetor
    troca(vetor, pivo_indice, fim);

    // chama a função particiona
    return particiona(vetor, inicio, fim);
}

void quickSort(vector<int> &vetor, int inicio, int fim)
{
    if (inicio < fim)
    {
        // função particiona retorna o índice do pivô
        int pivo_indice = particiona_random(vetor, inicio, fim);

        // chamada recursivas quickSort para as duas metades
        // a esquerda (pivo_indice - 1) e a direita (pivo_indice + 1) do pivô
        quickSort(vetor, inicio, pivo_indice - 1);
        quickSort(vetor, pivo_indice + 1, fim);
    }
}

int main()
{
    vector<int> vetor = {5, 2, 4, 1, 3};
    int n = vetor.size(); // n é o tamanho do vetor, neste caso, 6

    //imprime o vetor desordenado
    imprimirVetor(vetor, n);

    //inicializa o gerador de números aleatórios
    srand(time(NULL));

    //chamada da função quickSort
    quickSort(vetor, 0, n - 1);

    //imprime o vetor ordenado
    imprimirVetor(vetor, n);    

    return 0;
}