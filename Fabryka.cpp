#include "Fabryka.h"

Wezel* FabrykaWezlow::utworzWezel(int wartosc, Wezel* poprzedni, Wezel* nastepny) {
    return new Wezel(wartosc, poprzedni, nastepny);
}