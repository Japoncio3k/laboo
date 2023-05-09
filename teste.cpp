#include <iostream>
#include <string>
#include <cmath>
#include "Video.h"
#include "Canal.h"
#include "Lista.h"
#include "VideoCurto.h"

using namespace std;

void teste () {
  // exercicio 1
  Lista* musicas = new Lista("Musicas", 8);
  Lista* favoritos = new Lista("Favoritos", 8);
  Video* valentineTexas = new Video("Valentine Texas", 42);
  Video* pleaser = new Video("Pleaser", 14);
  Video* everythingStays = new Video("Everything Stays", 71);
  Video* thumbnail = new Video("Thumbnail", 6);
  VideoCurto* nobody = new VideoCurto("Nobody", 4);
  favoritos->adicionar(valentineTexas);
  favoritos->adicionar(thumbnail);
  favoritos->adicionar(nobody);
  musicas->adicionar(valentineTexas);
  musicas->adicionar(pleaser);
  musicas->adicionar(everythingStays);
  favoritos->adicionar(musicas);
  delete musicas;
  favoritos->imprimir();
  delete(favoritos);
  return;
}

//* COMENTE O MAIN AO SUBMETER
// int main () {
//   teste ();
//   return 0;
// }
