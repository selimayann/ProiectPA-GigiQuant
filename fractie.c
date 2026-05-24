#include "fractie.h"

fractie createf (int numarator, int numitor){
    fractie f;
    f.numarator = numarator;
    f.numitor = numitor;
    return f;
}

int cmmdc(int a, int b){

    while (b != 0){
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}

fractie simplificare(fractie f){
    int d;
    if(f.numarator == 0) {
        f.numitor = 1;
        return f;
    }

    d = cmmdc(f.numarator, f.numitor);
    f.numarator = f.numarator / d;
    f.numitor = f.numitor / d;

    return f;
}

fractie adunare(fractie a, fractie b){
    fractie c;
    c.numarator = a.numarator * b.numitor + b.numarator * a.numitor;
    c.numitor = a.numitor * b.numitor;
    return simplificare(c);
}

fractie inmultire (fractie a, fractie b){
    fractie x;
    x.numarator = a.numarator * b.numarator;
    x.numitor = a.numitor * b.numitor;
    return simplificare(x);
}