#include <iostream>
#include <fstream>
#include <string>
#include <limits>

using namespace std;

int main() {
    ifstream alturaFile("altura.txt");
    ifstream pesoFile("peso.txt");

    if (!alturaFile || !pesoFile) {
        cerr << "Erro ao abrir os arquivos de entrada!" << endl;
        return 1;
    }

    string codigo, maxAlturaCodigo, maxPesoCodigo;
    double altura, peso;
    double maxAltura = numeric_limits<double>::min();
    double maxPeso = numeric_limits<double>::min();

    // Processa o arquivo de altura
    while (alturaFile >> codigo >> altura) {
        if (altura > maxAltura) {
            maxAltura = altura;
            maxAlturaCodigo = codigo;
        }
    }

    // Processa o arquivo de peso
    while (pesoFile >> codigo >> peso) {
        if (peso > maxPeso) {
            maxPeso = peso;
            maxPesoCodigo = codigo;
        }
    }

    alturaFile.close();
    pesoFile.close();

    cout << "Pessoa com maior altura: " << maxAlturaCodigo << " com " << maxAltura << " metros" << endl;
    cout << "Pessoa com maior peso: " << maxPesoCodigo << " com " << maxPeso << " kg" << endl;

    return 0;
}
