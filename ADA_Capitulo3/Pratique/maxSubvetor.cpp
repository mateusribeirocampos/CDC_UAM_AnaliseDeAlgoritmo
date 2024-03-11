/*_______________________________________________________________________________________________*/
/*                                                                                               */
/*Caro(a) estudante,                                                                             */
/*Suponha que você tenha recebido a oportunidade de investir nas ações de uma empresa na bolsa   */
/*de valores. Como seu objetivo é maximizar o seu lucro, uma estratégia é analisar a variação    */
/*dos preços das ações e identificar o período em que elas apresentam maior valorização agregada.*/
/*A Figura 1 ilustra a variação dos preços das ações durante 16 dias. No intervalo após o dia 7, */
/*até o fim do dia 11, o valor das ações apresentou a maior soma: 43.                            */
/*                                                                                               */
/*vetor = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7}                    */
/*                                                                                               */
/*Figura 1 – Máximo Subvetor. Fonte: CORMEN et al., 2009, p. 70. (Adaptado).                     */
/*                                                                                               */
/*Esse cenário pode ser modelado como um problema de se encontrar o subvetor de maior valor      */
/*em um vetor. Um algoritmo de divisão e conquista pode ser implementado para resolver           */
/*esse problema, conforme apresentado no pseudocódigo abaixo. O algoritmo recebe um vetor        */
/*A delimitado pelos índicess min e max . O algoritmo faz uso de um procedimento auxiliar,       */
/*de complexidade Θ(n) , chamado subvetor-geral, responsável por identificar a maior soma        */
/*dentro de um subvetor informado.                                                               */
/*                                                                                               */
/* Máximo-subvetor(A, min, max)                                                                  */
/* 01. se max = min então ;                                                                      */
/* 02. retorna (min, max, A[min]);                                                               */
/* 03. senão ;                                                                                   */
/* 04. meio = (min + max) / 2;                                                                   */
/* 05. (esq-min, esq-max, soma-esq) =  Máximo-Subvetor(A, min, meio);                            */
/* 06. (dir-min, dir-max, soma-dir) =  Máximo-Subvetor(A, meio + 1, max);                        */
/* 07. (geral-min, geral-max, soma-geral) = Subvetor-Geral(A, min, meio, max);                   */
/* 08. se soma-esq ≥ soma-dir e soma-esq ≥ soma-geral;                                           */
/* 09. retorna (esq-min, esq-max, soma-esq);                                                     */
/* 10. se soma-dir ≥ soma-esq e soma-dir ≥ soma-geral;                                           */
/* 11. retorna (dir-min, dir-max, soma-dir);                                                     */
/* 12. senão retorna (geral-min, geral-max, soma-geral).                                         */
/*                                                                                               */
/*_______________________________________________________________________________________________*/
/*VAMOS PRATICAR?                                                                                */
/*Construa a função de recorrência que modela o algoritmo de divisão e conquista presentado      */
/*e aplique o teorema mestre para descrever acomplexidade geral desse algoritmo.                 */
/*Organize sua resposta em um arquivo de texto (DOC ou PDF)                                      */
/*_______________________________________________________________________________________________*/

#include <iostream>
#include <vector>
#include <chrono>
#include <climits>
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

void imprimirSubvetor(vector<int> &vetor, int &inicio, int &fim)
{
    cout << "[";
    for (int i = inicio; i <= fim; i++)
    {
        cout << vetor[i];
        if (i < fim)
        {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

int somaMaximoSubvetor(vector<int> &vetor, int n, int &inicio, int &fim) {
    int maximoAteAgora = INT_MIN, maximoTerminandoAqui = 0;
    int s = 0;

    for (int i = 0; i < n; i++) {
        maximoTerminandoAqui += vetor[i];
        if (maximoAteAgora < maximoTerminandoAqui) {
            maximoAteAgora = maximoTerminandoAqui;
            inicio = s;
            fim = i;
        }
        if (maximoTerminandoAqui < 0) {
            maximoTerminandoAqui = 0;
            s = i + 1;
        }
    }
    return (fim - inicio + 1);
}

int somaSubvetor(vector<int> &vetor, int inicio, int fim) 
{
    int soma = 0;
    for (int i = inicio; i <= fim; i++) {
        soma += vetor[i];
    }
    return soma;
}

int main()
{
    vector<int> vetor = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
    int n = vetor.size();
    int inicio, fim;

    auto inicioExecucao = chrono::high_resolution_clock::now();

    imprimirVetor(vetor, n);

    int tamanhoMaiorSubvetor = somaMaximoSubvetor(vetor, n, inicio, fim);
    cout << "Tamanho do subvetor com a maior soma: " << tamanhoMaiorSubvetor << endl;
    int somaMaiorSubvetor = somaSubvetor(vetor, inicio, fim);
    cout << "Soma do subvetor com a maior soma: " << somaMaiorSubvetor << endl;
    cout << "Subvetor com a maior soma: ";
    imprimirSubvetor(vetor, inicio, fim);

    auto fimExecucao = chrono::high_resolution_clock::now();

    cout << "Tempo de execucao: " << chrono::duration_cast<chrono::nanoseconds>(fimExecucao - inicioExecucao).count() << " ns" << endl;

    return 0;
}