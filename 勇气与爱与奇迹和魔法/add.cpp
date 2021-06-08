/*
Day3
a + b = a^b + (unsigned int)(a&b) << 1;
*/

/*
思路
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int add(int a, int b) {
		//两数相加，位运算
		//可以先画真值表统计出所有的情况
		//可以发现无进位和的值与异或运算相同，进位值与与运算情况相同
		//a + b = a^b + (unsigned int)(a&b) << 1;
		while (b) {
			int carry = (unsigned int)(a & b) << 1;
			a ^= b;
			b = carry;
		}
		return a;
	}
};

int main() {
	Solution solu;
	cout << solu.add(1, 3) << endl;
}
