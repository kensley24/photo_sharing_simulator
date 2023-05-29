
#ifndef PHOTO_H
#define PHOTO_H

#include <iostream>
#include <string>
#include <iomanip>
#include "Date.h"

using namespace std;

class Photo{
  public:

    friend ostream& operator<<(ostream& out, Photo& p);
    Photo(const string& title, const string& category, const Date& date, const string& content);
    Photo();
    Photo(const Photo& p);
    bool equals(const string& title) const;
    ostream& print(ostream& out) const;
    ostream& display(ostream& out) const;

    const Date& getDate () const;
    const string& getCategory () const;




  private:
    string title;
    string content;
    string category;
    Date d;
};

#endif
