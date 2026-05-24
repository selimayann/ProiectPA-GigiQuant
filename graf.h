#ifndef GRAPH_H
#define GRAPH_H
#include "fractie.h"

typedef struct Graph{
    int V;
    int E;
    int **a;
}Graph;

Graph* createGraph(int V);
void addEdge(Graph *g, int v1, int v2);
void deleteGraph(Graph *g);
int gradIesire(Graph *g, int nod);
fractie probKDays(Graph *g, int start, int target, int K);

#endif

