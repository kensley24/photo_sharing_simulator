#include "PhotoGram.h"
#include "MediaFactory.h"

PhotoGram::PhotoGram(){

}

PhotoGram::~PhotoGram(){

  for(int i = 0; i < albArr.getSize(); i++){
    delete albArr[i];
  }

  for(int i = 0; i < photoList.getSize(); i++){
    delete photoList[i];
  }

}


bool PhotoGram::addAlbum(const string& title, const string& description){
  if(albArr.isFull()){
    cout<<"the album array is too full"<<endl;
    return false;
  }
  MediaFactory m;
  Album* newAlb = m.createAlbum(title, description);
  albArr.add(newAlb);
  return true;
}
/*
bool PhotoGram::removeAlbum(const string& albumTitle){
  Album* rmv = albArr->remove(albumTitle);
  if(rmv == nullptr){
    cout<<"could not remove album "<<albumTitle<<endl;
    return false;
  }
  delete rmv;
  return true;
}

bool PhotoGram::removePhoto(const string& albumTitle, const string& photoTitle){
  Album* alb = albArr->get(albumTitle);
  if(alb == nullptr){
    cout<<"could not find album "<<albumTitle<<endl;
    return false;
  }
  Photo* ph = alb->removePhoto(photoTitle);
  if(ph == nullptr){
    cout<<"could not find photo "<<photoTitle<<endl;
    return false;
  }
  delete ph;
  return true;
}

Album* PhotoGram::downloadAlbum(const string& albumTitle) const{
  Album* alb = albArr->get(albumTitle);
  if(alb == nullptr){
    cout<<"album named "<<albumTitle<<" does not exist"<<endl;
    return nullptr;
  }

  return alb;

}


Photo* PhotoGram::downloadPhoto(const string& albumTitle, const string& photoTitle) const{
  Album* alb = albArr->get(albumTitle);
  if(alb == nullptr){
    cout<<"album named "<<albumTitle<<" does not exist"<<endl;
    return nullptr;
  }
  Photo* p = alb->getPhoto(photoTitle);
  if(p == nullptr){
    cout<<"photo named "<<photoTitle<<" does not exist"<<endl;
    return nullptr;
  }
  return p;
}

void PhotoGram::printAlbums() const{
  for(int i = 0; i < albArr->size(); i++){
    cout<<"********************************"<<endl;
    albArr->get(i)->print();
    cout<<"********************************"<<endl;
  }
}

void PhotoGram::displayAlbums() const{
  for(int i = 0; i< albArr->size(); i++){
    cout<<"*****************************"<<endl;
    albArr->get(i)->display();
    cout<<"*****************************"<<endl;
  }
}
*/

void PhotoGram::addToAlbum(int index, Array<Photo*>& photos){
  if(index < 0 || index > albArr.getSize()){
    return;
  }
  for(int i = 0; i < photos.getSize(); i++){
    albArr[index]->addPhoto(photos[i]);
  }
}

void PhotoGram::uploadPhoto(const string& title){
  MediaFactory m;
  Photo* p = m.uploadPhoto(title);
  photoList.add(p);
}

bool PhotoGram::deleteAlbum(int index){
  if(index < 0 || index >= albArr.getSize()){
    cout<<"bad index"<<endl;
    return false;
  }

  Album* a = albArr[index];
  albArr.remove(a);
  delete a;
  return true;
}

void PhotoGram::getPhotos(const Criteria& c, Array<Photo*>& photoArray){
  for(int i = 0; i < photoList.getSize(); i++){
    if(c.matches(*(photoList[i]))){
      photoArray.add(photoList[i]);
    }
  }
}

void PhotoGram::displayAlbum(int index, View& v) const{
  if(index < 0 || index >= albArr.getSize()){
    cout<<"invalid index"<<endl;
  }
  else{
    v.displayAlbum(*albArr[index]);
  }

}

int PhotoGram::printAlbums(View& v) const{
  v.printAlbums(albArr);
  return (albArr.getSize());
}

void PhotoGram::displayPhoto(int index, View& v) const{
  if(index < 0 || index > photoList.getSize()){
    cout<<"invalid index"<<endl;
  }
  else{
    v.displayPhoto(*photoList[index]);
  }
}

int PhotoGram::printPhotos(View& v) const{
  v.printPhotos(photoList);
  return (photoList.getSize());
}
