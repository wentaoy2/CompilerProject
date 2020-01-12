#include "coolrt.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <string.h>
//#include <iostream>
/* This file provides the runtime library for cool. It implements
   the functions of the cool classes in C
   */

/* Class name strings */
const char Object_string[] 	= "Object";
const char String_string[] 	= "String";
const char Int_string[] 	= "Int";
const char Bool_string[] 	= "Bool";
const char IO_string[] 		= "IO";

const char default_string[]	= "";

extern const Object_vtable Object_vtable_prototype;
extern const String_vtable String_vtable_prototype;
extern const IO_vtable IO_vtable_prototype;
extern const Int_vtable Int_vtable_prototype;
extern const Bool_vtable Bool_vtable_prototype;
/* Class vtable prototypes */
/*
const Object_vtable Object_vtable_prototype = {

};
*/
/* ADD CODE HERE FOR MORE VTABLE PROTOTYPES */


/*
// Methods in class object (only some are provided to you)
*/
Object* Object_abort(Object *self)
{
	printf("Abort called from class %s\n",
	       !self? "Unknown" : self->vtable->name);
	exit(1);
	return self;
}

const String* Object_type_name(Object *self)
{
	if (self == 0) {
		fprintf(stderr, "At __FILE__(line __LINE__): self is NULL\n");
		abort();
	}
	String *s = String_new();
	s->val = self->vtable->name;
	return s;
}


/* ADD CODE HERE FOR MORE METHODS OF CLASS OBJECT */


/*
// Methods in class IO (only some are provided to you)
*/

IO* IO_out_string(IO *self, String* x)
{
	if (self == 0 || x == 0) {
		fprintf(stderr, "At __FILE__(line __LINE__): NULL object\n");
		abort();
	}
	printf("%s",x->val);
	return self;
}

IO* IO_out_int(IO *self, int x)
{
	if (self == 0) {
		fprintf(stderr, "At __FILE__(line __LINE__): NULL object\n");
		abort();
	}
	printf("%d", x);
	return self;
}


/*
 * Get one line from stream using get_line(), then discard newline character.
 * Allocate string *in_string_p and store result there.
 * Return number of chars read.
 */
static int get_one_line(char** in_string_p, FILE* stream)
{
	/* Get one line worth of input */
	size_t len = 0;
	ssize_t num_chars_read;
	num_chars_read = getline(in_string_p, &len, stdin);
	if (*in_string_p == 0) {
		fprintf(stderr, "At __FILE__(line __LINE__):\n   ");
		fprintf(stderr, "    allocation failed in IO::in_string()\n");
		exit(1);
	}

	/* Discard the newline char, if any.  It may not exist if EOF reached. */
	if (num_chars_read > 0 && (*in_string_p)[num_chars_read-1] == '\n') {
		(*in_string_p)[num_chars_read-1] = '\0';
		--len;
	}

	return len;
}

/*
 * The method IO::in_string(): String reads a string from
 * the standard input, up to but not including a newline character.
 */
String* IO_in_string(IO *self)
{
	if (self == 0) {
		fprintf(stderr, "At __FILE__(line __LINE__): self is NULL\n");
		abort();
	}

	/* Get one line worth of input with the newline, if any, discarded */
	char* in_string = 0;
	ssize_t len = get_one_line(&in_string, stdin);
	assert(in_string);

	/* We can take advantage of knowing the internal layout of String objects */
	String *str = String_new();
	str->val = in_string;
	return str;
}

/*
 * The method IO::in_int(): Int reads a single integer, which may be preceded
 * by whitespace.
 * Any characters following the integer, up to and including the next newline,
 * are discarded by in_int.
 */
int IO_in_int(IO *self)
{
	if (self == 0) {
		fprintf(stderr, "At __FILE__(line __LINE__): self is NULL\n");
		abort();
	}

	/* Get one line worth of input with the newline, if any, discarded */
	char* in_string = 0;
	ssize_t len = get_one_line(&in_string, stdin);
	assert(in_string);

	/* Now extract initial int and ignore the rest of the line */
	int x;
	int num_ints = 0;
	if (len)
		num_ints = sscanf(in_string, " %d", &x); /* Discards initial spaces*/

	/* If no text found, abort. */
	if (num_ints == 0) {
		fprintf(stderr, "At __FILE__(line __LINE__):\n   ");
		fprintf(stderr, "    Invalid integer on input in IO::in_int()");
		Object_abort((Object*) self);
	}
	return x;
}

Object * Object_copy(Object *self){
	Object * output = Object_new();
	output->vtable = self->vtable;
	memcpy(output, self, self->vtable->size);
	return output;
}

Object * Object_new(void){
	//Object output;
	Object* ptr = malloc(sizeof(Object));
	ptr->vtable = &Object_vtable_prototype;
	//memcpy(ptr, &output, sizeof(Object));
	return ptr;
}

IO * IO_new(void){
//	IO output;
	IO* ptr = malloc(sizeof(IO));
	ptr->vtable  = &IO_vtable_prototype;
//	memcpy(ptr, &output, sizeof(IO));
	return ptr;
}


void Int_init(Int* ptr, int val){
	ptr->val = val;
//	return ptr;
}

void Bool_init(Bool* ptr, bool val){
	ptr->val = val;
//	return ptr;
}
/*
void Int_init(Int* ptr, int val){

	ptr->vtable  = &Int_vtable_prototype;
	ptr->val = val;
	return ptr;
}*/


Int* Int_copy(Int* self){
	Int * copy = Int_new();
	Int_init(copy, self->val);

	return copy;
}

Bool* Bool_copy(Bool* self){
	Bool * copy = Bool_new();
	Bool_init(copy, self->val);

	return copy;
}



Int * Int_new(void){
	//Int output;
	Int* ptr = malloc(sizeof(Int));
	//memcpy(ptr, &output, sizeof(Int));
	ptr->vtable  = &Int_vtable_prototype;
	//ptr->val = val;
	return ptr;
}

/*
void Bool_init(Int* ptr, int val){

	ptr->vtable  = &Bool_vtable_prototype;
	ptr->val = val;
	return ptr;
}

*/


Bool * Bool_new(void){
//	Bool output;
	Bool* ptr = malloc(sizeof(Bool));
	ptr->vtable  = &Bool_vtable_prototype;
	//ptr->val = val;
//	memcpy(ptr, &output, sizeof(Bool));
	return ptr;
}

String * String_new(void){
//	String output;
	String* ptr = malloc(sizeof(String));
	ptr->vtable = &String_vtable_prototype;
	return ptr;
}

/* ADD CODE HERE FOR MORE METHODS OF CLASS IO */


/* ADD CODE HERE FOR METHODS OF OTHER BUILTIN CLASSES */
int String_length(String* s) {
	//Int* output = Int_new();
	int output = (int)strlen(s->val);
	return output;
}

String* String_concat(String* self, String* fir){
	char * sel = self->val;
	int len1 = strlen(sel);
	char * sel2 = fir->val;
	int len2 = strlen(sel2);
	char * output = malloc(len1 + len2 + 1);
	memcpy(output, sel, len1);
	memcpy(output + len1, sel2, len2);
	output[len1 + len2] = '\0';
	String * fin = String_new();
	fin->val = output;
	return fin;
}

String* String_substr(String* self, int fir, int sec){
/*	char * sel = self->val;
	size_t lens = strlen(sel);
	assert(lens < fir->val + sec->val);

	char* result = malloc(sec->val + 1);
	memcpy(result, sel+fir->val, sec->val);
	result[fir->val] = '\0';
	String * output = String_new();
	//output->vtblptr = self->vtblptr;
	output->val = result;
	return output;*/
	char * sel = self->val;
	size_t lens = strlen(sel);
	//fprintf(stderr, "%d\n", lens);
	//fprintf(stderr, "%d\n", fir+sec);
	//cout << lens;
	//cout << fir + sec;
	assert(lens <= fir + sec);
	//cout << lens;
	char* result = malloc(sec + 1);
	memcpy(result, sel+fir, sec);
	result[fir] = '\0';
	String * output = String_new();
	//output->vtblptr = self->vtblptr;
	output->val = result;
	return output;
}
