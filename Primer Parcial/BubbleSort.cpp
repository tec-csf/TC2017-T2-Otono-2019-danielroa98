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

void bubbleSort(int arreglo[], int tamanio)
{
	int i, j;
	for (i = 0; i < tamanio-1; i++)

	for (j = 0; j < tamanio-i-1; j++)
		if (arreglo[j] > arreglo[j+1])
			swap(&arreglo[j], &arreglo[j+1]);
}

void printArray(int arreglo[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << arreglo[i] << " ";
	cout << endl;
}

int main()
{
	int sizeA;
	int sizeRand = 1000000;

	cout << "Inserte el tamaño del arreglo" << endl;
	cin >> sizeA;
	cout << "\n";

	int arreglo[sizeA];

	srand((unsigned) time(0));

	for (int cont = 0; cont < sizeA; cont++) {
		arreglo[cont] = (rand()%sizeRand)+1;
	}

	int tamanio = sizeof(arreglo)/sizeof(arreglo[0]);

	auto start = high_resolution_clock::now();

	bubbleSort(arreglo, tamanio);
	cout<<"Sorted array: \n";

	auto stop = high_resolution_clock::now();
	auto durationSeg = duration_cast<seconds>(stop-start);
	auto durationMilli = duration_cast<milliseconds>(stop-start);
	auto durationMicro = duration_cast<microseconds>(stop-start);

	printArray(arreglo, tamanio);

	cout << "Le tomo " << durationSeg.count() << " segundos\n";
	cout << "Le tomo " << durationMilli.count() << " milisegundos\n";
	cout << "Le tomo " << durationMicro.count() << " microsegundos\n";

	return 0;
}
