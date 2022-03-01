// Copyright 2021 qqq <polyakovdd@student.bmstu.ru>


#ifndef CODE_MY_STACK_HPP
#define CODE_MY_STACK_HPP
//Шаблонный класс MyStack на основе односвязного списка.
// модуль подключен


//Шаблонный класс ListNode (узел односвязного списка)
template<class INF, class FRIEND>
class ListNode                //узел списка
{
private:
    INF d;                        //информационная часть узла
    ListNode *next;         //указатель на следующий узел списка
    ListNode() { next = nullptr; } //конструктор
    friend FRIEND;
};

//Шаблонный класс MyStack на основе односвязного списка.
template<class INF>
class MyStack {
    typedef class ListNode<INF, MyStack<INF> > Node;
    Node *top;
public:
    MyStack();
    ~MyStack();
    MyStack(MyStack* stack);
    bool empty();
    void push(INF n);
    bool pop();
    INF top_inf();
    void reverse();
    void print();
    MyStack &operator=(const MyStack<INF> *stack){
        ~this;
        if (stack!= this)
        {
            Node* node = top;
            while (node != nullptr) {
                stack->push(node->d);
                node = node->next;
            }
        }
    }
};





#endif //CODE_MY_STACK_HPP
