// getKthFromEnd.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};
/*
	输入一个链表，输出该链表中倒数第k个节点。为了符合大多数人的习惯，本题从1开始计数，即链表的尾节点是倒数第1个节点。
	例如，一个链表有 6 个节点，从头节点开始，它们的值依次是 1、2、3、4、5、6。这个链表的倒数第 3 个节点是值为 4 的节点。

	示例：
	给定一个链表: 1->2->3->4->5, 和 k = 2.
	返回链表 4->5.
	*/
	/*
	行，又是链表，这个东西wdnmd就反直觉，但是我会搞定它
	第一轮复习开始了xd
	*/
	/*
	第一感觉是先逆序，但是也不是直接能返回，顺序反了，还要逆序一次
	先逆序，好遍历，不好返回
	不逆序，好返回，不好遍历
	问题在于不知道链表的长度，那么最简单的方法就是先遍历一次知道链表的长度，那么复杂度就是O(n+m)
	先做吧
	*/
	//0 ms	100%
	//10.3 MB  72%
	//真的假的
ListNode* getKthFromEnd(ListNode* head, int k) {
	int length = 0;
	ListNode* count_length = head;
	while (count_length) {
		++length;
		count_length = count_length->next;
	}
	int count = length - k;
	while (count) {
		head = head->next;
		--count;
	}
	return head;
}
//应该是规模不大导致的，看了一下，双指针的方法比较合理，不需要额外引入栈空间，也是O(n)
//两个指针指头，先后指针走K步，然后先指针后指针同时后移，知道后指针指空，返回先指针
//0 ms	100%
//10.2 MB  81%
//wtf
ListNode* getKthFromEnd_better(ListNode* head, int k) {
	ListNode* pre_ptr = head;
	while (k) {
		pre_ptr = pre_ptr->next;
		--k;
	}
	while (pre_ptr) {
		head = head->next;
		pre_ptr = pre_ptr->next;
	}
	return head;
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
