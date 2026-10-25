#ifndef ITERATOR_H
#define ITERATOR_H

#include "Wezel.h"

/// <summary>
/// Klasa umożliwiająca iterację po elementach listy powiązanej za pomocą wskaźnika na bieżący węzeł.
/// </summary>

class Iterator {
private:
    Wezel* aktualny; 

public:
    Iterator(Wezel* start);

    bool czyKoniec() const;

    int pobierzWartosc() const;

    void nastepny();

    void poprzedni();

    Wezel* getAktualny() const;
};

#endif