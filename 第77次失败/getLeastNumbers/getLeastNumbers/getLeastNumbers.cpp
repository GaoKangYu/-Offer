/*
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
如何在面试环节被羞辱：使用sort
如何在岗位上快速完成开发：使用sort

…

复习数据结构
大根堆
c++优先队列：堆顶是最大值，完美满足本题需求的一个数据结构
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:
	vector<int> getLeastNumbers(vector<int>& arr, int k) {
		if (k == 0 || arr.empty()){
			return {};
		}
		priority_queue<int> least_nums;
		vector<int> ret;
		//先把前k个数字压入大根堆
		for (int i = 0; i < k; ++i) {
			least_nums.push(arr[i]);
		}
		//从k+1开始遍历，如果有比大根堆中最大值还小的，去除大根堆顶的值，压入该值
		for (int i = k; i < arr.size(); ++i) {
			if (arr[i] < least_nums.top()) {
				least_nums.pop();
				least_nums.push(arr[i]);
			}
		}
		while (k) {
			ret.push_back(least_nums.top());
			least_nums.pop();
			--k;
		}
		return ret;
	}
};

int main()
{
	std::cout << "Hello World!\n";
}

