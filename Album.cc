#include "Album.h"

Album::Album(const string& t, const string& d): title(t), description(d){

}


Album::~Album(){

}

string Album::getTitle() const{
  return title;
}

bool Album::equals(const string& title) const{
  if(this->title == title){
    return true;
  }
  return false;
}


bool Album::addPhoto(Photo* p){
  array.add(p);
  return true;
}

Photo* Album::getPhoto(int index) const{
  if(index < 0 || index > array.getSize()){
    cout<<"invalid index"<<endl;
    return nullptr;
  }
  return(array[index]);
}

int Album::size() const{
  return(array.getSize());
}

ostream& Album::print(ostream& out)const{
  out<<title<<endl;
  out<<description<<endl;
  return out;
}


ostream& Album::display(ostream& out) const{
  print(out);
  for(int i = 0; i < array.getSize(); i++){
    out<< *(array[i]);
  }
  return out;
}

ostream& operator<<(ostream& out, const Album& a){
  a.print(out);
  return out;
}
