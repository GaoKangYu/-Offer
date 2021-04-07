/*
剑指 Offer 56 - I. 数组中数字出现的次数

一个整型数组 nums 里除两个数字之外，其他数字都出现了两次。请写程序找出这两个只出现一次的数字。

要求时间复杂度是O(n)，空间复杂度是O(1)。

示例 1：
输入：nums = [4,1,4,6]
输出：[1,6] 或 [6,1]

示例 2：
输入：nums = [1,2,10,4,1,4,3,3]
输出：[2,10] 或 [10,2]
 

限制：
2 <= nums.length <= 10000
*/

/*
第一想法是辅助空间，哈希或者栈都可以，但是空间要求O（1），就代表唯一能够使用的空间就是返回的vector
先排序，那么可以做到
可以不排序吗？

题目条件很特殊：除了两个数字以外，其他数字都出现了两次，找出两个只出现了一次的数字

新知识，异或

异或，同为0，不同为1，满足交换律，那么，如果只有1个出现一次的值，不论顺序，全部元素异或，最后得到的值就是所求值
题目要求找到两个，因此需要分组
两个值，分成两组，分别执行上述思路即可
如何分组？
首先对整个元素执行一次异或
得到x@y的值
随后使用一个m开始分组的工作
目前这个m的作用还是没搞懂
先背
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> singleNumbers(vector<int>& nums) {
		int x = 0, y = 0, n = 0, m = 1;
		for (auto num : nums){
			n ^= num;
		}
		//找到那个为1的位，符合条件的m有多个，只需要其中一个即可，与00000001取与运算即可
		while ((n & m) == 0){
			//左移位运算，右边自动补零
			m <<= 1;
		}
		//异或满足交换律，第一步异或，相同的数其实都抵消了，剩下两个不同的数。这两个数异或结果肯定有某一位为1，不然都是0的话就是相同数。
		//找到这个位，不同的两个数一个在此位为0，另一个为1。
		//按此位将所有数分成两组，分开后各自异或，相同的两个数异或肯定为0（而且分开的时候，两个数必为一组）。
		//剩下的每组里就是我门要找的数。
		for (auto num : nums){
			if (m & num){
				x ^= num;
			}
			else{
				y ^= num;
			}
		}
		return vector<int> {x, y};
	}

	vector<int> input() {
		vector<int> input;
		int tmp;
		while (scanf_s("%d", &tmp)){
			input.push_back(tmp);
			if (getchar() == '\n'){
				break;
			}
		}
		show_result(input);
		return input;
	}

	void show_result(vector<int>& res) {
		printf("[");
		for (auto r : res){
			printf("%d ", r);
		}
		printf("]\n");
	}
};

int main() {
	Solution solu;
	vector<int> input;
	input = solu.input();
	vector<int> result;
	result = solu.singleNumbers(input);
	solu.show_result(result);
}

