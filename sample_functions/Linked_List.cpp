#include <bits/stdc++.h>
using namespace std;

class ListNode {
	public:
		int data;
		ListNode* next;

		ListNode(int data1, ListNode* next_ptr) {
			data = data1;
			next = next_ptr;
		}

		ListNode(int data1) {
			data = data1;
			next = nullptr;
		}
};

void print_Linked_List(ListNode* head) {
	ListNode* curr = head;
	cout << "\n Printing the ListNode ....... \n\t";
	while (curr != nullptr) {
		cout << curr -> data << " ";
		curr = curr -> next;
	}
	cout << "\n Done with printing of ListNode\n";
}

ListNode* insert_new_head(ListNode* head, int val) {
	ListNode* temp = new ListNode(val, head);
	return temp;
}

int main() {
	ListNode* head = new ListNode(1);
	head -> next = new ListNode(2);
	head -> next -> next = new ListNode(3);
	head -> next -> next -> next = new ListNode(4);

	print_Linked_List(head);
	
	ListNode* new_head = insert_new_head(head, 0);

	print_Linked_List(new_head);

	return 0;
}
