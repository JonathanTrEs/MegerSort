#ifndef MERGESORTP_H_
#define MERGESORTP_H_

#include "Problema.h"
#include "MergeSortS.h"

class MergeSortP: public Problema {
public:
  MergeSortP(int);
  MergeSortP(int n, int* v, int ini, int fin);
  virtual ~MergeSortP();
  
  bool isCasoMinimo();
  pair<Problema*,Problema*> descomponer();
  void solver(Solucion* s);
  
  void iniciarVector();
  
private:
  int _n;
  int* _v;
  int _ini;
  int _fin;
  int _med;
};

#endif /* MERGESORTP_H_ */