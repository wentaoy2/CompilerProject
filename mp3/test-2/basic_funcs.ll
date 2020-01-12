declare i32 @strcmp(i8*, i8*)
declare i32 @printf(i8*, ...)
declare void @abort()
declare i8* @malloc(i32)
declare %Object* @Object_new()
declare %Object* @Object_abort(%Object*)
declare %String* @Object_type_name(%Object*)
declare %Object* @Object_copy(%Object*)
declare %IO* @IO_new()
declare %IO* @IO_out_string(%IO*, %String*)
declare %IO* @IO_out_int(%IO*, i32)
declare %String* @IO_in_string(%IO*)
declare i32 @IO_in_int(%IO*)
declare %String* @String_new()
declare i32 @String_length(%String*)
declare %String* @String_concat(%String*, %String*)
declare %String* @String_substr(%String*, i32, i32)
declare %Int* @Int_new()
declare void @Int_init(%Int*, i32)
declare %Bool* @Bool_new()
declare void @Bool_init(%Bool*, i1)
@str.Object = internal constant [7 x i8] c"Object\00"
%Object = type {
	%Object_vtable*
}

%Object_vtable = type {
	i32,
	i32,
	i8*,
	%Object* () *,
	%Object* (%Object*) *,
	%String* (%Object*) *,
	%Object* (%Object*) *
}

@Object_vtable_prototype = constant %Object_vtable {
	i32 0,
	i32 ptrtoint (%Object* getelementptr (%Object, %Object* null, i32 1) to i32),
	i8* getelementptr ([7 x i8],[7 x i8]* @str.Object, i32 0, i32 0),
	%Object* () * @Object_new,
	%Object* (%Object*) * @Object_abort,
	%String* (%Object*) * @Object_type_name,
	%Object* (%Object*) * @Object_copy
}

@str.Int = internal constant [4 x i8] c"Int\00"
%Int = type {
	%Int_vtable*,
	i32
}

%Int_vtable = type {
	i32,
	i32,
	i8*,
	%Int* () *,
	%Object* (%Int*) *,
	%String* (%Int*) *,
	%Int* (%Int*) *
}

@Int_vtable_prototype = constant %Int_vtable {
	i32 1,
	i32 ptrtoint (%Int* getelementptr (%Int, %Int* null, i32 1) to i32),
	i8* getelementptr ([4 x i8],[4 x i8]* @str.Int, i32 0, i32 0),
	%Int* () * @Int_new,
	%Object* (%Int*) * bitcast (%Object* (%Object*) * @Object_abort to %Object* (%Int*) *),
	%String* (%Int*) * bitcast (%String* (%Object*) * @Object_type_name to %String* (%Int*) *),
	%Int* (%Int*) * bitcast (%Object* (%Object*) * @Object_copy to %Int* (%Int*) *)
}

@str.Bool = internal constant [5 x i8] c"Bool\00"
%Bool = type {
	%Bool_vtable*,
	i1
}

%Bool_vtable = type {
	i32,
	i32,
	i8*,
	%Bool* () *,
	%Object* (%Bool*) *,
	%String* (%Bool*) *,
	%Bool* (%Bool*) *
}

@Bool_vtable_prototype = constant %Bool_vtable {
	i32 2,
	i32 ptrtoint (%Bool* getelementptr (%Bool, %Bool* null, i32 1) to i32),
	i8* getelementptr ([5 x i8],[5 x i8]* @str.Bool, i32 0, i32 0),
	%Bool* () * @Bool_new,
	%Object* (%Bool*) * bitcast (%Object* (%Object*) * @Object_abort to %Object* (%Bool*) *),
	%String* (%Bool*) * bitcast (%String* (%Object*) * @Object_type_name to %String* (%Bool*) *),
	%Bool* (%Bool*) * bitcast (%Object* (%Object*) * @Object_copy to %Bool* (%Bool*) *)
}

@str.String = internal constant [7 x i8] c"String\00"
%String = type {
	%String_vtable*,
	i8*
}

%String_vtable = type {
	i32,
	i32,
	i8*,
	%String* () *,
	%Object* (%String*) *,
	%String* (%String*) *,
	%String* (%String*) *,
	i32 (%String*) *,
	%String* (%String*,%String*) *,
	%String* (%String*,i32,i32) *
}

@String_vtable_prototype = constant %String_vtable {
	i32 3,
	i32 ptrtoint (%String* getelementptr (%String, %String* null, i32 1) to i32),
	i8* getelementptr ([7 x i8],[7 x i8]* @str.String, i32 0, i32 0),
	%String* () * @String_new,
	%Object* (%String*) * bitcast (%Object* (%Object*) * @Object_abort to %Object* (%String*) *),
	%String* (%String*) * bitcast (%String* (%Object*) * @Object_type_name to %String* (%String*) *),
	%String* (%String*) * bitcast (%Object* (%Object*) * @Object_copy to %String* (%String*) *),
	i32 (%String*) * @String_length,
	%String* (%String*,%String*) * @String_concat,
	%String* (%String*,i32,i32) * @String_substr
}

@str.IO = internal constant [3 x i8] c"IO\00"
%IO = type {
	%IO_vtable*
}

%IO_vtable = type {
	i32,
	i32,
	i8*,
	%IO* () *,
	%Object* (%IO*) *,
	%String* (%IO*) *,
	%IO* (%IO*) *,
	%IO* (%IO*,%String*) *,
	%IO* (%IO*,i32) *,
	%String* (%IO*) *,
	i32 (%IO*) *
}

@IO_vtable_prototype = constant %IO_vtable {
	i32 4,
	i32 ptrtoint (%IO* getelementptr (%IO, %IO* null, i32 1) to i32),
	i8* getelementptr ([3 x i8],[3 x i8]* @str.IO, i32 0, i32 0),
	%IO* () * @IO_new,
	%Object* (%IO*) * bitcast (%Object* (%Object*) * @Object_abort to %Object* (%IO*) *),
	%String* (%IO*) * bitcast (%String* (%Object*) * @Object_type_name to %String* (%IO*) *),
	%IO* (%IO*) * bitcast (%Object* (%Object*) * @Object_copy to %IO* (%IO*) *),
	%IO* (%IO*,%String*) * @IO_out_string,
	%IO* (%IO*,i32) * @IO_out_int,
	%String* (%IO*) * @IO_in_string,
	i32 (%IO*) * @IO_in_int
}

@str.Main = internal constant [5 x i8] c"Main\00"
%Main = type {
	%Main_vtable*
}

%Main_vtable = type {
	i32,
	i32,
	i8*,
	%Main* () *,
	%Object* (%Main*) *,
	%String* (%Main*) *,
	%Main* (%Main*) *,
	%Main* (%Main*,%String*) *,
	%Main* (%Main*,i32) *,
	%String* (%Main*) *,
	i32 (%Main*) *,
	%Object* (%Main*) *
}

@Main_vtable_prototype = constant %Main_vtable {
	i32 5,
	i32 ptrtoint (%Main* getelementptr (%Main, %Main* null, i32 1) to i32),
	i8* getelementptr ([5 x i8],[5 x i8]* @str.Main, i32 0, i32 0),
	%Main* () * @Main_new,
	%Object* (%Main*) * bitcast (%Object* (%Object*) * @Object_abort to %Object* (%Main*) *),
	%String* (%Main*) * bitcast (%String* (%Object*) * @Object_type_name to %String* (%Main*) *),
	%Main* (%Main*) * bitcast (%Object* (%Object*) * @Object_copy to %Main* (%Main*) *),
	%Main* (%Main*,%String*) * bitcast (%IO* (%IO*,%String*) * @IO_out_string to %Main* (%Main*,%String*) *),
	%Main* (%Main*,i32) * bitcast (%IO* (%IO*,i32) * @IO_out_int to %Main* (%Main*,i32) *),
	%String* (%Main*) * bitcast (%String* (%IO*) * @IO_in_string to %String* (%Main*) *),
	i32 (%Main*) * bitcast (i32 (%IO*) * @IO_in_int to i32 (%Main*) *),
	%Object* (%Main*) * @Main_main
}

@str.2 = internal constant [14 x i8] c"<basic class>\00"
@String.2 = constant  %String {
	%String_vtable* @String_vtable_prototype,
	i8* getelementptr ([14 x i8],[14 x i8]* @str.2, i32 0, i32 0)
}

@str.1 = internal constant [7 x i8] c"Frugel\00"
@String.1 = constant  %String {
	%String_vtable* @String_vtable_prototype,
	i8* getelementptr ([7 x i8],[7 x i8]* @str.1, i32 0, i32 0)
}

@str.0 = internal constant [15 x i8] c"basic_funcs.cl\00"
@String.0 = constant  %String {
	%String_vtable* @String_vtable_prototype,
	i8* getelementptr ([15 x i8],[15 x i8]* @str.0, i32 0, i32 0)
}

define i32 @main() {
entry:
	%vtpm.0 = call %Main* @Main_new(  )
	%main.returnValue = call %Object*(%Main* ) @Main_main( %Main* %vtpm.0 )
	ret i32 0
}

define %Object* @Main_main(%Main* %self) {

entry:
	%vtpm.1 = alloca %Main*
	store %Main* %self, %Main** %vtpm.1
	%vtpm.2 = load %Main*, %Main** %vtpm.1
	%vtpm.3 = icmp eq %Main* %vtpm.2, null
	br i1 %vtpm.3, label %abort, label %tmp.0

tmp.0:
	%vtpm.4 = getelementptr %Main, %Main* %vtpm.2, i32 0, i32 0
	%vtpm.5 = load %Main_vtable*, %Main_vtable** %vtpm.4
	%vtpm.6 = getelementptr %Main_vtable, %Main_vtable* %vtpm.5, i32 0, i32 5
	%tmp.1 = load %String* (%Main*) *, %String* (%Main*) ** %vtpm.6
	%vtpm.7 = call %String*(%Main* ) %tmp.1( %Main* %vtpm.2 )
	%vtpm.8 = load %Main*, %Main** %vtpm.1
	%vtpm.9 = icmp eq %Main* %vtpm.8, null
	br i1 %vtpm.9, label %abort, label %tmp.2

tmp.2:
	%vtpm.10 = getelementptr %Main, %Main* %vtpm.8, i32 0, i32 0
	%vtpm.11 = load %Main_vtable*, %Main_vtable** %vtpm.10
	%vtpm.12 = getelementptr %Main_vtable, %Main_vtable* %vtpm.11, i32 0, i32 7
	%tmp.3 = load %Main* (%Main*,%String*) *, %Main* (%Main*,%String*) ** %vtpm.12
	%vtpm.13 = call %Main*(%Main*, %String* ) %tmp.3( %Main* %vtpm.8, %String* %vtpm.7 )
	%vtpm.14 = load %Main*, %Main** %vtpm.1
	%vtpm.15 = icmp eq %Main* %vtpm.14, null
	br i1 %vtpm.15, label %abort, label %tmp.4

tmp.4:
	%vtpm.16 = getelementptr %Main, %Main* %vtpm.14, i32 0, i32 0
	%vtpm.17 = load %Main_vtable*, %Main_vtable** %vtpm.16
	%vtpm.18 = getelementptr %Main_vtable, %Main_vtable* %vtpm.17, i32 0, i32 8
	%tmp.5 = load %Main* (%Main*,i32) *, %Main* (%Main*,i32) ** %vtpm.18
	%vtpm.19 = call %Main*(%Main*, i32 ) %tmp.5( %Main* %vtpm.14, i32 879 )
	%vtpm.20 = load %Main*, %Main** %vtpm.1
	%vtpm.21 = icmp eq %Main* %vtpm.20, null
	br i1 %vtpm.21, label %abort, label %tmp.6

tmp.6:
	%vtpm.22 = getelementptr %Main, %Main* %vtpm.20, i32 0, i32 0
	%vtpm.23 = load %Main_vtable*, %Main_vtable** %vtpm.22
	%vtpm.24 = getelementptr %Main_vtable, %Main_vtable* %vtpm.23, i32 0, i32 5
	%tmp.7 = load %String* (%Main*) *, %String* (%Main*) ** %vtpm.24
	%vtpm.25 = call %String*(%Main* ) %tmp.7( %Main* %vtpm.20 )
	%vtpm.26 = icmp eq %String* %vtpm.25, null
	br i1 %vtpm.26, label %abort, label %tmp.8

tmp.8:
	%vtpm.27 = getelementptr %String, %String* %vtpm.25, i32 0, i32 0
	%vtpm.28 = load %String_vtable*, %String_vtable** %vtpm.27
	%vtpm.29 = getelementptr %String_vtable, %String_vtable* %vtpm.28, i32 0, i32 8
	%tmp.9 = load %String* (%String*,%String*) *, %String* (%String*,%String*) ** %vtpm.29
	%vtpm.30 = call %String*(%String*, %String* ) %tmp.9( %String* %vtpm.25, %String* @String.1 )
	%vtpm.31 = load %Main*, %Main** %vtpm.1
	%vtpm.32 = icmp eq %Main* %vtpm.31, null
	br i1 %vtpm.32, label %abort, label %tmp.10

tmp.10:
	%vtpm.33 = getelementptr %Main, %Main* %vtpm.31, i32 0, i32 0
	%vtpm.34 = load %Main_vtable*, %Main_vtable** %vtpm.33
	%vtpm.35 = getelementptr %Main_vtable, %Main_vtable* %vtpm.34, i32 0, i32 7
	%tmp.11 = load %Main* (%Main*,%String*) *, %Main* (%Main*,%String*) ** %vtpm.35
	%vtpm.36 = call %Main*(%Main*, %String* ) %tmp.11( %Main* %vtpm.31, %String* %vtpm.30 )
	%vtpm.37 = load %Main*, %Main** %vtpm.1
	%vtpm.38 = icmp eq %Main* %vtpm.37, null
	br i1 %vtpm.38, label %abort, label %tmp.12

tmp.12:
	%vtpm.39 = getelementptr %Main, %Main* %vtpm.37, i32 0, i32 0
	%vtpm.40 = load %Main_vtable*, %Main_vtable** %vtpm.39
	%vtpm.41 = getelementptr %Main_vtable, %Main_vtable* %vtpm.40, i32 0, i32 5
	%tmp.13 = load %String* (%Main*) *, %String* (%Main*) ** %vtpm.41
	%vtpm.42 = call %String*(%Main* ) %tmp.13( %Main* %vtpm.37 )
	%vtpm.43 = icmp eq %String* %vtpm.42, null
	br i1 %vtpm.43, label %abort, label %tmp.14

tmp.14:
	%vtpm.44 = getelementptr %String, %String* %vtpm.42, i32 0, i32 0
	%vtpm.45 = load %String_vtable*, %String_vtable** %vtpm.44
	%vtpm.46 = getelementptr %String_vtable, %String_vtable* %vtpm.45, i32 0, i32 7
	%tmp.15 = load i32 (%String*) *, i32 (%String*) ** %vtpm.46
	%vtpm.47 = call i32(%String* ) %tmp.15( %String* %vtpm.42 )
	%vtpm.48 = load %Main*, %Main** %vtpm.1
	%vtpm.49 = icmp eq %Main* %vtpm.48, null
	br i1 %vtpm.49, label %abort, label %tmp.16

tmp.16:
	%vtpm.50 = getelementptr %Main, %Main* %vtpm.48, i32 0, i32 0
	%vtpm.51 = load %Main_vtable*, %Main_vtable** %vtpm.50
	%vtpm.52 = getelementptr %Main_vtable, %Main_vtable* %vtpm.51, i32 0, i32 8
	%tmp.17 = load %Main* (%Main*,i32) *, %Main* (%Main*,i32) ** %vtpm.52
	%vtpm.53 = call %Main*(%Main*, i32 ) %tmp.17( %Main* %vtpm.48, i32 %vtpm.47 )
	%vtpm.54 = load %Main*, %Main** %vtpm.1
	%vtpm.55 = icmp eq %Main* %vtpm.54, null
	br i1 %vtpm.55, label %abort, label %tmp.18

tmp.18:
	%vtpm.56 = getelementptr %Main, %Main* %vtpm.54, i32 0, i32 0
	%vtpm.57 = load %Main_vtable*, %Main_vtable** %vtpm.56
	%vtpm.58 = getelementptr %Main_vtable, %Main_vtable* %vtpm.57, i32 0, i32 5
	%tmp.19 = load %String* (%Main*) *, %String* (%Main*) ** %vtpm.58
	%vtpm.59 = call %String*(%Main* ) %tmp.19( %Main* %vtpm.54 )
	%vtpm.60 = icmp eq %String* %vtpm.59, null
	br i1 %vtpm.60, label %abort, label %tmp.20

tmp.20:
	%vtpm.61 = getelementptr %String, %String* %vtpm.59, i32 0, i32 0
	%vtpm.62 = load %String_vtable*, %String_vtable** %vtpm.61
	%vtpm.63 = getelementptr %String_vtable, %String_vtable* %vtpm.62, i32 0, i32 9
	%tmp.21 = load %String* (%String*,i32,i32) *, %String* (%String*,i32,i32) ** %vtpm.63
	%vtpm.64 = call %String*(%String*, i32, i32 ) %tmp.21( %String* %vtpm.59, i32 2, i32 2 )
	%vtpm.65 = load %Main*, %Main** %vtpm.1
	%vtpm.66 = icmp eq %Main* %vtpm.65, null
	br i1 %vtpm.66, label %abort, label %tmp.22

tmp.22:
	%vtpm.67 = getelementptr %Main, %Main* %vtpm.65, i32 0, i32 0
	%vtpm.68 = load %Main_vtable*, %Main_vtable** %vtpm.67
	%vtpm.69 = getelementptr %Main_vtable, %Main_vtable* %vtpm.68, i32 0, i32 7
	%tmp.23 = load %Main* (%Main*,%String*) *, %Main* (%Main*,%String*) ** %vtpm.69
	%vtpm.70 = call %Main*(%Main*, %String* ) %tmp.23( %Main* %vtpm.65, %String* %vtpm.64 )
	%vtpm.71 = load %Main*, %Main** %vtpm.1
	%vtpm.72 = bitcast %Main* %vtpm.71 to %Object*
	ret %Object* %vtpm.72

abort:
	call void @abort(  )
	unreachable
}

define %Main* @Main_new() {

entry:
	%vtpm.74 = getelementptr %Main_vtable, %Main_vtable* @Main_vtable_prototype, i32 0, i32 1
	%vtpm.75 = load i32, i32* %vtpm.74
	%vtpm.76 = call i8*(i32 ) @malloc( i32 %vtpm.75 )
	%vtpm.77 = bitcast i8* %vtpm.76 to %Main*
	%vtpm.78 = getelementptr %Main, %Main* %vtpm.77, i32 0, i32 0
	store %Main_vtable* @Main_vtable_prototype, %Main_vtable** %vtpm.78
	%vtpm.79 = alloca %Main*
	store %Main* %vtpm.77, %Main** %vtpm.79
	ret %Main* %vtpm.77

abort:
	call void @abort(  )
	unreachable
}

