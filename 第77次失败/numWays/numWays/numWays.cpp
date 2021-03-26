/*
剑指 Offer 10- II. 青蛙跳台阶问题

一只青蛙一次可以跳上1级台阶，也可以跳上2级台阶。求该青蛙跳上一个 n 级的台阶总共有多少种跳法。
答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。

示例 1：
输入：n = 2
输出：2

示例 2：
输入：n = 7
输出：21

示例 3：
输入：n = 0
输出：1

提示：
0 <= n <= 100
*/

/*
经典动态规划
f(n) = f(n-1) + f(n-2)

f(0) = 1
f(1) = 1
f(2) = 2


*/

#include <iostream>
#include <vector>
using namespace std;

//草稿纸，很需要。。。循环进行的是一个推演过程，跟通项公式类似，那么需要确保的是，通项中的n n-1 n-2中的某一项是我需要的，那么直接返回它即可
class Solution {
public:
	int numWays(int n) {
		if (n == 0) {
			return 1;
		}
		int dp_1 = 2;
		int dp_2 = 1;
		int dp_n = 3;
		for (int i = 1; i < n; ++i) {
			dp_2 = dp_1;
			dp_1 = dp_n;
			dp_n = (dp_1 + dp_2) % 1000000007;
		}
		return dp_2;
	}
};

int main()
{
	std::cout << "Hello World!\n";
}

