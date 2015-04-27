# LIBDATASTRUCT - README.OHTABLE

La classe OHTable permet de créer des objets de type table de hachage
à adressage ouvert avec des clefs de type chaines de caractère C
traditionnelles, portable, héritable et performante.

OHTable : Classe table de hachage
*  Membre privés : 
**	OHTable( const OHTable & )
***		construction par recopie interdite
**	OHTable & operator = ( const OHTable & )
***		assignation interdite
*  Membres protégés :
**	int Size;
**	int Capacity;
**	int init(const int)
***		initialise une table de hachage de int elements
**	int destroy()
***		supprime la table de hachage
**	int hash(char*)
***		hache la chaine pour en obtenir le rang
*  Membre publiques : 
**	OHTable(int)
***		constructeur de la classe, appelle init(int)
**	~OHTable()
***		destructeur de la classe, appelle destroy()
**	int add(const char*,const void*)
***		ajoute une entrée à la table
**	void *get(const char*)
***		renvoie l'adresse de l'élément correspondant à la chaine
**	void *set(const char*,const void*)
***		modifie l'adresse de l'élément correspondant à la chaine,
***		renvoie l'adresse précédente
**	void *operator [] (const char*)
***		équivalent à get
**	bool exists(const char*)
***		renvoie 1 si un élément correspondant à la chaine existe
**	int rem(const char*)
***		supprime un élément correspondant à la chaine
**	int size()
***		retourne la taille maximale de la table de hachage

