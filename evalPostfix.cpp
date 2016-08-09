/*
  EVALUATING A POSTFIX EXPRESSION
  DATA-STRUCTURE: STACK
*/

#include<iostream>
#include <stack> 
#include<cstring>
#include<cmath>
using namespace std;

bool isOperator(char currentChar) {
    if (currentChar=='+' || currentChar=='-' || currentChar=='*' || currentChar=='/' || currentChar=='^') 
        return true;
    else
        return false;
}

void getValues(char postfix[], float value[]) {
    int i=0;
    char currentChar;
    //Traverse the postfix expresssion
    //Accept values of the variables 
    while(postfix[i]!='\0') {
        currentChar=postfix[i];
        if (!isOperator(currentChar)) {
            cout << "Enter value of " << currentChar << ": ";
            cin >> value[currentChar];
        }
        i++;
    }
}



float calculateOperandValues(float operand1, float operand2, char Operator) {
    if (Operator == '+')
        return operand1 + operand2;
    if (Operator == '-')
        return operand1 - operand2;
    if (Operator == '*')
        return operand1 * operand2;
    if (Operator == '/')
        return operand1 / operand2;
    if (Operator == '^')
        return pow(operand1,operand2);
}

float evaluatePostfix(char postfix[]) {
    stack<float> Stack; //stack
    char currentChar;
    int i=0;
    float result, operand1, operand2, value[200];

    getValues(postfix, value); //Get values of all variables present in the postfix expression and store in value
    
    while(postfix[i]!='\0') {
        currentChar = postfix[i];
        if (isOperator(currentChar)) {
            operand2 = Stack.top();
            Stack.pop();
            operand1 = Stack.top();
            Stack.pop();
            result = calculateOperandValues(operand1, operand2, currentChar);
            Stack.push(result);
        }
        else { //It is a variable 
            Stack.push(value[currentChar]);
        }
        i++;
    }
    return Stack.top(); //Final answer
}

//Function to check whether open and close braces match
bool checkParentheses(char infix[]) {
    int open=0, close=0, i=0;
    while (infix[i] != '\0') {
        if(infix[i] == '(')
            open++;
        if(infix[i] == ')') {
            close++;
            if (close>open)
                return false;
        }
        i++;
    }
    if(open==close)
        return true;
    else
        return false;
}

bool isValid(char currentChar) {
    return ( (currentChar>=65 && currentChar<=90) || (currentChar>=97 && currentChar<=122) || (currentChar>=40 && currentChar<=43) || currentChar==45 || currentChar==47 || currentChar==94);
}


//Validate String
//Allowed: a-z, A-Z, + - * / % ^ ( )
bool validate(char infix[]) {
    int i=0;
    while (infix[i] != '\0') {
        if (! isValid(infix[i]) ) 
            return false;  
        else 
            i++;
    }
    if (checkParentheses(infix) == false) {
        return false;
    }
    return true;
}

int priorityNumber(char Operator) {
    if (Operator=='^')
        return 0;
    if (Operator=='*' || Operator=='/')
        return 1;
    if (Operator=='+' || Operator=='-') 
        return 2;
    if (Operator=='(')
        return 3;
}

bool checkPriority(char currentOperator, char topOperator) {
    if (priorityNumber(currentOperator) < priorityNumber(topOperator))
        return true;
    else 
        return false;
}

bool isOperand(char currentChar) {
    return ( (currentChar>=65 && currentChar<=90) || (currentChar>=97 && currentChar<=122) );
}

void infix2Postfix(char infix[], char answer[]) {
    int i=0, j=0;
    char currentChar;
    char postfix[50]="";
    stack<char> operatorStack; //Operator stack
    while(infix[i]!='\0') {
        currentChar=infix[i];
        if ( isOperand(currentChar) ) {
            postfix[j]=currentChar;
            j++;
        }
        else  { //It is operator
            if (currentChar=='(') {
                operatorStack.push(currentChar);
                i++;
                continue;
            }

            if(operatorStack.empty() ) { 
                if (currentChar!=')') 
                    operatorStack.push(currentChar);
            }
            else { 
                if (checkPriority(currentChar,operatorStack.top()))  {
                    //Current operator has high precedence than the one on the top of the stack
                    operatorStack.push(currentChar);
                }
                else { 
               //Current operator has equal or less precedence than the one on the top of the stack
                    while (!operatorStack.empty()) {
                        if (operatorStack.top()=='(') {
                            operatorStack.pop(); 
                            break; 
                        }
                        postfix[j]=operatorStack.top();
                        j++;
                        operatorStack.pop(); 
                    } //End of while
                    if(currentChar!=')') 
                        operatorStack.push(currentChar);
                } //End of else 
            } //End of else
        }
        i++; //Point to next character of infix expression
    }//Traversing string

    //Transfer remaining items from stack to postfix string
    while(!operatorStack.empty()) {
        postfix[j]=operatorStack.top();
        operatorStack.pop();
        j++;
    }

    strcpy(answer,postfix);

} //End of function


int main() {
    char infix[50], postfix[50];
    float ans;
    cout << "Enter an infix expression without space. Use round brace to indicate priority. Only +, -, *, /, ^ symbols are allowed\n";
    cin >> infix;

   //Check whether open and closing braces match or not
    if (validate(infix) == false) {
        cout << "The expression contains a number, or an unwanted symbol, or the round braces do not match\n";
        return -1;
    }

    cout << "Infix expresion : " << infix << endl;

    infix2Postfix(infix,postfix);
    cout << "Postfix expression : " << postfix << endl;

    ans = evaluatePostfix(postfix);
    cout << "Answer: " << ans << endl;

   return 0;
}
