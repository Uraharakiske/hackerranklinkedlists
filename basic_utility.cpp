#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node* node;
};
int length(struct node* head){
    int count = 0;
    struct node* current = head;
    while(current != nullptr){
        count++;
        current  = current->next;

    }
}
void push(struct node** head,int data;){
    struct node* new_node = struct node* (malloc(sizeof(struct node)));
    new_node -> data = data;
    
    new_node->next = *head;
    *head = new_node;
}

tail = *tail;
        