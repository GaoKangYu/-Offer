/*
三次方回文

一个正整数自身是回文，同时是它某个回文数的三次方，那么它就是三次方回文数。
输入一组单调递增的数，找出其中的三次方回文数，如果没有找到则返回[]。
输入第一行为起始数字，第二行为结束数字。
*/

/*
遍历+判断，判断值是否为三次方回文，再开三次根号，判断是不是回文。
*/

#include <iostream>
#include <vector>
//使用sstream实现int转string
#include <sstream>
#include <math.h>

using namespace std;

class Solution {
public:
	vector<int> cubic_palindrome(vector<int> input) {
		vector<int> ret;
		//使用sstream实现int转string
		stringstream strStream;
		for (int n : input){
			//读int加入缓冲区
			strStream << n;
			//转string
			string s = strStream.str();
			//清空缓冲区，很重要
			strStream.str("");
			//开三次方，1.0而不是1
			strStream << pow(n,1.0 / 3);
			string s_3 = strStream.str();
			strStream.str("");
			if (is_palindrome(s) && is_palindrome(s_3)){
				ret.push_back(n);
			}
		}
		return ret;
	}

	bool is_palindrome(string val) {
		for (int i = 0, j = val.length() - 1; i < j; ++i, --j){
			if (val[i]!=val[j]){
				return false;
			}
		}
		return true;
	}

	vector<int> build_vector() {
		vector<int> ret;
		int start;
		int end;
		scanf_s("%d", &start);
		scanf_s("%d", &end);
		for (int i = start; i <= end; ++i){
			ret.push_back(i);
		}
		return ret;
	}

	void print_result(vector<int> result) {
		for (int i = 0; i < result.size(); ++i){
			printf("%d", result[i]);
			if (i != result.size() - 1){
				printf(" ");
			}
		}
	}
};

int main(){
	Solution solu;
	vector<int> input;
	input = solu.build_vector();
	vector<int> result;
	result = solu.cubic_palindrome(input);
	solu.print_result(result);
}

