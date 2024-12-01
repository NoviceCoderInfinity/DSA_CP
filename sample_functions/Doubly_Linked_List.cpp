#include <bits/stdc++.h>
using namespace std;

class Node() {
public:
	int data;
	Node* next;
	Node* prev;

	Node(int data1, Node* next_ptr, Node* prev_ptr) {
		data = data1;
		next = next_ptr;
		prev = prev_ptr;
	}

	Node(int data1) {
		data = data1;
		next = nullptr;
		prev = nullptr;
	}
};

void print_doubly_linked_list(Node* head) {
	Node* curr = head;
	cout << "Printing the Doubly Linked List with head pointer " <<  head << " ........\n\t";
	while(curr != nullptr) {
		cout << curr -> data << " ";
	}
	cout << "\n........Printing complete\n";
}

int main() {
	Node* head = new Node(10);
	Node* prev = head;
}
