#include <iostream>
#include <cmath>
using namespace std;

int weishu(int n)
{
	return static_cast<int>(log10(n) + 1);
}
int solve(int n)
{
	int l = 1, j;
	for (auto i = 1; n>l; l += weishu(++i))//减去前面的数字，只剩下从1开始的一组
		n -= l;
	for (l = j = 1; n>l; l = weishu(++j))
		n -= l;
	j /= 1<<l - n;//j=答案所在的数字，n=答案在该数字第几位，l=j的位数
	return j % 10;
}
int main(int argc, string argv[])
{
	std::ios::sync_with_stdio(false);
	setlocale(LC_ALL, "");
	int T, n;
	cin >> T;
	while (T--)
	{
		cin >> n;
		cout << solve(n) << endl;
	}
	//system("pause");
	return 0;
}