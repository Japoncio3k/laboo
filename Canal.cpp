#include "Canal.h"
#include <iostream>

using namespace std;

Canal::Canal(string nome, int maximoDeVideos): nome (nome), maximoDeVideos (maximoDeVideos){}

int Canal::getDuracaoTotal() {
  int duracao = 0;
  for(int i=0; i<this->quantidade; i++){
    duracao += this->videos[i]->getDuracao();
  }
  return duracao;
}

int Canal::getTotalDeVisualizacoes() {
  int visualizacoes = 0;
  for(int i=0; i<this->quantidade; i++){
    visualizacoes += this->videos[i]->getVisualizacoes();
  }
  return visualizacoes;
}

bool Canal::postar(Video* v) {
  bool temIgual = false;
  for(int i = 0; i < this->quantidade; i++){
    if(this->videos[i] == v){
      temIgual = true;
    }
  }
  if(this->quantidade >= this->maximoDeVideos || v->getDuracao() == 0 || temIgual) {
    return false;
  }
  this->videos[quantidade] = v;
  this->quantidade++;
  return true;
}

void Canal::imprimir(){
  cout << "Canal: " << this->nome <<" - " << this->quantidade << " videos - " << this->getTotalDeVisualizacoes() << " visualizacoes totais" << endl;
  int i = 0;
  while(i<this->quantidade){
    cout << endl;
    this->videos[i]->imprimir();
    i++;
  }
}

string Canal::getNome(){
  return this->nome;
}

void Canal::setNome(string nomeNovo){
  this->nome = nomeNovo;
}

int Canal::getQuantidade(){
  return this->quantidade;
}

Video** Canal::getVideos(){
  return this->videos;
}