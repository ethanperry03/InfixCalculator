/** ----- Ethan Perry - Program 5 - Calculator via. Stacks -----
 * Files:
 *      Stack.h - stores the class declaration of the templated, linked list,
 *      implementation of a stack. The below methods are all inherent to a Stack instance.
 *      Stack.cpp - This is the implementation of the linked list stack, as well as
 *      the implementation of the Stack class methods.
 *      Calculator.cpp - This stores the class declaration of the infix -> postfix -> result
 *      program (using the stacks from the Stack class) as well as the implementation of
 *      the Calc class. The user will input from this constructor and the result is
 *      displayed from that object instance.
 *
 * Description: This program uses stacks to take an expression from infix notation and,
 * without storing the postfix, evaluates the expression and returns the result. Using the
 * templated, linked list stack implementation from the Stack class, the program stores a
 * number stack and operator stack. The numbers stack simply reads in values in the same
 * order as the the infix expression but the operator stack (in tandem with the algorithm)
 * allow for expression ot be evaluated as the input is read in. Once the input is done and
 * the ops stack is empty (meaning all subexpressions are evaluated) the result lies
 * on the top of the nums stack, and that (and only that) is displayed to the user.
 *
 * Input: The user inputs their expression and the sentinel value of the input loop is a '='.
 * The user cannot enter any parenthesis or spaces so the expression is slightly limited.
 * At least one number must be entered for it to be valid input (10.3=). The input alternates
 * num, op, num, op, ... , num, =
 * The valid operators are:
 *         ^ - exponent.
 *   /, %, * - float division, float modulo division, multiplication.
 *      -, + - subtraction, addition
 * ex input: 1-2^5.1/4+199.99*0.00123=
 *
 * Output: Just the float result of the inputted expression is displayed to the user with
 * three decimal places of precision.
 */

using namespace std;
#include <iostream>

#ifndef P5_STACK_H
#define P5_STACK_H

// template type of the Nodes used in the linked list
template <class Type> struct Node {
    // stored the data of Type
    Type data;
    // stores a "next" pointer that points to the thing below it in the stack
    Node *below;
};

// template class definition
template <class Type>
class Stack {
    // this is the head pointer to the stack (also a top pointer)
    Node<Type> *head;
public:
    // constructor that is inline making an empty stack on creation
    Stack() {head = nullptr;};
    // creates a new node with param data and puts it onto the top of the stack
    void push(Type);
    // returns the value of the data at the top node (head)
    Type top() const;
    // pops whatever was at the top and reorients the head pointer
    void pop();
    // returns a bool (true if it is empty / false if not)
    bool isEmpty() const;
    // this is a basic display method that was used in debugging
    void display() const;
};

#endif //P5_STACK_H