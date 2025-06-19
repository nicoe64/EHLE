#include <iostream>
#include <vector>
using namespace std;

void print(const string& n, const string& f, const vector<int>& d, const float s) {
    cout << "Name:\t\t" << n << "\n";
    cout << "First Name:\t" << f << "\n";
    cout << "Date Of Birth:\t" << d[0] << "." << "0" << d[1] << "." << d[2] << "\n";
    cout << "Salary:\t\t" << s << " $" << "\n";
}

int main() {
    string name = "Ehle";
    string firstName = "Nicolas";

    vector<int> dateOfBirth = {28, 6, 2005};
    float salary = 10000.00;
    
    print(name, firstName, dateOfBirth, salary);
 
    return 0;
}