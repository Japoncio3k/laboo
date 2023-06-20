#include <string>
#include "Conteudo.h"

using namespace std;

class PersistenciaConteudo {
private:
  string arquivo;
public:
  PersistenciaConteudo(string arquivo);
  ~PersistenciaConteudo();
  void inserir(Conteudo *c);
  Conteudo** obter(int& quantidade);
};