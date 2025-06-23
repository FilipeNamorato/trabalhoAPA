#include <iostream>
#include <chrono>
#include <iomanip>
using namespace std;
using namespace std::chrono;

long long contador = 0; // Conta quantas vezes a função é chamada

long double fibonacci(int n) {
    contador++;
    if (n == 1) return 1;
    else if (n == 2) return 1;
    else return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;
    cout << "Digite a posição n da sequência de Fibonacci: ";
    cin >> n;

    if (n <= 0) {
        cout << "n deve ser um inteiro positivo." << endl;
        return 1;
    }

    auto inicio = high_resolution_clock::now();

    long double resultado = fibonacci(n);

    auto fim = high_resolution_clock::now();
    auto duracao = duration_cast<microseconds>(fim - inicio); // Tempo em microssegundos

    cout << fixed << setprecision(0);
    cout << "Fibonacci(" << n << ") = " << resultado << endl;
    cout << "Chamadas recursivas realizadas: " << contador << endl;
    cout << "Tempo de execução: " << duracao.count() << " microssegundos" << endl;

    return 0;
}
