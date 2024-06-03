#include <iostream>
#include <stack>
using namespace std;

// Function to convert decimal to binary using stack
stack<int> decimalToBinary(int decimal) {
    stack<int> binaryStack;

    // Special case for 0
    if (decimal == 0) {
        binaryStack.push(0);
        return binaryStack;
    }

    while (decimal > 0) {
        int remainder = decimal % 2;
        binaryStack.push(remainder);
        decimal /= 2;
    }

    return binaryStack;
}

int main() {
    int decimalNumber;
    cout << "Enter a decimal number: ";
    cin >> decimalNumber;

    stack<int> binaryStack = decimalToBinary(decimalNumber);

    cout << "Binary representation of " << decimalNumber << " is: ";
    while (!binaryStack.empty()) {
        cout << binaryStack.top();
        binaryStack.pop();
    }
    cout << endl;

    return 0;
}
