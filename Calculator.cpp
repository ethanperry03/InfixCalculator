using namespace std;
#include <iostream>
#include "Stack.h"
#include "cmath"
#include "iomanip"

class Calc {
    // this stack holds all the number form the expression
    Stack<float> nums;
    // this holds all the operators from the expression
    Stack<char> ops;
    // this will add the input operator to the stack but in the process
    // evaluate the expression if necessary
    void addOp(char);
    // this returns the precedence value from the given input operator
    int prec(char);
    // this returns the evaluation of part of the expression
    float evaluate(float, float, char);
public:
    // public constructor
    Calc();
};

/* Constructor
 * Creates a Calc object that will store the user inputted expression ending with a '='
 * and then will accurately calculate the result and display it to 3 decimal place precision.
 * PRE: Nothing exists prior.
 * POST: The expression is evaluated and displayed to the user so nothing is done after that.
 */
Calc::Calc(){
    // declare input temp variables
    char inChar;
    float inNum;

    // prompter
    cout << ">>";
    // get the first num
    cin >> inNum;
    // push it onto the number stack
    nums.push(inNum);

    // get input character (operator)
    cin.get(inChar);

    // while there is not an = sign (sentinel value for input)
    while(inChar != '='){
        // push char in correct order for the operator stack
        addOp(inChar);

        // get num and push
        cin >> inNum;
        nums.push(inNum);

        // get new input then loop
        cin.get(inChar);
    }

    // this is to ensure you do any remaining operations if op stack is not empty
    while(!ops.isEmpty()) {
        // do the correct operation designated by the operator
        addOp(ops.top());
        // pop that operator
        ops.pop();
    }

    // this outputs the result with fixed 3 decimals
    cout << fixed << showpoint << setprecision(3) << nums.top();
}

/* addOp
 * When an operator character is entered in the expression, this is called. The stack
 * implementation allows for the postfix to be calculated as the program goes and this
 * method, in conjunction with evaluate(), correctly orders the operators as they are
 * entered while evaluating parts of the expression.
 * char in: this is the input character that is a math operator from the input expression.
 * PRE: The expression may have been partly entered or just starting but regardless, this
 * method will add the given 'in' operator to the stack.
 * POST: The ops stack is now up-to-date to allow the postfix operations to work thus far,
 * and if evaluate() was called, the nums stack has been updated.
 */
void Calc::addOp(char in){
    // if the stack of operators is empty or the new op has higher prec
    if (ops.isEmpty() || prec(ops.top()) < prec(in)) {
        // push the operator onto the ops stack
        ops.push(in);
    }
    // else you need to do some shuffling around
    else {
        // while there are still operators in your stack AND top has higher prec
        while(!ops.isEmpty() && prec(ops.top()) >= prec(in)) {
            // store the top of the number stack then pop it
            float right = nums.top();
            nums.pop();

            // store the new top of the stack and then pop that
            float left = nums.top();
            nums.pop();

            // get the result of the evaluate (left *op* right = ?)
            float result = evaluate(left, right, ops.top());

            // store result at the top of the number stack
            nums.push(result);

            // pop the operator that was just used from ops stack, then loop
            ops.pop();
        }
        // at the end of this, you push the input operator to the stack
        ops.push(in);
    }
}

/* evaluate()
 * This method reads in two floats and the operator that is to be done to them. It will
 * then return the evaluated result of the input expression.
 * float a, b: These are the two value of the subexpression being evaluated.
 * char op: This is the character corresponding to the operation that is to be done
 * to the input floats.
 * PRE: The expression or subexpression has not be evaluated yet.
 * POST: The result has been accurately calculated and returned as a float.
 */
float Calc::evaluate(float a, float b, char op) {
    float val = 0;
    switch(op) {
        // if character is exp, exponentiate
        case '^':
            val = pow(a, b);
            break;
        // if *, multiply
        case '*':
            val = a * b;
            break;
        // if /, divide
        case '/':
            val = a / b;
            break;
        // if mod, do float modular div
        case '%':
            val = fmod(a, b);
            break;
        // if +, add
        case '+':
            val = a + b;
            break;
        // if -, sub
        case '-':
            val = a - b;
            break;
        default:
            val = 0;
            break;
    }
    // return the value of the operation done
    return val;
}

/* prec()
 * This method returns the precedence of a given operator as an integer. ^ has the highest
 * precedence, followed by *, %, / on the next tier, and below that is +, -. This is useful
 * in the addOp method when you wish to know the relative precedence of the top operator of
 * the op stack and the input character.
 * char c: This is the char input that is an operator of the expression.
 * return: Integer corresponding to precedence level.
 * PRE: The given character corresponding to an operation is passed in.
 * POST: The relative precedence level is returned as an int.
 */
int Calc::prec(char c) {
    // default value is 0
    int val;

    // if it is exp
    if (c == '^'){
        val = 3;
    }
    // else if it is a multiplicative operator
    else if (c == '*' || c == '/' || c == '%'){
        val = 2;
    }
    // else if it is additive
    else if (c == '+' || c == '-') {
        val = 1;
    }
    // default val = 0
    else {
        val = 0;
    }
    // return the precedence value
    return val;
}

int main() {

    // run the calculator
    Calc c;

    return 0;
}