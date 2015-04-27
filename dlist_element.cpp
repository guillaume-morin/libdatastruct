/*****************************************************************************/
/* LIBC++ - dlist_element.cpp                                                */
/* Classe élément d'une liste doublement chainée                             */
/* Copyright (c) 2004 Guillaume Morin - All rights reserved                  */
/*****************************************************************************/

#include "dlist_element.hpp"

using namespace std;

// Affichage sur stdout du contenu de l'élément
void DList_Element::display()
{
  cout  << "Prev " << (void*)Previous << " | Addr " << (void*)this << " | Data " << (void*)Data << " | Next " << (void*)Next << endl;
}
