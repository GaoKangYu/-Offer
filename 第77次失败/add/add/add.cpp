/*
剑指 Offer 65. 不用加减乘除做加法

写一个函数，求两个整数之和，要求在函数体内不得使用 “+”、“-”、“*”、“/” 四则运算符号。

示例:
输入: a = 1, b = 1
输出: 2
 
提示：
a, b 均可能是负数或 0
结果不会溢出 32 位整数
*/

/*
不用加减乘除做加法

位运算

有符号数

算了背下来吧
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int add(int a, int b) {
		while (b) {
			int carry = (unsigned int)(a & b) << 1;
			a ^= b;
			b = carry;
		}
		return a;
	}

	void acm() {
		int test_nums;
		cin >> test_nums;
		while (test_nums){
			int a, b;
			cin >> a >> b;
			cout << add(a, b) << endl;
			--test_nums;
		}
	}
};

int main() {
	Solution solu;
	solu.acm();
}
