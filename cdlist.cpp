/*****************************************************************************/
/* LIBC++ - cdlist.cpp                                                       */
/* Classe liste doublement chain�e circulaire                                */
/* Copyright (c) 2004 Guillaume Morin - All rights reserved                  */
/*****************************************************************************/

#include "cdlist.hpp"

// Insertion d'un �l�ment apr�s *element
int CDList::insert_next(DList_Element *element,const void *data) 
{ 
  DList_Element *nouv_element;

  // Allocation du nouvel �l�ment
  if ((nouv_element=(DList_Element *)malloc(sizeof(DList_Element))) == NULL)
    // On retourne une erreur si l'allocation �choue
    return -1;

  // On fait pointer Data sur les donn�es
  nouv_element->Data=(void *)data;

  // Est-ce que la liste est vide ?
  if (Size==0)
    {
      // Liste vide, l'�l�ment est le seul
      Head=nouv_element;
      Tail=nouv_element;
      Head->Previous=nouv_element;
      Head->Next=nouv_element;
    }
  // Liste non vide, l'�l�ment doit-il �tre ins�r� en t�te ?
  else if (element==NULL)
    {
      // Liste non vide, �l�ment en t�te
      nouv_element->Previous=Tail;
      nouv_element->Next=Head;
      Head->Previous=nouv_element;
      Tail->Next=nouv_element;
      Head=nouv_element;
    }
  else
    {
      // Liste non vide, �l�ment ailleurs qu'en t�te

      // Insertion � la fin ?
      if (element==Tail)
	// Oui, l'�l�ment devient la queue
	Tail=nouv_element;

      // Insertion du nouvel �l�ment
      nouv_element->Previous=element;
      nouv_element->Next=element->Next;
      element->Next->Previous=nouv_element;
      element->Next=nouv_element;
    }

  // On incr�mente la taille de la liste
  Size++;

  return 0;
}

int CDList::insert_previous(DList_Element *element,const void *data) 
{ 
  DList_Element *nouv_element;

  // Allocation du nouvel �l�ment
  if ((nouv_element=(DList_Element *)malloc(sizeof(DList_Element))) == NULL)
    // On retourne une erreur si l'allocation �choue
    return -1;

  // On fait pointer Data sur les donn�es
  nouv_element->Data=(void *)data;

  // Est-ce que la liste est vide ?
  if (Size==0)
    {
      // Liste vide, l'�l�ment est le seul
      Head=nouv_element;
      Tail=nouv_element;
      Head->Previous=nouv_element;
      Head->Next=nouv_element;
    }
  // Liste non vide, l'�l�ment doit-il �tre ins�r� en queue ?
  else if (element==NULL)
    {
      // Liste non vide, �l�ment en queue
      nouv_element->Previous=Tail;
      nouv_element->Next=Head;
      Head->Previous=nouv_element;
      Tail->Next=nouv_element;
      Tail=nouv_element;
    }
  else
    {
      // Liste non vide, �l�ment ailleurs qu'en queue

      // Insertion en t�te ?
      if (element==Head)
	// Oui, l'�l�ment devient la t�te
	Head=nouv_element;

      // Insertion du nouvel �l�ment
      nouv_element->Previous=element->Previous;
      nouv_element->Next=element;
      element->Previous->Next=nouv_element;
      element->Previous=nouv_element;
    }

  // On incr�mente la taille de la liste
  Size++;

  return 0;
}

// Suppression d'un �l�ment
int CDList::remove(DList_Element *element,void **data) 
{ 
  DList_Element *anc_element;

  // Impossible de supprimer si la liste est vide
  if (Size==0)
    return -1;

  // Si element est NULL, on supprime l' �l�ment de t�te
  if (element==NULL)
    element=Head;

  // *data prend la valeur du pointeur vers les donn�es
  *data=element->Data;

  // N'y a t'il qu'un seul �l�ment ?
  if (element->Next==element)
    {
      // On supprime le dernier �l�ment

      // On fait pointer anc_element sur l'�l�ment � supprimer
      anc_element=element;

      // La liste est vide, donc Head et Tail pointent vers NULL
      Head=Tail=NULL;
    }
  else 
    {
      // Suppression d'un �l�ment

      // On fait pointer anc_element sur l'�l�ment � supprimer
      anc_element=element;

      // On modifie les �l�ments pr�c�dent et suivant
      element->Previous->Next=element->Next;
      element->Next->Previous=element->Previous;

      // Si l'�l�ment est en t�te on change la t�te
      if (element==Head)
	Head=element->Next;

      // Si l'�l�ment est en queue on change la queue
      if (element==Tail)
	Tail=element->Previous;
    }

  // On lib�re la m�moire allou�e � l'�lement
  free(anc_element);

  // On d�cr�mente la taille de la liste
  Size--;

  return 0; 
}














