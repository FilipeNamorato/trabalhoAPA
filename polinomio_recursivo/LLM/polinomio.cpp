#include "polinomio.h"
#include <iostream>
#include <sstream>
#include <cmath>
#include <iomanip> // setw e setprecision

PolinomioRecursivo::PolinomioRecursivo(const std::vector<int>& coef) : coeficientes(coef), grau(coef.size() - 1) {}

// Método auxiliar para cálculo de potência (O(i))
int PolinomioRecursivo::potencia(int x, int i) {
    if (i == 0) return 1;
    if (i == 1) return x;
    return x * potencia(x, i - 1);
}

// Implementação do método de potenciação (O(n²))
int PolinomioRecursivo::metodoPotenciacao(int x) {
    int resultado = 0;
    for (int i = 0; i <= grau; i++) {
        resultado += coeficientes[i] * potencia(x, i);
    }
    return resultado;
}

// Implementação do método do produto (O(n))
int PolinomioRecursivo::avaliarProdutoRec(int x, int i, int potenciaAtual) {
    if (i > grau) return 0;
    if (i == 0) {
        return coeficientes[0] + avaliarProdutoRec(x, 1, x);
    }
    return coeficientes[i] * potenciaAtual + avaliarProdutoRec(x, i + 1, potenciaAtual * x);
}

int PolinomioRecursivo::metodoProduto(int x) {
    return avaliarProdutoRec(x, 0, 1);
}

// Implementação do método de Horner (O(n))
int PolinomioRecursivo::termo(int x, int i) {
    if (i < grau) {
        return coeficientes[i] + x * termo(x, i + 1);
    }
    return coeficientes[grau];
}

int PolinomioRecursivo::metodoHorner(int x) {
    if (grau == 0) return coeficientes[0];
    return termo(x, 0);
}

// Representação do polinômio como string
std::string PolinomioRecursivo::toString() const {
    std::stringstream ss;
    for (int i = grau; i >= 0; i--) {
        if (coeficientes[i] != 0) {
            if (i != grau && coeficientes[i] > 0) ss << " + ";
            if (coeficientes[i] < 0) ss << " - ";
            
            if (abs(coeficientes[i]) != 1 || i == 0) {
                ss << abs(coeficientes[i]);
            }
            
            if (i > 0) {
                ss << "x";
                if (i > 1) ss << "^" << i;
            }
        }
    }
    return ss.str();
}

// Análise detalhada da complexidade
void PolinomioRecursivo::analisarComplexidade() {
    std::cout << "\n=== ANÁLISE DE COMPLEXIDADE DETALHADA ===\n";
    std::cout << "Polinômio: " << toString() << " (grau " << grau << ")\n\n";

    // Método de Potenciação
    std::cout << "1. MÉTODO DE POTENCIAÇÃO (Complexidade O(n²)):\n";
    std::cout << "   Como funciona:\n";
    std::cout << "   - Calcula cada potência x^i do zero\n";
    std::cout << "   - Multiplica pelo coeficiente a_i\n";
    std::cout << "   - Soma todos os termos\n\n";
    
    std::cout << "   Análise matemática (T(n)):\n";
    std::cout << "   Para um polinômio de grau " << grau << ":\n";
    std::cout << "   - Cada x^i requer (i-1) multiplicações (ex: x³ = x*x*x → 2 mult)\n";
    std::cout << "   - Total multiplicações potências: 0+0+1+...+" << grau-1 << " = " << (grau*(grau-1))/2 << "\n";
    std::cout << "   - Multiplicações pelos coeficientes: " << grau+1 << "\n";
    std::cout << "   - Somas: " << grau << "\n";
    std::cout << "   Fórmula: T(n) = n(n-1)/2 + (n+1) + n = " << (grau*(grau-1))/2 + (grau+1) + grau << " operações\n\n";

    // Método do Produto
    std::cout << "2. MÉTODO DO PRODUTO (Complexidade O(n)):\n";
    std::cout << "   Como funciona:\n";
    std::cout << "   - Mantém o valor da potência atual (x^i)\n";
    std::cout << "   - Atualiza multiplicando por x a cada termo\n";
    std::cout << "   - Evita recálculos das potências\n\n";
    
    std::cout << "   Análise matemática (T(n)):\n";
    std::cout << "   - 2 multiplicações por termo (exceto o primeiro)\n";
    std::cout << "   - 1 soma por termo\n";
    std::cout << "   Fórmula: T(n) = 2*" << grau << " + " << grau << " = " << 2*grau + grau << " operações\n\n";

    // Método de Horner
    std::cout << "3. MÉTODO DE HORNER (Complexidade O(n)):\n";
    std::cout << "   Como funciona:\n";
    std::cout << "   - Forma aninhada: ";
    std::cout << coeficientes[0];
    for (int i = 1; i <= grau; i++) {
        std::cout << " + x*(" << coeficientes[i];
    }
    for (int i = 1; i <= grau; i++) std::cout << ")";
    std::cout << "\n   - Calcula tudo em uma única passagem\n\n";
    
    std::cout << "   Análise matemática (T(n)):\n";
    std::cout << "   - 1 multiplicação e 1 soma por termo (exceto o primeiro)\n";
    std::cout << "   Fórmula: T(n) = " << grau << " + " << grau << " = " << grau + grau << " operações\n\n";

    // Tabela Comparativa
    std::cout << "COMPARAÇÃO FINAL PARA GRAU " << grau << ":\n";
    std::cout << "+------------------+---------------------+---------------------+\n";
    std::cout << "| Método           | Operações Aritméticas | Complexidade        |\n";
    std::cout << "+------------------+---------------------+---------------------+\n";
    std::cout << "| Potenciação      | " << std::setw(19) << (grau*(grau-1))/2 + (grau+1) + grau << " | O(n²)               |\n";
    std::cout << "| Produto          | " << std::setw(19) << 3*grau << " | O(n)                |\n";
    std::cout << "| Horner           | " << std::setw(19) << 2*grau << " | O(n)                |\n";
    std::cout << "+------------------+---------------------+---------------------+\n";
}
   