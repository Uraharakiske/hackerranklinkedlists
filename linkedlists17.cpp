//shuffle merge
//front back split:
//insert sort code
#include<bits/stdc++.h>
using namespace std;
#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node* next;
};
int length_linkedList(struct node* head){
    struct node* current = head;
    int count;
    while(current != nullptr){
        current = current ->next;
        count++;
        
    }
    return count;
}
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
void print_in_reverse(struct node* head){
    vector<int> arr;
    struct node* current = head;
    while(current!=nullptr){
        int data = current->data;
        arr.push_back(data);
        current = current->next;
    }
    for(int i= arr.size()-1;i=0;i--){
        cout<< arr[i];
    }
}
void SortedInsert(struct node** headRef, struct node* newNode){
    int value = newNode->data;
    struct node* current = *headRef;
    if(*headRef == nullptr){
        *headRef = newNode;
    }
    else{
        while(current!=nullptr){
            int currentValue = current->data;
            if(currentValue<=value){
                current = current->next;
            }
            else{
                newNode->next = current->next;
                current->next = newNode;
                break;
            }
        }

    }
    
}

void frontBackSplit(struct node** head,struct node** list1,struct node** list2;){
    
    int length = length_linkedList(*head);
    struct node* current = *head;
    
    if(length%2 == 0 ){
        if(length == 2){
            *list1 = *head;
            *list2 = *head -> next;
            *list1->next = nullptr;
        }
        else If(length == 0){
            *list1 = nullptr;
            *list2 = nullptr;

        }
        else{
            int i = 1;
            while(i<= length/2){
                current = current->next;
                i++;
            }
            *list1 = current;
            *list2 = current->next;
            *list1->next = nullptr;
        }

    }
    else{
        if(length == 1){
            *list1 = *head;
            *list2 = nullptr;
        }
        else{
            int i = 1;
            while(i< (length/2 +1)){
                current = current->next;
            }
            *list1 = current;
            *list2 = current->next;
            *list->next = nullptr;
        }
    }

}

void RemoveDuplicates(struct node*head){
    struct node* current = *head->next;
    struct node* previous = *head;
    while(current !=  nullptr){
        if(current->data == previous->data){
            previous->next = current->next;
            struct node* free_node = current;
            
            current = previous->next;
            free(free_node);
        }   
        else{
            current = current->next;
            previous = previous->next;
        }     
    }
    
}
void moveNode(struct node** list1, struct node** list2){
    if(*list2 !=nullptr){
        struct node* current = *list2;
        *list2 = *list2->next;
        current -> next = *list1;
        *list1 = current;
    }
    else{
        cout<< "error";
    }
    

}
void alternatingSplit(struct node** head, struct node** head1, struct node** head2){
    // a b a b a
    // a a a    b b
    // its given in the question that the list can be in any order and it turns out be convenient if the linked list are in reverse order
    // movenode can be used
    struct node* current = *head;
    while(current!=nullptr){
        
        moveNode((head1),&(current));
        if(current!=nullptr){
            moveNode((head2),&(current));
        }
        


    } // takes care of emty list and everything
}
// 1,3,5,7   2,4,6,8
// 1,3,5,7   2,4,
// 1,3       2,4,6
// /         /
// 1         2
//1          /
void shuffle_merge(struct node** head1, struct node** head2,struct node** head){
    struct node* current = *head;
    struct node* current1 = *head1;
    struct node* current2 = *head2;
    while(current1!= nullptr || current2!=nullptr ){
        moveNode(&(current),head1);
        moveNode(&(current),head2));
        
    }
    if(current1 == nullptr){
        if(current2!=nullptr){
            while(current2!=nullptr){
                moveNode(&(current), currrent2);
            }
        }
        else{
            return;
        }

    }
    else{
        if(current1!=nullptr){
            while(current1!=nullptr){
                moveNode(&(current), currrent1);
            }
        }
        else{
            return;
        }
    }
    reverse_linkedlists(head);
}





int main(){
    vector<int> v;
    while(true){
        int i;
        cin >> i;
        if(i == "endl"){

        }
    }
}