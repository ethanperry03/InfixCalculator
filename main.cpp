using namespace std;
#include <iostream>
#include "Stack.h"

int main() {

//    Stack<char> s;
//
//    char c;
//    cout << ">>";
//    cin.get(c);
//
//    while(c != '\n') {
//        s.push(c);
//        cin.get(c);
//    }
//
//    s.display();

    Stack<int> k;

    int num = 1;
    int n;
    cin >> n;

    while(n != 0){
        if (n == 1) {
            k.push(++num);
        }
        else if (n == 2) {
            k.pop();
        }
        k.display();
        cin >> n;
    }

    return 0;
}
