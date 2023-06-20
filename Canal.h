#ifndef CANAL_H
#define CANAL_H
#define MAXIMO_VIDEOS 20
#include "Conteudo.h"
#include <string>
#include <vector>

using namespace std;

class Canal {
private:
  string nome;

protected:
  vector<Conteudo*> *conteudos;

public:
  Canal(string nome);
  Canal(string nome, vector<Conteudo*>* conteudos);
  virtual ~Canal();
  int getDuracaoTotal();
  int getTotalDeVisualizacoes();
  virtual void postar(Conteudo *v);
  void imprimir();
  string getNome();
  vector<Conteudo*> *getConteudos();
};

#endif