#include <stdio.h>
#include <stdlib.h>
#include "fractie.h"
#include "graf.h"

int stare (double p, double delta){
    return (int)(p/delta);
}

int main(int argc, const char *argv[]) {
    FILE *in = fopen(argv[1], "r");
    FILE *out = fopen(argv[2], "w");

    int N, K, V;

    double delta, pStart, pTarget;

    int vMin, vMax, s;

    fscanf(in, "%d", &N);
    fscanf(in, "%lf", &delta);
    fscanf(in, "%d", &K);
    fscanf(in, "%lf", &pStart);
    fscanf(in, "%lf", &pTarget);

    double* preturi = (double*) malloc(N * sizeof(double));

    for (int i = 0; i < N; i++){
        fscanf(in, "%lf", &preturi[i]);
    }

    vMin = stare (preturi[0], delta);
    vMax = vMin;

    for(int i = 1; i<N; i++){
        s = stare (preturi[i], delta);

        if (s<vMin) vMin = s;
        if (s>vMax) vMax = s;
    }

    s = stare (pStart, delta);

    if (s<vMin) vMin = s;
    if (s>vMax) vMax = s;

    s = stare (pTarget, delta);

    if (s<vMin) vMin = s;
    if (s>vMax) vMax = s;

    V = vMax - vMin + 1;

    Graph *g = createGraph(V);

    for(int i = 0; i<N-1; i++){
        int vi = stare(preturi[i], delta) - vMin;
        int vj = stare(preturi[i+1], delta) - vMin;
        addEdge(g, vi, vj);
    }

int start = stare(pStart, delta) - vMin;
int target = stare(pTarget, delta) - vMin;

for (int i = 0; i<K; i++){
    fractie result = probKDays(g, start, target, i);
    
    if(i> 0 ) fprintf(out, "\n");
    if(result.numitor == 1)
        fprintf(out, "%d", result.numarator);
    else
        fprintf(out, "%d/%d", result.numarator, result.numitor);
}

free(preturi);
fclose(in);
fclose(out);
deleteGraph(g);


}