/*
Day2
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
思路
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int add(int a, int b) {
		//两数相加，位运算
		//可以先画真值表统计出所有的情况
		//可以发现无进位和的值与异或运算相同，进位值与与运算情况相同
		//因此a+b = a^b + carry(a&b)<<1
		while (b) {
			int carry = (unsigned int)(a & b) << 1;
			a ^= b;
			b = carry;
		}
		return a;
	}
};

int main() {

}
