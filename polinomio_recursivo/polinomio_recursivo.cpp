#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include <chrono>
using namespace std::chrono;
using namespace std;

// Variáveis globais para armazenar dados do polinômio
vector<int> coeficientes_globais;
int grau_global;
int x_global;

// Função para ler dados do polinômio
void ler_polinomio() {
    cout << "=== ENTRADA DO POLINÔMIO ===" << endl;
    cout << "Digite o grau do polinômio (n): ";
    cin >> grau_global;
    
    // Validação para grau não negativo
    while (grau_global < 0) {
        cout << "O grau deve ser não negativo. Digite novamente: ";
        cin >> grau_global;
    }

    // Redimensiona o vetor para ter espaço suficiente
    coeficientes_globais.resize(grau_global + 1);
    
    cout << "Digite os coeficientes a0, a1, ..., a" << grau_global << ":" << endl;
    for (int i = 0; i <= grau_global; i++) {
        cout << "a[" << i << "]: ";
        cin >> coeficientes_globais[i];
        while (cin.fail()) {
        cout << "Entrada invalida!" << endl;
        // Limpa o estado de erro
        cin.clear();
        // Descarta o restante da linha para evitar loop infinito
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "a[" << i << "]: ";
        cin >> coeficientes_globais[i];
        }
    } 

    cout << "Digite o valor de x: ";
    cin >> x_global;
    
    cout << "\nPolinômio inserido: ";
    bool primeiro = true;
    for (int i = grau_global; i >= 1; i--) {
        if (primeiro) {
            cout << coeficientes_globais[i];
            primeiro = false;
        } else {
            if (coeficientes_globais[i] >= 0) {
                cout << " + " << coeficientes_globais[i];
            } else {
                cout << " - " << abs(coeficientes_globais[i]);
            }
        }
        if (i > 1) cout << "x^" << i;
        else if (i == 1) cout << "x";
    }
    cout << "\nPara x = " << x_global << endl;
}

// 1 - Implementação recursiva do Polinômio (Algoritmo de Horner)
// Complexidade: O(n) - cada chamada recursiva executa operações O(1)
// e há exatamente n chamadas recursivas
int termo(int i, int n) {
    if (i < n) {
        // O(1): caso base
        return coeficientes_globais[i] + x_global * termo(i + 1, n);
    } else {
        // O(1): operações aritméticas básicas
        return coeficientes_globais[n];
    }
}

int polinomio_horner() {
    if (grau_global == 0) {
        return coeficientes_globais[0];
    } else {
        return termo(0, grau_global);
    }
}

// 2 - Método Potenciação
// Complexidade da potencia: O(i) - há i chamadas recursivas
int potencia(int x, int i) {
    if (i == 0) {
        // O(1): caso base
        return 1;
    } else if (i == 1) {
        // O(1): caso base
        return x;
    } else {
        // O(1): operação aritmética + chamada recursiva
        return x * potencia(x, i - 1);
    }
}

// Complexidade total: O(n²) - para cada termo i (1 a n), calcula potencia(x,i) que é O(i)
// Somatório de i=1 até n de O(i) = O(n²)
int polinomio_potenciacao_rec(int i) {
    if (i > grau_global) {
        // O(1): caso base
        return 0;
    } else {
        // O(i): potencia(x_global, i) tem complexidade O(i)
        // Total: O(n²) considerando todas as chamadas
        return coeficientes_globais[i] * potencia(x_global, i) + polinomio_potenciacao_rec(i + 1);
    }
}

int polinomio_potenciacao() {
    return polinomio_potenciacao_rec(0);
}

// 3 - Método Produto  
// Complexidade: O(n) - há n chamadas recursivas, cada uma O(1)
int polinomio_produto_rec(int i, int y, int p) {
    if (i > grau_global) {
        // O(1): caso base
        return p;
    } else if (i == 0) {
        // O(1): operações aritméticas + chamada recursiva
        return polinomio_produto_rec(i + 1, x_global, coeficientes_globais[0]);
    } else if (i == grau_global) {
        // O(1): operações aritméticas
        return p + coeficientes_globais[i] * y;
    } else {
        // O(1): operações aritméticas + chamada recursiva
        return polinomio_produto_rec(i + 1, y * x_global, p + coeficientes_globais[i] * y);
    }
}

int polinomio_produto() {
    return polinomio_produto_rec(0, 1, 0);
}


int main() {
    cout << "=== ALGORITMOS RECURSIVOS - ANÁLISE DE COMPLEXIDADE ===" << endl;
    
    // Ler dados do polinômio
    ler_polinomio();
    
    // Variáveis para armazenar resultados e tempos
    int resultado_horner, resultado_potenciacao, resultado_produto;
    double tempo_horner, tempo_potenciacao, tempo_produto;
    
    // Teste 1: Método Horner
    cout << "\n--- TESTE MÉTODO HORNER ---" << endl;
    auto inicio = high_resolution_clock::now();
    resultado_horner = polinomio_horner();
    auto fim = high_resolution_clock::now();
    tempo_horner = duration_cast<nanoseconds>(fim - inicio).count() / 1000000.0;
    cout << "Resultado: p(" << x_global << ") = " << resultado_horner << endl;
    cout << "Complexidade: O(n) - n chamadas recursivas, cada uma O(1)" << endl;
    cout << "Tempo: " << tempo_horner << " milissegundos" << endl;
    
    // Teste 2: Método Potenciação
    cout << "\n--- TESTE MÉTODO POTENCIAÇÃO ---" << endl;
    inicio = high_resolution_clock::now();
    resultado_potenciacao = polinomio_potenciacao();
    fim = high_resolution_clock::now();
    tempo_potenciacao = duration_cast<nanoseconds>(fim - inicio).count() / 1000000.0;
    cout << "Resultado: p(" << x_global << ") = " << resultado_potenciacao << endl;
    cout << "Complexidade: O(n²) - para cada termo i, calcula x^i em O(i), somatório = O(n²)" << endl;
    cout << "Tempo: " << tempo_potenciacao << " milissegundos" << endl;
    
    // Teste 3: Método Produto
    cout << "\n--- TESTE MÉTODO PRODUTO ---" << endl;
    inicio = high_resolution_clock::now();
    resultado_produto = polinomio_produto();
    fim = high_resolution_clock::now();
    tempo_produto = duration_cast<nanoseconds>(fim - inicio).count() / 1000000.0;
    cout << "Resultado: p(" << x_global << ") = " << resultado_produto << endl;
    cout << "Complexidade: O(n) - n+1 chamadas recursivas, cada uma O(1)" << endl;
    cout << "Tempo: " << tempo_produto << " milissegundos" << endl;
    

    // Comparação final
    cout << "\n=== COMPARAÇÃO FINAL DOS MÉTODOS DE POLINÔMIO ===" << endl;
    cout << "Método\t\tResultado\tTempo (ms)\tComplexidade" << endl;
    cout << "------------------------------------------------------" << endl;
    cout << "Horner\t\t" << resultado_horner << "\t\t" << tempo_horner << "\t\tO(n)" << endl;
    cout << "Potenciação\t" << resultado_potenciacao << "\t\t" << tempo_potenciacao << "\t\tO(n²)" << endl;
    cout << "Produto\t\t" << resultado_produto << "\t\t" << tempo_produto << "\t\tO(n)" << endl;
    
    cout << "\nAnálise:" << endl;
    if (resultado_horner == resultado_potenciacao && resultado_horner == resultado_produto) {
        cout << "• Todos os métodos produziram o mesmo resultado: " << resultado_horner << endl;
    } else {
        cout << "• ATENÇÃO: Os métodos produziram resultados diferentes!" << endl;
        cout << "  Horner: " << resultado_horner << ", Potenciação: " << resultado_potenciacao << ", Produto: " << resultado_produto << endl;
    }
    cout << "• Métodos mais eficientes (menor complexidade): Horner e Produto O(n)" << endl;
    cout << "• Método menos eficiente: Potenciação O(n²)" << endl;
    
    // Identificar o mais rápido
    if (tempo_horner <= tempo_produto && tempo_horner <= tempo_potenciacao) {
        cout << "• Método mais rápido neste teste: Horner (" << tempo_horner << " μs)" << endl;
    } else if (tempo_produto <= tempo_horner && tempo_produto <= tempo_potenciacao) {
        cout << "• Método mais rápido neste teste: Produto (" << tempo_produto << " μs)" << endl;
    } else {
        cout << "• Método mais rápido neste teste: Potenciação (" << tempo_potenciacao << " μs)" << endl;
    }
    
    return 0;
}