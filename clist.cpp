/*****************************************************************************/
/* LIBC++ - clist.cpp                                                        */
/* Classe liste chainée circulaire                                           */
/* Copyright (c) 2004 Guillaume Morin - All rights reserved                  */
/*****************************************************************************/

#include "clist.hpp"

// Insertion d'un élément après *element
int CList::insert_next(List_Element *element,const void *data) 
{ 
  List_Element *nouv_element;

  // Allocation du nouvel élément
  if ((nouv_element=(List_Element *)malloc(sizeof(List_Element))) == NULL)
    // On retourne une erreur si l'allocation échoue
    return -1;

  // On fait pointer Data sur les données
  nouv_element->Data=(void *)data;

  // La liste est-elle vide ?
  if (Size==0)
    {
      // Liste vide, insertion du nouvel élément pointant vers lui-même
      nouv_element->Next=nouv_element;
      Head=nouv_element;
      Tail=nouv_element;
    }
  // Liste non vide, l'élément doit-il être inséré en tête ?
  else if (element==NULL)
    {
      // Liste non vide, élément en tête
      nouv_element->Next=Head;
      Tail->Next=nouv_element;
      Head=nouv_element;
    }
  else
    {
      // Liste non vide, élément ailleurs qu'en tête

      // Insertion à la fin ?
      if (element==Tail)
	// Oui, l'élément devient la queue
	Tail=nouv_element;

      nouv_element->Next=element->Next;
      element->Next=nouv_element;
    }

  // On incrémente la taille de la liste
  Size++;

  return 0;
}

// Suppression d'un élément après *element
int CList::remove_next(List_Element *element,void **data) 
{ 
  List_Element *anc_element;

  // Impossible de supprimer si la liste est vide
  if (Size==0)
    return -1;

  // Si element est NULL, on supprime l' élément de tête
  if (element==NULL)
    element=Tail;

  // *data prend la valeur du pointeur vers les données
  *data=element->Next->Data;

  // N'y a t'il qu'un seul élément ?
  if (element->Next==element)
    {
      // Un seul élément à supprimer

      // On fait pointer anc_element sur l'élément à supprimer
      anc_element=element->Next;

      // La liste est vide, donc Head et Tail pointent vers NULL
      Head=Tail=NULL;
    }
  else
    {
      // Il y a plus d'un élément

      // On fait pointer anc_element sur l'élément à supprimer
      anc_element=element->Next;

      // On pointe element vers le suivant de anc_element
      element->Next=element->Next->Next;

      // Supprime-t-on la queue?
      if (anc_element==Tail)
	// Oui, element devient la queue
	Tail=element;
      else if (anc_element==Head)
	// Non, mais l'ancien élément était la tête 
	// On modifie la tête
	Head=anc_element->Next;
    }

  // On libère la mémoire allouée à l'élement
  free(anc_element);

  // On décrémente la taille de la liste
  Size--;

  return 0; 
}
