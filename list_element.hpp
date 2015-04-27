/*****************************************************************************/
/* LIBC++ - list_element.hpp                                                 */
/* Classe élément d'une liste chainée                                        */
/* Copyright (c) 2004 Guillaume Morin - All rights reserved                  */
/*****************************************************************************/

#define LIST_ELEMENT_HPP 1

#ifndef IOSTREAM
#define IOSTREAM 1
#include <iostream>
#endif

class List_Element
{
private:

  void *Data;
  List_Element *Next;

  List_Element();
  List_Element(void* data,List_Element* next)
  {
    Data=data;Next=next;
  }
  ~List_Element();
  List_Element(const List_Element &element);
  List_Element & List_Element::operator = (const List_Element &element);

public:

  void display();
  void* data()
  { return Data; }
  List_Element* next()
  { return Next; }

  friend class List;
  friend class CList;
  friend class Stack;
  friend class Queue;

};
