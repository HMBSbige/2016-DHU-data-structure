#include <iostream>
#include <algorithm>
#include <vector>
//#include <valarray>
#include <string>
using namespace std;
int main() 
{
	string c;
	while (cin>>c && c != "#")
	{
		vector<char> s;
		for (int i=0;c[i]!=0;++i)
			s.push_back(c[i]);
		vector<char> temp(s);
		reverse(temp.begin(), temp.end());
		next_permutation(s.begin(),s.end());
		if (temp == s)
			cout << "No Successor" << endl;
		else
		{
			for (char &x : s)
				cout << x;
			cout << endl;
		}
	}
	//system("pause");
	return 0;
}
/*

*/