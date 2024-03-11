#include <iostream>
#include <vector>
using namespace std;

// Função que verifica se existe um subconjunto cuja soma é igual a alvo
bool subsetSum(const vector<int> &vetor, int alvo) {
    // Vetor de booleanos que indica se é possível obter a soma i
    vector<bool> dp(alvo + 1, false);
    
    // A soma 0 é sempre possível
    dp[0] = true;

    // Para cada número no vetor
    for(int numero : vetor) {
        // Para cada soma possível
        for(int i = alvo; i >= numero; i--) {
            // Se é possível obter a soma i - numero, então é possível obter a soma i
            if(dp[i - numero] == true) {
                dp[i] = true;
            }
        }
    }
    // Retorna se é possível obter a soma alvo
    return dp[alvo];
}
int main() {

    vector<int> vetor = {3, 34, 4, 12, 5, 2};
    int alvo = 61;

    cout << "Existe um subconjunto cuja soma eh: " << alvo << " ? ";
    if(subsetSum(vetor, alvo)) {
        cout << "Sim" << endl;
    } else {
        cout << "Nao" << endl;
    }

    return 0;
}