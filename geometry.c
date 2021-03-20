#include <math.h>

#include "geometry.h"


double xlinha(point p, point a, point b) {
    if (a.x == b.x) {
        return a.x;
    }
    if ( (a.y == b.y) ) {
        if (((p.x <= a.x) && (p.x >= b.x)) || ((p.x <= b.x) && (p.x >= a.x))) {
            return p.x;
        }
        if (a.x <= b.x) {
            return b.x;
        }
        else {
            return a.x;
        }
    }
    double m = (double)(a.y - b.y) / (double)(a.x - b.x);
    return (((double)(p.y - b.y)/m) + (double)b.x);
}

int ylinha(point p, point a, point b) {
    if (b.y == a.y) {
        if (p.y == b.y) {
            return 2;
        }
        else {
            return 0;
        }
    }
    if (((p.y <= a.y) && (p.y > b.y)) || ((p.y <= b.y) && (p.y > a.y))) {
        return 1;
    }
    return 0;
}

int verify(point p, point a, point b) {
    if (((p.x == a.x) && (p.y == a.y)) || ((p.x == b.x) && (p.y == b.y))) {
        return 2;
    }
    if ((b.x == a.x) && (b.y == a.y)) {
        return 0;
    }
    float xl = xlinha(p,a,b);
    int yl = ylinha(p,a,b);
    if ((yl == 2) && (xl > p.x)) {
        return 0;
    }
    if ((yl == 1) || (yl == 2)) {
        if (((xl-(double)p.x)<0.000001)&&((xl-(double)p.x)>-0.000001)) {
            return 2;
        }
        if (xl > p.x) {
            return 1;
        }
        else {
            return 0;
        }
    }
    return 0;
}

int inside(point p, point poly[], int n) {
    int ncruza = 0;
    int cruza = 0;
    if (n == 0) {
        return 0;
    }
    if (n==1) {
        cruza = verify(p, poly[0],poly[0]);
        if (cruza == 2) {
            return 1;
        }
        ncruza += cruza;
    }
    else {
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                cruza = verify(p, poly[i],poly[n-1]);
            }
            else {
                cruza = verify(p, poly[i],poly[i-1]);
            }
            if (cruza == 2) {
                return 1;
            }
            ncruza += cruza;
        }
    }
    if ( (ncruza%2) == 0) {
        return 0;
    }
    else {
        return 1;
    }
}
