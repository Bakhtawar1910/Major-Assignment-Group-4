/**
 * @file User.h
 * @brief Declaration of the User class.
 *
 * Represents a user who can donate or request books
 * within the Old Book Exchange System.
 */

#ifndef USER_H
#define USER_H

#include <string>

using namespace std;

/**
 * @class User
 * @brief Represents a system user.
 *
 * Stores user information such as ID, name,
 * email, and phone number. Users can donate
 * or request books through the system.
 */
class User {
private:
    /**
     * @brief Unique identifier for the user.
     */
    int id;

    /**
     * @brief Name of the user.
     */
    string name;

    /**
     * @brief Email address of the user.
     */
    string email;

    /**
     * @brief Phone number of the user.
     */
    string phone;

public:
    /**
     * @brief Default constructor.
     */
    User();

    /**
     * @brief Parameterized constructor.
     *
     * @param id Unique identifier for the user
     * @param name Name of the user
     * @param email Email address of the user
     * @param phone Phone number of the user
     */
    User(int id, string name, string email, string phone);

    /**
     * @brief Gets the user ID.
     * @return User ID
     */
    int getId() const { return id; }

    /**
     * @brief Gets the user name.
     * @return User name
     */
    string getName() const { return name; }

    /**
     * @brief Gets the user email.
     * @return User email
     */
    string getEmail() const { return email; }

    /**
     * @brief Gets the user phone number.
     * @return User phone number
     */
    string getPhone() const { return phone; }

    /**
     * @brief Displays user details.
     */
    void displayUser() const;
};

#endif
