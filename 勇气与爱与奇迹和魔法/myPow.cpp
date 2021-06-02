/*
Day3
剑指 Offer 16. 数值的整数次方

实现 pow(x, n) ，即计算 x 的 n 次幂函数（即，xn）。不得使用库函数，同时不需要考虑大数问题。

 

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
快速幂，积累权重，n的某一位是1才需要累乘，累乘！！
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	double myPow(double x, int n) {
		//首先预处理数值，排除部分特殊情况
		if (x == 0) {
			return 0;
		}
		if (n == 0) {
			return 1;
		}
		long _n = n;
		//如果是负次幂，x为倒数，
		if (_n < 0) {
			_n = -_n;
			x = 1.0 / x;
		}
		//开始快速幂运算
		double res = 1;
		while (_n) {
			if (_n & 1) {
				res *= x;
			}
			x *= x;
			_n >>= 1;
		}
		return res;
	}
};

int main() {

}
