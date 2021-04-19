/*
剑指 Offer 61. 扑克牌中的顺子

从扑克牌中随机抽5张牌，判断是不是一个顺子，即这5张牌是不是连续的。
2～10为数字本身，A为1，J为11，Q为12，K为13，而大、小王为 0 ，可以看成任意数字。
A 不能视为 14。

示例 1:
输入: [1,2,3,4,5]
输出: True
 
示例 2:
输入: [0,0,1,2,5]
输出: True
 
限制：
数组长度为 5 
数组的数取值为 [0, 13] .
*/

/*
思路
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	bool isStraight_violence(vector<int>& nums) {
		//还是觉得需要排序一下
		quick_sort(0, nums.size() - 1, nums);
		int ghost_num = 0;
		int index = 0;
		while (nums[index] == 0) {
			++ghost_num;
			++index;
		}
		for (; index < 4; ++index) {
			if (nums[index + 1] - nums[index] != 1 && ghost_num) {
				--ghost_num;
				++nums[index];
				--index;
			}
			else if (nums[index + 1] - nums[index] != 1) {
				return false;
			}
		}
		return true;
	}

	bool isStraight(vector<int>& nums) {
		//还是觉得需要排序一下
		sort(nums.begin(), nums.end());
		int ghost_num = 0;
		//题目的很多条件都没有用上，只有5张牌，如果是顺子那么最大的减最小的应该差小于5
		//还是先统计癞子数目
		for (int index = 0; index < 4; ++index) {
			if (nums[index] == 0) {
				++ghost_num;
			}
			else if (nums[index] == nums[index + 1]) {
				return false;
			}
		}
		return nums[4] - nums[ghost_num] < 5;
	}

	void quick_sort(int left, int right, vector<int>& nums) {
		if (left >= right) {
			return;
		}
		int i = left;
		int j = right;
		int base = nums[left];
		while (i < j) {
			while (i < j && nums[j] >= base) {
				--j;
			}
			while (i < j && nums[i] <= base) {
				++i;
			}
			swap(nums[i], nums[j]);
		}
		swap(nums[i], nums[left]);
		quick_sort(left, i - 1, nums);
		quick_sort(i + 1, right, nums);
	}
};

int main() {
	Solution solu;
	vector<int> sort_test{1,2,3,4,5};
	cout << solu.isStraight(sort_test) << endl;
}
