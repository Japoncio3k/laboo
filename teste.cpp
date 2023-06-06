#include "Canal.h"
#include "Lista.h"
#include "Video.h"
#include "Conteudo.h"
#include <cmath>
#include <iostream>
#include <string>

using namespace std;

void teste() {
  Video* moreLikeU = new Video("More Like You", 338);
  moreLikeU->assistir(102);
  moreLikeU->assistir(68);
  moreLikeU->imprimir();
  moreLikeU->setPorcentagem(0.2);
  moreLikeU->assistir(102);
  moreLikeU->assistir(68);
  moreLikeU->imprimir();
  delete moreLikeU;
}

//* COMENTE O MAIN AO SUBMETER
// int main () {
//   teste ();
//   return 0;
// }