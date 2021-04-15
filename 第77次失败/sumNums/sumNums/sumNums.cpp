/*
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
数学+1，（首项+尾项） * 项数 / 2

但是不让用乘法，wtf

但是还是拓展了思路，八股背多了是这样的，拓展思路啊xd，每天能学到新东西真是太好了

基于法一继续优化

本质上是将  (n+1)*n/2 中题目不允许的操作给替换掉，除法可以用位右移操作>>

得到法二，利用语言自带的特性，sizeof

法二不安全，再次改进

替换乘法，快速乘法
例如，求A*B
A二进制展开，二进制A的第i位1对乘法的贡献为1<<i，所以需要将二进制A中的每一个1拿去贡献，然后将这些值累加起来，又因为不能用for
所以根据题目范围，n 为 [1,10000]，所以 n 二进制展开最多不会超过 14 位，所以写14层循环展开就可以

学到了新知识  &  这个是位运算符，A & 1是A的二进制形式与00000001按位取与，不要总惦记着你的十进制
以及，&&是逻辑运算符，有短路原则，&&前半为0，后半就不算了，因此才出现ans为0,的情况，woc好巧妙，这样的做法还控制了多次循环的情况下，后续循环不再加A
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int sumNums_1(int n) {
		int ret = 1;
		ret = (1 + n) * n / 2;
		return ret;
	}

	int sumNums_2(int n) {
		//一个int占4个byte，因此需要>>3，如果是bool或者char则占1个byte，直接>>1就可以
		//这确实是不安全的行为，因此舍弃该方法，取巧的，算了
		//bool nums[n][n + 1];
		//return sizeof(nums)>>1;
	}

	int sumNums_3(int n) {
		int ans = 0;
		int A = n;
		int B = n + 1;

		(B & 1) && (ans += A);
		B >>= 1;
		A <<= 1;
		cout << "B = "<<B<<endl;
		cout << "A = "<<A<<endl;
		cout << "ans = " << ans << endl;

		(B & 1) && (ans += A);
		B >>= 1;
		A <<= 1;
		cout << "B = " << B << endl;
		cout << "A = " << A << endl;
		cout << "ans = " << ans << endl;

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

	int input() {
		int ret;
		scanf_s("%d", &ret);
		return ret;
	}
};

int main() {
	Solution solu;
	int input = solu.input();
	cout << "Result : " << solu.sumNums_3(input);
}
