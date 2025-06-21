#include <iostream>
#include <chrono>
#include <iomanip> // Para setprecision
using namespace std;
using namespace std::chrono;

long long contador = 0; // Conta quantas vezes a função é chamada

long double fibonacci(int n) {
    contador++; // Incrementa a cada chamada recursiva
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
    duration<double> duracao = duration_cast<duration<double>>(fim - inicio);

    cout << fixed << setprecision(8);
    cout << "Fibonacci(" << n << ") = " << resultado << endl;
    cout << "Chamadas recursivas realizadas: " << contador << endl;
    cout << "Tempo de execução: " << duracao.count() << " segundos" << endl;

    return 0;
}
