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
  Video(string nome, int duracao);
  ~Video();
  void assistir (int tempo);    
  void imprimir ();
  string getNome();
  int getDuracao();
  int getVisualizacoes();
};

#endif