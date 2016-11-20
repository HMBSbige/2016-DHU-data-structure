#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <sstream>
#include <iostream>
#include <new>
using namespace std;
//                              
vector<int> *G = NULL;                           
vector<int>  val;
vector<string> S;
int row, col;
inline int GetId(int x, int y) { return (x - 1)*col + y; }  // 数字转换成id
inline int StringToNum(const string& s) //字符串转数字
{
	int num;
	stringstream ss(s);
	ss >> num;
	return num;
}
inline int Stoid(const string& str) // 字母转换成id
{
	int i;
	for (i = 0; i<str.size(); i++)
	{
		if (str[i] >= '0'&&str[i] <= '9')  break;           //  找到字母和数字的分界位置
	}
	int R = 0, C = 0;
	for (int j = 0; j<i; j++) 
		C = C * 26 + str[j] - 'A' + 1;
	for (int j = i; j<str.size(); j++)  
		R = R * 10 + str[j] - '0';
	return GetId(R, C);
}
inline int GetNum(const string& str, int id)
{
	int pre = 1;
	int i;
	int sum = 0;
	for (i = 1; i<str.size(); i++){
		if (str[i] == '+'){
			sum+=val[Stoid(str.substr(pre, i - pre))];
			pre = i + 1;
		}
	}
	sum += val[Stoid(str.substr(pre, i - pre))];             
	return sum;
}
inline void makeG(const string& str, int id)
{
	int pre = 1;
	int i;
	for (i = 1; i<str.size(); i++){
		if (str[i] == '+'){
			G[Stoid(str.substr(pre, i - pre))].push_back(id);
			pre = i + 1;
		}
	}
	G[Stoid(str.substr(pre, i - pre))].push_back(id);
}
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
		for (int i = 1; i<n; ++i)
			for (int j = 0; j<g[i].size(); j++)
				++du[g[i][j]];
		int tot = 1;
		queue <int> Q;
		for (int i = 1; i<n; ++i)
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
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		cin >> col >> row;
		int maxn = col*row + 1;
		if (G != NULL)
			delete[] G;
		G = new vector<int>[maxn];
		val.resize(maxn);
		S.resize(maxn);
		for (int i = 1; i < maxn; i++)
			val[i] = 0;
		//初始化
		for (int i = 1; i <= row; i++)
		{
			for (int j = 1; j <= col; j++)
			{
				int id = GetId(i, j);         
				cin >> S[id];
				if (S[id][0] != '=')
					val[id] = StringToNum(S[id]);
				else
					makeG(S[id], id);
			}
		}
		TopologicalSort tp(maxn);
		tp.readg(G);
		tp.isSort();
        //
		for (int i = 1; i < maxn; i++) {
			int id=tp.L[i];
			if (S[id][0] == '=')
				val[id] = GetNum(S[id],id);
		}
		//output
		for (int i = 1; i <= row; i++){
			for (int j = 1; j <= col; j++){
				if (j != 1)
					cout << " ";
				cout << val[GetId(i, j)];
			}
			cout << endl;
		}
	}
	//system("pause");
	return 0;
}