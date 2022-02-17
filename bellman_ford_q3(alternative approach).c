#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

struct Edge{
    int src,dest,wt;
};

struct Graph{
    int V,E;
    struct Edge* edge;
};

struct Graph* createGraph(int V,int E){
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V=V;
    graph->E=E;
    graph->edge=(struct Edge*)malloc(graph->E*sizeof(struct Edge*));
    return graph;
}

void printSol(int dist[], int V){
    printf("Vertice\tDistance from source\n");
    for(int i=0;i<V;i++){
        printf("%d\t\t%d\n",i+1,dist[i]);
    }
}

void bellmanFord(struct Graph* graph, int S){
    int V=graph->V;
    int E=graph->E;

    int dist[V];
    for(int i=0;i<V;i++){
        dist[i]=INT_MAX;
    }
    dist[S]=0;


    for(int i=0;i<V-1;i++){
        for(int j=0;j<E;j++){

            int u = graph->edge[j].src;
            int v = graph->edge[j].dest;
            int weight=graph->edge[j].wt;

            if(dist[v]>dist[u]+weight){
                dist[v]=dist[u]+weight;
            }

        }
    }

    for(int j=0;j<E;j++){

        int u = graph->edge[j].src;
        int v = graph->edge[j].dest;
        int weight=graph->edge[j].wt;

        if(dist[v]>dist[u]+weight){
            printf("Negative Edge Cycle Exists\n");
            break;
        }

    }

    printSol(dist,V);


}

int main(){
    int V,E,S;
    printf("Enter number of vertices in graph\n");
    scanf("%d",&V);
 
    printf("Enter number of edges in graph\n");
    scanf("%d",&E);
 
    printf("Enter your source vertex number\n");
    scanf("%d",&S);

    struct Graph* graph = createGraph(V,E);
    for(int i=0;i<E;i++){
        printf("\nEnter edge %d properties Source, destination, weight respectively\n",i+1);
        scanf("%d",&graph->edge[i].src);
        scanf("%d",&graph->edge[i].dest);
        scanf("%d",&graph->edge[i].wt);
    }

    bellmanFord(graph,S);

}