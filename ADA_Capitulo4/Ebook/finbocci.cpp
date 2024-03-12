#include <iostream>
#include <vector>
using namespace std;

void divideFibonacci(vector<double> &vetor, int a)
{
    // Começa o loop a partir de 2 para evitar a divisão por zero
    for (int i = 2; i < a; i++)
    {
        vetor[i] = vetor[i - 1] + vetor[i - 2];
        if (vetor[i - 2] != 0)
        {
            vetor[i] = double(vetor[i - 1]) / vetor[i - 2];
        }
        else
        {
            vetor[i] = 0;
        }
        cout << "Divide vetor[" << i << "] = " << vetor[i] << endl;
    }
}

void fibonacci(vector<int> &vetor, int n)
{
    for (int i = 2; i < n; i++)
    {
        vetor[i] = vetor[i - 1] + vetor[i - 2];
        cout << "vetor[" << i << "] = " << vetor[i] << endl;
    }
}

void imprimirVetor(const vector<int> &vetor)
{
    cout << "[";
    for (size_t i = 0; i < vetor.size(); i++)
    {
        cout << vetor[i];
        if (i < vetor.size() - 1)
        {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

void imprimirVetor(const vector<double> &vetor)
{
    cout << "[";
    for (size_t i = 0; i < vetor.size(); i++)
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
    int n;
    cout << "Digite o tamanho da sequencia de Fibonacci: ";
    cin >> n;

    vector<int> fibonacciSequencia(n); // Inicializa um vetor com n elementos

    // Preenche os dois primeiros elementos da sequência de Fibonacci
    fibonacciSequencia[0] = 0;
    fibonacciSequencia[1] = 1;

    // Calcula a sequência de Fibonacci para os elementos restantes
    fibonacci(fibonacciSequencia, n);

    // Imprime a sequência de Fibonacci
    cout << "Fibonacci de " << n << " elementos: ";
    imprimirVetor(fibonacciSequencia);

    // Calcula a razão entre os termos consecutivos da sequência de Fibonacci
    vector<double> taxaFibonacci(n); // Inicializa um vetor com n elementos para armazenar a razão dos termos consecutivos
    taxaFibonacci[0] = 1;            // Razão inicial
    taxaFibonacci[1] = 1;            // Razão inicial
    divideFibonacci(taxaFibonacci, n);

    // Imprime a razão entre os termos consecutivos da sequência de Fibonacci
    cout << "Razao entre os elementos consecutivos da sequencia de Fibonacci: ";
    imprimirVetor(taxaFibonacci);

    return 0;
}
