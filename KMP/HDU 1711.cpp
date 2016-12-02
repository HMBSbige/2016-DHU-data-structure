#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
template <class T> vector <int> find_substring(T pattern,T text){
    int n=pattern.size();
    vector <int> next(n+1,0);
    for(int i=1;i<n;++i){
        int j=i;
        while (j>0){
            j=next[j];
            if(pattern[j]==pattern[i]){
                next[i+1]=j+1;
                break;
            }
        }
    }
    vector <int> positions;
    int m=text.size();
    for(int i=0,j=0;i<m;++i){
        if(j<n && text[i]==pattern[j]){
            ++j;
        }else{
            while(j>0){
                j=next[j];
                if(text[i]==pattern[j]){
                    ++j;
                    break;
                }
            }
        }
        if(j==n){
            positions.push_back(i-n+1);
        }
    }
    return positions;
}
int main()
{
    int t,m,n;
    cin>>t;
    while(t--){
        cin>>m>>n;
        vector<int> int1(m),int2(n);
        for(int i=0;i<m;++i){
            scanf("%d",&int1[i]);
        }
        for(int i=0;i<n;++i){
            scanf("%d",&int2[i]);
        }
        vector<int> ans=find_substring<vector<int>>(int2,int1);
        if(!ans.size())
            cout<<-1;
        else
            cout<<ans[0]+1;
        cout<<endl;
    }
    return 0;
}
