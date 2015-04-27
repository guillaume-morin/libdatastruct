/*****************************************************************************/
/* LIBC++ - cdlist.hpp                                                       */
/* Classe liste doublement chainée circulaire                                */
/* Copyright (c) 2004 Guillaume Morin - All rights reserved                  */
/*****************************************************************************/

#define CDLIST_HPP 1

#ifndef DLIST_HPP
#include "dlist.hpp"
#endif

class CDList : public DList
{
private:
public:
  int insert_previous(DList_Element *element,const void *data);
  int insert_next(DList_Element *element,const void *data);
  int remove(DList_Element *element,void **data);
};
