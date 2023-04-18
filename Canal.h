#define MAXIMO_VIDEOS 15
#include "Video.h"
#include <string>

using namespace std;

class Canal {
private:
  string nome;
  Video* videos[MAXIMO_VIDEOS];
  int quantidade = 0;

public:
  int getDuracaoTotal();
  int getTotalDeVisualizacoes();
  bool postar(Video* v);
  void imprimir();
  string getNome();
  void setNome(string nomeNovo);
  int getQuantidade();
  Video** getVideos();
};
