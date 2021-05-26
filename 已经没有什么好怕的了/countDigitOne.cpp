/*
Day2
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
cur=0,count = high*i;
cur=1,count=high*i+low+1;
cur>1,count=high*i+i
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int countDigitOne(int n) {
		//统计1的个数，按照位数统计
		int count = 0;
		long i = 1;//i为位数，i=1为个位，i=10位十位
		while (n / i != 0) {//循环条件，确保在当前位
			//1532
			//1532 / 10
			//1532 / 100
			//1532 / 1000
			//1532 / (i * 10)
			//high = n / (i * 10)
			long high = n / (i * 10);//当前位左边的位，高位
			//1532
			//1532 % 10
			//(1532 / 10) % 10
			//(1532 / 100) % 10
			//(1532 / i) % 10
			//cur = (n / i) % 10
			long cur = (n / i) % 10;//当前位
			//1532
			//1532 % 1
			//1532 % 10
			//1532 % 100
			//low = n % i
			long low = n % i;//当前位右边
			if (cur == 0) {
				//当前位为0，1的个数为high * i，数学结论
				count += high * i;
			}
			else if (cur == 1) {
				//当前位为1时，1的个数为high * i + low + 1
				count += high * i + low + 1;
			}
			else {
				//否则，为high * i + i
				count += high * i + i;
			}
			i *= 10;//循环持续条件，进位
		}
		return count;
	}
};

int main() {

}
