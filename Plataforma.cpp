#include "Plataforma.h"
#include "Usuario.h"
#include <iostream>

using namespace std;

Plataforma::Plataforma() {
  this->usuarios = new Usuario *[this->maximoDeUsuarios];
}

Plataforma::~Plataforma() {
  cout << "Destrutor de Plataforma" << endl;
  for (int i = 0; i < this->quantidade; i++) {
    delete this->usuarios[i];
  }
  delete this->usuarios;
  cout << "Plataforma deletada" << endl;
}

bool Plataforma::adicionar(Usuario *usuario) {
  bool naoTemIgual = true;
  for(int i = 0; i < this->quantidade; i++) {
    if(this->usuarios[i] == usuario) {
      naoTemIgual = false;
    }
  }
  if(naoTemIgual){
    this->usuarios[this->quantidade] = usuario;
    this->quantidade++;
  }
  return naoTemIgual;
}

int Plataforma::getQuantidadeDeUsuarios() {
  return this->quantidade;
}

Usuario** Plataforma::getUsuarios() {
  return this->usuarios;
}