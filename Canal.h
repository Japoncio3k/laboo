#define MAXIMO_VIDEOS 15
#include "Conteudo.h"
#include <string>

using namespace std;

class Canal {
private:
  string nome;
  int maximo;
  Conteudo* *conteudos;
  int quantidade = 0;

public:
  Canal(string nome, int maximo);
  Canal(string nome, Conteudo** conteudos, int quantidade);
  ~Canal();
  int getDuracaoTotal();
  int getTotalDeVisualizacoes();
  bool postar(Conteudo* v);
  void imprimir();
  string getNome();
  int getQuantidade();
  Conteudo** getConteudos();
};
