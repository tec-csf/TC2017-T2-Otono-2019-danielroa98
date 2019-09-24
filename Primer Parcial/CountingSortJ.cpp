/*obtained from https://www.tutorialspoint.com/cplusplus-program-to-implement-counting-sort */

#include<algorithm>
#include <bits/stdc++.h>
#include <chrono>
#include<stdio.h>
using namespace std;
using namespace std::chrono;


int getMax(int array[], int size) {
   int max = array[1];
   for(int i = 2; i<=size; i++) {
      if(array[i] > max)
         max = array[i];
   }
   return max; //the max element from the array
}
void countSort(int *array, int size) {
   int output[size+1];
   int max = getMax(array, size);
   int count[max+1];     //create count array (max+1 number of elements)
   for(int i = 0; i<=max; i++)
      count[i] = 0;     //initialize count array to all zero
   for(int i = 1; i <=size; i++)
      count[array[i]]++;     //increase number count in count array.
   for(int i = 1; i<=max; i++)
      count[i] += count[i-1];     //find cumulative frequency
   for(int i = size; i>=1; i--) {
      output[count[array[i]]] = array[i];
      count[array[i]] -= 1; //decrease count for same numbers
   }
   for(int i = 1; i<=size; i++) {
      array[i] = output[i]; //store output array to main array
   }
}
int main() {
	int n=100000;
	int array[n+1];
	int nrand =n*10;

	srand((unsigned)time(0));

	for(int i=0; i<n; i++){
	array[i] = (rand()%nrand)+1;
	}

	auto start = high_resolution_clock::now();
	countSort(array,n);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<milliseconds>(stop - start);
	cout << "La duracion es: "<< duration.count() << " ms, con tamaño: " << n << endl;

}

