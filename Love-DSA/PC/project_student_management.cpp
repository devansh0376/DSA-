#include <iostream>
#include <vector>

using namespace std;

class Subject {
public:
    string name;
    int credits;
    int grade;

    Subject(const string& subjectName, int subjectCredits)
        : name(subjectName), credits(subjectCredits), grade(0) {}

    void setGrade(int subjectGrade) {
        grade = subjectGrade;
    }
};

class Student {
public:
    string name;
    int rollNumber;
    vector<Subject> subjects;

    Student(const string& studentName, int studentRollNumber)
        : name(studentName), rollNumber(studentRollNumber) {}

    void enrollSubject(const string& subjectName, int subjectCredits) {
        Subject newSubject(subjectName, subjectCredits);
        subjects.push_back(newSubject);
    }

    void updateGrade(const string& subjectName, int subjectGrade) {
        for (auto& subject : subjects) {
            if (subject.name == subjectName) {
                subject.setGrade(subjectGrade);
                return;
            }
        }
        cout << "Subject not found.\n";
    }

    void displayDetails() {
        cout << "Student Name: " << name << "\n";
        cout << "Roll Number: " << rollNumber << "\n";
        cout << "Subjects Enrolled:\n";
        for (const auto& subject : subjects) {
            cout << "Subject: " << subject.name << ", Credits: " << subject.credits << ", Grade: " << subject.grade << "\n";
        }
    }
};

int main() {
    string studentName;
    int rollNumber;

    cout << "Enter student name: ";
    getline(cin, studentName);

    cout << "Enter student roll number: ";
    cin >> rollNumber;
    cin.ignore(); // Ignore the newline character left in the input buffer

    Student student(studentName, rollNumber);

    int choice;
    bool exitProgram = false;

    while (!exitProgram) {
        cout << "\n---- Student Management System ----\n";
        cout << "1. Enroll Subject\n";
        cout << "2. Update Grade\n";
        cout << "3. Display Student Details\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: {
                string subjectName;
                int subjectCredits;

                cout << "Enter subject name: ";
                getline(cin, subjectName);

                cout << "Enter subject credits: ";
                cin >> subjectCredits;
                cin.ignore();

                student.enrollSubject(subjectName, subjectCredits);
                break;
            }
            case 2: {
                string subjectName;
                int subjectGrade;

                cout << "Enter subject name: ";
                getline(cin, subjectName);

                cout << "Enter grade for " << subjectName << ": ";
                cin >> subjectGrade;
                cin.ignore();

                student.updateGrade(subjectName, subjectGrade);
                break;
            }
            case 3:
                student.displayDetails();
                break;
            case 4:
                exitProgram = true;
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    }

    return 0;
}

     