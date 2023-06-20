#include "Video.h"
#include "Lista.h"
#include <iostream>
#include <algorithm>

using namespace std;

Lista::Lista(string nome): Conteudo(nome,0) {
  this->videos = new list<Video*>();
}

list<Video*>* Lista::getVideos() {
  return this->videos;
}

int Lista::getVisualizacoes() {
  int visualizacoes = 0;
  list<Video*>::iterator i = this->videos->begin();
  while(i != this->videos->end()){
    visualizacoes += (*i)->getVisualizacoes();
    i++;
  }
  return visualizacoes;
}

bool Lista::adicionar(Video* v) {
  list<Video*>::iterator it = find(this->videos->begin(), this->videos->end(), v);
  if(it!=this->videos->end()){
    return false;
  }

  if(v->getDuracao() == 0) {
    return false;
  }
  this->videos->push_back(v);
  this->duracao += v->getDuracao();
  return true;
}

int Lista::getDuracao() {
  if(this->videos->size() == 0) {
    throw new logic_error("lista vazia");
  }
  return this->duracao;
}

void Lista::adicionar(Lista* l){
  list<Video*>::iterator i = l->videos->begin();
  while(i!=l->videos->end()){
    this->adicionar((*i));
    i++;
  }
}

void Lista::imprimir() {
  cout << "Lista com " << this->videos->size() << " videos: " << getNome() << " - " << this->duracao << " minutos" << endl;
  list<Video*>::iterator i = this->videos->begin();
  int cont = 1;
  while(i!=this->videos->end()){
    cout << "\t" << cont << ". " << (*i)->getNome() << endl;
    cont++;
    i++;
  }
}

Lista::~Lista() {
  cout << "Lista com " << this->videos->size() << " videos destruida" << endl;
  delete this->videos;
}