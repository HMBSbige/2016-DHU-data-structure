#include <iostream>
#include <map>
#include <vector>
using namespace std;
#define L(x,y,z) a[1]*x*x*x+a[2]*y*y*y+a[3]*z*z*z
#define R(x,y) -a[4]*x*x*x-a[5]*y*y*y
int main()
{
    vector<int> a(6);
    while(cin>>a[1]>>a[2]>>a[3]>>a[4]>>a[5])
    {
        int cnt=0;
        map<int,int> m;
        for(int i=-50;i<=50;++i)
            for(int j=-50;j<=50;++j)
                if(i!=0 && j!=0)
                    m[R(i, j)]++;
        for(int x=-50;x<=50;++x)
            for(int y=-50;y<=50;++y)
                for(int z=-50;z<=50;++z)
                    if(x!=0 && y!=0 && z!=0)
                    {
                        auto it=m.find(L(x,y,z));//map<int,int>::iterator
                        if(it!=m.end())
                            cnt+=it->second;
                    }
        cout<<cnt<<endl;
    }

    return 0;
}