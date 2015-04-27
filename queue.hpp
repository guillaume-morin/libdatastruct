/*****************************************************************************/
/* LIBC++ - queue.hpp                                                        */
/* File                                                                      */
/* Copyright (c) 2004 Guillaume Morin - All rights reserved                  */
/*****************************************************************************/

#define QUEUE_HPP 1

#ifndef LIST_HPP
#include "list.hpp"
#endif

class Queue : protected List
{
private:
public:
  int enqueue(const void *data);
  int dequeue(void **data);
  void *peek();
  void display();
};
