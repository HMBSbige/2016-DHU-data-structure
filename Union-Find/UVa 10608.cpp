#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct DisjoinSet {
	std::vector<int> father, rank,max;
	int _max = 1;

	DisjoinSet(int n) :father(n), rank(n),max(n,1){
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
	int testnumber,N,M,a,b;
	
	cin >> testnumber;
	for (int i = 0; i < testnumber; ++i) {
		cin >> N >> M;
		DisjoinSet uf(N);
		while (M--) {
			cin >> a >> b;
			if (uf.find(a-1) != uf.find(b-1))
				uf.merge(a-1, b-1);
		}
		cout << uf._max << endl;
	}
	//system("pause");
	return 0;
}