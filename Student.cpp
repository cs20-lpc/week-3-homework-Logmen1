// TODO:  Student class methods implementation here.

#include "Student.hpp"
#include "Course.hpp"
#include <string>

student::student() {
	ID = 0;
	name = "";
	gpa = 0.0;
}
student::~student() {
	courses.clear();
}
void student::setID(int i) {
	ID = i;
}
void student::setName(std::string s) {
	name = s;
}
void student::setGPA(double d) {
	gpa = d;
}
void student::addCourse() {
	course studentCourse;
	std::cout << "enter the name of the course:\n";
	std::string s;
	std::cin >> s;
	studentCourse.setCourseName(s);
	std::cout << "enter the course location:\n";
	int i;
	std::cin >> i;
	studentCourse.setLocation(i);

	courses.append(studentCourse);
}
int student::getID() const {
	return ID;
}
std::string student::getName() const {
	return name;
}
double student::getGPA() const {
	return gpa;
}
course student::printCourses() const {
	std::cout << "courses: ";
	for (int x = 0; x < courses.getLength(); x++) {
		std::cout << courses.getElement(x).getCourseName() << " " << courses.getElement(x).getLocation() << std::endl<<"         ";
	}
}