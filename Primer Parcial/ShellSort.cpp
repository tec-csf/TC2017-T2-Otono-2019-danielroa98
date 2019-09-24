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
void shellSort(int arr[], int n)
{
	for (int gap = n / 2; gap > 0; gap /= 2) {
		for (int i = gap; i < n; i += 1) {
			int temp = arr[i];

			int j;
			for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
				arr[j] = arr[j - gap];

			arr[j] = temp;
		}
	}
}

void printArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		std::cout << arr[i] << " ";
	std::cout << "\n";
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

	int n = sizeof(arr) / sizeof(arr[0]);

  auto start = high_resolution_clock::now();

	shellSort(arr, n);

  auto stop = high_resolution_clock::now();
	auto durationSeg = duration_cast<seconds>(stop-start);
	auto durationMilli = duration_cast<milliseconds>(stop-start);
	auto durationMicro = duration_cast<microseconds>(stop-start);

	std::cout << "Array after sorting: \n";
	printArray(arr, n);

  cout << "Le tomo " << durationSeg.count() << " segundos\n";
	cout << "Le tomo " << durationMilli.count() << " milisegundos\n";
	cout << "Le tomo " << durationMicro.count() << " microsegundos\n";

	return 0;
}
