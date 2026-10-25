#include "Wezel.h"

/// <summary>
/// Konstruktor inicjalizujący obiekt klasy Wezel z podaną wartością oraz wskaźnikami na poprzedni i następny węzeł.
/// </summary>
/// <param name="val">Wartość przechowywana w węźle.</param>
/// <param name="pop">Wskaźnik na poprzedni węzeł.</param>
/// <param name="nast">Wskaźnik na następny węzeł.</param>

Wezel::Wezel(int val, Wezel* pop, Wezel* nast)
    : wartosc(val), poprzedni(pop), nastepny(nast) {}