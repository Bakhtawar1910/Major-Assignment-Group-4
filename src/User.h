#ifndef USER_H
#define USER_H

#include <string>
using namespace std;

class User {
private:
    int id;
    string name;
    string email;
    string phone;

public:
    User();
    User(int id, string name, string email, string phone);

    int getId() const { return id; }
    string getName() const { return name; }

    void displayUser() const;
};

#endif