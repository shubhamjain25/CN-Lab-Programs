#include<stdio.h>

struct node {
    int dist[20];
    int from[20];

}rt[10];

int main() {
    int costmat[20][20];
    int nodes, i, j, k, count = 0;
    printf("\nEnter the number of nodes : ");
    scanf("%d", &nodes); //Enter the nodes

    printf("\nEnter the cost matrix :\n");
    for (i = 0; i < nodes; i++) {
        for (j = 0; j < nodes; j++) {
            scanf("%d", & costmat[i][j]);
            costmat[i][i] = 0;
            rt[i].dist[j] = costmat[i][j];
            rt[i].from[j] = j;
        }
    }
    
    do {
        count = 0;                          

        //We are checking for all the nodes.
        //The significance of count is that let's say if there is a negative edge which minimised the distance b/w two vertices
        //Now all the adjacent vertices distance may or may not be changed, and thereby we check the whole matrix again 
        //Till we reach a state where no additional change can be made to the distances
        //And count in that case will not incremnent. 


        for (i = 0; i < nodes; i++)         //traversal to each source node 
            for (j = 0; j < nodes; j++)     //traversal to each destination node
                for (k = 0; k < nodes; k++) //traversal to all intermediate nodes possible between source & destination
                    if (rt[i].dist[j] > costmat[i][k] + rt[k].dist[j]) {
                        rt[i].dist[j] = rt[i].dist[k] + rt[k].dist[j];
                        rt[i].from[j] = k;
                        count++;
                    }
        printf("Count is greater than 0\n");
    } while (count != 0);
    
    for (i = 0; i < nodes; i++) {
        printf("\n\n For router %d\n", i + 1);
        for (j = 0; j < nodes; j++) {
            printf("\t\nnode %d via %d Distance %d", j + 1, rt[i].from[j] + 1, rt[i].dist[j]);
        }
    }
    
    printf("\n\n");
}