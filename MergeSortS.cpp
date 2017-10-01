
#include "MergeSortS.h"

MergeSortS::MergeSortS() : Solucion::Solucion() {
}

MergeSortS::~MergeSortS() {
  delete [] _v;
}

void MergeSortS::resolver() {
  for (int i = 0; i < _n; i++)
    cout << _v[i] << " ";
  cout << endl;
}

void MergeSortS::mezcla(pair<Solucion*,Solucion*> subSoluciones) {
  _v = (((MergeSortS*)subSoluciones.first))->_v;
  _n = (((MergeSortS*)subSoluciones.first))->_n;
  _ini = (((MergeSortS*)subSoluciones.first))->_ini;
  _med = (((MergeSortS*)subSoluciones.first))->_fin;
  _fin = (((MergeSortS*)subSoluciones.second))->_fin;
  int i = _ini;
  int j = _med + 1;
  int k = _ini;
  int* aux = new int[_n];
  while ((i <= _med) && (j <= _fin)) {
    if (_v[i] < _v[j]) {
      aux[k] = _v[i];
      i++;
    }
    else { 
      aux[k] = _v[j];
      j++;
    }
    k++;
  }
  if (i > _med)
    while (j <= _fin) {
      aux[k] = _v[j];
      j++;
      k++;
    }
  else
    while (i <= _med) { 
      aux[k] = _v[i];
      i++; 
      k++;
    } 
  for (int k = _ini; k <= _fin; k++)
    _v[k] = aux[k] ;
  
}

Solucion* MergeSortS::getInstance() {
  return new MergeSortS();
}

void MergeSortS::setValor(int* v, int n, int ini, int fin, int med) {
  _v = v;
  _n = n;
  _ini = ini;
  _fin = fin;
  _med = med;
}