using namespace std;
#include <iostream>
#include "Stack.h"

/* push
 * This take the input data of Type, creates a temporary Node, stores the input
 * data inside of it, then pushes that node to the top of the stack.
 * PRE: The stack exists without the new input node being properly placed in the stack.
 * POST: The input data, now in a node, is at the top of the stack, and the rest of the.
 * old stack follows below it in the same order.
 */
template <class Type>
void Stack<Type>::push(Type input) {
    // create a temporary node pointer of type Type
    Node<Type> *temp = new Node<Type>;
    // put the correct data in the new pointer
    temp->data = input;
    // have the new node next point to the head (put it on top)
    temp->below = head;
    // reorient the head pointer to point to the new node
    head = temp;
}

/* top
 * This returns the data from the top of the stack. Whatever Node is at the top
 * is accessed and data is returned (assuming stack is not empty).
 * PRE: Stack exists.
 * POST: Stack exists in same order (const) and the top data is returned.
 */
template <class Type>
Type Stack<Type>::top() const {
    // if the stack is not empty
    if(this->head != nullptr) {
        // return the data at the top
        return (head->data);
    }
    // else {} ????
}

/* pop
 * This method takes whatever is at the top (of a valid stack), pops the Node
 * off and reorienting the stack to now contain the same data but with the top
 * Node not being on the top. The previous top that was popped is deallocated.
 * PRE: The stack exists.
 * POST: The stack exists in the same order but with the previous top item no longer.
 * being there and then top - 1 now being the currently top item.
 */
template <class Type>
void Stack<Type>::pop() {
    // create a temp Node pointer of Type to start at the top
    Node<Type> *temp = this->head;
    // if the stack is not empty
    if(!this->isEmpty()) {
        // make the head point to the item below the top item
        this->head = this->head->below;
        // delete the temp (aka the previous top item)
        delete temp;
    }
}

/* display
 * This methods shows you what value is pointing to where. Say your stack is
 * 1 on the top then 2, 3, 4, this method will output to the user the following:
 * 1 -> 2 -> 3 -> 4 -> end
 * It is a great way to be able to visualize the actual stack.
 * PRE: Stack exists.
 * POST: Stack exists in same order AND the above format is displayed to the user.
 */
template <class Type>
void Stack<Type>::display() const {
    // create a temp Node pointer to the head
    Node<Type> *temp = this->head;
    // loop through to show the linked list stack
    while(temp != nullptr) {
        // display the head data and then an arrow
        cout << temp->data << " -> ";
        // then display the data
        temp = temp->below;
    }
    // cout end to signify the stack is empty (or at the end)
    cout << "end" << endl;
}

/* isEmpty
 * Returns a bool that is true if the stack is empty and false otherwise.
 * return: bool ^.
 * PRE: Stack exists.
 * POST: Stack exists in same order and the correct bool is returned.
 */
template <class Type>
bool Stack<Type>::isEmpty() const {
    // if the head null?
    return (head == nullptr);
}

// these are necessary to declare what types of stacks are being used
template class Stack<char>;
template class Stack<float>;