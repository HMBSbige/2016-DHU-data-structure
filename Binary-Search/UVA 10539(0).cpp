#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
#define max 1000000LL
#define maxN  max*max
#define LL long long//LL stand for lovelive(#»¬»ü)
LL Prime[max+1];
bool isPrime[max+1];
LL APN[max+1];//APN stand for AlmostPrimeNumbers
int DoPrime(LL N)
{
    int i,j,n=0;
    memset(isPrime+2,1,sizeof(isPrime)-2);
    for (i = 2 ; i < N ; ++ i)
        if (isPrime[i])
        {
            Prime[n++] = i;
            for (j = i<<1 ; j <=N ; j += i)
                isPrime[j] = 0;
        }
     return n;
}
int DoAPN(int N)
{
    int i,n=0;
    LL TEMP;

    for(i=0;i<N;++i)
    {
        TEMP=Prime[i]*Prime[i];
        for(;TEMP<=maxN;)
        {
            APN[n++]=TEMP;
            TEMP*=Prime[i];
        }
    }
    return n;
}
bool cmp(LL a, LL b)
{
    return a < b;
}
int find(int right,LL key)/*3 4 5 6 7 8 9 10*/
{
    int left=0,mid;
    for(;right-left!=1;)
    {
        mid =(left+right)>>1;
        if (APN[mid] > key)
         right=mid;
        else if(APN[mid] < key)
         left=mid;
        else
            return mid;

    }
    return left;
}
int main()
{
    int t,x,y;
    LL a,b;
    int num=DoAPN(DoPrime(max));
    sort(APN,APN+num,cmp);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld%lld",&a,&b);
        x=find(num-1,a);
        y=find(num-1,b);
        if (APN[x] == a) x --;
        if (APN[0] > a) x --;
        if (APN[0] > b) y --;
        printf("%d\n",y-x);
    }

    return 0;
}
