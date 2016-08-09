/*
  A SIMPLE PROGRAM THAT CONVERTS AN POSTFIX EXPRESSION GIVEN BY USER INTO A INFIX EXPRESSION
  DATA-STRUCTURE : STACK
*/

#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool isOperator (char);

string prefix2Infix(string prefix)
{
    int i, n = prefix.length();
    stack<string> operand;
    string temp, op1, op2;
    while(i < n){
        temp = prefix[i];
        if(isOperator(prefix[i])){
            op1 = operand.top();
            operand.pop();
            op2 = operand.top();
            operand.pop();
            operand.push("(" + op2 + temp + op1 + ")");
        }
        else {
            operand.push(temp);
        }
        i++;
    }
    return operand.top();
}

int main() {
	string prefix, infix;
	cout << "Enter the Prefix Expression : ";
	cin >> prefix;
	cout << prefix << endl;
	infix = prefix2Infix(prefix);
	cout << "The equivalent Infix Expression is : " << infix << endl;
	return 0;
}

bool isOperator (char currentChar) {
    if (currentChar=='+' || currentChar=='-' || currentChar=='*' || 
        currentChar=='/' || currentChar=='^') 
        return true;
    else
        return false;
}
