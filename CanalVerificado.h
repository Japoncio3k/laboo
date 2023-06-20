#include "Canal.h"
#include "string.h"

using namespace std;

class CanalVerificado: public Canal {
public:
  CanalVerificado(string nome);
  virtual ~CanalVerificado();    
  void postar(Conteudo *v);
};