#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include  <chrono>
using namespace std::chrono;
using namespace std;


// Variáveis globais para armazenar dados do polinômio
vector<int> coeficientes_globais;
int grau_global;
int x_global;

// Função para ler dados do polinômio
void ler_polinomio() {
    cout << "\n=== ENTRADA DO POLINÔMIO ===" << endl;
    cout << "Digite o grau do polinômio (n): ";
    cin >> grau_global;
    
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
    for (int i = grau_global; i >= 0; i--) {
        if (i == grau_global) {
            cout << coeficientes_globais[i];
        } else {
            cout << (coeficientes_globais[i] >= 0 ? " + " : " - ") << abs(coeficientes_globais[i]);
        }
        if (i > 1) cout << "x^" << i;
        else if (i == 1) cout << "x";
    }
    cout << "\nPara x = " << x_global << endl;
}

// 1 - Implementação recursiva do Polinômio (Algoritmo de Horner)
int termo(int i, int n) {
    if (i < n) {
        return coeficientes_globais[i] + x_global * termo(i + 1, n);
    } else {
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

// Análise de complexidade do método Horner com níveis k-ésimos
void complexidade_horner() {
    cout << "\n--- ANÁLISE DE COMPLEXIDADE - MÉTODO HORNER ---" << endl;
    cout << "Equação de recorrência da função termo(i):" << endl;
    cout << "T(n) = 1 (caso base: i >= n)" << endl;
    cout << "T(i) = 4 + T(i+1) para i < n" << endl;
    
    cout << "\nExpansão por níveis:" << endl;
    cout << "1º nível: T(" << grau_global << ") = 4 + T(" << (grau_global-1) << ")" << endl;
    if (grau_global >= 2) {
        cout << "2º nível: T(" << grau_global << ") = 4 + 4 + T(" << (grau_global-2) << ")" << endl;
    }
    if (grau_global >= 3) {
        cout << "3º nível: T(" << grau_global << ") = 4 + 4 + 4 + T(" << (grau_global-3) << ")" << endl;
    }
    
    cout << "k-ésimo nível: T(" << grau_global << ") = 4.k + T(" << grau_global << "-k)" << endl;
    cout << "Condição de retorno: " << grau_global << " - k = 0 => k = " << grau_global << endl;
    cout << "Derivando: T(" << grau_global << ") = 4." << grau_global << " + 1 = " << (4*grau_global + 1) << endl;
    cout << "Portanto T(n) é O(n)." << endl;
}

// 2 - Progressão Aritmética (1, 3, 5, 7, ...)
int impar(int n) {
    if (n == 1) {
        return 1;
    } else {
        return 2 + impar(n - 1);
    }
}

// Análise de complexidade da Progressão Aritmética com níveis k-ésimos
void complexidade_impar(int n) {
    cout << "\n--- ANÁLISE DE COMPLEXIDADE - PROGRESSÃO ARITMÉTICA ---" << endl;
    cout << "Equação de recorrência:" << endl;
    cout << "F(1) = 1" << endl;
    cout << "F(n) = 2 + F(n-1) para n > 1" << endl;
    
    cout << "\nFunção de complexidade:" << endl;
    cout << "T(1) = 1" << endl;
    cout << "T(n) = 3 + T(n-1) para n > 1" << endl;
    
    cout << "\nExpansão por níveis:" << endl;
    cout << "1º nível: T(" << n << ") = 3 + T(" << (n-1) << ")" << endl;
    if (n >= 3) {
        cout << "2º nível: T(" << n << ") = 3 + 3 + T(" << (n-2) << ")" << endl;
    }
    if (n >= 4) {
        cout << "3º nível: T(" << n << ") = 3 + 3 + 3 + T(" << (n-3) << ")" << endl;
    }
    
    cout << "k-ésimo nível: T(" << n << ") = 3.k + T(" << n << "-k)" << endl;
    cout << "Condição de retorno: " << n << " - k = 1 => k = " << (n-1) << endl;
    cout << "Derivando: T(" << n << ") = 3.(" << (n-1) << ") + 1 = " << (3*(n-1) + 1) << endl;
    cout << "Portanto T(n) é O(n)." << endl;
}

// 3 - Progressão Geométrica (1, 2, 4, 8, ...)
int quadrado(int n) {
    if (n == 1) {
        return 1;
    } else {
        return 2 * quadrado(n - 1);
    }
}

// Análise de complexidade da Progressão Geométrica com níveis k-ésimos
void complexidade_quadrado(int n) {
    cout << "\n--- ANÁLISE DE COMPLEXIDADE - PROGRESSÃO GEOMÉTRICA ---" << endl;
    cout << "Equação de recorrência:" << endl;
    cout << "F(1) = 1" << endl;
    cout << "F(n) = 2 * F(n-1) para n > 1" << endl;
    
    cout << "\nFunção de complexidade:" << endl;
    cout << "T(1) = 1" << endl;
    cout << "T(n) = 3 + T(n-1) para n > 1" << endl;
    
    cout << "\nExpansão por níveis:" << endl;
    cout << "1º nível: T(" << n << ") = 3 + T(" << (n-1) << ")" << endl;
    if (n >= 3) {
        cout << "2º nível: T(" << n << ") = 3 + 3 + T(" << (n-2) << ")" << endl;
    }
    if (n >= 4) {
        cout << "3º nível: T(" << n << ") = 3 + 3 + 3 + T(" << (n-3) << ")" << endl;
    }
    
    cout << "k-ésimo nível: T(" << n << ") = 3.k + T(" << n << "-k)" << endl;
    cout << "Condição de retorno: " << n << " - k = 1 => k = " << (n-1) << endl;
    cout << "Derivando: T(" << n << ") = 3.(" << (n-1) << ") + 1 = " << (3*(n-1) + 1) << endl;
    cout << "Portanto T(n) é O(n)." << endl;
}

// 4 - Método Potenciação
int potencia(int x, int i) {
    if (i == 0) {
        return 1;
    } else if (i == 1) {
        return x;
    } else {
        return x * potencia(x, i - 1);
    }
}

int polinomio_potenciacao_rec(int i) {
    if (i > grau_global) {
        return 0;
    } else {
        return coeficientes_globais[i] * potencia(x_global, i) + polinomio_potenciacao_rec(i + 1);
    }
}

int polinomio_potenciacao() {
    return polinomio_potenciacao_rec(0);
}

// Análise de complexidade do método Potenciação com níveis k-ésimos
void complexidade_potenciacao() {
    cout << "\n--- ANÁLISE DE COMPLEXIDADE - MÉTODO POTENCIAÇÃO ---" << endl;
    cout << "Para cada x^i, são necessárias (i-1) multiplicações" << endl;
    cout << "T(n) = 2n + 1 + ∑(i+1) para i=1 até n" << endl;
    
    int soma_i = 0;
    cout << "\nCalculando somatório:" << endl;
    for (int i = 1; i <= grau_global; i++) {
        soma_i += (i + 1);
        cout << "i=" << i << ": +" << (i+1);
        if (i < grau_global) cout << " ";
    }
    cout << " = " << soma_i << endl;
    
    int termo1 = 2 * grau_global + 1;
    int termo2 = grau_global;
    int termo3 = (grau_global * (grau_global + 1)) / 2;
    
    cout << "T(" << grau_global << ") = 2(" << grau_global << ") + 1 + " << grau_global << " + (" << grau_global << " × (" << grau_global << "+1))/2" << endl;
    cout << "T(" << grau_global << ") = " << termo1 << " + " << termo2 << " + " << termo3 << " = " << (termo1 + termo2 + termo3) << endl;
    cout << "Complexidade: O(n²)" << endl;
}

// 5 - Método Produto
int polinomio_produto_rec(int i, int y, int p) {
    if (i > grau_global) {
        return p;
    } else if (i == 0) {
        return polinomio_produto_rec(i + 1, x_global, coeficientes_globais[0]);
    } else if (i == grau_global) {
        return p + coeficientes_globais[i] * y;
    } else {
        return polinomio_produto_rec(i + 1, y * x_global, p + coeficientes_globais[i] * y);
    }
}

int polinomio_produto() {
    return polinomio_produto_rec(0, 1, 0);
}

// Análise de complexidade do método Produto com níveis k-ésimos
void complexidade_produto() {
    cout << "\n--- ANÁLISE DE COMPLEXIDADE - MÉTODO PRODUTO ---" << endl;
    cout << "Algoritmo iterativo equivalente:" << endl;
    cout << "P <- a0; y <- x; z <- n-1" << endl;
    cout << "Para i <- 1 até z: P <- p + ai.y; y <- y.x;" << endl;
    cout << "p <- p + an.y;" << endl;
    
    cout << "\nAnálise de operações:" << endl;
    cout << "Inicialização: 1 operação" << endl;
    cout << "Loop principal: (2n - 1) operações de controle" << endl;
    cout << "Dentro do loop: 3(n-1) operações" << endl;
    cout << "Operação final: 2 operações" << endl;
    
    int termo1 = 1;
    int termo2 = 2 * grau_global - 1;
    int termo3 = 3 * (grau_global - 1);
    int termo4 = 2;
    
    cout << "T(" << grau_global << ") = 1 + (2×" << grau_global << " - 1) + 3×(" << grau_global << "-1) + 2" << endl;
    cout << "T(" << grau_global << ") = " << termo1 << " + " << termo2 << " + " << termo3 << " + " << termo4 << " = " << (termo1 + termo2 + termo3 + termo4) << endl;
    cout << "T(" << grau_global << ") = 5n - 1 = 5×" << grau_global << " - 1 = " << (5*grau_global - 1) << endl;
    cout << "Complexidade: O(n)" << endl;
}

// Função para comparar complexidades
void comparar_complexidades() {
    cout << "\n=== COMPARAÇÃO DE COMPLEXIDADES DOS MÉTODOS DE POLINÔMIO ===" << endl;
    
    int horner = 4 * grau_global + 1;
    int produto = 5 * grau_global - 1;
    int potenciacao = 2 * grau_global + 1 + grau_global + (grau_global * (grau_global + 1)) / 2;
    
    cout << "Para n = " << grau_global << ":" << endl;
    cout << "Horner:      T(n) = 4n + 1 = " << horner << endl;
    cout << "Produto:     T(n) = 5n - 1 = " << produto << endl;
    cout << "Potenciação: T(n) = 2n + 1 + n + n(n+1)/2 = " << potenciacao << endl;
    
    cout << "\nRanking de eficiência (menor é melhor):" << endl;
    vector<pair<string, int>> metodos = {
        {"Horner", horner},
        {"Produto", produto}, 
        {"Potenciação", potenciacao}
    };
    
    // Ordenar por complexidade
    for (int i = 0; i < 2; i++) {
        for (int j = i + 1; j < 3; j++) {
            if (metodos[i].second > metodos[j].second) {
                swap(metodos[i], metodos[j]);
            }
        }
    }
    
    for (int i = 0; i < 3; i++) {
        cout << (i+1) << "º " << metodos[i].first << " (" << metodos[i].second << ")" << endl;
    }
    
    cout << "\nObservação do PDF:" << endl;
    cout << "5n - 1 = 4n + 1 => n₀ = 2" << endl;
    cout << "Para n ≥ 2, Horner domina assintoticamente o método Produto." << endl;
}

// Função para testar progressões
void testar_progressao_aritmetica() {
    int n;
    cout << "\n--- TESTE DA PROGRESSÃO ARITMÉTICA ---" << endl;
    cout << "Digite o valor de n para calcular o n-ésimo termo ímpar: ";
    cin >> n;
    
    if (n <= 0) {
        cout << "Aviso: n deve ser positivo, mas vamos calcular mesmo assim..." << endl;
    }
    
    int resultado = impar(abs(n)); // Usar valor absoluto para evitar recursão infinita
    cout << "O " << n << "º termo da progressão (1, 3, 5, 7, ...) é: " << resultado << endl;
    cout << "Fórmula: 2n - 1 = 2(" << abs(n) << ") - 1 = " << (2*abs(n) - 1) << endl;
    complexidade_impar(abs(n));
}

void testar_progressao_geometrica() {
    int n;
    cout << "\n--- TESTE DA PROGRESSÃO GEOMÉTRICA ---" << endl;
    cout << "Digite o valor de n para calcular o n-ésimo termo (potência de 2): ";
    cin >> n;
    
    if (n <= 0) {
        cout << "Aviso: n deve ser positivo, mas vamos calcular mesmo assim..." << endl;
    }
    
    int resultado = quadrado(abs(n));
    cout << "O " << n << "º termo da progressão (1, 2, 4, 8, ...) é: " << resultado << endl;
    cout << "Fórmula: 2^(n-1) = 2^(" << abs(n) << "-1) = 2^" << (abs(n)-1) << " = " << resultado << endl;
    complexidade_quadrado(abs(n));
}

int main() {
    cout << "=== ALGORITMOS RECURSIVOS - ANÁLISE DE COMPLEXIDADE ===" << endl;
    
    // Ler dados do polinômio no início
    ler_polinomio();
    
    int opcao;
    do {
        cout << "\n=== MENU DE TESTES ===" << endl;
        cout << "1. Testar Polinômio (Algoritmo de Horner)" << endl;
        cout << "2. Testar Polinômio (Método Potenciação)" << endl;
        cout << "3. Testar Polinômio (Método Produto)" << endl;
        cout << "4. Testar Progressão Aritmética" << endl;
        cout << "5. Testar Progressão Geométrica" << endl;
        cout << "6. Comparar Complexidades dos Métodos de Polinômio" << endl;
        cout << "7. Alterar dados do polinômio" << endl;
        cout << "0. Sair" << endl;
        cout << "Escolha uma opção: ";
        cin >> opcao;
        
        switch(opcao) {
            case 1: {
                cout << "\n--- TESTE MÉTODO HORNER ---" << endl;
                auto inicio = high_resolution_clock::now();
                int resultado = polinomio_horner();
                cout << "Resultado: p(" << x_global << ") = " << resultado << endl;
                auto fim = high_resolution_clock::now();
                auto duracao = duration_cast<microseconds>(fim - inicio);
                complexidade_horner();
                cout << "Tempo: " << duracao.count() << " microssegundos" << endl;
                break;
            }
            
            case 2: {
                cout << "\n--- TESTE MÉTODO POTENCIAÇÃO ---" << endl;
                auto inicio1 = high_resolution_clock::now();
                int resultado = polinomio_potenciacao();
                cout << "Resultado: p(" << x_global << ") = " << resultado << endl;
                auto fim1 = high_resolution_clock::now();
                auto duracao1 = duration_cast<microseconds>(fim1 - inicio1);
                complexidade_potenciacao();
                cout << "Tempo: " << duracao1.count() << " microssegundos" << endl;
                break;
            }
            
            case 3: {
                cout << "\n--- TESTE MÉTODO PRODUTO ---" << endl;
                auto inicio2 = high_resolution_clock::now();
                int resultado = polinomio_produto();
                cout << "Resultado: p(" << x_global << ") = " << resultado << endl;
                auto fim2 = high_resolution_clock::now();
                auto duracao2 = duration_cast<microseconds>(fim2 - inicio2);
                complexidade_produto();
                cout << "Tempo: " << duracao2.count() << " microssegundos" << endl;
                break;
            }
            
            case 4: {
                auto inicio3 = high_resolution_clock::now();
                testar_progressao_aritmetica();
                auto fim3 = high_resolution_clock::now();
                auto duracao3 = duration_cast<microseconds>(fim3 - inicio3);
                complexidade_produto();
                cout << "Tempo: " << duracao3.count() << " microssegundos" << endl;
                break;
            }
            
            case 5: {
                auto inicio4 = high_resolution_clock::now();
                testar_progressao_geometrica();
                auto fim4 = high_resolution_clock::now();
                auto duracao4 = duration_cast<microseconds>(fim4 - inicio4);
                cout << "Tempo: " << duracao4.count() << " microssegundos" << endl;
                break;
            }
            
            case 6: {
                auto inicio5 = high_resolution_clock::now();
                comparar_complexidades();
                auto fim5 = high_resolution_clock::now();
                auto duracao5 = duration_cast<microseconds>(fim5 - inicio5);
                cout << "Tempo: " << duracao5.count() << " microssegundos" << endl;
                break;
            }
            
            case 7: {
                ler_polinomio();
                break;
            }
            
            case 0:
                cout << "Encerrando programa..." << endl;
                break;
                
            default:
                cout << "Opção inválida! Tente novamente." << endl;
        }
        
    } while (opcao != 0);
    
    return 0;
}