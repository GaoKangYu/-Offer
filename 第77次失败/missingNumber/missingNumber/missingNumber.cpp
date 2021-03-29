/*
剑指 Offer 53 - II. 0～n-1中缺失的数字

一个长度为n-1的递增排序数组中的所有数字都是唯一的，并且每个数字都在范围0～n-1之内。
在范围0～n-1内的n个数字中有且只有一个数字不在该数组中，请找出这个数字。

示例 1:
输入: [0,1,3]
输出: 2

示例 2:
输入: [0,1,2,3,4,5,6,7,9]
输出: 8
 
限制：
1 <= 数组长度 <= 10000
*/

/*
标准二分法
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int missingNumber(vector<int>& nums) {
		int i = 0;
		int j = nums.size() - 1;
		while (i <= j) {
			int mid = i + (j - i) / 2;
			if (nums[mid] == mid) { // mid之前的元素位置正确 
				i = mid + 1; //查找后面的元素情况
			}
			else { //mid之后的元素位置正确
				j = mid - 1; //查找前面的元素情况
			}
		}
		return i;
	}

	vector<int> input() {
		printf("Please input numbers, ended by 'enter' \n");
		int val;
		vector<int> ret;
		do{
			scanf_s("%d", &val);
			ret.push_back(val);
		} while (getchar() != '\n');
		print_result(ret);
		return ret;
	}

	void print_result(vector<int> input) {
		printf("Input vector : [");
		for (int i = 0; i < input.size(); ++i){
			printf("%d", input[i]);
			if (i != input.size() - 1){
				printf(" ");
			}
		}
		printf("] \n");
	}
};

int main(){
	Solution solu;
	vector<int> input;
	input = solu.input();
	int result;
	result = solu.missingNumber(input);
	printf("%d \n", result);
}

