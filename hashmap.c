/*
Write a program that reads a specified number of phone book entries, creating a hash map entry as needed, then reads name queries and outputs the matching entry from the phone book, if such entry exists.

Input Format

The first line of input will have an integer, denoting the number of entries in the phone book. Each entry consists of two lines:

a name.
a corresponding phone number to that name.
Each following line will be a name query. Read the queries until end-of-file!
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cs50.h"   // Contains defination for GetInt() and GetString()
#define N 101

typedef struct x{
    char name[256];
    unsigned int phone;
    struct x *next;
} node;

int hash(char k[256])
{
    int n = strlen(k), val = 0;
    for(int i = 0; i < n; i++)
        val += (i + 1) * (k[i] - 'b');
    return val % N;
}

node* add(node* head, node* temp)
{
    if(!head)
        return temp;
    head -> next = add(head -> next, temp);
    return head;
}
node* insert(node* head, char n[256], unsigned int p)
{
    node* new = (node*) malloc(sizeof(node));
    strcpy(new -> name, n);
    new -> phone = p, new -> next = NULL;
    if(!head)
        return new;
    head -> next = add(head -> next, new);
    return head;
}

unsigned int search(node* head, char n[256])
{
    if(!head)
        return 0;
    if(!strcmp(head -> name, n))
        return head -> phone;
    return search(head -> next, n);
}

int main(void)
{
    char n[256], *m;
    unsigned int p;
    int t = GetInt(), h;
    node* map[N] = {0};
    for(int i = 0; i < t; i++){
        scanf("%s %u", n, &p);
        h = hash(n);
        map[h] = insert(map[h], n, p);
    }
    getchar(), getchar();
    while(1){
        m = GetString();
        p = search(map[hash(m)], m);
        p ? printf("%s=%d\n", m, p) : printf("Not found\n");
    }
}
