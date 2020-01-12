//
// This is the MP2 skeleton cgen header.  As given, it contains only basic
// functionality.  You will need to add members to each of the classes
// to get them to perform their desired functions.  Document your important
// design decisions below.  We should be able to read your documentation and
// get a general overview of how your compiler generates code.  For instance,
// how does your compiler generate structures for classes, how is inheritance
// modeled, how do you handle dynamic binding, etc.
//

// ------------------ INSERT DESIGN DOCUMENTATION HERE --------------------- //


// ----------------------------- END DESIGN DOCS --------------------------- //

#include "cool-tree.h"
#include "symtab.h"
#include "value_printer.h"

//
// CgenClassTable represents the top level of a Cool program, which is
// basically a list of classes.  The class table is used to look up classes
// (CgenNodes) by name, and it also handles global code generation tasks.
// The CgenClassTable constructor is where you'll find the entry point for
// code generation for an entire Cool program.
//
class CgenClassTable : public cool::SymbolTable<Symbol,CgenNode>
{
private:
	// Class list
	List<CgenNode> *nds;
	List<CgenNode> *special_nds;
	int current_tag;

#ifndef MP3
	CgenNode* getMainmain(CgenNode* c);
#endif

public:

	// The ostream where we are emitting code
	ostream *ct_stream;
	// CgenClassTable constructor begins and ends the code generation process
	CgenClassTable(Classes, ostream& str);
	~CgenClassTable();

	// Get the root of the class Tree, i.e. Object
	CgenNode *root();
	int get_num_classes() const	{ return current_tag; }
  op_type mainReturn = op_type("Object*");
	vector<string>string_name;
	vector<global_value> string_global;
private:
	// COMPLETE FUNCTIONS

	// Create declarations for C runtime functions we need to generate code
	void setup_external_functions();
	void setup_classes(CgenNode *c, int depth);

#ifdef MP3
	void code_classes(CgenNode *c);
#endif

	// The following creates an inheritance graph from a list of classes.
	// The graph is implemented as a tree of `CgenNode', and class names
	// are placed in the base class symbol table.
	void install_basic_classes();
	void install_class(CgenNode *nd);
	void install_special_class(CgenNode *nd);
	void install_classes(Classes cs);
	void build_inheritance_tree();
	void set_relations(CgenNode *nd);

	// INCOMPLETE FUNCTIONS

	// Setup each class in the table and prepare for code generation phase
	void setup();

	// Code generation functions. You need to write these functions.
	void code_module();
	void code_constants();
	void code_main();

	// ADD CODE HERE

};


//
// Each CgenNode corresponds to a Cool class.  As such, it is responsible for
// performing code generation on the class level.  This includes laying out
// the class attributes, creating the necessary Types for the class and
// generating code for each of its methods.
//
class CgenNode : public class__class
{
public:
	enum Basicness
	{ Basic, NotBasic };

#ifndef MP3
	void codeGenMainmain(std::ostream &o);
#endif

private:
	CgenNode *parentnd;                        // Parent of class
	List<CgenNode> *children;                  // Children of class
	Basicness basic_status;                    // `Basic' or 'NotBasic'
	CgenClassTable *class_table;

	// Class tag.  Should be unique for each class in the tree
	int tag;
	int max_child;


	// ADD CODE HERE


	//vector<op_type> return_types;
public:
		int depth;
	// COMPLETE FUNCTIONS
	vector<Symbol> method_types;
	vector<Symbol> method_names;

	vector<string> feature_attribute_names;
	vector<op_type> feature_attribute_types;
	//vector<const_value> vtable_const_types;
	//vector<const_type> vtable_values;
vector <op_func_type> vtable_types;
//	vector<op_type> vtable_types;
	//vector<op_type> vtable_return_types;
 	vector<string> vtable_names;
	vector<op_type> vtable_original_types;
	vector<string> vtable_original_owner;
	vector<op_type> vtable_return_types;
	vector<bool> return_self_type;
	//vector<operand>formal_operands;


	// Relationships with other nodes in the tree
 	CgenNode *get_parentnd() { return parentnd; }
	void add_child(CgenNode *child);
	void set_parentnd(CgenNode *p);
	int basic() { return (basic_status == Basic); }
	List<CgenNode> *get_children() { return children; }

	// Accessors for other provided fields
	int get_tag() const 	{ return tag; }
	CgenClassTable *get_classtable() { return class_table; }

	void set_max_child(int mc) 	{ max_child = mc; }
	int get_max_child() const 	{ return max_child; }
	int get_attribute_index(string name);
	int get_vtable_index(string name);
	// INCOMPLETE FUNCTIONS

	// Constructs a CgenNode from a Class
	CgenNode(Class_ c, Basicness bstatus, CgenClassTable *class_table);
	virtual ~CgenNode() { }

	// Class setup. You need to write the body of this function.
	void setup(int tag, int depth);

	// Class codegen. You need to write the body of this function.
	void code_class();

	// ADD CODE HERE
	string get_type_name() { return string(name->get_string()); }

	ostream* get_stream() { return this->get_classtable()->ct_stream; }

	void add_method(Symbol type, Symbol name);

	op_type convertType(string fir);
	op_type convertTypeNoString(string fir);
	op_type convertTypeNoPtr(string fir);

	void create_vtable();
private:
	// Layout the methods and attributes for code generation
	// You need to write the body of this function.
	void layout_features();

	// ADD CODE HERE

};

//
// CgenEnvironment provides the environment for code generation of a method.
// Its main task is to provide a mapping from Cool names to LLVM Values.
// This mapping needs to be maintained as scopes are entered and exited, new
// variables are declared, and so on. CgenEnvironment is also a good place
// to put non-local information you will need during code generation.  Two
// examples are the current CgenNode and the current Function.
//
class CgenEnvironment
{
private:
	// mapping from variable names to memory locations
	cool::SymbolTable<Symbol,operand> var_table;

	// Keep counters for unique name generation in the current method
	int block_count;
	int tmp_count;
	int ok_count;

	// ADD CODE HERE
	CgenNode *cur_class;


public:
	std::ostream *cur_stream;
	bool coding_methods;

	operand pointer_to_this_class;
	vector<operand> formal_operands;
  vector<string> formal_names;
	// fresh name generation functions
	string new_name();
	string new_ok_label();
	const string new_label(const std::string& prefix, bool increment);

	// Used in provided code for the (case..of) construct
	string next_label;
	operand branch_operand;
	void add_local(Symbol name, operand &vb);
	void kill_local();
	// end of helpers for provided code

	CgenEnvironment(ostream &strea, CgenNode *cur_class);

	int get_formal_index(string name);
	operand *lookup(Symbol name)	{ return var_table.lookup(name); }

	CgenNode *get_class() { return cur_class; }
	void set_class(CgenNode *c) { cur_class = c; }

	// INCOMPLETE FUNCTIONS

	// Must return the CgenNode for a class given the symbol of its name
	CgenNode *type_to_class(Symbol t);
	// ADD CODE HERE

};

// Utitlity function
// Generate any code necessary to convert from given operand to
// dest_type, assuing it has already been checked to be compatible
operand conform(operand src, op_type dest_type, CgenEnvironment *env);
// Retrieve the class tag from operand src. Argument is the cgen node for
// the static class of src.
operand get_class_tag(operand src, CgenNode *src_cls, CgenEnvironment *env);
