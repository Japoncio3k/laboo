#include "Video.h"
#include "Lista.h"
#include <iostream>

using namespace std;

Lista::Lista(string nome, int tamanho): Conteudo(nome,0), tamanho (tamanho) {
  this->videos = new Video*[tamanho];
}

Video** Lista::getVideos() {
  return this->videos;
}

int Lista::getVisualizacoes() {
  int visualizacoes = 0;
  for(int i = 0; i < this->quantidade; i++) {
    visualizacoes += this->videos[i]->getVisualizacoes();
  }
  return visualizacoes;
}

int Lista::getQuantidade(){
  return this->quantidade;
}

bool Lista::adicionar(Video* v) {
  bool temIgual = false;
  for(int i = 0; i < this->quantidade; i++){
    if(this->videos[i] == v){
      temIgual = true;  
    }
  }
  if(this->quantidade >= this->tamanho || v->getDuracao() == 0 || temIgual) {
    return false;
  }
  this->videos[this->quantidade] = v;
  this->quantidade++;
  this->duracao += v->getDuracao();
  return true;
}

bool Lista::adicionar(Lista* l){
  Lista* naoRepetidos = new Lista("Nao Repetidos", l->getQuantidade());

  for(int i = 0; i < l->getQuantidade(); i++) {
    bool ehRepetido = false;
    for(int j = 0; j < this->getQuantidade(); j++){
      if(this->videos[j] == l->videos[i]){
        ehRepetido = true;
      }
    }
    if(!ehRepetido){
      naoRepetidos->adicionar(l->videos[i]);
    }
  }

  if(naoRepetidos->getQuantidade() + this->getQuantidade() > this->tamanho){
    return false;
  }
  
  for(int i = 0; i < naoRepetidos->getQuantidade(); i++) {
    this->adicionar(naoRepetidos->videos[i]);
  }

  return true;
}

void Lista::imprimir() {
  cout << "Lista com " << this->quantidade << " videos: " << getNome() << " - " << this->duracao << " minutos" << endl;
  for (int i = 0; i < this->quantidade; i++) {
    cout << "\t" << i+1 << ". " << this->videos[i]->getNome() << endl;
  }
}

Lista::~Lista() {
  cout << "Lista com " << quantidade << " videos destruida" << endl;
  delete this->videos;
}