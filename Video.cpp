#include "Video.h"
#include <iostream>

using namespace std;

Video::Video(string nome, int duracao) : Conteudo(nome, duracao) {
  if(duracao<=0){
    throw new invalid_argument("duracao invalida");
  }
}

Video::Video(string nome, int duracao, int visualizacoes) : Conteudo(nome, duracao) {
  if(duracao<=0){
    throw new invalid_argument("duracao invalida");
  }
  if(visualizacoes<0){
    throw new invalid_argument("visualizacao invalida");
  }else{
    this->visualizacoes = visualizacoes;
  }
}

double Video::porcentagem = 0.3;

Video::~Video() {
  cout << "Destrutor de video com " << this->visualizacoes
       << " visualizacoes: " << this->getNome() << endl;
}

void Video::assistir(int tempo) {
  double porcentagemAssistida = (double)tempo / duracao;
  if (porcentagemAssistida - this->getPorcentagem() >= 0) {
    this->visualizacoes++;
  }
  return;
}

void Video::imprimir() {
  cout << "Video: " << this->getNome() << " - " << this->duracao << " min - "
       << this->visualizacoes << " visualizacoes" << endl;
  return;
}

double Video::getPorcentagem() {
  return Video::porcentagem;
}

void Video::setPorcentagem(double valor) {
  Video::porcentagem = valor;
}

int Video::getVisualizacoes() { 
  return this->visualizacoes; 
}