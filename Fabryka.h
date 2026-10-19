#ifndef FABRYKA_H
#define FABRYKA_H

#include "Wezel.h"

class Fabryka {
public:
    virtual ~Fabryka() = default;
    virtual Wezel* utworzWezel(int wartosc, Wezel* poprzedni = nullptr, Wezel* nastepny = nullptr) = 0;
};

class FabrykaWezlow : public Fabryka {
public:
    Wezel* utworzWezel(int wartosc, Wezel* poprzedni = nullptr, Wezel* nastepny = nullptr) override;
};

#endif