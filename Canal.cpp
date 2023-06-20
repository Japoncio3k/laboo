#include "Canal.h"
#include "VideoCurto.h"
#include "NaoVerificado.h"
#include <iostream>
#include <algorithm>

using namespace std;

Canal::Canal(string nome): nome (nome){
  conteudos = new vector<Conteudo*>();
}

Canal::Canal(string nome, vector<Conteudo*>*conteudos): nome (nome), conteudos (conteudos) {}

Canal::~Canal(){
  cout << endl << "Destrutor de canal: " << this->nome << " - " << this->conteudos->size() << " conteudos" << endl;
  for(unsigned int i=0; i<this->conteudos->size(); i++){
    delete (*this->conteudos)[i];
  }
  delete this->conteudos;
  cout << "Canal destruido" << endl;
}

int Canal::getDuracaoTotal() {
  int duracao = 0;
  for(unsigned int i=0; i<this->conteudos->size(); i++){
    try{
      duracao += (*this->conteudos)[i]->getDuracao();
    }catch(exception* e) {}
  }
  return duracao;
} 

int Canal::getTotalDeVisualizacoes() {
  int visualizacoes = 0;
  for(unsigned int i=0; i<this->conteudos->size(); i++){
    visualizacoes += (*this->conteudos)[i]->getVisualizacoes();
  }
  return visualizacoes;
}

void Canal::postar(Conteudo* v) {
  VideoCurto* testaVideoCurto = dynamic_cast<VideoCurto*>(v);
  if(testaVideoCurto!=NULL){
    throw new NaoVerificado();
  }

  vector<Conteudo*>::iterator it = find(this->conteudos->begin(),this->conteudos->end(),v);
  if(it!=this->conteudos->end()){
    throw new invalid_argument("conteudo repetido");
  }

  this->conteudos->push_back(v);
}

void Canal::imprimir(){
  cout << endl << "Canal: " << this->nome << " - " << this->getDuracaoTotal() << " minutos totais" << endl;
  cout << "\t" << this->conteudos->size() << " elementos postados" << endl << endl; 
  for(unsigned int i=0; i<this->conteudos->size(); i++){
    (*this->conteudos)[i]->imprimir();
  }
}

string Canal::getNome(){
  return this->nome;
}

vector<Conteudo*>* Canal::getConteudos(){
  return this->conteudos;
}