#ifndef EMPLOYEE_H
#define EMPLOYEE_H
using namespace std;
#include <string>
#include <vector>

class Employee {
private:
    string name;
    string firstName;
    vector<int> dateOfBirth;
    float salary;
    static const string company;
public:
    Employee(const string& pName, const string& pFirstName, const vector<int>& pdateOfBirth, const float salary);
    float getSalary() const;
    void print() const;
    int age() const;
    void riseSalary(const float rise);
    static string getCompany();
};

#endif // EMPLOYEE_H