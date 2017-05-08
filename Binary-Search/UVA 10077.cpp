#include <iostream>

using namespace std;

struct  fractions
{
	size_t Numerator,Denominator;
	fractions(size_t a=1, size_t b=1)
	{
		Numerator = a;
		Denominator = b;
	}
	friend bool operator >(const fractions& a, const fractions& b)
	{
		if(a.Numerator*b.Denominator>b.Numerator*a.Denominator)
			return true;
		return false;
	}
	friend bool operator <(const fractions& a, const fractions& b)
	{
		if (a.Numerator*b.Denominator<b.Numerator*a.Denominator)
			return true;
		return false;
	}
	friend bool operator ==(const fractions& a, const fractions& b)
	{
		if (a.Numerator*b.Denominator==b.Numerator*a.Denominator)
			return true;
		return false;
	}
};
int main(int argc, string argv[])
{
	std::ios::sync_with_stdio(false);
	setlocale(LC_ALL, "");
	size_t m, n;
	while (cin >> m>>n && !(m==1 && n==1))
	{
		fractions left(0,1),mid(1,1),right(1,0),now(m,n);
		while(true){
			if(now>mid)
			{
				left = mid;
				cout << "R";
			}				
			else if (now<mid)
			{
				right = mid;
				cout << "L";
			}	
			else
				break;
			mid = fractions(left.Numerator + right.Numerator, left.Denominator + right.Denominator);
		}
		cout << endl;
	}
	//system("pause");
	return 0;
}
