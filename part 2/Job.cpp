// Revised by M. Molodowitch 5/11/2016
// 
// Member function definitions for class Job
#include <iostream>
#include <string>
#include "Job.h"

using namespace std;



Job::Job(const string ID, const string description, const string phoneExt, const string contactName )
{
   setJobID ( ID );

   setJobDescription  (description);

   setPhoneExt ( phoneExt);

   setName(contactName);
}


// Destructor can be overloaded to deallocate
// any dynamically allocated memory.
// No dynamically allocated memory here, so nothing in body
Job::~Job()
{

}


Job & Job::setJobDescription ( const string description)
{
	jobDescription = description;

	return *(this);
}



Job & Job::setJobID( const string jobNumber ){

	jobID = jobNumber;
	
	return (*this);
	
}


Job & Job::setPhoneExt( const string phoneNumber )
{
	phoneExt = phoneNumber;
	
	return (*this);
	
}

Job & Job::setName(const string contactName)
{
	name = contactName;

	return (*this);
}


const string Job::getJobDescription() const
{
	return jobDescription;
}


const string Job::getJobID() const
{
	return jobID;
}


const string Job::getPhoneExt() const
{
	return phoneExt;
}

const string Job::getName() const
{
	return name;
}

// The print function can be modidfied to suit your need.
// modified to include contact name, also removed the first newline
ostream & operator<<( ostream & outstream, const Job job)
{
	outstream << "Job:  " << job.getJobID()<< "\nJob Description:  " << job.getJobDescription()
			<< "\nPhone Extension: " << job.getPhoneExt() << "\nName: " << job.getName();

	return outstream;
}


//Following for use in Binary Search Tree

   // for comparison operators <, >, ==,  only the jobID value is looked at.
   //
   // This means that one job object will equal another if the job ID's are the same,
   // even if the other fields differ.
   //
   // When looking for an old job with a particular ID, you can create a new job object
   // with the same ID but with default values for the other fields.  If an old job is equal,
   // to your new job (i.e. same job ID), you have found what you were looking for.  


   bool Job::operator<(const Job& right) const 
   {
	   return (jobID < right.jobID);
   }
   
   bool Job::operator>(const Job& right)const 
   {
	   return (jobID > right.jobID);
   }

   
   // This definition of equality means if job1 has jobID == 5, jobDescription == "", contactName == "",
   // and phoneExt == -1, and job2 has jobID == 5, jobDescription == "Paint CS building outside railings",
   // contactName == "James Whoever", and phoneExt == 5555,
   // job1 == job2
   
   bool Job::operator==(const Job& right)const 
   {
	   return (jobID == right.jobID);
   }
