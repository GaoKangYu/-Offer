/*
Day3
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

扩展练习：
尝试以 O(n log k) 时间复杂度和 O(n) 空间复杂度解决。
*/

/*
思路
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	//哈希+排序
	//map 和 unordered_map有什么区别？
	vector<string> topKFrequent(vector<string>& words, int k) {
		unordered_map<string, int> count;
		for (string& word : words) {
			//没有这个key则插入，有则自增value
			++count[word];
		}
		//至此完成了单词频次统计
		//定义返回vec，大小为k
		int n = count.size();
		vector<string> ret(n);
		int i = 0;
		for (auto& c : count) {
			ret[i] = c.first;
			++i;
		}
		//需要对vec进行排序，按value降序、value相同则按字母升序
		//lambda表达式[]()->{}
		sort(ret.begin(), ret.end(), [&](const string& a, const string& b) -> bool {
			return count[a] == count[b] ? a < b : count[a] > count[b];
			});
		ret.erase(ret.begin() + k, ret.end());
		return ret;
	}

	void show_res(vector<string>& res, int k) {
		cout << "[";
		for (int i = 0; i < k; ++i) {
			cout << res[i];
			if (i < k - 1) {
				cout << ", ";
			}
		}
		cout << "]" << endl;
	}
};

int main() {
	Solution solu;
	vector<string> input{ "the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is" };
	int k = 3;
	vector<string> output = solu.topKFrequent(input, k);
	solu.show_res(output, k);
}
