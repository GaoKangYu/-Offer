/*
Day2
剑指 Offer 17. 打印从1到最大的n位数

输入数字 n，按顺序打印出从 1 到最大的 n 位十进制数。比如输入 3，则打印出 1、2、3 一直到最大的 3 位数 999。

示例 1:
输入: n = 1
输出: [1,2,3,4,5,6,7,8,9]
 

说明：
用返回一个整数列表来代替打印
n 为正整数
*/

/*
思路
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> printNumbers(int n) {
		//先找到n位最大值，然后自增至最大值
		int max_val = pow(10, n) - 1;
		vector<int> ret(max_val);
		for (int i = 0, j = 1; j <= max_val; ++i, ++j) {
			ret[i] = j;
		}
		return ret;
	}
};

int main() {
	Solution solu;
	vector<int> res = solu.printNumbers(4);
	cout << "[";
	for (int i = 0; i < res.size(); ++i){
		cout << res[i];
		if (i < res.size() - 1) {
			cout << ",";
		}
	}
	cout << "]" << endl;
}
