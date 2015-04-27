/*****************************************************************************/
/* LIBC++ - cdlist.cpp                                                       */
/* Classe liste doublement chainée circulaire                                */
/* Copyright (c) 2004 Guillaume Morin - All rights reserved                  */
/*****************************************************************************/

#include "cdlist.hpp"

// Insertion d'un élément après *element
int CDList::insert_next(DList_Element *element,const void *data) 
{ 
  DList_Element *nouv_element;

  // Allocation du nouvel élément
  if ((nouv_element=(DList_Element *)malloc(sizeof(DList_Element))) == NULL)
    // On retourne une erreur si l'allocation échoue
    return -1;

  // On fait pointer Data sur les données
  nouv_element->Data=(void *)data;

  // Est-ce que la liste est vide ?
  if (Size==0)
    {
      // Liste vide, l'élément est le seul
      Head=nouv_element;
      Tail=nouv_element;
      Head->Previous=nouv_element;
      Head->Next=nouv_element;
    }
  // Liste non vide, l'élément doit-il être inséré en tête ?
  else if (element==NULL)
    {
      // Liste non vide, élément en tête
      nouv_element->Previous=Tail;
      nouv_element->Next=Head;
      Head->Previous=nouv_element;
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

      // Insertion du nouvel élément
      nouv_element->Previous=element;
      nouv_element->Next=element->Next;
      element->Next->Previous=nouv_element;
      element->Next=nouv_element;
    }

  // On incrémente la taille de la liste
  Size++;

  return 0;
}

int CDList::insert_previous(DList_Element *element,const void *data) 
{ 
  DList_Element *nouv_element;

  // Allocation du nouvel élément
  if ((nouv_element=(DList_Element *)malloc(sizeof(DList_Element))) == NULL)
    // On retourne une erreur si l'allocation échoue
    return -1;

  // On fait pointer Data sur les données
  nouv_element->Data=(void *)data;

  // Est-ce que la liste est vide ?
  if (Size==0)
    {
      // Liste vide, l'élément est le seul
      Head=nouv_element;
      Tail=nouv_element;
      Head->Previous=nouv_element;
      Head->Next=nouv_element;
    }
  // Liste non vide, l'élément doit-il être inséré en queue ?
  else if (element==NULL)
    {
      // Liste non vide, élément en queue
      nouv_element->Previous=Tail;
      nouv_element->Next=Head;
      Head->Previous=nouv_element;
      Tail->Next=nouv_element;
      Tail=nouv_element;
    }
  else
    {
      // Liste non vide, élément ailleurs qu'en queue

      // Insertion en tête ?
      if (element==Head)
	// Oui, l'élément devient la tête
	Head=nouv_element;

      // Insertion du nouvel élément
      nouv_element->Previous=element->Previous;
      nouv_element->Next=element;
      element->Previous->Next=nouv_element;
      element->Previous=nouv_element;
    }

  // On incrémente la taille de la liste
  Size++;

  return 0;
}

// Suppression d'un élément
int CDList::remove(DList_Element *element,void **data) 
{ 
  DList_Element *anc_element;

  // Impossible de supprimer si la liste est vide
  if (Size==0)
    return -1;

  // Si element est NULL, on supprime l' élément de tête
  if (element==NULL)
    element=Head;

  // *data prend la valeur du pointeur vers les données
  *data=element->Data;

  // N'y a t'il qu'un seul élément ?
  if (element->Next==element)
    {
      // On supprime le dernier élément

      // On fait pointer anc_element sur l'élément à supprimer
      anc_element=element;

      // La liste est vide, donc Head et Tail pointent vers NULL
      Head=Tail=NULL;
    }
  else 
    {
      // Suppression d'un élément

      // On fait pointer anc_element sur l'élément à supprimer
      anc_element=element;

      // On modifie les éléments précédent et suivant
      element->Previous->Next=element->Next;
      element->Next->Previous=element->Previous;

      // Si l'élément est en tête on change la tête
      if (element==Head)
	Head=element->Next;

      // Si l'élément est en queue on change la queue
      if (element==Tail)
	Tail=element->Previous;
    }

  // On libère la mémoire allouée à l'élement
  free(anc_element);

  // On décrémente la taille de la liste
  Size--;

  return 0; 
}














