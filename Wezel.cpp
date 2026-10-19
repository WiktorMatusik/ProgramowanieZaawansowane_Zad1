#include "Wezel.h"

Wezel::Wezel(int val, Wezel* pop, Wezel* nast)
    : wartosc(val), poprzedni(pop), nastepny(nast) {}