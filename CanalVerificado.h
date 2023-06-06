#include "Canal.h"
#include "string.h"

using namespace std;

class CanalVerificado: public Canal {
public:
  CanalVerificado(string nome, int maximo);
  virtual ~CanalVerificado();    
  bool postar(Conteudo *v);
};