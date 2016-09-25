#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int weishu(int n)
{
    return (int)(log10(n)+1);
}
int f(int n)
{
    int i=1,l=1,j=1;
    for(i=1;n>l; l+=weishu(++i))
        n-=l;
    for(l=j=1;n>l;l=weishu(++j))
        n-=l;
    /*char c[l];
    sprintf(c,"%d",j);
    n=c[n-1]-'0';
    return n;*/
    j/=(int)pow(10,l-n);
    j%=10;
    return j;
}
int  main()
{
    int T,n;
    cin>>T;
    while(T--)
    {
        cin>>n;
        cout<<f(n)<<endl;
    }
    return 0;
}