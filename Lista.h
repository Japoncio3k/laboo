#include "Video.h"
#include <string>

using namespace std;

class Lista : public Conteudo {
protected:
  Video** videos;
  int quantidade = 0;
  int tamanho;

public:
  Lista(string nome, int tamanho);
  ~Lista();
  bool adicionar(Video* v);
  bool adicionar (Lista* l); 
  void imprimir();
  Video** getVideos();
  int getQuantidade();
  int getVisualizacoes();
};
