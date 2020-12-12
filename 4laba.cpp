#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string.h>
#include "testClass.h"
using std::vector;
using namespace std;

template <typename T>
void selectionSort(T* a, int n)   //A function for sorting using selection algorithm
{
	for (int i = 0; i < n - 1; i++) {
		T min = a[i];
		// Find the minimum element 
		int k = i;
		for (int j = i + 1; j < n; j++) {
			if (min > a[j]) {
				min = a[j];
				k = j;
			}
		}
		// Swap the found minimum element with the first element
		swap(a[i], a[k]);
	}
}

template <typename T>
void selectionSort(vector<T>& a, int n)
{
	for (int i = 0; i < n - 1; i++) {
		T min = a[i];
		int k = i;
		for (int j = i + 1; j < n; j++) {
			if (min > a[j]) {
				min = a[j];
				k = j;
			}
		}
		swap(a[i], a[k]);
	}
}

template <typename T>
void сocktailSort(T* a, int n)  //A function for sorting using сocktail algorithm
{
	bool swapped = true;
	int start = 0;
	int end = n - 1;

	while (swapped) {
	// reset the swapped flag on entering  loop, because it might be true from a previous iteration.	
		swapped = false;
		// loop from left to right same as the bubble sort
		for (int i = start; i < end; ++i) {
			if (a[i] > a[i + 1]) {
				swap(a[i], a[i + 1]);
				swapped = true;
			}
		}
		// if nothing moved, then array is sorted
		if (!swapped)
			break;
		// otherwise, reset the swapped flag so that it can be used in the next stage
		swapped = false;
		// move the end point back by one, because item at the end is in its rightful spot
		--end;
		// from right to left, doing the same comparison as in the previous stage
		for (int i = end - 1; i >= start; --i) {
			if (a[i] > a[i + 1]) {
				swap(a[i], a[i + 1]);
				swapped = true;
			}
		}
		// increase the starting point, because the last stage would have moved the next smallest number to its rightful spot
		++start;
	}
}

template <typename T>
void сocktailSort(vector<T>& a, int n) {
	bool swapped = true;
	int start = 0;
	int end = n - 1;

	while (swapped) {
		swapped = false;
		for (int i = start; i < end; ++i) {
			if (a[i] > a[i + 1]) {
				swap(a[i], a[i + 1]);
				swapped = true;
			}
		}
		if (!swapped)
			break;
		swapped = false;
		--end;
		for (int i = end - 1; i >= start; --i) {
			if (a[i] > a[i + 1]) {
				swap(a[i], a[i + 1]);
				swapped = true;
			}
		}
		++start;
	}

}

template <typename T>
void gnomeSort(T& arr, int n)  // A function for sorting using gnome algorithm
{
	int index = 0;
	while (index < n) {
		if (index == 0) index++;  //If you are at the start of the array then go to the right element
		else if (arr[index] >= arr[index - 1]) index++;  //If the current array element is larger or equal to the previous array element then go one step right
		else {
			swap(arr[index], arr[index - 1]);  //If the current array element is smaller than the previous array element then swap these two elements and go one step backwards
			index--;
		}
	}
	return;
}

template <typename T1, typename T2>
void pigeonholeSort(T1& arr, T2 n)   //A function for sorting using pigeonhole algorithm 
{
	// Find minimum and maximum values in arr[]
	T2 min = arr[0], max = arr[0];
	for (int i = 1; i < int(n); i++) {
		if (min > arr[i])
			min = arr[i];
		if (max < arr[i])
			max = arr[i];
	}
	T2 range = max - min;  // Find range 
	range++;

	// Create an array of vectors. Size of array range. Each vector represents a hole that is going to contain matching elements.
	vector <vector<T2>> holes;
	vector <T2> temp;
	temp.clear();

	for (T2 i = 0; i < range; i++) {
		holes.push_back(temp);
	}
        // Traverse through input array and put every element in its respective hole ( arr[i] – min)
	for (int i = 0; i < n; i++) {
		holes[arr[i] - min].push_back(arr[i]);
	}
       // Traverse through all holes one by one. For every hole, take its elements and put in array
	int index = 0;
	for (T2 i = 0; i < range; i++) {
		for (int j = 0; j < holes[i].size(); j++) {
			arr[index] = holes[i][j];
			index++;
		}
	}

	return;
}



int main() 
{
  int a[] = { 1, 5, 2, 7, 6, 3, 2, 9, 4, 8 };
	string b[] = { "21", "15", "12", "37", "16", "23", "32", "49", "14", "18" };
	vector<int> vector1 = { 1, 5, 7, 82, 3, 5, 7, 12 };
	testClass arr_obj[] = { {9,6}, {7, 3}, {4, 5}, {6, 3}, {2, 1} };

	сocktailSort(a, 10);
	сocktailSort(b, 10);
	сocktailSort(vector1, 8);
	сocktailSort(arr_obj, 5);

	cout << "Cocktail sort" << endl;

	for (int i = 0; i < 10; i++) {
		cout << a[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < 10; i++) {
		cout << b[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < 8; i++) {
		cout << vector1[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < 5; i++) {
		cout << arr_obj[i].x << " + " << arr_obj[i].y << ", ";
	}
	cout << endl;


	int c[] = { 1, 5, 2, 7, 6, 3, 2, 9, 4, 8 };
	string d[] = { "21", "15", "12", "37", "16", "23", "32", "49", "14", "18" };
	vector<int> vector2 = { 1, 5, 7, 82, 3, 5, 7, 12 };
	testClass arr_obj_2[] = { {9,6}, {7, 3}, {4, 5}, {6, 3}, {2, 1} };

	selectionSort(c, 10);
	selectionSort(d, 10);
	selectionSort(vector2, 8);
	selectionSort(arr_obj_2, 5);

	cout << "Choise sort" << endl;

	for (int i = 0; i < 10; i++) {
		cout << c[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < 10; i++) {
		cout << d[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < 8; i++) {
		cout << vector2[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < 5; i++) {
		cout << arr_obj_2[i].x << " + " << arr_obj_2[i].y << ", ";
	}
	cout << endl;
	
	cout << "-------------------------------------" << endl;

}

