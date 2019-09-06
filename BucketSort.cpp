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
#include <vector>

using namespace std;
using namespace std::chrono;

static void BucketSort(int* data, int count) {
	int minValue = data[0];
	int maxValue = data[0];

	for (int i = 1; i < count; i++)
	{
		if (data[i] > maxValue)
			maxValue = data[i];
		if (data[i] < minValue)
			minValue = data[i];
	}

	int bucketLength = maxValue - minValue + 1;
	vector<int>* bucket = new vector<int>[bucketLength];

	for (int i = 0; i < bucketLength; i++)
	{
		bucket[i] = vector<int>();
	}

	for (int i = 0; i < count; i++)
	{
		bucket[data[i] - minValue].push_back(data[i]);
	}

	int k = 0;
	for (int i = 0; i < bucketLength; i++)
	{
		int bucketSize = bucket[i].size();

		if (bucketSize > 0)
		{
			for (int j = 0; j < bucketSize; j++)
			{
				data[k] = bucket[i][j];
				k++;
			}
		}
	}
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

	BucketSort(arr, n);

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
