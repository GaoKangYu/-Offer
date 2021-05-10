/*
Day2
剑指 Offer 11. 旋转数组的最小数字

把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。
例如，数组 [3,4,5,1,2] 为 [1,2,3,4,5] 的一个旋转，该数组的最小值为1。  

示例 1：

输入：[3,4,5,1,2]
输出：1
示例 2：

输入：[2,2,2,0,1]
输出：0
*/

/*
思路
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int minArray(vector<int>& numbers) {
		int start = 0;
		int end = numbers.size() - 1;
		//如果本来就是单增序列，直接返回首值即可
		if (numbers[start] < numbers[end]) {
			return numbers[start];
		}
		while (start < end) {
			int mid = start + (end - start) / 2;
			if (numbers[mid] < numbers[end]) {
				end = mid;
			}
			else if (numbers[mid] > numbers[end]) {
				++start;
			}
			else {
				--end;
			}
		}
		return numbers[start];
	}
};

int main() {

}
