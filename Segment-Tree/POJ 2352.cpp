#include <iostream>
#include <cstdio>
#include <vector>
#include <string.h>
using namespace std;
#define M 32000
typedef struct t
{
	int l, r, w;
}Tree;
Tree tree[M * 3];
void CreateTree(int left, int right, int n)
{
	tree[n].l = left;
	tree[n].r = right;
	tree[n].w = 0;
	if (left == right)
		return;
	int mid = (tree[n].l + tree[n].r) >> 1;
	CreateTree(left, mid, n << 1);
	CreateTree(mid + 1, right, n << 1 | 1);
}
int find(int left, int right, int n)
{
	if (tree[n].l == left && tree[n].r == right)
		return tree[n].w;
	else
	{
		int sum = 0;
		int mid = (tree[n].l + tree[n].r) >> 1;
		if (left > mid)
			sum += find(left, right, n << 1 | 1);
		else if (right <= mid)
			sum += find(left, right, n << 1);
		else
			sum += find(left, mid, n << 1) + find(mid + 1, right, n << 1 | 1);
		return sum;
	}
}
void insert(int x, int n)
{
	tree[n].w++;
	if (tree[n].l == tree[n].r && tree[n].r == x)
		return;
	int mid = (tree[n].l + tree[n].r) >> 1;
	if (x <= mid)
		insert(x, n << 1);
	else insert(x, n << 1 | 1);
}
int main()
{
	int N, max = 0, y;
	cin >> N;
	vector<int> x(N);
	vector<int> level(N,0);
	//memset(level, 0, sizeof(level));
	for (int i = 0; i < N; ++i)
	{
		scanf("%d%d", &x[i], &y);
		//cin >> x[i] >> y;
		if (x[i] > max)
			max = x[i];
	}
	CreateTree(0, max, 1);
	for (int i = 0; i < N; ++i)
	{
		level[find(0, x[i], 1)]++;
		insert(x[i], 1);
	}
	for (int i = 0; i < N; ++i)
		cout << level[i] << endl;
	//system("pause");
	return 0;
}