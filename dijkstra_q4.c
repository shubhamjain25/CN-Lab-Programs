#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include<stdbool.h>  

int V;

int getMinDistance(int dist[], bool flag[], int n){
    int mi=0,md=INT_MAX;
    for(int i=0;i<n;i++){
        if(!flag[i]&&dist[i]<md){
            md=dist[i];
            mi=i;
        }
    }
    return mi;
}

void printSol(int dist[], int src, int n){
    printf("From\tTo\tDistance\n");
    for(int i=0;i<n;i++){
        if(i!=src){
            printf("%d\t%d\t%d\n",src,i,dist[i]);
        }
    }
}

void dij(int graph[V][V], int src, int n){
    int dist[n];
    bool flag[n];
    for(int i=0;i<n;i++){
        dist[i]=INT_MAX;
        flag[i]=false;
    }

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         printf("%d ",graph[i][j]);
    //     }
    //     printf("\n");
    // }

    dist[src]=0;
    for(int i=0;i<n-1;i++){
        
        int u = getMinDistance(dist,flag,n);
        flag[u]=true;

        // printf("u   v   gp  dist\n");
        for(int v=0;v<n;v++){
            // printf("%d  %d  %d  %d\n",u,v,graph[u][v],dist[u]);
            if(!flag[v]&&dist[u]!=INT_MAX&&graph[u][v]&&graph[u][v]+dist[u]<dist[v]){
                dist[v]=graph[u][v]+dist[u];
                // printf("\n DISTANCE UPDATED for %d equals %d\n",v,dist[v]);
            }

        }

    }

    printSol(dist,src,n);
}

int main(){

    int v,src;
    printf("Enter total nodes in the graph: ");
    scanf("%d",&v); 
    int graph[v][v];
    printf("Enter cost matrix of the graph: \n");
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            scanf("%d",&graph[i][j]);    
        }
    }
    do{
        printf("Enter source node in the graph: ");
        scanf("%d",&src);
    }while(src<0||src>=v); 

    V=v;
    dij(graph,src,v);

}