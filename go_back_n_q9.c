#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int main(){
    int ws,nf;
    printf("Enter the windowsize: ");
    scanf("%d",&ws);

    printf("Enter the total no of frames: ");
    scanf("%d",&nf);

    int i,inp[nf+1];
    for(i=1;i<=nf;i++){
        printf("Enter the frame data at %d: ",i);
        scanf("%d",&inp[i]);
    }
    
    printf("\nWith sliding window protocol the frames will be sent in the following manner (assuming no corruption of frames)\n\n");
    printf("After sending %d frames at each stage sender waits for acknowledgement sent by the receiver\n\n",ws);

    for(i=1;i<=nf;i++){
        printf("%d\n",inp[i]);
        if(i%ws==0){
            printf("ACK of above frames sent is received by user\n");
        }
    }

    if(nf%ws!=0){
        printf("ACK of above frames sent is received by user\n");
    }

    return 0;
}