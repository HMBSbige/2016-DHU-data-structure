#include <iostream>
#include <sstream>
#include <vector>
#include <cstdio>
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
	int ncases,n;
	cin >> ncases;
	cin.ignore();
	while (ncases--){
		char tempchar1, tempchar2;
		cin >> tempchar1;
		cin.ignore();
		n = tempchar1 - 'A' + 1;
		DisjoinSet uf(n);
		while (~scanf("%c",&tempchar1)){
			if (tempchar1 == '\n')
				break;
			cin >> tempchar2;
			cin.ignore();
			
			if (uf.find(tempchar1 - 'A') != uf.find(tempchar2 - 'A')){
				uf.merge(tempchar1 - 'A', tempchar2 - 'A');
				--n;
			}
		}
		cout << n << endl;
		if (ncases)
			cout << endl;
	}
	//system("pause");
	return 0;
}