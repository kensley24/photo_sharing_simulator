#ifndef CRITERIA_H
#define CRITERIA_H

#include <iostream>
#include <string>
#include <iomanip>
#include "Photo.h"
#include "Date.h"

using namespace std;

class Criteria {
  public:
    friend ostream& operator<<(ostream& out, const Criteria& c);
    virtual bool matches(const Photo& p) const = 0;
    virtual void print(ostream& out) const = 0;

};


class Cat_Criteria: virtual public Criteria {
  public:
    Cat_Criteria(const string& cat);
    virtual bool matches(const Photo& p) const;
    virtual void print(ostream& out) const;

  private:
    string category;

};


class Date_Criteria: virtual public Criteria {
  public:
    Date_Criteria(const Date& s, const Date& e);
    virtual bool matches(const Photo& p) const;
    virtual void print(ostream& out) const;

  private:
    Date start;
    Date end;

};

class CandD_Criteria: virtual public Date_Criteria, virtual public Cat_Criteria {
  public:
    CandD_Criteria(const Date& start, const Date& end, const string& category);
    virtual bool matches(const Photo& p) const;
    virtual void print(ostream& out) const;

};

#endif
