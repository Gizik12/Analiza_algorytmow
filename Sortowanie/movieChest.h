#ifndef _movieChest_H_
#define _movieChest_H_
#include <iostream>
#include <vector>
using namespace std;


class Movie
{
    int number;
    string title;
    float rating;

    public:
    int getNumber();
    void setNumber(int v);
    string getTitle();
    void setTitle(string n);
    float getRating();
    void setRating(float v);
};

class MovieChest
{
    //tablica obiektów Movie
    vector <Movie*> tab;
    int size;
    int capacity;

    public:
    MovieChest(int cap);
    int getSize();
    void setSize(int v);
    int getCapacity();
    void setCapacity(int v);
    void loadData(int amount_of_data);
    void addMovie(Movie* movie);
};
#endif