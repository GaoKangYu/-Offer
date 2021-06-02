/*
Day3
剑指 Offer 43. 1～n 整数中 1 出现的次数

输入一个整数 n ，求1～n这n个整数的十进制表示中1出现的次数。
例如，输入12，1～12这些整数中包含1 的数字有1、10、11和12，1一共出现了5次。

 
示例 1：
输入：n = 12
输出：5

示例 2：
输入：n = 13
输出：6 

限制：
1 <= n < 2^31
*/

/*
0 : high * i + 0
1 : high * i + i + 1
other : high * i + i
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int countDigitOne(int n) {
		//return value count, for counting amount of one
		int count = 0;
		//position of current pointer
		long i = 1;
		//current pos
		while (n / i) {
			//1532
			//1532 / 10
			//1532 / 100
			//1532 / 1000
			//n / i * 10
			//left pos of cur
			int high = n / (i * 10);
			//cur pos
			//1532  2 1532 % 10
			//1532  3 1532 / 10 % 10
			//1532  5 1532 / 100 % 10
			//1532  1
			// n / i
			int cur = n / i % 10;
			//right pos of cur
			//1532  0 1532 % i
			//1532  2 
			//1532  3
			//1532  5
			//1532  1
			int low = n % i;
			if (cur == 0) {
				//1502
				count += high * i;
			}
			else if (cur == 1) {
				//1512
				count += high * i + low + 1;
			}
			else {
				//1522
				count += high * i + i;
			}
			i *= 10;
		}
		return count;
	}
};

int main() {

}
