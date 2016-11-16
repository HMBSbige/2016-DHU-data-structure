#include <iostream>
#include <vector>
#include <queue>
#include <new>
#include <string>
#include <cstring>
using namespace std;
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

int main() {
	int m, n, i, j;
	while (cin >> n >> m && !(m==0 && n==0)) {
		vector<int> *g = new vector<int>[n];
		while (m--) {
			cin >> i >> j;
			g[i-1].push_back(j - 1);
		}
		TopologicalSort tp(n);
		tp.readg(g);
		tp.isSort();
		for (i = 0; i < n; ++i) {
			if (i)
				cout << " ";
			cout << tp.L[i]+1;
		}
		cout << endl;
		delete[] g;
	}
	//system("pause");
	return 0;
}