#include <iostream>
#include <vector>
#include <cmath>
#include <chrono>
#include <bits/stdc++.h>

using namespace std;
using namespace chrono;

// Variáveis globais
vector<int> coeficientes_globais;
int grau_global;
int x_global;

// Contadores de iteração
int iteracoes_potenciacao = 0;
int iteracoes_produto = 0;
int iteracoes_horner = 0;

// Metodo 1: Potenciacao
int metodoPotencia() {
    iteracoes_potenciacao = 0;
    int p = coeficientes_globais[0];
    for (int i = 1; i <= grau_global; i++) {
        int potencia = 1;
        for (int j = 1; j <= i; j++) {
            potencia *= x_global;
            iteracoes_potenciacao++; // conta multiplicações
        }
        p += coeficientes_globais[i] * potencia;
        iteracoes_potenciacao++; // conta a multiplicação do coeficiente com a potência
    }
    return p;
}

// Metodo 2: Produto Acumulado
int metodoProduto() {
    iteracoes_produto = 0;
    int p = coeficientes_globais[0];
    int y = x_global;
    int z = grau_global - 1;

    for (int i = 1; i <= z; i++) {
        p += coeficientes_globais[i] * y;
        y *= x_global;
        iteracoes_produto += 2; // uma multiplicação para coef*y e outra para y*x
    }

    p += coeficientes_globais[grau_global] * y;
    iteracoes_produto++; // última multiplicação do coeficiente com y

    return p;
}

// Metodo 3: Horner
int metodoHorner() {
    iteracoes_horner = 0;
    int p = coeficientes_globais[grau_global];
    int z = grau_global - 1;

    for (int i = z; i >= 0; i--) {
        p = coeficientes_globais[i] + x_global * p;
        iteracoes_horner += 2; // uma multiplicação e uma soma por iteração
    }
    return p;
}

// Exibir o polinomio atual
void exibirPolinomio() {
    cout << "\npolinomio atual: ";
    for (int i = grau_global; i >= 0; i--) {
        cout << coeficientes_globais[i];
        if (i > 0) cout << "x^" << i << " + ";
    }
    cout << endl;
}

// Ler polinomio
void ler_polinomio() {
    cout << "Digite o grau do polinomio (n): ";
    cin >> grau_global;
    coeficientes_globais.resize(grau_global + 1);

    cout << "Digite os coeficientes (do termo de grau " << grau_global << " ate o termo de grau 0):" << endl;
    for (int i = grau_global; i >= 0; i--) {
        cout << "Coeficiente de x^" << i << ": ";
        cin >> coeficientes_globais[i];
    }

    cout << "Digite o valor de x: ";
    cin >> x_global;

    exibirPolinomio();
}


void gerar_polinomio_aleatorio(int grau, int x) {
    grau_global = grau;
    x_global = x;
    coeficientes_globais.resize(grau + 1);

    srand(time(0));  // Inicializa a semente do gerador de números aleatórios

    for (int i = 0; i <= grau; i++) {
        // Gera coeficientes aleatorios entre -10 e 10
        coeficientes_globais[i] = (rand() % 21) - 10;
    }

    cout << "\nPolinomio de grau " << grau_global << " gerado automaticamente com coeficientes aleatorios e x = " << x_global << endl;
}


int main() {
    //ler_polinomio();
    gerar_polinomio_aleatorio(9999,44554);
    int resultado_horner, resultado_potenciacao, resultado_produto;
    double tempo_horner, tempo_potenciacao, tempo_produto;

    // Horner
    cout << "\n--- TESTE METODO HORNER ---" << endl;
    auto inicio = high_resolution_clock::now();
    resultado_horner = metodoHorner();
    auto fim = high_resolution_clock::now();
    tempo_horner = duration_cast<nanoseconds>(fim - inicio).count() / 1000000.0;
    cout << "Resultado: p(" << x_global << ") = " << resultado_horner << endl;
    cout << "iteracoes: " << iteracoes_horner << endl;
    cout << "Tempo: " << tempo_horner << " ms" << endl;

    // Potenciacao
    cout << "\n--- TESTE METODO POTENCIAÇÃO ---" << endl;
    inicio = high_resolution_clock::now();
    resultado_potenciacao = metodoPotencia();
    fim = high_resolution_clock::now();
    tempo_potenciacao = duration_cast<nanoseconds>(fim - inicio).count() / 1000000.0;
    cout << "Resultado: p(" << x_global << ") = " << resultado_potenciacao << endl;
    cout << "iteracoes: " << iteracoes_potenciacao << endl;
    cout << "Tempo: " << tempo_potenciacao << " ms" << endl;

    // Produto
     cout << "\n--- TESTE METODO PRODUTO ---" << endl;
    inicio = high_resolution_clock::now();
    resultado_produto = metodoProduto();
    fim = high_resolution_clock::now();
    tempo_produto = duration_cast<nanoseconds>(fim - inicio).count() / 1000000.0;
    cout << "Resultado: p(" << x_global << ") = " << resultado_produto << endl;
    cout << "iteracoes: " << iteracoes_produto << endl;
    cout << "Tempo: " << tempo_produto << " ms" << endl;

    // Comparação final
    cout << "\n=== COMPARACAO FINAL ===" << endl;
    cout << "Metodo\t\tResultado\tTempo(ms)\titeracoes" << endl;
    cout << "-------------------------------------------------------" << endl;
    cout << "Horner\t\t" << resultado_horner << "\t\t" << tempo_horner << "\t\t" << iteracoes_horner << endl;
    cout << "Potenciacao\t" << resultado_potenciacao << "\t\t" << tempo_potenciacao << "\t\t" << iteracoes_potenciacao << endl;
    cout << "Produto\t\t" << resultado_produto << "\t\t" << tempo_produto << "\t\t" << iteracoes_produto << endl;

    cout << "\nAnalise:" << endl;
    if (resultado_horner == resultado_potenciacao && resultado_horner == resultado_produto) {
        cout << "Todos os Metodos produziram o mesmo resultado." << endl;
    } else {
        cout << "ATENCAO: Os Metodos produziram resultados diferentes!" << endl;
    }

    // Analise de desempenho
    cout << "Metodo mais rapido: ";
    if (tempo_horner <= tempo_potenciacao && tempo_horner <= tempo_produto)
        cout << "Horner (" << tempo_horner << " ms)" << endl;
    else if (tempo_potenciacao <= tempo_produto)
        cout << "Potenciacao (" << tempo_potenciacao << " ms)" << endl;
    else
        cout << "Produto (" << tempo_produto << " ms)" << endl;

    cout << "Metodo com menos iteracoes: ";
    int min_iter = min({iteracoes_horner, iteracoes_potenciacao, iteracoes_produto});
    if (min_iter == iteracoes_horner) cout << "Horner (" << iteracoes_horner << " iteracoes)" << endl;
    else if (min_iter == iteracoes_potenciacao) cout << "Potenciacao (" << iteracoes_potenciacao << " iteracoes)" << endl;
    else cout << "Produto (" << iteracoes_produto << " iteracoes)" << endl;

    return 0;
}
