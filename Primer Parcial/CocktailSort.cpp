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

void CocktailSort(int arreglo[], int tamanio)
{
	bool swapped = true;
	int start = 0;
	int end = tamanio - 1;

	while (swapped) {
		swapped = false;

		for (int i = start; i < end; ++i) {
			if (arreglo[i] > arreglo[i + 1]) {
				swap(arreglo[i], arreglo[i + 1]);
				swapped = true;
			}
		}

		if (!swapped)
			break;

		swapped = false;

		--end;

		for (int i = end - 1; i >= start; --i) {
			if (arreglo[i] > arreglo[i + 1]) {
				swap(arreglo[i], arreglo[i + 1]);
				swapped = true;
			}
		}

		++start;
	}
}

void printArray(int arreglo[], int tamanio)
{
	for (int i = 0; i < tamanio; i++)
		printf("%d ", arreglo[i]);
	printf("\n");
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

	CocktailSort(arreglo, tamanio);

	//printf("Sorted array:\n");

	auto stop = high_resolution_clock::now();
	auto durationSeg = duration_cast<seconds>(stop-start);
	auto durationMilli = duration_cast<milliseconds>(stop-start);
	auto durationMicro = duration_cast<microseconds>(stop-start);

	//printArray(arreglo, tamanio);

	cout << "Le tomo " << durationSeg.count() << " segundos\n";
	cout << "Le tomo " << durationMilli.count() << " milisegundos\n";
	cout << "Le tomo " << durationMicro.count() << " microsegundos\n";

	return 0;
}
