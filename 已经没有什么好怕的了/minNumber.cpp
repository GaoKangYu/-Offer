/*
Day2
剑指 Offer 45. 把数组排成最小的数

输入一个非负整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。

 

示例 1:
输入: [10,2]
输出: "102"

示例 2:
输入: [3,30,34,5,9]
输出: "3033459"
 

提示:
0 < nums.length <= 100

说明:
输出结果可能非常大，所以你需要返回一个字符串而不是整数
拼接起来的数字可能会有前导 0，最后结果不需要去掉前导 0
*/

/*
思路
*/

#include <iostream>
#include <vector>
#include <string>


using namespace std;

class Solution {
public:
	string minNumber(vector<int>& nums) {
		int n = nums.size();
		vector<string> _nums(n);
		for (int i = 0; i < n; ++i) {
			_nums[i] = to_string(nums[i]);
		}
		//自定义排序，很有意思的题目
		quick_sort(_nums, 0, n - 1);
		string ret = "";
		for (auto n : _nums) {
			ret += n;
		}
		return ret;
	}

	void quick_sort(vector<string>& _nums, int left, int right) {
		if (left >= right) {
			return;
		}
		int i = left;
		int j = right;
		string base = _nums[left];
		while (i < j) {
			//从右到左找到一个比基准值小的
			while (i < j && _nums[j] + base >= base + _nums[j]) {
				--j;
			}
			//从左到右找到一个比基准值大的
			while (i < j && _nums[i] + base <= base + _nums[i]) {
				++i;
			}
			swap(_nums[i], _nums[j]);
		}
		swap(_nums[i], _nums[left]);
		quick_sort(_nums, left, i - 1);
		quick_sort(_nums, i + 1, right);
	}
};

int main() {

}
