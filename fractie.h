#ifndef FRACTIE_H
#define FRACTIE_H

typedef struct {
    int numarator;
    int numitor;
}fractie;

fractie createf (int numarator, int numitor);
int cmmdc(int a, int b);
fractie simplificare(fractie f);
fractie adunare(fractie a, fractie b);
fractie inmultire(fractie a, fractie b);

#endif
