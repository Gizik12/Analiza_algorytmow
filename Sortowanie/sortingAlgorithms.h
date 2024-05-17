#include "movieChest.h"
#ifndef _SORTINGALGORITHMS_H_
#define _SORTINGALGORITHMS_H_

// Funkcja sortująca przez scalanie
void mergeSort(vector<Movie*>& arr, int left, int right);

// Funkcja pomocnicza sortowania przez scalanie
void merge(vector<Movie*>& arr, int left, int mid, int right);

// Funkcja pomocnicza quicksort
int medianOfThree(MovieChest& movies, int low, int high);
int partition(MovieChest& movies, int low, int high);

// Funkcja sortująca quicksort
void quickSort(MovieChest &movies, int low, int high);

// Funkcja sortująca kubełkowo
void bucketSort(MovieChest &movies);
#endif
