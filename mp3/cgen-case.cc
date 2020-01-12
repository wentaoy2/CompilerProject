//****************************************************************************
// 
// The MP3 handout explains (in Section 7, step 9) how code generation for 
// CASE statements works.  We have given you *most* of the code that implements
// this strategy, including:
// 1) code to compute CgenNode::max_child, the highest tag value of any
//    child class of the current class
// 2) typcase_class::code(), which generates code for the 'case' header
// 3) branch_class::code(), which generates code for a single branch of a 'case'
// (#1 was in the original MP2 handout.  #2 and #3 are below.)
// 
// WHAT YOU MUST DO:
// 4) Incorporate the two methods below -- typcase_class::code() and 
//    branch_class::code() -- into your cgen.cc file, replacing the empty
//    versions of the methods you had before.
// 5) Generate code to initialize the tag value in the class object of each class.
//    (You can do this in CgenNode::setup().)
// 6) Generate code to retrieve the tag value from the dynamic class object 
//    pointed to by an object instance. (You must do this in get_class_tag().
//    You MUST use this function name since it is called by
//    typcase_class::code(), below.)
// 7) Test your code using several examples that contain 'case'.  Be sure to
//    consider cases having different patterns of subclasses in branch labels.
//
//****************************************************************************

// Handle a Cool case expression (selecting based on the type of an object)
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

// Handle one branch of a Cool case expression.
// If the source tag is >= the branch tag
// and <= (max child of the branch class) tag,
// then the branch is a superclass of the source.
// See the MP3 handout for more information about our use of class tags.
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
