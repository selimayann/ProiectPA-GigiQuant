#include <stdio.h>
#include <stdlib.h>
#include "fractie.h"
#include "graf.h"

Graph* createGraph(int V){

    Graph *g = (Graph*) malloc(sizeof(Graph));

    if(g == NULL) return NULL;

    g->V = V;
    g->E = 0;

    g->a = (int**) malloc(V * sizeof(int*));
    if (g->a == NULL) {
        free(g);
        return NULL;
    }

    for(int i = 0; i < V; i++){
        g -> a[i] = (int*) calloc(g->V, sizeof(int));
        if (g-> a[i] == NULL){
            return NULL;
        }

    }
    return g;
}

void addEdge(Graph *g, int v1, int v2){

    if (g == NULL) return;

    if (v1 < 0 || v1 >= g->V || v2 < 0 || v2 >= g->V) return;

    if (g->a[v1][v2] == 0)
        g->E++;

    g->a[v1][v2]++;
}

void deleteGraph(Graph *g){
    if (g == NULL) return;

    for(int i = 0; i < g->V; i++){
        free(g->a[i]);
    }
    free(g->a);
    free(g);
}

int gradIesire(Graph *g, int nod) {
    int s = 0;

    if (g == NULL) return 0;

    if(nod<0 || nod >= g->V) return 0;

    for(int j = 0; j<g->V; j++) s = s+ g->a[nod][j];

    return s;
}


fractie probKDays(Graph *g, int start, int target, int K) {

    fractie* current = (fractie*) malloc(g->V * sizeof(fractie));
    fractie* next = (fractie*) malloc(g->V * sizeof(fractie));

    fractie result;
    int day, total;

    for(int i = 0; i<g->V; i++){
        current[i] = createf(0, 1);
        next[i] = createf(0, 1);
    }

    current[start] = createf(1,1);

    for(day = 0; day<K; day++){

        for(int i = 0; i<g->V; i++){
            next[i] = createf(0,1);
        }
        for(int i = 0; i<g->V; i++){
            total = gradIesire(g,i);
                for(int j = 0; j<g->V; j++){
                    if (g->a[i][j] > 0 && total > 0){
                        fractie prob = createf(g->a[i][j], total);

                        next[j] = adunare(next[j], inmultire(current[i], prob));
                        
                    }
                }
        }
        for(int i = 0; i<g->V; i++){
            current[i] = next[i];
        }
    }
        result = current[target];
        free(current);
        free(next);

        return result;
    }
