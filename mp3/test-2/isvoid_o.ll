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
	%Main_vtable*,
	%Main*
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
	i1 (%Main*) *,
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
	i1 (%Main*) * @Main_func,
	%Object* (%Main*) * @Main_main
}

@str.3 = internal constant [14 x i8] c"<basic class>\00"
@String.3 = constant  %String {
	%String_vtable* @String_vtable_prototype,
	i8* getelementptr ([14 x i8],[14 x i8]* @str.3, i32 0, i32 0)
}

@str.2 = internal constant [7 x i8] c"not ok\00"
@String.2 = constant  %String {
	%String_vtable* @String_vtable_prototype,
	i8* getelementptr ([7 x i8],[7 x i8]* @str.2, i32 0, i32 0)
}

@str.1 = internal constant [3 x i8] c"ok\00"
@String.1 = constant  %String {
	%String_vtable* @String_vtable_prototype,
	i8* getelementptr ([3 x i8],[3 x i8]* @str.1, i32 0, i32 0)
}

@str.0 = internal constant [12 x i8] c"isvoid_o.cl\00"
@String.0 = constant  %String {
	%String_vtable* @String_vtable_prototype,
	i8* getelementptr ([12 x i8],[12 x i8]* @str.0, i32 0, i32 0)
}

define i32 @main() {
entry:
	%vtpm.0 = call %Main* @Main_new(  )
	%main.returnValue = call %Object*(%Main* ) @Main_main( %Main* %vtpm.0 )
	ret i32 0
}

define i1 @Main_func(%Main* %self) {

entry:
	%vtpm.1 = alloca %Main*
	store %Main* %self, %Main** %vtpm.1
	%vtpm.2 = load %Main*, %Main** %vtpm.1
	%vtpm.3 = getelementptr %Main, %Main* %vtpm.2, i32 0, i32 1
	%vtpm.4 = load %Main*, %Main** %vtpm.3
	%vtpm.5 = icmp eq %Main* %vtpm.4, null
	ret i1 %vtpm.5

abort:
	call void @abort(  )
	unreachable
}

define %Object* @Main_main(%Main* %self) {

entry:
	%vtpm.7 = alloca %Main*
	store %Main* %self, %Main** %vtpm.7
	%vtpm.8 = alloca %Main*
	%vtpm.9 = load %Main*, %Main** %vtpm.7
	%vtpm.10 = icmp eq %Main* %vtpm.9, null
	br i1 %vtpm.10, label %abort, label %tmp.0

tmp.0:
	%vtpm.11 = getelementptr %Main, %Main* %vtpm.9, i32 0, i32 0
	%vtpm.12 = load %Main_vtable*, %Main_vtable** %vtpm.11
	%vtpm.13 = getelementptr %Main_vtable, %Main_vtable* %vtpm.12, i32 0, i32 11
	%tmp.1 = load i1 (%Main*) *, i1 (%Main*) ** %vtpm.13
	%vtpm.14 = call i1(%Main* ) %tmp.1( %Main* %vtpm.9 )
	br i1 %vtpm.14, label %condTrue.0, label %condFalse.1

condTrue.0:
	%vtpm.15 = load %Main*, %Main** %vtpm.7
	%vtpm.16 = icmp eq %Main* %vtpm.15, null
	br i1 %vtpm.16, label %abort, label %tmp.2

tmp.2:
	%vtpm.17 = getelementptr %Main, %Main* %vtpm.15, i32 0, i32 0
	%vtpm.18 = load %Main_vtable*, %Main_vtable** %vtpm.17
	%vtpm.19 = getelementptr %Main_vtable, %Main_vtable* %vtpm.18, i32 0, i32 7
	%tmp.3 = load %Main* (%Main*,%String*) *, %Main* (%Main*,%String*) ** %vtpm.19
	%vtpm.20 = call %Main*(%Main*, %String* ) %tmp.3( %Main* %vtpm.15, %String* @String.1 )
	store %Main* %vtpm.20, %Main** %vtpm.8
	br label %end.2

condFalse.1:
	%vtpm.21 = load %Main*, %Main** %vtpm.7
	%vtpm.22 = icmp eq %Main* %vtpm.21, null
	br i1 %vtpm.22, label %abort, label %tmp.4

tmp.4:
	%vtpm.23 = getelementptr %Main, %Main* %vtpm.21, i32 0, i32 0
	%vtpm.24 = load %Main_vtable*, %Main_vtable** %vtpm.23
	%vtpm.25 = getelementptr %Main_vtable, %Main_vtable* %vtpm.24, i32 0, i32 7
	%tmp.5 = load %Main* (%Main*,%String*) *, %Main* (%Main*,%String*) ** %vtpm.25
	%vtpm.26 = call %Main*(%Main*, %String* ) %tmp.5( %Main* %vtpm.21, %String* @String.2 )
	store %Main* %vtpm.26, %Main** %vtpm.8
	br label %end.2

end.2:
	%vtpm.27 = load %Main*, %Main** %vtpm.8
	%vtpm.28 = load %Main*, %Main** %vtpm.7
	%vtpm.29 = bitcast %Main* %vtpm.28 to %Object*
	ret %Object* %vtpm.29

abort:
	call void @abort(  )
	unreachable
}

define %Main* @Main_new() {

entry:
	%vtpm.31 = getelementptr %Main_vtable, %Main_vtable* @Main_vtable_prototype, i32 0, i32 1
	%vtpm.32 = load i32, i32* %vtpm.31
	%vtpm.33 = call i8*(i32 ) @malloc( i32 %vtpm.32 )
	%vtpm.34 = bitcast i8* %vtpm.33 to %Main*
	%vtpm.35 = getelementptr %Main, %Main* %vtpm.34, i32 0, i32 0
	store %Main_vtable* @Main_vtable_prototype, %Main_vtable** %vtpm.35
	%vtpm.36 = alloca %Main*
	store %Main* %vtpm.34, %Main** %vtpm.36
	%vtpm.37 = load %Main*, %Main** %vtpm.36
	%vtpm.38 = getelementptr %Main, %Main* %vtpm.37, i32 0, i32 1
	store %Main* null, %Main** %vtpm.38
	ret %Main* %vtpm.34

abort:
	call void @abort(  )
	unreachable
}

