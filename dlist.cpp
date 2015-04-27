/*****************************************************************************/
/* LIBC++ - dlist.cpp                                                        */
/* Classe liste doublement chainée                                           */
/* Copyright (c) 2004 Guillaume Morin - All rights reserved                  */
/*****************************************************************************/

#include "dlist.hpp"

using namespace std;

// Initialisation de la liste
void DList::init(void(*destroy)(void *data)=free) 
{
  // Mise zéro des données 
  Size=0;
  Destroy=destroy;
  Head=NULL;
  Tail=NULL;
}

// Destruction de la liste
void DList::destroy() 
{
  void *data;
  
  // Suppression des éléments un a un
  while (Size > 0)
    {
      if ( (remove(Tail,(void **)&data) == 0) && (Destroy!=NULL) )
	Destroy(data);
    }

  // Mise à zéro des données
  memset(this,0,sizeof(DList));
}

// Insertion d'un élément après *element
int DList::insert_next(DList_Element *element,const void *data) 
{ 
  DList_Element *nouv_element;

  // Si element est NULL, on insère l'élément en queue
  if (element==NULL)
    element=Tail;

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
      Head->Previous=NULL;
      Head->Next=NULL;
    }
  else
    {
      // Liste non vide, insertion de l'élément 
      nouv_element->Next=element->Next;
      nouv_element->Previous=element;

      // Est-ce que element est la queue ?
      if (element->Next==NULL)
	// Oui, le nouvel element est le dernier
	Tail=nouv_element;
      else
	// Non, on modifie le pointeur previous de l'élément suivant
	element->Next->Previous=nouv_element;

      // nouv_element devient le suivant d'element
      element->Next=nouv_element;
    }

  // On incrémente la taille de la liste
  Size++;

  return 0;
}

// Insertion d'un élément avant *element
int DList::insert_previous(DList_Element *element,const void *data) 
{ 
  DList_Element *nouv_element;

  // Si element est NULL, on insère l'élément en tête 
  if (element==NULL)
    element=Head;

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
      Head->Previous=NULL;
      Head->Next=NULL;
    }
  else
    {
      // Liste non vide, insertion de l'élément 
      nouv_element->Next=element;
      nouv_element->Previous=element->Previous;
      
      // Est-ce que element est la tête ?
      if (element->Previous==NULL)
	// Oui, le nouvel element est le premier
	Head=nouv_element;
      else
	// Non, on modifie le pointeur next de l'élément précédent
	element->Previous->Next=nouv_element;

      // nouv_element devient le précent d'element
      element->Previous=nouv_element;
    }

  // On incrémente la taille de la liste
  Size++;

  return 0;
}

// Suppression d'un élément
int DList::remove(DList_Element *element,void **data) 
{ 

  // Erreur si la liste est vide
  if (Size==0)
    return -1;

  // Si element est NULL on supprimer l'element de tête
  if (element==NULL)
    element=Head;

  // *data prend la valeur du pointeur vers les données
  *data=element->Data;

  // L'élément à supprimer est-il en tête ?
  if (element==Head)
    {
      // Suppression de l'élément de tête

      // Head pointe vers l'élément suivant
      Head=element->Next;

      // Est-ce qu'il y a un élément suivant ?
      if (Head==NULL)
	// Non, la liste est vide, Tail doit pointer vers NULL
	Tail=NULL;
      else
	// Oui, on fait pointer Previous de l'élément suivant vers NULL
	element->Next->Previous=NULL;
    }
  else
    {
      // Suppression d'un élément ailleurs qu'en tête

      // On modifie l'élément précédent afin qu'il pointe sur le suivant
      element->Previous->Next=element->Next;

      // Y a t'il un élément suivant ?
      if (element->Next==NULL)
	// Non, l'élément précédent devient la queue
	Tail=element->Previous;
      else
	// Oui, on change le pointer previous de l'élément suivant
	element->Next->Previous=element->Previous;	
    }

  // On libère la mémoire allouée à l'élement
  free(element);

  // On décrémente la taille de la liste
  Size--;

  return 0; 
}

// Affichage sur stdout du contenu de la liste
void DList::display()
{
  DList_Element* element;
  int count=0;

  // On affiche les données générales de la liste
  cout << "DList::display - Size " << Size << " | Dest " << (void*)Destroy << " | Head " << (void*)Head << " | Tail " << (void*)Tail << endl;

  // On affiche un à un les éléments de la liste
  element=Head;
  while(count<Size)
    {
      cout << "Elmt " << ++count << " | ";
      element->display();
      element=element->Next;
    }
}
