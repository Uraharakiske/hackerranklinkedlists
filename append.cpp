//insert sort code
#include<bits/stdc++.h>
using namespace std;
void swap(int *i, int *j){
    int temp;
    *i = temp;
    *i = *j;
    *j = temp;
}

void insert_sort_linkedLists(struct node** head){ //passing vector by reference
    struct node* current = (*head)->next;
    struct node* previous_node;
    if(head == nullptr|| head->next == nullptr){
        return;
    }
    else{
        // 3 cases
        // 3 2
        //   5 4 3 2 1
        // 11 5 17 7 13 - 5 11 17 7 13 - 
        while(current!=nullptr){
            struct node* looper = *head;
            int value = current->data;
            while(looper !=current){
                struct node* previous_looper;
                if(value <= looper->data){
                    previous_node->next = current->next;
                    current->next = looper;
                    current = previous_looper->next;
                    
                    break;
                }
                else{
                    previous_looper = looper;
                    looper = looper->next;
                }

                
                
            }
            previous_node =current;
            current = current->next;

        }
    }
    

}

void append(struct node** a, struct node** b){
    struct node* current = *a;
    if(*a == nullptr){
        *a = *b;
    }
    else{
        while(current->next != nullptr){
        
        current = current ->next;


        }
        current->next = *b;
    }    
    
    *b = nullptr;
    

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

