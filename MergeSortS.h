#ifndef MERGESORTS_H_
#define MERGESORTS_H_

#include "Solucion.h"

class MergeSortS: public Solucion {
public:
  MergeSortS();
  virtual ~MergeSortS();

  void resolver();
  void mezcla(pair<Solucion*,Solucion*>);
  Solucion* getInstance();

  void setValor(int*, int, int, int, int);

private:
  int _n;  
  int* _v;
  int _ini;
  int _fin;
  int _med;
};

#endif /* MERGESORTS_H_ */