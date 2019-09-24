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

int getMax(int arr[], int n)
{
	int mx = arr[0];
	for (int i = 1; i < n; i++)
		if (arr[i] > mx)
			mx = arr[i];
	return mx;
}

void countSort(int arr[], int n, int exp)
{
	int output[n];
	int i, count[10] = {0};

	for (i = 0; i < n; i++)
		count[ (arr[i]/exp)%10 ]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = n - 1; i >= 0; i--)
	{
		output[count[ (arr[i]/exp)%10 ] - 1] = arr[i];
		count[ (arr[i]/exp)%10 ]--;
	}

	for (i = 0; i < n; i++)
		arr[i] = output[i];
}

void radixsort(int arr[], int n)
{

	int m = getMax(arr, n);

	for (int exp = 1; m/exp > 0; exp *= 10)
		countSort(arr, n, exp);
}

void print(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
}

int main()
{
	int sizeA;

	cout << "Inserte el tamaño del arreglo" << endl;
	cin >> sizeA;
	cout << "\n";

	int sizeRand = 1000000;

  int arr[sizeA];

  srand((unsigned) time(0));

  cout << "El tamaño por default del arreglo es de "<< sizeA << "\n";

  for (int cont = 0; cont < sizeA; cont++) {
    arr[cont] = (rand()%sizeRand)+1;
  }

	int n = sizeof(arr)/sizeof(arr[0]);

	auto start = high_resolution_clock::now();

	radixsort(arr, n);

	auto stop = high_resolution_clock::now();
	auto durationSeg = duration_cast<seconds>(stop-start);
	auto durationMilli = duration_cast<milliseconds>(stop-start);
	auto durationMicro = duration_cast<microseconds>(stop-start);

//	print(arr, n);

	cout << "Le tomo " << durationSeg.count() << " segundos\n";
	cout << "Le tomo " << durationMilli.count() << " milisegundos\n";
	cout << "Le tomo " << durationMicro.count() << " microsegundos\n";

	return 0;
}
