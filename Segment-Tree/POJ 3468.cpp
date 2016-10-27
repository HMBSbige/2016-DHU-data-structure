#include <iostream>
#include <cstdio>
using namespace std;
#define LL long long
#define M 100000
struct tree {
	int l, r, mid;
	LL sum,add;
}Tree[3 * M];
LL a[M + 1];
LL CreateTree(int left, int right, int n)
{
	Tree[n].l = left;
	Tree[n].r = right;
	Tree[n].add = 0;
	Tree[n].mid = (Tree[n].l + Tree[n].r) >> 1;
	if (left == right)
	{
		Tree[n].sum = a[left];
		return a[left];
	}
	else
	{
		Tree[n].sum = CreateTree(left, Tree[n].mid, n << 1) + CreateTree(Tree[n].mid + 1, right, n << 1 | 1);
		return Tree[n].sum;
	}
}
LL find(int left, int right, int n)
{
	if (left <= Tree[n].l && Tree[n].r <= right)
		return Tree[n].sum;
	if (Tree[n].add) {
		Tree[n << 1].sum += Tree[n].add*(Tree[n << 1].r - Tree[n << 1].l + 1);
		Tree[n << 1 | 1].sum += Tree[n].add*(Tree[n << 1 | 1].r - Tree[n << 1 | 1].l + 1);
		Tree[n << 1].add += Tree[n].add;
		Tree[n << 1 | 1].add += Tree[n].add;
		Tree[n].add = 0;
	}
	LL sum = 0;
	if (left <= Tree[n].mid)
		sum += find(left, right, n << 1);
	if (right>Tree[n].mid)
		sum += find(left, right, n << 1 | 1);
	return sum;
}
void insert(int left, int right, int add, int n) {

	if (left <= Tree[n].l&&Tree[n].r <= right)
	{
		Tree[n].add += add;
		Tree[n].sum += add*(Tree[n].r - Tree[n].l + 1);
		return;
	}
	if (Tree[n].add) {
		Tree[n << 1].sum += Tree[n].add*(Tree[n << 1].r - Tree[n << 1].l + 1);
		Tree[n << 1 | 1].sum += Tree[n].add*(Tree[n << 1 | 1].r - Tree[n << 1 | 1].l + 1);
		Tree[n << 1].add += Tree[n].add;
		Tree[n << 1 | 1].add += Tree[n].add;
		Tree[n].add = 0;
	}
	if (left <= Tree[n].mid)
		insert(left, right, add, n << 1);
	if (right>Tree[n].mid)
		insert(left, right, add, n << 1 | 1);
	Tree[n].sum = Tree[n << 1].sum + Tree[n << 1 | 1].sum;
}
int main()
{
	int N, Q;
	cin >> N >> Q;
	for (int i = 1; i <= N; ++i)
		//cin >> a[i];
		scanf("%lld", &a[i]);
	CreateTree(1, N, 1);

	char c;
	while(Q-- &&cin >> c)
	{
		int m, n, C;
		if (c == 'C')
		{
			//cin >> m >> n>> C;
			scanf("%d%d%d", &m, &n, &C);
			insert(m, n, C, 1);
		}
		else if (c == 'Q')
		{
			//cin >> m >> n;
			scanf("%d%d", &m, &n);
			cout << find(m, n, 1) << endl;
		}
	}
	//system("pause");
	return 0;
}
/*
Sample Input
10 5
1 2 3 4 5 6 7 8 9 10
Q 4 4
Q 1 10
Q 2 4
C 3 6 3
Q 2 4
Sample Output
4
55
9
15
*/