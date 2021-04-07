/*
剑指 Offer 63. 股票的最大利润
假设把某股票的价格按照时间先后顺序存储在数组中，请问买卖该股票一次可能获得的最大利润是多少？

示例 1:
输入: [7,1,5,3,6,4]
输出: 5
解释: 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
	 注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格。

示例 2:
输入: [7,6,4,3,1]
输出: 0
解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。
 
限制：0 <= 数组长度 <= 10^5
*/

/*
小根堆
队顶始终是最小值，比它小，入栈，比它大，更新利润值，直到结束
尝试一下

没问题，但实际上可以用常数来维护这个最小值

实现空间O（1）
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int max_profit = 0;
		priority_queue<int, vector<int>, greater<int>> min_queue;
		int n = prices.size();
		if (prices.empty()) {
			return 0;
		}
		min_queue.push(prices[0]);
		for (int i = 1; i < n; ++i) {
			if (min_queue.top() > prices[i]) {
				min_queue.push(prices[i]);
			}
			else if (min_queue.top() < prices[i]) {
				int profit = prices[i] - min_queue.top();
				max_profit = max(max_profit, profit);
			}
		}
		return max_profit;
	}

	int maxProfit_better(vector<int>& prices) {
		int max_profit = 0;
		int min_price = 1e9;
		int n = prices.size();
		for (auto p : prices){
			max_profit = max(max_profit, p - min_price);
			min_price = min(min_price, p);
		}
		return max_profit;
	}

	vector<int> input() {
		vector<int> ret;
		int tmp;
		while (scanf_s("%d", &tmp)){
			ret.push_back(tmp);
			if (getchar() == '\n') {
				break;
			}
		};
		print_result(ret);
		return ret;
	}

	void print_result(vector<int> result) {
		printf("Vector : ");
		for (auto r : result){
			printf("%d ", r);
		}
		printf("\n");
	}
};

int main() {
	Solution solu;
	vector<int> input;
	input = solu.input();
	printf("Max profit is : %d", solu.maxProfit(input));
}

