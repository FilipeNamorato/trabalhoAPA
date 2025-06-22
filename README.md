# Trabalho de Análise de Projetos e Algoritmos

Este repositório contém os códigos e análises de dois problemas clássicos:
- Sequência de Fibonacci
- Avaliação de Polinômios

Ambos foram resolvidos com:
- Algoritmos recursivos e iterativos
- Geração automática de código usando modelo de linguagem (LLM)

## Objetivos

1. Implementar as versões recursiva e iterativa dos dois problemas.
2. Gerar os códigos com um modelo de linguagem (como o ChatGPT).
3. Comparar a eficiência teórica e prática dos algoritmos com diferentes tamanhos de entrada.


## Ferramentas
- **Linguagem**: C++ (padrão C++11)
- **Compilador**: g++
- **Sistema**: Linux (Ubuntu)
- **Modelo de LLM**: ChatGPT 

## Compilação e Execução
### Fibonacci
```bash
g++ -o fibonacci_rec fibonacci/fibonacci_recursivo.cpp
./fibonacci_rec
```

### Polinômio_recursivo
```bash
g++ -std=c++11 polinomio_recursivo.cpp -o polinomio
./polinomio
```
Exemplo com múltiplos arquivos:
```bash
g++ -std=c++11 main.cpp polinomio.cpp -o polinomio
```

## Complexidade dos Algoritmos
| Problema          | Método        | Complexidade | Detalhes                          |
|---------------    |---------------|--------------|-----------------------------------|
| **Fibonacci**     | Recursivo     | O(2ⁿ)        | Ineficiente para n > 40           |
|                   | Iterativo     | O(n)         | Ótimo para qualquer n             |
| **Polinômio_rec** | Horner        | O(n)         | 2n operações, n+1 passos          |
|                   | Produto       | O(n)         | 3n-1 operações, n+1 passos        |
|                   | Potenciação   | O(n²)        | n(n+1)/2 passos (ineficiente)     |

## Conclusões
1. **Fibonacci iterativo** é a melhor escolha para qualquer caso real
2. **Horner_recursivo** é ideal para polinômios quando operações são críticas
3. **Produto_recursivo** tem melhor desempenho em tempo de execução
4. **Potenciação_recursivo** só é viável para polinômios de grau muito baixo

## Autores
- Deyvison Gregorio Dias
- Filipe de Lima Namorato  
- Gustavo do Bem Ferreira
- Vinícius Ferraz Guedes Melo
```
