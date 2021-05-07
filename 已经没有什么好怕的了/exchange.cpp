/*
Day2
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
思路
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> exchange(vector<int>& nums) {
		//仍然是快排的swap思路
		//实际上只需要一次O（n）的遍历
		//双指针
		int n = nums.size();
		int slow = 0, fast = n - 1;
		while (slow < fast) {
			//慢指针找到一个偶数
			while (slow < fast && nums[slow] % 2 != 0) {
				++slow;
			}
			//cout << "慢指针找到了偶数"<<nums[slow]<<endl;
			//快指针找到一个奇数
			while (slow < fast && nums[fast] % 2 == 0) {
				--fast;
			}
			//cout << "快指针找到了奇数"<<nums[fast]<<endl;
			swap(nums[slow], nums[fast]);
		}
		return nums;
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
			cout << "Input : ";
			showRes(input);
			exchange(input);
			cout << "Output : ";
			showRes(input);
			--test_nums;
		}
	}

	void showRes(vector<int>& nums) {
		cout << '[';
		for (int i = 0; i < nums.size(); ++i) {
			cout << nums[i];
			if (i < nums.size() - 1) {
				cout << ", ";
			}
		}
		cout << ']' << endl;
	}
};

int main() {
	Solution solu;
	solu.acm();
}
