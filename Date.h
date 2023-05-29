
#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Date {
	public:
		//constructor
		friend istream& operator>>(istream&, Date&);
		friend ostream& operator<<(ostream&, const Date&);
		Date();
		Date(int year, int month, int day);
		Date(const Date&);

		//setters
		void setDay( int);
		void setMonth(int);
		void setYear(int);
		void setDate(int, int, int);
		void setDate(const Date&);

		//getters
		int getDay() const;
		int getMonth() const;
		int getYear() const;
		string getMonthName() const;

		//other
		void incDate();
		void addDays(int);
		void print(ostream& out) const;

		//overloading
		bool operator<(const Date& d) const;
		bool operator==(const Date& d) const;
		bool operator<=(const Date& d) const;

	private:
		//functions
		int getMaxDay() const;

		//variables
		int day;
		int month;
		int year;

};
#endif
