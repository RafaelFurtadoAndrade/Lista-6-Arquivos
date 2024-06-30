#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream inputFile("mochileiro.txt");

    if (!inputFile) {
        cerr << "Erro ao abrir o arquivo de entrada!" << endl;
        return 1;
    }

    char targetChar;
    cout << "Informe o caractere a ser contado: ";
    cin >> targetChar;

    string line;
    int lineNumber = 1;

    while (getline(inputFile, line)) {
        int count = 0;
        for (size_t i = 0; i < line.size(); ++i) {
            if (line[i] == targetChar) {
                ++count;
            }
        }
        cout << "Linha " << lineNumber << ": " << count << " ocorrências do caractere '" << targetChar << "'" << endl;
        ++lineNumber;
    }

    inputFile.close();

    return 0;
}
