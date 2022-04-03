// Name: 林信佑
// Date: 2022/3/10 下午 01:22:47
// Last Update: 2022/3/10 下午 01:22:47
// Problem statement: Collatz Conjecture
#include <iostream>
#include <unordered_map>
using namespace std;

int calc(unordered_map<int, int>& cache, int n)
{
	if (cache.find(n) != cache.end())
		return cache[n];
	if (n & 1)	// odd
	{
		cache[n] += calc(cache, n * 3 + 1) + 1;
	}
	else // even
	{
		cache[n] += calc(cache, n / 2) + 1;
	}
	return cache[n];
}
int main()
{
	unordered_map<int, int> cache;
	cache[1] = 1;
	for (int start, end; cin >> start >> end;)
	{
		cout << start << ' ' << end << ' ';
		if (end < start)
			swap(start, end);

		int res = -1;
		for (int i = start; i <= end; i++)
		{
			res = max(res, calc(cache, i));
		}
		cout << res << '\n';
	}
	return 0;
}