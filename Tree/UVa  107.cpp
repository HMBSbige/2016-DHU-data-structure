#include <iostream>
#include <cmath>
using namespace std;
int main()
{/*设初始猫高h,每次分裂N，m次分裂后最后一组猫数量为w，则h=(N+1)^m,w=N^m
    log(N+1)(h)=m,log(N)(w)=m
    log(h)/log(N+1)=log(w)/log(N)
*/
    double h,w,N,m;
    while(cin>>h>>w && h && w)
    {
        for(N=1;abs(log(h)*log(N)-log(w)*log(N+1))>1e-10;++N);
        m=(int)(0.5+log(h)/log(N+1));

        if ( N == 1 )
            cout<<m;
        else cout<<(int)(0.5+(1-pow(N,m))/(1-N));
        cout<<' '<< (int)(0.5+(h*(1-pow((N/(N+1)),m+1)))/(1-(N/(N+1))))<<endl;
    }
    return 0;
}