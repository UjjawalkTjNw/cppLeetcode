#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class PhoneDirectory {
private:
    unordered_map<string, string> phoneBook;

public:
    void addContact(string phoneNumber, string contactInfo) {
        phoneBook[phoneNumber] = contactInfo;
    }

    string getContact(string phoneNumber) {
        if (phoneBook.find(phoneNumber) != phoneBook.end()) {
            return phoneBook[phoneNumber];
        } else {
            return "Contact not found";
        }
    }
};

int main() {
    PhoneDirectory directory;
    directory.addContact("1234567890", "Alice");
    directory.addContact("0987654321", "Bob");
    directory.addContact("5555555555", "Charlie");

    cout << "Retrieve 1234567890: " << directory.getContact("1234567890") << endl;
    cout << "Retrieve 5555555555: " << directory.getContact("5555555555") << endl;
    cout << "Retrieve 1111111111: " << directory.getContact("1111111111") << endl;

    return 0;
}
