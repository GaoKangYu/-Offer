/*
Day3
剑指 Offer 17. 打印从1到最大的n位数

输入数字 n，按顺序打印出从 1 到最大的 n 位十进制数。比如输入 3，则打印出 1、2、3 一直到最大的 3 位数 999。

示例 1:
输入: n = 1
输出: [1,2,3,4,5,6,7,8,9]
 

说明：
用返回一个整数列表来代替打印
n 为正整数
*/

/*
思路
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution_better {
public:
	void Print1ToMaxOfNDigits_2(int n)
	{
		if (n <= 0)
			return;

		char* number = new char[n + 1];
		number[n] = '\0';

		for (int i = 0; i < 10; ++i)
		{
			number[0] = i + '0';
			Print1ToMaxOfNDigitsRecursively(number, n, 0);
		}

		delete[] number;
	}

	void Print1ToMaxOfNDigitsRecursively(char* number, int length, int index)
	{
		if (index == length - 1)
		{
			PrintNumber(number);
			return;
		}

		for (int i = 0; i < 10; ++i)
		{
			number[index + 1] = i + '0';
			Print1ToMaxOfNDigitsRecursively(number, length, index + 1);
		}
	}

	void PrintNumber(char* number)
	{
		bool isBeginning0 = true;
		int nLength = strlen(number);

		for (int i = 0; i < nLength; ++i)
		{
			if (isBeginning0 && number[i] != '0')
				isBeginning0 = false;

			if (!isBeginning0)
			{
				printf("%c", number[i]);
			}
		}

		printf("\t");
	}
};


int main() {
	Solution_better test;
	test.Print1ToMaxOfNDigits_2(2);
}
