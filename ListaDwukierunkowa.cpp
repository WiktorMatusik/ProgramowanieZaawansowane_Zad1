#include "ListaDwukierunkowa.h"
#include <iostream>
#include <stdexcept>

ListaDwukierunkowa::ListaDwukierunkowa(Fabryka* fab)
    : poczatek(nullptr), koniec(nullptr), rozmiar(0), fabryka(fab) {}

ListaDwukierunkowa::~ListaDwukierunkowa() {
    Wezel* temp = poczatek;
    while (temp != nullptr) {
        Wezel* nastepny = temp->nastepny;
        delete temp;
        temp = nastepny;
    }
}

void ListaDwukierunkowa::dodajNaPoczatek(int wartosc) {
    Wezel* nowyWezel = fabryka->utworzWezel(wartosc, nullptr, poczatek);
    if (poczatek == nullptr) {
        koniec = nowyWezel;
    }
    else {
        poczatek->poprzedni = nowyWezel;
    }
    poczatek = nowyWezel;
    rozmiar++;
}

void ListaDwukierunkowa::dodajNaKoniec(int wartosc) {
    Wezel* nowyWezel = fabryka->utworzWezel(wartosc, koniec, nullptr);
    if (koniec == nullptr) {
        poczatek = nowyWezel;
    }
    else {
        koniec->nastepny = nowyWezel;
    }
    koniec = nowyWezel;
    rozmiar++;
}

void ListaDwukierunkowa::dodajPodIndeks(int indeks, int wartosc) {
    if (indeks < 0 || indeks > rozmiar) {
        throw std::out_of_range("Indeks poza zakresem listy!");
    }
    if (indeks == 0) {
        dodajNaPoczatek(wartosc);
        return;
    }
    if (indeks == rozmiar) {
        dodajNaKoniec(wartosc);
        return;
    }

    Wezel* temp = poczatek;
    for (int i = 0; i < indeks; ++i) {
        temp = temp->nastepny;
    }

    Wezel* nowyWezel = fabryka->utworzWezel(wartosc, temp->poprzedni, temp);
    temp->poprzedni->nastepny = nowyWezel;
    temp->poprzedni = nowyWezel;
    rozmiar++;
}

int ListaDwukierunkowa::pobierzRozmiar() const {
    return rozmiar;
}

void ListaDwukierunkowa::wyswietl() const {
    Wezel* temp = poczatek;
    std::cout << "Lista: ";
    while (temp != nullptr) {
        std::cout << temp->wartosc << " ";
        temp = temp->nastepny;
    }
    std::cout << std::endl;
}