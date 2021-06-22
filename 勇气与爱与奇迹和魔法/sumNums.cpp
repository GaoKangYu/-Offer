/*
Day3
剑指 Offer 64. 求1+2+…+n

求 1+2+...+n ，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。

示例 1：
输入: n = 3
输出: 6

示例 2：
输入: n = 9
输出: 45
 

限制：
1 <= n <= 10000
*/

/*
思路
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int sumNums(int n) {
		int ans = 0;
		int A = n;
		int B = n + 1;

		(B & 1) && (ans += A);
		B >>= 1;
		A <<= 1;

		(B & 1) && (ans += A);
		B >>= 1;
		A <<= 1;

		(B & 1) && (ans += A);
		B >>= 1;
		A <<= 1;

		(B & 1) && (ans += A);
		B >>= 1;
		A <<= 1;

		(B & 1) && (ans += A);
		B >>= 1;
		A <<= 1;

		(B & 1) && (ans += A);
		B >>= 1;
		A <<= 1;

		(B & 1) && (ans += A);
		B >>= 1;
		A <<= 1;

		(B & 1) && (ans += A);
		B >>= 1;
		A <<= 1;

		(B & 1) && (ans += A);
		B >>= 1;
		A <<= 1;

		(B & 1) && (ans += A);
		B >>= 1;
		A <<= 1;

		(B & 1) && (ans += A);
		B >>= 1;
		A <<= 1;

		(B & 1) && (ans += A);
		B >>= 1;
		A <<= 1;

		(B & 1) && (ans += A);
		B >>= 1;
		A <<= 1;

		(B & 1) && (ans += A);
		B >>= 1;
		A <<= 1;

		return ans >> 1;
	}
};

int main() {

}
