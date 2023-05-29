#include "Photo.h"

Photo::Photo(const string& title, const string& category, const Date& date, const string& content)
: title(title), category(category), d(date), content(content){

}

Photo::Photo(){
  title = "default title";
  d = Date();
  content = "default content";
  category = "default category";
}


Photo::Photo(const Photo& p){
  title = p.title;
  d = p.d;
  content = p.content;
  category = p.category;
}

const Date& Photo::getDate() const{
  return d;
}

const string& Photo::getCategory () const{
  return category;
}

bool Photo::equals(const string& title) const{
  if(this->title == title){
    return true;
  }
  return false;
}

ostream& Photo::print(ostream& out) const{
  out<<title<<endl;
  out<<category<<endl;
  d.print(out);
  out<<endl;
  return out;
}

ostream& Photo::display(ostream& out) const{
  out<<content<<endl;
  this->print(out);
  return out;
}

ostream& operator<<(ostream&out, Photo& p){
  p.display(out);
  return out;
}
