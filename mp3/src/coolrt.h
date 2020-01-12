/*
 * This file provides the runtime library for cool. It implements
 * the cool classes in C.  Feel free to change it to match the structure
 * of your code generator.
*/

#include <stdbool.h>

typedef struct Object Object;
typedef struct String String;
typedef struct IO IO;
typedef struct Int Int;
typedef struct Bool Bool;

typedef struct Object_vtable Object_vtable;
typedef struct String_vtable String_vtable;
typedef struct IO_vtable IO_vtable;
typedef struct Int_vtable Int_vtable;
typedef struct Bool_vtable Bool_vtable;

/* class type definitions */
struct Object {
  Object_vtable * vtable;
	/* ADD CODE HERE */
};

struct Int {
  Int_vtable * vtable;
  int val;
	/* ADD CODE HERE */
};

struct Bool {
  Bool_vtable* vtable;
  bool val;
	/* ADD CODE HERE */
};

struct String {
  String_vtable* vtable;
  char* val;
	/* ADD CODE HERE */
};

struct IO {
  IO_vtable * vtable;
	/* ADD CODE HERE */
};


/* vtable type definitions */
struct Object_vtable {
  int tag;
  int size;
  char* name;
  Object * (*Object_new)(void);
  Object * (*Object_abort)(Object* self);
  const String* (*Object_type_name)(Object* self);
  //TODO: self type?
  Object* (*Object_copy)(Object* self);
	/* ADD CODE HERE */
};

struct IO_vtable {
  int tag;
  int size;
  char* name;
  IO* (*IO_new)(void);
  Object* (*Object_abort)(IO* self);
  const String* (*Object_type_name)(IO* self);
  IO* (*Object_copy)(IO* self);
  IO* (*IO_out_string)(IO* self, String* x);
  IO* (*IO_out_int)(IO* self, Int* x);
  String* (*IO_in_string)(IO* self);
  Int* (*IO_in_int)(IO* self);
	/* ADD CODE HERE */
};

struct Int_vtable {
  int tag;
  int size;
  char* name;
  void (*Int_init)(Int* ptr, int val);
  Int * (*Int_new)(void);
  Object * (*Object_abort)(Int* self);
  const String* (*Object_type_name)(Int* self);
  //TODO: self type?
  Int* (*Object_copy)(Int* self);
	/* ADD CODE HERE */
};

struct Bool_vtable {
  int tag;
  int size;
  char* name;
  void (*Bool_init)(Bool* ptr, bool val);
  Bool * (*Bool_new)(void);
  Object * (*Object_abort)(Bool* self);
  const String* (*Object_type_name)(Bool* self);
  //TODO: self type?
  Bool* (*Object_copy)(Bool* self);
	/* ADD CODE HERE */
};

struct String_vtable {
  int tag;
  int size;
  char* name;
  String * (*String_new)(void);
  Object * (*Object_abort)(String* self);
  const String* (*Object_type_name)(String* self);
  //TODO: self type?
  String* (*Object_copy)(String* self);
  int (*String_length)(String* self);
  String* (*String_concat)(String* self, String* fir);
  String* (*String_substr)(String* self, int fir, int sec);
	/* ADD CODE HERE */
};

/* methods in class Object */
Object* Object_new(void);
Object* Object_abort(Object *self);
const String* Object_type_name(Object *self);
Object* Object_copy(Object* self);

	/* ADD CODE HERE */

/* methods in class IO */
IO* IO_new(void);
void IO_init(IO *self);
IO* IO_out_string(IO *self, String *x);
IO* IO_out_int(IO *self, int x);
String* IO_in_string(IO *self);
int IO_in_int(IO *self);

/* methods in class Int */
	/* ADD CODE HERE */
Int* Int_new(void);
//Void Int_init(Int*, int);
/* methods in class Bool */
	/* ADD CODE HERE */
Bool * Bool_new(void);
//Void Bool_init(Bool*, bool);
/* methods in class String */
	/* ADD CODE HERE */
String* String_new(void);
int String_length(String * self);
String* String_concat(String* self, String* fir);
String* String_substr(String* self, int fir, int sec);
