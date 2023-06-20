#include "PersistenciaConteudo.h"
#include <string>
#include <fstream>
#include "VideoCurto.h"
#include <iostream>

using namespace std;

PersistenciaConteudo::PersistenciaConteudo(string arquivo): arquivo (arquivo) {}

void PersistenciaConteudo::inserir(Conteudo *c) {
  ofstream file;
  file.open(this->arquivo,ios_base::app);
  VideoCurto* testaVideoCurto = dynamic_cast<VideoCurto*>(c);
  if(testaVideoCurto!=NULL){
    file << "s ";
  }else{
    file << "v ";
  }
  file << c->getNome() << " " << c->getDuracao() << " " << c->getVisualizacoes() << endl;
  file.close();
}

Conteudo** PersistenciaConteudo::obter(int& quantidade) {
  Conteudo** conteudos = new Conteudo*[10];
  ifstream file;
  file.open(this->arquivo);
  if(file.fail()){
    file.close();
    throw new invalid_argument("Erro de leitura");
  }

  Video* v;
  string s1, s2;
  int i3, i4;
  file >> s1;
  file >> s2;
  file >> i3;
  file >> i4;
  while(file) {
    if(s1 == "s"){
      v = new VideoCurto(s2,i3,i4);
    }else if(s1 == "v"){
      v = new Video(s2,i3,i4);
    }
    conteudos[quantidade] = v;
    quantidade++;
    file >> s1;
    file >> s2;
    file >> i3;
    file >> i4;
  }
  file.close();
  if(!file.eof()){
    throw new logic_error("Erro de formatação");
  }
  return conteudos;
}