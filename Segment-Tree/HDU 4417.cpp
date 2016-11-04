#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define maxn 100000
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
int num[maxn+1];
vector<int> v[maxn<<2];
typedef pair<vector<int>::iterator,vector<int>::iterator> p;
void CreateTree(int l,int r,int rt){
    v[rt].clear();
    for(int i=l;i<=r;++i)
        v[rt].push_back(num[i]);
    int mid=(l+r)>>1;
    sort(v[rt].begin(),v[rt].end());
    if(l==r)
        return;
    CreateTree(lson);
    CreateTree(rson);
}
int find(int L,int R,int H,int l,int r,int rt)
{
    if(L<=l && R>=r){
        p range;
        range=equal_range(v[rt].begin(),v[rt].end(),H);
        return range.second-v[rt].begin();
    }
    int mid=(l+r)>>1;
    int cnt=0;
    if(L<=mid) cnt+=find(L,R,H,lson);
    if(R>mid)  cnt+=find(L,R,H,rson);
    return cnt;
}
int main()
{
    int T,n,m,L,R,H;
    scanf("%d",&T);
    for(int icase=1;icase<=T;++icase){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;++i)
            scanf("%d",&num[i]);
        CreateTree(1,n,1);
        printf("Case %d:\n",icase);
        while(m--){
            scanf("%d%d%d",&L,&R,&H);
            printf("%d\n",find(L+1,R+1,H,1,n,1));
        }
    }
    return 0;
}