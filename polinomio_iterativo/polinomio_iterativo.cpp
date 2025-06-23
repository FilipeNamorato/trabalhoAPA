#include <iostream>
#include <vector>
#include <cmath>
#include <chrono>

using namespace std;
using namespace chrono;

// Variáveis globais
vector<int> coeficientes_globais;
int grau_global;
int x_global;

// Método 1: Potenciação
int metodoPotencia() {
    int p = coeficientes_globais[0];
    for (int i = 1; i <= grau_global; i++) {
        int potencia = 1;
        for (int j = 1; j <= i; j++) {
            potencia *= x_global;
        }
        p += coeficientes_globais[i] * potencia;
    }
    return p;
}

// Método 2: Produto Acumulado
int metodoProduto() {
    int p = coeficientes_globais[0];
    int y = x_global;
    int z = grau_global - 1;

    for (int i = 1; i <= z; i++) {
        p += coeficientes_globais[i] * y;
        y *= x_global;
    }
    p += coeficientes_globais[grau_global] * y;

    return p;
}

// Método 3: Horner
int metodoHorner() {
    int p = coeficientes_globais[grau_global];
    int z = grau_global - 1;

    for (int i = z; i >= 0; i--) {
        p = coeficientes_globais[i] + x_global * p;
    }
    return p;
}

// Exibir o polinômio atual
void exibirPolinomio() {
    cout << "\nPolinômio atual: ";
    for (int i = grau_global; i >= 0; i--) {
        cout << coeficientes_globais[i];
        if (i > 0) cout << "x^" << i << " + ";
    }
    cout << endl;
}

// Ler polinômio
void ler_polinomio() {
    cout << "Digite o grau do polinomio (n): ";
    cin >> grau_global;
    coeficientes_globais.resize(grau_global + 1);

    cout << "Digite os coeficientes (do termo de grau " << grau_global << " até o termo de grau 0):" << endl;
    for (int i = grau_global; i >= 0; i--) {
        cout << "Coeficiente de x^" << i << ": ";
        cin >> coeficientes_globais[i];
    }

    cout << "Digite o valor de x: ";
    cin >> x_global;

    exibirPolinomio();
}

// Wrappers para chamadas na main
int polinomio_potenciacao() {
    return metodoPotencia();
}

int polinomio_produto() {
    return metodoProduto();
}

int polinomio_horner() {
    return metodoHorner();
}

int main() {

    // Ler dados do polinômio
    ler_polinomio();

    int resultado_horner, resultado_potenciacao, resultado_produto;
    double tempo_horner, tempo_potenciacao, tempo_produto;

    // Teste Horner
    cout << "\n--- METODO HORNER ---" << endl;
    auto inicio = high_resolution_clock::now();
    resultado_horner = polinomio_horner();
    auto fim = high_resolution_clock::now();
    tempo_horner = duration_cast<nanoseconds>(fim - inicio).count() / 1000000.0;
    cout << "Resultado: p(" << x_global << ") = " << resultado_horner << endl;
    cout << "Complexidade: O(n) - n chamadas recursivas, cada uma O(1)" << endl;
    cout << "Tempo: " << tempo_horner << " milissegundos" << endl;

    // Teste Potenciação
    cout << "\n--- METODO POTENCIACAO ---" << endl;
    inicio = high_resolution_clock::now();
    resultado_potenciacao = polinomio_potenciacao();
    fim = high_resolution_clock::now();
    tempo_potenciacao = duration_cast<nanoseconds>(fim - inicio).count() / 1000000.0;
    cout << "Resultado: p(" << x_global << ") = " << resultado_potenciacao << endl;
    cout << "Complexidade: O(n²) - para cada termo i, calcula x^i em O(i), somatorio = O(n²)" << endl;
    cout << "Tempo: " << tempo_potenciacao << " milissegundos" << endl;

    // Teste Produto
    cout << "\n--- METODO PRODUTO ---" << endl;
    inicio = high_resolution_clock::now();
    resultado_produto = polinomio_produto();
    fim = high_resolution_clock::now();
    tempo_produto = duration_cast<nanoseconds>(fim - inicio).count() / 1000000.0;
    cout << "Resultado: p(" << x_global << ") = " << resultado_produto << endl;
    cout << "Complexidade: O(n) - n+1 chamadas recursivas, cada uma O(1)" << endl;
    cout << "Tempo: " << tempo_produto << " milissegundos" << endl;

    // Comparação final
    cout << "\n=== COMPARACAO FINAL DOS METODOS DE POLINOMIO ===" << endl;
    cout << "Metodo\t\tResultado\tTempo (ms)\tComplexidade" << endl;
    cout << "------------------------------------------------------" << endl;
    cout << "Horner\t\t" << resultado_horner << "\t\t" << tempo_horner << "\t\tO(n)" << endl;
    cout << "Potenciacao\t" << resultado_potenciacao << "\t\t" << tempo_potenciacao << "\t\tO(n²)" << endl;
    cout << "Produto\t\t" << resultado_produto << "\t\t" << tempo_produto << "\t\tO(n)" << endl;

    cout << "\nAnalise:" << endl;
    if (resultado_horner == resultado_potenciacao && resultado_horner == resultado_produto) {
        cout << "• Todos os metodos produziram o mesmo resultado: " << resultado_horner << endl;
    } else {
        cout << "• ATENCAO: Os metodos produziram resultados diferentes!" << endl;
        cout << "  Horner: " << resultado_horner << ", Potenciacao: " << resultado_potenciacao << ", Produto: " << resultado_produto << endl;
    }
    cout << "• Metodos mais eficientes (menor complexidade): Horner e Produto O(n)" << endl;
    cout << "• Metodo menos eficiente: Potenciacao O(n^2)" << endl;

    if (tempo_horner <= tempo_produto && tempo_horner <= tempo_potenciacao) {
        cout << "• Metodo mais rapido neste teste: Horner (" << tempo_horner << " ms)" << endl;
    } else if (tempo_produto <= tempo_horner && tempo_produto <= tempo_potenciacao) {
        cout << "• Metodo mais rapido neste teste: Produto (" << tempo_produto << " ms)" << endl;
    } else {
        cout << "• Metodo mais rápido neste teste: Potenciação (" << tempo_potenciacao << " ms)" << endl;
    }

    return 0;
}
