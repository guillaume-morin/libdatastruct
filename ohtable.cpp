/*****************************************************************************/
/* LIBC++ - HTable                                                           */
/* Table de hachage                                                          */
/* Copyright (c) 2004 Guillaume Morin - All rights reserved                  */
/*****************************************************************************/

#include "ohtable.hpp"

using namespace std;

// Fonction de hachage
int OHTable::hash(const char *key)
{
  int i=0,result=0;
  while (key[i]!=0)
    result+=key[i++];
  result=result%Capacity;
  return result;
}

// Initialise la table de hachage
int OHTable::init(const int nb_element)
{
  // Allocation de la mémoire de la table en une seule fois
  Table=(OHTable_Element**)malloc(sizeof(OHTable_Element*)*nb_element);
  
  //Enregistrement de la capacité
  Capacity=nb_element;

  // Mise à zéro de la table
  memset(Table,0,nb_element);
  Size=0;
  
  return 0;
}

int OHTable::destroy()
{
  // On efface chacun des éléments
  //  while (Size)
  //    free(rem(NULL));

  while (Size)
    rem(NULL);

  // Libère la mémoire allouée
  free(Table);
  Table=NULL;

  return 0;
}

// Ajoute une entrée
int OHTable::add(char *key,void *value)
{
  // Vérification du taux de remplissage
  if (Size==Capacity)
    return -1;

  // On hache la clef
  int position=hash(key);

  // On essaye l'emplacement
  while (Table[position]!=0)
    {
      ++position;
      if (position==Capacity)
	position=0;
    }
    
  // Allocation de l'élément
  if ((Table[position]=(OHTable_Element*)malloc(sizeof(OHTable_Element*)))==NULL)
    return -1;

  // Insertion des valeurs
  Table[position]->Key=key;
  Table[position]->Value=value;
  
  // Incrémentation de la taille
  ++Size;

  return 0;
}

int OHTable::display()
{
  cout << endl<< "OHTable::display()" << endl;
  cout << "Capacity : " << Capacity << endl;
  cout << "Size : " << Size << endl;
  cout << "Mémoire allouée pour la table : " << Capacity*sizeof(OHTable_Element*) << endl;
  cout << "Mémoire utilisée par la table : " << Size*sizeof(OHTable_Element*) << endl;
  cout << "Mémoire utilisée par les HTable_Element : " << Size*sizeof(OHTable_Element) << endl << endl;
  cout << "Contenu :" << endl;

  int i=0;
  while (i<Capacity)
    {
      if (Table[i]==0)
	cout << i << " NULL" << " | ";
      else
	cout << i << " " << Table[i]->Key << " " << Table[i]->Value << " | ";
      ++i;
    }
  cout << endl << endl;

  return 0;
}

void *OHTable::get(const char *key)
{
  int limit=0;

  // On hache la clef
  int position=hash(key);
  
  // On vérifie l'emplacement
  for (;;)
    {
      // Y-a t-il un élément ?
      if (Table[position]==NULL)
	return NULL;
      
      // On compare les chaines
      if (strcmp(key,Table[position]->Key)==0)
	return Table[position]->Value;
      else
	{
	  ++limit;
	  // On a fait le tour
	  if (limit==Capacity)
	    return NULL;

	  // On se décale
	  ++position;
	  if (position==Capacity-1)
	    position=0;
	}
    }
}

void *OHTable::set(const char *key,const void *value)
{
  int limit=0;
  void *old_value;

  // On hache la clef
  int position=hash(key);
  
  // On vérifie l'emplacement
  for (;;)
    {
      // Y-a t-il un élément ?
      if (Table[position]==NULL)
	return NULL;
      
      // On compare les chaines
      if (strcmp(key,Table[position]->Key)==0)
	{
	  // Sauvegarde de l'ancienne valeur
	  old_value=Table[position]->Value;

	  // Modification la valeur
	  Table[position]->Value=(void*)value;
	  
	  // on retourne l'ancienne
	  return old_value;
	}
      else
	{
	  ++limit;
	  // On a fait le tour
	  if (limit==Capacity)
	    return NULL;

	  // On se décale
	  ++position;
	  if (position==Capacity-1)
	    position=0;
	}
    }
}

void *OHTable::rem(const char *key)
{
  int limit=0,position=0;
  void *old_value;

  // Y-a-t il élément précis à supprimer
  if (key==NULL)
    {
      // Non, on efface le premier élément rencontré
      for (;;)
	{
	  // Y-a-t il un élément ?
	  if (Table[position]==NULL)
	    {
	      // Non, on vérifie qu'on n'a pas tout testé
	      //	      printf("Limit: %i\tCapacity: %i\tPosition: %i,Size: %i\n",limit,Capacity,position,Size);
	      ++limit;
	      if (limit==Capacity)
		return NULL;
	      
	      // Sinon, on continue la recherche
	      ++position;
	      if (position==Capacity)
		position=0;
	    }
	  else
	    {
	      // On sauvegarde Value
	      old_value=Table[position]->Value;
	      
	      // On libère la mémoire de la Key
	      free (Table[position]->Key);
	      Table[position]->Key=NULL;
	      
	      // On libère la mémoire du OHTable_Element
	      free(Table[position]);
	      Table[position]=NULL;

	      // On décrémente la taille
	      --Size;

	      // et on returne la value
	      return old_value;
	    }
	}
      
      
    }
  else
    {
      // Oui, on recherche l'élément

      // On hache la clef
      position=hash(key);
      
      // On vérifie l'emplacement
      for (;;)
	{
	  // Y-a t-il un élément ?
	  if (Table[position]==NULL)
	    return NULL;
	  
	  // On compare les chaines
	  if (strcmp(key,Table[position]->Key)==0)
	    {
	      // On sauvegarde Value
	      old_value=Table[position]->Value;
	      
	      // On libère la mémoire de la Key
	      free (Table[position]->Key);
	      Table[position]->Key=NULL;
	      
	      // On libère la mémoire du OHTable_Element
	      free(Table[position]);
	      Table[position]=NULL;
	      
	      // On décrémente la taille
	      --Size;

	      // et on returne la value
	      return old_value;
	    }
	  else
	    {
	      ++limit;
	      // On a fait le tour
	      if (limit==Capacity)
		return NULL;
	      
	      // On se décale
	      ++position;
	      if (position==Capacity)
		position=0;
	    }
	}
    }
}
