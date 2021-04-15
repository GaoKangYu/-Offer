/*
剑指 Offer 14- I. 剪绳子

给你一根长度为 n 的绳子，请把绳子剪成整数长度的 m 段（m、n都是整数，n>1并且m>1），
每段绳子的长度记为 k[0],k[1]...k[m-1] 。请问 k[0]*k[1]*...*k[m-1] 可能的最大乘积是多少？
例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。

示例 1：
输入: 2
输出: 1
解释: 2 = 1 + 1, 1 × 1 = 1

示例 2:
输入: 10
输出: 36
解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36

提示：
2 <= n <= 58
*/

/*
数学方法，但是这周dp得学，明天

剪绳子，用3当因子最佳，数学结论，记住“尽可能将绳子以长度3等分为多段时，乘积最大”


*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int cuttingRope(int n) {
		if (n <= 3) {
			return n - 1;
		}
		int ret = 1;
		while (n > 4) {
			ret *= 3;
			n -= 3;
		}
		return ret * n;
	}

	int input() {
		int ret;
		scanf_s("%d", &ret);
		return ret;
	}
};

int main() {
	Solution solu;
	int input = solu.input();
	cout << "Result : " << solu.cuttingRope(input) << endl;;
}
