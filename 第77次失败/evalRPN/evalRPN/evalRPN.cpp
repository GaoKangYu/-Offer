// evalRPN.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <stack>
	/*
	根据 逆波兰表示法，求表达式的值。
	有效的算符包括 +、-、*、/ 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。

	说明：
	整数除法只保留整数部分。
	给定逆波兰表达式总是有效的。
	换句话说，表达式总会得出有效数值且不存在除数为 0 的情况。
	*/
	/*
	虽然但是，他的提示已经挺明显了
	用栈操作，那么，需要学一下原始栈操作吗，还是说直接vector
	*/
int evalRPN(vector<string>& tokens) {
	stack<int> nums;
	int val_pre;
	int val_after;
	for (auto n : tokens) {
		if (n == "+") {
			val_after = nums.top();
			nums.pop();
			val_pre = nums.top();
			nums.pop();
			nums.push(val_pre + val_after);
		}
		else if (n == "-") {
			val_after = nums.top();
			nums.pop();
			val_pre = nums.top();
			nums.pop();
			nums.push(val_pre - val_after);
		}
		else if (n == "*") {
			val_after = nums.top();
			nums.pop();
			val_pre = nums.top();
			nums.pop();
			nums.push(val_pre * val_after);
		}
		else if (n == "/") {
			val_after = nums.top();
			nums.pop();
			val_pre = nums.top();
			nums.pop();
			nums.push(val_pre / val_after);
		}
		else {
			nums.push(stoi(n));
		}
	}
	return nums.top();
}


int main()
{
    std::cout << "Hello World!\n";
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
