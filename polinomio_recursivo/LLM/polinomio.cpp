#include "polinomio.h"
#include <iostream>
#include <sstream>
#include <cmath>
#include <iomanip>
#include <chrono>

PolinomioRecursivo::PolinomioRecursivo(const std::vector<int>& coef) : 
    coeficientes(coef), 
    grau(coef.size() - 1),
    tempoPotenciacao(0),
    tempoProduto(0),
    tempoHorner(0) {}

int PolinomioRecursivo::potencia(int x, int i) {
    if (i == 0) return 1;
    if (i == 1) return x;
    return x * potencia(x, i - 1);
}

int PolinomioRecursivo::metodoPotenciacao(int x) {
    auto start = std::chrono::high_resolution_clock::now();
    
    int resultado = 0;
    for (int i = 0; i <= grau; i++) {
        resultado += coeficientes[i] * potencia(x, i);
    }
    
    auto end = std::chrono::high_resolution_clock::now();
    tempoPotenciacao = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    return resultado;
}

int PolinomioRecursivo::avaliarProdutoRec(int x, int i, int potenciaAtual) {
    if (i > grau) return 0;
    if (i == 0) {
        return coeficientes[0] + avaliarProdutoRec(x, 1, x);
    }
    return coeficientes[i] * potenciaAtual + avaliarProdutoRec(x, i + 1, potenciaAtual * x);
}

int PolinomioRecursivo::metodoProduto(int x) {
    auto start = std::chrono::high_resolution_clock::now();
    
    int result = avaliarProdutoRec(x, 0, 1);
    
    auto end = std::chrono::high_resolution_clock::now();
    tempoProduto = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    return result;
}

int PolinomioRecursivo::termo(int x, int i) {
    if (i < grau) {
        return coeficientes[i] + x * termo(x, i + 1);
    }
    return coeficientes[grau];
}

int PolinomioRecursivo::metodoHorner(int x) {
    auto start = std::chrono::high_resolution_clock::now();
    
    if (grau == 0) return coeficientes[0];
    int result = termo(x, 0);
    
    auto end = std::chrono::high_resolution_clock::now();
    tempoHorner = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    return result;
}

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

void PolinomioRecursivo::analisarComplexidade() {
    int x = 2; // Valor para avaliação
    metodoPotenciacao(x);
    metodoProduto(x);
    metodoHorner(x);
    
    std::cout << "\n=== ANÁLISE DE COMPLEXIDADE DETALHADA ===\n";
    std::cout << "Polinômio: " << toString() << " (grau " << grau << ")\n";
    std::cout << "Tempos de execução (x=" << x << "):\n";
    std::cout << "- Potenciação: " << tempoPotenciacao << " ns\n";
    std::cout << "- Produto: " << tempoProduto << " ns\n";
    std::cout << "- Horner: " << tempoHorner << " ns\n\n";

    // Restante da análise de complexidade...
    std::cout << "COMPARAÇÃO FINAL PARA GRAU " << grau << ":\n";
    std::cout << "+------------------+---------------------+---------------------+----------------+\n";
    std::cout << "| Método           | Operações Aritméticas | Complexidade        | Tempo (ns)     |\n";
    std::cout << "+------------------+---------------------+---------------------+----------------+\n";
    std::cout << "| Potenciação      | " << std::setw(19) << (grau*(grau-1))/2 + (grau+1) + grau 
              << " | O(n²)               | " << std::setw(14) << tempoPotenciacao << " |\n";
    std::cout << "| Produto          | " << std::setw(19) << 3*grau 
              << " | O(n)                | " << std::setw(14) << tempoProduto << " |\n";
    std::cout << "| Horner           | " << std::setw(19) << 2*grau 
              << " | O(n)                | " << std::setw(14) << tempoHorner << " |\n";
    std::cout << "+------------------+---------------------+---------------------+----------------+\n";
}