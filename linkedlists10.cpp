//insert sort code
#include<bits/stdc++.h>
using namespace std;
void swap(int *i, int *j){
    int temp;
    *i = temp;
    *i = *j;
    *j = temp;
}

void insert_sort((vetor<int> &(arr)){ //passing vector by reference
    
    for(int i =1 ; i < arr.size(); i++){
        int  value = arr[i];
        int hole = i;
        while(hole>0 && arr[i-1]){
            arr[i]=arr[i-1];
            hole = hole-1;
        }
        arr[hole] = value;
    }

}




int main(){
    vector<int> v;
    while(true){
        int i;
        cin >> i;
        if(i == "endl")
    }
}