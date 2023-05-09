#include "Video.h"
#include <iostream>

using namespace std;

Video::Video(string nome, int duracao):Conteudo(nome,duracao) {}

Video::~Video(){
  cout << "Destrutor de video com " << this->visualizacoes << " visualizacoes: " << this->getNome() << endl; 
}

void Video::assistir(int tempo) {
  double porcentagemAssistida = (double) tempo/duracao;
  if(porcentagemAssistida-0.3>=0) {
    this->visualizacoes++;
  }
  return;
}

void Video::imprimir() {
  cout << "Video: " << this->getNome() << " - " << this->duracao << " min - " << this->visualizacoes << " visualizacoes" << endl;
  return;
}