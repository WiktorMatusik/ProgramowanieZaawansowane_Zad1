#ifndef FABRYKA_H
#define FABRYKA_H

#include "Wezel.h"

/// <summary>
/// Abstrakcyjna klasa fabryki do tworzenia obiektów typu Wezel.
/// </summary>

class Fabryka {
public:
    virtual ~Fabryka() = default;
    virtual Wezel* utworzWezel(int wartosc, Wezel* poprzedni = nullptr, Wezel* nastepny = nullptr) = 0;
};

/// <summary>
/// Tworzy nowy węzeł z podaną wartością oraz opcjonalnymi wskaźnikami do poprzedniego i następnego węzła.
/// </summary>

class FabrykaWezlow : public Fabryka {
public:
    Wezel* utworzWezel(int wartosc, Wezel* poprzedni = nullptr, Wezel* nastepny = nullptr) override;
};

#endif