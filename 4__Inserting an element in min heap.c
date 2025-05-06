#include<stdio.h>
#define MAX 10000
int heap[MAX];
int size=0;

//logic for inserting 
void insert(int val){



    if(size>=MAX){
        printf("the heap is full\n");
        return;
    }

    heap[size]=val;
    size++;

    int indx=size-1;
    int prnt;

    //logic for maintain the heap property
    while(indx>0){
         prnt=(indx-1)/2;
         if(heap[indx]<heap[prnt]){
            int temp=heap[indx];
            heap[indx]=heap[prnt];
            heap[prnt]=temp;
            indx=prnt;
         }else{
            break;
         }

    }

}

int main(){
    int n;
    scanf("%d",&n);
    if(n<1){
        printf("Invalid input\n");
        return -1;
    }

    int x;
    while(n--){
        scanf("%d",&x);
        insert(x);
    }

    //logic for printing the heap
    for(int i=0;i<size;i++){
        printf("%d ",heap[i]);
    }


    
    return 0;
}