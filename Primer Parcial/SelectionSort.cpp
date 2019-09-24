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

 void swap(int *xp, int *yp)
 {
 	int temp = *xp;
 	*xp = *yp;
 	*yp = temp;
 }

 void selectionSort(int arr[], int n)
 {
 	int i, j, min_idx;

 	for (i = 0; i < n-1; i++)
 	{
 		min_idx = i;
 		for (j = i+1; j < n; j++)
 		if (arr[j] < arr[min_idx])
 			min_idx = j;

 		swap(&arr[min_idx], &arr[i]);
 	}
 }
 void printArray(int arr[], int size)
 {
 	int i;
 	for (i=0; i < size; i++)
 		cout << arr[i] << " ";
 	cout << endl;
 }
 int main()
 {

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

 	selectionSort(arr, n);

  auto stop = high_resolution_clock::now();
	auto durationSeg = duration_cast<seconds>(stop-start);
	auto durationMilli = duration_cast<milliseconds>(stop-start);
	auto durationMicro = duration_cast<microseconds>(stop-start);

 	//cout << "Sorted array: \n";
 	//printArray(arr, n);

  cout << "Le tomo " << durationSeg.count() << " segundos\n";
	cout << "Le tomo " << durationMilli.count() << " milisegundos\n";
	cout << "Le tomo " << durationMicro.count() << " microsegundos\n";

 	return 0;
 }
