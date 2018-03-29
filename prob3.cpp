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

int helperSumPos(int sum, Node* &ptr) {
	if (ptr == nullptr) {
		return sum;
	}
	else {
		if (ptr->val > 0) {
			sum += ptr->val;
		}
		helperSumPos(sum, ptr->next);
	}
}

int sumPos(Node* &ptr) {
	int sum = 0;
	return helperSumPos(sum, ptr);
}


int main() {


	Node* head = nullptr;

	for (int i = 0; i < 5; i++) {
		Node* temp = new Node;
		temp->val = i;
		temp->next = head;
		head = temp;
	}

	int answer = sumPos(head);

	head->next->next->val = -1; //testing negative

	answer = sumPos(head);

	system("pause");
	return 0;
}