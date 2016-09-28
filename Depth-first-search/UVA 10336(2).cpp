author:Shijie
#include <iostream>

using namespace std;

void next(int x,int y,int h,int w,char arr[100][100][2])
{
    if(x>=w||y>=h||x<0||y<0)
    {
        return;
    }
    if(arr[x][y][1]==0)
    {
        arr[x][y][1]=1;
    }
    else
    {
        return;
    }
    if(x-1>=0&&arr[x-1][y][0]==arr[x][y][0])
    {
        next(x-1,y,h,w,arr);
    }
    if(x+1<100&&arr[x+1][y][0]==arr[x][y][0])
    {
        next(x+1,y,h,w,arr);
    }
    if(y-1>=0&&arr[x][y-1][0]==arr[x][y][0])
    {
        next(x,y-1,h,w,arr);
    }
    if(y+1<100&&arr[x][y+1][0]==arr[x][y][0])
    {
        next(x,y+1,h,w,arr);
    }
}
void solve(int h,int w,char arr[100][100][2])
{
    int result[26],i,j,k,n=0;
    for(i=0;i<26;i++)
    {
        result[i]=0;
    }
    for(i=0;i<w;i++)
    {
        for(j=0;j<h;j++)
        {
            if(arr[i][j][1]==0)
            {
                next(i,j,h,w,arr);
                result[arr[i][j][0]-'a']++;
            }
        }
    }
    for(i=0;i<26;i++)
    {
        if(result[i]!=0)
        {
            n++;
        }
    }
    for(j=0;j<n;j++)
    {
        k=25;
        for(i=25;i>=0;i--)
        {
            if(result[k]<=result[i])
            {
                k=i;
            }
        }
        cout<<(char)(k+'a')<<": "<<result[k]<<endl;
        result[k]=0;
    }
}
int main()
{
    int n,h,w,i,j,k;
    char arr[100][100][2];
    cin>>n;
    for(k=0;k<n;k++)
    {
        cin>>h;
        cin>>w;
        for(i=0;i<h;i++)
        {
            for(j=0;j<w;j++)
            {
                cin>>arr[j][i][0];
                arr[j][i][1]=0;
            }
        }
        cout<<"World #"<<k+1<<endl;
        solve(h,w,arr);
    }
    return 0;
}
