#ifndef VIDEO_H
#define VIDEO_H
#include "Conteudo.h"
#include <string>

using namespace std;

class Video : public Conteudo {
public:
  Video(string nome, int duracao);
  ~Video();
  void assistir (int tempo);    
  void imprimir ();
};

#endif