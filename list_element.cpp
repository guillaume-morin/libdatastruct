/*****************************************************************************/
/* LIBC++ - list_element.cpp                                                 */
/* Classe élément d'une liste chainée                                        */
/* Copyright (c) 2004 Guillaume Morin - All rights reserved                  */
/*****************************************************************************/

#include "list_element.hpp"

using namespace std;

// Affichage sur stdout du contenu de l'élément
void List_Element::display()
{
  cout << "Addr " << (void*)this << " | Data " << (void*)Data << " | Next " << (void*)Next << endl;
}
