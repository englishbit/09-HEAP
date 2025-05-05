#include<stdio.h>
#define MAX_SIZE 1000
int heap[MAX_SIZE];

int size=0;
//logic for inserting function

void insert(int val){

    //logic for special case
    if(size>=MAX_SIZE){
        printf("the heap is full\n");
        return;
    }

    heap[size]=val;
    int indx=size;
    size++;

    //logic for maintain the max heap property
    while(indx>0){
        int prnt_indx=(indx-1)/2;

        if(heap[indx]>heap[prnt_indx]){
            int temp=heap[indx];
            heap[indx]=heap[prnt_indx];
            heap[prnt_indx]=temp;
            indx=prnt_indx;
        }else{
            break;
        }
        
    }

}


//logic for finding the max value 
    int find_max(){
        if(size==0){
            printf("the heap is empty\n");
            return -1;
        }


        int max_val=heap[0];
        return max_val;

    
    }







int main(){
int x;
int q;
scanf("%d",&q);

//logic for special case
if(q<1){
    printf("Invalid input\n");
    return -1;
}

while(q--){
    scanf("%d",&x);
    insert(x);
}



//logic for printing the max heap
    for(int i=0;i<size;i++){
        printf("%d ",heap[i]);
    }

    

    printf("\n%d",find_max());

    return 0;
}