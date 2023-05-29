
#include "MediaFactory.h"
#include <fstream>
#include <sstream>
#include <limits>

Date MediaFactory::toDate(const string& d){
    stringstream ss;
    ss<<d;
    int year, month, day;
    ss>>year>>month>>day;
    return Date(year, month, day);
}

// 'upload' a photo
Photo* MediaFactory::uploadPhoto(const string& t){
    ifstream mediaFile;
    mediaFile.open("media/photos.txt");
    string temp, title, date, description, category;
    stringstream content;

    // We are assuming there is at least one record.
    // TBH not a great assumption to make
    cout<<"Searching for photo title: "<<t<<endl;
    while( getline(mediaFile, title)){
        if (t == title){
            getline(mediaFile, category);
            getline(mediaFile, date);
            getline(mediaFile, temp);
            while (temp!="!!endrecord!!"){
                content<<temp<<endl;
                getline(mediaFile, temp);
            }
            mediaFile.close();
            return new Photo(title, category, toDate(date), content.str());
        }

        // wrong title, advance to next photo
        while (temp!="!!endrecord!!"){
            getline(mediaFile, temp);
        }
    }

    mediaFile.close();
    return nullptr;
}

// create Criteria
Criteria* MediaFactory::dateCriteria(const Date& start, const Date& end){
  Criteria* date = new Date_Criteria(start, end);
  return date;
}
Criteria* MediaFactory::categoryCriteria(const string& cat){
  Criteria* c = new Cat_Criteria(cat);
  return c;
}
Criteria* MediaFactory::dateAndCatCriteria(const Date& start, const Date& end, const string& cat){
  Criteria* media = new CandD_Criteria(start, end, cat);
  return media;
}

Album* MediaFactory::createAlbum(const string& title, const string& description){
  Album* a = new Album(title, description);
  return a;
}
