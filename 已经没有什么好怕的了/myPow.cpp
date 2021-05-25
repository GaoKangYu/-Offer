/*
Day2
剑指 Offer 16. 数值的整数次方

实现 pow(x, n) ，即计算 x 的 n 次幂函数（即，x^n）。不得使用库函数，同时不需要考虑大数问题。

示例 1：

输入：x = 2.00000, n = 10
输出：1024.00000
示例 2：

输入：x = 2.10000, n = 3
输出：9.26100
示例 3：

输入：x = 2.00000, n = -2
输出：0.25000
解释：2-2 = 1/22 = 1/4 = 0.25
 

提示：
-100.0 < x < 100.0
-2^31 <= n <= 2^31-1
-10^4 <= x^n <= 10^4
*/

/*
思路
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	double myPow(double x, int n) {
		if (n == 0) {
			return 1;
		}
		if (x == 0 || x == 1) {
			return x;
		}
		double res = 1;
		long _n = n;
		if (n < 0) {
			_n = -_n;
			x = 1.0 / x;
		}
		//快速幂
		//只有在1的位置上，才有相应的权重
		while (_n) {
			if (_n & 1) {
				//积累权重
				res *= x;
			}
			//推移权重
			x *= x;
			_n >>= 1;
		}
		return res;
	}
};

int main() {

}
