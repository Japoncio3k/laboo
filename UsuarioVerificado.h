#include "Usuario.h"
#include "string.h"

using namespace std;

class UsuarioVerificado : public Usuario {
public:
  UsuarioVerificado(string nome, string nomeDoCanal);
  virtual ~UsuarioVerificado();
};