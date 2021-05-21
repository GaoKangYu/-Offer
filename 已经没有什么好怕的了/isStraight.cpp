/*
Day2
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

class Solution_usual {
public:
	bool isStraight(vector<int>& nums) {
		//先写通用方法，再写5张牌的方法
		//0是癞子
		sort(nums.begin(), nums.end());
		int count_ghost = 0;
		for (int i = 0; i < nums.size() - 1; ++i) {
			while (nums[i] == 0) {
				++count_ghost;
				++i;
			}
			//完成了癞子的统计
			int sub = nums[i + 1] - nums[i];
			if (sub == 1) {
				continue;
			}
			else {
				if (sub == 0) {
					return false;
				}
				else if (sub > count_ghost + 1) {
					return false;
				}
				else {
					count_ghost -= sub - 1;
				}
			}
		}
		return true;
	}
};


class Solution {
public:
	bool isStraight(vector<int>& nums) {
		quick_sort(nums, 0, nums.size() - 1);
		//统计癞子个数
		int ghost_count = 0;
		for (int i = 0; i < 4; ++i) {
			while (nums[i] == 0) {
				++ghost_count;
				++i;
			}
			if (nums[i] == nums[i + 1]) {
				return false;
			}
		}
		return nums[4] - nums[ghost_count] < 5;
	}

	void quick_sort(vector<int>& nums, int left, int right) {
		if (left >= right) {
			return;
		}
		int i = left;
		int j = right;
		int base = nums[left];
		while (i < j) {
			//从右到左找到一个比基准值小的
			while (i < j && nums[j] >= base) {
				--j;
			}
			//从左到右找到一个比基准值大的
			while (i < j && nums[i] <= base) {
				++i;
			}
			swap(nums[i], nums[j]);
		}
		swap(nums[i], nums[left]);
		quick_sort(nums, left, i - 1);
		quick_sort(nums, i + 1, right);
	}
};

int main() {

}
