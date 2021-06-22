/*
Day3
剑指 Offer 66. 构建乘积数组

给定一个数组 A[0,1,…,n-1]，请构建一个数组 B[0,1,…,n-1]，其中 B[i] 的值是数组 A 中除了下标 i 以外的元素的积,
即 B[i]=A[0]×A[1]×…×A[i-1]×A[i+1]×…×A[n-1]。不能使用除法。

 

示例:
输入: [1,2,3,4,5]
输出: [120,60,40,30,24]

提示：
所有元素乘积之和不会溢出 32 位整数
a.length <= 100000
*/

/*
思路
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> constructArr(vector<int>& a) {
		int len = a.size();
		if (len < 2) {
			return a;
		}
		//两次乘法，复用乘积
		vector<int> ret(len, 1);
		for (int i = 0, tmp = 1; i < len; tmp *= a[i], ++i) {
			ret[i] = tmp;
		}
		//逆向再乘一次
		for (int i = len - 1, tmp = 1; i >= 0; tmp *= a[i], --i) {
			ret[i] *= tmp;
		}
		return ret;
	}
};

int main() {

}
