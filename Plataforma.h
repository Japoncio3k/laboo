#include "Usuario.h"

using namespace std;

class Plataforma {
private:
  Usuario** usuarios;
  int quantidade;

public:
  Plataforma();
  virtual ~Plataforma();
  virtual bool adicionar (Usuario* usuario);
  virtual int getQuantidadeDeUsuarios();
  virtual Usuario** getUsuarios();
  const int maximoDeUsuarios = 20;
};