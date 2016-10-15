#include <iostream>
#include <algorithm>
#include <vector>
//#include <valarray>
//#include <string>
//#include <cstring>
using namespace std;
int main() 
{
	int t;
	cin >> t;
	while (t--)
	{
		int x, k, sum = 0,temp;
		cin >> x;
		k = (x - 1) >> 1;
		vector<int> s;
		while (x--)
		{
			cin >> temp;
			s.push_back(temp);
		}
		sort(s.begin(), s.end());
		temp = s[k];
		for (int &d : s)
		{
			sum += abs(d - temp);
		}
		cout << sum<<endl;
	}
	//system("pause");
	return 0;
}
/*

*/