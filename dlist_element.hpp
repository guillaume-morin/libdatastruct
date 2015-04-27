/*****************************************************************************/
/* LIBC++ - dlist_element.hpp                                                */
/* Classe élément d'une liste doublement chainée                             */
/* Copyright (c) 2004 Guillaume Morin - All rights reserved                  */
/*****************************************************************************/

#define DLIST_ELEMENT_HPP 1

#ifndef IOSTREAM
#define IOSTREAM 1
#include <iostream>
#endif

class DList_Element
{

  void *Data;
  DList_Element *Previous;
  DList_Element *Next;

  DList_Element();
  DList_Element(void* data,DList_Element* next,DList_Element* previous)
  {
    Data=data;Next=next;Previous=previous;
  }
  ~DList_Element();
  DList_Element(const DList_Element &element);
  DList_Element & DList_Element::operator = (const DList_Element &element);

public:

  void display();

  friend class DList;
  friend class CDList;

};
