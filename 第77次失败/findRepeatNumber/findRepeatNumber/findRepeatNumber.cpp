// findRepeatNumber.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iterator>
#include <sstream>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <stack>

/*
	剑指 Offer 03. 数组中重复的数字
	找出数组中重复的数字。
	在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。
	数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。

	示例 1：
	输入：
	[2, 3, 1, 0, 2, 5, 3]
	输出：2 或 3
	*/
	/*
	因为只需要查一个，所以我直接打算哈希表了
	*/
	//效率一般  56 ms	26.8 MB
int findRepeatNumber(vector<int>& nums) {
	unordered_set<int> nums_count;
	for (int n : nums) {
		if (nums_count.find(n) != nums_count.end()) {
			return n;
		}
		else {
			nums_count.insert(n);
		}
	}
	return 0;
}
//试试排序吧，这个强一点，内存占用击败多  44 ms	22.3 MB
int findRepeatNumber_2(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size() - 1; ++i) {
		if (nums[i] == nums[i + 1]) {
			return nums[i];
		}
	}
	return 0;
}
//最佳解法 原地置换  24 ms	22.3 MB
//原理上，这就要看“长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内” 这一条件了
//这说明没有重复数字的情况下，排序完成后，0-n-1的下标正好对应0-n-1的值，所以只需要看下标和值是否一致，全一致，那就没有重复
//有不一致，拿去对比它该去的坑，如果和坑的值一样，那就是重复了，直接返回，否则换位，直到换到下标和值一一对应
//如果没有这样的限制，上一个方法或者哈希法是最佳的
int findRepeatNumber_well(vector<int>& nums) {
	for (int i = 0; i < nums.size(); i++) {
		while (nums[i] != i) {
			if (nums[nums[i]] == nums[i])
				return nums[i];
			else
				swap(nums[nums[i]], nums[i]);
		}
	}
	return -1;
}

int main()
{
    std::cout << "Hello World!\n";
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
