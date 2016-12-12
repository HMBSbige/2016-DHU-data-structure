#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
using namespace std;

int main()
{
	int command,k,p;
	map<int, int> q;
	map<int, int>::iterator it;
	map<int, int>::reverse_iterator rit;

	while(scanf("%d", &command) && command){
		switch (command) {
		case 1:
			scanf("%d %d", &k, &p);//用cin可能TLE
			q[p] = k;
			break;
		case 2:
			if (q.empty()) {
				cout << 0 << endl;
				continue;//直接跳出switch，进入下一次循环。
			}
			rit = q.rbegin();
			cout << rit->second << endl;
			q.erase(--rit.base());//q.erase((++rit).base()); 
			break;
		case 3:
			if (q.empty()) {
				cout << 0 << endl;
				continue;//直接跳出switch，进入下一次循环。
			}
			it = q.begin();
			cout << it->second << endl;
			q.erase(it);
			break;
		}
	}
	//system("pause");
	return 0;
}