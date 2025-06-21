#include "polinomio.h"
#include <iostream>
#include <vector>
#include <sstream>

PolinomioRecursivo criarPolinomio() {
    std::cout << "\nCRIAÇÃO DO POLINÔMIO\n";
    std::cout << "Digite os coeficientes em ordem crescente de grau (a0 a1 a2 ... an)\n";
    std::cout << "Exemplo: 1 2 1 para x² + 2x + 1\n";
    std::cout << "Coeficientes: ";
    
    std::vector<int> coeficientes;
    std::string entrada;
    std::getline(std::cin, entrada);
    std::istringstream iss(entrada);
    
    int coef;
    while (iss >> coef) {
        coeficientes.push_back(coef);
    }
    
    if (coeficientes.empty()) {
        coeficientes = {0};
        std::cout << "Nenhum coeficiente informado. Usando polinômio 0.\n";
    }
    
    return PolinomioRecursivo(coeficientes);
}

void mostrarMenu() {
    std::cout << "\n=== MENU PRINCIPAL ===" << std::endl;
    std::cout << "1. Avaliar com método de potenciação (O(n²))" << std::endl;
    std::cout << "2. Avaliar com método do produto (O(n))" << std::endl;
    std::cout << "3. Avaliar com método de Horner (O(n))" << std::endl;
    std::cout << "4. Mostrar polinômio atual" << std::endl;
    std::cout << "5. Análise detalhada de complexidade" << std::endl;
    std::cout << "0. Sair" << std::endl;
    std::cout << "Escolha: ";
}

int main() {
    PolinomioRecursivo polinomio = criarPolinomio();
    std::cout << "Polinômio criado: " << polinomio.toString() << std::endl;
    
    int opcao;
    do {
        mostrarMenu();
        std::cin >> opcao;
        std::cin.ignore(); // Limpar buffer
        
        switch(opcao) {
            case 1: {
                int x;
                std::cout << "Digite o valor de x: ";
                std::cin >> x;
                std::cout << "Resultado: " << polinomio.metodoPotenciacao(x) << std::endl;
                break;
            }
            case 2: {
                int x;
                std::cout << "Digite o valor de x: ";
                std::cin >> x;
                std::cout << "Resultado: " << polinomio.metodoProduto(x) << std::endl;
                break;
            }
            case 3: {
                int x;
                std::cout << "Digite o valor de x: ";
                std::cin >> x;
                std::cout << "Resultado: " << polinomio.metodoHorner(x) << std::endl;
                break;
            }
            case 4:
                std::cout << "Polinômio atual: " << polinomio.toString() << std::endl;
                break;
            case 5:
                polinomio.analisarComplexidade();
                break;
            case 0:
                std::cout << "Encerrando programa..." << std::endl;
                break;
            default:
                std::cout << "Opção inválida!" << std::endl;
        }
    } while (opcao != 0);
    
    return 0;
}