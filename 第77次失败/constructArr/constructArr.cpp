/*
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
1、先计算全元素的积，然后除以A[i]，但是不能用除法
2、直接暴力O（N*N），但是肯定超时了
 1plus、用位运算替换除法，位运算除以2很好操作，除以其他的要如何操作？
 2plus、
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	//结果集中任何一个元素 = 其左边所有元素的乘积 * 其右边所有元素的乘积。
	//一轮循环构建左边的乘积并保存
	//二轮循环构建右边乘积的过程，乘以左边的乘积，并将最终结果保存
	vector<int> constructArr(vector<int>& a) {
		int n = a.size();
		vector<int> b(n);
		//第一次遍历，目的是计算并保存前i-1个数的乘积，回避乘i是通过辅助变量完成的
		//相当于后延了一步，每次b[i]存的是p*a[i-1]，秒啊
		for (int i = 0, p = 1; i < n; p *= a[i], ++i) {
			b[i] = p;
		}
		//第二次遍历，目的是计算并保存后i+1个数的乘积，回避乘i也是通过辅助变量
		//也是后延一步，每次b[i]乘的是p*a[i+1]
		for (int i = n - 1, p = 1; i >= 0; p *= a[i], --i) {
			b[i] *= p;
		}
		return b;
	}

	void acm_start() {
		int test_data_nums;
		cin >> test_data_nums;
		fflush(stdin);
		while (test_data_nums){
			vector<int> input_a;
			int val;
			while (cin >> val){
				input_a.push_back(val);
				if (getchar() == '\n') {
					break;
				}
			}
			fflush(stdin);
			vector<int> output_b = constructArr(input_a);
			cout << "[";
			for (int i = 0; i < output_b.size(); ++i){
				cout << output_b[i];
				if (i < output_b.size() - 1) {
					cout << ",";
				}
			}
			cout << "]" << endl;
			--test_data_nums;
		}
	}
};

int main() {
	Solution solu;
	solu.acm_start();
}
