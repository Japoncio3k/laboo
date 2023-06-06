#include "UsuarioVerificado.h"
#include "CanalVerificado.h"
#include <iostream>

using namespace std;

UsuarioVerificado::UsuarioVerificado(string nome, string nomeDoCanal, int maximo): Usuario(nome, new CanalVerificado(nomeDoCanal, maximo)) {}

UsuarioVerificado::~UsuarioVerificado() {}