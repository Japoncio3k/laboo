#include <iostream>
#include <string>
#include <cmath>
#include "Video.h"
#include "Canal.h"

using namespace std;

void teste () {
  //ex 1 aula 3
  Video* video = new Video();
  video->setNome("1 hour of Wii music");
  video->setDuracao(64);
  video->assistir(18);
  video->assistir(2);
  video->assistir(57);
  video->imprimir();
  //ex 2
  video->assistir(61);
  video->assistir(43);
  Video* video3 = new Video();
  video3->setNome("bidoofwave");
  video3->setDuracao(591);
  video3->assistir(303);
  video3->assistir(109);
  video3->assistir(487);
  Canal* canal = new Canal();
  canal->setNome("Nintendo");
  canal->postar(video);
  canal->postar(video3);
  video3->imprimir();
  cout << canal->getDuracaoTotal() << endl << canal->getTotalDeVisualizacoes() << endl;
  //ex 1 aula 4
  canal->imprimir();
  return;
}

//* COMENTE O MAIN AO SUBMETER
int main () {
  teste ();
  return 0;
}

//*/