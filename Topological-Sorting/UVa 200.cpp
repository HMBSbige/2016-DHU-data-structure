#include <iostream>
#include <vector>
#include <queue>
#include <new>
#include <string>
#include <cstring>
using namespace std;
#define min(a,b) a<b?a:b
int c[26][26];
class TopologicalSort {
private:
	vector<int> *g, du;
	int n;
public:
	vector<int> L;
	TopologicalSort(int n) :du(n, 0), L(n, 0) {
		this->n = n;
	}
	void readg(vector<int> *g) {
		this->g = g;
	}
	bool isSort() {
		for (int i = 0; i<n; ++i)
			for (int j = 0; j<g[i].size(); j++)
				++du[g[i][j]];
		int tot = 0;
		queue <int> Q;
		for (int i = 0; i<n; ++i)
			if (!du[i])
				Q.push(i);
		while (!Q.empty()) {
			int x = Q.front();
			Q.pop();
			L[tot++] = x;
			for (int j = 0; j<g[x].size(); ++j) {
				int t = g[x][j];
				--du[t];
				if (!du[t])
					Q.push(t);
			}
		}
		if (tot == n)
			return 1;
		return 0;
	}
};
void cmpANDgetg(string a, string b) {
	int len = min(a.length(), b.length());
	for (int i = 0; i<len; ++i) {
		if (a[i] != b[i]) {
			c[a[i] - 'A'][b[i] - 'A'] = 1;
			break;
		}
	}
}
int find(vector<char> a, char x) {
	for (int i = 0;i<a.size(); ++i)
		if (a[i] == x)
			return i;
}
int main() {
	vector<string> Str;
	string tempStr;
	int m = 0, n = 0;
	int letter[26];
	memset(letter, 0, sizeof(letter));
	while (getline(cin, tempStr, '\n') && tempStr != "#") {
		Str.push_back(tempStr);
		++m;
	}
	for (int i = 0; i<26; ++i)
		for (int j = 0; j<26; ++j)
			c[i][j] = 0;
	for (int i = 0; i<m - 1; ++i) {
		cmpANDgetg(Str[i], Str[i + 1]);
	}
	for (int i = 0; i<26; ++i)
		for (int j = 0; j<26; ++j) {
			if (c[i][j]) {
				letter[i] = letter[j] = 1;
			}
		}
	vector<char> map;
	for (int i = 0; i<26; ++i) {
		if (letter[i]){
			++n;
			map.push_back(i + 'A');
		}
	}
	vector<int> *g = new vector<int>[n];
	for (int i = 0; i<n; ++i)
		for(int j=0;j<26;++j)
			if(c[map[i]-'A'][j])
				g[i].push_back(find(map,j+'A'));
	TopologicalSort tp(n);
	tp.readg(g);
	tp.isSort();
	for (int i = 0; i<n; ++i) {
		cout << map[tp.L[i]];
	}
	cout<< endl;
	delete[] g;
	//system("pause");
	return 0;
}