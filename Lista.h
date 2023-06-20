#include "Video.h"
#include <string>
#include <list>

using namespace std;

class Lista : public Conteudo {
protected:
  list<Video*>* videos;

public:
  Lista(string nome);
  ~Lista();
  bool adicionar(Video* v);
  void adicionar (Lista* l); 
  void imprimir();
  list<Video*>* getVideos();
  int getVisualizacoes();
  int getDuracao();
};
