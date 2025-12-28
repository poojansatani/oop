#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Student {
private:
    string name, subject;
    int rollNo;

public:
    Student(string Name, int RollNo, string Subject) {
        name = Name;
        rollNo = RollNo;
        subject = Subject;
    }

    void setName(string Name) { name = Name; }
    void setRollNo(int RollNo) { rollNo = RollNo; }
    void setSubject(string Subject) { subject = Subject; }

    string getName() { return name; }
    int getRollNo() { return rollNo; }
    string getSubject() { return subject; }
};

class College {
private:
    vector<Student> ve;

public:
    void add(string Name, int RollNo, string Subject) {
        ve.push_back(Student(Name, RollNo, Subject));
    }

    void display() {
        if (ve.empty()) {
            cout << "No students available.\n";
            return;
        }
        for (auto &s : ve) {
            cout << "Name: " << s.getName()
                 << ", Roll No: " << s.getRollNo()
                 << ", Subject: " << s.getSubject() << endl;
        }
    }

    void update() {
        int rollNo;
        cout << "Enter Roll No to update: ";
        cin >> rollNo;

        bool found = false;

        for (auto &s : ve) {
            if (s.getRollNo() == rollNo) {
                found = true;

                cin.ignore();
                string name, subject;
                int newRoll;

                cout << "Enter new Roll No: ";
                cin >> newRoll;
                cin.ignore();

                cout << "Enter new Name: ";
                getline(cin, name);

                cout << "Enter new Subject: ";
                getline(cin, subject);

                s.setRollNo(newRoll);
                s.setName(name);
                s.setSubject(subject);

                cout << "Student updated successfully.\n";
                break;
            }
        }

        if (!found) {
            cout << "Student not found.\n";
        }
    }
};

int main() {
    College college;
    int choice;

    while (true) {
        cout << "\n1. Add Student\n2. Display Students\n3. Update Student\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        cin.ignore();

        if (choice == 1) {
            string name, subject;
            int roll;

            cout << "Enter Name: ";
            getline(cin, name);

            cout << "Enter Roll No: ";
            cin >> roll;
            cin.ignore();

            cout << "Enter Subject: ";
            getline(cin, subject);

            college.add(name, roll, subject);
        }
        else if (choice == 2) {
            college.display();
        }
        else if (choice == 3) {
            college.update();
        }
        else if (choice == 4) {
            break;
        }
        else {
            system("cls");
            cout << "Invalid choice.\n";
        }
    }
    return 0;
}
