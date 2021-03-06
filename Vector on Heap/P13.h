#pragma once
#include <utility>
#include <vector>

using namespace std;

typedef int TElem;

typedef bool(*Relation)(TElem p1, TElem p2);

//removes the last k elements from the vector (considering the relation)
//if k is less than or equal to zero, throws an exception
//if k is greater than the size of the array, all elements will be removed
void removeLast(vector<TElem>& elements, Relation r, int k);

void bubble_down(vector <TElem>& mxh, TElem x, int len);
void bubble_up(vector <TElem>& minh, TElem x, int len);