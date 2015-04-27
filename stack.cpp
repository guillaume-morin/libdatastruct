/*****************************************************************************/
/* LIBC++ - stack.cpp                                                        */
/* Pile                                                                      */
/* Copyright (c) 2004 Guillaume Morin - All rights reserved                  */
/*****************************************************************************/

#include "stack.hpp"

using namespace std;

// push met une donn�e au dessus de la pile
int Stack::push(const void *data)
{
  return insert_next(NULL,data);
}

// push extrait une donn�e de la pile
int Stack::pop(void **data)
{
  return remove_next(NULL,data);
}

// push extrait une donn�e de la pile sans la supprimer
void *Stack::peek()
{ 
  return (Head == NULL) ? NULL : Head->Data;
}

// Affichage sur stdout du contenu de la pile
void Stack::display()
{
  List_Element* element;
  int count=0;

  // On affiche les donn�es g�n�rales de la pile
  cout << "Stack::display - Size " << Size << " | Dest " << (void*)Destroy << " | Head " << (void*)Head << " | Tail " << (void*)Tail << endl;

  // On affiche un � un les �l�ments de la pile
  element=Head;
  while(count<Size)
    {
      cout << "Elmt " << ++count << " | ";
      element->display();
      element=element->Next;
    }
}
