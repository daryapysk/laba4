#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string.h>
#include "testClass.h"
using std::vector;
using namespace std;

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


int main() 
{
  
}

