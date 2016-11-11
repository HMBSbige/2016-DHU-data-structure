#include <iostream>
#include <sstream>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;
struct DisjoinSet {
	std::vector<int> father, rank, max;
	int _max = 1;

	DisjoinSet(int n) :father(n), rank(n), max(n, 1){
		for (int i = 0; i<n; ++i)
			father[i] = i;
	}
	int find(int v) {
		return father[v] = father[v] == v ? v : find(father[v]);
	}
	void merge(int x, int y) {
		int a = find(x), b = find(y);
		if (rank[a]<rank[b]){
			father[a] = b;
			if (_max < (max[b] += max[a]))
				_max = max[b];
		}
		else {
			father[b] = a;
			if (_max < (max[a] += max[b]))
				_max = max[a];
			if (rank[b] == rank[a])
				++rank[a];
		}
	}
};
int main()
{
	int ncase,n,a,b,n1,n2;
	char c;
	cin >> ncase;
	cin.ignore();
	stringstream ss;
	string str;
	while (ncase--){
		cin >> n;
		cin.ignore();
		DisjoinSet uf(n);
		n1 = n2 = 0;
		while ((getline(cin, str)) && (str != "")){
			ss.clear();
			ss << str;
			ss >> c >> a >> b;
			--a; --b;
			if (c == 'c'){
				if (uf.find(a) != uf.find(b))
					uf.merge(a, b);
			}
			else{
				if (uf.find(a) == uf.find(b))
					++n1;
				else
					++n2;
			}
		}
		cout << n1 << "," << n2 << endl;
		if (ncase)
			cout << endl;
	}
	//system("pause");
	return 0;
}