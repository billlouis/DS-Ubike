#ifndef graph_h
#define graph_h 1
#include "iostream"
using namespace std;

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
void dijkstra(int **graph, int src, int V);
void printSolution(int dist[], int V);
int minDistance(int dist[], bool sptSet[], int V);
#endif
