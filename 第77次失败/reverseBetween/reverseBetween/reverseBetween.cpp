// reverseBetween.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
/*
给你单链表的头指针 head 和两个整数 left 和 right ，其中 left <= right 。请你反转从位置 left 到位置 right 的链表节点，返回 反转后的链表 。

示例1：
输入：head = [1,2,3,4,5], left = 2, right = 4
输出：[1,4,3,2,5]

示例 2：
输入：head = [5], left = 1, right = 1
输出：[5]
*/
//链表可以只改值吗？
//可以，那直接相对交换值就可以
/*
链表的遍历方式又很阴间
1 2 3 4 5 6 7 8 9
想到的最直观的方法就是遍历多次，每次从left开始，先这么做吧
*/
/*
执行用时：4 ms, 在所有 C++ 提交中击败了51.36%的用户
内存消耗：7.2 MB, 在所有 C++ 提交中击败了57.69%的用户
*/
ListNode* reverseBetween(ListNode* head, int left, int right) {
	ListNode* left_node;
	ListNode* right_node;
	while (left < right) {
		ListNode* head_tmp = head;
		int left_tmp = left;
		//找当前的左节点
		while (left_tmp) {
			left_node = head_tmp;
			head_tmp = head_tmp->next;
			--left_tmp;
		}
		//cout<<left_node->val<<endl;
		ListNode* left_node_tmp = left_node;
		int right_tmp = right - left;
		while (right_tmp) {
			right_node = left_node_tmp->next;
			--right_tmp;
			left_node_tmp = left_node_tmp->next;
		}
		//cout<<right_node->val<<endl;
		int tmp;
		tmp = left_node->val;
		left_node->val = right_node->val;
		right_node->val = tmp;
		++left;
		--right;
	}
	return head;
}

ListNode *reverseBetween_well(ListNode *head, int left, int right) {
	// 设置 dummyNode 是这一类问题的一般做法
	ListNode *dummyNode = new ListNode(-1);
	dummyNode->next = head;
	ListNode *pre = dummyNode;
	for (int i = 0; i < left - 1; i++) {
		pre = pre->next;
	}
	ListNode *cur = pre->next;
	ListNode *next;
	for (int i = 0; i < right - left; i++) {
		next = cur->next;
		cur->next = next->next;
		next->next = pre->next;
		pre->next = next;
	}
	return dummyNode->next;
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
