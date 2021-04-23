/*
剑指 Offer 46. 把数字翻译成字符串

给定一个数字，我们按照如下规则把它翻译为字符串：0 翻译成 “a” ，1 翻译成 “b”，……，11 翻译成 “l”，……，25 翻译成 “z”。
一个数字可能有多个翻译。请编程实现一个函数，用来计算一个数字有多少种不同的翻译方法。

示例 1:
输入: 12258
输出: 5
解释: 12258有5种不同的翻译，分别是"bccfi", "bwfi", "bczi", "mcfi"和"mzi"
 
提示：
0 <= num < 2^31
*/

/*
年轻人的第一次动态规划
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	int translateNum(int num) {
		if (num < 10) { return 1; }
		//状态转移方程为:
		//到第i个位置dp[i] = dp[i - 1] + 1+dp[i - 2]或者dp[i] = dp[i-1]
		//前i-1种情况+把当前数字单独翻译为字符；前i-2种情况+把当前数字和前一个数字组合起来翻译为字符
		//那这样的话先把num转换为string，要分情况
		string s = to_string(num);
		int len = s.length();
		vector<int> dp(len + 1);
		dp[1] = 1; // 显而易见 dp[1] = 1
		dp[0] = 1; // 比如 num = 12，有两种方法，即 dp[2] = dp[1] + dp[0]，可得 dp[0] = 1

		for (int i = 2; i < len + 1; ++i) {
			if (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '5')) {
				dp[i] = dp[i - 2] + dp[i - 1];
			}
			else {
				dp[i] += dp[i - 1];
				//这里还不太懂
			}
		}

		return dp[len];
	}


};

int main() {
	Solution solu;

	cout << solu.translateNum(13213) << endl;
}
