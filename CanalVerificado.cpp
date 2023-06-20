#include "CanalVerificado.h"
#include "Conteudo.h"
#include <stdexcept>
#include <algorithm>

using namespace std;

CanalVerificado::CanalVerificado(string nome) : Canal(nome){};

CanalVerificado::~CanalVerificado() {}

void CanalVerificado::postar(Conteudo *v) {
  vector<Conteudo*>::iterator it = find(this->conteudos->begin(),this->conteudos->end(),v);
  if(it!=this->conteudos->end()){
    throw new invalid_argument("conteudo repetido");
  }

  this->conteudos->push_back(v);
}