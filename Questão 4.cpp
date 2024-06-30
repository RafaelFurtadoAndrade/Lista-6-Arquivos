#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Função para verificar se um aluno está cadastrado
bool alunoCadastrado(const string& nome) {
    ifstream file(nome + ".txt");
    return file.good();
}

// Função para cadastrar um aluno
void cadastrarAluno() {
    string nome, matricula;
    cout << "Informe o nome do aluno: ";
    cin >> nome;
    if (alunoCadastrado(nome)) {
        cout << "Aluno já cadastrado." << endl;
        return;
    }
    cout << "Informe a matrícula do aluno: ";
    cin >> matricula;
    ofstream file(nome + ".txt");
    file << matricula << endl;
    file.close();
    cout << "Aluno cadastrado com sucesso." << endl;
}

// Função para adicionar uma nota a um aluno
void adicionarNota() {
    string nome;
    double nota;
    cout << "Informe o nome do aluno: ";
    cin >> nome;
    if (!alunoCadastrado(nome)) {
        cout << "Aluno não cadastrado." << endl;
        return;
    }
    cout << "Informe a nota: ";
    cin >> nota;
    ofstream file(nome + ".txt", ios::app);
    file << nota << endl;
    file.close();
    cout << "Nota adicionada com sucesso." << endl;
}

// Função para calcular a média de um aluno
void calcularMedia() {
    string nome;
    cout << "Informe o nome do aluno: ";
    cin >> nome;
    if (!alunoCadastrado(nome)) {
        cout << "Aluno não cadastrado." << endl;
        return;
    }
    ifstream file(nome + ".txt");
    string linha;
    getline(file, linha);  // Ignora a primeira linha (matrícula)
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
    cout << "Média do aluno " << nome << ": " << media << endl;
}

int main() {
    int opcao;
    do {
        cout << "Menu:" << endl;
        cout << "1. Cadastrar aluno" << endl;
        cout << "2. Adicionar nota de um aluno" << endl;
        cout << "3. Calcular média de um aluno" << endl;
        cout << "4. Fechar o programa" << endl;
        cout << "Escolha uma opção: ";
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
                cout << "Opção inválida. Tente novamente." << endl;
        }
    } while (opcao != 4);

    return 0;
}
