//Russell Richardson

#include <iostream>


using namespace std;

struct Node {
	Node() {
		val = 0;
		next = nullptr;
	}

	int val;
	Node* next;
};

Node* copy(Node* &originalList) {
	Node* temp = originalList;
	Node* newHead = nullptr;
	Node* elseTemp;
	while (temp != nullptr) {
		Node* copy = new Node;
		copy->val = temp->val;
		if (newHead == nullptr) {
			copy->next = newHead;
			newHead = copy;
		}
		else {
			elseTemp = newHead;
			while (elseTemp->next != nullptr) {
				elseTemp = elseTemp->next;
			}
			elseTemp->next = copy;
		}
		temp = temp->next;
	}
	return newHead;
}

void print(Node* head) {
	while (head != nullptr) {
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
}

int main() {


	Node* head = nullptr;

	for (int i = 0; i < 5; i++) {
		Node* temp = new Node;
		temp->val = i;
		temp->next = head;
		head = temp;
	}

	print(head);
	Node* copyList = copy(head);
	print(copyList);
	


	system("pause");
	return 0;
}