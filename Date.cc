
#include "Date.h"

Date::Date(){
	setDate(1901,1,1);
}

Date::Date(int y, int m, int d){
	setDate(y,m,d);
}


Date::Date(const Date& d){
	setDate(d.year,d.month,d.day);
}

void Date::setDay(int d){
	int max = getMaxDay();
	if (d>max) d=max;
	if (d<1) d=1;
	day = d;
}

void Date::setMonth(int m){
	if (m > 12) m = 12;
	if (m < 1) m = 1;
	month = m;
}

void Date::setYear(int y){
	if (y < 1901) y = 1901;
	year = y;
}

void Date::setDate(int y, int m, int d){
	setMonth(m);
	setDay(d);
	setYear(y);
}

void Date::setDate(const Date& d){
	setDate(d.year, d.month, d.day);
}


int Date::getDay() const{ return day; }
int Date::getMonth() const{ return month; }
int Date::getYear() const{ return year; }
string Date::getMonthName() const{
	string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	return months[month-1];
}


void Date::incDate(){
	day += 1;
	if (day > getMaxDay()){
		day = 1;
		month += 1;
	}

	if (month > 12){
		month = 1;
		year += 1;
	}
}

void Date::addDays(int num){
	for (int i = 0; i < num; ++i){
		incDate();
	}
}

void Date::print(ostream& out) const{
	out << getMonthName()<<" "<<day<<", "<<year;
}

int Date::getMaxDay() const{
	switch(getMonth()){
		case 4:
		case 6:
		case 9:
		case 11: 			return 30;
		case 2:				return 28;
		default:			return 31;
	}
}

//overloading
bool Date::operator<(const Date& d) const{
	if(d.year > this->year){
		return true;
	}
	else if(d.year == this->year){
		if(d.month > this->month){
			return true;
		}
		else if(d.month == this->month){
			if(d.day > this->day){
				return true;
			}
		}
	}
	return false;

}

bool Date::operator==(const Date& d) const{
	return((d.year == this->year) && (d.month == this->month) && (d.day == this->day));
}

bool Date::operator<=(const Date& d) const{

	if(d.year > this->year){
		return true;
	}
	else if(d.year == this->year){

		if(d.month > this->month){
			return true;
		}
		else if(d.month == this->month){

			if(d.day > this->day || d.day == this->day){
				return true;
			}
		}
	}
	return false;
}

istream& operator>>(istream& is, Date& day){
    int y,m,d;

    is>>setw(2)>>y;
    is.ignore();  //throws away :
    is>>setw(2)>>m;
    is.ignore();
    is>>setw(2)>>d;

    day.setDate(y,m,d);

    return is;
}

ostream& operator<<(ostream& ost, const Date& t){
  ost<<setfill('0')<<setw(2)<< t.year<<","
      <<setfill('0')<<setw(2)<< t.month<<","
      <<setfill('0')<<setw(2)<< t.day;
    return ost;
}
