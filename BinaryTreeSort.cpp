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
#include<algorithm>

using namespace std;
using namespace std::chrono;

struct Node
{
	int key;
	struct Node *left, *right;
};

struct Node *newNode(int item)
{
	struct Node *temp = new Node;
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

void storeSorted(Node *root, int arr[], int &i)
{
	if (root != NULL)
	{
		storeSorted(root->left, arr, i);
		arr[i++] = root->key;
		storeSorted(root->right, arr, i);
	}
}

Node* insert(Node* node, int key)
{
	if (node == NULL) return newNode(key);

	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);

	return node;
}

void treeSort(int arreglo[], int tamanio)
{
	struct Node *root = NULL;

	root = insert(root, arreglo[0]);
	for (int i=1; i<tamanio; i++)
		insert(root, arreglo[i]);

	int i = 0;
	storeSorted(root, arreglo, i);
}

int main()
{

  int sizeA;

	cout << "Inserte el tamaño del arreglo" << endl;
	cin >> sizeA;
	cout << "\n";

	int sizeRand = 1000000;

  int arreglo[sizeA];

  srand((unsigned) time(0));

  cout << "El tamaño por default del arreglo es de "<< sizeA << "\n";

  for (int cont = 0; cont < sizeA; cont++) {
    arreglo[cont] = (rand()%sizeRand)+1;
  }

  int tamanio = sizeof(arreglo)/sizeof(arreglo[0]);

	auto start = high_resolution_clock::now();

	treeSort(arreglo, tamanio);

	auto stop = high_resolution_clock::now();
	auto durationSeg = duration_cast<seconds>(stop-start);
	auto durationMilli = duration_cast<milliseconds>(stop-start);
	auto durationMicro = duration_cast<microseconds>(stop-start);

	/*cout << "\n\nLos valores del arreglo ordenados son los siguientes:" << endl;
	for (int i = 0; i < tamanio; i++)
	{
		cout << arreglo[i] << " ";
	}
	cout << "\n\n";*/

	cout << "Le tomo " << durationSeg.count() << " segundos\n";
	cout << "Le tomo " << durationMilli.count() << " milisegundos\n";
	cout << "Le tomo " << durationMicro.count() << " microsegundos\n";

	return 0;
}
