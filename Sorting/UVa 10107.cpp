#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
int main()
{
	vector<LL> n;
	n.reserve(10010);
	LL temp;
	int i = 0;
	while (cin >> temp)
	{
		n.push_back(temp);
		sort(n.begin(), n.end());
		if (++i%2)
			cout << n[(i - 1) >> 1] << endl;
		else 
			cout << ((n[(i - 1) >> 1] + n[(i+1) >> 1])>>1 )<< endl;
	}
	//system("pause");
	return 0;
}