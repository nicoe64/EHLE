#include "employee.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std; 
 
 
Employee:: Employee(const string& pName, const string& pFirstName, const vector<int>& pdateOfBirth, const float salary) {
    /*data*/
}

const string Employee::company = "CP Soft";

string Employee::getCompany() {
    return company;
}

float getSalary() {
    /*data*/
}

int age() {
    /*data*/
}

void riseSalary(const float rise) {
    /*data*/
}

void print() {
    // ...
    cout << "Company:\t" << company << "\n";
}

int main() {

    return 0;
}