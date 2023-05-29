#include "Criteria.h"


ostream& operator<<(ostream& os, const Criteria& a){
    a.print(os);
    return os;
}

//Cat_Criteria
Cat_Criteria::Cat_Criteria(const string& cat){
  category = cat;
}

bool Cat_Criteria::matches(const Photo& p) const{
  if(p.getCategory() == category){
    return true;
  }
  return false;
}

void Cat_Criteria::print(ostream& out) const{
  out<<"Category: "<<category<<endl;
  //return out;
}

//date criteria
Date_Criteria::Date_Criteria(const Date& s, const Date& e){
  start = s;
  end = e;
}

bool Date_Criteria::matches(const Photo& p) const{
  if((start <= p.getDate()) && (p.getDate() <= end)){
    return true;
  }
  return false;
}
void Date_Criteria::print(ostream& out) const{
  out<<"printing date criteria: start date - "<<start<<"end date - "<<end<<endl;
  //return out;
}


CandD_Criteria::CandD_Criteria(const Date& start, const Date& end, const string& category)
:Date_Criteria(start, end), Cat_Criteria(category){

}

bool CandD_Criteria::matches(const Photo& p) const{
  if(Date_Criteria::matches(p) && Cat_Criteria::matches(p)){
    return true;
  }
  return false;
}

void CandD_Criteria::print(ostream& out) const{
  out<<"printing from CandD_Criteria"<<endl;
  Date_Criteria::print(out);
  Cat_Criteria::print(out);
  //return out;
}
