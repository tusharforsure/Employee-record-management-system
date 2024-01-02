#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <algorithm> 
using namespace std;


class Employee {
private:
    string name;
    string empID;
    string dob;
    string doj;
    string maritalStatus;
    string phoneNumber;
    string emailID;
    string department;
    unsigned long long int ctc;
    int leavesTaken;

public:
    Employee() : ctc(0.0), leavesTaken(0) {}

    void setDetails() 
    
    {
        cout << "Enter Name (alphabets only): ";
        cin.ignore(); // Ignore any previous newline in the input buffer
        while (true) {
        getline(cin, name);
        bool validName = true;
        for (size_t i = 0; i < name.length(); ++i) {
            char c = name[i];
            if (!isalpha(c) && !isspace(c)) {
                validName = false;
                break;
                    }
                }
                if (validName) {
                    break;
                } else {
                    cout << "Invalid name format. Please enter alphabets and spaces only." << endl;
                    cout << "Enter Name (alphabets only): ";
                }
    }
        bool validID = false;
        while (!validID) {
            cout << "Enter Employee ID (alphanumeric, no spaces): ";
            cin >> empID;
            if (empID.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ01234567890") == string::npos) {
                validID = true;
            } else {
                cout << "Invalid Employee ID format. Please enter alphanumeric characters only." << endl;
            }
    }
        cout << "Enter Date of Birth (dd/mm/yyyy): ";
        cin >> dob;

        cout << "Enter Date of Joining (dd/mm/yyyy): ";
        cin >> doj;

        cout << "Enter Marital Status: ";
        cin >> maritalStatus;

        bool validPhoneNumber = false;
            while (!validPhoneNumber) {
                cout << "Enter Phone Number (10 digits only): ";
                cin >> phoneNumber;

                // Check if the input is the correct length and contains only digits
                if (phoneNumber.length() == 10 && std::all_of(phoneNumber.begin(), phoneNumber.end(), ::isdigit)) {
                    validPhoneNumber = true;
                } else {
                    cout << "Invalid phone number format. Please enter a 10-digit phone number." << endl;
                }
    }
        cout << "Enter Email ID: ";
        cin >> emailID;

        cout << "Enter Work Department: ";
        cin >> department;

        cout << "Enter CTC: ";
        cin >> ctc;
    }

    void displayDetails() const 
    {
        cout << "Name: " << name << endl;
        cout << "Employee ID: " << empID << endl;
        cout << "Date of Birth: " << dob << endl;
        cout << "Date of Joining: " << doj << endl;
        cout << "Marital Status: " << maritalStatus << endl;
        cout << "Phone Number: " << phoneNumber << endl;
        cout << "Email ID: " << emailID << endl;
        cout << "Work Department: " << department << endl;
        cout << "CTC: " << ctc << endl << endl;
    }

    string getEmpID() const {
        return empID;
    }

    void updateDetails() 
    {
        cout << "Update Name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Update Date of Birth (dd/mm/yyyy): ";
        cin >> dob;

        cout << "Update Date of Joining (dd/mm/yyyy): ";
        cin >> doj;

        cout << "Update Marital Status: ";
        cin >> maritalStatus;

        cout << "Update Phone Number: ";
        cin >> phoneNumber;

        cout << "Update Email ID: ";
        cin >> emailID;

        cout << "Update Work Department: ";
        cin >> department;

        cout << "Update CTC: ";
        cin >> ctc;
    }

    void saveToFile() 
    {
        ofstream outFile(empID + ".txt");
        if (outFile.is_open()) {
            outFile << "Name: " << name << endl;
            outFile << "Employee ID: " << empID << endl;
            outFile << "Date of Birth: " << dob << endl;
            outFile << "Date of Joining: " << doj << endl;
            outFile << "Marital Status: " << maritalStatus << endl;
            outFile << "Phone Number: " << phoneNumber << endl;
            outFile << "Email ID: " << emailID << endl;
            outFile << "Work Department: " << department << endl;
            outFile << "CTC: " << ctc << endl << endl;
            outFile.close();
            cout << "Employee record saved to file: " << empID + ".txt" << endl;
        } else {
            cout << "Error: Unable to open the file for writing." << endl;
        }
    }

    void setDetailsFromFile(const string& filename) 
    {
        ifstream inFile(filename);
        if (inFile.is_open()) {
            string line;
            while (getline(inFile, line)) {
                
            }
            inFile.close();
        } else {
            cout << "Unable to open file: " << filename << endl;
        }
    }

    void takeLeave(int leaveDays) 
    {
        leavesTaken += leaveDays;
        cout << "Leave of " << leaveDays << " days granted for Employee ID " << empID << "." << endl;
    }

    void viewLeaves() const 
    {
        cout << endl;
    }
};

class EmployeeManagement {
public:
    void addEmployee() {
        Employee newEmployee;
        newEmployee.setDetails();
        newEmployee.saveToFile();
    }

    void displayAllEmployees() const {
        cout << "Displaying all employees:" << endl;

        ifstream inFile;
        string filename;
        for (int i = 1; i <= 1000; ++i) {
            filename = to_string(i) + ".txt"; // Assuming filenames are employee IDs
            inFile.open(filename.c_str());

            if (inFile.is_open()) {
                string line;
                while (getline(inFile, line)) {
                    cout<< line << endl;
                }
                cout << endl;
                inFile.close();
            }
            
        }
    }

    void searchEmployee(const string& empID) const {
        ifstream inFile(empID + ".txt");
        if (inFile.is_open()) {
            string line;
            cout <<"\nInformation of Employee ID : "<< empID << endl;
            while (getline(inFile, line)) {
            
                cout << line << endl;
            }
            inFile.close();
        } else {
            cout << "Employee with ID " << empID << " not found." << endl;
        }
    }

    void updateEmployee(const string& empID) {
        ifstream inFile(empID + ".txt");
        if (inFile.is_open()) {
            inFile.close();
            Employee employee;
            employee.updateDetails();
            employee.saveToFile();
            cout << "Employee details updated successfully." << endl;
        } else {
            cout << "Employee with ID " << empID << " not found." << endl;
        }
    }

    void setDetailsFromFile(const string& empID) {
        Employee employee;
        employee.setDetailsFromFile(empID + ".txt");
    }


    void markAttendance(const string& empID) {
            string month;
            cout << "Enter the month to mark attendance (e.g., January, February, etc.): ";
            cin >> month;

            const int compulsoryWorkingDays = 23;

            int presentDays;
            cout << "Enter the number of days employee with employee id " << empID << " was present in " << month << endl << "(Compulsory Working Days: 23): ";
            cin >> presentDays;

            int absentDays = compulsoryWorkingDays - presentDays;

            int leaveDays;
            cout << "Enter the number of leave days: ";
            cin >> leaveDays;

            string filename = empID + "_" + month + "_Attendance.txt";
            ofstream outFile(filename);

            if (outFile.is_open()) {
                outFile << "Employee ID: " << empID << endl;
                outFile << "Month: " << month << endl;
                outFile << "Compulsory Working Days: " << compulsoryWorkingDays << endl;
                outFile << "Present Days: " << presentDays << endl;
                outFile << "Absent Days: " << absentDays << endl;
                outFile << "Leave Days: " << leaveDays << endl; 

                outFile.close();
                cout << "Attendance for Employee ID " << empID << " marked for " << month << "." << endl;
            } else {
                cout << "Error: Unable to open the file for writing." << endl;
    }
}



    void viewAttendance(const string& empID) {
        string month;
        cout << "Enter the month to view attendance (e.g., January, February, etc.): ";
        cin >> month;


        string filename = empID + "_" + month + "_Attendance.txt";
        ifstream inFile(filename);

    if (inFile.is_open()) {
        string line;
        while (getline(inFile, line)) {
            if (line.find("Month: " + month) != string::npos) {
            cout << "Employee ID: " << empID << endl;
            cout << line << endl; 
            for (int i = 0; i < 4; ++i) {
                getline(inFile, line); 
                cout << line << endl;
            }
        
            Employee employee;
            employee.setDetailsFromFile(empID + ".txt");
            employee.viewLeaves();
            break;
        }
    }

        inFile.close();
    } else {
        cout << "No attendance recorded for Employee ID " << empID << " in " << month << "." << endl;
    }
}

    void deleteEmployee(const string& empID) {
        string filename = empID + ".txt";
        if (remove(filename.c_str()) == 0) {
            cout << "Employee with ID " << empID << " has been deleted." << endl;
        } else {
            cout << "Employee with ID " << empID << " not found or unable to delete." << endl;
        }
    }
    void viewCTC(const string& empID) const {
        string filename = empID + ".txt";
        cout << "Attempting to open file: " << filename << endl; // Debug statement
        ifstream inFile(filename);
        if (inFile.is_open()) {
        string line;
        unsigned long long int ctc = 0;
        while (getline(inFile, line)) {
            if (line.find("CTC: ") != string::npos) {
                cout << "CTC for Employee ID " << empID << ": " << line.substr(5) << endl;
                stringstream ss(line.substr(5));
                if (ss >> ctc) {
                    double monthlySalary = static_cast<double>(ctc) / 12.0;
                    cout << "Monthly Salary: " << monthlySalary << endl;

                    string month;
                    cout << "Enter the month to view salary details (e.g., January, February, etc.): ";
                    cin >> month;

                    string attendanceFilename = empID + "_" + month + "_Attendance.txt";
                    ifstream attendanceFile(attendanceFilename);

                    if (attendanceFile.is_open()) {
                        int leaveDays = 0;
                        int absentDays = 0;
                        while (getline(attendanceFile, line)) {
                            if (line.find("Leave Days: ") != string::npos) {
                                stringstream leaves(line.substr(12));
                                leaves >> leaveDays;
                            }
                            if (line.find("Absent Days: ") != string::npos) {
                                stringstream absents(line.substr(13));
                                absents >> absentDays;
                            }
                        }
                        attendanceFile.close();

                        int totalAbsentDays = absentDays + (leaveDays > 3 ? leaveDays - 3 : 0);

                        double dailySalary = monthlySalary / 23.0;
                        double deductions = dailySalary * totalAbsentDays;

                        double monthlySalaryAfterDeduction = monthlySalary - deductions;
                        cout << "Salary for Employee ID " << empID << " in " << month << ": ₹" << monthlySalaryAfterDeduction << endl;
                    } else {
                        cout << "No attendance recorded for Employee ID " << empID << " in " << month << "." << endl;
                    }
                    inFile.close();
                    return; 
                } else {
                    cout << "Invalid CTC found for Employee ID " << empID << "." << endl;
                    inFile.close();
                    return; 
                }
            }
        }
        inFile.close();
        cout << "CTC not found for Employee ID " << empID << "." << endl;
    } else {
        cout << "Employee with ID " << empID << " not found." << endl;
    }
}
};

int main() {
     EmployeeManagement empManagement;
    int choice;
    string searchID, updateID;

    string username, password;
    const string adminUsername = "admin";
    const string adminPassword = "1234";
    bool loggedIn = false;

    do {
        cout << "        __________________________________" << endl;
        cout << "\n        EMPLOYEE RECORD MANAGEMENT SYSTEM    \n";
        cout << "        __________________________________\n" << endl;

        if (!loggedIn) {
            cout << "\tEnter Username: ";
            cin >> username;

            cout << "\tEnter Password: ";
            cin >> password;
            cout << endl;

            if (username == adminUsername && password == adminPassword) {
                loggedIn = true;
                cout << "\n\nLogin Successful!\n\n";
            } else {
                cout << "\n\nInvalid username or password. Please try again.\n\n";
            }
        } else {
    
        cout << "\t\t1. Add Employee\n\n";
        cout << "\t\t2. Display All Employees\n\n";
        cout << "\t\t3. Search Employee\n\n";
        cout << "\t\t4. Update Employee\n\n";
        cout << "\t\t5. Delete Employee data\n\n";
        cout << "\t\t6. Mark attendance\n\n";
        cout << "\t\t7. View attendance\n\n";
        cout << "\t\t8. View Salary\n\n";
        cout << "\t\t9. Exit\n\n";
        cout << "\t\tEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                empManagement.addEmployee();
                break;
            case 2:
                empManagement.displayAllEmployees();
                break;
            case 3:
                cout << "Enter Employee ID to search: ";
                cin >> searchID;
                empManagement.searchEmployee(searchID);
                break;
            case 4:
                cout << "Enter Employee ID to update: ";
                cin >> updateID;
                empManagement.updateEmployee(updateID);
                break;
            case 5:
                cout << "Enter Employee ID to delete: ";
                cin >> updateID;
                empManagement.deleteEmployee(updateID);
                break;
            case 6:
                cout << "Enter Employee ID to mark attendance: ";
                cin >> updateID;
                empManagement.markAttendance(updateID);
                break;
            case 7:
                cout << "Enter Employee ID to view attendance: ";
                cin >> searchID;
                empManagement.viewAttendance(searchID);
                break;
            case 8:
                cout << "Enter Employee ID to view Salary: ";
                cin >> searchID;
                empManagement.viewCTC(searchID);
                break;

            case 9:
                cout << "Exiting program.\n";
                break;
                default:
                cout << "Invalid choice. Please enter a valid option.\n";

         }
    }
    } while (choice != 9);
    
    return 0;
}