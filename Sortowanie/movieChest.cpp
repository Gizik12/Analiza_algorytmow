#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "movieChest.h"
using namespace std;

//Setery i getery dla klasy Movie
void Movie::setNumber(int v)
{
    this->number = v;
}
int Movie::getNumber()
{
    return this->number;
}
void Movie::setTitle(string n)
{
    this->title = n;
}
string Movie::getTitle()
{
    return this->title;
}
void Movie::setRating(float v)
{
    this->rating = v;
}
float Movie::getRating()
{
    return this->rating;
}
//Setery i getery dla klasy Tab
void MovieChest::setSize(int v)
{
    this->size = v;
}
int MovieChest::getSize()
{
    return this->size;
}
void MovieChest::setCapacity(int v)
{
    this->capacity = v;
}
int MovieChest::getCapacity()
{
    return this->capacity;
}
MovieChest::MovieChest(int cap)
{
    this->size = 0;
    this->capacity = cap;
}
void MovieChest::addMovie(Movie* movie) // Funkcja dodająca filmy do tablicy
{
    if(size < capacity)
    {
        tab.push_back(movie);
        size++;
    }
    else
    {
        cout << "Za mało miejsca w tablicy" << endl;
    }
}
void MovieChest::loadData(int amount_of_data)
{
    setCapacity(amount_of_data);
    int number = 0;
    string title = "";
    float rating = 0.0f;
    ifstream file("data.txt");
    if (file.is_open())
    {
        string line;
        cout << "Poprawnie otworzony plik" << endl;
        for (int i = 0; i < this->capacity && getline(file, line); i++)
        {
            istringstream iss(line);
            string token;

            if (getline(iss, token, ','))
            {
                number = stoi(token);
            }
            if (getline(iss, token, ','))
            {
                if (token.front() == '"')
                {
                    title = token.substr(1);
                    while (getline(iss, token, ','))
                    {
                        title += "," + token;
                        if (token.back() == '"')
                        {
                            title.pop_back();
                            break;
                        }
                    }
                }
                else
                {
                    title = token;
                }
            }
            if (getline(iss, token, ','))
            {
                rating = stof(token);
            }
            else
            {
                rating = 0.0f;
            }

            Movie* m = new Movie(); // Alokacja dynamiczna obiektu Movie
            m->setNumber(number);
            m->setTitle(title);
            m->setRating(rating);

            if (m->getRating() != 0.0f)
            {
                addMovie(m);
            }
        }
    }
    file.close();
}
void MovieChest::showMovie()
{
    for(int i = 0; i < this->size; i++)
    {
        cout << tab[i]->getNumber() << " " << tab[i]->getTitle() << " " << tab[i]->getRating() << endl;
    }
}
Movie* MovieChest::getMovie(int index) // Funckja zwraca pojedynczy obiekt o danym indeksie
{
    if (index >= 0 && index < size)
    {
        return tab[index];
    }
    else
    {
        return nullptr; // Zwracamy nullptr, jeśli indeks jest nieprawidłowy
    }
}