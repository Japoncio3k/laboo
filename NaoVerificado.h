#include <stdexcept>
#include <string>

using namespace std;

class NaoVerificado: public logic_error {
public:
  NaoVerificado();
};