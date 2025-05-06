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

//logic for finding the min value
int find_min(){
    if(size==0){
        printf("the heap is empty\n");
        return -1;
    }
    return heap[0];
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

    printf("the minimum value is:%d\n",find_min());

    return 0;
}