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
void MovieChest::addMovie(Movie* movie) //funkcja dodająca filmy do tablicy
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
    int number = 0;
    string title = "";
    float rating = 0.0f;
    ifstream file("data.txt");
    if(file.is_open())
    {
        string line;
        cout << "Poprawnie otworzony plik"<<endl;
        for(int i = 0; i < amount_of_data && getline(file, line); i++)
        {
            istringstream iss(line);
            string token;

            // Wczytujemy numer, tytuł i ocenę filmu z linii
            if (getline(iss, token, ','))
            {
                number = stoi(token); // Konwersja ciągu znaków na liczbę
            }
            if (getline(iss, token, ','))
            {
                // Sprawdzamy, czy token zaczyna się od cudzysłowia
                if (token.front() == '"')
                {
                    title = token.substr(1); // Usuwamy cudzysłowia z początku
                    while (getline(iss, token, ','))
                    {
                        title += "," + token; // Dodajemy kolejne tokeny do tytułu filmu
                        if (token.back() == '"') // Jeśli ostatni token kończy się cudzysłowiem, kończymy wczytywanie tytułu
                        {
                            title.pop_back(); // Usuwamy cudzysłowia z końca
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
                rating = stof(token); // Konwersja ciągu znaków na float
            }
            else
            {
                rating = 0.0f;
            }

            Movie m;
            m.setNumber(number);
            m.setTitle(title);
            m.setRating(rating);

            if(m.getRating() != 0.0f) //Sprawdzanie czy isnije ocena filmu, jeśli nie pomijamy
            {
                addMovie(&m);
            }
        }
    }
    file.close();
}