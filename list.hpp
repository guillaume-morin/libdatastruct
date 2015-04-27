/*****************************************************************************/
/* LIBC++ - list.hpp                                                         */
/* Classe liste chainée                                                      */
/* Copyright (c) 2004 Guillaume Morin - All rights reserved                  */
/*****************************************************************************/

#define LIST_HPP 1

#ifndef LIST_ELEMENT_HPP
#include "list_element.hpp"
#endif

#ifndef IOSTREAM
#define IOSTREAM 1
#include <iostream>
#endif

#ifndef STDLIB_H
#define STDLIB_H 1
#include <stdlib.h>
#endif

#ifndef STRING_H
#define STRING_H 1
#include <string.h>
#endif

class List
{
private:

  List(const List &);
  List & List::operator = (const List &);

protected:

  int Size;
  void (*Destroy)(void *data);
  List_Element *Head;
  List_Element *Tail;

public:

  List( void(*Destroy)(void *data) = *free )
  { init(Destroy); }
  ~List()
  { destroy(); }

  void init(void(*destroy)(void *data));

  void destroy();

  int insert_next(List_Element *element,const void *data);

  int remove_next(List_Element *element,void **data);

  void display();

  int size()
  { return Size; }

  List_Element *head()
  { return Head; }

  List_Element *tail()
  { return Tail; }

  int is_head(List_Element *element)
  { return element==Head ? 1 : 0; }

  int is_tail(List_Element *element)
  { return element==Tail ? 1 : 0; }

  void *data(List_Element *element)
  { return element->Data; }

  List_Element *next(List_Element *element)
  { return element->Next; }

};
