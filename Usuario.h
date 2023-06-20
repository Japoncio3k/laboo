#ifndef USUARIO_H
#define USUARIO_H
#include "string.h"
#include "Canal.h"

using namespace std;

class Usuario {
private:
  string nome;
  Canal* canal;

public:
  Usuario(string nome, string nomeDoCanal);
  Usuario(string nome, Canal* canal);
  virtual ~Usuario();
  virtual Canal* getCanal();
  virtual string getNome();
};
#endif