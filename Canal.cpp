#include "Canal.h"
#include "VideoCurto.h"
#include <iostream>

using namespace std;

Canal::Canal(string nome, int maximo): nome (nome), maximo (maximo){
  conteudos = new Conteudo*[maximo];
}

Canal::Canal(string nome, Conteudo** conteudos, int quantidade): nome (nome), conteudos (conteudos), quantidade (quantidade)  {
  this->maximo = quantidade;
}

Canal::~Canal(){
  cout << endl << "Destrutor de canal: " << this->nome << " - " << this->quantidade << " conteudos" << endl;
  for(int i=0; i<this->quantidade; i++){
    delete this->conteudos[i];
  }
  delete this->conteudos;
  cout << "Canal destruido" << endl;
}

int Canal::getDuracaoTotal() {
  int duracao = 0;
  for(int i=0; i<this->quantidade; i++){
    duracao += this->conteudos[i]->getDuracao();
  }
  return duracao;
} 

int Canal::getTotalDeVisualizacoes() {
  int visualizacoes = 0;
  for(int i=0; i<this->quantidade; i++){
    visualizacoes += this->conteudos[i]->getVisualizacoes();
  }
  return visualizacoes;
}

bool Canal::postar(Conteudo* v) {
  VideoCurto* testaVideoCurto = dynamic_cast<VideoCurto*>(v);
  if(testaVideoCurto!=NULL){
    return false;
  }
  bool temIgual = false;
  for(int i = 0; i < this->quantidade; i++){
    if(this->conteudos[i] == v){
      temIgual = true;  
    }
  }
  if(this->quantidade >= this->maximo || v->getDuracao() == 0 || temIgual) {
    return false;
  }
  this->conteudos[quantidade] = v;
  this->quantidade++;
  return true;
}

void Canal::imprimir(){
  cout << endl << "Canal: " << this->nome << " - " << this->getDuracaoTotal() << " minutos totais" << endl;
  cout << "\t" << this->quantidade << " elementos postados" << endl << endl; 
  for(int i=0; i<this->quantidade; i++){
    this->conteudos[i]->imprimir();
  }
}

string Canal::getNome(){
  return this->nome;
}

int Canal::getQuantidade(){
  return this->quantidade;
}

Conteudo** Canal::getConteudos(){
  return this->conteudos;
}