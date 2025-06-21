#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Algoritmo 1: Inicia com 1 e 1 - Iterativa
int fibonacci1(int n) {
    if (n == 1) {
        return 1;
    } else if (n == 2) {
        return 1;
    } else {
        int f1 = 1, f2 = 1, f;
        for (int i = 3; i <= n; i++) {
            f = f1 + f2;
            f1 = f2;
            f2 = f;
        }
        return f;
    }
}

// Algoritmo 2: Inicia com 0 e 1 - Generativa_Iterativa (chatGPT)
int fibonacci2(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;

    int anterior = 0, atual = 1, proximo;

    for (int i = 2; i <= n; i++) {
        proximo = anterior + atual;
        anterior = atual;
        atual = proximo;
    }

    return atual;
}

// Utilizar valores altos de n para medir o tempo de execução
// Exemplo: 10000, 100000, 1000000
int main() {
    int n;
    cout << "Digite o valor de n: ";
    cin >> n;

    // Medir tempo do Algoritmo 1 (inicia com 1 e 1)
    auto inicio1 = high_resolution_clock::now();
    int resultado1 = fibonacci1(n);
    auto fim1 = high_resolution_clock::now();
    auto duracao1 = duration_cast<microseconds>(fim1 - inicio1);

    // Medir tempo do Algoritmo 2 (inicia com 0 e 1)
    auto inicio2 = high_resolution_clock::now();
    int resultado2 = fibonacci2(n);
    auto fim2 = high_resolution_clock::now();
    auto duracao2 = duration_cast<microseconds>(fim2 - inicio2);

    cout << "Resultado Fibonacci1: " << resultado1 << " | Tempo: " << duracao1.count() << " microsegundos" << endl;
    cout << "Resultado Fibonacci2: " << resultado2 << " | Tempo: " << duracao2.count() << " microsegundos" << endl;

    return 0;
}