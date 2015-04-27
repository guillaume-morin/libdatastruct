/*****************************************************************************/
/* LIBC++ - clist.cpp                                                        */
/* Classe liste chain�e circulaire                                           */
/* Copyright (c) 2004 Guillaume Morin - All rights reserved                  */
/*****************************************************************************/

#include "clist.hpp"

// Insertion d'un �l�ment apr�s *element
int CList::insert_next(List_Element *element,const void *data) 
{ 
  List_Element *nouv_element;

  // Allocation du nouvel �l�ment
  if ((nouv_element=(List_Element *)malloc(sizeof(List_Element))) == NULL)
    // On retourne une erreur si l'allocation �choue
    return -1;

  // On fait pointer Data sur les donn�es
  nouv_element->Data=(void *)data;

  // La liste est-elle vide ?
  if (Size==0)
    {
      // Liste vide, insertion du nouvel �l�ment pointant vers lui-m�me
      nouv_element->Next=nouv_element;
      Head=nouv_element;
      Tail=nouv_element;
    }
  // Liste non vide, l'�l�ment doit-il �tre ins�r� en t�te ?
  else if (element==NULL)
    {
      // Liste non vide, �l�ment en t�te
      nouv_element->Next=Head;
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

      nouv_element->Next=element->Next;
      element->Next=nouv_element;
    }

  // On incr�mente la taille de la liste
  Size++;

  return 0;
}

// Suppression d'un �l�ment apr�s *element
int CList::remove_next(List_Element *element,void **data) 
{ 
  List_Element *anc_element;

  // Impossible de supprimer si la liste est vide
  if (Size==0)
    return -1;

  // Si element est NULL, on supprime l' �l�ment de t�te
  if (element==NULL)
    element=Tail;

  // *data prend la valeur du pointeur vers les donn�es
  *data=element->Next->Data;

  // N'y a t'il qu'un seul �l�ment ?
  if (element->Next==element)
    {
      // Un seul �l�ment � supprimer

      // On fait pointer anc_element sur l'�l�ment � supprimer
      anc_element=element->Next;

      // La liste est vide, donc Head et Tail pointent vers NULL
      Head=Tail=NULL;
    }
  else
    {
      // Il y a plus d'un �l�ment

      // On fait pointer anc_element sur l'�l�ment � supprimer
      anc_element=element->Next;

      // On pointe element vers le suivant de anc_element
      element->Next=element->Next->Next;

      // Supprime-t-on la queue?
      if (anc_element==Tail)
	// Oui, element devient la queue
	Tail=element;
      else if (anc_element==Head)
	// Non, mais l'ancien �l�ment �tait la t�te 
	// On modifie la t�te
	Head=anc_element->Next;
    }

  // On lib�re la m�moire allou�e � l'�lement
  free(anc_element);

  // On d�cr�mente la taille de la liste
  Size--;

  return 0; 
}
