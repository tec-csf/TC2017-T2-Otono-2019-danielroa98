/*
 *
 * Daniel Roa
 * A01021960
 * Fecha de entrega 06/09/2019
 *
 */

#include <algorithm>
#include <bits/stdc++.h>
#include <chrono>
#include <stdio.h>

using namespace std;
using namespace std::chrono;

int getMax(int array[], int size) {
   int max = array[1];
   for(int i = 2; i<=size; i++) {
      if(array[i] > max)
         max = array[i];
   }
   return max;
}

void countSort(int *array, int size) {
   int output[size+1];
   int max = getMax(array, size);
   int count[max+1];
   for(int i = 0; i<=max; i++)
      count[i] = 0;
   for(int i = 1; i <=size; i++)
      count[array[i]]++;
   for(int i = 1; i<=max; i++)
      count[i] += count[i-1];
   for(int i = size; i>=1; i--) {
      output[count[array[i]]] = array[i];
      count[array[i]] -= 1;
   }
   for(int i = 1; i<=size; i++) {
      array[i] = output[i];
   }
}
int main() {

  int n=1000000;
	int array[n+1];
	int nrand =n*10;

	srand((unsigned)time(0));

	for(int i=0; i<n; i++){
	array[i] = (rand()%nrand)+1;
	}

	auto start = high_resolution_clock::now();

	countSort(array,n);

	auto stop = high_resolution_clock::now();

  auto durationMilli = duration_cast<microseconds>(stop - start);

  cout << "Con " << n << " valores le tomo..." << endl;

 	cout << "Le tomo " << durationMilli.count() << " microsegundos\n";
 	//cout << "Le tomo " << durationMicro.count() << " microsegundos\n";

 	return 0;
}
