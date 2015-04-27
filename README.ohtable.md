# LIBDATASTRUCT - README.OHTABLE

La classe OHTable permet de cr�er des objets de type table de hachage
� adressage ouvert avec des clefs de type chaines de caract�re C
traditionnelles, portable, h�ritable et performante.

OHTable : Classe table de hachage
*  Membre priv�s : 
**	OHTable( const OHTable & )
***		construction par recopie interdite
**	OHTable & operator = ( const OHTable & )
***		assignation interdite
*  Membres prot�g�s :
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
***		ajoute une entr�e � la table
**	void *get(const char*)
***		renvoie l'adresse de l'�l�ment correspondant � la chaine
**	void *set(const char*,const void*)
***		modifie l'adresse de l'�l�ment correspondant � la chaine,
***		renvoie l'adresse pr�c�dente
**	void *operator [] (const char*)
***		�quivalent � get
**	bool exists(const char*)
***		renvoie 1 si un �l�ment correspondant � la chaine existe
**	int rem(const char*)
***		supprime un �l�ment correspondant � la chaine
**	int size()
***		retourne la taille maximale de la table de hachage

