#include <iostream>


#include "MyStack.hpp"
#include "MyStack.cpp"

#define N 3960

void Multipliers(int i, int i1, MyStack<int> *pStack);

int main() {
    MyStack<int> *stack = new MyStack<int>;
    bool q = stack->empty();
    std::cout << q << '\n';
    stack->push(1);
    stack->push(2);
    stack->push(3);
    stack->push(4);
    MyStack<int> *stack1 = stack;
    q = stack1->empty();
    std::cout << q << '\n';
    std::cout << stack1->top_inf() << '\n';
    stack1->pop();
    std::cout << stack1->top_inf() << '\n';
    std::cout << '\n';



    q = stack->empty();
    std::cout << q << '\n';
    std::cout << stack->top_inf() << '\n';
    stack->pop();
    std::cout << stack->top_inf() << '\n';
    stack->pop();
    stack->pop();
    stack->pop();
    q = stack->empty();
    std::cout << q << "\n\n\n";

    Multipliers(N, 2, stack);
    std::cout << N << '=';
    stack->print();
    stack->reverse();
    std::cout << N << '=';
    stack->print();

    return 0;
}

void Multipliers(int n, int div, MyStack<int> *stack) {
    if (n == 1) return;
    if (n % div == 0) {
        stack->push(div);
        Multipliers(n / div, div, stack);
    } else if (div == 2)
        Multipliers(n, div + 1, stack);
    else
        Multipliers(n, div + 2, stack);
}
