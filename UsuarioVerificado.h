#include "Usuario.h"
#include "string.h"

using namespace std;

class UsuarioVerificado : public Usuario {
public:
  UsuarioVerificado(string nome, string nomeDoCanal, int maximo);
  virtual ~UsuarioVerificado();
};