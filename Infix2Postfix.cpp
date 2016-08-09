/*
  A SIMPLE PROGRAM THAT CONVERTS AN INFIX EXPRESSION GIVEN BY USER INTO A POSTFIX EXPRESSION
  DATA-STRUCTURE : STACK
*/

#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

bool isValidChar(char);
bool isOperand(char);
bool isValidate(char[]);
int getPriority(char);
bool checkPriority(char, char);

void infx2Postfx(char infix[], char answer[]) {
    int i=0, j=0;      char currentChar;    char postfix[50]="";
    stack<char> operatorStack;
    while(infix[i]!='\0') 
    {
        currentChar = infix[i];
        if(isOperand(currentChar))
            postfix[j++] = currentChar;
        else {
            if(currentChar == '('){
                operatorStack.push(currentChar);
                i++;
                continue;
            }
            else if(operatorStack.empty() && currentChar != ')')
                operatorStack.push(currentChar);
            else {
                if (checkPriority(currentChar, operatorStack.top()))
                    operatorStack.push(currentChar);
                else {
                    while (!operatorStack.empty()) {
                        if (operatorStack.top() == '(') {
                            operatorStack.pop(); 
                            break; 
                        }
                        postfix[j++] = operatorStack.top();
                        operatorStack.pop();
                    }
                    if(currentChar != ')') 
                        operatorStack.push(currentChar);
                }
            } 
        }
        i++;
    }
    while(!operatorStack.empty()) {
        postfix[j++] = operatorStack.top();
        operatorStack.pop();
    }
    strcpy(answer,postfix); 
}

int main() {
	char infix[50], postfix[50];
	cout << "Enter the Infix Expression : ";
	cin >> infix;
	cout << infix << endl;
	if(!isValidate(infix)){
	    cout << "The supplied Expression contains Error!";
	    return -1;
	}
	infx2Postfx(infix, postfix);
	cout << "The equivalent Postfix Expression is : " << postfix << endl;
	return 0;
}

bool isValidChar(char c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||
            (c >= 40 && c <= 43) || c == 45 || c == 47 || c == 94);
}

bool isOperand(char c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

bool isValidate(char infx[])
{
    unsigned int i = 0, open = 0, close = 0;
    while(infx[i] != '\0'){
        if(!isValidChar(infx[i]))
            return false;
        if(infx[i] == '(')
            open++;
        else if(infx[i] == ')')
            close++;
        if(close > open)
            return false;
        i++;
    }
    if(open == close)
        return true;
    return false;
}

int getPriority(char x)
{
    switch(x){
        case '^' : return 0;
        case '*' : case '/' : return 1;
        case '+' : case '-' : return 2;
        case '(' : return 3;
        default: return 4;
    }
}

bool checkPriority(char cur, char top)
{
    return (getPriority(cur) < getPriority(top));
}
