void imprimirVetor(vector<int> vetor, int n)
{
    cout << "[";
    for (int i = 0; i < n; i++)
    {
        cout << vetor[i] << ", ";
    }
    cout << "]" << endl;
}