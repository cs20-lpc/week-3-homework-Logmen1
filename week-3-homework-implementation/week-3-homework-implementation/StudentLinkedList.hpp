#ifndef STUDENT_LINKED_LIST_HPP
#define STUDENT_LINKED_LIST_HPP

#include "List.hpp"
#include "Student.hpp"
#include <iostream>

template <>
class LinkedList<student> {
protected:
    struct Node {
        student value;
        Node* next;
        Node(student v = student(), Node* n = nullptr) : value(v), next(n) {}
    };
    Node* head;
    int length;

public:
    LinkedList() : head(nullptr), length(0) {}
    ~LinkedList() { clearAll(); }

    void append(const student& s) {}
    student findID(int id) {}
    void destID(int id) {}
    void nodeCourse(int id) {}
    void printCourse(int id) {}
    void printAll() const {}
    void clearAll() {}

    int getLength() const { return length; }
    bool isEmpty() const { return length == 0; }
};




#endif