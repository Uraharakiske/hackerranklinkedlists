// recuresive reverse;
#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node* next;
};
void insert_node_at_tail(struct node** head,int data){
    //struct node* current = (struct node*) malloc(sizeof(struct node));
    //current->next = nullptr;
    //current->data = data;
    //struct node* temp = *head;
    //while(temp!=nullptr){
    //    temp = temp->next;
    //}
    //temp = current;(This is probably the error)
    struct node* current = (struct node*) malloc(sizeof(struct node));
    current->next = nullptr;
    current->data = data;
    if(*head==nullptr){
        *head = current;
    }
    else{
        struct node* temp;
        temp = *head;
        while((temp->next)!=nullptr){
           temp = temp->next;
        }
        temp->next=current;
    }
}

void print_linkedlist(struct node* head){
    struct node* current = head;
    while(current!=nullptr){
        cout<< (current->data)<<'\n';
        current = current->next;
    }

}
void free_linkedlist(struct node **head){
    
    while(*head!=nullptr){
        struct node* temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}
void insert_node_at_position(struct node** head,int data,int position){
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = data;
    struct node* temp = *head;
    int count = position;
    if(count == 0 ){
        new_node->next = *head;
        *head = new_node;
    }
    else{
        while(count-1){
            
            temp=temp->next;
            count--;
        }
        new_node->next = temp->next;
        temp->next = new_node;
        
    }
}
struct node* delete_node_at_position(struct node** head, int position){
    
    /*
    sample example 1.0| 1| 2| 3| 4| 5| remove the 2nd node and then do it for the zeroth node
    sample example 2. 0 remove the zeroth node to give an emty list
    1.2 head is changed;
    1.1 head doesnt change
    2.1 head is nullptr
    to delete a node of linked list (suppose i want to delete 2
    current is assigned to 0
    0->1->2 (1 is previous node free(1->next))
    */
    struct node* current = *head;
    if((*head) -> next == nullptr){
        *head = nullptr;
    }
    else{   
        if(position == 0){
            *head = (*head) -> next;
            free(current);
        }
        else{
            for(int i=0;i<position-1;i++){
                current = current->next;
            }
            struct node* temp = current;
            // temp is pointing to 1;
            // we need to link 1 to three
            temp = temp->next; // pointing to 2;
            current->next = temp->next; //current pointing to 3;
            free(temp);            
        }
    }
}
void recursive_reverse_linkedlists(struct node** head){
    //exit condition
    if(head == nullptr){
        return;
    }
    struct node* first;
    struct node* rest;
    first = *head;
    rest = (first)->next
    if(rest->next == nullptr){
        return;
    }
    recursive_reverse_linkedlists(&rest);
    first->next->next = first;
    first->next = nullptr;
    *headref = rest; 
}


int main(){
    int count;
    cin>> count;
    struct node* head =nullptr;
    for(int i=0;i<count;i++){
        int item;
        cin >> item;
        insert_node_at_tail(&(head),item);

    }
    recursive_reverse_linkedlists((&head));
    print_linkedlist(head);
    free_linkedlist(&(head));
    return 0;
}