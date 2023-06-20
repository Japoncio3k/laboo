#include "Canal.h"
#include "Lista.h"
#include "Video.h"
#include "VideoCurto.h"
#include <cmath>
#include <iostream>
#include <string>
#include "CanalVerificado.h"

using namespace std;

void teste() {
  Lista* l1 = new Lista("Freckle season");
  Lista* l2 = new Lista("Singles");
  Video* v1 = new Video("Pretending", 208);
  VideoCurto* v2 = new VideoCurto("Heavy", 3, 14);
  Video* v3 = new Video("Figure it out", 54, 3);
  Video* v4 = new Video("Flatline", 85, 7);
  l2->adicionar(v1);
  l2->adicionar(v4);
  l1->adicionar(v2);
  l1->adicionar(v3);

  l1->adicionar(l2);
  l2->adicionar(l1);

  l1->imprimir();
  l2->imprimir();
  delete l1;
  delete l2;
}

//* COMENTE O MAIN AO SUBMETER
int main () {
  teste ();
  return 0;
}