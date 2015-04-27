/*****************************************************************************/
/* LIBC++ - queue.cpp                                                        */
/* File                                                                      */
/* Copyright (c) 2004 Guillaume Morin - All rights reserved                  */
/*****************************************************************************/

#include "queue.hpp"

using namespace std;

// enqueue met ins�re une donn�e en queue de file
int Queue::enqueue(const void *data)
{
  return insert_next(Tail,data);
}

// enqueue r�cup�re une donn�e en t�te de file
int Queue::dequeue(void **data)
{
  return remove_next(NULL,data);
}

// peek r�cup�re une donn�e en t�te de file sans la retirer
void *Queue::peek()
{ 
  return (Head == NULL) ? NULL : Head->Data;
}

// Affichage sur stdout du contenu de la file
void Queue::display()
{
  List_Element* element;
  int count=0;

  // On affiche les donn�es g�n�rales de la file
  cout << "Queue::display - Size " << Size << " | Dest " << (void*)Destroy << " | Head " << (void*)Head << " | Tail " << (void*)Tail << endl;

  // On affiche un � un les �l�ments de la file
  element=Head;
  while(count<Size)
    {
      cout << "Elmt " << ++count << " | ";
      element->display();
      element=element->Next;
    }
}
