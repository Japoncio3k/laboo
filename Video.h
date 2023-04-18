#ifndef VIDEO_H
#define VIDEO_H
#include <string>

using namespace std;

class Video {
private: 
  string nome;
  int duracao;
  int visualizacoes = 0;

public:
  void assistir (int tempo);    
  void imprimir ();
  string getNome();
  int getDuracao();
  void setNome(string nomeNovo);
  void setDuracao(int duracaoNova);
  int getVisualizacoes();
};

#endif