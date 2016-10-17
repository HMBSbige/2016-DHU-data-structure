#include<iostream>
#include<iomanip>
//#include<cstdio>
#include<queue>
using namespace std;
struct Student
{
	int ID;
	int m;//stand for money
};
int main()
{
	int n, k;

	while (cin >> n >> k && !(n == 0 && k == 0))
	{
		queue<Student> a;
		Student temp;
		//init
		for (int i = 0; i < n; ++i)
		{
			temp.ID = i + 1;
			temp.m = 0;
			a.push(temp);
		}
		//solve
		int mm = 1,next=1;
		while (!a.empty())
		{
			temp = a.front();
			a.pop();
			
			if (temp.m + mm <= 40)
			{
				temp.m += mm;
				next = 1 + next%k;
				mm = next;
			}
			else
			{
				mm = temp.m + mm-40;
				temp.m = 40;	
			}

			if (temp.m == 40)
				cout << setw(3) << temp.ID;
			else
				a.push(temp);

		}
		cout << endl;
	}
	//system("pause");
	return 0;
}
