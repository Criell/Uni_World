// Course: Object Oriented Programming
// Practical #
// Author: Zachary Forman
// Student ID: 1632538
// Description: Class definition for basic person class.

// The macro _PERSON_H is used to prevent the Person class being accidently
// included more than once into a program. The first time this file is
// included, _PERSON_H will be defined. If it is included again, the #ifndef
// will cause the text between the #ifndef and #endif to be omitted.
#ifndef _PERSON_H
#define _PERSON_H

#include <string>  // For strings

// Definition of Person class.
// Person class is used for high performance computational simulation of the most
// important aspects of a person - their name, occupation, age - and
// most critically, how hungry they are.
class Person
{
public:
	// Constructs a person, with parameters as given and a random hour last eaten.
	Person(std::string name, std::string job, int year, int month, int day);

	// Trivial destructor.
	~Person();

	// Returns the age, in full years, of the person based on the
	// current date passed in the parameters.
	int getAge(int current_year, int current_month, int current_day) const;

	// Accessors. Note the use of `const` for all methods which do not
	// modify member variables. This is a good idea as the compiler will
	// help catch errors you might make inside a const function if you
	// accidentally modify a member variable.
	std::string getName() const;
	std::string getJob() const;

	// set person's job to their new job.
	void changeJobs(std::string new_job);

	// set a person's time last eaten to hour.
	void eatFood(int hour);

	// Returns true if the difference between hour and the time
	// last eaten is more than TIME_TO_HUNGRY
	bool isHungry(int hour) const;

private:
	// Never changes. Doesn't vary between people.
	// `const` indicates the value never changes
	// `static` indicates that this (const) variable is the same for EVERY Person object.
	// It is the combination of these two keywords that allows us to define the value
	// here in the header. For every other member variable we must assign it in the
	// constructor.
	const static int TIME_TO_HUNGRY = 4;

	// Never changes for any Person, but varies between Persons.
	const int m_year_of_birth;
	const int m_month_of_birth;
	const int m_day_of_birth;
	const std::string m_name;

	// Can vary over time for a single Person
	std::string m_job;
	int m_hour_last_ate;
};

#endif // _PERSON_H
