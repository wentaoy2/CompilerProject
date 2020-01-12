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
@str.Object = internal constant [7 x i8] c"Object\00", align 1
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
	i8* getelementptr ([7 x i8], [7 x i8]* @str.Object, i32 0, i32 0),
	%Object* () * @Object_new,
	%Object* (%Object*) * @Object_abort,
	%String* (%Object*) * @Object_type_name,
	%Object* (%Object*) * @Object_copy
}

@str.Int = internal constant [4 x i8] c"Int\00", align 1
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
	i8* getelementptr ([4 x i8], [4 x i8]* @str.Int, i32 0, i32 0),
	%Int* () * @Int_new,
	%Object* (%Int*) * bitcast (%Object* (%Object*) * @Object_abort to %Object* (%Int*) *),
	%String* (%Int*) * bitcast (%String* (%Object*) * @Object_type_name to %String* (%Int*) *),
	%Int* (%Int*) * bitcast (%Object* (%Object*) * @Object_copy to %Int* (%Int*) *)
}

@str.Bool = internal constant [5 x i8] c"Bool\00", align 1
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
	i8* getelementptr ([5 x i8], [5 x i8]* @str.Bool, i32 0, i32 0),
	%Bool* () * @Bool_new,
	%Object* (%Bool*) * bitcast (%Object* (%Object*) * @Object_abort to %Object* (%Bool*) *),
	%String* (%Bool*) * bitcast (%String* (%Object*) * @Object_type_name to %String* (%Bool*) *),
	%Bool* (%Bool*) * bitcast (%Object* (%Object*) * @Object_copy to %Bool* (%Bool*) *)
}

@str.String = internal constant [7 x i8] c"String\00", align 1
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
	i8* getelementptr ([7 x i8], [7 x i8]* @str.String, i32 0, i32 0),
	%String* () * @String_new,
	%Object* (%String*) * bitcast (%Object* (%Object*) * @Object_abort to %Object* (%String*) *),
	%String* (%String*) * bitcast (%String* (%Object*) * @Object_type_name to %String* (%String*) *),
	%String* (%String*) * bitcast (%Object* (%Object*) * @Object_copy to %String* (%String*) *),
	i32 (%String*) * @String_length,
	%String* (%String*,%String*) * @String_concat,
	%String* (%String*,i32,i32) * @String_substr
}

@str.IO = internal constant [3 x i8] c"IO\00", align 1
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
	i8* getelementptr ([3 x i8], [3 x i8]* @str.IO, i32 0, i32 0),
	%IO* () * @IO_new,
	%Object* (%IO*) * bitcast (%Object* (%Object*) * @Object_abort to %Object* (%IO*) *),
	%String* (%IO*) * bitcast (%String* (%Object*) * @Object_type_name to %String* (%IO*) *),
	%IO* (%IO*) * bitcast (%Object* (%Object*) * @Object_copy to %IO* (%IO*) *),
	%IO* (%IO*,%String*) * @IO_out_string,
	%IO* (%IO*,i32) * @IO_out_int,
	%String* (%IO*) * @IO_in_string,
	i32 (%IO*) * @IO_in_int
}

@str.Main = internal constant [5 x i8] c"Main\00", align 1
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
	i8* getelementptr ([5 x i8], [5 x i8]* @str.Main, i32 0, i32 0),
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

@str.3 = internal constant [14 x i8] c"<basic class>\00", align 1
@String.3 = constant %String {
	%String_vtable* @String_vtable_prototype,
	i8* getelementptr ([14 x i8], [14 x i8]* @str.3, i32 0, i32 0)
}

@str.2 = internal constant [7 x i8] c"not ok\00", align 1
@String.2 = constant %String {
	%String_vtable* @String_vtable_prototype,
	i8* getelementptr ([7 x i8], [7 x i8]* @str.2, i32 0, i32 0)
}

@str.1 = internal constant [3 x i8] c"ok\00", align 1
@String.1 = constant %String {
	%String_vtable* @String_vtable_prototype,
	i8* getelementptr ([3 x i8], [3 x i8]* @str.1, i32 0, i32 0)
}

@str.0 = internal constant [12 x i8] c"isvoid_o.cl\00", align 1
@String.0 = constant %String {
	%String_vtable* @String_vtable_prototype,
	i8* getelementptr ([12 x i8], [12 x i8]* @str.0, i32 0, i32 0)
}

define i32 @main() {
entry:
	%main.obj = call %Main*() @Main_new( )
	%main.retval = call %Object*(%Main*) @Main_main( %Main* %main.obj )
	ret i32 0
}

define i1 @Main_func(%Main* %self) {

entry:
	%tmp.0 = alloca %Main*
	store %Main* %self, %Main** %tmp.0
	%tmp.1 = load %Main*, %Main** %tmp.0
	%tmp.2 = getelementptr %Main, %Main* %tmp.1, i32 0, i32 1
	%tmp.3 = load %Main*, %Main** %tmp.2
	%tmp.4 = icmp eq %Main* %tmp.3, null
	ret i1 %tmp.4

abort:
	call void @abort(  )
	unreachable
}

define %Object* @Main_main(%Main* %self) {

entry:
	%tmp.5 = alloca %Main*
	store %Main* %self, %Main** %tmp.5
	%tmp.6 = alloca %Main*
	%tmp.7 = load %Main*, %Main** %tmp.5
	%tmp.8 = icmp eq %Main* %tmp.7, null
	br i1 %tmp.8, label %abort, label %ok.0

ok.0:
	%tmp.9 = getelementptr %Main, %Main* %tmp.7, i32 0, i32 0
	%tmp.10 = load %Main_vtable*, %Main_vtable** %tmp.9
	%tmp.11 = getelementptr %Main_vtable, %Main_vtable* %tmp.10, i32 0, i32 11
	%tmp.12 = load i1 (%Main*) *, i1 (%Main*) ** %tmp.11
	%tmp.13 = call i1(%Main*) %tmp.12( %Main* %tmp.7 )
	br i1 %tmp.13, label %true.0, label %false.0

true.0:
	%tmp.14 = load %Main*, %Main** %tmp.5
	%tmp.15 = icmp eq %Main* %tmp.14, null
	br i1 %tmp.15, label %abort, label %ok.1

ok.1:
	%tmp.16 = getelementptr %Main, %Main* %tmp.14, i32 0, i32 0
	%tmp.17 = load %Main_vtable*, %Main_vtable** %tmp.16
	%tmp.18 = getelementptr %Main_vtable, %Main_vtable* %tmp.17, i32 0, i32 7
	%tmp.19 = load %Main* (%Main*,%String*) *, %Main* (%Main*,%String*) ** %tmp.18
	%tmp.20 = call %Main*(%Main*, %String*) %tmp.19( %Main* %tmp.14, %String* @String.1 )
	store %Main* %tmp.20, %Main** %tmp.6
	br label %end.0

false.0:
	%tmp.21 = load %Main*, %Main** %tmp.5
	%tmp.22 = icmp eq %Main* %tmp.21, null
	br i1 %tmp.22, label %abort, label %ok.2

ok.2:
	%tmp.23 = getelementptr %Main, %Main* %tmp.21, i32 0, i32 0
	%tmp.24 = load %Main_vtable*, %Main_vtable** %tmp.23
	%tmp.25 = getelementptr %Main_vtable, %Main_vtable* %tmp.24, i32 0, i32 7
	%tmp.26 = load %Main* (%Main*,%String*) *, %Main* (%Main*,%String*) ** %tmp.25
	%tmp.27 = call %Main*(%Main*, %String*) %tmp.26( %Main* %tmp.21, %String* @String.2 )
	store %Main* %tmp.27, %Main** %tmp.6
	br label %end.0

end.0:
	%tmp.28 = load %Main*, %Main** %tmp.6
	%tmp.29 = load %Main*, %Main** %tmp.5
	%tmp.30 = bitcast %Main* %tmp.29 to %Object*
	ret %Object* %tmp.30

abort:
	call void @abort(  )
	unreachable
}

define %Main* @Main_new() {

entry:
	%tmp.31 = getelementptr %Main_vtable, %Main_vtable* @Main_vtable_prototype, i32 0, i32 1
	%tmp.32 = load i32, i32* %tmp.31
	%tmp.33 = call i8*(i32) @malloc( i32 %tmp.32 )
	%tmp.34 = bitcast i8* %tmp.33 to %Main*
	%tmp.35 = getelementptr %Main, %Main* %tmp.34, i32 0, i32 0
	store %Main_vtable* @Main_vtable_prototype, %Main_vtable** %tmp.35
	%tmp.36 = alloca %Main*
	store %Main* %tmp.34, %Main** %tmp.36
	%tmp.37 = getelementptr %Main, %Main* %tmp.34, i32 0, i32 1
	store %Main* null, %Main** %tmp.37
	ret %Main* %tmp.34

abort:
	call void @abort(  )
	unreachable
}

