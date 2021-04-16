/*
剑指 Offer 21. 调整数组顺序使奇数位于偶数前面

输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有奇数位于数组的前半部分，所有偶数位于数组的后半部分。

示例：
输入：nums = [1,2,3,4]
输出：[1,3,2,4]
注：[3,1,2,4] 也是正确的答案之一。
 

提示：
0 <= nums.length <= 50000
1 <= nums[i] <= 10000
*/

/*
交换位置，想到了快排，第一想法是改进快排

本质上是改变了“大小”的依据

复习快排

快排真是个好东西啊
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> exchange(vector<int>& nums) {
		quick_exchange(0, nums.size() - 1, nums);
		return nums;
	}

	void quick_exchange(int left, int right, vector<int>& nums) {
		int i = left;
		int j = right;
		while (i < j) {
			//左移j直到找到奇数
			while (i < j && (nums[j] % 2 == 0)) {
				--j;
			}
			//右移i直到找到偶数
			while (i < j && (nums[i] % 2 != 0)) {
				++i;
			}
			//交换
			if (i < j) {
				swap(nums[i], nums[j]);
			}
		}
	}

	void quick_sort(int left, int right, vector<int>& nums) {
		//递归边界条件
		if (left >= right){
			return;
		}
		int i = left;
		int j = right;
		int base = nums[left];
		while (i < j){
			//左移j直到找到比基本值小的
			while(i < j && nums[j] >= base) {
				--j;
			}
			//右移i直到找到比基本值大的
			while(i < j && nums[i] <= base) {
				++i;
			}
			if (i < j) {
				swap(nums[i], nums[j]);
			}
		}
		//基本值归位
		swap(nums[left], nums[i]);
		//递归左边
		quick_sort(left, i - 1, nums);
		//递归右边
		quick_sort(i + 1, right, nums);
	}
};

int main() {
	Solution solu;
	vector<int> input{1,4,5,5,8,1,2,3,4,9,0};
	cout << '[';
	for (int i = 0; i < input.size(); ++i) {
		cout << input[i];
		if (i < input.size() - 1) {
			cout << ',';
		}
	}
	cout << ']' << endl;
	solu.quick_exchange(0, input.size() - 1, input);
	cout << '[';
	for (int i = 0; i < input.size(); ++i){
		cout << input[i];
		if (i < input.size() - 1){
			cout << ',';
		}
	}
	cout << ']' << endl;
}
