/*****************************************************************************/
/* LIBC++ - clist.hpp                                                        */
/* Classe liste chainée circulaire                                           */
/* Copyright (c) 2004 Guillaume Morin - All rights reserved                  */
/*****************************************************************************/

#define CLIST_HPP 1

#ifndef LIST_HPP
#include "list.hpp"
#endif

class CList : public List
{
private:
public:
  int insert_next(List_Element *element,const void *data);
  int remove_next(List_Element *element,void **data);
};
