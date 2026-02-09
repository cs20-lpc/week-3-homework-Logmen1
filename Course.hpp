// TODO:  Course class definitins go here.

#ifndef COURSE_HPP
#define COURSE_HPP

#include <string>


class course {
private:
	std::string courseName;
	int location;

public:
	course();
	void setCourseName(std::string);
	void setLocation(int);
	std::string getCourseName() const;
	int getLocation() const;
};
#endif