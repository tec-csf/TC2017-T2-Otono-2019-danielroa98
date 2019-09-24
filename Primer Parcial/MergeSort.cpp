/*
 *
 * Daniel Roa
 * A01021960
 * Fecha de entrega 06/09/2019
 *
 */
 
#include <bits/stdc++.h>
#include <chrono>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <iostream>

using namespace std;
using namespace std::chrono;

void swapping(int &a, int &b) {
   int temp;
   temp = a;
   a = b;
   b = temp;
}
void display(int *array, int size) {
   for(int i = 0; i<size; i++)
      cout << array[i] << " ";
   cout << endl;
}
void merge(int *array, int l, int m, int r) {
   int i, j, k, nl, nr;
   nl = m-l+1; nr = r-m;
   int larr[nl], rarr[nr];
   for(i = 0; i<nl; i++)
      larr[i] = array[l+i];
   for(j = 0; j<nr; j++)
      rarr[j] = array[m+1+j];
   i = 0; j = 0; k = l;
   while(i < nl && j<nr) {
      if(larr[i] <= rarr[j]) {
         array[k] = larr[i];
         i++;
      }else{
         array[k] = rarr[j];
         j++;
      }
      k++;
   }
   while(i<nl) {
      array[k] = larr[i];
      i++; k++;
   }
   while(j<nr) {
      array[k] = rarr[j];
      j++; k++;
   }
}
void mergeSort(int *array, int l, int r) {
   int m;
   if(l < r) {
      int m = l+(r-l)/2;
      mergeSort(array, l, m);
      mergeSort(array, m+1, r);
      merge(array, l, m, r);
   }
}
int main() {

  int sizeA;
	int sizeRand = 1000000;

	cout << "Inserte el tamaño del arreglo" << endl;
	cin >> sizeA;
	cout << "\n";

	int arr[sizeA];

	srand((unsigned) time(0));

	for (int cont = 0; cont < sizeA; cont++) {
		arr[cont] = (rand()%sizeRand)+1;
	}

	int n = sizeof(arr)/sizeof(arr[0]);

	auto start = high_resolution_clock::now();

   mergeSort(arr, 0, n-1);

   auto stop = high_resolution_clock::now();
 	 auto durationSeg = duration_cast<seconds>(stop-start);
 	 auto durationMilli = duration_cast<milliseconds>(stop-start);
 	 auto durationMicro = duration_cast<microseconds>(stop-start);


   //cout << "Array after Sorting: ";
   //display(arr, n);

   cout << "Le tomo " << durationSeg.count() << " segundos\n";
 	 cout << "Le tomo " << durationMilli.count() << " milisegundos\n";
 	 cout << "Le tomo " << durationMicro.count() << " microsegundos\n";

   return 0;
}
