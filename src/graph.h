#ifndef graph_h
#define graph_h 1
#include "iostream"
using namespace std;
#include "./vectors.h"
#include "./user.h"
#include "./bike.h"
struct Edge {
    int src, dest, weight;
    };

class Graph {
    
    private :
    int V, E;
    
    public :
    Graph() : V(1), E(1), edge(new Edge[1]){}
    Graph(int Vertices, int Edges);
    int getV();
    int getE();
    Edge* edge;
    
}; 
int* dijkstra(int **graph, int src, int V);
void printSolution(int ** dist, int V);
void floydWarshall(int ** dist, int V);
int minDistance(int dist[], bool sptSet[], int V);
void mergeU(vectors<User> &vec, int front, int mid, int end);
void mergeB(vectors<Bike> &vec, int front, int mid, int end);

void mergeSortUser(vectors<User> &vec, int front, int end);
void mergeSortBike(vectors<Bike> &vec, int front, int end);
#endif
