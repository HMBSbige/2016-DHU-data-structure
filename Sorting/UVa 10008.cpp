#include <iostream>
#include <algorithm>
#include <vector>
//#include <valarray>
#include <string>
#include <cstring>
using namespace std;
int main() 
{
	int t;
	cin >> t;
	getchar();
	vector<string> s;
	while (t--)
	{
		string temp;
		getline(cin, temp,'\n');
		s.push_back(temp);
	}
	int cnt[26];
	memset(cnt, 0, sizeof(cnt));
	for (string &x : s)
		for (int i = 0; x[i] != 0; ++i)
		{
			if (x[i] >= 'a' && x[i] <= 'z')
				++cnt[x[i] - 'a'];
			else if (x[i] >= 'A' && x[i] <= 'Z')
				++cnt[x[i] - 'A'];
		}
	//output
	int n=0;
	for (int i = 0; i < 26; i++)
	{
		if (cnt[i] != 0)
			n++;
	}
	while (n--)
	{
		int k = 0;
		for (int i = 1; i <26;++i)
			if (cnt[k] < cnt[i])
				k = i;
		
		cout << (char)(k + 'A') << " " << cnt[k] << endl;
		cnt[k] = 0;
	}
	//system("pause");
	return 0;
}
/*

*/