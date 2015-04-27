/*****************************************************************************/
/* LIBC++ - stack.hpp                                                        */
/* Pile                                                                      */
/* Copyright (c) 2004 Guillaume Morin - All rights reserved                  */
/*****************************************************************************/

#define STACK_HPP 1

#ifndef LIST_HPP
#include "list.hpp"
#endif

class Stack : protected List
{
private:
public:
  int push(const void *data);
  int pop(void **data);
  void *peek();
  void display();
};
