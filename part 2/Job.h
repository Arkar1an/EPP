// Original source attribution available
// Modified by M. Molodowitch

// A Job class
// Note how comparison operators are defined.

// Russell Richardson
// added a contact name and setters and getters
// changed data members all to strings since no
// arithmatic is performed on them

#ifndef JOB_H
#define JOB_H

#include <iostream>
#include <string>

using namespace std;


class Job{
	friend ostream & operator<<( ostream &, const Job);


public:
   Job ( const string = "",  const string = "", const string = "", const string= "");  // constructor with default values
   ~Job();                       // destructor

   Job & setJobID( const string );
   Job & setJobDescription ( const string);
   Job & setPhoneExt( const string );
   Job & setName(const string);

   const string getJobID() const;
   const string getJobDescription() const;   
   const string getPhoneExt() const;
   const string getName() const;
   
  

   //Following three operator overloads are for use in Binary Search Tree
   // Comparisons betwen jobs are done by jobID only.

   bool operator<(const Job& right) const; 
   
   bool operator>(const Job& right)const;
    
   bool operator==(const Job& right)const; 

private:
   string jobID;
   string jobDescription;
   string phoneExt;
   string name;
};

#endif



