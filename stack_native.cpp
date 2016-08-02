/*
  STACK IMPLEMENTATION FROM SCRATCH
  WITH DYNAMIC MEMORY ALLOCATION (LINKED LIST)
  
  TIME COMPLEXITY:
    PUSH(), POP(), TOP(), EMPTY() : O (1)
*/

#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct node{
    int data;
    struct node *prev;
} node;

struct stack{
    private:
    node *node_top = NULL;
    
    public:
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
