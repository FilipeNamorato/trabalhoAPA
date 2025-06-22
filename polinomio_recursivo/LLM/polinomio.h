#ifndef POLINOMIO_H
#define POLINOMIO_H

#include <vector>
#include <string>

class PolinomioRecursivo {
private:
    std::vector<int> coeficientes;
    int grau;
    long tempoPotenciacao;  // Variáveis para armazenar tempos de execução
    long tempoProduto;
    long tempoHorner;
    
    // Funções auxiliares privadas
    int potencia(int x, int i);
    int avaliarProdutoRec(int x, int i, int potenciaAtual);
    int termo(int x, int i);
    
public:
    // Construtor
    PolinomioRecursivo(const std::vector<int>& coef);
    
    // Métodos de avaliação
    int metodoPotenciacao(int x);
    int metodoProduto(int x);
    int metodoHorner(int x);
    
    // Método para análise de complexidade
    void analisarComplexidade();
    
    // Utilitário
    std::string toString() const;
};

#endif