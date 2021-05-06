/*
Day2
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
印象中是
所求乘积 = 其左边所有数乘积 * 其右边所有数乘积
因此需要两次求积
*/

#include <iostream>
#include <vector>

using namespace std;


//思路正确，但是效率很低，没有利用到累乘这个条件，每次都需要重复乘，重新赋值tmp
class Solution_v1 {
public:
	vector<int> constructArr(vector<int>& a) {
		int n = a.size();
		vector<int> ret(n, 1);
		//第一遍，求取该位置左边所有数的乘积
		for (int i = 0; i < n; ++i) {
			int tmp = 1;
			int j = 0;
			while (j < i){
				tmp *= a[i];
			}
			ret[i] *= tmp;
		}
		//至此，完成左边所有数的乘积
		//第二遍，求取该位置右边所有数乘积
		for (int i = n - 1; i >= 0; --i) {
			int tmp = 1;
			int j = n - 1;
			while (j > i) {
				tmp *= a[i];
			}
			ret[i] *= tmp;
		}
		return ret;
	}
};


//优化的点在于利用了累乘这个条件，节省了重复乘算中间值的时间
class Solution {
public:
	vector<int> constructArr(vector<int>& a) {
		int n = a.size();
		vector<int> ret(n);
		//第一遍，求取该位置左边所有数的乘积，注意，先乘，再增加下标，始终保持返回数组的ret[i]等于累乘至a[i-1]，这里使用赋值而不是*也可以节省时间
		for (int i = 0, tmp = 1; i < n; tmp *= a[i], ++i) {
			ret[i] = tmp;
		}
		//至此，完成左边所有数的乘积
		//第二遍，求取该位置右边所有数乘积，同样，保持ret[i] = 逆序累乘至a[i+1]，由此组合，可以跳过a[i]且不用除法
		for (int i = n - 1, tmp = 1; i >= 0; tmp *= a[i], --i) {
			ret[i] *= tmp;
		}
		return ret;
	}

	void showResult(vector<int>& res) {
		int n = res.size();
		cout << '[';
		for (int i = 0; i < n; ++i) {
			cout << res[i];
			if (i < n - 1) {
				cout << ", ";
			}
		}
		cout << ']' << endl;
	}

	void acm() {
		int test_nums;
		cin >> test_nums;
		while (test_nums){
			int val;
			vector<int> input;
			while (cin >> val){
				input.push_back(val);
				if (getchar() == '\n') {
					break;
				}
			}
			vector<int> res = constructArr(input);
			cout << "Input : " << endl;
			showResult(input);
			cout << "Output : " << endl;
			showResult(res);
			--test_nums;
		}
	}
};

int main() {
	Solution solu;
	solu.acm();
}
