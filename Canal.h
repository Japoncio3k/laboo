#define MAXIMO_VIDEOS 15
#include "Video.h"
#include <string>

using namespace std;

class Canal {
private:
  string nome;
  int maximoDeVideos;
  Video* *videos = new Video*[maximoDeVideos];
  int quantidade = 0;

public:
  Canal(string nome, int maximoDeVideos);
  int getDuracaoTotal();
  int getTotalDeVisualizacoes();
  bool postar(Video* v);
  void imprimir();
  string getNome();
  void setNome(string nomeNovo);
  int getQuantidade();
  Video** getVideos();
};
