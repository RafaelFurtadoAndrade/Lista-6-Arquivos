#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Fun��o para verificar se um aluno est� cadastrado
bool alunoCadastrado(const string& nome) {
    ifstream file(nome + ".txt");
    return file.good();
}

// Fun��o para cadastrar um aluno
void cadastrarAluno() {
    string nome, matricula;
    cout << "Informe o nome do aluno: ";
    cin >> nome;
    if (alunoCadastrado(nome)) {
        cout << "Aluno j� cadastrado." << endl;
        return;
    }
    cout << "Informe a matr�cula do aluno: ";
    cin >> matricula;
    ofstream file(nome + ".txt");
    file << matricula << endl;
    file.close();
    cout << "Aluno cadastrado com sucesso." << endl;
}

// Fun��o para adicionar uma nota a um aluno
void adicionarNota() {
    string nome;
    double nota;
    cout << "Informe o nome do aluno: ";
    cin >> nome;
    if (!alunoCadastrado(nome)) {
        cout << "Aluno n�o cadastrado." << endl;
        return;
    }
    cout << "Informe a nota: ";
    cin >> nota;
    ofstream file(nome + ".txt", ios::app);
    file << nota << endl;
    file.close();
    cout << "Nota adicionada com sucesso." << endl;
}

// Fun��o para calcular a m�dia de um aluno
void calcularMedia() {
    string nome;
    cout << "Informe o nome do aluno: ";
    cin >> nome;
    if (!alunoCadastrado(nome)) {
        cout << "Aluno n�o cadastrado." << endl;
        return;
    }
    ifstream file(nome + ".txt");
    string linha;
    getline(file, linha);  // Ignora a primeira linha (matr�cula)
    vector<double> notas;
    double nota;
    while (file >> nota) {
        notas.push_back(nota);
    }
    file.close();
    if (notas.empty()) {
        cout << "Nenhuma nota encontrada para o aluno." << endl;
        return;
    }
    double soma = 0;
    for (double n : notas) {
        soma += n;
    }
    double media = soma / notas.size();
    cout << "M�dia do aluno " << nome << ": " << media << endl;
}

int main() {
    int opcao;
    do {
        cout << "Menu:" << endl;
        cout << "1. Cadastrar aluno" << endl;
        cout << "2. Adicionar nota de um aluno" << endl;
        cout << "3. Calcular m�dia de um aluno" << endl;
        cout << "4. Fechar o programa" << endl;
        cout << "Escolha uma op��o: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                cadastrarAluno();
                break;
            case 2:
                adicionarNota();
                break;
            case 3:
                calcularMedia();
                break;
            case 4:
                cout << "Fechando o programa..." << endl;
                break;
            default:
                cout << "Op��o inv�lida. Tente novamente." << endl;
        }
    } while (opcao != 4);

    return 0;
}
