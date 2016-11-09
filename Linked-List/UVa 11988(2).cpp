#include <iostream>
#include <string>
#include <cstring>
#include <list>
#include <cstdio>
using namespace std;
int main(){
    char S[100010];
    string s;
    while (gets(S))
    {
            s=S;
            list <string> ans;
            char sign=']';
            int begin=0,templen=0;
            for (int i=0;i<s.size();i++)
            {
                    if (s[i]=='['||s[i]==']')
                    {
                        if (templen>0)
                        if (sign=='[') ans.insert(ans.begin(),s.substr(begin,templen));
                        else ans.insert(ans.end(),s.substr(begin,templen));
                        begin+=(templen+1);templen=0;
                        sign=s[i];
                    }
                    else templen++;
            }
            if (templen>0)
            if (sign=='[') ans.insert(ans.begin(),s.substr(begin,templen));
            else ans.insert(ans.end(),s.substr(begin,templen));
            
                for (list<string>::iterator it = ans.begin(); it != ans.end(); it++){
                    printf("%s", it->c_str());
                }
            
            cout<<endl;
    }
    return 0;
}
