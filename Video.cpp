#include "Video.h"
#include <iostream>

using namespace std;

Video::Video(string nome, int duracao): nome (nome), duracao (duracao){}

Video::~Video(){
  cout << "Destrutor de video com " << this->visualizacoes << " visualizacoes: " << this->nome << endl; 
}

void Video::assistir(int tempo) {
  double porcentagemAssistida = (double) tempo/duracao;
  if(porcentagemAssistida-0.3>=0) {
    this->visualizacoes++;
  }
  return;
}

void Video::imprimir() {
  cout << "Video: " << this->nome << " - " << this->duracao << " min - " << this->visualizacoes << " visualizacoes" << endl;
  return;
}

string Video::getNome(){
  return this->nome;
}

int Video::getDuracao(){
  return this->duracao;
}

int Video::getVisualizacoes(){
  return this->visualizacoes;
}