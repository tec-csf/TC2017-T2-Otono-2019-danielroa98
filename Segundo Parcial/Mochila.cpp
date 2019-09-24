/*
 *  Problema de la mochila
 *  Daniel Roa, A01021960
 *
 *  24 de septiembre del 2019
 */

#include <stdlib.h>
#include <iostream>

using namespace std;

int pruebas(int better, int worse){

  return (better > worse) ? better : worse;

}

int backpack(int resistencia, int importancia[], int peso[], int n){

  if (n == 0 || resistencia == 0) {
    return 0;
  }

  if (importancia[n-1] > resistencia) {
    return backpack(resistencia, importancia, peso, n-1);
  }
  else return pruebas(peso[n-1] + backpack(resistencia - importancia[n-1], importancia, peso, n-1), backpack(resistencia, importancia, peso, n-1));

};

int main() {

  int no;
  int tam;            // tamaño de los arreglos
  int resistencia;   // valor del peso que puede aguantar la mochila

  cout << "Cuál es la resistencia de la mochila?" << '\n';
  cin >> resistencia;
  cout << '\n';

  std::cout << "Cuántos objetos caben en la mochila? (Tamaño del arreglo)" << '\n';
  cin >> tam;
  cout << '\n';

  int importancia[tam];   //valor de importancia de los objetos
  int peso[tam];          //valor del peso de cada objeto

  std::cout << "Escriba un número para crear el arreglo aleatorio" << '\n';
  cin >> no;
  cout << '\n';

  srand((unsigned)time(0));

  for (int i = 0; i < tam; i++) {
    importancia[i] = (rand() % no) + 1;
  }

  for (int i = 0; i < tam; i++) {
    peso[i] = (rand() % no) + 1;
  }

  int n = sizeof(importancia)/sizeof(importancia[0]);

  //  cout << "El valor es " << backpack(resistencia, importancia, peso, n) << "\n" ;

  if(tam > backpack(resistencia, importancia, peso, n)){
    cout << "La mochila se va a romper" << '\n';
  }else{
    cout << "La mochila si va a aguantar" << '\n';
  }

  return 0;
}
