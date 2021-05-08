/*
Day2
剑指 Offer 39. 数组中出现次数超过一半的数字

数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。

 

你可以假设数组是非空的，并且给定的数组总是存在多数元素。

 

示例 1:
输入: [1, 2, 3, 2, 2, 2, 5, 4, 2]
输出: 2
 

限制：
1 <= 数组长度 <= 50000
*/

/*
思路
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

//常规解法，哈希，O（n） + O（n）
class Solution_v1{
public:
	int majorityElement(vector<int>& nums) {
		//第一想法还是用哈希
		int n = nums.size();
		unordered_map<int, int> count;
		for (auto num : nums) {
			++count[num];
		}
		for (auto c : count) {
			if (c.second > n / 2) {
				return c.first;
			}
		}
		return nums[0];
	}
};

//摩尔投票法，很巧妙的方法
class Solution {
public:
	int majorityElement(vector<int>& nums) {
		//相同则计数加一，不同则极限一换一
		int x = 0, vote = 0;
		for (auto n : nums) {
			if (vote == 0) {
				x = n;
			}
			vote += (x == n ? 1 : -1);
		}
		return x;
	}

	void acm() {
		int val;
		vector<int> input;
		while (cin >> val){
			input.push_back(val);
			if (getchar() == '\n') {
				break;
			}
		}
		cout << "Res : " << majorityElement(input) << endl;
	}
};

int main() {
	Solution solu;
	solu.acm();
}
