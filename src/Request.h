#ifndef REQUEST_H
#define REQUEST_H

#include <string>
using namespace std;

class Request {
private:
    int id;
    int bookId;
    int userId;
    string status;

public:
    Request();
    Request(int id, int bookId, int userId);

    void displayRequest() const;
};

#endif