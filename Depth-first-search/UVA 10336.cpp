#include <cstdio>
#include <cstring>
using namespace std;
int findc(char*a,int W)
{
    for(int i=0;i<W;i++)
        if(a[i]>='a' && a[i]<='z')
            return i;
    return -1;
}
char l[100][100];
void dfs(char c,int i,int j,int H,int W)
{
    if(i>=0&&i<H&&j>=0&&j<W&&l[i][j]==c)
    {
        l[i][j]='0';
        dfs(c,i,j+1,H,W);
        dfs(c,i,j-1,H,W);
        dfs(c,i+1,j,H,W);
        dfs(c,i-1,j,H,W);
    }
    else
        return;
}
void RtL(int H,int W)
{
    char c;
    int s[26],max;

    memset(s,0,sizeof(s));
    int i,j;
    for(i=0;i<H;i++)
    {
        getchar();
        for(j=0;j<W;j++)
        {
            scanf("%c",&l[i][j]);
        }
    }
    while(1)
    {
        for(i=0;i<H;i++)
        {
            j=findc(l[i],W);
            if(j!=-1)
                break;
        }
        if(j==-1)
            break;
        c=l[i][j];
        s[c-'a']++;
        //clear the same area.
        dfs(c,i,j,H,W);
    }
    //output
    for(i=1,max=s[0];i<26;i++)
        max=max>s[i]?max:s[i];
    do
    {
        for(i=0;i<26;i++)
            if(max==s[i])
                printf("%c: %d\n",i+'a',s[i]);
    }while(--max);
}
int main()
{
    int t,H,W,i=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&H,&W);
        printf("World #%d\n",i++);
        RtL(H,W);
    }
    return 0;
}