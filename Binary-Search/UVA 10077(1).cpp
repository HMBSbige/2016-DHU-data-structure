#include <iostream>
#include <cstdio>
using namespace std;

void tree(int Lx, int Ly, int Rx, int Ry, int Tx, int Ty)
{
    if (Lx+Rx == Tx && Ly+Ry == Ty) {
        printf("\n");
        return;
    }
    if (((double)(Lx+Rx)/(double)(Ly+Ry)) < ((double)Tx/(double)Ty) )
        {
        printf("R");
        tree(Lx+Rx, Ly+Ry, Rx, Ry, Tx, Ty);
    }
    else
        {
        printf("L");
        tree(Lx, Ly, Lx+Rx, Ly+Ry, Tx, Ty);
    }
}

int main()
{
    int n,m;
    while (cin >> m>> n && !(m == 1 && n == 1))
        tree(0, 1, 1, 0, m, n);
    return 0;
}
