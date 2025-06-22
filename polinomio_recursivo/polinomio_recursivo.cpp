#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include <chrono>
#include <cstdlib>
#include <ctime>
using namespace std::chrono;
using namespace std;

// Variáveis globais para armazenar dados do polinômio
vector<int> coeficientes_globais;
int grau_global;
int x_global;

// Contadores globais para rastrear o número de passos (chamadas recursivas)
int contador_horner = 0;
int contador_potenciacao = 0;
int contador_produto = 0;
int contador_potencia = 0;

// Contadores globais para operações aritméticas (somas e multiplicações)
int operacoes_horner = 0;
int operacoes_potenciacao = 0;
int operacoes_potencia = 0;
int operacoes_produto = 0;

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
    for (int i = grau_global; i >= 0; i--) {
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
    contador_horner++; // Incrementa contador a cada chamada recursiva
    if (i < n) {
        operacoes_horner += 2; // 1 soma + 1 multiplicação
        return coeficientes_globais[i] + x_global * termo(i + 1, n);
    } else {
        return coeficientes_globais[n];
    }
}

int polinomio_horner() {
    contador_horner = 0; // Reseta contador antes de começar
    operacoes_horner = 0; // Reseta contador de operações aritméticas
    if (grau_global == 0) {
        contador_horner = 1; // Conta como 1 passo mesmo sem recursão
        return coeficientes_globais[0];
    } else {
        return termo(0, grau_global);
    }
}

// 2 - Método Potenciação
// Complexidade da potencia: O(i) - há i chamadas recursivas
int potencia(int x, int i) {
    contador_potencia++; // Incrementa contador a cada chamada recursiva
    if (i == 0) {
        return 1;
    } else if (i == 1) {
        return x;
    } else {
        operacoes_potencia++; // 1 multiplicação por chamada 
        return x * potencia(x, i - 1);
    }
}

// Complexidade total: O(n²) - para cada termo i (0 a n), calcula potencia(x,i) que é O(i)
// Somatório de i=0 até n de O(i) = O(n²)
int polinomio_potenciacao_rec(int i) {
    contador_potenciacao++; // Incrementa contador a cada chamada recursiva
    if (i > grau_global) {
        return 0;
    } else {
        operacoes_potenciacao += 2; // 1 multiplicação + 1 soma
        return coeficientes_globais[i] * potencia(x_global, i) + polinomio_potenciacao_rec(i + 1);
    }
}

int polinomio_potenciacao() {
    contador_potenciacao = 0; 
    contador_potencia = 0;    
    operacoes_potenciacao = 0;
    operacoes_potencia = 0;
    return polinomio_potenciacao_rec(0);
}

// 3 - Método Produto  
// Complexidade: O(n) - há n chamadas recursivas, cada uma O(1)
int polinomio_produto_rec(int i, int y, int p) {
    contador_produto++; // Incrementa contador a cada chamada recursiva
    if (i > grau_global) {
        return p;
    } else if (i == 0) {
        return polinomio_produto_rec(i + 1, x_global, coeficientes_globais[0]);
    } else if (i == grau_global) {
        operacoes_produto += 2; // 1 multiplicação + 1 soma
        return p + coeficientes_globais[i] * y;
    } else {
        operacoes_produto += 3; // 2 multiplicações + 1 soma
        return polinomio_produto_rec(i + 1, y * x_global, p + coeficientes_globais[i] * y);
    }
}

int polinomio_produto() {
    contador_produto = 0; // Reseta contador antes de começar
    operacoes_produto = 0; // Reseta contador de operações
    return polinomio_produto_rec(0, 1, 0);
}

void gerar_polinomio_aleatorio(int grau, int x) {
    grau_global = grau;
    x_global = x;
    coeficientes_globais.resize(grau + 1);

    srand(time(0));  // Inicializa a semente do gerador de números aleatórios

    for (int i = 0; i <= grau; i++) {
        // Gera coeficientes aleatórios entre -10 e 10
        coeficientes_globais[i] = (rand() % 21) - 10;
    }

    cout << "\nPolinômio de grau " << grau_global << " gerado automaticamente com coeficientes aleatórios e x = " << x_global << endl;
}

void executar_testes() {
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
    cout << "Passos executados: " << contador_horner << endl;
    cout << "Operações aritméticas: " << operacoes_horner << endl;
    cout << "Tempo: " << tempo_horner << " milissegundos" << endl;

    // Teste 2: Método Potenciação
    cout << "\n--- TESTE MÉTODO POTENCIAÇÃO ---" << endl;
    inicio = high_resolution_clock::now();
    resultado_potenciacao = polinomio_potenciacao();
    fim = high_resolution_clock::now();
    tempo_potenciacao = duration_cast<nanoseconds>(fim - inicio).count() / 1000000.0;
    int total_passos_potenciacao = contador_potenciacao + contador_potencia;
    int total_operacoes_potenciacao = operacoes_potenciacao + operacoes_potencia;
    cout << "Resultado: p(" << x_global << ") = " << resultado_potenciacao << endl;
    cout << "Complexidade: O(n²) - para cada termo i, calcula x^i em O(i), somatório = O(n²)" << endl;
    cout << "Passos executados: " << total_passos_potenciacao << " (polinômio: " << contador_potenciacao << " + potência: " << contador_potencia << ")" << endl;
    cout << "Operações aritméticas: " << total_operacoes_potenciacao << endl;
    cout << "Tempo: " << tempo_potenciacao << " milissegundos" << endl;

    // Teste 3: Método Produto
    cout << "\n--- TESTE MÉTODO PRODUTO ---" << endl;
    inicio = high_resolution_clock::now();
    resultado_produto = polinomio_produto();
    fim = high_resolution_clock::now();
    tempo_produto = duration_cast<nanoseconds>(fim - inicio).count() / 1000000.0;
    cout << "Resultado: p(" << x_global << ") = " << resultado_produto << endl;
    cout << "Complexidade: O(n) - n+1 chamadas recursivas, cada uma O(1)" << endl;
    cout << "Passos executados: " << contador_produto << endl;
    cout << "Operações aritméticas: " << operacoes_produto << endl;
    cout << "Tempo: " << tempo_produto << " milissegundos" << endl;

    // Comparação final
    cout << "\n=== COMPARAÇÃO FINAL DOS MÉTODOS DE POLINÔMIO ===" << endl;
    cout << "Método\t\tResultado\tTempo (ms)\tOperações\tComplexidade" << endl;
    cout << "------------------------------------------------------------------------" << endl;
    cout << "Horner\t\t" << resultado_horner << "\t\t" << tempo_horner << "\t\t" << operacoes_horner << "\t\tO(n)" << endl;
    cout << "Potenciação\t" << resultado_potenciacao << "\t\t" << tempo_potenciacao << "\t\t" << total_operacoes_potenciacao << "\t\tO(n²)" << endl;
    cout << "Produto\t\t" << resultado_produto << "\t\t" << tempo_produto << "\t\t" << operacoes_produto << "\t\tO(n)" << endl;

    cout << "\nAnálise:" << endl;
    if (resultado_horner == resultado_potenciacao && resultado_horner == resultado_produto) {
        cout << "• Todos os métodos produziram o mesmo resultado: " << resultado_horner << endl;
    } else {
        cout << "• ATENÇÃO: Os métodos produziram resultados diferentes!" << endl;
        cout << "  Horner: " << resultado_horner << ", Potenciação: " << resultado_potenciacao << ", Produto: " << resultado_produto << endl;
    }
    cout << "• Métodos mais eficientes (menor complexidade): Horner e Produto O(n)" << endl;
    cout << "• Método menos eficiente: Potenciação O(n²)" << endl;

    // Método mais rápido
    if (tempo_horner <= tempo_produto && tempo_horner <= tempo_potenciacao) {
        cout << "• Método mais rápido neste teste: Horner (" << tempo_horner << " ms)" << endl;
    } else if (tempo_produto <= tempo_horner && tempo_produto <= tempo_potenciacao) {
        cout << "• Método mais rápido neste teste: Produto (" << tempo_produto << " ms)" << endl;
    } else {
        cout << "• Método mais rápido neste teste: Potenciação (" << tempo_potenciacao << " ms)" << endl;
    }

    // Método com menos operações aritméticas
    cout << "• Método com menos operações aritméticas: ";
    if (operacoes_horner <= total_operacoes_potenciacao && operacoes_horner <= operacoes_produto) {
        cout << "Horner (" << operacoes_horner << " operações)";
    } else if (operacoes_produto <= operacoes_horner && operacoes_produto <= total_operacoes_potenciacao) {
        cout << "Produto (" << operacoes_produto << " operações)";
    } else {
        cout << "Potenciação (" << total_operacoes_potenciacao << " operações)";
    }
    cout << endl;
}


int main() {
    cout << "=== ALGORITMOS RECURSIVOS - ANÁLISE DE COMPLEXIDADE ===" << endl;

    int opcao;
    cout << "\nEscolha a forma de gerar o polinômio:" << endl;
    cout << "1 - Digitar manualmente" << endl;
    cout << "2 - Gerar aleatório (exemplo: grau 10000, x=2)" << endl;
    cout << "Opção: ";
    cin >> opcao;

    switch(opcao) {
        case 1:
            ler_polinomio();
            break;
        case 2:            
            gerar_polinomio_aleatorio(10000, 2);
            break;
        default:
            cout << "Opção inválida!" << endl;
            return 1;
    }

    executar_testes();

    return 0;
}
