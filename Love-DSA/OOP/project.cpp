#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

// Base Class - Contact
class Contact {
protected:
    string name;
    string phone;
    string email;

public:
    Contact(string name, string phone, string email) : name(name), phone(phone), email(email) {}

    // Encapsulation: Getters and setters for the attributes
    string getName() const { return name; }
    void setName(const string& n) { name = n; }

    string getPhone() const { return phone; }
    void setPhone(const string& p) { phone = p; }

    string getEmail() const { return email; }
    void setEmail(const string& e) { email = e; }

    // Virtual function for displaying contact info (Polymorphism)
    virtual void displayInfo() const {
        cout << "Name: " << name << "\nPhone: " << phone << "\nEmail: " << email << endl;
    }

    // Pure virtual function for unique features
    virtual bool isEmergencyContact() const = 0;

    virtual ~Contact() {}
};

// Derived Class - PersonalContact
class PersonalContact : public Contact 
{
    bool isFavorite;

public:
    PersonalContact(string name, string phone, string email, bool favorite = false)
        : Contact(name, phone, email), isFavorite(favorite) {}

    void markAsFavorite() { isFavorite = true; }
    bool isFavoriteContact() const { return isFavorite; }

    void displayInfo() const override {
        Contact::displayInfo();
        cout << "Favorite: " << (isFavorite ? "Yes" : "No") << endl;
    }

    bool isEmergencyContact() const override {
        return false; // Personal contacts are not emergency contacts
    }
};

// Derived Class - WorkContact
class WorkContact : public Contact {
    string company;
    string position;

public:
    WorkContact(string name, string phone, string email, string company, string position)
        : Contact(name, phone, email), company(company), position(position) {}

    void displayInfo() const override {
        Contact::displayInfo();
        cout << "Company: " << company << "\nPosition: " << position << endl;
    }

    bool isEmergencyContact() const override {
        return false; // Work contacts are not emergency contacts
    }
};

// Derived Class - EmergencyContact
class EmergencyContact : public Contact {
    string relationship;

public:
    EmergencyContact(string name, string phone, string email, string relationship)
        : Contact(name, phone, email), relationship(relationship) {}

    void displayInfo() const override {
        Contact::displayInfo();
        cout << "Relationship: " << relationship << "\n[EMERGENCY CONTACT]" << endl;
    }

    bool isEmergencyContact() const override {
        return true; // Emergency contacts are marked as emergency
    }
};

// ContactManager Class - Manages all contacts
class ContactManager {
    vector<Contact*> contacts;

public:
    // Add a new contact
    void addContact(Contact* contact) {
        contacts.push_back(contact);
    }

    // Search contact by name
    Contact* searchContact(const string& name) {
        for (Contact* contact : contacts) {
            if (contact->getName() == name) {
                return contact;
            }
        }
        return nullptr;
    }

    // Display all contacts
    void displayAllContacts() {
        for (Contact* contact : contacts) {
            contact->displayInfo();
            cout << "--------------------------" << endl;
        }
    }

    // Delete a contact by name
    void deleteContact(const string& name) {
        for (auto it = contacts.begin(); it != contacts.end(); ++it) {
            if ((*it)->getName() == name) {
                delete *it;
                contacts.erase(it);
                cout << "Contact '" << name << "' deleted successfully." << endl;
                return;
            }
        }
        cout << "Contact not found!" << endl;
    }

    // Save contacts to file
    void saveContactsToFile(const string& filename) {
        ofstream file(filename);
        for (Contact* contact : contacts) {
            file << contact->getName() << "," << contact->getPhone() << "," << contact->getEmail() << "\n";
        }
        file.close();
        cout << "Contacts saved to file." << endl;
    }

    // Load contacts from file
    void loadContactsFromFile(const string& filename) {
        ifstream file(filename);
        string line;
        while (getline(file, line)) {
            cout << "Loaded: " << line << endl;
            // You can parse and create new Contact objects here
        }
        file.close();
    }

    // Destructor to free memory
    ~ContactManager() {
        for (Contact* contact : contacts) {
            delete contact;
        }
    }
};

// Function to get user input for a new contact
void getUserInput(ContactManager& manager) {
    int choice;
    cout << "Enter the type of contact you want to add:\n";
    cout << "1. Personal Contact\n2. Work Contact\n3. Emergency Contact\n";
    cin >> choice;
    cin.ignore();

    string name, phone, email;
    cout << "Enter Name: ";
    getline(cin, name);
    cout << "Enter Phone: ";
    getline(cin, phone);
    cout << "Enter Email: ";
    getline(cin, email);

    if (choice == 1) {
        char favChoice;
        cout << "Mark as Favorite? (y/n): ";
        cin >> favChoice;
        bool isFavorite = (favChoice == 'y' || favChoice == 'Y');
        manager.addContact(new PersonalContact(name, phone, email, isFavorite));
    } else if (choice == 2) {
        string company, position;
        cout << "Enter Company: ";
        cin.ignore();
        getline(cin, company);
        cout << "Enter Position: ";
        getline(cin, position);
        manager.addContact(new WorkContact(name, phone, email, company, position));
    } else if (choice == 3) {
        string relationship;
        cout << "Enter Relationship: ";
        getline(cin, relationship);
        manager.addContact(new EmergencyContact(name, phone, email, relationship));
    } else {
        cout << "Invalid choice!" << endl;
    }
}

int main() {
    ContactManager manager;
    int option;

    do {
        cout << "\nContact Management System\n";
        cout << "1. Add Contact\n2. Display All Contacts\n3. Search Contact\n4. Delete Contact\n5. Save Contacts\n6. Load Contacts\n0. Exit\n";
        cout << "Enter option: ";
        cin >> option;
        cin.ignore();

        switch (option) {
            case 1:
                getUserInput(manager);
                break;
            case 2:
                manager.displayAllContacts();
                break;
            case 3: {
                string name;
                cout << "Enter name to search: ";
                getline(cin, name);
                Contact* contact = manager.searchContact(name);
                if (contact) {
                    cout << "Contact found:\n";
                    contact->displayInfo();
                } else {
                    cout << "Contact not found!" << endl;
                }
                break;
            }
            case 4: {
                string name;
                cout << "Enter name to delete: ";
                getline(cin, name);
                manager.deleteContact(name);
                break;
            }
            case 5:
                manager.saveContactsToFile("contacts.txt");
                break;
            case 6:
                manager.loadContactsFromFile("contacts.txt");
                break;
            case 0:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid option!" << endl;
        }
    } while (option != 0);

    return 0;
}
