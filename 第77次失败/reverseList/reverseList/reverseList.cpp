// reverseList.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

/*
	剑指 Offer 24. 反转链表
	定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点。

	示例:
	输入: 1->2->3->4->5->NULL
	输出: 5->4->3->2->1->NULL

	限制：
	0 <= 节点个数 <= 5000
	*/
	/*
	DNA里刻着对链表题的失败以及
	递归
	*/
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
/*
示例:
输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL
*/
ListNode* reverseList(ListNode* head) {
	ListNode* front = nullptr;
	ListNode* cur = head;
	while (cur) {
		//避免丢失原指针
		ListNode* next = cur->next;
		//当前节点的下一指针指向前一个节点
		cur->next = front;
		//没有这句话，front始终都是nullptr了，相当于后挪一下，抽象思维欠缺，xd
		front = cur;
		//按原顺序继续遍历，相当于cur = cur->next
		cur = next;
	}
	return front;
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
