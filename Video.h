#ifndef VIDEO_H
#define VIDEO_H
#include "Conteudo.h"
#include <string>

using namespace std;

class Video : public Conteudo {
private:
  static double porcentagem;

protected:
  int visualizacoes = 0;

public:
  Video(string nome, int duracao);
  Video(string nome, int duracao, int visualizacoes);
  ~Video();
  virtual void assistir (int tempo);    
  virtual void imprimir ();
  virtual int getVisualizacoes();
  static double getPorcentagem();
  static void setPorcentagem(double valor);
};

#endif