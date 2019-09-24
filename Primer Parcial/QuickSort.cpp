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

void swap(int* a, int* b)
{
int t = *a;
*a = *b;
*b = t;
}

int partition (int arreglo[], int low, int high)
{
int pivot = arreglo[high];
int i = (low - 1);

for (int j = low; j <= high- 1; j++)
{
  if (arreglo[j] <= pivot)
  {
    i++;
    swap(&arreglo[i], &arreglo[j]);
  }
}
swap(&arreglo[i + 1], &arreglo[high]);
return (i + 1);
}

void quickSort(int arreglo[], int low, int high)
{
if (low < high)
{
  int pi = partition(arreglo, low, high);

  quickSort(arreglo, low, pi - 1);
  quickSort(arreglo, pi + 1, high);
}
}
void printArray(int arr[], int size)
{
int i;
for (i=0; i < size; i++)
  printf("%d ", arr[i]);
printf("\n");
}

int main()
{

int sizeA;
int sizeRand = 100000;

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

quickSort(arreglo, 0, tamanio-1);

auto stop = high_resolution_clock::now();
auto durationSeg = duration_cast<seconds>(stop-start);
auto durationMilli = duration_cast<milliseconds>(stop-start);
auto durationMicro = duration_cast<microseconds>(stop-start);

//printf("Sorted array: \n");
//printArray(arreglo, tamanio);
//cout << "\n\n";

cout << "Le tomo " << durationSeg.count() << " segundos\n";
cout << "Le tomo " << durationMilli.count() << " milisegundos\n";
cout << "Le tomo " << durationMicro.count() << " microsegundos\n";

return 0;
}
