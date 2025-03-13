/*
39. Combination Sum
40. Combination Sum II
216. Combination Sum III
377. Combination Sum IV
46. Permutations    
131. Palindrome Partitioning
132. Palindrome Partitioning II
114. Flatten Binary Tree to Linked List
152. Maximum Product Subarray
213. House Robber II
221. Maximal Square
264. Ugly Number II
32. Longest Valid Parentheses
376. Wiggle Subsequence
442. Find All Duplicates in an Array 
437. Path Sum III
424. Longest Repeating Character Replacement
538. Convert BST to Greater Tree
542. 01 Matrix
621. Task Scheduler
678. Valid Parenthesis String
450. Delete Node in a BST
786. K-th Smallest Prime Fraction
738. Monotone Increasing Digits
790. Domino and Tromino Tiling
813. Largest Sum of Averages
546. remove boxes leetcode
2401. Longest Nice Subarray
907. Sum of Subarray Minimums
983. Minimum Cost For Tickets
1043. Partition Array for Maximum Sum
2767. Partition String Into Minimum Beautiful Substrings
1110. Delete Nodes And Return Forest
990. Satisfiability of Equality Equations
221. Maximal Square
1201. Ugly Number III
1334. Find the City With the Smallest Number of Neighbors at a Threshold Distance(IMP)
1530. Number of Good Leaf Nodes Pairs1786. Number of Restricted Paths From First to Last Node
1901. Find a Peak Element II
1915. Number of Wonderful Substrings(IMP)
1976. Number of Ways to Arrive at Destination
885. Spiral Matrix III
2952. Minimum Number of Coins to be Added 

*/
//https://docs.google.com/spreadsheets/d/1Vb97Fj-_vgeCmsMSBusFJqtSfhr_cgf-_PRRl6zM3ac/edit?gid=0#gid=0

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// Base Class:  Contact
class Contact {
protected: 
    string name;
    string phoneNumber;
    string email;

public: 
    // Constructors
    Contact() : name(""), phoneNumber(""), email("") {}
    Contact(string n, string p, string e) : name(n), phoneNumber(p), email(e) {}

    // Virtual Destructor
    virtual ~Contact() {}

    // Getters
    string getName() const { return name; }
    string getPhoneNumber() const { return phoneNumber; }
    string getEmail() const { return email; }

    // Setters
    void setName(string n) { name = n; }
    void setPhoneNumber(string p) { phoneNumber = p; }
    void setEmail(string e) { email = e; }

    // Virtual method to display contact information
    virtual void displayContact() const {
        cout << "Name: " << name << endl;
        cout << "Phone Number: " << phoneNumber << endl;
        cout << "Email: " << email << endl;
    }
};

// Derived Class:  PersonalContact
class PersonalContact : public Contact {
private: 
    string birthday;

public: 
    // Constructors
    PersonalContact() : Contact(), birthday("") {}
    PersonalContact(string n, string p, string e, string b) 
        : Contact(n, p, e), birthday(b) {}

    // Getter and Setter
    string getBirthday() const { return birthday; }
    void setBirthday(string b) { birthday = b; }

    // Overridden method to display contact information
    void displayContact() const override {
        Contact::displayContact();
        cout << "Birthday: " << birthday << endl;
    }
};

// Derived Class:  BusinessContact
class BusinessContact : public Contact {
private: 
    string companyName;
    string jobTitle;

public: 
    // Constructors
    BusinessContact() : Contact(), companyName(""), jobTitle("") {}
    BusinessContact(string n, string p, string e, string c, string j) 
        : Contact(n, p, e), companyName(c), jobTitle(j) {}

    // Getters and Setters
    string getCompanyName() const { return companyName; }
    void setCompanyName(string c) { companyName = c; }
    string getJobTitle() const { return jobTitle; }
    void setJobTitle(string j) { jobTitle = j; }

    // Overridden method to display contact information
    void displayContact() const override {
        Contact::displayContact();
        cout << "Company Name: " << companyName << endl;
        cout << "Job Title: " << jobTitle << endl;
    }
};

// ContactManager Class
class ContactManager {
private: 
    vector<Contact*> contacts;

public: 
    ~ContactManager() {
        for (auto contact : contacts) {
            delete contact;
        }
    }

    void addContact(Contact* contact) {
        contacts.push_back(contact);
    }

    void removeContact(const string& name) {
        auto it = remove_if(contacts.begin(), contacts.end(), [&name](Contact* c) {
            return c->getName() == name;
        });
        if (it != contacts.end()) {
            delete *it;
            contacts.erase(it);
        }
    }

    void updateContact(const string& name, Contact* updatedContact) {
        for (auto& contact : contacts) {
            if (contact->getName() == name) {
                delete contact;
                contact = updatedContact;
                break;
            }
        }
    }

    void listContacts() const {
        for (const auto& contact : contacts) {
            contact->displayContact();
            cout << "----------------------" << endl;
        }
    }

    void findContactByName(const string& name) const {
        for (const auto& contact : contacts) {
            if (contact->getName() == name) {
                contact->displayContact();
                return;
            }
        }
        cout << "Contact not found." << endl;
    }
};

// Main Function
int main() {
    ContactManager manager;
    int choice;
    string name, phoneNumber, email, extra;
    string companyName, jobTitle;

    do {
        cout << "Contact Management System" << endl;
        cout << "1. Add Personal Contact" << endl;
        cout << "2. Add Business Contact" << endl;
        cout << "3. Remove Contact" << endl;
        cout << "4. Update Contact" << endl;
        cout << "5. List All Contacts" << endl;
        cout << "6. Find Contact by Name" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  // To ignore the newline character after the number input

        switch (choice) {
            case 1: 
                cout << "Enter Name: ";
                getline(cin, name);
                cout << "Enter Phone Number: ";
                getline(cin, phoneNumber);
                cout << "Enter Email: ";
                getline(cin, email);
                cout << "Enter Birthday: ";
                getline(cin, extra);
                manager.addContact(new PersonalContact(name, phoneNumber, email, extra));
                break;
            case 2: 
                cout << "Enter Name: ";
                getline(cin, name);
                cout << "Enter Phone Number: ";
                getline(cin, phoneNumber);
                cout << "Enter Email: ";
                getline(cin, email);
                cout << "Enter Company Name: ";
                getline(cin, companyName);
                cout << "Enter Job Title: ";
                getline(cin, jobTitle);
                manager.addContact(new BusinessContact(name, phoneNumber, email, companyName, jobTitle));
                break;
            case 3: 
                cout << "Enter Name of the contact to remove: ";
                getline(cin, name);
                manager.removeContact(name);
                break;
            case 4: 
                cout << "Enter Name of the contact to update: ";
                getline(cin, name);
                cout << "Enter New Phone Number: ";
                getline(cin, phoneNumber);
                cout << "Enter New Email: ";
                getline(cin, email);
                cout << "Enter Contact Type (1 for Personal, 2 for Business): ";
                int type;
                cin >> type;
                cin.ignore();
                if (type == 1) {
                    cout << "Enter New Birthday: ";
                    getline(cin, extra);
                    manager.updateContact(name, new PersonalContact(name, phoneNumber, email, extra));
                } else if (type == 2) {
                    cout << "Enter New Company Name: ";
                    getline(cin, companyName);
                    cout << "Enter New Job Title: ";
                    getline(cin, jobTitle);
                    manager.updateContact(name, new BusinessContact(name, phoneNumber, email, companyName, jobTitle));
                } else {
                    cout << "Invalid type. Contact not updated." << endl;
                }
                break;
            case 5: 
                manager.listContacts();
                break;
            case 6: 
                cout << "Enter Name to find: ";
                getline(cin, name);
                manager.findContactByName(name);
                break;
            case 7: 
                cout << "Exiting..." << endl;
                break;
            default: 
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 7);

    return 0;
}
