#include "Fabryka.h"

/// <summary>
/// Tworzy nowy węzeł z podaną wartością oraz wskaźnikami na poprzedni i następny węzeł.
/// </summary>
/// <param name="wartosc">Wartość przechowywana w nowym węźle.</param>
/// <param name="poprzedni">Wskaźnik na poprzedni węzeł (może być nullptr).</param>
/// <param name="nastepny">Wskaźnik na następny węzeł (może być nullptr).</param>
/// <returns>Wskaźnik do nowo utworzonego węzła.</returns>

Wezel* FabrykaWezlow::utworzWezel(int wartosc, Wezel* poprzedni, Wezel* nastepny) {
    return new Wezel(wartosc, poprzedni, nastepny);
}