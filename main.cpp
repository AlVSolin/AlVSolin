#include <iostream>



// Упрощённая структура, реализующая элемент односвязного списка.
struct ListNode {
	int val;
	ListNode* next;
};



// Функция, переворачивающая односвязный список.
ListNode* ReverseFList(ListNode* head)
{
	ListNode* cur;
	ListNode* next;;
	ListNode* prev;

	cur = head;
	next = cur->next;

	// Работаем с первым элементом отдельно.
	cur->next = nullptr;
	cur = next;
	prev = head;
	
	// Основной цикл.
	while (cur->next != nullptr) {
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}

	// Работаем с последним элементом отдельно.
	cur->next = prev;
	prev = cur;
	head = cur;

	// Возвращаем указатель на новое начало списка.
	return(head);
}



int main() {

	ListNode LN[5];
	ListNode* head = &LN[0];

	// Инициализируем односвязный список.
	for (int i = 0; i != 4; ++i) {
		LN[i].val = i * i;
		LN[i].next = &LN[i + 1];
	}
	LN[4].val = 4 * 4;
	LN[4].next = nullptr;

	// Выводим значения его полей val в заданном при инициализации порядке. 
	for (ListNode* cur = head; cur != nullptr; cur = cur->next) {
		std::cout << cur->val << " ";
	}
	std::cout << std::endl;

	// Запускаем функцию "переворачивания".
	head = ReverseFList(head);

	// Выводим значения его полей val в порядке после "разворота".
	for (ListNode* cur = head; cur != nullptr; cur = cur->next) {
		std::cout << cur->val << " ";
	}
	std::cout << std::endl;

	return(0);
}