/*
UVa11988_Broken Keyboard
http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=229&problem=3139&mosmsg=Submission+received+with+ID+8911931
çÑ²ýÐÂ
2011/6/2
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <deque>
typedef long long int64;
const int maxint = 0x3f3f3f3f;
const int minint = -maxint;
const double eps = 1e-11;
const double pi = acos(-1.0);
using namespace std;
void chmax(int& a, int b) {if(a<b) a=b;}
void chmin(int& a, int b) {if(a>b) a=b;}
template<class T> ostream& operator<(ostream& in, T e)
{cout<<' '<<e;return cout;}
//////////////////////////////////////////////////////////
char input[100010];
int main()
{
	while(gets(input))
	{
		deque<string> que;
		bool front = true;
		string pend;
		for(int i=0; input[i]; ++i)
		{
			if(input[i]=='[')
			{
				if(front)
					que.push_front(pend);
				else
					que.push_back(pend);
				front = true;
				pend.clear();
			}
			else if(input[i]==']')
			{
				if(front)
					que.push_front(pend);
				else
					que.push_back(pend);
				front = false;
				pend.clear();
			}
			else
				pend += input[i];
		}
		if(front)
			que.push_front(pend);
		else
			que.push_back(pend);
		for(deque<string>::iterator ite=que.begin(); ite!=que.end();++ite)
			printf("%s", ite->c_str());
		putchar('\n');
	}
	return 0;
}