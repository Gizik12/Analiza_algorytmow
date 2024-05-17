#include "sortingAlgorithms.h"
#include <stack>
#include <vector>
#include <cmath>

// Merge Sort
void merge(vector<Movie*>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Tworzymy tymczasowe wektory
    vector<Movie*> L(n1), R(n2);

    // Kopiujemy dane do wektorów tymczasowych L[] i R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Scalanie wektorów tymczasowych z powrotem do arr[l..r]
    int i = 0; // Indeks początkowy pierwszego podwektora
    int j = 0; // Indeks początkowy drugiego podwektora
    int k = left; // Indeks początkowy scalonego wektora
    while (i < n1 && j < n2) {
        if (L[i]->getRating() >= R[j]->getRating()) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Kopiowanie pozostałych elementów L[], jeśli są takie
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Kopiowanie pozostałych elementów R[], jeśli są takie
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<Movie*>& arr, int left, int right) {
    if (left < right) {
        // Znajdujemy środek
        int mid = left + (right - left) / 2;

        // Sortujemy pierwszą i drugą połowę
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Scalanie posortowanych połówek
        merge(arr, left, mid, right);
    }
}

// Quick Sort
int medianOfThree(MovieChest& movies, int low, int high) {
    int mid = low + (high - low) / 2;
    
    float ratingLow = movies.getMovie(low)->getRating();
    float ratingMid = movies.getMovie(mid)->getRating();
    float ratingHigh = movies.getMovie(high)->getRating();
    
    // Zwracamy indeks mediany spośród trzech elementów
    if ((ratingLow >= ratingMid && ratingLow <= ratingHigh) || (ratingLow <= ratingMid && ratingLow >= ratingHigh))
        return low;
    else if ((ratingMid >= ratingLow && ratingMid <= ratingHigh) || (ratingMid <= ratingLow && ratingMid >= ratingHigh))
        return mid;
    else
        return high;
}

int partition(MovieChest& movies, int low, int high) {
    // Wybieramy medianę spośród trzech elementów jako pivot
    int pivotIndex = medianOfThree(movies, low, high);
    movies.swapMovies(pivotIndex, high); // Przenosimy pivot na koniec tablicy
    float pivot = movies.getMovie(high)->getRating();

    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (movies.getMovie(j)->getRating() > pivot) {
            i++;
            movies.swapMovies(i, j);
        }
    }

    movies.swapMovies(i + 1, high);
    return i + 1;
}

void quickSort(MovieChest& movies, int low, int high) {
    // Tworzymy stos dla przechowywania granic podziału
    std::stack<std::pair<int, int>> stack;
    stack.push(std::make_pair(low, high));

    while (!stack.empty()) {
        // Pobieramy granice podziału ze stosu
        low = stack.top().first;
        high = stack.top().second;
        stack.pop();

        // Wykonujemy podział
        int pi = partition(movies, low, high);

        // Jeśli lewa część podziału ma więcej niż jeden element, dodajemy jej granice do stosu
        if (pi - 1 > low) {
            stack.push(std::make_pair(low, pi - 1));
        }

        // Jeśli prawa część podziału ma więcej niż jeden element, dodajemy jej granice do stosu
        if (pi + 1 < high) {
            stack.push(std::make_pair(pi + 1, high));
        }
    }
}

// Bucket Sort
void bucketSort(MovieChest& movies) {
    const int bucketSize = 10;
    int n = movies.getSize();

    // Create empty buckets
    vector<vector<Movie*>> buckets(bucketSize);

    // Distribute movies into buckets based on their rating
    for (int i = 0; i < n; i++) {
        int bucketIndex = min(static_cast<int>(movies.getMovie(i)->getRating() * bucketSize), bucketSize - 1);
        buckets[bucketIndex].push_back(movies.getMovie(i));
    }

    // Sort each bucket individually
    for (int i = 0; i < bucketSize; i++) {
        if (!buckets[i].empty()) {
            int bucketSize = buckets[i].size();
            mergeSort(buckets[i], 0, bucketSize - 1);
        }
    }

    // Concatenate all buckets into movies
    int idx = 0;
    for (int i = 0; i < bucketSize; i++) {
        for (Movie* movie : buckets[i]) {
            movies.setMovie(idx++, movie);
        }
    }
}