/*
  STACK IMPLEMENTATION FROM SCRATCH
  WITH DYNAMIC MEMORY ALLOCATION (LINKED LIST)
  
  TIME COMPLEXITY:
    PUSH(), POP(), TOP(), EMPTY(), SWAP() : O (1)
    SIZE() : O (N)
*/

#include <iostream>
#include <cstdlib>

using namespace std;

struct node{
    int data;
    struct node *prev;
};

struct stack{
    node *node_top = NULL;
    
    void push(int z)
    {
        node *curr = (node*)malloc(sizeof(node));
        curr -> data = z, curr -> prev = node_top;
        node_top = curr;
    }
    
    void pop()
    {
        node *temp = node_top -> prev;
        free(node_top);
        node_top = temp;
    }
    
    int empty()
    {
        return (node_top == NULL ? 1 : 0);
    }
    
    int top()
    {
        return (node_top -> data);
    }
    
    unsigned int size()
    {
        unsigned int n = 0;
        node *curr = node_top;
        while(curr != NULL){
            n++;
            curr = curr -> prev;
        }
        return n;
    }
    
    void swap(stack &s)
    {
    	node *tmp = s.node_top;
    	s.node_top = this -> node_top, this -> node_top = tmp;
    }
};

int main(void) {
    int n = 5, x;
    stack s;
    while(n--){
        cin >> x;
        s.push(x);
    }
    while(!s.empty()){
        cout << s.top() << endl;
        s.pop();
    }
	return 0;
}
