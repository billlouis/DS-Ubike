#include "./graph.h"
#include <climits>
#include <iostream>
Graph::Graph(int Vertices , int Edges){
    V = Vertices;
    E = 2*Edges; 
    edge = new Edge[E];
    for(int i =0; i < E; i++){
        edge[i].src = 0;
        edge[i].dest = 0;
        edge[i].weight = 0;
    }
}
int Graph::getE(){
    return E;
}
int Graph::getV(){
    return V;
}
int minDistance(int dist[], bool sptSet[], int V)
{
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
 
    return min_index;
}
// void printSolution(int dist[], int V)
// {
//     cout << "Vertex \t Distance from Source" << endl;
//     for (int i = 0; i < V; i++)
//         cout << i << " \t\t\t\t" << dist[i] << endl;
// }
int* dijkstra(int **graph, int src, int V)
{
    int *dist = new int(V);
    bool *sptSet = new bool(V);
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;
    // Distance of source vertex from itself is always 0
    dist[src] = 0;
 
    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum distance vertex from the set of
        // vertices not yet processed. u is always equal to
        // src in the first iteration.
        int u = minDistance(dist, sptSet, V);
 
        // Mark the picked vertex as processed
        sptSet[u] = true;
 
        // Update dist value of the adjacent vertices of the
        // picked vertex.
        for (int v = 0; v < V; v++)
 
            // Update dist[v] only if is not in sptSet,
            // there is an edge from u to v, and total
            // weight of path from src to  v through u is
            // smaller than current value of dist[v]
            if (!sptSet[v] && graph[u][v]
                && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }
    //delete [] sptSet;
    return dist;
}

void floydWarshall(int ** dist, int V)
{
     
    int i, j, k;
 
    /* Add all vertices one by one to
    the set of intermediate vertices.
    ---> Before start of an iteration,
    we have shortest distances between all
    pairs of vertices such that the
    shortest distances consider only the
    vertices in set {0, 1, 2, .. k-1} as
    intermediate vertices.
    ----> After the end of an iteration,
    vertex no. k is added to the set of
    intermediate vertices and the set becomes {0, 1, 2, ..
    k} */
    for (k = 0; k < V; k++) {
        // Pick all vertices as source one by one
        for (i = 0; i < V; i++) {
            // Pick all vertices as destination for the
            // above picked source
            for (j = 0; j < V; j++) {
                // If vertex k is on the shortest path from
                // i to j, then update the value of
                // dist[i][j]
                if (dist[i][j] > (dist[i][k] + dist[k][j])
                    && (dist[k][j] != INT_MAX
                        && dist[i][k] != INT_MAX))
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
 
    // Print the shortest distance matrix
  //  printSolution(dist, V);
}
 
/* A utility function to print solution */
void printSolution(int **dist, int V)
{
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}
void mergeUser(vectors<User> &vec, int left, int mid, int right){
   
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;
    User* leftArray = new User[subArrayOne];
    User* rightArray = new User[subArrayTwo];
    for(int i = 0; i < subArrayOne; i++){
        leftArray[i] = vec[left+i];
    }
    for(int i = 0; i < subArrayTwo; i++){
        rightArray[i] = vec[mid + 1 + i];
    }
    // for(int i = 0; i < leftArray.Size(); i++){
    //     cout << leftArray[i].id <<" "<< leftArray[i].start_time << endl;
    // }
    // for(int i = 0; i < rightArray.Size(); i++){
    //     cout << rightArray[i].id <<" "<< rightArray[i].start_time << endl;
    // }
    // cout << leftArray.Size() << " ";
    // cout << rightArray.Size() << endl;
    int idxLeft = 0, idxRight =0, idxMerge = left;
    while(idxLeft < subArrayOne && idxRight < subArrayTwo){
        if(leftArray[idxLeft].start_time <= rightArray[idxRight].start_time){
            if(leftArray[idxLeft].start_time == rightArray[idxRight].start_time){
                if(leftArray[idxLeft].id < rightArray[idxRight].id){
                   vec[idxMerge] = leftArray[idxLeft];
                   idxLeft++;
                }
                else {
                   vec[idxMerge] = rightArray[idxRight];
                   idxRight++;
                }
            }
            else {
               vec[idxMerge] = leftArray[idxLeft];
               idxLeft++;
            }
        }
        else {
           vec[idxMerge] = rightArray[idxRight];
           idxRight++;
        }
       idxMerge++;
    }
    while(idxLeft<subArrayOne){
       vec[idxMerge] = leftArray[idxLeft];
        idxLeft++;
        idxMerge++;
    }
    while(idxRight<subArrayTwo){
       vec[idxMerge] = rightArray[idxRight];
        idxRight++;
        idxMerge++;
    }
    delete [] leftArray;
    delete [] rightArray;
}

void mergeSortUser(vectors<User> &vec, int front, int end){

    if(front >= end) return;
    int mid = (front + end) /2;
    mergeSortUser(vec, mid+1, end);
    mergeSortUser(vec, front, mid);
    mergeUser(vec, front, mid, end);

}