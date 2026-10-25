#include "Iterator.h"
#include <stdexcept>

using namespace std;

Iterator::Iterator(Wezel* start) : aktualny(start) {}
/// <summary>
/// Sprawdza, czy iterator osiągnął koniec kolekcji.
/// </summary>
/// <returns>Zwraca true, jeśli iterator wskazuje na koniec (nullptr), w przeciwnym razie false.</returns>
bool Iterator::czyKoniec() const {
    return aktualny == nullptr;
}
/// <summary>
/// Zwraca wartość wskazywaną przez iterator.
/// </summary>
/// <returns>Wartość elementu, na który wskazuje iterator. Rzuca wyjątek std::out_of_range, jeśli iterator wskazuje na nullptr.</returns>
int Iterator::pobierzWartosc() const {
    if (aktualny == nullptr) {
        throw out_of_range("Iterator wskazuje na nullptr!");
    }
    return aktualny->wartosc;
}
/// <summary>
/// Przesuwa iterator na następny element w kolekcji, jeśli istnieje.
/// </summary>
void Iterator::nastepny() {
    if (aktualny != nullptr) {
        aktualny = aktualny->nastepny;
    }
}
/// <summary>
/// Przesuwa iterator na poprzedni element w kolekcji, jeśli to możliwe.
/// </summary>
void Iterator::poprzedni() {
    if (aktualny != nullptr) {
        aktualny = aktualny->poprzedni;
    }
}

/// <summary>
/// Zwraca wskaźnik do aktualnego węzła iteratora.
/// </summary>
/// <returns>Wskaźnik do aktualnego węzła (Wezel*) lub nullptr, jeśli iterator nie wskazuje na żaden węzeł.</returns>

Wezel* Iterator::getAktualny() const {
    return aktualny;
}