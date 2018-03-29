#include <iostream>
#include <fstream>


using namespace std;


void readFile(Queue<Job> &standardJobs) {

	ifstream inStream;
	inStream.open("Save.txt");

	if (inStream.is_open()) {
		while (!inStream.eof()) {

		}
	}
	
	else {
		ofstream outStream;
		outStream.open("Save.txt");
		outStream << "" << endl;
		cout << "There are no previous jobs" << endl;
		outStream.close();
	}
	inStream.close();
}

int main() {



	system("pause");
	return 0;
}