#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

struct Employee {
    string name;
    float salary;
};
                    //Employee *data,
Employee* load_data() {
    ifstream infile("MOCK_DATA.txt");
    string line;
    int num_employee = 0;
    int capacity = 10;
    Employee* employees = new Employee[capacity];

    if (infile.is_open()) {
        while (getline(infile, line)) {
            stringstream ss(line);
            string name; 
            string salaryStr;

            if (getline(ss, name, ',') && getline(ss, salaryStr)) {
                double salary = stod(salaryStr);

                if(num_employee == capacity) {
                    capacity *= 2;
                    Employee* newEmployee = new Employee[capacity];

                    for (int i = 0; i < num_employee; i++)
                    {
                        newEmployee[i] = employees[i];
                    }

                    delete[] employees;
                    employees = newEmployee;
                }

                employees[num_employee].name = name;
                employees[num_employee].salary = salary;
                num_employee++;
            }
        }

        infile.close();
    } else {
        cout << "Failed to open the file." << endl;
    }

    return employees;
}