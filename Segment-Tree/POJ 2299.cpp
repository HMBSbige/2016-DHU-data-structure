#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define LL long long
#define M 500000
struct tree {
	int l, r, mid, w;
}Tree[3*M];
void CreateTree(int left, int right, int n)
{
	Tree[n].l = left;
	Tree[n].r = right;
	Tree[n].w = 0;
	Tree[n].mid = (Tree[n].l + Tree[n].r) >> 1;
	if (left == right)
		return;
	CreateTree(left, Tree[n].mid, n << 1);
	CreateTree(Tree[n].mid + 1, right, n << 1 | 1);
}
LL find(int left, int right, int n)
{
	if (Tree[n].l == left && Tree[n].r == right)
		return Tree[n].w;
	else
	{
		LL sum = 0;
		if (left > Tree[n].mid)
			sum += find(left, right, n << 1 | 1);
		else if (right <= Tree[n].mid)
			sum += find(left, right, n << 1);
		else
			sum+= find(left, Tree[n].mid, n << 1) + find(Tree[n].mid + 1, right, n << 1 | 1);
		return sum;
	}
}
void insert(LL x,int n)
{
	++Tree[n].w;
	if (Tree[n].l == Tree[n].r && Tree[n].r == x)
		return;
	if (x <= Tree[n].mid)
		insert(x, n << 1);
	else
		insert(x, n << 1 | 1);
}
LL a[M];
int index[M];
int cmp(int i, int j)
{
	return a[i] < a[j];
}
int main()
{
	int t;//limit=500,000
	while (cin >> t && t)
	{
		LL cnt=0;
		for (int i = 0; i < t; ++i)
		{
			cin >> a[i];
			index[i] = i;
		}
		sort(index, index + t,cmp);
		CreateTree(0, t-1, 1);
		for (int i = 0; i < t; ++i)
		{
			if(index[i]!=t-1)
				cnt += find(index[i]+1,t-1, 1);
			insert(index[i], 1);
		}
		cout << cnt << endl;
	}
	//system("pause");
	return 0;
}