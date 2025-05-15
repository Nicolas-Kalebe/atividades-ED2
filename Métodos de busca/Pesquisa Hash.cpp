//NOME: Nícolas Kalebe - Matricula: 202302573
//NOME: Abner Gabriel - Matricula: 202302517

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <chrono>
#include <random>
#include <iomanip>

class HashTable {
private:
    int M;
    std::vector<std::list<std::string>> table;

public:
    HashTable(int tamanho) : M(tamanho), table(tamanho) {}

    int funcaoHash(const std::string &chave) {
        int soma = 0;
        for (char c : chave) {
            soma += static_cast<int>(c);
        }
        return (5 * soma) % M;
    }

    void inserir(const std::string &chave) {
        int index = funcaoHash(chave);
        table[index].push_back(chave);
    }

    bool procurar(const std::string &chave) {
        int index = funcaoHash(chave);
        for (const std::string &procurado : table[index]) {
            if(procurado == chave) {
                return true;
            }
        }
        return false;
    }

    int contadorDeColisoes() {
        int colisoes = 0;
        for(const auto &lista : table) {
            if(lista.size() > 1) {
                colisoes += lista.size() - 1;
            }
        }
        return colisoes;
    }
};

std::string generateRandomString(int length) {
    static const std::string chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, chars.size() - 1);

    std::string result;
    for (int i = 0; i < length; ++i) {
        result += chars[dis(gen)];
    }
    return result;
}

int main() {
    std::vector<int> valoresDeM = {31, 79, 151};
    std::vector<int> tamanhoDosInputs = {100, 1000, 10000};

    for (int M : valoresDeM) {
        std::cout << "\nTestando M = " << M << std::endl;

        for (int N : tamanhoDosInputs) {
            std::cout << "\nTestando com " << N << " inputs" << std::endl;

            HashTable hashTable(M);
            std::vector<std::string> chaves;

            for (int i = 0; i < N; ++i) {
                std::string key = generateRandomString(10);
                chaves.push_back(key);
                hashTable.inserir(key);

                // Chave hash de cada string. Tirar comentários se quiser ver.
                // std::cout << "String: " << key << " | Hash: " << hashTable.funcaoHash(key) << "\n";
            }

            int colisoes = hashTable.contadorDeColisoes();
            std::cout << "Número de colisões: " << colisoes << std::endl;

            double total_time = 0;
            for (int i = 0; i < 10; ++i) {
                std::string search_key = chaves[rand() % N];

                auto start = std::chrono::high_resolution_clock::now();
                bool found = hashTable.procurar(search_key);
                auto end = std::chrono::high_resolution_clock::now();

                std::chrono::duration<double, std::milli> duration = end - start;
                total_time += duration.count();
            }

            double avg_time = total_time / 10;
            std::cout << std::fixed << std::setprecision(8);
            std::cout << "Tempo médio de busca: " << avg_time << " milissegundos\n";


            std::cout << std::string(50, '-') << "\n";
        }
    }
    return 0;
}
