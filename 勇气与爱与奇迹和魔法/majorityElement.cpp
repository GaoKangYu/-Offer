/*
Day3
剑指 Offer 39. 数组中出现次数超过一半的数字

数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
你可以假设数组是非空的，并且给定的数组总是存在多数元素。

示例 1:
输入: [1, 2, 3, 2, 2, 2, 5, 4, 2]
输出: 2
*/

/*
摩尔投票法

本质上是因为所求元素很多，极限一换一最后剩下的肯定是所求，因此
设置一个vote
vote为0则
3 3 4 

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int majorityElement(vector<int>& nums) {
		int vote = 1;
		int ret = nums[0];
		for (int i = 1; i < nums.size(); ++i)
		{
			if (ret == nums[i]) {
				++vote;
			}
			else {
				--vote;
			}
			if (vote == 0) {
				ret = nums[i];
				++vote;
			}
		}
		return ret;
	}

};

class Solution_better {
public:
	int majorityElement(vector<int>& nums) {
		int vote = 0;
		int ret = 0;
		for (int n : nums) {
			if (vote == 0) {
				ret = n;
			}
			vote += ret == n ? 1 : -1;
		}
		return ret;
	}
};

int main() {
	vector<int> input{ 1, 2, 3, 4, 5, 6, 6, 6, 6, 6, 6 };
	Solution solu;
	cout << "Res = " << solu.majorityElement(input) << endl;
}
