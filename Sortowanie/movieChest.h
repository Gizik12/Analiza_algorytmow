#ifndef _movieChest_H_
#define _movieChest_H_
#include <iostream>
#include <vector>
#include <string>
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
    float getRating() const;
    void setRating(float v);
};

class MovieChest
{
    // Tablica obiektów Movie
    vector <Movie*> tab;
    int size;
    int capacity;

    public:
    MovieChest() : size(0), capacity(0) {}
    int getSize();
    void setSize(int v);
    int getCapacity();
    void setCapacity(int v);
    void loadData(int amount_of_data);
    void clear();
    void addMovie(Movie* movie);
    void showMovie();
    Movie* getMovie(int index);
    void setMovie(int index, Movie* movie);
    void swapMovies(int index1, int index2);
};
#endif