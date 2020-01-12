//**************************************************************
//
// Code generator SKELETON
//
// Read the comments carefully and add code to build an LLVM program
//**************************************************************

#define EXTERN
#include "cgen.h"
#include <string>
#include <sstream>


#define SSTR( x ) dynamic_cast< std::ostringstream & >( \
            ( std::ostringstream() << std::dec << x ) ).str()
//
extern int cgen_debug;
//int cgen_debug = 1;
//////////////////////////////////////////////////////////////////////
//
// Symbols
//
// For convenience, a large number of symbols are predefined here.
// These symbols include the primitive type and method names, as well
// as fixed names used by the runtime system.  Feel free to add your
// own definitions as you see fit.
//
//////////////////////////////////////////////////////////////////////
EXTERN Symbol
	// required classes
	Object,
	IO,
	String,
	Int,
	Bool,
	Main,

	// class methods
	cool_abort,
	type_name,
	cool_copy,
	out_string,
	out_int,
	in_string,
	in_int,
	length,
	concat,
	substr,

	// class members
	val,

	// special symbols
	No_class,    // symbol that can't be the name of any user-defined class
	No_type,     // If e : No_type, then no code is generated for e.
	SELF_TYPE,   // Special code is generated for new SELF_TYPE.
	self,        // self generates code differently than other references

	// extras
	arg,
	arg2,
	prim_string,
	prim_int,
	prim_bool;


//********************************************************
//
// PREDEFINED FUNCTIONS:
//
// The following functions are already coded, you should
// not need to modify them, although you may if necessary.
//
//********************************************************

//
// Initializing the predefined symbols.
//
static void initialize_constants(void)
{
	Object      = idtable.add_string("Object");
	IO          = idtable.add_string("IO");
	String      = idtable.add_string("String");
	Int         = idtable.add_string("Int");
	Bool        = idtable.add_string("Bool");
	Main        = idtable.add_string("Main");

	cool_abort  = idtable.add_string("abort");
	type_name   = idtable.add_string("type_name");
	cool_copy   = idtable.add_string("copy");
	out_string  = idtable.add_string("out_string");
	out_int     = idtable.add_string("out_int");
	in_string   = idtable.add_string("in_string");
	in_int      = idtable.add_string("in_int");
	length      = idtable.add_string("length");
	concat      = idtable.add_string("concat");
	substr      = idtable.add_string("substr");

	val         = idtable.add_string("val");

	No_class    = idtable.add_string("_no_class");
	No_type     = idtable.add_string("_no_type");
	SELF_TYPE   = idtable.add_string("SELF_TYPE");
	self        = idtable.add_string("self");

	arg         = idtable.add_string("arg");
	arg2        = idtable.add_string("arg2");
	prim_string = idtable.add_string("sbyte*");
	prim_int    = idtable.add_string("int");
	prim_bool   = idtable.add_string("bool");
}

//*********************************************************
//
// Define method for code generation
//
// This is the method called by the compiler driver
// `cgtest.cc'. cgen takes an `ostream' to which the assembly will be
// emitted, and it passes this and the class list of the
// code generator tree to the constructor for `CgenClassTable'.
// That constructor performs all of the work of the code
// generator.
//
//*********************************************************
void program_class::cgen(ostream &os)
{
	initialize_constants();
	class_table = new CgenClassTable(classes,os);
}


// Create definitions for all String constants
void StrTable::code_string_table(ostream& s, CgenClassTable* ct)
{
	for (List<StringEntry> *l = tbl; l; l = l->tl()) {
		l->hd()->code_def(s, ct);
	}
}

// Create definitions for all Int constants
void IntTable::code_string_table(ostream& s, CgenClassTable* ct)
{
	for (List<IntEntry> *l = tbl; l; l = l->tl()) {
		l->hd()->code_def(s, ct);
	}
}

//
// Sets up declarations for extra functions needed for code generation
// You should not need to modify this code for MP2.1
//
void CgenClassTable::setup_external_functions()
{
	ValuePrinter vp;
	// setup function: external int strcmp(sbyte*, sbyte*)
	op_type i32_type(INT32), i8ptr_type(INT8_PTR), vararg_type(VAR_ARG);
	vector<op_type> strcmp_args;
	strcmp_args.push_back(i8ptr_type);
	strcmp_args.push_back(i8ptr_type);
	vp.declare(*ct_stream, i32_type, "strcmp", strcmp_args);

	// setup function: external int printf(sbyte*, ...)
	vector<op_type> printf_args;
	printf_args.push_back(i8ptr_type);
	printf_args.push_back(vararg_type);
	vp.declare(*ct_stream, i32_type, "printf", printf_args);

	// setup function: external void abort(void)
	op_type void_type(VOID);
	vector<op_type> abort_args;
	vp.declare(*ct_stream, void_type, "abort", abort_args);

	// setup function: external i8* malloc(i32)
	vector<op_type> malloc_args;
	malloc_args.push_back(i32_type);
	vp.declare(*ct_stream, i8ptr_type, "malloc", malloc_args);

#ifdef MP3
  op_type obj_ptr_type("Object*"), str_ptr_type("String*"), i1_type(INT1),
			io_ptr_type("IO*"), int_ptr_type("Int*"), bool_ptr_type("Bool*");

	vector<op_type> obj_new_args;
	vp.declare(*ct_stream, op_type("Object*"), "Object_new", obj_new_args);

	vector<op_type> obj_abort_args;
	obj_abort_args.push_back(op_type("Object*"));
	vp.declare(*ct_stream, op_type("Object*"), "Object_abort", obj_abort_args);

	vector<op_type> obj_type_args;
	obj_type_args.push_back(op_type("Object*"));
	vp.declare(*ct_stream, op_type("String*"), "Object_type_name", obj_type_args);

	vector<op_type> obj_copy_args;
	obj_copy_args.push_back(op_type("Object*"));
	vp.declare(*ct_stream, op_type("Object*"), "Object_copy", obj_copy_args);

  vector<op_type> io_new_args;
  vp.declare(*ct_stream, op_type("IO*"), "IO_new", io_new_args);

  vector<op_type> io_out_string_args;
  io_out_string_args.push_back(op_type("IO*"));
  io_out_string_args.push_back(op_type("String*"));
  vp.declare(*ct_stream, op_type("IO*"), "IO_out_string", io_out_string_args);

  vector<op_type> io_out_int_args;
  io_out_int_args.push_back(op_type("IO*"));
  io_out_int_args.push_back(op_type(INT32));
  vp.declare(*ct_stream, op_type("IO*"), "IO_out_int", io_out_int_args);

  vector<op_type> io_in_string_args;
  io_in_string_args.push_back(op_type("IO*"));
  vp.declare(*ct_stream, op_type("String*"), "IO_in_string", io_in_string_args);

  vector<op_type> io_in_int_args;
  io_in_int_args.push_back(op_type("IO*"));
  vp.declare(*ct_stream, op_type(INT32), "IO_in_int", io_in_int_args);


  	vector<op_type> string_new_args;
  	vp.declare(*ct_stream, op_type("String*"), "String_new", string_new_args);

  	vector<op_type> str_len_args;
  	str_len_args.push_back(op_type("String*"));
  	vp.declare(*ct_stream, op_type(INT32), "String_length", str_len_args);

  	vector<op_type> str_concat_args;
  	str_concat_args.push_back(op_type("String*"));
  	str_concat_args.push_back(op_type("String*"));
  	vp.declare(*ct_stream, op_type("String*"), "String_concat", str_concat_args);

  	vector<op_type> str_substr_args;
  	str_substr_args.push_back(op_type("String*"));
  	str_substr_args.push_back(op_type(INT32));
  	str_substr_args.push_back(op_type(INT32));
  	vp.declare(*ct_stream, op_type("String*"), "String_substr", str_substr_args);


  vector<op_type> int_new_args;
  vp.declare(*ct_stream, op_type("Int*"), "Int_new", int_new_args);


  vector<op_type> int_init_args;
  int_init_args.push_back(op_type("Int*"));
  int_init_args.push_back(op_type(INT32));
  vp.declare(*ct_stream, op_type(VOID), "Int_init", int_init_args);


    vector<op_type> bool_new_args;
    vp.declare(*ct_stream, op_type("Bool*"), "Bool_new", bool_new_args);

  vector<op_type> bool_init_args;
  bool_init_args.push_back(op_type("Bool*"));
  bool_init_args.push_back(op_type(INT1));
  vp.declare(*ct_stream, op_type(VOID), "Bool_init", bool_init_args);



	//ADD CODE HERE
	//Setup external functions for built in object class functions
#endif
}

// Creates AST nodes for the basic classes and installs them in the class list
void CgenClassTable::install_basic_classes()
{
	// The tree package uses these globals to annotate the classes built below.
	curr_lineno = 0;
	Symbol filename = stringtable.add_string("<basic class>");

	//
	// A few special class names are installed in the lookup table but not
	// the class list. Thus, these classes exist, but are not part of the
	// inheritance hierarchy.

	// No_class serves as the parent of Object and the other special classes.
	Class_ noclasscls = class_(No_class,No_class,nil_Features(),filename);
	install_special_class(new CgenNode(noclasscls, CgenNode::Basic, this));
	delete noclasscls;

#ifdef MP3
	// SELF_TYPE is the self class; it cannot be redefined or inherited.
	Class_ selftypecls = class_(SELF_TYPE,No_class,nil_Features(),filename);
	install_special_class(new CgenNode(selftypecls, CgenNode::Basic, this));
	delete selftypecls;
	//
	// Primitive types masquerading as classes. This is done so we can
	// get the necessary Symbols for the innards of String, Int, and Bool
	//
	Class_ primstringcls = class_(prim_string,No_class,nil_Features(),filename);
	install_special_class(new CgenNode(primstringcls, CgenNode::Basic, this));
	delete primstringcls;
#endif
	Class_ primintcls = class_(prim_int,No_class,nil_Features(),filename);
	install_special_class(new CgenNode(primintcls, CgenNode::Basic, this));
	delete primintcls;
	Class_ primboolcls = class_(prim_bool,No_class,nil_Features(),filename);
	install_special_class(new CgenNode(primboolcls, CgenNode::Basic, this));
	delete primboolcls;
	//
	// The Object class has no parent class. Its methods are
	//        cool_abort() : Object   aborts the program
	//        type_name() : Str       returns a string representation of class name
	//        copy() : SELF_TYPE      returns a copy of the object
	//
	// There is no need for method bodies in the basic classes---these
	// are already built in to the runtime system.
	//
	Class_ objcls =
		class_(Object,
		       No_class,
		       append_Features(
		       append_Features(
		       single_Features(method(cool_abort, nil_Formals(),
		                              Object, no_expr())),
		       single_Features(method(type_name, nil_Formals(),
		                              String, no_expr()))),
		       single_Features(method(cool_copy, nil_Formals(),
		                              SELF_TYPE, no_expr()))),
		       filename);
	install_class(new CgenNode(objcls, CgenNode::Basic, this));
	delete objcls;

//
// The Int class has no methods and only a single attribute, the
// "val" for the integer.
//
	Class_ intcls=
		class_(Int,
		       Object,
		       single_Features(attr(val, prim_int, no_expr())),
		       filename);
	install_class(new CgenNode(intcls, CgenNode::Basic, this));
	delete intcls;

//
// Bool also has only the "val" slot.
//
	Class_ boolcls=
		class_(Bool,
		       Object,
		       single_Features(attr(val, prim_bool, no_expr())),
		       filename);
	install_class(new CgenNode(boolcls, CgenNode::Basic, this));
	delete boolcls;

#ifdef MP3
//
// The class String has a number of slots and operations:
//       val                                  the string itself
//       length() : Int                       length of the string
//       concat(arg: Str) : Str               string concatenation
//       substr(arg: Int, arg2: Int): Str     substring
//
	Class_ stringcls =
		class_(String,
		       Object,
		       append_Features(
		       append_Features(
		       append_Features(
		       single_Features(attr(val, prim_string, no_expr())),
		       single_Features(method(length, nil_Formals(),
		                              Int, no_expr()))),
		       single_Features(method(concat,
		                              single_Formals(formal(arg, String)),
		                              String,
		                              no_expr()))),
		       single_Features(method(substr,
		                              append_Formals(
		                                 single_Formals(formal(arg, Int)),
		                                 single_Formals(formal(arg2, Int))),
		                              String,
		                              no_expr()))),
		       filename);
	install_class(new CgenNode(stringcls, CgenNode::Basic, this));
	delete stringcls;
#endif

#ifdef MP3
//
// The IO class inherits from Object. Its methods are
//        out_string(Str) : SELF_TYPE          writes a string to the output
//        out_int(Int) : SELF_TYPE               "    an int    "  "     "
//        in_string() : Str                    reads a string from the input
//        in_int() : Int                         "   an int     "  "     "
//
	Class_ iocls =
		class_(IO,
		       Object,
		       append_Features(
		       append_Features(
		       append_Features(
		       single_Features(method(out_string,
		                              single_Formals(formal(arg, String)),
		                              SELF_TYPE, no_expr())),
		       single_Features(method(out_int, single_Formals(formal(arg, Int)),
		                              SELF_TYPE, no_expr()))),
		       single_Features(method(in_string, nil_Formals(), String,
		                              no_expr()))),
		       single_Features(method(in_int, nil_Formals(), Int, no_expr()))),
		       filename);
	install_class(new CgenNode(iocls, CgenNode::Basic, this));
	delete iocls;
#endif
}

//
// install_classes enters a list of classes in the symbol table.
//
void CgenClassTable::install_classes(Classes cs)
{
	for (int i = cs->first(); cs->more(i); i = cs->next(i)) {
		install_class(new CgenNode(cs->nth(i),CgenNode::NotBasic,this));
	}
}

//
// Add this CgenNode to the class list and the lookup table
//
void CgenClassTable::install_class(CgenNode *nd)
{
	Symbol name = nd->get_name();

	if (probe(name))
		return;

	// The class name is legal, so add it to the list of classes
	// and the symbol table.
	nds = new List<CgenNode>(nd,nds);
	addid(name,nd);
}

//
// Add this CgenNode to the special class list and the lookup table
//
void CgenClassTable::install_special_class(CgenNode *nd)
{
	Symbol name = nd->get_name();

	if (probe(name))
		return;

	// The class name is legal, so add it to the list of special classes
	// and the symbol table.
	special_nds = new List<CgenNode>(nd, special_nds);
	addid(name,nd);
}

//
// CgenClassTable::build_inheritance_tree
//
void CgenClassTable::build_inheritance_tree()
{
	for(List<CgenNode> *l = nds; l; l = l->tl())
		set_relations(l->hd());
}

//
// CgenClassTable::set_relations
//
// Takes a CgenNode and locates its, and its parent's, inheritance nodes
// via the class table.  Parent and child pointers are added as appropriate.
//
void CgenClassTable::set_relations(CgenNode *nd)
{
	CgenNode *parent_node = probe(nd->get_parent());
	nd->set_parentnd(parent_node);
	parent_node->add_child(nd);
}

// Get the root of the class tree.
CgenNode *CgenClassTable::root()
{
	return probe(Object);
}

//////////////////////////////////////////////////////////////////////
//
// Special-case functions used for the method Int Main::main() for
// MP2-1 only.
//
//////////////////////////////////////////////////////////////////////

#ifndef MP3

CgenNode* CgenClassTable::getMainmain(CgenNode* c)
{
	if (c && ! c->basic())
		return c;                   // Found it!

	List<CgenNode> *children = c->get_children();
	for (List<CgenNode> *child = children; child; child = child->tl()) {
		if (CgenNode* foundMain = this->getMainmain(child->hd()))
			return foundMain;   // Propagate it up the recursive calls
	}

	return 0;                           // Make the recursion continue
}

#endif

//-------------------------------------------------------------------
//
// END OF PREDEFINED FUNCTIONS
//
//-------------------------------------------------------------------


///////////////////////////////////////////////////////////////////////////////
//
// coding string, int, and boolean constants
//
// Cool has three kinds of constants: strings, ints, and booleans.
// This section defines code generation for each type.
//
// All string constants are listed in the global "stringtable" and have
// type stringEntry.  stringEntry methods are defined both for string
// constant definitions and references.
//
// All integer constants are listed in the global "inttable" and have
// type IntEntry.  IntEntry methods are defined for Int
// constant definitions and references.
//
// Since there are only two Bool values, there is no need for a table.
// The two booleans are represented by instances of the class BoolConst,
// which defines the definition and reference methods for Bools.
//
///////////////////////////////////////////////////////////////////////////////

//
// Create global definitions for constant Cool objects
//
void CgenClassTable::code_constants()
{
#ifdef MP3
//CgenEnvironment* env = new CgenEnvironment(*(this->ct_stream), root());

//ValuePrinter vp(*(env->cur_stream));
//int i = stringtable.len();


stringtable.code_string_table(*this->ct_stream, this);

	// ADD CODE HERE
#endif
}

// generate code to define a global string constant
void StringEntry::code_def(ostream& s, CgenClassTable* ct)
{
#ifdef MP3
ValuePrinter vp(s);
op_arr_type type_array(INT8, this->get_len()+1);
op_arr_type type_array_ptr(INT8_PTR, this->get_len()+1);
const_value strConstant(type_array, std::string(this->get_string()), true);
std::string head = "str.";
head = head + std::to_string(this->index);
vp.init_constant(head, strConstant);

string fin = "String." + std::to_string(this->index);

s << "@" << fin << " = constant  %String {";
s << "\n";
s << "\t";
s << "%String_vtable* @String_vtable_prototype";
s << ",\n";
s << "\t";
s << "i8* getelementptr (" << type_array.get_name() + "," + type_array.get_name() + "*" << " @";
s	<< head << ", i32 0, i32 0)";

s << "\n}\n\n";


global_value global_operand(op_type("String*"), fin);
ct->string_global.push_back(global_operand);
ct->string_name.push_back(this->get_string());
/*vector<op_type> str_types;
vector<const_value> str_constants;

op_type String_vtable_head("String_vtable*");
str_types.push_back(String_vtable_head);
const_value String_vtable_global_const(String_vtable_head, "@String_vtable_global", false);


str_constants.push_back(String_vtable_global_const);


str_types.push_back(op_type(INT8_PTR));
std::string get_element_handle("@" + head);
const_value get_element_handle_const(type_array, get_element_handle, false);
str_constants.push_back(get_element_handle_const);

std::string fin = "String." + std::to_string(this->index);
global_value string_global(op_type("String"), fin);

vp.init_struct_constant(string_global, str_types, str_constants);*/
	// ADD CODE HERE
#endif
}

// generate code to define a global int constant
void IntEntry::code_def(ostream& s, CgenClassTable* ct)
{
	// Leave this method blank, since we are not going to use global
	// declarations for int constants.
}

//////////////////////////////////////////////////////////////////////////////
//
//  CgenClassTable methods
//
//////////////////////////////////////////////////////////////////////////////

//
// CgenClassTable constructor orchestrates all code generation
//
CgenClassTable::CgenClassTable(Classes classes, ostream& s)
: nds(0)
{
	if (cgen_debug) std::cerr << "Building CgenClassTable" << endl;
	ct_stream = &s;
	// Make sure we have a scope, both for classes and for constants
	enterscope();

	// Create an inheritance tree with one CgenNode per class.
	install_basic_classes();
	install_classes(classes);
	build_inheritance_tree();

  if (cgen_debug) std::cerr << "Building CgenClassTable 2" << endl;
	// First pass
	setup();

  //if (cgen_debug) std::cerr << "Building CgenClassTable 3" << endl;
	// Second pass
	code_module();

  //if (cgen_debug) std::cerr << "Building CgenClassTable 4" << endl;
	// Done with code generation: exit scopes
	exitscope();

}

CgenClassTable::~CgenClassTable()
{
}

// The code generation first pass.  Define these two functions to traverse
// the tree and setup each CgenNode
void CgenClassTable::setup()
{

	setup_external_functions();


  setup_classes(root(), 0);
}


void CgenClassTable::setup_classes(CgenNode *c, int depth)
{
	// MAY ADD CODE HERE
	// if you want to give classes more setup information

	c->setup(current_tag++, depth);
	List<CgenNode> *children = c->get_children();
	for (List<CgenNode> *child = children; child; child = child->tl()){
    if (cgen_debug) std::cerr << "setup" << endl;
		setup_classes(child->hd(), depth + 1);
}
	c->set_max_child(current_tag-1);

	/*
	if (cgen_debug)
		std::cerr << "Class " << c->get_name() << " assigned tag "
			<< c->get_tag() << ", max child " << c->get_max_child()
			<< ", depth " << c->get_depth() << endl;
	*/
}


// The code generation second pass. Add code here to traverse the tree and
// emit code for each CgenNode
void CgenClassTable::code_module()
{
	code_constants();

#ifndef MP3
	// This must be after code_module() since that emits constants
	// needed by the code() method for expressions
	CgenNode* mainNode = getMainmain(root());
	mainNode->codeGenMainmain(*ct_stream);
#endif
	code_main();

#ifdef MP3
	code_classes(root());
#else
#endif
}


#ifdef MP3
void CgenClassTable::code_classes(CgenNode *c)
{

  c->code_class();
  for(List<CgenNode> * child = c->get_children(); child; child = child->tl()){
    code_classes(child->hd());
  }
	// ADD CODE HERE

}
#endif


//
// Create LLVM entry point. This function will initiate our Cool program
// by generating the code to execute (new Main).main()
//
void CgenClassTable::code_main()
{

	// Define a function main that has no parameters and returns an i32

#ifndef MP3
	ValuePrinter printer(*ct_stream);
	string inputString = "Main.main() returned %d\n";
	op_arr_type inputTypeArray(INT8, inputString.length()+1);
	const_value inputConst(inputTypeArray, inputString, false);
	printer.init_constant(".str", inputConst);
	vector<operand> mainArgs;
	printer.define(op_type(INT32), "main", mainArgs);

	vector<op_type> mainArgsTypes;


	// Define an entry basic block
	printer.begin_block("entry");

	// Call Main_main(). This returns int* for phase 1, Object for phase 2
	operand result = printer.call(mainArgsTypes, op_type(INT32), "Main_main",
	true, mainArgs);


	// Get the address of the string "Main_main() returned %d\n" using
	// getelementptr



	//op_arr_type inputPTRTypeArray(INT8_PTR, inputString.length()+1);

	global_value globalInputString(inputTypeArray.get_ptr_type(), ".str", inputConst);

	operand address = printer.getelementptr(inputTypeArray ,globalInputString, int_value(0), int_value(0), op_type(INT8_PTR));

	// Call printf with the string address of "Main_main() returned %d\n"
	// and the return value of Main_main() as its arguments

	vector<op_type> printfArgsTypes;
  vector<operand> printfArgs;
	printfArgs.push_back(address);
	printfArgs.push_back(result);
	printfArgsTypes.push_back(op_type(INT8_PTR));
	printfArgsTypes.push_back(op_type(VAR_ARG));
	operand callprintf = printer.call(printfArgsTypes, op_type(INT32),
  				"printf", true, printfArgs);
	// Insert return 0
	printer.ret(int_value(0));
	printer.end_define();

#else
	// Phase 2

ostream &o = *ct_stream;
ValuePrinter vp(*ct_stream);
o << "define i32 @main() {";

vp.begin_block("entry");

vector<op_type> main_arg_types;
vector<operand> main_args;
//op_type no_op_type;
//operand no_op;
//main_arg_types.push_back(no_op_type);
//main_args.push_back(no_op);

op_type main_ptr_type("Main*");

//operand main_operand = vp.alloca_mem(op_type("Main"));
//main_args.push_back(main_operand);
//main_arg_types.push_back(main_ptr_type);

operand mainNewOut = vp.call( main_arg_types, op_type("Main*"), "Main_new", true, main_args);

vector<operand> main_ret_args;
vector<op_type> main_ret_args_types;
main_ret_args.push_back(mainNewOut);
main_ret_args_types.push_back(op_type("Main*"));

op_type main_ret_type = this->mainReturn;
//CgenNode* mainNode = envSymbol("Main")
operand main_ret_operand(main_ret_type,"main.returnValue");

vp.call(*ct_stream, main_ret_args_types, "Main_main", true, main_ret_args, main_ret_operand);

int_value oprd_zero(0);
vp.ret(oprd_zero);

vp.end_define();
#endif

}


///////////////////////////////////////////////////////////////////////
//
// CgenNode methods
//
///////////////////////////////////////////////////////////////////////

void CgenNode::add_method(Symbol type, Symbol name){
	this->method_types.push_back(type);
	this->method_types.push_back(name);
}


CgenNode::CgenNode(Class_ nd, Basicness bstatus, CgenClassTable *ct)
: class__class((const class__class &) *nd),
  parentnd(0), children(0), basic_status(bstatus), class_table(ct), tag(-1)
{
	// ADD CODE HERE
}

void CgenNode::add_child(CgenNode *n)
{
	children = new List<CgenNode>(n,children);
}

void CgenNode::set_parentnd(CgenNode *p)
{
	assert(parentnd == NULL);
	assert(p != NULL);
	parentnd = p;
}


void CgenNode::create_vtable(){
	ValuePrinter vp(*(this->class_table->ct_stream));

	string str_const_name = "str." + string(name->get_string());
	op_arr_type str_arr_type(INT8, string(name->get_string()).length() + 1);
	op_arr_type str_arr_ptr_type(INT8_PTR, string(name->get_string()).length() + 1);
	const_value const_operand(str_arr_type, string(name->get_string()), true);
	vp.init_constant(str_const_name, const_operand);

	global_value global_operand(str_arr_ptr_type, str_const_name);

//if (cgen_debug) std::cerr << "feature1" << endl;
	vp.type_define(string(name->get_string()), this->feature_attribute_types);

	vector<op_type> vtable_types;
	vtable_types.push_back(op_type(INT32));
	vtable_types.push_back(op_type(INT32));
	vtable_types.push_back(op_type(INT8_PTR));
	for(int i = 0; i < this->vtable_types.size(); i++){
		vtable_types.push_back(this->vtable_types[i]);
	}
	vp.type_define(string(name->get_string()) + "_vtable", vtable_types);

//if (cgen_debug) std::cerr << "feature2" << endl;
	ostream &o = *this->class_table->ct_stream;

  string output_string_one = "@" + string(name->get_string()) + "_vtable_prototype = constant %"
  + name->get_string() + "_vtable {";
  o << output_string_one;
  o << "\n";

	global_value global_vtable_operand(op_type(string(name->get_string()) + "_vtable*"),
							string(name->get_string()) + "_vtable_prototype");

	//this->class_table->map_class_name.push_back(str_class_name);
	//this->class_table->map_global.push_back(oprd_const_global);
//if (cgen_debug) std::cerr << "feature3" << endl;
  o << "\t";
	o << "i32 " << this->tag;
  o << ",\n";

	string output_string_two = "i32 ptrtoint (%" + string(name->get_string()) + "* getelementptr (%" + name->get_string() +
                          + ", %" + name->get_string() + "* null, i32 1) to i32)";

  o << "\t";
	o << output_string_two;
  o << ",\n";

  string output_string_three = "i8* getelementptr (" + str_arr_type.get_name() + "," + str_arr_type.get_name() + "* @"
  + str_const_name + ", i32 0, i32 0)";
  o << "\t";
	o << output_string_three;
  o << ",\n";

	o << "\t";

  string output_string_four = "%" + string(name->get_string()) + "* () * @" + string(name->get_string()) + "_new";

o << output_string_four;



   string tempString;


	for(int i = 1; i < this->vtable_original_types.size(); i++){
  //    if (cgen_debug) std::cerr <<this->vtable_names.size()<< endl;
  //      if (cgen_debug) std::cerr <<this->vtable_types.size() << endl;
    //      if (cgen_debug) std::cerr << this->vtable_original_types.size() << endl;

		string str_vtable_name = this->vtable_names[i];
		string str_vtable_type = this->vtable_types[i].get_name();
		string str_original_type = this->vtable_original_types[i].get_name();



      o << ",\n\t";

      tempString = str_vtable_type + " bitcast (" + str_original_type
      + " @" + str_vtable_name + " to " + str_vtable_type + ")";

    o << tempString;
    }

for(int i = this->vtable_original_types.size(); i < this->vtable_types.size(); i++)

    {

      string str_vtable_name = this->vtable_names[i];
  		string str_vtable_type = this->vtable_types[i].get_name();
      o << ",\n\t";

      tempString = str_vtable_type + " @" + str_vtable_name;
      o << tempString;



	}


o << "\n}\n\n";


  this->class_table->string_name.push_back(string(name->get_string()));
	this->class_table->string_global.push_back(global_vtable_operand);
}

//
// Class setup.  You may need to add parameters to this function so that
// the classtable can provide setup information (such as the class tag
// that should be used by this class).
//
// Things that setup should do:
//  - layout the features of the class
//  - create the types for the class and its vtable
//  - create global definitions used by the class such as the class vtable
//
void CgenNode::setup(int tag, int depth)
{this->depth = depth;
	this->tag = tag;
#ifdef MP3
  std::string name_str(this->get_type_name());
  string vtable_ptr_str = name_str + "_vtable*";
  string pointer_to_this_class_str = name_str + "*";

   op_type vtable_ptr_type(vtable_ptr_str);

   this->feature_attribute_names.push_back("__vtable_ptr__");
   this->feature_attribute_types.push_back(vtable_ptr_type);

   //if (cgen_debug) std::cerr << "setup_feature" << endl;
   if(depth >0){
      for(int i=1; i < this->parentnd->feature_attribute_names.size(); i++){
        //TODO:not sure if needed


        this->feature_attribute_names.push_back(this->parentnd->feature_attribute_names[i]);
        this->feature_attribute_types.push_back(this->parentnd->feature_attribute_types[i]);
      }


   }


   vector<op_type> new_args;
  // new_args.push_back(op_type(pointer_to_this_class_str));
   op_func_type new_func_type(op_type(pointer_to_this_class_str), new_args);
   this->vtable_names.push_back(name_str+"_new");
   this->vtable_types.push_back(new_func_type);
   this->return_self_type.push_back(false);

   //if (cgen_debug) std::cerr << "setup_feature" << endl;

    this->vtable_original_types.push_back(new_func_type);
    this->vtable_original_owner.push_back(this->get_type_name());

   if(depth > 0){


     string parent_name = this->parentnd->get_type_name();
     for(int i = 1; i < this->parentnd->vtable_names.size(); i++){
       op_type new_result_type;

       if(this->parentnd->return_self_type[i] == true)
       {
         new_result_type = op_type(this->get_type_name(), 1);

       }else {
         new_result_type = this->parentnd->vtable_types[i].get_result_type();
         //self_vtable_entry = this->parentnd->vtable_types[i];
       }
       vector <op_type> new_arg_types;
       vector<op_type> temp_arg_types = this->parentnd->vtable_types[i].get_arg_types();
       for(int j =0; j< temp_arg_types.size(); j++){
          if(temp_arg_types[j].get_name() == "%" + this->parentnd->get_type_name() + "*"){
            new_arg_types.push_back(op_type(this->get_type_name() , 1));
          }else{
            new_arg_types.push_back(temp_arg_types[j]);
          }
       }

       op_func_type self_vtable_entry = op_func_type(new_result_type, new_arg_types);


       this->vtable_names.push_back(this->parentnd->vtable_names[i]);
       this->vtable_types.push_back(self_vtable_entry);
       this->return_self_type.push_back(this->parentnd->return_self_type[i]);

       if(i < this->parentnd->vtable_original_types.size())
       {this->vtable_original_types.push_back(this->parentnd->vtable_original_types[i]);

       }
       else {
        this->vtable_original_types.push_back(this->parentnd->vtable_types[i]);
       }

       this->vtable_original_owner.push_back(this->parentnd->vtable_original_owner[i]);
     }
   }

   	layout_features();
    create_vtable();

//TODO:check if really need such inheritance....append to feature
//REALY IMPORTANT

  /*  for(int i = this->parentnd->features->first(); this->parentnd->features->more(i);
    i = this->parentnd->features->next(i)){
      if(typeid(this->parentnd->features->nth(i)) == typeid(attr_class) ){
          this->features =
           list_node<Feature>.append(list_node<Feature>.single(this->parentnd->features->nth(i)),
           this->features);
      }
    }*/

#endif
}

#ifdef MP3
//
// Class codegen. This should performed after every class has been setup.
// Generate code for each method of the class.
//



void CgenNode::code_class()
{
  //if (cgen_debug) std::cerr << "hello" << endl;
	// No code generation for basic classes. The runtime will handle that.
	if (basic())
		return;
    //if (cgen_debug) std::cerr << "hello2" << endl;
  CgenEnvironment *env = new CgenEnvironment(*(this->get_stream()), this);
  ValuePrinter vp(*(env->cur_stream));
  env->coding_methods = true;
  for(int i = features->first(); features->more(i); i = features->next(i)){
//    env->var_table();
    //if (cgen_debug) std::cerr << "hello3" << endl;

    features->nth(i)->code(env);
//    env->kill_local();
  }


//constructor
  op_type pointer_to_this_class_type(this->get_type_name() + "*");
  vector<operand> args;
//  args.push_back(operand(pointer_to_this_class_type, "this"));
  vp.define(pointer_to_this_class_type, this->get_type_name() + "_new", args);
  vp.begin_block("entry");

//get load_operand as int
op_type class_vtable_type(this->get_type_name() + "_vtable");
  op_type class_vtable_type_ptr(this->get_type_name() + "_vtable*");
  global_value class_vtable_operand(class_vtable_type_ptr, this->get_type_name()+ "_vtable_prototype");
//TODO: check one and zero index here

//ValuePrinter vp(* env->cur_stream);
//op_type class_vtable_type(string(type_name->get_string()) + "_vtable");
//op_type class_vtable_type_ptr(string(type_name->get_string()) + "_vtable*");
//global_value class_vtable_operand(class_vtable_type_ptr, string(type_name->get_string()) + "_vtable_prototype");
operand vtable_operand = vp.getelementptr(class_vtable_type ,class_vtable_operand, int_value(0), int_value(1), op_type(INT32_PTR));
operand load_operand = vp.load(op_type(INT32), vtable_operand);
vector<op_type> malloc_types;
vector<operand> malloc_args;
malloc_types.push_back(op_type(INT32));
malloc_args.push_back(load_operand);
operand call_malloc_operand = vp.call(malloc_types, op_type(INT8_PTR), "malloc", true, malloc_args);
//operand bitcastToClass = vp.bitcast(call_malloc_operand, op_type(string(this->get_type_name()) + "*")) ;
operand bitcastToClass = conform(call_malloc_operand, op_type(string(this->get_type_name()) + "*"), env) ;
//vector<op_type> arg_types;
//arg_types.push_back(op_type(string(type_name->get_string()) + "*"));
//vector<operand> args;
//args.push_back(bitcastToClass);
//vp.call(arg_types, VOID, string(type_name->get_string()) + "_init", true, args);

//return bitcastToClass;


//operand mallocOutput = operand(pointer_to_this_class_type, "this");
//operand bitcastToClass = vp.getelementptr(pointer_to_this_class_type.get_deref_type(), mallocOutput, int_value(0), int_value(1), op_type(INT32_PTR));



//env->pointer_to_this_class = bitcastToClass;

//if (cgen_debug) std::cerr << "hello" << endl;
//if (cgen_debug) std::cerr << bitcastToClass.get_typename() << endl;


  op_type pointer_pointer_to_class_vtable_type(this->get_type_name() + "_vtable**");
  //operand * pointer_pointer_to_class_vtable = new operand(vp.getelementptr(bitcastToClass,
  //  int_value(0), int_value(0), pointer_pointer_to_class_vtable_type));
  operand pointer_pointer_to_class_vtable = vp.getelementptr(op_type(this->get_type_name()), bitcastToClass, int_value(0), int_value(0), pointer_pointer_to_class_vtable_type);
  vp.store(class_vtable_operand, pointer_pointer_to_class_vtable);
  //TODO: alloca and new???
   //operand *alloca_operand = new operand(vp.alloca_mem(pointer_to_this_class_type));
   //vp.store(bitcastToClass, *alloca_operand);
   //alloca???
//   env->add_local(Symbol(self), bitcastToClass);

  op_type class_ptr_ptr_type(this->get_type_name() + "**");
  operand class_ptr_ptr = vp.alloca_mem(pointer_to_this_class_type);

  vp.store(bitcastToClass,class_ptr_ptr);
env->add_local(self, class_ptr_ptr);
//env->pointer_to_this_class = &class_ptr_ptr;
//  env->add_local(self, bitcastToClass);

  env->coding_methods = false;

//vp.begin_block("hello1");
//TODO:check correctness, initialize inherited objects
  for(int j = this->depth; j > 0; j --){
    CgenNode * cur = this;
    for(int i = 0; i<j; i++){
      cur = cur->parentnd;
    }
//    env->add_local(self, class_ptr_ptr);
    for(int k = cur->features->first(); cur->features->more(k); k = cur->features->next(k)){
    //  env->add_local(self, class_ptr_ptr);
    //  vp.begin_block("hello1");
      cur->features->nth(k)->code(env);
      //vp.begin_block("hello2");
      //env->kill_local();
    }
  //  env->kill_local();
  }

  for(int i = features->first(); features->more(i); i = features->next(i)){
  //  vp.begin_block("hello1");
    features->nth(i)->code(env);
  //  vp.begin_block("hello2");
  }

//vp.begin_block("hello2");

  env->kill_local();
  vp.ret(bitcastToClass);

  vp.begin_block("abort");
  vector<op_type> abort_types;
  vector<operand> abort_args;
  operand abort_call = vp.call(abort_types, op_type(VOID), "abort", true, abort_args);

  vp.unreachable();
  vp.end_define();

	// ADD CODE HERE
}

// Laying out the features involves creating a Function for each method
// and assigning each attribute a slot in the class structure.
void CgenNode::layout_features()
{
	int temp = features->first();
	while(features->more(temp)){
  //  if (cgen_debug) std::cerr << "feature1" << endl;
		features->nth(temp)->layout_feature(this);
		temp = features->next(temp);

	}
  //if (cgen_debug) std::cerr << "feature2" << endl;
	// ADD CODE HERE
}
#else

//
// code-gen function main() in class Main
//
void CgenNode::codeGenMainmain(std::ostream &stm)
{
	//TODO:CTSTREAM?
	ValuePrinter vp(stm);
	// In Phase 1, this can only be class Main. Get method_class for main().
	assert(std::string(this->name->get_string()) == std::string("Main"));
	method_class* mainMethod = (method_class*) features->nth(features->first());

	// ADD CODE HERE TO GENERATE THE FUNCTION int Mainmain().
	// Generally what you need to do are:
	// -- setup or create the environment, env, for translating this method
	// -- invoke mainMethod->code(env) to translate the method
	CgenEnvironment *env = new CgenEnvironment(stm, this);
	vector<operand> mainArgs;
	vp.define(op_type(INT32), "Main_main", mainArgs);
	vp.begin_block("entry");
	mainMethod->code(env);
	vp.end_define();

}

#endif

//
// CgenEnvironment functions
//

//
// Class CgenEnvironment should be constructed by a class prior to code
// generation for each method.  You may need to add parameters to this
// constructor.
//
CgenEnvironment::CgenEnvironment(std::ostream &o, CgenNode *c)
{
	cur_class = c;
	cur_stream = &o;
	var_table.enterscope();
	//TODO: NEGA ONE?
	tmp_count = block_count = ok_count = 0;
	// ADD CODE HERE
}

// Look up a CgenNode given a symbol
CgenNode *CgenEnvironment::type_to_class(Symbol t) {
	return t == SELF_TYPE ? get_class()
		: get_class()->get_classtable()->lookup(t);
}

// Provided CgenEnvironment methods
// Generate unique string names
std::string CgenEnvironment::new_name() {
	std::stringstream s;
	s << tmp_count++;
	return "tmp." + s.str();
}

std::string CgenEnvironment::new_ok_label() {
	std::stringstream s;
	s << ok_count++;
	return "ok." + s.str();
}
const std::string CgenEnvironment::new_label(const std::string& prefix,
		bool increment) {
	std::string suffix = itos(block_count);
	block_count += increment;
	return prefix + suffix;
}

void CgenEnvironment::add_local(Symbol name, operand &vb) {
	var_table.enterscope();
	var_table.addid(name, &vb);
}

void CgenEnvironment::kill_local() {
	var_table.exitscope();
}


////////////////////////////////////////////////////////////////////////////
//
// APS class methods
//
////////////////////////////////////////////////////////////////////////////

//******************************************************************
//
//   Fill in the following methods to produce code for the
//   appropriate expression.  You may add or remove parameters
//   as you wish, but if you do, remember to change the parameters
//   of the declarations in `cool-tree.handcode.h'.
//
//*****************************************************************

#ifdef MP3
// conform and get_class_tag are only needed for MP3

// conform - If necessary, emit a bitcast or boxing/unboxing operations
// to convert an object to a new type. This can assume the object
// is known to be (dynamically) compatible with the target type.
// It should only be called when this condition holds.
// (It's needed by the supplied code for typecase)
operand conform(operand src, op_type type, CgenEnvironment *env) {
  ValuePrinter vp(*(env->cur_stream));
//box

	if (cgen_debug) std::cerr << "conform" << endl;

if(string(src.get_type().get_name()) != string(type.get_name())){
operand output = src;

  if(string(src.get_type().get_name()) == string(op_type(INT32).get_name())||
    string(src.get_type().get_name()) == string(op_type(INT1).get_name()))
    //&&  string(type.get_name()) == string(op_type("Object*").get_name())
{
    op_type returnType;

    if(string(src.get_type().get_name()) == string(op_type(INT32).get_name()))
{
  returnType = op_type("Int*");
  vector<operand> args;
  vector<op_type> arg_types;
  string funName =  "Int_new";
  operand intOutput = vp.call(arg_types, returnType, funName, true, args);

  vector<operand> args2;
  vector<op_type> arg_types2;

  args2.push_back(intOutput);
  arg_types2.push_back(returnType);
  args2.push_back(src);
  arg_types2.push_back(src.get_type());
  string funName2 =  "Int_init";
  operand intOutput2 = vp.call(arg_types2, op_type(VOID), funName2, true, args2);
  output = intOutput;

}
else{
  returnType = op_type("Bool*");
  vector<operand> args;
  vector<op_type> arg_types;
  string funName =  "Bool_new";
  operand intOutput = vp.call(arg_types, returnType, funName, true, args);

  vector<operand> args2;
  vector<op_type> arg_types2;

  args2.push_back(intOutput);
  arg_types2.push_back(returnType);
  args2.push_back(src);
  arg_types2.push_back(src.get_type());
  string funName2 =  "Bool_init";
  operand intOutput2 = vp.call(arg_types2, op_type(VOID), funName2, true, args2);
  output = intOutput;
}

  }
else if(type.get_name() == op_type(INT32).get_name() || type.get_name() == op_type(INT1).get_name()){


    if(type.get_name() == op_type(INT32).get_name()){
      if(src.get_type().get_name() == op_type("Object*").get_name()){
        src = vp.bitcast(src, op_type("Int*"));
      }

    operand vtable_operand = vp.getelementptr(src.get_type().get_deref_type() , src, int_value(0), int_value(1), op_type(INT32_PTR));
    output = vp.load(type, vtable_operand);
  }else{

      if(src.get_type().get_name() == op_type("Object*").get_name()){
        src = vp.bitcast(src, op_type("Bool*"));
      }
    operand vtable_operand = vp.getelementptr(src.get_type().get_deref_type() , src, int_value(0), int_value(1), op_type(INT1_PTR));
    output = vp.load(type, vtable_operand);
  }
  return output;
  }
  //std::cerr << "hello2" << endl;
  //std::cerr << type.get_name() << endl;
  output = vp.bitcast(output, type);

  // ADD CODE HERE (MP3 ONLY)
	return output;
}
return src;
}
// Retrieve the class tag from an object record.
// src is the object we need the tag from.
// src_class is the CgenNode for the *static* class of the expression.
// You need to look up and return the class tag for it's dynamic value
operand get_class_tag(operand src, CgenNode *src_cls, CgenEnvironment *env) {
	// ADD CODE HERE (MP3 ONLY)
  string name = src_cls->get_type_name();
    ValuePrinter vp(* env->cur_stream);

  operand getElementOut = vp.getelementptr(src.get_type().get_deref_type(), src, int_value(0),
  int_value(0), op_type(src_cls->get_type_name()+ "_vtable**") );
 //std::cerr <<  "hello1"<< endl;
  operand vtable_ptr = vp.load( op_type(src_cls->get_type_name()+ "_vtable*"), getElementOut);
  //std::cerr <<  "hello2"<< endl;
  operand funcResult = vp.getelementptr(vtable_ptr.get_type().get_deref_type(), vtable_ptr,
    int_value(0), int_value(0), op_type(INT32_PTR));
/*

  ValuePrinter vp(* env->cur_stream);
  op_type class_vtable_type(name + "_vtable");
  op_type class_vtable_type_ptr(name + "_vtable*");
  global_value class_vtable_operand(class_vtable_type_ptr, name+ "_vtable_prototype");
operand vtable_operand = vp.getelementptr(class_vtable_type ,class_vtable_operand, int_value(0), int_value(0), op_type(INT32_PTR));
*/
  operand load_operand = vp.load(op_type(INT32), funcResult);
  return load_operand;
}
#endif

//
// Create a method body
//
void method_class::code(CgenEnvironment *env)
{

	if (cgen_debug) std::cerr << "method" << endl;
  if(!(env->coding_methods))
    return;
  ValuePrinter printer(*(env->cur_stream));

  string fir = string(return_type->get_string());
  op_type temp;
  if(fir == "SELF_TYPE"){
   temp = op_type(env->get_class()->get_type_name(), 1);
    //return temp;
  }
  else if(fir == "Bool" || fir == "bool"){
   temp = op_type(INT1);
    //return temp;
  }
  else if(fir == "Int" || fir == "int"){
   temp = op_type(INT32);
    //return temp;
  }
  else {
   temp = op_type(fir + "*");
  //return temp;
  }

  op_type return_type = temp;
  string function_name = string(env->get_class()->get_type_name()) + "_" + string(name->get_string());

  vector<operand> new_operand_vec;
  env->formal_operands = new_operand_vec;
  vector<string> new_name_vec;
  env->formal_names = new_name_vec;


  op_type class_type(env->get_class()->get_type_name(),1);
  operand self_operand(class_type, "self");


//  vector<operand> function_arguments;
//  vector<Symbol> symbol_vec;
  env->formal_operands.push_back(self_operand);
  //symbol_vec.push_back(self);
  env->formal_names.push_back("self");

//TODO: do we really need symbol vec???
  for(int x = formals->first(); formals->more(x); x = formals->next(x)){
    op_type formal_type(env->get_class()->convertType(this->formals->nth(x)->get_type_decl()->get_string()));
    operand formal_operand(formal_type, string(this->formals->nth(x)->get_name()->get_string()));
    //env->formal_operands.push_back(self_operand);
    //function_arguments.push_back(formal_operand);
    //symbol_vec.push_back(this->formals->nth(x)->get_name());
    env->formal_operands.push_back(formal_operand);
    env->formal_names.push_back(this->formals->nth(x)->get_name()->get_string());
  }

  ValuePrinter vp(* env->cur_stream);
  vp.define(return_type, function_name, env->formal_operands);

  vp.begin_block("entry");

  for(size_t i =0; i< env->formal_operands.size(); i++){
    // if (cgen_debug) std::cerr << env->formal_operands[i].get_type().get_name() << endl;
    operand alloc_result = vp.alloca_mem(env->formal_operands[i].get_type());


/*
    if(string(env->formal_names[i]->get_string()) == "self"){
      //TODO: check pptr error

      op_type ptrType(alloc_result.get_type());
      ptrType.set_id(OBJ_PPTR);
      alloc_result = operand(ptrType, alloc_result.get_name().substr(1));
    //  if (cgen_debug) std::cerr << "heloo" << endl;
    }
    //env->add_local(symbol_vec[i], alloc_result);
*/
    vp.store(env->formal_operands[i], alloc_result);
    env->formal_operands[i] = alloc_result;
  //  if (cgen_debug) std::cerr << env->lookup(self) << endl;
  }
   //if (cgen_debug) std::cerr << env->lookup(self)<< endl;
  operand output = expr->code(env);
  if(output.get_type().get_name()!= return_type.get_name()){
    output = conform(output, return_type, env);
    //output = vp.bitcast(output, return_type);

  }
  vp.ret(output);


  //printer.ret(expr->code(env));
	printer.begin_block("abort");
	vector<op_type> argTypes;
	vector<operand> args;
	operand call = printer.call(argTypes, VOID, "abort", true, args);
	printer.unreachable();
  vp.end_define();

	// ADD CODE HERE

}

//
// Codegen for expressions.  Note that each expression has a value.
//

operand assign_class::code(CgenEnvironment *env)
{
	if (cgen_debug) std::cerr << "assign" << endl;
	// ADD CODE HERE AND REPLACE "return operand()" WITH SOMETHING
	// MORE MEANINGFUL
	ValuePrinter printer(*(env->cur_stream));

  operand realAssignment;
	operand * assignment = env->lookup(name);
  if(assignment){
    realAssignment = *assignment;
  }
  else {
    int formal_index= env->get_formal_index(this->name->get_string());

    if(formal_index >= 0){
      realAssignment = env->formal_operands[formal_index];
    }

else{

  operand self_ptr_operand = env->formal_operands[0];

//  operand self_operand = vp.load(self_ptr_operand.get_type().get_deref_type(), self_ptr_operand);

  int attribute_index = env->get_class()->get_attribute_index(name->get_string());
  op_type attribute_type = env->get_class()->feature_attribute_types[attribute_index];

  operand self_operand = printer.load(self_ptr_operand.get_type().get_deref_type(),   self_ptr_operand);
  if(attribute_index >= 0){
    //TODO: chceck attribute pointer
  //  std::cerr << self_operand.get_typename() << endl;
    operand attribute_pointer = printer.getelementptr(self_operand.get_type().get_deref_type(),
     self_operand, int_value(0), int_value(attribute_index), attribute_type.get_ptr_type());

    realAssignment = attribute_pointer;

  }
   else {
    std::cerr << "assign_class_not_found" << endl;
  }
}
}
operand exprOp = expr->code(env);
  op_type dereferenced_assignment_type = realAssignment.get_type().get_deref_type();
  //std::cerr << "hello1" << endl;
    //std::cerr << dereferenced_assignment_type.get_name() << endl;
  if(dereferenced_assignment_type.get_name() != exprOp.get_type().get_name()){
  operand fin = conform(exprOp, dereferenced_assignment_type, env);
  printer.store(fin, realAssignment);
  return exprOp;
}

else{
	printer.store(exprOp, realAssignment);
	return exprOp;
}
}

operand cond_class::code(CgenEnvironment *env)
{

	if (cgen_debug) std::cerr << "cond" << endl;
	// ADD CODE HERE AND REPLACE "return operand()" WITH SOMETHING
	// MORE MEANINGFUL

	ValuePrinter printer(*(env->cur_stream));
	operand reg;
	string typeString = string(then_exp->get_type()->get_string());
	//op_type type;

  /*
	if(typeString.compare("Int") == 0){
		type = INT32;
	} else if(typeString.compare("Bool") == 0){
		type = INT1;
	}
  */
  op_type type = env->get_class()->convertType(typeString);
   //if (cgen_debug) std::cerr << env->formal_operands[i].get_type().get_name() << endl;
	reg = printer.alloca_mem(type);
	string label1 = env->new_label("condTrue.", true);
  string label2 = env->new_label("condFalse.", true);
	string label3 = env->new_label("end.", true);

	operand predOp = pred->code(env);


	//operand reg;
	printer.branch_cond(predOp, label1, label2);
	printer.begin_block(label1);
	operand ifOp = then_exp->code(env);
  //type = ifOp.get_type();

	printer.store(ifOp, reg);

	printer.branch_uncond(label3);


	printer.begin_block(label2);
  operand elseOp = else_exp->code(env);
	//type = ifOp.get_type();
	//reg = printer.alloca_mem(type);
	printer.store(elseOp, reg);
	printer.branch_uncond(label3);

	printer.begin_block(label3);
	operand output = printer.load(type, reg);
	return output;
}

operand loop_class::code(CgenEnvironment *env)
{
	if (cgen_debug) std::cerr << "loop" << endl;
	ValuePrinter printer(*(env->cur_stream));

	string label2 = env->new_label("true.", true);
  string label3 = env->new_label("false.", true);
	string label1 = env->new_label("loop.", true);
	printer.branch_uncond(label1);
	printer.begin_block(label1);
	operand predOp = pred->code(env);

	printer.branch_cond(predOp, label2, label3);
	printer.begin_block(label2);
	operand output = body->code(env);
 //TODO:output zero as initial value?????
	printer.branch_uncond(label1);
	printer.begin_block(label3);
	return output;

	// ADD CODE HERE AND REPLACE "return operand()" WITH SOMETHING
	// MORE MEANINGFUL
}

operand block_class::code(CgenEnvironment *env)
{
	if (cgen_debug) std::cerr << "block" << endl;
	// ADD CODE HERE AND REPLACE "return operand()" WITH SOMETHING
	// MORE MEANINGFUL
	int i = 0;
  operand output;
	while(body->more(i)){
		output = body->nth(i)->code(env);
		i++;
	}
	return output;
}
operand default_value(op_type type){
  if(type.get_id() == INT1){
		bool_value temp(false, false);
		return temp;
	}else if(type.get_id() == INT32){
		int_value temp(0);
		return temp;
	}else{
		// Phase 2:
		null_value temp(type);
		return temp;
	}
}

operand let_class::code(CgenEnvironment *env)
{
	if (cgen_debug) std::cerr << "let" << endl;
	ValuePrinter printer(*(env->cur_stream));
	string iden = identifier->get_string();
	string td = type_decl->get_string();
	op_type type = env->get_class()->convertType(td);
	/*if(td.compare("Int") == 0){
		type = INT32;
	} else if(td.compare("Bool") == 0){
		type = INT1;
	}*/
	operand initOp = init->code(env);

  //	if (cgen_debug) std::cerr << "let-hello" << endl;
    //	if (cgen_debug) std::cerr << type.get_name() << endl;
  if(string(initOp.get_type().get_name()) != "" &&string(initOp.get_type().get_name()) != string(type.get_name()) )
    initOp = conform(initOp, type, env);
    //initOp = printer.bitcast(initOp, type);
	operand allocOp = printer.alloca_mem(type);




	operand idenOp = operand(type, iden);

	env->add_local(identifier, allocOp);

	if(!(initOp.get_type().get_id() == EMPTY)) {
		printer.store(initOp, allocOp);}
		else{
		string emptyOutPut;
    /*
		if(type.get_id() == INT32){
			emptyOutPut = "0";
		}else if(type.get_id() == INT1){
			emptyOutPut = "false";
		}*/
		//operand tempOp = const_value(type, emptyOutPut, true);
    operand tempOp = default_value(type);
    printer.store(tempOp, allocOp);
	}

  operand op_let = body->code(env);
  env->kill_local();
	// ADD CODE HERE AND REPLACE "return operand()" WITH SOMETHING
	// MORE MEANINGFUL
	return op_let;
}

operand plus_class::code(CgenEnvironment *env)
{
	if (cgen_debug) std::cerr << "plus" << endl;
	// ADD CODE HERE AND REPLACE "return operand()" WITH SOMETHING
	// MORE MEANINGFUL
	ValuePrinter printer(*(env->cur_stream));
	operand first = e1->code(env);
	operand second = e2->code(env);

  conform(first, op_type(INT32), env);
  conform(second, op_type(INT32), env);
  operand output = printer.add(first, second);
  //conform(output, op_type("Int*"), env);
	return output;
}

operand sub_class::code(CgenEnvironment *env)
{
	if (cgen_debug) std::cerr << "sub" << endl;
	// ADD CODE HERE AND REPLACE "return operand()" WITH SOMETHING
	// MORE MEANINGFUL
	ValuePrinter printer(*(env->cur_stream));
	operand first = e1->code(env);
	operand second = e2->code(env);
  conform(first, op_type(INT32), env);
  conform(second, op_type(INT32), env);
	operand output = printer.sub(first, second);
  //conform(output, op_type("Int*"), env);
	return output;
}

operand mul_class::code(CgenEnvironment *env)
{
	if (cgen_debug) std::cerr << "mul" << endl;
	// ADD CODE HERE AND REPLACE "return operand()" WITH SOMETHING
	// MORE MEANINGFUL
	ValuePrinter printer(*(env->cur_stream));
	operand first = e1->code(env);
	operand second = e2->code(env);
  conform(first, op_type(INT32), env);
  conform(second, op_type(INT32), env);
	operand output = printer.mul(first, second);
  //conform(output, op_type("Int*"), env);
	return output;
}

operand divide_class::code(CgenEnvironment *env)
{
	if (cgen_debug) std::cerr << "div" << endl;
	// ADD CODE HERE AND REPLACE "return operand()" WITH SOMETHING
	// MORE MEANINGFUL
	ValuePrinter printer(*(env->cur_stream));
	operand first = e1->code(env);
	operand second = e2->code(env);
  conform(first, op_type(INT32), env);
  conform(second, op_type(INT32), env);
	operand testZero = printer.icmp(EQ, second, int_value(0));
	string tempBlock = env->new_name();
	//TODO:TEMPBLOCK????
	printer.branch_cond(testZero, "abort", tempBlock);

	printer.begin_block(tempBlock);
	operand output = printer.div(first, second);
  //conform(output, op_type("Int*"), env);
	return output;
}

operand neg_class::code(CgenEnvironment *env)
{
	if (cgen_debug) std::cerr << "neg" << endl;
	ValuePrinter printer(*(env->cur_stream));
	operand first = e1->code(env);
  conform(first, op_type(INT32), env);
	// ADD CODE HERE AND REPLACE "return operand()" WITH SOMETHING
	// MORE MEANINGFUL
	operand output = printer.sub(int_value(0), first);
  //conform(output, op_type("Int*"), env);
	return output;
}

operand lt_class::code(CgenEnvironment *env)
{
	if (cgen_debug) std::cerr << "lt" << endl;
	// ADD CODE HERE AND REPLACE "return operand()" WITH SOMETHING
	// MORE MEANINGFUL
	ValuePrinter printer(*(env->cur_stream));
	operand first = e1->code(env);
	operand second = e2->code(env);
  conform(first, op_type(INT32), env);
  conform(second, op_type(INT32), env);
	operand output = printer.icmp(LT, first, second);
  //conform(output, op_type("Bool*"), env);
	return output;
}

operand eq_class::code(CgenEnvironment *env)
{
	if (cgen_debug) std::cerr << "eq" << endl;
	// ADD CODE HERE AND REPLACE "return operand()" WITH SOMETHING
	// MORE MEANINGFUL
	ValuePrinter printer(*(env->cur_stream));
	operand first = e1->code(env);
	operand second = e2->code(env);
  if(string(first.get_type().get_name()) ==  string(op_type("Int*").get_name())){
  first = conform(first, op_type(INT32), env);
  second = conform(second, op_type(INT32), env);
}else if(string(first.get_type().get_name()) ==  string(op_type("Bool*").get_name())){
  first = conform(first, op_type(INT1), env);
  second = conform(second, op_type(INT1), env);
}
if(string(first.get_type().get_name()) !=  string(op_type(INT32).get_name())
  && string(first.get_type().get_name()) !=  string(op_type(INT1).get_name())){
    first = conform(first, op_type(INT8_PTR), env);
    second = conform(second, op_type(INT8_PTR), env);
  }


	operand output = printer.icmp(EQ, first, second);
//  conform(output, op_type("Bool*"), env);
	return output;
}

operand leq_class::code(CgenEnvironment *env)
{
	if (cgen_debug) std::cerr << "leq" << endl;
	// ADD CODE HERE AND REPLACE "return operand()" WITH SOMETHING
	// MORE MEANINGFUL
	ValuePrinter printer(*(env->cur_stream));


	operand first = e1->code(env);

	operand second = e2->code(env);
  conform(first, op_type(INT32), env);
  conform(second, op_type(INT32), env);
	operand output = printer.icmp(LE, first, second);
  //conform(output, op_type("Bool*"), env);
	return output;
}

operand comp_class::code(CgenEnvironment *env)
{
	if (cgen_debug) std::cerr << "complement" << endl;
	// ADD CODE HERE AND REPLACE "return operand()" WITH SOMETHING
	// MORE MEANINGFUL
	ValuePrinter printer(*(env->cur_stream));
  operand first = e1->code(env);
  conform(first, op_type(INT1), env);
	/*
	string tempBlockTrue = env->new_name();
	string tempBlockFalse = env->new_name();

	printer.branch_cond(first, tempBlockTrue, tempBlockFalse);

	//TODO: Correct Branch?
	printer.begin_block(tempBlockTrue);
	bool_value output(false, false);
	return output;

	printer.begin_block(tempBlockFalse);
	bool_value output(true, false);
	*/
	operand output = printer.xor_in(first, bool_value(true, true));
  //conform(output, op_type("Bool*"), env);
	return output;
}

operand int_const_class::code(CgenEnvironment *env)
{
	if (cgen_debug) std::cerr << "Integer Constant" << endl;
	// ADD CODE HERE AND REPLACE "return operand()" WITH SOMETHING
	// MORE MEANINGFUL

	int_value output(atoi(token->get_string()));

	return output;
}

operand bool_const_class::code(CgenEnvironment *env)
{
	if (cgen_debug) std::cerr << "Boolean Constant" << endl;
	// ADD CODE HERE AND REPLACE "return operand()" WITH SOMETHING
	// MORE MEANINGFUL
  bool_value output(val,false);
//  operand boxOutput = conform(output, op_type("Bool*"), env);

	return output;
}

int CgenNode::get_attribute_index(string name){
    for(int i =0; i< this->feature_attribute_names.size(); i++){
      if(this->feature_attribute_names[i] == name){
        return i;
      }
    }
    return -1;
}

int CgenNode::get_vtable_index(string name){
    for(int i =0; i< this->vtable_names.size(); i++){
      if(this->vtable_names[i] == name){
        return i;
      }
    }
    return -1;
}

int CgenEnvironment::get_formal_index(string name){
  for(int i =0; i< this->formal_names.size(); i++){
    if(this->formal_names[i] == name){
      return i;
    }
  }
  return -1;
}

operand object_class::code(CgenEnvironment *env)
{
	if (cgen_debug) std::cerr << "Object" << endl;
	// ADD CODE HERE AND REPLACE "return operand()" WITH SOMETHING
	// MORE MEANINGFUL

  // ADD CODE HERE AND REPLACE "return nothing" WITH SOMETHING MORE MEANINGFUL
	ValuePrinter vp(*env->cur_stream);

  operand load_operand;

	operand *object_id= env->lookup(this->name);
 //if (cgen_debug) std::cerr << "test1"<< endl;
	if(object_id){

  //    if (cgen_debug) std::cerr << "??" << endl;
    //if (cgen_debug) std::cerr << string(this->name->get_string()) << endl;
    //if (cgen_debug) std::cerr << object_id->get_type().get_id() << endl;


		load_operand = vp.load(object_id->get_type().get_deref_type(), *object_id);
    if (cgen_debug) std::cerr << string(load_operand.get_type().get_name()) << endl;
    if (cgen_debug) std::cerr << load_operand.get_type().get_id() << endl;

    //if (cgen_debug) std::cerr << "??" << endl;
//		return load_operand;
}else{

//if (cgen_debug) std::cerr << "test2"<< endl;
  string this_name(this->name->get_string());
  int formal_index = env->get_formal_index(this_name);
  if(formal_index >= 0){
  //  if (cgen_debug) std::cerr << "test3"<< endl;
    operand formal_operand = env->formal_operands[formal_index];
//    if (cgen_debug) std::cerr << formal_operand.get_type().get_name()<< endl;
  //if (cgen_debug) std::cerr << formal_operand.get_type().get_id()<< endl;
    load_operand = vp.load(formal_operand.get_type().get_deref_type(), formal_operand);
    //return load_operand;

  } else {
//if (cgen_debug) std::cerr << "test3"<< endl;
  	//if (cgen_debug) std::cerr << "test2" << endl;
  //TODO:separate local and p
  //operand self_ptr = env->pointer_to_this_class;
  operand self_ptr;
  //  if(temp_ptr == nullptr)
  operand *cur_self_ptr = env->lookup(self);

  if(cur_self_ptr != 0)
    {
      //self_ptr = vp.load(cur_self_ptr.get_type().get_deref_type(), cur_self_ptr);
      self_ptr = *cur_self_ptr;
    }
  else
    self_ptr = env->formal_operands[0];
  //else
  //  self_ptr = *(temp_ptr);

  //operand self_ptr = *(env->lookup(self));
	//if (cgen_debug) std::cerr << "test3" << endl;
	operand operand_self = vp.load( self_ptr.get_type().get_deref_type(), self_ptr);


	int attr_index = env->get_class()->get_attribute_index(this->name->get_string());



	if(attr_index >= 0){

		op_type attr_type = env->get_class()->feature_attribute_types[attr_index];

		operand attr_ptr = vp.getelementptr(operand_self.get_type().get_deref_type(), operand_self, int_value(0), int_value(attr_index), attr_type.get_ptr_type());

		 load_operand = vp.load(attr_type, attr_ptr);
	//	return load_operand;

  }else{
    return operand();
  }
}
	}


return load_operand;
}




operand no_expr_class::code(CgenEnvironment *env)
{
	if (cgen_debug) std::cerr << "No_expr" << endl;
	// ADD CODE HERE AND REPLACE "return operand()" WITH SOMETHING
	// MORE MEANINGFUL
	return operand();
}

//*****************************************************************
// The next few functions are for node types not supported in Phase 1
// but these functions must be defined because they are declared as
// methods via the Expression_SHARED_EXTRAS hack.
//*****************************************************************

operand static_dispatch_class::code(CgenEnvironment *env)
{
	if (cgen_debug) std::cerr << "static dispatch" << endl;
#ifndef MP3
	assert(0 && "Unsupported case for phase 1");
#else
ValuePrinter vp(*env->cur_stream);
vector<op_type> arg_types;
vector<operand> args;
op_type result_type;
//string fun= string(type_name->get_string()) + "_" + string(name->get_string());
int i = 0;
operand output;
while(actual->more(i)){
  output = actual->nth(i)->code(env);
  i++;
  args.push_back(output);
  //arg_types.push_back(output.get_type());
  //TODO:record during exxecution?
}
operand result = expr->code(env);

operand testZero = vp.icmp(EQ, result, null_value(result.get_type()));
string tempBlock = env->new_name();
vp.branch_cond(testZero, "abort", tempBlock);
vp.begin_block(tempBlock);

if (cgen_debug) std::cerr << result.get_type().get_name()<< endl;
args.insert(args.begin(), result);

//arg_types.insert(arg_types.begin(), op_type(string(type_name->get_string()) + "*") );
//may have error
//env->add_local(self, result);
CgenNode* tempClass = env->type_to_class(type_name);

//operand getElementOut = vp.getelementptr(result.get_type().get_deref_type(), result, int_value(0),
//int_value(0), op_type(string(type_name->get_string())+ "_vtable**") );
//std::cerr <<  "hello1"<< endl;
//operand vtable_ptr = vp.load( op_type(string(type_name->get_string())+ "_vtable*"), getElementOut);
//std::cerr <<  "hello2"<< endl;
string fun;
int indix = 0;
for(int i = tempClass->vtable_names.size()-1; i >= 0; i--){
  if(tempClass->vtable_original_owner[i] + "_" + string(name->get_string()) == tempClass->vtable_names[i] ){
    fun= tempClass->vtable_names[i];
    indix = i;
    break;
  }
}
/*
for(int i =0; i<tempClass->vtable_names.size(); i++){
  if(fun == tempClass->vtable_names[i]){
    indix = i;
    break;
  }
}
*/
global_value beta_proto(op_type(string(type_name->get_string())+"_vtable*"), string(type_name->get_string())+"_vtable_prototype");
operand funcResult = vp.getelementptr(beta_proto.get_type().get_deref_type(), beta_proto,
  int_value(0), int_value(indix+3), tempClass->vtable_types[indix].get_ptr_type());

ostream &o = *env->cur_stream;
operand func(tempClass->vtable_types[indix],env->new_name());
vp.load(o, tempClass->vtable_types[indix], funcResult, func);
//std::cerr << tempClass->vtable_types[indix].get_name() << endl;
//std::cerr <<  "hello4"<< endl;
vector<op_type> formal_target = tempClass->vtable_types[indix].get_arg_types();

for(int i =0; i < args.size(); i++){
  if(
    string(args[i].get_type().get_name()) != string(formal_target[i].get_name()))
  //  if (cgen_debug) std::cerr << string(formal_target[i].get_name()) << endl;
    args[i] = conform(args[i], formal_target[i], env);
    //args[i] = vp.bitcast(args[i], formal_target[i]);
   arg_types.push_back(formal_target[i]);
}

operand realoutput = vp.call(arg_types, tempClass->vtable_types[indix].get_result_type(), func.get_name().substr(1), false, args);
//realoutput = conform(realoutput, op_type(string(result.get_type().get_name()) + "*"),env);
if (cgen_debug) std::cerr << result.get_type().get_name()<< endl;
if(tempClass->return_self_type[indix]){
  realoutput = conform(realoutput, result.get_type(),env);
  //realoutput = vp.bitcast(realoutput, op_type(string(tempClass->get_type_name()) + "*"));
}




//operand realoutput = vp.call(arg_types, result_type, fun, true, args);




return realoutput;






  // ADD CODE HERE AND REPLACE "return operand()" WITH SOMETHING
	// MORE MEANINGFUL
#endif
	return operand();
}

operand string_const_class::code(CgenEnvironment *env)
{
	if (cgen_debug) std::cerr << "string_const" << endl;
#ifndef MP3
	assert(0 && "Unsupported case for phase 1");
#else


string temp = string(this->token->get_string());
int result = -1;
for(int i = 0; i < env->get_class()->get_classtable()->string_name.size(); i++){
		if(env->get_class()->get_classtable()->string_name[i] == temp){
			result = i;
		}
	}

if(result >= 0){
  return env->get_class()->get_classtable()->string_global[result];
}else{
  return operand();
}

	// ADD CODE HERE AND REPLACE "return operand()" WITH SOMETHING
	// MORE MEANINGFUL
#endif
	return operand();
}

operand dispatch_class::code(CgenEnvironment *env)
{
	if (cgen_debug) std::cerr << "dispatch" << endl;
#ifndef MP3
	assert(0 && "Unsupported case for phase 1");
#else
	// ADD CODE HERE AND REPLACE "return operand()" WITH SOMETHING
	// MORE MEANINGFUL

  ValuePrinter vp(*env->cur_stream);
  vector<op_type> arg_types;
  vector<operand> args;
  op_type result_type;

  int i = 0;
  operand output;
  //vp.begin_block("hello");
  while(actual->more(i)){
    output = actual->nth(i)->code(env);
    i++;
    args.push_back(output);
  //  arg_types.push_back(output.get_type());
    //TODO:record during exxecution?
  }
  //vp.begin_block("hello2");
  operand result = expr->code(env);

Symbol tempType = expr->get_type();
  if(string(result.get_type().get_name()) == string(op_type(INT32).get_name()) ){
   result = conform(result, op_type("Int*"), env);
   tempType = Symbol("Int");
}else if(string(result.get_type().get_name()) == string(op_type(INT1).get_name()) ){
   result = conform(result, op_type("Bool*"), env);
   tempType = Symbol("Bool");
} else{

  operand testZero = vp.icmp(EQ, result, null_value(result.get_type()));

  string tempBlock = env->new_name();
  vp.branch_cond(testZero, "abort", tempBlock);
  vp.begin_block(tempBlock);
}
  //Symbol tempType;
  CgenNode* tempClass = env->type_to_class(expr->get_type());

  int indix = 0;
  for(int i = tempClass->vtable_names.size()-1; i >= 0; i--){
    if(tempClass->vtable_original_owner[i] + "_" + string(name->get_string()) == tempClass->vtable_names[i] ){
      indix = i;
      break;
    }
  }
//  string fun= tempClass->vtable_names[indix];
  args.insert(args.begin(), result);
  //arg_types.insert(arg_types.begin(), result.get_type());
  //may have error
  //env->add_local(self, result);
  //std::cerr <<  result.get_type().get_name()<< endl;
  operand getElementOut = vp.getelementptr(result.get_type().get_deref_type(), result, int_value(0),
  int_value(0), op_type(tempClass->get_type_name()+ "_vtable**") );
 //std::cerr <<  "hello1"<< endl;
  operand vtable_ptr = vp.load( op_type(tempClass->get_type_name()+ "_vtable*"), getElementOut);
  //std::cerr <<  "hello2"<< endl;
  operand funcResult = vp.getelementptr(vtable_ptr.get_type().get_deref_type(), vtable_ptr,
    int_value(0), int_value(indix+3), tempClass->vtable_types[indix].get_ptr_type());
  //std::cerr <<  "hello3"<< endl;
  ostream &o = *env->cur_stream;
  operand func(tempClass->vtable_types[indix],env->new_name());
  vp.load(o, tempClass->vtable_types[indix], funcResult, func);
  //std::cerr << tempClass->vtable_types[indix].get_name() << endl;
  //std::cerr <<  "hello4"<< endl;
  vector<op_type> formal_target = tempClass->vtable_types[indix].get_arg_types();
  for(int i =0; i < args.size(); i++){
    if(string(args[i].get_type().get_name()) != string(formal_target[i].get_name()))
      args[i] = conform(args[i], formal_target[i], env);
    //  args[i] = vp.bitcast(args[i], formal_target[i]);
    arg_types.push_back(formal_target[i]);
  }

  operand realoutput = vp.call(arg_types, tempClass->vtable_types[indix].get_result_type(), func.get_name().substr(1), false, args);
    //std::cerr <<  "hello5"<< endl;
  /*CgenNode* tempClass = env->type_to_class(op_type(result->get_type_name()));
  for(int i =0; i<tempClass.vtable_names.size(); i++){
    if(fun == tempClass.vtable_names[i]){
      if(tempClass->return_self_type[i]){
        realoutput = vp.bitcast(realoutput, op_type(tempClass->get_typename() + "*"));
      }

      break;
    }
  }*/



  return realoutput;
#endif
	return operand();
}

operand typcase_class::code(CgenEnvironment *env) {
    if (cgen_debug)
        std::cerr << "typecase::code()" << endl;
#ifndef MP3
    assert(0 && "Unsupported case for phase 1");
#else
    ValuePrinter vp(*env->cur_stream);
    CgenClassTable *ct = env->get_class()->get_classtable();

    string header_label = env->new_label("case.hdr.", false);
    string exit_label = env->new_label("case.exit.", false);

    // Generate code for expression to select on, and get its static type
    operand code_val = expr->code(env);
    operand expr_val = code_val;
    string code_val_t = code_val.get_typename();
    op_type join_type = env->type_to_class(type)->get_type_name();
    CgenNode *cls = env->type_to_class(expr->get_type());

    // Check for case on void, which gives a runtime error
    if (code_val.get_type().get_id() != INT32_PTR && code_val.get_type().get_id() != INT1_PTR) {
        op_type bool_type(INT1), empty_type;
        null_value null_op(code_val.get_type());
        operand icmp_result(bool_type, env->new_name());
        vp.icmp(*env->cur_stream, EQ, code_val, null_op, icmp_result);
        string ok_label = env->new_ok_label();
        vp.branch_cond(icmp_result, "abort", ok_label);
	vp.begin_block(ok_label);
    }

    operand tag = get_class_tag(expr_val, cls, env);
    vp.branch_uncond(header_label);
    string prev_label = header_label;
    vp.begin_block(header_label);

    // Get result type of case expression
    branch_class *b = (branch_class *)cases->nth(cases->first());
    string case_result_type = b->get_expr()->get_type()->get_string();
    if (case_result_type == "SELF_TYPE")
        case_result_type = env->get_class()->get_type_name();

    // Allocate space for result of case expression
    op_type alloca_type(case_result_type, 1);
    operand alloca_final(alloca_type, env->new_name());
    env->branch_operand = alloca_final;
    vp.alloca_mem(*env->cur_stream, alloca_type, alloca_final);

    std::vector<operand> values;
    env->next_label = exit_label;

    // Generate code for the branches
    for (int i=ct->get_num_classes()-1; i >= 0; --i) {
        for (int j=cases->first(); cases->more(j); j = cases->next(j)) {
            if (i == ct->lookup(cases->nth(j)->get_type_decl())->get_tag()) {
                string prefix = string("case.") + itos(i) + ".";
                string case_label = env->new_label(prefix, false);
                vp.branch_uncond(case_label);
		vp.begin_block(case_label);
                operand val = cases->nth(j)->code(expr_val, tag,
                                                  join_type, env);
                values.push_back(val);
            }
        }
    }

    // Abort if there was not a branch covering the actual type
    vp.branch_uncond("abort");

    // Done with case expression: get final result
    env->new_label("", true);
    vp.begin_block(exit_label);
    operand final_result(alloca_type, env->new_name());
    alloca_final.set_type(alloca_final.get_type().get_ptr_type());
    vp.load(*env->cur_stream, alloca_final.get_type().get_deref_type(), alloca_final,
            final_result);
    alloca_final.set_type(alloca_final.get_type().get_deref_type());

    if (cgen_debug)
        cerr << "Done typcase::code()" << endl;
    return final_result;
#endif
}


operand new__class::code(CgenEnvironment *env)
{
	if (cgen_debug) std::cerr << "newClass" << endl;
#ifndef MP3
	assert(0 && "Unsupported case for phase 1");
#else


//string funcName = type_name->get_string();
vector<op_type> arg_types;
vector<operand> args;
//  malloc_types.push_back(op_type(INT32));
//  malloc_args.push_back(src);
ValuePrinter vp(*env->cur_stream);

//CgenNode* tempClass = env->type_to_class(type_name);
//operand result( op_type(string(type_name->get_string()) + "*"), env->new_name() );
//operand getElementOut = vp.getelementptr(result.get_type().get_deref_type(), result, int_value(0),
//int_value(0), op_type(string(type_name->get_string())+ "_vtable**") );
//std::cerr <<  "hello1"<< endl;
//operand vtable_ptr = vp.load( op_type(string(type_name->get_string())+ "_vtable*"), getElementOut);
//std::cerr <<  "hello2"<< endl;
//operand funcResult = vp.getelementptr(vtable_ptr.get_type().get_deref_type(), vtable_ptr,
//  int_value(0), int_value(3), tempClass->vtable_types[0].get_ptr_type());

//ostream &o = *env->cur_stream;
//operand func(tempClass->vtable_types[0],env->new_name());
//vp.load(o, tempClass->vtable_types[0], funcResult, func);
//std::cerr << tempClass->vtable_types[indix].get_name() << endl;
//std::cerr <<  "hello4"<< endl;
//operand realoutput = vp.call(arg_types, tempClass->vtable_types[0].get_result_type(), func.get_name().substr(1), false, args);
string func = string(type_name->get_string()) + "_new";
operand realoutput = vp.call(arg_types, op_type(string(type_name->get_string()) + "*"), func, true, args);
//operand call_malloc_operand = vp.call(malloc_types, op_type(string(type_name->get_string())+"*"), funcName, true, malloc_args);
return realoutput;
	// ADD CODE HERE AND REPLACE "return operand()" WITH SOMETHING
	// MORE MEANINGFUL
#endif
	return operand();
}

operand isvoid_class::code(CgenEnvironment *env)
{
	if (cgen_debug) std::cerr << "isvoid" << endl;
#ifndef MP3
	assert(0 && "Unsupported case for phase 1");
#else
//REALLY NOT SURE IF I SHOULD DO THIS
    ValuePrinter vp(* env->cur_stream);
    operand result = e1->code(env);
    //operand output(bool_type, env->new_name());
    operand output = vp.icmp(EQ, result, null_value(result.get_type()));
    return output;
    //if(result.get_type().get_name() == op_type(VOID).get_name()){
    //  return bool_value(true, false);
    //}else{
    //  return bool_value(false, false);
    //}
	// ADD CODE HERE AND REPLACE "return operand()" WITH SOMETHING
	// MORE MEANINGFUL
#endif
	return operand();
}

// Create the LLVM Function corresponding to this method.
void method_class::layout_feature(CgenNode *cls)
{
#ifndef MP3
	assert(0 && "Unsupported case for phase 1");
#else
if (cgen_debug) std::cerr << "method.feature"<< endl;
//TODO: check basic type
//std::cerr << name->get_string()<< endl;
if(string(name->get_string()) == "main"){
  //std::cerr << "hello"<< endl;
  cls->get_classtable()->mainReturn = cls->convertType(string(return_type->get_string()));
  //if (cgen_debug) std::cerr << return_type->get_string() << endl;

}

string class_name = cls->get_type_name();
op_type class_ptr(class_name + "*");
operand self_operand(class_ptr, "self");

vector <op_type> temp_formals;
temp_formals.push_back(class_ptr);

int temp = formals->first();
while(formals->more(temp)){
	//TODO:check better type!!
	op_type tempType(cls->convertType(formals->nth(temp)->get_type_decl()->get_string()));
	temp_formals.push_back(tempType);
	//operand tempOperand(tempType, this->formals->nth_length(temp)->get_name()->get_string());
	temp = formals->next(temp);
}

//cls->add_method(return_type, name);


op_type vtable_return_type(cls->convertType(return_type->get_string()));
op_func_type vtable_function_type(vtable_return_type, temp_formals);

cls->vtable_types.push_back(vtable_function_type);
//cls->vtable_return_types.push_back(return_type);

std::string vtable_function_name = cls->get_type_name();
vtable_function_name += "_";
vtable_function_name += name->get_string();

cls->vtable_names.push_back(vtable_function_name);

if(string(return_type->get_string()) == "SELF_TYPE")
{
  cls->return_self_type.push_back(true);
}else{
  cls->return_self_type.push_back(false);
}
cls->vtable_original_owner.push_back(cls->get_type_name());
//cls->vtable_original_types.push_back(vtable_function_type);


//op_type vtable_function_global_type(vtable_function_name);
//global_value vtable_global(vtable_function_global_type, vtable_function_name);

//TODO: necessary to keep those const???
//const_value vtable_const(vtable_function_global_type, vtable_function_name, false);
//cls->vtable_const_types.push_back(vtable_const);

	// ADD CODE HERE


#endif
}

// If the source tag is >= the branch tag and <= (max child of the branch class) tag,
// then the branch is a superclass of the source
operand branch_class::code(operand expr_val, operand tag,
                           op_type join_type, CgenEnvironment *env) {
#ifndef MP3
    assert(0 && "Unsupported case for phase 1");
#else
    operand empty;
    ValuePrinter vp(* env->cur_stream);
    if  (cgen_debug)
        cerr << "In branch_class::code()" << endl;

    CgenNode *cls = env->get_class()->get_classtable()->lookup(type_decl);
    int my_tag = cls->get_tag();
    int max_child = cls->get_max_child();

    // Generate unique labels for branching into >= branch tag and <= max child
    string sg_label =
        env->new_label(string("src_gte_br") + "." + itos(my_tag) + ".", false);
    string sl_label =
        env->new_label(string("src_lte_mc") + "." + itos(my_tag) + ".", false);
    string exit_label =
        env->new_label(string("br_exit") + "." + itos(my_tag) + ".", false);

    int_value my_tag_val(my_tag);
    op_type old_tag_t(tag.get_type()), i32_t(INT32);
    tag.set_type(i32_t);

    // Compare the source tag to the class tag
    operand icmp_result = vp.icmp(LT, tag, my_tag_val);
    vp.branch_cond(icmp_result, exit_label, sg_label);
    vp.begin_block(sg_label);
    int_value max_child_val(max_child);

    // Compare the source tag to max child
    operand icmp2_result = vp.icmp(GT, tag, max_child_val);
    vp.branch_cond(icmp2_result, exit_label, sl_label);
    vp.begin_block(sl_label);
    tag.set_type(old_tag_t);

    // Handle casts of *arbitrary* types to Int or Bool.  We need to:
    // (a) cast expr_val to boxed type (struct Int* or struct Bool*)
    // (b) unwrap value field from the boxed type
    // At run-time, if source object is not Int or Bool, this will never
    // be invoked (assuming no bugs in the type checker).
    if (cls->get_type_name() == "Int" || cls->get_type_name() == "Bool") {
        op_type lbl_t(cls->get_type_name(), 1);
        expr_val = conform(expr_val, lbl_t, env);
    }

    // If the case expression is of the right type, make a new local
    // variable for the type-casted version of it, which can be used
    // within the expression to evaluate on this branch.
    op_type alloc_type(cls->get_type_name(), 1);
    operand alloc_op = vp.alloca_mem(alloc_type);
    operand conf_result = conform(expr_val, alloc_type,  env);
    vp.store(conf_result, alloc_op);
    env->add_local(name, alloc_op);

    // Generate code for the expression to evaluate on this branch
    operand val = conform(expr->code(env), join_type.get_ptr_type(), env);
    operand conformed = conform(val, env->branch_operand.get_type(), env);
    env->branch_operand.set_type(env->branch_operand.get_type()
                                                    .get_ptr_type());
    // Store result of the expression evaluated
    vp.store(conformed, env->branch_operand);
    env->branch_operand.set_type(env->branch_operand.get_type()
                                                    .get_deref_type());
    env->kill_local();
    // Branch to case statement exit label
    vp.branch_uncond(env->next_label);
    vp.begin_block(exit_label);
    if (cgen_debug)
        cerr << "Done branch_class::code()" << endl;
    return conformed;
#endif
}
/*
op_type CgenNode::convertTypePtr(string fir){
	if(fir == "SELF_TYPE"){
		op_type temp(this->get_type_name());
		return temp;
	}
	else if(fir == "Bool" || fir == "bool"){
		op_type temp(INT1_PTR);
		return temp;
	}
	else if(fir == "Int" || fir == "int"){
		op_type temp(INT32_PTR);
		return temp;
	}
	else if(fir == "sbyte*" || fir == "String" ){
		op_type temp(INT8_PPTR);
		return temp;
	}
	op_type temp(fir + "*");
	return temp;
}*/

op_type CgenNode::convertTypeNoString(string fir){
	if(fir == "SELF_TYPE"){
		op_type temp(this->get_type_name() + "*");
		return temp;
	}
	else if(fir == "Bool" || fir == "bool"){
		op_type temp(INT1);
		return temp;
	}
	else if(fir == "Int" || fir == "int"){
		op_type temp(INT32);
		return temp;
	}
	else if(fir == "sbyte*" || fir == "String" ){
		op_type temp(INT8_PTR);
    //op_type temp("String*");
		return temp;
	}
	op_type temp(fir + "*");
	return temp;
}

op_type CgenNode::convertType(string fir){
	if(fir == "SELF_TYPE"){
		op_type temp(this->get_type_name() + "*");
		return temp;
	}
	else if(fir == "Bool" || fir == "bool"){
		op_type temp(INT1);
		return temp;
	}
	else if(fir == "Int" || fir == "int"){
		op_type temp(INT32);
		return temp;
	}
	else if(fir == "sbyte*" || fir == "String" ){
		//op_type temp(INT8_PTR);
    op_type temp("String*");
		return temp;
	}
	op_type temp(fir + "*");
	return temp;
}

op_type CgenNode::convertTypeNoPtr(string fir){
	if(fir == "SELF_TYPE"){
		op_type temp(this->get_type_name());
		return temp;
	}
	else if(fir == "Bool" || fir == "bool"){
		op_type temp(INT1);
		return temp;
	}
	else if(fir == "Int" || fir == "int"){
		op_type temp(INT32);
		return temp;
	}
	else if(fir == "sbyte*" || fir == "String" ){
		//op_type temp(INT8_PTR);
    //op_type temp(INT8_PTR);
    op_type temp("String*");
    return temp;
	}
	op_type temp(fir);
	return temp;
}
// Assign this attribute a slot in the class structure
void attr_class::layout_feature(CgenNode *cls)
{
#ifndef MP3
	assert(0 && "Unsupported case for phase 1");
#else

 op_type attribute_type(cls->convertTypeNoString(type_decl->get_string()));
 cls->feature_attribute_types.push_back(attribute_type);
  cls->feature_attribute_names.push_back(name->get_string());
/*
  string temp = std::string(type_decl->get_string());
	if(temp == "Int" || temp == "Int"){
		cls->feature_attributes.push_back(op_type(INT32));
	}
	else if(temp == "sbyte*" || temp == "String"){
		cls->feature_attributes.push_back(op_type(INT8_PTR));
	}
	else if(temp == "Bool" || temp == "bool"){
		cls->feature_attributes.push_back(op_type(INT1));
	}
	//TODO: special for self_type??
	else if(temp == "SELF_TYPE"){
		cls->feature_attributes.push_back(op_type(temp));
	}
	else {
		cls->feature_attributes.push_back(op_type(temp + "*"));
	}
  */
//TODO: string as object???
//TODO: need an env???
//TODO: How do we do with init???
	// ADD CODE HERE
#endif
}




void attr_class::code(CgenEnvironment *env)
{
#ifndef MP3
	assert(0 && "Unsupported case for phase 1");
#else
if (cgen_debug) std::cerr << "attr_class"<< endl;
  if(env->coding_methods){
    return;
  /*  op_type type_decl_op_type(env->get_class()->convertTypePtr(type_decl->get_string()));
    operand nilOperand(type_decl_op_type, "nil");
    env->add_local(name, nilOperand);
*/
  }else {
    ValuePrinter vp(*(env->cur_stream));
    int attr_index = env->get_class()->get_attribute_index(this->name->get_string());
    op_type attr_type = env->get_class()->feature_attribute_types[attr_index];

    //vp.begin_block("hello");
    operand expression_operand = init->code(env);
    //vp.begin_block("hello2");
    //operand * selfInVarTable = env->lookup(self);

    if(expression_operand.get_name() == ""){
      expression_operand = default_value(attr_type);
    }
//vp.begin_block("hello");
    operand *class_ptr = env->lookup(self);
    operand real_class_ptr = vp.load(class_ptr->get_type().get_deref_type()   ,*class_ptr);
    operand operand_attribute = vp.getelementptr(real_class_ptr.get_type().get_deref_type() ,real_class_ptr, int_value(0), int_value(attr_index), attr_type.get_ptr_type());

    expression_operand = conform(expression_operand, operand_attribute.get_type().get_deref_type(), env);
    vp.store(expression_operand, operand_attribute);
  }

  //TODO: FIGURE OUT THE OFFSET OF OBJECT
	// ADD CODE HERE
#endif
}
