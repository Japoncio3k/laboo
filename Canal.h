#define MAXIMO_VIDEOS 15
#include "Video.h"
#include <string>

using namespace std;

class Canal {
private:
  string nome;
  int maximoDeVideos;
  Video* *videos;
  int quantidade = 0;

public:
  Canal(string nome, int maximoDeVideos);
  ~Canal();
  int getDuracaoTotal();
  int getTotalDeVisualizacoes();
  bool postar(Video* v);
  void imprimir();
  string getNome();
  int getQuantidade();
  Video** getVideos();
};
