#ifndef ALBUM_H
#define ALBUM_H

#include <iostream>
#include <string>
#include <iomanip>
#include "Array.h"
#include "Photo.h"

using namespace std;

class Album {
  public:
    /*
    Album ( const string & title , const string & description );
    bool equals ( const string & title ) const ;
    void addPhoto ( Photo *);
    Photo * getPhoto (int) const ;
    int size () const ;
    void print ( ostream &) const ;
    void display ( ostream &) const ;
    */
    friend ostream& operator<<(ostream& out, const Album& a);
    Album(const string& title, const string& description);
    //Album(const Album& oldAlbum);
    ~Album();
    ostream& print(ostream& out) const;
    string getTitle() const;
    bool equals(const string& title) const;
    //bool lessThan(const Album& alb) const;
    //add at back******
    bool addPhoto(Photo* p);
    //bool addPhoto(int index, Photo* p);
    //Photo* getPhoto(const string& title) const;
    Photo* getPhoto(int index) const;
    //Photo* removePhoto(int index);
    //Photo* removePhoto(const string& title);
    int size() const;
    ostream& display(ostream & out) const;

  private:
    string title;
    string description;
    Array<Photo*> array;
    //PhotoArray* array;


};

#endif
