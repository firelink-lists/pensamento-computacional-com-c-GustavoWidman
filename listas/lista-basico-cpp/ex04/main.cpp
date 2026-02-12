/**
 * @exercise Lista Básico C++ - Exercício 4
 * @title Template e Shared Pointer
 * @description Crie uma template de função `trocar` que receba dois parâmetros por referência e troque seus valores. No `main`, crie dois `shared_ptr` para diferentes tipos (ex: `int` e `double`), use a função template para trocar os valores apontados pelos shared_ptr, exiba os valores antes e depois da troca, e mostre a contagem de referências.
 * @input stdin
 * @output stdout
 * @timeout 1000
 * @test name="Troca int" input="5 10" expected="Antes: 5 10\nDepois: 10 5\nRefs: 1 1"
 * @test name="Troca double" input="3.14 2.71" expected="Antes: 3.14 2.71\nDepois: 2.71 3.14\nRefs: 1 1"
 */

#include <iostream>
#include <memory>

using namespace std;

// TODO: Crie o template de função trocar

template<typename T>
void trocar(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

template<typename T>
void run(T val1, T val2) {
    // TODO: Crie shared_ptr para int
    auto ptr1 = make_shared<T>(val1);
    auto ptr2 = make_shared<T>(val2);

    // TODO: Exiba valores antes da troca
    cout << "Antes: " << *ptr1 << " " << *ptr2 << endl;

    // TODO: Troque os valores
    trocar(*ptr1, *ptr2);

    // TODO: Exiba valores depois da troca
    cout << "Depois: " << *ptr1 << " " << *ptr2 << endl;

    // TODO: Mostre contagem de referências
    cout << "Refs: " << ptr1.use_count() << " " << ptr2.use_count() << endl;
}

int main() {
    double val1, val2;
    cin >> val1 >> val2;

    if (val1 == (int)val1 && val2 == (int)val2) {
        run((int)val1, (int)val2);
    } else {
        run(val1, val2);
    }

    return 0;
}
