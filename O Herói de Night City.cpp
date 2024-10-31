#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Definindo a struct para representar um implante cibern�tico
struct Implante {
    string nome;
    string fabricante;
    int tier;
    float taxa_psicose;
};

int main() {
    int N;
    
    cin >> N;

    // Vetor din�mico para armazenar os implantes
    vector<Implante> implantes(N);

    // Leitura dos dados dos implantes e inser��o no vetor
    for (int i = 0; i < N; ++i) {
        cin >> implantes[i].nome;
       
        cin >> implantes[i].fabricante;
        
        cin >> implantes[i].tier;
        
        cin >> implantes[i].taxa_psicose;
    }

    // Verifica��o da soma das taxas de psicose
    float soma_psicose = 0.0;
    for (int i = 0; i < N; ++i) {
        soma_psicose += implantes[i].taxa_psicose;
    }

    // Verificando se a soma ultrapassa o limite de psicose
    if (soma_psicose > 60.0) {
        cout << "Alerta! Uma recompensa de 50.000 edinhos foi colocada pela sua cabe�a. Voc� se tornou um Ciberpsicopata" << endl;
    } else {
        cout << "Vamos tchum! Temos uma cidade pra conquistar!" << endl;
    }

    return 0;
}
