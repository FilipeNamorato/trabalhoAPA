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

## Ferramentas usadas

- Linguagem: C++
- Compilador: g++
- Plataforma: Linux (Ubuntu)
- LLM: ChatGPT

## Como compilar e executar

Exemplo:

```bash
g++ -o fibonacci_rec fibonacci/fibonacci_recursivo.cpp
./fibonacci_rec
```
```bash
g++ -std=c++11 polinomio_recursivo.cpp -o polinomio
./polinomio
```
Exemplo com múltiplos arquivos:
```bash
g++ -std=c++11 main.cpp polinomio.cpp -o polinomio
```

## Complexidade esperada

Fibonacci:
- Recursivo: O(2^n)
- Iterativo: O(n)

Polinômio recursivo:
Horner:      O(n) - n chamadas recursivas, cada uma O(1)
Produto:     O(n) - n+1 chamadas recursivas, cada uma O(1)
Potenciação: O(n²) - para cada termo i, calcula x^i em O(i)


## Sobre os códigos gerados pela IA

Usamos um modelo de linguagem para gerar os códigos iniciais.
Alguns ajustes foram feitos para garantir que eles funcionassem corretamente.

## Conclusões



## Autores

- Deyvison Gregorio Dias
- Filipe de Lima Namorato
- Gustavo do Bem Ferreira
- Vinícius Ferraz Guedes Melo