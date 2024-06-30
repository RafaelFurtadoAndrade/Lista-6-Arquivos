
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main() {
    ifstream inputFile("vetores.txt");
    ofstream outputFile("soma.txt");

    if (!inputFile) {
        cerr << "Erro ao abrir o arquivo de entrada!" << endl;
        return 1;
    }

    string line;
    vector<int> sumVector;
    
    while (getline(inputFile, line)) {
        istringstream iss(line);
        vector<int> currentVector;
        int number;
        while (iss >> number) {
            currentVector.push_back(number);
        }

        if (sumVector.size() < currentVector.size()) {
            sumVector.resize(currentVector.size(), 0);
        }

        for (size_t i = 0; i < currentVector.size(); ++i) {
            sumVector[i] += currentVector[i];
        }
    }

    for (size_t i = 0; i < sumVector.size(); ++i) {
        outputFile << sumVector[i] << " ";
    }

    inputFile.close();
    outputFile.close();

    cout << "Soma dos vetores salva em soma.txt" << endl;

    return 0;
}
