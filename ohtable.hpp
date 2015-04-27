/*****************************************************************************/
/* LIBC++ - OHTable                                                          */
/* Table de hachage à adressage ouvert                                       */
/* Copyright (c) 2004 Guillaume Morin - All rights reserved                  */
/*****************************************************************************/

#define OHTABLE_HPP 1

#ifndef STRING_H
#define STRING_H 1
#include <string.h>
#endif

#ifndef STDLIB_H
#define STDLIB_H 1
#include <stdlib.h>
#endif

#ifndef STRING_H
#define STRING_H 1
#include <string.h>
#endif

#ifndef IOSTREAM
#define IOSTREAM 1
#include <iostream>
#endif

typedef struct OHTable_Element_ {
  char* Key;
  void* Value;
} OHTable_Element;


class OHTable {

private:

  // Fonctions interdites
  OHTable(const OHTable &);
  OHTable & operator = (const OHTable &);

protected: 

  // Données protégées
  int Capacity;
  int Size;
  OHTable_Element **Table;
  
  // Fonctions protégées
  int init(const int nb_element);
  int destroy();
  int hash(const char *key);
  
public:

  // Fonctions publiques
  int add(char *key,void *value);
  void *get(const char *key);
  void *set(const char *key,const void *value);
  void *rem(const char *key);
  int display();

  bool exists(const char *key)
  {
    return (((void*)get(key))==NULL) ? 0 : 1;
  }

  OHTable(const int nb_element=200)
  {
    init(nb_element);
  }

  ~OHTable()
  {
    destroy();
  }

  int size()
  {
    return Size;
  }

  int capacity()
  {
    return Capacity;
  }

  void *operator [] (const char *key)
  {
    return get(key);
  }

};
