#ifndef CANAL_H
#define CANAL_H
#define MAXIMO_VIDEOS 20
#include "Conteudo.h"
#include <string>

using namespace std;

class Canal {
private:
  string nome;

protected:
  int maximo;
  Conteudo **conteudos;
  int quantidade = 0;

public:
  Canal(string nome, int maximo);
  Canal(string nome, Conteudo **conteudos, int quantidade);
  ~Canal();
  int getDuracaoTotal();
  int getTotalDeVisualizacoes();
  virtual bool postar(Conteudo *v);
  void imprimir();
  string getNome();
  int getQuantidade();
  Conteudo **getConteudos();
};

#endif