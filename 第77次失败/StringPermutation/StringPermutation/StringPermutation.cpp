/*
StringPermutation.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
*/

/*
输入一个字符串，打印出该字符串中字符的所有排列。
你可以以任意顺序返回这个字符串数组，但里面不能有重复元素。

示例:
输入：s = "abc"
输出：["abc","acb","bac","bca","cab","cba"]
 
限制：
1 <= s 的长度 <= 8
*/

/*
全排列，回溯算法问题
*/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
	vector<string> permutation(string s) {
		dfs(s, 0);
		return res;
	}
private:
	vector<string> res;
	void dfs(string s, int x) {
		if (x == s.size() - 1) {
			res.push_back(s);                       // 添加排列方案
			return;
		}
		unordered_set<int> st;
		for (int i = x; i < s.size(); i++) {
			if (st.find(s[i]) != st.end()) continue; // 重复，因此剪枝
			st.insert(s[i]);
			swap(s[i], s[x]);                       // 交换，将 s[i] 固定在第 x 位
			dfs(s, x + 1);                          // 开启固定第 x + 1 位字符
			swap(s[i], s[x]);                       // 恢复交换
		}
	}
};

int main()
{
    std::cout << "Hello World!\n";
}

