/*
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
哈希map
数组计数，没给取值的范围，不是很安全，先试试，没给范围，不安全

新方法，摩尔投票法，极限一换一
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int majorityElement_arry(vector<int>& nums) {
		int count[11]{ 0 };
		int ret = 0;
		int n = nums.size() - 1;
		for (int i = 0; i < nums.size(); ++i) {
			++count[nums[i]];
			if (count[nums[i]] > n / 2) {
				return nums[i];
			}
		}
		return 0;
	}

	int majorityElement(vector<int>& nums) {
		int x = 0, votes = 0;
		for (int num : nums) {
			//一换一结束了就重新开始
			if (votes == 0) x = num;
			//如果是自己人就加一，否则极限一换一
			//因为目标数是最多的，所以极限一换一的结果肯定是目标数
			votes += (num == x ? 1 : -1);
		}
		return x;
	}

	vector<int> input() {
		vector<int> ret;
		int val;
		while (scanf_s("%d", &val)){
			ret.push_back(val);
			if (getchar() == '\n') {
				break;
			}
		}
		fflush(stdin);
		return ret;
	}
};

int main() {
	Solution solu;
	vector<int> input = solu.input();
	cout << "Res : " << solu.majorityElement(input) << endl;
}
