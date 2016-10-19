#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		//input
		int N, P;
		cin >> N >> P;
		vector<int> days(N, 0);
		vector<int> h(P);
		for (int &x : h)
			cin >> x;
		//solve		
		for (int &x : h)
            for (int i = x; i <= N; i += x)
                if (i % 7 != 0 && i % 7 != 6)
                    days[i - 1] = 1;
		//output
		int ans = 0;
		for (int &x : days)
			if (x == 1)
				++ans;
		cout << ans << endl;
	}
	//system("pause");
	return 0;
}