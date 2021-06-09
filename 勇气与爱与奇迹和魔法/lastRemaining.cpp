/*
Day3
题目描述
*/

/*
思路
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int lastRemaining(int n, int m) {
		int ans = 0;
		for (int i = 2; i <= n; ++i){
			ans = (ans + m) % i;
		}
		return ans;
	}
};

int main() {
	Solution solu;
	cout << solu.lastRemaining(12, 3) << endl;
}
