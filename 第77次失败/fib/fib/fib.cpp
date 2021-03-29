/*
剑指 Offer 10- I. 斐波那契数列

写一个函数，输入 n ，求斐波那契（Fibonacci）数列的第 n 项（即 F(N)）。斐波那契数列的定义如下：
F(0) = 0,   F(1) = 1
F(N) = F(N - 1) + F(N - 2), 其中 N > 1.
斐波那契数列由 0 和 1 开始，之后的斐波那契数就是由之前的两数相加而得出。
答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。

示例 1：
输入：n = 2
输出：1

示例 2：
输入：n = 5
输出：5
 
提示：
0 <= n <= 100
*/

/*
剑指offer是最基础的算法、解法入门
原来是这样，我完全懂了

上楼梯问题的通解，动态规划
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int fib(int n) {
		if (n == 0) {
			return 0;
		}
		int f_0 = 0;
		int f_1 = 1;
		int f_n = 1;
		for (int i = 1; i < n; ++i) {
			//挪动的思想
			/*
			过程：
			*/
			f_0 = f_1;
			f_1 = f_n;
			f_n = (f_1 + f_0) % 1000000007;
		}
		return f_1 % 1000000007;
	}
};

int main()
{
	std::cout << "Hello World!\n";
}

