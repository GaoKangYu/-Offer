// mergeTwoLists.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

/*
剑指offer25
输入两个递增排序的链表，合并这两个链表并使新链表中的节点仍然是递增排序的。

示例1：
输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4
限制：

0 <= 链表长度 <= 1000
*/

/*
递归
*/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;


 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == nullptr)
			return l2;

		if (l2 == nullptr)
			return l1;

		ListNode* ret = nullptr;
		if (l1->val < l2->val){
			ret = l1;
			ret->next = mergeTwoLists(l1->next, l2);
		}
		else{
			ret = l2;
			ret->next = mergeTwoLists(l1, l2->next);
		}
		return ret;
	}
};

int main()
{
	std::cout << "Hello World!\n";
}
