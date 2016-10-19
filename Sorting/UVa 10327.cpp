#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int T;
	while (cin >> T)
	{
		vector<int> n(T);
		for (int &x : n)
			cin >> x;
		int cnt = 0;
		for(int i=0;i<T-1;++i)
			for(int j=0;j<T-1-i;++j)
				if (n[j]>n[j+1])
				{ 
					swap(n[j], n[j + 1]);
					++cnt;
				}
		cout << "Minimum exchange operations : " << cnt << endl;
	}
	//system("pause");
	return 0;
}