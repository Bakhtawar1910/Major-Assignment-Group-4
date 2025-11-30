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
    User(); // Constructor (implementation will come later)
};

#endif