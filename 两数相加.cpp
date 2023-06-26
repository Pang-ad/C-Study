
//Definition for singly-linked list
struct ListNode
{
	int val;
	ListNode *next;
	ListNode():val(0),next(nullptr){}
	ListNode(int x):val(x),next(nullptr){}
	ListNode(int x,ListNode *next):val(x),next(next){}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
	ListNode* dummy = new ListNode(0);			//创建虚拟头结点
	ListNode* curr = dummy;						//当前节点指针，用于构建新的链表
	int carry = 0;								//进位值
	
	while (l1 || l2 || carry)
	{
		int sum = carry;
		if (l1)
		{
			sum += l1->val;
			l1 = l1->next;
		}
		if (l2)
		{
			sum += l2->val;
			l2 = l2->next;
		}
		carry = sum / 10;
		curr->next = new ListNode(sum % 10);
		curr = curr->next;
	}
	return dummy->next;				//返回虚拟头节点下一个节点，即为结果链表的头节点
}