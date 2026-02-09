
#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <iostream>
#include "Student.hpp"


using namespace std;


///////////////////////////
//// Generic LinkedList<T>
///////////////////////////
template <typename T>
class LinkedList {
protected:
    struct Node {
        T value;
        Node* next;
        Node(T v = T(), Node* n = nullptr) : value(v), next(n) {}
    };

    Node* head;
    int length;

public:

    LinkedList(){
        head = nullptr;
        length = 0;
    }

    ~LinkedList() {
        clear();
    }


    void append(const T& elem) {
        // TODO
        Node* NewNode = new Node;
        NewNode->value = elem;
        NewNode->next = nullptr;

        if (!head) {
            head = NewNode;
        }

        else {
            Node* traveler = head;
            while (traveler->next != nullptr) {
                traveler = traveler->next;
            }
            traveler->next = NewNode;
        }
        this->length++;
    }


    void clear() {
        // TODO
        Node* traveler = head;
        while (traveler != nullptr) {
            Node* temp = traveler;
            traveler = traveler->next;
            delete temp;
        }

        head = nullptr;
        this->length = 0;
    }


    T getElement(int position) const {
        // TODO
        if (this->isEmpty()) {
            throw std::string("List is empty, no elements to return\n");
        }

        if (position < 0 || position >= this->length) {
            throw std::string("Index out of bounds");
        }
        Node* traveler = head;
        for (int i = 0; i < position; i++) {
            traveler = traveler->next;
        }

        return traveler->value;
    }

    int getLength() const {
        return this->length;
    }


    bool isEmpty() const {
        return this->length == 0;
    }


    void replace(int position, const T& elem) {
        // TODO
        if (this->isEmpty()) {
            throw std::string("List is empty, no elements to replace.\n");
        }

        if (position < 0 || position >= this->length) {
            throw std::string("Index out of bounds");
        }
        Node* traveler = head;
        for (int i = 0; i < position; i++) {
            traveler = traveler->next;
        }

        traveler->value = elem;
    }
};


///////////////////////////
//// Full specialization for student
///////////////////////////


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

    void append(const student& s) {
        Node* newNode = new Node(s, nullptr);
        if (!head) head = newNode;
        else {
            Node* traveler = head;
            while (traveler->next != nullptr) traveler = traveler->next;
            traveler->next = newNode;
        }
        length++;
    }

    bool isEmpty() const { return length == 0; }
    int getLength() const { return length; }


    student& findID(int ide) {
        if (this->isEmpty()) {
            throw std::string("List is empty, no elements to return\n");
        }
        Node* traveler = head;
        while (traveler != nullptr) {
            student& fill = traveler->value;
            if (fill.getID() != ide) {

                traveler = traveler->next;
            }
            else {

                return fill;
            }
        }

        throw std::string("List does not contain student with this ID\n");
    }


    void destID(int ide) {

        if (this->isEmpty()) {
            throw std::string("List is empty, no elements to delete\n");
        }

        Node* trailer = nullptr;
        Node* traveler = head;

        while (traveler != nullptr) {

            if (traveler->value.getID() != ide) {

                trailer = traveler;
                traveler = traveler->next;
            }
            else {
                if (trailer == nullptr) { 
                    head = traveler->next;
                }
                else {
                    trailer->next = traveler->next;
                }
                delete traveler;
                length--;
                return;
            }
        }

        throw std::string("List does not contain student with this ID\n");
    }



    void nodeCourse(int ide) {
        try {
            student& fill = findID(ide);
            fill.addCourse();
        }
        catch (std::string s) {
            std::cout << s;
        }
    }


    void printCourse(int ide) {
        try {
            student& fill = findID(ide);
            std::cout << "found: " << fill.getID() << " " << fill.getName() << " " << fill.getGPA() << endl;
            fill.printCourses();
        }
        catch (std::string s) {
            std::cout << s;
        }
    }


    void printAll() {
        Node* traveler = head;
        while (traveler != nullptr) {
            student& fill = traveler->value;
            std::cout << "students in list:\n" << fill.getID() << " " << fill.getName() << " " << fill.getGPA() << endl;
            fill.printCourses();
            traveler = traveler->next;

        }
    }

   
    void clearAll() {
        Node* traveler = head;
        while (traveler != nullptr) {
            Node* temp = traveler;
            traveler = traveler->next;
            delete temp;
        }

        head = nullptr;
        this->length = 0;

    }
};

#endif