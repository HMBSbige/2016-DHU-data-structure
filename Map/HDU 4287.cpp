#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

char ch[26] = { '2', '2', '2', '3', '3', '3', '4', '4', '4',
'5', '5', '5', '6', '6', '6', '7', '7', '7', '7', '8', '8', '8',
'9', '9', '9', '9' };

template <class T> void vecClear(vector<T> vec){
	vector<T>().swap(vec);
}
string StoN(string s) {
	size_t l = s.length();
	string ans="";
	for (int i = 0; i < l; ++i) {
		ans += ch[s[i] - 'a'];
	}
	return ans;
}
int main()
{
	int t,n,m;
	string S;
	map<string, int> _map;
	map<string, int>::iterator it;
	vector<string> list;

	cin >> t;
	while (t--) {
		_map.clear();
		vecClear(list);

		scanf("%d%d", &n, &m);
		list.resize(n);
		for (int i = 0; i < n; ++i){
			cin >> list[i];
			_map[list[i]] = 0;
		}
		for (int i = 0; i < m; ++i) {
			cin >> S;
			S=StoN(S);
			it = _map.find(S);
			if (it != _map.end())
				++it->second;
		}
		//output
		for (int i = 0; i < n; ++i) {
			cout << _map[list[i]] << endl;
		}
	}
	//system("pause");
	return 0;
}