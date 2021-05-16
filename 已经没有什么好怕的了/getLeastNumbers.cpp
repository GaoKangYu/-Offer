/*
Day2
剑指 Offer 40. 最小的k个数

输入整数数组 arr ，找出其中最小的 k 个数。例如，输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4。


示例 1：
输入：arr = [3,2,1], k = 2
输出：[1,2] 或者 [2,1]

示例 2：
输入：arr = [0,1,2,1], k = 1
输出：[0]
 

限制：
0 <= k <= arr.length <= 10000
0 <= arr[i] <= 10000
*/

/*
思路
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> getLeastNumbers(vector<int>& arr, int k) {
		vector<int> ret(k);
		quick_sort(arr, 0, arr.size() - 1);
		for (int i = 0; i < k; ++i) {
			ret[i] = arr[i];
		}
		return ret;
	}

	void quick_sort(vector<int>& nums, int left, int right) {
		if (left >= right) {
			return;
		}
		int i = left;
		int j = right;
		int base = nums[left];
		//从大到小
		while (i < j) {
			//从右往左找到一个比基准值小的
			while (i < j && nums[j] >= base) {
				--j;
			}
			//从左往右找到一个比基准值大的
			while (i < j && nums[i] <= base) {
				++i;
			}
			swap(nums[i], nums[j]);
		}
		//基准值归位
		swap(nums[i], nums[left]);
		//递归左边
		quick_sort(nums, left, i - 1);
		//递归右边
		quick_sort(nums, i + 1, right);
	}
};

int main() {

}
