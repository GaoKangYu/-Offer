/*
Day2
剑指 Offer 49. 丑数

我们把只包含质因子 2、3 和 5 的数称作丑数（Ugly Number）。求按从小到大的顺序的第 n 个丑数。

 

示例:

输入: n = 10
输出: 12
解释: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 是前 10 个丑数。

说明:  
1 是丑数。
n 不超过1690。
*/

/*
思路
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int nthUglyNumber(int n) {
		int p = 0, q = 0, r = 0;
		vector<int> dp(n, 0);
		dp[0] = 1;
		for (int i = 1; i < n; ++i) {
			dp[i] = min(min(dp[p] * 2, dp[q] * 3), dp[r] * 5);
			if (dp[i] == dp[p] * 2) {
				++p;
			}
			if (dp[i] == dp[q] * 3) {
				++q;
			}
			if (dp[i] == dp[r] * 5) {
				++r;
			}
		}
		return dp[n - 1];
	}
};

int main() {

}
