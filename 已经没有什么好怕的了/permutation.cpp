/*
Day2
剑指 Offer 38. 字符串的排列

输入一个字符串，打印出该字符串中字符的所有排列。
你可以以任意顺序返回这个字符串数组，但里面不能有重复元素。

示例:
输入：s = "abc"
输出：["abc","acb","bac","bca","cab","cba"]
 
限制：
1 <= s 的长度 <= 8
*/

/*
思路
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

class Solution {
public:
	vector<string> ret;
	vector<string> permutation(string s) {
		//dfs+hash
		dfs(s, 0);
		return ret;
	}

	//dfs，传入s与从第几个字符开始处理
	void dfs(string s, int x) {
		//如果处理到了最后一个字符，加入ret列表
		if (x == s.size() - 1) {
			ret.push_back(s);
			return;
		}
		unordered_set<char> visit;
		for (int i = x; i < s.size(); ++i) {
			if (visit.find(s[i]) != visit.end()) {
				continue;
			}
			visit.insert(s[i]);
			swap(s[i], s[x]);
			dfs(s, x + 1);
			swap(s[i], s[x]);
		}
		
	}


};

int main() {
	Solution solu;
	vector<string> res = solu.permutation("abcd");
	for (auto s : res){
		cout << s << " ";
	}
	cout << endl;

}
