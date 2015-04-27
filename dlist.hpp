/*****************************************************************************/
/* LIBC++ - dlist.hpp                                                        */
/* Classe liste doublement chainée                                           */
/* Copyright (c) 2004 Guillaume Morin - All rights reserved                  */
/*****************************************************************************/

#define DLIST_HPP 1

#ifndef DLIST_ELEMENT_HPP
#include "dlist_element.hpp"
#endif

#ifndef STDLIB_H
#define STDLIB_H 1
#include <stdlib.h>
#endif

#ifndef STRING_H
#define STRING_H 1
#include <string.h>
#endif

class DList
{

protected:

  int Size;
  void (*Destroy)(void *data);
  DList_Element *Head;
  DList_Element *Tail;

  DList(const DList &);
  DList & DList::operator = (const DList &);

public:

  DList( void(*Destroy)(void *data) = *free )
  { init(Destroy); }

  ~DList()
  { destroy(); }

  void init(void(*destroy)(void *data));

  void destroy();

  int insert_next(DList_Element *element,const void *data);

  int insert_previous(DList_Element *element,const void *data);

  int remove(DList_Element *element,void **data);

  int size()
  { return Size; }

  DList_Element *head()
  { return Head; }

  DList_Element *tail()
  { return Tail; }

  int is_head(DList_Element *element)
  { return element==Head ? 1 : 0; }

  int is_tail(DList_Element *element)
  { return element==Tail ? 1 : 0; }

  void *data(DList_Element *element)
  { return element->Data; }

  DList_Element *next(DList_Element *element)
  { return element->Next; }

  DList_Element *previous(DList_Element *element)
  { return element->Previous; }

  void display();

};
