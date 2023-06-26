
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
	ListNode* dummy = new ListNode(0);			//��������ͷ���
	ListNode* curr = dummy;						//��ǰ�ڵ�ָ�룬���ڹ����µ�����
	int carry = 0;								//��λֵ
	
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
	return dummy->next;				//��������ͷ�ڵ���һ���ڵ㣬��Ϊ��������ͷ�ڵ�
}