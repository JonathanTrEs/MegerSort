
#include "MergeSortP.h"

MergeSortP::MergeSortP(int n) : Problema::Problema() {
  _n = n;
  _ini = 0;
  _fin = _n - 1;
  _med = (_ini + _fin) / 2;
  _v = new int[_n];
  iniciarVector();
}

MergeSortP::MergeSortP(int n, int* v, int ini, int fin) {
  _n = n;
  _v = v;
  _ini = ini;
  _fin = fin;
  _med = (_ini + _fin) / 2;
}

MergeSortP::~MergeSortP() {
  delete [] _v;
}

void MergeSortP::iniciarVector() {
  cout << "Introduzca " << _n << " elementos del vector" << endl;
  for (int i = 0; i < _n; i++)
    cin >> _v[i];
}

bool MergeSortP::isCasoMinimo() {
  return (_fin <= _ini);
}

pair<Problema*,Problema*> MergeSortP::descomponer() {
  _med = (_ini + _fin) / 2;
  pair<Problema*,Problema*> subProblemas;
  subProblemas.first = new MergeSortP(_n, _v, _ini, _med);
  subProblemas.second = new MergeSortP(_n, _v, _med + 1, _fin);
  return subProblemas;
}

void MergeSortP::solver(Solucion* s) {
  ((MergeSortS*)s)->setValor(_v, _n, _ini, _fin, _med); 
}