#include <iostream>
#include <algorithm>
#include <vector>
//#include <valarray>
//#include <string>
using namespace std;
int main() 
{
	int t;
	cin >> t;
	while (t--)
	{
		int x,temp,cnt=0;
		vector<int> train;
		cin >> x;
		for (int i = 0; i < x; ++i)
		{
			cin >> temp;
			train.push_back(temp);
		}
		for (int i = 0; i < x-1; ++i)
			for (int j = 0; j < x-i-1;++j)
				if (train[j]>train[j + 1])
				{
					++cnt;
					swap(train[j], train[j + 1]);
				}
		cout << "Optimal train swapping takes " << cnt << " swaps."<<endl;
	}
	
	
	//system("pause");
	return 0;
}
/*

*/