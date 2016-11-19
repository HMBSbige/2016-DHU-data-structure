#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <new>
#include <algorithm>
using namespace std;
class TopologicalSortDFS {
private:
	size_t N;
	vector<int> *map=NULL;
	vector<int> degree, EXIT, sss;
public:
	vector< vector<int> > ans;
	TopologicalSortDFS(){}
	TopologicalSortDFS(size_t n) {init(n);}
	void init(size_t n) {
		this->N = n;
		ans.clear();
		if(map!=NULL)
			delete[] map;
		degree.resize(n);
		EXIT.resize(n);
		sss.resize(n);
		map = new vector<int>[n];
		for (int i = 0; i<n; ++i) {
			map[i].resize(n);
			degree[i] = 0;
			EXIT[i] = 1;
			for (int j = 0; j<n; ++j)
				map[i][j] = 0;
		}
	}
	~TopologicalSortDFS() {
		delete[] map;
	}
	void readmap(size_t a, size_t b) {
		map[a][b] = 1;
	}
	void readdu(size_t a) {
		degree[a]++;
	}
	void DFS(int step) {
		int i, j;
		if (step == N) {
			ans.push_back(sss);
			return;
		}
		for (i = 0; i<N; i++) {
			if (EXIT[i] && degree[i] == 0) {
				EXIT[i] = 0;
				sss[step] = i;
				for (j = 0; j<N; j++) {
					if (map[i][j])
						degree[j]--;
				}
				DFS(step + 1);
				for (j = 0; j<N; j++) {
					if (map[i][j])
						degree[j]++;
				}
				EXIT[i] = 1;
			}
		}
	}
};
size_t find(vector <char> a, char x) {
	for (size_t i = 0; i<a.size(); ++i)
		if (a[i] == x)
			return i;
}
int main()
{
	vector <char> list;
	char tempC, a, b;
	stringstream ss;
	string tempStr;
	bool isfirst = 1;
	TopologicalSortDFS tp;
	while (getline(cin, tempStr, '\n')) {
		if (isfirst)
			isfirst = 0;
		else
			cout << endl;
		list.clear();
		ss.clear();
		ss << tempStr;
		while (ss >> tempC) {
			list.push_back(tempC);
		}
		sort(list.begin(), list.end());	
		size_t N = list.size();
		tp.init(N);
		getline(cin, tempStr, '\n');
		ss.clear();
		ss << tempStr;
		while (ss >> a >> b) {
			tp.readmap(find(list, a), find(list, b));
			tp.readdu(find(list, b));
		}
		tp.DFS(0);
		//output
		for (size_t i = 0; i<tp.ans.size(); ++i) {
			for (size_t j = 0; j<tp.ans[i].size(); ++j)
				cout << list[tp.ans[i][j]];
			cout << endl;
		}
	}
	return 0;
}