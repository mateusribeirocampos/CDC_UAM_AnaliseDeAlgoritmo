#include <iostream>
#include <vector>
using namespace std;

// Função para calcular a sequência de Fibonacci e armazenar os resultados em um vetor.
void fibonacci(vector<int> &vetor, int n)
{
    // Loop para preencher o vetor com os números da sequência de Fibonacci.
    for (int i = 0; i < n; i++)
    {
        // Define os dois primeiros números da sequência de Fibonacci.
        if (i == 0)
        {
            vetor[i] = 0;
        }
        else if (i == 1)
        {
            vetor[i] = 1;
        }
        else
        {
            // Calcula o próximo número da sequência como a soma dos dois números anteriores.
            vetor[i] = vetor[i - 1] + vetor[i - 2];
            // Imprime o número calculado.
            cout << "vetor[" << i << "]: " << vetor[i] << endl;
        }
    }
}

// Função para calcular a razão entre os termos consecutivos da sequência de Fibonacci.
void razaoFibonacci(vector<double> &taxaFibonacci, const vector<int> &fibonacciSequencia)
{
    // Loop para calcular a razão entre os termos consecutivos.
    for (auto i = 2; i <= fibonacciSequencia.size(); i++)
    {
        // Verifica se o denominador é diferente de zero para evitar divisão por zero.
        if (fibonacciSequencia[i - 2] != 0)
        {
            taxaFibonacci[i] = double(fibonacciSequencia[i - 1]) / fibonacciSequencia[i - 2];
        }
        else
        {
            taxaFibonacci[i] = 0;
        }
    }
}

// Função para imprimir um vetor de inteiros.
void imprimirVetor(const vector<int> &vetor)
{
    cout << "[";
    // Loop para imprimir cada elemento do vetor.
    for (auto i = 0; i < vetor.size(); i++)
    {
        cout << vetor[i];
        // Adiciona uma vírgula e um espaço entre os elementos, exceto após o último.
        if (i < vetor.size() - 1)
        {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

// Função para imprimir um vetor de doubles.
void imprimirVetor(const vector<double> &vetor)
{
    cout << "[";
    // Loop para imprimir cada elemento do vetor.
    for (int i = 0; i < vetor.size(); i++)
    {
        cout << vetor[i];
        // Adiciona uma vírgula e um espaço entre os elementos, exceto após o último.
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
    // Solicita ao usuário o tamanho da sequência de Fibonacci.
    cout << "Digite o tamanho da sequencia de Fibonacci: ";
    cin >> n;

    // Inicializa um vetor com n + 1 elementos para armazenar a sequência de Fibonacci.
    vector<int> fibonacciSequencia(n + 1);
    // Inicializa um vetor com n + 1 elementos para armazenar a razão dos termos consecutivos.
    vector<double> taxaFibonacci(n + 1);

    // Calcula a sequência de Fibonacci e armazena os resultados no vetor.
    fibonacci(fibonacciSequencia, n + 1);

    // Calcula a razão entre os termos consecutivos da sequência de Fibonacci.
    razaoFibonacci(taxaFibonacci, fibonacciSequencia);

    // Imprime a sequência de Fibonacci e a razão entre os termos consecutivos.
    cout << "Fibonacci de " << n << " elementos: ";
    imprimirVetor(fibonacciSequencia);
    cout << "Razao entre os elementos consecutivos da sequencia de Fibonacci: ";
    imprimirVetor(taxaFibonacci);

    return 0;
}
