/*****************************************************************************/
/* LIBC++ - dtype.hpp                                                        */
/* Type de donnée d'un index                                                 */
/* Copyright (c) 2004 Guillaume Morin - All rights reserved                  */
/*****************************************************************************/

#define DTYPE_HPP 1

typedef enum DType_ {
  // Types de base
  CHAR,
  INT,
  SHORT,
  LONG,
  FLOAT,
  DOUBLE,
  // Signés
  S_CHAR,
  S_INT,
  S_SHORT,
  S_LONG,
  // Non signés
  US_CHAR,
  US_INT,
  US_SHORT,
  US_LONG,
  // Pointeur vers un type
  TYPE_PTR,
  // Pointeur vers une structure
  STRUCT_PTR,
  // Pointeur vers une classe
  CLASS_PTR,
  // Pointeur vers une fonction
  FUNC_PTR,
  // Non défini
  UNDEFINED
} DType;
