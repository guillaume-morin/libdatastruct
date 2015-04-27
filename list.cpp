/*****************************************************************************/
/* LIBC++ - list.cpp                                                         */
/* Classe liste chainée                                                      */
/* Copyright (c) 2004 Guillaume Morin - All rights reserved                  */
/*****************************************************************************/

#include "list.hpp"

using namespace std;

// Initialisation de la liste
void List::init(void(*destroy)(void *data)=free) 
{
  // Mise zéro des données 
  Size=0;
  Destroy=destroy;
  Head=NULL;
  Tail=NULL;
}

// Destruction de la liste
void List::destroy()
{
  void *data;
  
  // Suppression des éléments un a un
  while (Size > 0)
    {
      if ( (remove_next(NULL,(void **)&data) == 0) && (Destroy!=NULL) )
	Destroy(data);
    }

  // Mise à zéro des données
  memset(this,0,sizeof(List));
}

// Insertion d'un élément après *element
int List::insert_next(List_Element *element,const void *data) 
{ 
  List_Element *nouv_element;

  // Allocation du nouvel élément
  if ((nouv_element=(List_Element *)malloc(sizeof(List_Element))) == NULL)
    // On retourne une erreur si l'allocation échoue
    return -1;

  // On fait pointer Data sur les données
  nouv_element->Data=(void *)data;

  // Nouvel élement en tête ?
  if (element==NULL)
    { 
      // Nouvel élément en tête
      if (Size==0)  // Liste vide ?
	Tail=nouv_element; // Liste vide, l'élément est à la fin

      // Insertion du nouvel élément
      nouv_element->Next = Head;
      Head=nouv_element;
    }
  else
    {
      // Nouvel élément ailleurs qu'en tête
      if (element->Next==NULL) // element à la fin ?
	Tail=nouv_element; // Nouel élément à la fin

      // Insertion du nouvel élément
      nouv_element->Next=element->Next;
      element->Next=nouv_element;
    }

  // On incrémente la taille de la liste
  Size++;

  return 0;
}

// Suppression d'un élément après *element
int List::remove_next(List_Element *element,void **data) 
{ 
  List_Element *anc_element;

  // Impossible de supprimer si la liste est vide
  if (Size==0)
    return -1;

  // L'élément à supprimer est-il en tête ?
  if (element==NULL)
    {
      // Suppression de l'élément de tête

      // *data prend la valeur du pointeur vers les données
      *data=Head->Data;

      // On fait pointer anc_element sur la tête
      anc_element=Head;

      // et la tête devient l'élément suivant
      Head=Head->Next;

      // Si la liste est maintenant vide, Tail doit pointe vers vers NULL
      if (Size==1)
	Tail=NULL;
    }
  else
    {
      // Suppression d'un élément ailleurs qu'en tête

      // Erreur si on est à la fin de la liste
      if (element->Next==NULL)
	return -1;

      // *data prend la valeur du pointeur vers les données
      *data=element->Next->Data;

      // On fait pointer anc_element sur l'élément suivant
      anc_element=element->Next;

      // et l'élément suivant de element sur l'élement suivant anc_element
      element->Next=element->Next->Next;

      // Si l'élement suivant anc_element est NULL, alors element 
      // devient la queue de la liste
      if (element->Next==NULL)
	Tail=element;
    }

  // On libère la mémoire allouée à l'élement
  free(anc_element);

  // On décrémente la taille de la liste
  Size--;

  return 0; 
}

// Affichage sur stdout du contenu de la liste
void List::display()
{
  List_Element* element;
  int count=0;

  // On affiche les données générales de la liste
  cout << "List::display - Size " << Size << " | Dest " << (void*)Destroy << " | Head " << (void*)Head << " | Tail " << (void*)Tail << endl;

  // On affiche un à un les éléments de la liste
  element=Head;
  while(count<Size)
    {
      cout << "Elmt " << ++count << " | ";
      element->display();
      element=element->Next;
    }
}
