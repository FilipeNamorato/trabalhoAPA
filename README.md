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

g++ -o fibonacci_rec fibonacci/fibonacci_recursivo.cpp
./fibonacci_rec

## Complexidade esperada

Fibonacci:
- Recursivo: O(2^n)
- Iterativo: O(n)

Polinômio:
- Ambos: O(n), mas o iterativo é mais rápido na prática (Horner)

## Sobre os códigos gerados pela IA

Usamos um modelo de linguagem para gerar os códigos iniciais.
Alguns ajustes foram feitos para garantir que eles funcionassem corretamente.

## Conclusões

- A versão iterativa é mais eficiente nos dois casos.
- O uso de LLMs ajudou a ganhar tempo, mas sempre foi preciso revisar.
- A comparação entre teoria e prática mostrou como a escolha do algoritmo afeta o desempenho.

## Autores

- Nome 1
- Nome 2
- Nome 3
- Nome 4

## Licença

Uso educacional. Licença MIT.
