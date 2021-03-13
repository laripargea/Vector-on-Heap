#include "P13.h"

void removeLast(vector<TElem>& elements, Relation r, int k)
//daca k <= 0 arunca exceptie
//daca k > size elements stergem toate elementele
//daca relatia este falsa (1>2) construim minheap altfel maxheap, si stergem ultimele k elemente
//best theta(1), worst theta(n^2), average theta(n) -> O(n^2)
{
    TElem a = 1; //theta(1)
    TElem b = 2;
    if (k <= 0) //theta(1)
    {
        exception e;
        throw e;
    }
    else if (k > elements.size()) //theta(n)
        elements.clear();
    else
    {
        if (r(a, b) == false)
        {
            for (int i = elements.size() / 4 - 1; i >= 0; i--) //pana la primul nod care nu e frunza
                bubble_up(elements, i, elements.size());
            for (int i = elements.size() - 1; i >= elements.size() / 2; i--) //O(n^2)
            {
                TElem aux = elements[0]; //verificam pana la jumatate, mutam radacina
                elements[0] = elements[i];
                elements[i] = aux;
                bubble_up(elements, 0, i); //pe heap-urile mici
            }
        }
        else
        {
            for (int i = elements.size() / 4 - 1; i >= 0; i--)
                bubble_down(elements, i, elements.size());
            for (int i = elements.size() - 1; i >= elements.size() / 2; i--)
            {
                TElem aux = elements[0];
                elements[0] = elements[i];
                elements[i] = aux;
                bubble_down(elements, 0, i);
            }
        }
        int len = elements.size();
        for (int i = len - 1; i > len - 1 - k; i--)
            elements.erase(elements.begin() + i);
    }
}

void bubble_down(vector <TElem>& mxh, TElem x, int len)
//pt maxheap aranjam recursiv ordinea tinand cont ca are 4 copii, cautam max
//best theta(1), worst theta(n), average theta(n) -> O(n)
{
    TElem mx = x; //theta(1)
    TElem unu = 4 * x + 1;
    TElem doi = 4 * x + 2;
    TElem trei = 4 * x + 3;
    TElem patru = 4 * x + 4;
    if (unu < len && mxh[unu] > mxh[mx]) //theta(1)
        mx = unu;
    if (doi < len && mxh[doi] > mxh[mx])
        mx = doi;
    if (trei < len && mxh[trei] > mxh[mx])
        mx = trei;
    if (patru < len && mxh[patru] > mxh[mx])
        mx = patru;
    if (mx != x)
    {
        TElem aux = mxh[x]; //interschimbam
        mxh[x] = mxh[mx];
        mxh[mx] = aux;
        bubble_down(mxh, mx, len);
    }
}

void bubble_up(vector <TElem>& minh, TElem x, int len)
//pt minheap aranjam recursiv ordinea, cautam min
//O(n)
{
    TElem mi = x;
    TElem unu = 4 * x + 1;
    TElem doi = 4 * x + 2;
    TElem trei = 4 * x + 3;
    TElem patru = 4 * x + 4;
    if (unu < len && minh[unu] < minh[mi])
        mi = unu;
    if (doi < len && minh[doi] < minh[mi])
        mi = doi;
    if (trei < len && minh[trei] < minh[mi])
        mi = trei;
    if (patru < len && minh[patru] < minh[mi])
        mi = patru;
    if (mi != x)
    {
        TElem aux = minh[x];
        minh[x] = minh[mi];
        minh[mi] = aux;
        bubble_up(minh, mi, len);
    }
}