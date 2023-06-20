#include "UsuarioVerificado.h"
#include "CanalVerificado.h"
#include <iostream>

using namespace std;

UsuarioVerificado::UsuarioVerificado(string nome, string nomeDoCanal): Usuario(nome, new CanalVerificado(nomeDoCanal)) {}

UsuarioVerificado::~UsuarioVerificado() {}