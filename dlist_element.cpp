/*****************************************************************************/
/* LIBC++ - dlist_element.cpp                                                */
/* Classe �l�ment d'une liste doublement chain�e                             */
/* Copyright (c) 2004 Guillaume Morin - All rights reserved                  */
/*****************************************************************************/

#include "dlist_element.hpp"

using namespace std;

// Affichage sur stdout du contenu de l'�l�ment
void DList_Element::display()
{
  cout  << "Prev " << (void*)Previous << " | Addr " << (void*)this << " | Data " << (void*)Data << " | Next " << (void*)Next << endl;
}
