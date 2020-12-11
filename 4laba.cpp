#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string.h>
#include "testClass.h"
using std::vector;
using namespace std;

template <typename T>
void selectionSort(T* a, int n)  
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
void сocktailSort(T* a, int n)  
{
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
void gnomeSort(T& arr, int n)  
{
	int index = 0;
	while (index < n) {
		if (index == 0) index++;
		else if (arr[index] >= arr[index - 1]) index++;
		else {
			swap(arr[index], arr[index - 1]);
			index--;
		}
	}
	return;
}

template <typename T1, typename T2>
void pigeonholeSort(T1& arr, T2 n)   
{
	
	T2 min = arr[0], max = arr[0];
	for (int i = 1; i < int(n); i++) {
		if (min > arr[i])
			min = arr[i];
		if (max < arr[i])
			max = arr[i];
	}
	T2 range = max - min;  
	range++;

	
	vector <vector<T2>> holes;
	vector <T2> temp;
	temp.clear();

	for (T2 i = 0; i < range; i++) {
		holes.push_back(temp);
	}

	for (int i = 0; i < n; i++) {
		holes[arr[i] - min].push_back(arr[i]);
	}

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
  
}

