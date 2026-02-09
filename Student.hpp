// TO DO:  Student class definition  here.

#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <string>
#include "Course.hpp"
#include "LinkedList.hpp"


class student {
private:
	int ID;
	std::string name;
	double gpa;
	LinkedList<course> courses;

public:
	student();
	~student();
	void setID(int);
	void setName(std::string);
	void setGPA(double);
	void addCourse();
	int getID() const;
	std::string getName() const;
	double getGPA() const;
	course printCourses() const;
};
#endif