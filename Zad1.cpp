#include <iostream>
#include "Fabryka.h"
#include "ListaDwukierunkowa.h"

int main() {
    FabrykaWezlow fabryka;
    ListaDwukierunkowa lista(&fabryka);

    // 1. Dodawanie na początek
    lista.dodajNaPoczatek(10);
    lista.dodajNaPoczatek(5);

    lista.wyswietl();

    // 2. Dodawanie na koniec
    lista.dodajNaKoniec(30);

    lista.wyswietl();

    // 3. Dodawanie pod wskazany indeks (indeks 2 -> miedzy 10 a 30)
    lista.dodajPodIndeks(2, 20);

    // Oczekiwany wynik: 5 10 20 30
    lista.wyswietl();

    return 0;
}