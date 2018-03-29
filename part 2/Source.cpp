//Russell Richardson

// Jobs will be stored in two different queues: one for the emergency jobs
// and one for the standard jobs. When assigning a job the program will first
// check the emergency queue and assign the first job in that queue before 
// removing it. If the emergency queue is empty then and only then may standard 
// jobs be assigned and then removed from the top of the queue. 

#include <iostream>
#include <fstream>
#include "Queue.h"
#include "Job.h"

using namespace std;

// this prints the menu for the user
void printMenu() {

	cout << "N: enter new job " << endl;
	cout << "A: assign job to employee " << endl;
	cout << "Q: save and quit " << endl;

}

// this function is called at the beginning and reads the previous days
// standard jobs into the system
// not sure how the eof function works this isn't right...
void ReadFile(Queue<Job> &standardJobs) {

	ifstream inStream;
	inStream.open("Save.txt");

	string jobID;
	string jobDescription;
	string phoneExt;
	string name;
	
	if (inStream.is_open()) {
		while (!inStream.eof()) {
			getline(inStream,jobID);
			getline(inStream,jobDescription);
			getline(inStream,phoneExt);
			getline(inStream,name);
			Job temp(jobID,jobDescription,phoneExt,name);
			standardJobs.enqueue(temp);
		}
	}

	else {
		ofstream outStream("Save.txt");
		outStream << "" << endl;
		outStream.close();
		cout << "There are no previous jobs..." << endl;
	}
	inStream.close();
}

// This function asks whether the job being entered is standard or 
// an emergency and then enqueues it into the appropriate queue.
// Both queues are passed into the function since the choice is made 
// inside the function.
void enterNewJob(Queue<Job> &standardJobs, Queue<Job> &emergencyJobs) {
	
	char jobType;
	string jobID;
	string jobDescription;
	string phoneExt;
	string name;

	cout << "Enter E for Emergency or S for Standard: ";
	cin >> jobType;

	if (jobType == 'e' || jobType == 'E') {
		
		cout << "Enter job ID: ";
		cin >> jobID;
		cout << "Enter job description: ";
		getline(cin,jobDescription);
		cout << "Enter contact number: ";
		cin >> phoneExt;
		cout << "Enter contact Name: ";
		getline(cin,name);

		Job newJob(jobID, jobDescription, phoneExt, name);
		emergencyJobs.enqueue(newJob);

	}

	else if (jobType == 's' || jobType == 'S') {

		cout << "Enter job ID: ";
		cin >> jobID;
		cout << "Enter job description: ";
		cin >> ws;
		getline(cin,jobDescription);
		cout << "Enter contact number: ";
		cin >> phoneExt;
		cout << "Enter contact Name: ";
		cin >> ws;
		getline(cin,name);

		Job newJob(jobID, jobDescription, phoneExt, name);
		standardJobs.enqueue(newJob);
	}

	else {
		cout << "Try again..." << endl;
	}
}

// This function assigns a job by printing to standard out put. First
// emergency jobs are printed. If there are no emergency jobs printed 
// then standard jobs are printed. If there are no jobs then the user
// is notified.
void assignJob(Queue<Job> &standardJobs, Queue<Job> &emergencyJobs) {

	Job assignment;

	if (!emergencyJobs.isEmpty()) {
		emergencyJobs.front(assignment);
		cout << assignment << endl;
		emergencyJobs.dequeue();
	}

	else if (emergencyJobs.isEmpty() && !standardJobs.isEmpty()) {
		standardJobs.front(assignment);
		cout << assignment << endl;
		standardJobs.dequeue();
	}

	else {
		cout << "There are currently no jobs..." << endl;
	}
}

// This function prints the remaining emergency jobs the order they were
// assigned and remove them from the queue. The function then saves the 
// standard jobs into the "Save.txt" file so that they may be loaded again
// into the system the next time the program runs.
void quit(Queue<Job> &standardJobs, Queue<Job> &emergencyJobs) {

	Job lastAssignments;
	while (!emergencyJobs.isEmpty()) {
		emergencyJobs.front(lastAssignments);
		cout << lastAssignments << endl;
		emergencyJobs.dequeue();
	}

	ofstream outStream;
	outStream.open("Save.txt");
	if (outStream.is_open()) {
		while (!standardJobs.isEmpty()) {
			standardJobs.front(lastAssignments);
			outStream << lastAssignments << endl;
			standardJobs.dequeue();
		}
	}

	outStream.close();

}

// This fucntion calls the desired function based on the user's
// choice. Both queues are passed into the function in case a choice 
// requires their use.
void menuAction(char &choice, Queue<Job> &standardJobs, Queue<Job> &emergencyJobs) {

	if (choice == 'n' || choice == 'N') {
		enterNewJob(standardJobs, emergencyJobs);
	}

	else if (choice == 'a' || choice == 'A') {
		assignJob(standardJobs, emergencyJobs);
	}

	else if (choice == 'q' || choice == 'Q') {

	}
	else {
		cout << "Invalid input try again..." << endl;
	}
}
int main() {

	Queue<Job> standardJobs;
	Queue<Job> emergencyJobs;
	char choice;
	bool done = false;

	ReadFile(standardJobs);

	do {
		printMenu();
		cin >> choice;
		menuAction(choice, standardJobs, emergencyJobs);
		if (choice == 'q' || choice == 'Q') {
			done = true;
		}
	} while (!done);

	quit(standardJobs, emergencyJobs);
	cout << endl;

	system("pause");
	return 0;
}