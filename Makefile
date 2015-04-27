#*****************************************************************************#
# LIBC++ - Makefile                                                           #
# Génération des executables                                                  #
# Copyright (c) 2004 Guillaume Morin - All rights reserved                    #
#*****************************************************************************#

CPP=g++
#CPPFLAGS= -I. -I../include -DHAVE_CONFIG_H -Wall -x c++ -fsigned-char -pipe
CPPFLAGS= -I. -I../include -Wall -x c++ -fsigned-char
ALT_INCLUDES= -I.
#OFLAGS=  -mcpu=i686 -O2 -pipe -fomit-frame-pointer -funroll-loops
OFLAGS= -pg -pipe -O0
CPPLIBS= 

all :	\
	demo_list \
	demo_clist \
	demo_dlist \
	demo_cdlist \
	demo_queue \
	demo_stack \
	demo_ohtable 

# Programmes de démonstration
demo_list:	demo_list.o list.o list_element.o
	$(CPP) $(CPPLIBS) demo_list.o list.o list_element.o -o demo_list
demo_list.o : demo_list.cpp
	$(CPP) $(ALT_INCLUDES) $(CPPFLAGS) $(OFLAGS) -c demo_list.cpp

demo_clist:	demo_clist.o clist.o list.o list_element.o
	$(CPP) $(CPPLIBS) demo_clist.o clist.o list.o list_element.o -o demo_clist
demo_clist.o : demo_clist.cpp
	$(CPP) $(ALT_INCLUDES) $(CPPFLAGS) $(OFLAGS) -c demo_clist.cpp

demo_dlist:	demo_dlist.o dlist.o dlist_element.o
	$(CPP) $(CPPLIBS) demo_dlist.o dlist.o dlist_element.o -o demo_dlist
demo_dlist.o : demo_dlist.cpp
	$(CPP) $(ALT_INCLUDES) $(CPPFLAGS) $(OFLAGS) -c demo_dlist.cpp

demo_cdlist:	demo_cdlist.o cdlist.o dlist.o dlist_element.o
	$(CPP) $(CPPLIBS) demo_cdlist.o cdlist.o dlist.o dlist_element.o -o demo_cdlist
demo_cdlist.o : demo_cdlist.cpp
	$(CPP) $(ALT_INCLUDES) $(CPPFLAGS) $(OFLAGS) -c demo_cdlist.cpp

demo_queue:	demo_queue.o queue.o list.o list_element.o
	$(CPP) $(CPPLIBS) demo_queue.o queue.o list.o list_element.o -o demo_queue
demo_queue.o : demo_queue.cpp
	$(CPP) $(ALT_INCLUDES) $(CPPFLAGS) $(OFLAGS) -c demo_queue.cpp

demo_stack:	demo_stack.o stack.o list.o list_element.o
	$(CPP) $(CPPLIBS) demo_stack.o stack.o list.o list_element.o -o demo_stack
demo_stack.o : demo_stack.cpp
	$(CPP) $(ALT_INCLUDES) $(CPPFLAGS) $(OFLAGS) -c demo_stack.cpp

demo_ohtable:	demo_ohtable.o ohtable.o list.o list_element.o
	$(CPP) $(CPPLIBS) ohtable.o demo_ohtable.o list.o list_element.o -o demo_ohtable
demo_ohtable.o : demo_ohtable.cpp
	$(CPP) $(ALT_INCLUDES) $(CPPFLAGS) $(OFLAGS) -c demo_ohtable.cpp

demo_chtable:	demo_chtable.o chtable.o
	$(CPP) $(CPPLIBS) chtable.o demo_chtable.o -o demo_chtable
demo_chtable.o : demo_chtable.cpp
	$(CPP) $(ALT_INCLUDES) $(CPPFLAGS) $(OFLAGS) -c demo_chtable.cpp

# Elements de base
list_element.o : list_element.cpp list_element.hpp
	$(CPP) $(ALT_INCLUDES) $(CPPFLAGS) $(OFLAGS) -c list_element.cpp

dlist_element.o : dlist_element.cpp dlist_element.hpp
	$(CPP) $(ALT_INCLUDES) $(CPPFLAGS) $(OFLAGS) -c dlist_element.cpp

list.o : list.cpp list.hpp
	$(CPP) $(ALT_INCLUDES) $(CPPFLAGS) $(OFLAGS) -c list.cpp

clist.o : clist.cpp clist.hpp
	$(CPP) $(ALT_INCLUDES) $(CPPFLAGS) $(OFLAGS) -c clist.cpp

dlist.o : dlist.cpp dlist.hpp
	$(CPP) $(ALT_INCLUDES) $(CPPFLAGS) $(OFLAGS) -c dlist.cpp

cdlist.o : cdlist.cpp cdlist.hpp
	$(CPP) $(ALT_INCLUDES) $(CPPFLAGS) $(OFLAGS) -c cdlist.cpp

stack.o : stack.cpp stack.hpp
	$(CPP) $(ALT_INCLUDES) $(CPPFLAGS) $(OFLAGS) -c stack.cpp

queue.o : queue.cpp queue.hpp
	$(CPP) $(ALT_INCLUDES) $(CPPFLAGS) $(OFLAGS) -c queue.cpp

ohtable.o : ohtable.cpp ohtable.hpp
	$(CPP) $(ALT_INCLUDES) $(CPPFLAGS) $(OFLAGS) -c ohtable.cpp

# Utilitaires
clean : 
	rm -f *.o
	rm -f *~ \#*
	rm -f demo_list demo_clist demo_dlist demo_cdlist 
	rm -f demo_queue demo_stack
	rm -f demo_ohtable

remake : 
	make clean
	make
