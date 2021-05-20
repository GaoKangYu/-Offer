/*
Day2
692. 前K个高频单词

给一非空的单词列表，返回前 k 个出现次数最多的单词。

返回的答案应该按单词出现频率由高到低排序。如果不同的单词有相同出现频率，按字母顺序排序。

示例 1：

输入: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
输出: ["i", "love"]
解析: "i" 和 "love" 为出现次数最多的两个单词，均为2次。
	注意，按字母顺序 "i" 在 "love" 之前。
 

示例 2：

输入: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
输出: ["the", "is", "sunny", "day"]
解析: "the", "is", "sunny" 和 "day" 是出现次数最多的四个单词，
	出现次数依次为 4, 3, 2 和 1 次。
 

注意：
假定 k 总为有效值， 1 ≤ k ≤ 集合元素数。
输入的单词均由小写字母组成。
*/

/*
很好的一个hash模板题
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
	vector<string> topKFrequent(vector<string>& words, int k) {
		unordered_map<string, int> visit;
		//就很优雅，始终记得是visit[key]---->value
		for (auto& w : words) {
			++visit[w];
		}
		int len = visit.size();
		vector<string> ret(len);
		int i = 0;
		//就很优雅
		for (auto& pair : visit) {
			ret[i] = pair.first;
			++i;
		}
		//自定义排序规则，背下来
		sort(ret.begin(), ret.end(), [&](const string& a, const string& b) -> bool {
			//如果freq相等，按照字母升序排列，否则按照freq排序
			return visit[a] == visit[b] ? a < b : visit[a] > visit[b];
			});
		//擦除前k个word以外的值
		ret.erase(ret.begin() + k, ret.end());
		return ret;
	}
};

int main() {
	Solution solu;
	vector<string> input{"i", "love", "leetcode", "i", "love", "coding"};
	vector<string> res;
	int k = 2;
	res = solu.topKFrequent(input, k);
	for (auto& r : res) {
		cout << r << " ";
	}
	cout << endl;
}
