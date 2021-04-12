/*
剑指 Offer 60. n个骰子的点数

把n个骰子扔在地上，所有骰子朝上一面的点数之和为s。输入n，打印出s的所有可能的值出现的概率。
你需要用一个浮点数数组返回答案，其中第 i 个元素代表这 n 个骰子所能掷出的点数集合中第 i 小的那个的概率。


示例 1:
输入: 1
输出: [0.16667,0.16667,0.16667,0.16667,0.16667,0.16667]

示例 2:
输入: 2
输出: [0.02778,0.05556,0.08333,0.11111,0.13889,0.16667,0.13889,0.11111,0.08333,0.05556,0.02778]
 

限制：
1 <= n <= 11
*/

/*
行，，，题目看懂了
数学题
就不能说人话吗xd

n个骰子，数字范围（同时也是数组长度）n--->6n，长度为5n+1
问题转换为：
n个骰子，掷出和为k的概率是多少？

。。没学会，xd，但是从数学角度，感觉每轮的值都是固定的
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<double> dicesProbability(int n) {
		vector<double> dp(6, 1.0 / 6.0);
		for (int i = 2; i <= n; i++) {
			vector<double> tmp(5 * i + 1, 0);
			for (int j = 0; j < dp.size(); j++) {
				for (int k = 0; k < 6; k++) {
					tmp[j + k] += dp[j] / 6.0;
				}
			}
			dp = tmp;
		}
		return dp;
	}

	int input() {
		int ret;
		scanf_s("%d", &ret);
		return ret;
	}
};

int main() {
	Solution solu;
	int input = solu.input();
	vector<double> res;
	res = solu.dicesProbability(input);
	cout << '[';
	for (int i = 0; i < res.size(); ++i){
		printf("%.5f", res[i]);
		if (i < res.size() - 1){
			cout << ',';
		}
	}
	cout << ']' << endl;
}

