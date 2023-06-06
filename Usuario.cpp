#include "Usuario.h"
#include <iostream>

using namespace std;

Usuario::Usuario(string nome, string nomeDoCanal, int maximo) : nome(nome) {
  this->canal = new Canal(nomeDoCanal, maximo);
}

Usuario::Usuario(string nome, Canal* canal) : nome(nome), canal (canal) {}

Usuario::~Usuario() {
  cout << "Destruidor de Usuario: " << this->nome << endl;
  delete this->canal;
}

Canal* Usuario::getCanal() {
  return this->canal;
}

string Usuario::getNome() {
  return this->nome;
}