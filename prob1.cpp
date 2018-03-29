// Russell Richardson

#include <iostream>


using namespace std;


void insert(int n, int arr[], int newEntry){

	int tempCurrent, tempNext, index;
	if (n == 0) {
		arr[0] = newEntry;
	}

	else if (newEntry > arr[n-1]) {
		arr[n] = newEntry;
	}
	else if (newEntry < arr[0]) {
		tempCurrent = arr[0];
		arr[0] = newEntry;
		for (int i = 1; i < n; i++) {
			tempNext = arr[i];
			arr[i] = tempCurrent;
			tempCurrent = tempNext;
		}
		arr[n] = tempCurrent;
		
	}
	else {
		for (int i = 0; i < n; i++) {
			if (newEntry >= arr[i] && newEntry <= arr[i + 1]) {
				tempCurrent = arr[i];
				arr[i] = newEntry;
				index = i;
				i = n;
			}
		}
		for (index; index < n; index++) {
			tempNext = arr[index];
			arr[index] = tempCurrent;
			tempCurrent = tempNext;
		}
		arr[n] = tempCurrent;
	}
}

int main() {

	int table[10];

	insert(0, table, 5);
	insert(1, table, 10);
	insert(2, table, 12);
	insert(3, table, 10);
	insert(4, table, 9);

	system("pause");
	return 0;
}