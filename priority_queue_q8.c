#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define SIZE 5

int f=-1;
int r=-1;
int q[SIZE];

int isFull(){
    return r==SIZE-1?1:0;
}

int isEmpty(){
    return r==-1?1:0;
}

void enqueue_element(){
    if(isFull()){
        printf("Queue already full\n");
        return;
    }
    int el,i;
    printf("Enter the element you want to enter: ");
    scanf("%d",&el);
    if(f==-1&&r==-1){
        f=0;
        q[++r]=el;
    }
    else{
        for(i=0;i<=r;i++){
            if(el<q[i]){
                break;
            }
        }
        for(int j=r+1;j>i;j--){
            q[j]=q[j-1];
        }
        q[i]=el;
        ++r;
    }
}

void display(){
    if(isEmpty()){
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements are: ");
    for(int i=0;i<=r;i++){
        printf("%d ",q[i]);
    }
    printf("\n");
}

void dequeue_element(){
    if(isEmpty()){
        printf("Queue is empty\n");
        return;
    }
    int el,i,flag=0;
    printf("Enter the element you want to delete: ");
    scanf("%d",&el);
    
    for(i=0;i<=r;i++){
        if(q[i]==el){
            flag=1;
            break;
        }
    }

    if(flag==0){
        printf("Element not present\n");
    }
    else{
        if(i==f&&f==r){
            f=-1;
        }
        else{
            for(int j=i;j<r;j++){
                q[j]=q[j+1];
            }
        }
        r--;
        printf("Element Deleted\n");
    }

}

void main(){
    int ch;
    do{
        printf("1.Enqueue  2.Dequeue   3.Display   4.Exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:enqueue_element();
                   break;
            case 2:dequeue_element();
                   break;
            case 3:display();
                   break;
            case 4:break;
            defaut:printf("Invalid Choice\n");

        }
    }while(ch!=4);
}
