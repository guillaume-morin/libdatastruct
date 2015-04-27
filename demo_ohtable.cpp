#ifndef OHTABLE_HPP
#include "ohtable.hpp"
#endif

#ifndef STDLIB_H
#define STDLIB_H 1
#include <stdlib.h>
#endif

#ifndef TIME_H
#define TIME_H 1
#include <time.h>
#endif

using namespace std;

int main(void)
{
  OHTable table(110);
  char** clefs;
  char** donnees;
  int taille;
  int clef;
  int i;

  // Création de clefs aléatoires
  // Taille de 8-16 caractères
  // Caractères [a-z][A-Z][0-9]

  time_t date;
  time(&date);
  srand(date);
  clefs=(char**)malloc(100*sizeof(char*));
  donnees=(char**)malloc(100*sizeof(char*));

  table.display();
  
  for (clef=0;clef<100;++clef)
    {
      taille=rand()%8+9;
      clefs[clef]=(char*)malloc((taille+1)*sizeof(char));
      donnees[clef]=(char*)malloc((taille+1)*sizeof(char));
      for (i=0;i<=taille;++i)
	{
	  do {
	   donnees[clef][i]=clefs[clef][i]=rand()%256;
	  } while ( ( (clefs[clef][i]<'A') || (clefs[clef][i]>'Z') ) && \
		    ( (clefs[clef][i]<'a') || (clefs[clef][i]>'z') ) && \
		    ( (clefs[clef][i]<'0') || (clefs[clef][i]>'9') ) );
	}
    }

  // Remplissage de la table de hachage

  for (clef=0;clef<50;++clef)
    {
      table.add(clefs[clef],(void*)donnees[clef]);
      printf("Ajout de la clef %s de valeur %s\n",clefs[clef],donnees[clef]);
    }

  table.display();
  
  for (clef=0;clef<50;++clef)
    {
      table.add(clefs[clef],(void*)donnees[clef]);
      printf("Ajout de la clef %s de valeur %s\n",clefs[clef],donnees[clef]);
    }

  table.display();
  
  // Affichage de quelques clefs

  printf("(char*)table->get(clefs[10] : %s\n",(char*)table.get(clefs[10]));
  printf("(char*)table[clefs[20]] : %s\n",(char*)table[clefs[20]]);

  return(0);
}
