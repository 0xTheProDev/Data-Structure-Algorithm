/*
  A PROGRAM TO CHECK IF A GROUP OF PARENTHESIS ARE PERFECT, i.e.,
  THEY ARE IN PAIR OF AN OPEN AND A CLOSE PARENTHESIS
  
  DATA-STRUCTURE : STACK (C++ STL)
*/

#include <iostream>
#include <cstdio>
#include <stack>
#define stack_c stack<char>
using namespace std;

bool isVal(stack_c &S1, stack_c &S2);
bool isPer(stack_c &S)
{
    if(S.empty())
        return false;
    stack_c O;
    return isVal(S, O);
}

int main() {
	stack_c st;
	char c;
	while((c = getchar()) != EOF)
	    if(c == '(' || c == ')')
	        st.push(c);
	cout << (isPer(st) ? "True" : "False") << endl;
	return 0;
}

bool isVal(stack_c &S1, stack_c &S2)
{
    if(S1.empty())
        return S2.empty();
    char t = S1.top();
    S1.pop();
    if(t == '('){
        if(S2.empty())
            return false;
        else{
            S2.pop();
            return isVal(S1, S2);
        }
    }
    else{
        S2.push(')');
        return isVal(S1, S2);
    }
}
