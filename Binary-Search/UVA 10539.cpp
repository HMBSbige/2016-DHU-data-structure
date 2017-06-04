#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
#define Max 1000000LL
#define maxN  Max*Max
typedef unsigned long long ull;
typedef long long ll;
vector<ull> AlmostPrimeNumbers;
vector<bool> isPrime;
vector<ull> Primes;
void MakePrime(ull N)//膜改快速线性筛法
{
	ull m = N;
	--N;
	N /= 2;
	ull sn = ull(sqrt(2 * N) / 2);
	vector<bool> p(N, true);
	for (ull i = 0; i < sn; i++) {
		if (p[i])
		{
			for (ull j = i*(2 * i + 6) + 3; j<N; j += 2 * i + 3)
				p[j] = false;
		}
	}
	//
	vector<ull>(1, 2).swap(Primes);
	isPrime = vector<bool>(m + 1, false);
	isPrime[2] = true;
	for (ull i = 0; i<N; ++i) {
		if (p[i]) {
			Primes.push_back(i + i + 3);
			isPrime[i + i + 3] = true;
		}
	}
}
void MakeAlmostPrimeNumbers(int N)
{
	for (int i = 0; i<N; ++i)
	{
		ull TEMP = Primes[i] * Primes[i];
		while (TEMP <= maxN)
		{
			AlmostPrimeNumbers.push_back(TEMP);
			TEMP *= Primes[i];
		}
	}
}
ll binary_search(std::vector<ull> array, ull value)
{
	ll left = 0;
	ll right = array.size() - 1;//ll right = array.size();

	while (left <= right)//while(left < right) 
	{
		ll middle = left + ((right - left) >> 1);

		if (array[middle]>value)
		{
			right = middle - 1;//right = mid  
		}
		else if (array[middle]<value)
		{
			left = middle + 1;
		}
		else
			return middle;
	}
	return left-1;//没找到返回小于value最近的位置
}
int main()
{
	ios::sync_with_stdio(false);
	int t;
	ull a, b;
	MakePrime(Max);
	MakeAlmostPrimeNumbers(Primes.size());
	sort(AlmostPrimeNumbers.begin(), AlmostPrimeNumbers.end());
	cin >> t;
	while (t--)
	{
		cin >> a >> b;
		ll x = binary_search(AlmostPrimeNumbers, a);
		ll y = binary_search(AlmostPrimeNumbers, b);
		if (x<AlmostPrimeNumbers.size() && AlmostPrimeNumbers[x] == a)
			--x;
		cout << y - x << endl;
	}
	return 0;
}