// Name: 林信佑
// Date: 2022/3/29 下午 04:02:05
// Last Update: 2022/3/29 下午 04:02:05
// Problem statement: Levenshtein Distance
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main()
{
	for (string old, target; getline(cin, old) && getline(cin, target);)
	{
		vector<vector<int>> dp(old.size() + 1, vector<int>(target.size() + 1, 0));
		// initialize
		for (int i = 0; i <= old.size(); i++)
			dp[i][0] = i;
		for (int i = 0; i <= target.size(); i++)
			dp[0][i] = i;

		// dp
		for (int i = 1; i <= old.size(); i++)
		{
			for (int j = 1; j <= target.size(); j++)
			{
				int cost = (old[i - 1] == target[j - 1] ? 0 : 1);
				dp[i][j] = min(min(dp[i - 1][j] + 1, dp[i][j - 1] + 1), (dp[i - 1][j - 1] + cost));
			}
		}
		cout << dp[old.size()][target.size()] << '\n';
	}
	return 0;
}