#include "VideoCurto.h"
#include <iostream>
using namespace std;

VideoCurto::VideoCurto(string nome, int duracao): Video (nome, duracao) {}

VideoCurto::~VideoCurto() {}

void VideoCurto::imprimir() {
  cout << "Video curto: " << this->getNome() << " - " << this->getVisualizacoes() << " visualizacoes" << endl;
}

void VideoCurto::assistir() {
  this->visualizacoes++;
}

void VideoCurto::assistir(int duracao){
  this->visualizacoes++;
}