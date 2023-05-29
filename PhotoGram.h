#ifndef PHOTOGRAM_H
#define PHOTOGRAM_H

#include <iostream>
#include <string>
#include <iomanip>
#include "Album.h"
#include "defs.h"
#include "Photo.h"
#include "Criteria.h"
#include "MediaFactory.h"
#include "View.h"

class PhotoGram{
  public:
    PhotoGram();
    ~PhotoGram();

    bool addAlbum(const string& title, const string& description);
    void addToAlbum(int index, Array<Photo*>& photos);
    void uploadPhoto(const string& title);
    bool deleteAlbum(int index);
    void getPhotos(const Criteria& c, Array<Photo*>& photoArray);
    void displayAlbum(int index, View& v) const;
    int printAlbums(View& v) const;
    void displayPhoto(int index, View& v) const;
    int printPhotos(View& v) const;

  private:
    Array<Album*> albArr;
    Array<Photo*> photoList;
    MediaFactory media;

};


#endif
