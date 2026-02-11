/**
 * @exercise Lista Básico C++ - Exercício 2
 * @title Contador de Pares e Ímpares
 * @description Escreva um programa que percorra os números de 1 a 50, verifique se é par ou ímpar, conte quantos pares e ímpares existem e exiba os resultados.
 * @input stdin (sem entrada)
 * @output stdout
 * @timeout 1000
 * @test name="Saída esperada" input="" expected="Pares: 25\nÍmpares: 25"
 */

#include <iostream>

using namespace std;

int main() {
    int pares = 0;
    int impares = 0;

    // TODO: Percorra números de 1 a 50
    for (int i = 1; i <= 50; i++) {
        // TODO: Conte pares e ímpares
        if (i % 2 == 0) {
            pares++;
        } else {
            impares++;
        }
    }

    // TODO: Exiba os resultados
    cout << "Pares: " << pares << endl;
    cout << "Ímpares: " << impares << endl;

    return 0;
}
