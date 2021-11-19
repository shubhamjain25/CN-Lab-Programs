#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>

#define MIN(x,y) x>y?y:x

void main(){
    int bs,or,n,i;
    printf("Enter bucket size: ");
    scanf("%d",&bs);
    printf("Enter output rate: ");
    scanf("%d",&or);
    printf("Enter no of frames to be sent: ");
    scanf("%d",&n);
    int f[n];
    for(int i=0;i<n;i++){
        printf("Enter frames to be sent at second %d: ",i+1);
        scanf("%d",&f[i]);
    }

    int rem=0,drop=0;
    printf("second  recieved  sent  dropped  remained \n");
    for(i=0;i<n;i++){
        printf("%d\t%d\t",i+1,f[i]);
        printf("%d\t",MIN(rem+f[i],or));
        int x = rem+f[i]-or;
        if(x>0){
            if(x>bs){
                drop=x-bs;
                rem=bs;
            }
            else{
                drop=0;
                rem=x;
            }
        }
        else{
            rem=0;
            drop=0;
        }
        printf("%d\t%d\n",drop,rem);
    }

    drop=0;
    while(rem!=0){
        printf("%d\t%d\t",++i,0);
        if(rem<=or){
            printf("%d\t",rem);
            rem=0;    
        }
        else{
            printf("%d\t",or);
            rem=rem-or;
        }
        printf("%d\t%d\n",drop,rem);
    }
}