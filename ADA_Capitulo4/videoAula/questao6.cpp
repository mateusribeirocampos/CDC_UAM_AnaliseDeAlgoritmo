/*
Somador

Entrada: Dois inteiros i e j a serem somados

Saída: Valor de i + j

1. se i = 0 então

2.        retorna j

3. senão

4.        retorna Somador(- -i, ++j)*/
#include <iostream>
using namespace std;

int somador(int i, int j)
{
    if (i == 0)
    {
        return j;
    }
    else
    {
        cout << "i: " << i << " j: " << j << endl;
        return somador(--i, ++j);
    }
}

int main()
{
    cout << somador(3, 7) << endl;
    return 0;
}