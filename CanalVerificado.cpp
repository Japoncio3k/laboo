#include "CanalVerificado.h"
#include "Conteudo.h"

using namespace std;

CanalVerificado::CanalVerificado(string nome, int maximo)
    : Canal(nome, maximo){};

CanalVerificado::~CanalVerificado() {}

bool CanalVerificado::postar(Conteudo *v) {
  bool temIgual = false;
  for (int i = 0; i < this->quantidade; i++) {
    if (this->conteudos[i] == v) {
      temIgual = true;
    }
  }
  if (this->quantidade >= this->maximo || v->getDuracao() == 0 || temIgual) {
    return false;
  }
  this->conteudos[this->quantidade] = v;
  this->quantidade++;
  return true;
}