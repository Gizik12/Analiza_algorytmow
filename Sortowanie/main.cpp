#include <iostream>
#include <chrono>
#include "movieChest.h"
#include "sortingAlgorithms.h"

using namespace std;
using namespace std::chrono;

// Funkcja do konwersji czasu w milisekundach na sekundy lub minuty
string formatTime(long long time_ms)
{
    if (time_ms >= 60000) // Jeśli czas jest co najmniej 1 minutą
    {
        long long minutes = time_ms / 60000;
        long long seconds = (time_ms % 60000) / 1000;
        return to_string(minutes) + " min " + to_string(seconds) + " sec";
    }
    else // Jeśli czas jest krótszy niż 1 minuta
    {
        long long seconds = time_ms / 1000;
        long long milliseconds = time_ms % 1000;
        return to_string(seconds) + " sec " + to_string(milliseconds) + " ms";
    }
}
// Funkcja obliczająca medianę dla posortowanego wektora
float calculateMedian(const vector<Movie*>& movies)
{
    int size = movies.size();
    if (size % 2 == 0)
    {
        return (movies[size / 2 - 1]->getRating() + movies[size / 2]->getRating()) / 2.0;
    }
    else
    {
        return movies[size / 2]->getRating();
    }
}

// Funkcja obliczająca średnią dla posortowanego wektora
float calculateMean(const vector<Movie*>& movies)
{
    float sum = 0.0;
    for (const Movie* movie : movies)
    {
        sum += movie->getRating();
    }
    return sum / movies.size();
}

int main()
{
    int data_sizes[] = {10000, 100000, 500000, 1000000, 1010292};
    int amount_of_data = data_sizes[4]; // Ustawiamy ile danych ma wczytac program
    MovieChest tab; // Użycie konstruktora domyślnego
    tab.loadData(amount_of_data); // Wczytanie danych z pliku do tablicy

    // Sortowanie za pomocą merge sort
    cout << "Sorting using Merge Sort:\n";
    auto start = high_resolution_clock::now();
    vector<Movie*> movies;
    for (int i = 0; i < tab.getSize(); ++i) {
        movies.push_back(tab.getMovie(i));
    }
    mergeSort(movies, 0, movies.size() - 1);
    auto end = high_resolution_clock::now();
    long long merge_sort_time = duration_cast<milliseconds>(end - start).count();
    cout << "Time taken: " << formatTime(merge_sort_time) << endl;

    // Obliczanie mediany i średniej
    float median = calculateMedian(movies);
    float mean = calculateMean(movies);
    cout << "Median: " << median << endl;
    cout << "Mean: " << mean << endl;

    // Ponowne wczytanie danych, aby móc sortować jeszcze raz
    tab.loadData(amount_of_data);

    // Sortowanie za pomocą quick sort
    cout << "\nSorting using Quick Sort:\n";
    start = high_resolution_clock::now();
    quickSort(tab, 0, tab.getSize() - 1);
    end = high_resolution_clock::now();
    long long quick_sort_time = duration_cast<milliseconds>(end - start).count();
    cout << "Time taken: " << formatTime(quick_sort_time) << endl;

    // Obliczanie mediany i średniej
    movies.clear();
    for (int i = 0; i < tab.getSize(); ++i) {
        movies.push_back(tab.getMovie(i));
    }
    median = calculateMedian(movies);
    mean = calculateMean(movies);
    cout << "Median: " << median << endl;
    cout << "Mean: " << mean << endl;

    // Ponowne wczytanie danych, aby móc sortować jeszcze raz
    tab.loadData(amount_of_data);

    //Sortowanie za pomocą bucket sort
    cout << "\nSorting using Bucket Sort:\n";
    start = high_resolution_clock::now();
    bucketSort(tab);
    end = high_resolution_clock::now();
    long long bucket_sort_time = duration_cast<milliseconds>(end - start).count();
    cout << "Time taken: " << formatTime(bucket_sort_time) << endl;

    // Obliczanie mediany i średniej
    movies.clear();
    for (int i = 0; i < tab.getSize(); ++i) {
        movies.push_back(tab.getMovie(i));
    }
    median = calculateMedian(movies);
    mean = calculateMean(movies);
    cout << "Median: " << median << endl;
    cout << "Mean: " << mean << endl;

    tab.clear();
    
    return 0;
}