/*****************************************************************************/
/* LIBC++ - list.cpp                                                         */
/* Classe liste chain�e                                                      */
/* Copyright (c) 2004 Guillaume Morin - All rights reserved                  */
/*****************************************************************************/

#include "list.hpp"

using namespace std;

// Initialisation de la liste
void List::init(void(*destroy)(void *data)=free) 
{
  // Mise z�ro des donn�es 
  Size=0;
  Destroy=destroy;
  Head=NULL;
  Tail=NULL;
}

// Destruction de la liste
void List::destroy()
{
  void *data;
  
  // Suppression des �l�ments un a un
  while (Size > 0)
    {
      if ( (remove_next(NULL,(void **)&data) == 0) && (Destroy!=NULL) )
	Destroy(data);
    }

  // Mise � z�ro des donn�es
  memset(this,0,sizeof(List));
}

// Insertion d'un �l�ment apr�s *element
int List::insert_next(List_Element *element,const void *data) 
{ 
  List_Element *nouv_element;

  // Allocation du nouvel �l�ment
  if ((nouv_element=(List_Element *)malloc(sizeof(List_Element))) == NULL)
    // On retourne une erreur si l'allocation �choue
    return -1;

  // On fait pointer Data sur les donn�es
  nouv_element->Data=(void *)data;

  // Nouvel �lement en t�te ?
  if (element==NULL)
    { 
      // Nouvel �l�ment en t�te
      if (Size==0)  // Liste vide ?
	Tail=nouv_element; // Liste vide, l'�l�ment est � la fin

      // Insertion du nouvel �l�ment
      nouv_element->Next = Head;
      Head=nouv_element;
    }
  else
    {
      // Nouvel �l�ment ailleurs qu'en t�te
      if (element->Next==NULL) // element � la fin ?
	Tail=nouv_element; // Nouel �l�ment � la fin

      // Insertion du nouvel �l�ment
      nouv_element->Next=element->Next;
      element->Next=nouv_element;
    }

  // On incr�mente la taille de la liste
  Size++;

  return 0;
}

// Suppression d'un �l�ment apr�s *element
int List::remove_next(List_Element *element,void **data) 
{ 
  List_Element *anc_element;

  // Impossible de supprimer si la liste est vide
  if (Size==0)
    return -1;

  // L'�l�ment � supprimer est-il en t�te ?
  if (element==NULL)
    {
      // Suppression de l'�l�ment de t�te

      // *data prend la valeur du pointeur vers les donn�es
      *data=Head->Data;

      // On fait pointer anc_element sur la t�te
      anc_element=Head;

      // et la t�te devient l'�l�ment suivant
      Head=Head->Next;

      // Si la liste est maintenant vide, Tail doit pointe vers vers NULL
      if (Size==1)
	Tail=NULL;
    }
  else
    {
      // Suppression d'un �l�ment ailleurs qu'en t�te

      // Erreur si on est � la fin de la liste
      if (element->Next==NULL)
	return -1;

      // *data prend la valeur du pointeur vers les donn�es
      *data=element->Next->Data;

      // On fait pointer anc_element sur l'�l�ment suivant
      anc_element=element->Next;

      // et l'�l�ment suivant de element sur l'�lement suivant anc_element
      element->Next=element->Next->Next;

      // Si l'�lement suivant anc_element est NULL, alors element 
      // devient la queue de la liste
      if (element->Next==NULL)
	Tail=element;
    }

  // On lib�re la m�moire allou�e � l'�lement
  free(anc_element);

  // On d�cr�mente la taille de la liste
  Size--;

  return 0; 
}

// Affichage sur stdout du contenu de la liste
void List::display()
{
  List_Element* element;
  int count=0;

  // On affiche les donn�es g�n�rales de la liste
  cout << "List::display - Size " << Size << " | Dest " << (void*)Destroy << " | Head " << (void*)Head << " | Tail " << (void*)Tail << endl;

  // On affiche un � un les �l�ments de la liste
  element=Head;
  while(count<Size)
    {
      cout << "Elmt " << ++count << " | ";
      element->display();
      element=element->Next;
    }
}
