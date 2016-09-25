#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
#define LL long long//LL stand for lovelive(#»¬»ü)
LL pow(LL x,LL y)
{
    LL i,ans=1;
    for(i=0;i<y;i++)
        ans*=x;
    return ans;
}
int main()
{
   LL k,x,y,z,temp;
   int ans;
   while(~scanf("%lld",&k),k)
   {
        ans=0;
        temp=(int)sqrt(k);
        if(temp*temp==k)
            ans+=(temp-1)>>1;
        for(z=3;z<31;z++)
        {
            for(x=1;x<temp;x++)
            {
                LL tx=pow(x,z);
                if(tx>k>>1)
                    break;
                for(y=x+1;;y++)
                {
                    LL ty=pow(y,z);
                    if(tx+ty+x*y*z==k)
                    {
                        ans++;
                        break;
                    }
                    if(tx+ty+x*y*z>k)
                        break;
                }
            }

        }
        printf("%d\n",ans);

   }

    return 0;
}
