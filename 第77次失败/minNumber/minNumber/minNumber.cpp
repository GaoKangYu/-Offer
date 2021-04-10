/*
剑指 Offer 45. 把数组排成最小的数

输入一个非负整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。

示例 1:
输入: [10,2]
输出: "102"

示例 2:
输入: [3,30,34,5,9]
输出: "3033459"
31333459
32333459
33333459
 
提示:
0 < nums.length <= 100

说明:
输出结果可能非常大，所以你需要返回一个字符串而不是整数
拼接起来的数字可能会有前导 0，最后结果不需要去掉前导 0
*/

/*
最小值，因为所有数字都要用上，所以位数不用考虑
需要保证每一位都是最小的
具体的实现可以当做一个特定规则的排序
第一位大则大，第一位同则比第二位，第二位大则大，如果只有一位，那么它的第二位视作与第一位相等

正好复习一下快排吧

行，难得思路完全一致

自定义排序
学到了模块化编程，实现某一功能，就完全不要管其他地方了，保证接口正确即可
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

//空间占用小但慢
class Solution {
public:
	string minNumber(vector<int>& nums) {
		quick_sort(0, nums.size() - 1, nums);
		string ret;
		for (auto n : nums) {
			ret += to_string(n);
		}
		return ret;
	}

	void quick_sort(int left, int right, vector<int>& nums) {
		//快排的核心：选定一个基本点，使用两个指针，最终使得基本点左边的值比它小，右边的值比它大
		//那么我需要改写的就是这个比较大小的条件即可
		//边界条件，结束递归
		if (left >= right) {
			return;
		}
		int i = left;
		int j = right;
		//以最左端作为基准点
		int base = nums[left];
		while (i < j) {
			//先动尾部，直到指向比基准点小的位置
			while (is_bigger(nums[j], base) && i < j) {
				--j;
			}
			//再动头部，直到指向比基准点大的位置
			while (is_bigger(base, nums[i]) && i < j) {
				++i;
			}
			//如果此时比基准点大的在左，比基准点小的在右，代表没有排序完成，交换这两个值
			if (i < j) {
				swap(nums[i], nums[j]);
			}
		}
		//此时基于该基准点完成了排序，两个指针相遇，基准点归位，完成该基准点下的排序
		swap(nums[left], nums[i]);
		//基于此规则完成基准点左侧的排序
		quick_sort(left, i - 1, nums);
		//完成右侧的排序
		quick_sort(i + 1, right, nums);
	}

	bool is_bigger(int val_1, int val_2) {
		//学到了学到了，模块化编程，只需要完成此单功能就好
		//直接最核心最根本的问题，为啥val_1比val_2大？
		//因为数字 val_1val_2 > val_2val_1
		string str_1 = to_string(val_1);
		string str_2 = to_string(val_2);
		if (str_1 + str_2 >= str_2 + str_1) {
			return true;
		}
		else {
			return false;
		}
	}
};

//快但占空间
class Solution_save_time {
public:
	string minNumber(vector<int>& nums) {
		quick_sort(0, nums.size() - 1, nums);
		string ret;
		for (auto n : nums) {
			ret += to_string(n);
		}
		return ret;
	}

	void quick_sort(int left, int right, vector<int>& nums) {
		//快排的核心：选定一个基本点，使用两个指针，最终使得基本点左边的值比它小，右边的值比它大
		//那么我需要改写的就是这个比较大小的条件即可
		//边界条件，结束递归
		if (left >= right) {
			return;
		}
		int i = left;
		int j = right;
		//以最左端作为基准点
		int base = nums[left];
		while (i < j) {
			//先动尾部，直到指向比基准点小的位置
			while (is_bigger(nums[j], base) && i < j) {
				--j;
			}
			//再动头部，直到指向比基准点大的位置
			while (is_bigger(base, nums[i]) && i < j) {
				++i;
			}
			//如果此时比基准点大的在左，比基准点小的在右，代表没有排序完成，交换这两个值
			if (i < j) {
				swap(nums[i], nums[j]);
			}
		}
		//此时基于该基准点完成了排序，两个指针相遇，基准点归位，完成该基准点下的排序
		swap(nums[left], nums[i]);
		//基于此规则完成基准点左侧的排序
		quick_sort(left, i - 1, nums);
		//完成右侧的排序
		quick_sort(i + 1, right, nums);
	}

	bool is_bigger(int val_1, int val_2) {
		//学到了学到了，模块化编程，只需要完成此单功能就好
		//直接最核心最根本的问题，为啥val_1比val_2大？
		//因为数字 val_1val_2 > val_2val_1
		string str_1 = to_string(val_1);
		string str_2 = to_string(val_2);
		if (str_1 + str_2 >= str_2 + str_1) {
			return true;
		}
		else {
			return false;
		}
	}
};

int main() {
	Solution solu;
	vector<int> input{3,30};
	solu.quick_sort(0, input.size() - 1, input);
	string res;
	res = solu.minNumber(input);
	cout << "Result : " << res << endl;
}

