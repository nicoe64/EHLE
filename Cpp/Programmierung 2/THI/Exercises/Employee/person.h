#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <vector>

using namespace std;

class Person {
    private:
        string name;
        string firstName;
        vector<int> dateOfBirth;
    
    public: 
        Person(const string& pName, const string& pFirstName, const vector<int> pDateOfBirth);

        void print();
        int age();
    
};

#endif // PERSON_H