/*****************************************************************************/
/* LIBC++ - dlist.cpp                                                        */
/* Classe liste doublement chain�e                                           */
/* Copyright (c) 2004 Guillaume Morin - All rights reserved                  */
/*****************************************************************************/

#include "dlist.hpp"

using namespace std;

// Initialisation de la liste
void DList::init(void(*destroy)(void *data)=free) 
{
  // Mise z�ro des donn�es 
  Size=0;
  Destroy=destroy;
  Head=NULL;
  Tail=NULL;
}

// Destruction de la liste
void DList::destroy() 
{
  void *data;
  
  // Suppression des �l�ments un a un
  while (Size > 0)
    {
      if ( (remove(Tail,(void **)&data) == 0) && (Destroy!=NULL) )
	Destroy(data);
    }

  // Mise � z�ro des donn�es
  memset(this,0,sizeof(DList));
}

// Insertion d'un �l�ment apr�s *element
int DList::insert_next(DList_Element *element,const void *data) 
{ 
  DList_Element *nouv_element;

  // Si element est NULL, on ins�re l'�l�ment en queue
  if (element==NULL)
    element=Tail;

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
      Head->Previous=NULL;
      Head->Next=NULL;
    }
  else
    {
      // Liste non vide, insertion de l'�l�ment 
      nouv_element->Next=element->Next;
      nouv_element->Previous=element;

      // Est-ce que element est la queue ?
      if (element->Next==NULL)
	// Oui, le nouvel element est le dernier
	Tail=nouv_element;
      else
	// Non, on modifie le pointeur previous de l'�l�ment suivant
	element->Next->Previous=nouv_element;

      // nouv_element devient le suivant d'element
      element->Next=nouv_element;
    }

  // On incr�mente la taille de la liste
  Size++;

  return 0;
}

// Insertion d'un �l�ment avant *element
int DList::insert_previous(DList_Element *element,const void *data) 
{ 
  DList_Element *nouv_element;

  // Si element est NULL, on ins�re l'�l�ment en t�te 
  if (element==NULL)
    element=Head;

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
      Head->Previous=NULL;
      Head->Next=NULL;
    }
  else
    {
      // Liste non vide, insertion de l'�l�ment 
      nouv_element->Next=element;
      nouv_element->Previous=element->Previous;
      
      // Est-ce que element est la t�te ?
      if (element->Previous==NULL)
	// Oui, le nouvel element est le premier
	Head=nouv_element;
      else
	// Non, on modifie le pointeur next de l'�l�ment pr�c�dent
	element->Previous->Next=nouv_element;

      // nouv_element devient le pr�cent d'element
      element->Previous=nouv_element;
    }

  // On incr�mente la taille de la liste
  Size++;

  return 0;
}

// Suppression d'un �l�ment
int DList::remove(DList_Element *element,void **data) 
{ 

  // Erreur si la liste est vide
  if (Size==0)
    return -1;

  // Si element est NULL on supprimer l'element de t�te
  if (element==NULL)
    element=Head;

  // *data prend la valeur du pointeur vers les donn�es
  *data=element->Data;

  // L'�l�ment � supprimer est-il en t�te ?
  if (element==Head)
    {
      // Suppression de l'�l�ment de t�te

      // Head pointe vers l'�l�ment suivant
      Head=element->Next;

      // Est-ce qu'il y a un �l�ment suivant ?
      if (Head==NULL)
	// Non, la liste est vide, Tail doit pointer vers NULL
	Tail=NULL;
      else
	// Oui, on fait pointer Previous de l'�l�ment suivant vers NULL
	element->Next->Previous=NULL;
    }
  else
    {
      // Suppression d'un �l�ment ailleurs qu'en t�te

      // On modifie l'�l�ment pr�c�dent afin qu'il pointe sur le suivant
      element->Previous->Next=element->Next;

      // Y a t'il un �l�ment suivant ?
      if (element->Next==NULL)
	// Non, l'�l�ment pr�c�dent devient la queue
	Tail=element->Previous;
      else
	// Oui, on change le pointer previous de l'�l�ment suivant
	element->Next->Previous=element->Previous;	
    }

  // On lib�re la m�moire allou�e � l'�lement
  free(element);

  // On d�cr�mente la taille de la liste
  Size--;

  return 0; 
}

// Affichage sur stdout du contenu de la liste
void DList::display()
{
  DList_Element* element;
  int count=0;

  // On affiche les donn�es g�n�rales de la liste
  cout << "DList::display - Size " << Size << " | Dest " << (void*)Destroy << " | Head " << (void*)Head << " | Tail " << (void*)Tail << endl;

  // On affiche un � un les �l�ments de la liste
  element=Head;
  while(count<Size)
    {
      cout << "Elmt " << ++count << " | ";
      element->display();
      element=element->Next;
    }
}
