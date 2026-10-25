#ifndef WEZEL_H
#define WEZEL_H

/// <summary>
/// Reprezentuje węzeł listy dwukierunkowej przechowujący wartość typu int oraz wskaźniki na poprzedni i następny węzeł.
/// </summary>

class Wezel {
public:
    int wartosc;
    Wezel* nastepny;
    Wezel* poprzedni;

    Wezel(int val, Wezel* pop = nullptr, Wezel* nast = nullptr);
};

#endif