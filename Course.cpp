// TODO:  Course class methods implementation here.

#include "Course.hpp"
#include <string>

course::course() {
	courseName = "";
	location = 0;
}

void course::setCourseName(std::string s) {
	courseName = s;
}

void course::setLocation(int i) {
	location = i;
}

std::string course::getCourseName() const {
	return courseName;
}

int course::getLocation() const {
	return location;
}
