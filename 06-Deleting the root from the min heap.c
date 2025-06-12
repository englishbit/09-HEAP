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

//logic for deleting the root
void delete(){
    if(size==0){
        printf("the heap is empty\n");
        return;
    }
     
     heap[0]=heap[size-1];
     size--;

     int index=0;
     while(index<size){
        int left=(2*index)+1;
        int right=(2*index)+2;
        int smallest=index;
        if(left<size && heap[left]<heap[smallest]){
            smallest=left;
        }
        if(right<size && heap[right]<heap[smallest]){
            smallest=right;
        }
        if(smallest!=index){
            int temp=heap[index];
            heap[index]=heap[smallest];
            heap[smallest]=temp;
            index=smallest;
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

    delete();

    printf("the heap after deleting\n");
    for(int i=0;i<size;i++){
        printf("%d ",heap[i]);
    }
    return 0;
}
