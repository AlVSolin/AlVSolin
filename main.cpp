#include <iostream>



// ���������� ���������, ����������� ������� ������������ ������.
struct ListNode {
	int val;
	ListNode* next;
};



// �������, ���������������� ����������� ������.
ListNode* ReverseFList(ListNode* head)
{
	ListNode* cur;
	ListNode* next;;
	ListNode* prev;

	cur = head;
	next = cur->next;

	// �������� � ������ ��������� ��������.
	cur->next = nullptr;
	cur = next;
	prev = head;
	
	// �������� ����.
	while (cur->next != nullptr) {
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}

	// �������� � ��������� ��������� ��������.
	cur->next = prev;
	prev = cur;
	head = cur;

	// ���������� ��������� �� ����� ������ ������.
	return(head);
}



int main() {

	ListNode LN[5];
	ListNode* head = &LN[0];

	// �������������� ����������� ������.
	for (int i = 0; i != 4; ++i) {
		LN[i].val = i * i;
		LN[i].next = &LN[i + 1];
	}
	LN[4].val = 4 * 4;
	LN[4].next = nullptr;

	// ������� �������� ��� ����� val � �������� ��� ������������� �������. 
	for (ListNode* cur = head; cur != nullptr; cur = cur->next) {
		std::cout << cur->val << " ";
	}
	std::cout << std::endl;

	// ��������� ������� "���������������".
	head = ReverseFList(head);

	// ������� �������� ��� ����� val � ������� ����� "���������".
	for (ListNode* cur = head; cur != nullptr; cur = cur->next) {
		std::cout << cur->val << " ";
	}
	std::cout << std::endl;

	return(0);
}