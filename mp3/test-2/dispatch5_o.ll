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
	%A*,
	%A*,
	%A*,
	%B*,
	%C*
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
	%Main* (%Main*) *
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
	%Main* (%Main*) * @Main_main
}

@str.A = internal constant [2 x i8] c"A\00"
%A = type {
	%A_vtable*
}

%A_vtable = type {
	i32,
	i32,
	i8*,
	%A* () *,
	%Object* (%A*) *,
	%String* (%A*) *,
	%A* (%A*) *,
	i32 (%A*) *
}

@A_vtable_prototype = constant %A_vtable {
	i32 6,
	i32 ptrtoint (%A* getelementptr (%A, %A* null, i32 1) to i32),
	i8* getelementptr ([2 x i8],[2 x i8]* @str.A, i32 0, i32 0),
	%A* () * @A_new,
	%Object* (%A*) * bitcast (%Object* (%Object*) * @Object_abort to %Object* (%A*) *),
	%String* (%A*) * bitcast (%String* (%Object*) * @Object_type_name to %String* (%A*) *),
	%A* (%A*) * bitcast (%Object* (%Object*) * @Object_copy to %A* (%A*) *),
	i32 (%A*) * @A_f
}

@str.B = internal constant [2 x i8] c"B\00"
%B = type {
	%B_vtable*
}

%B_vtable = type {
	i32,
	i32,
	i8*,
	%B* () *,
	%Object* (%B*) *,
	%String* (%B*) *,
	%B* (%B*) *,
	i32 (%B*) *
}

@B_vtable_prototype = constant %B_vtable {
	i32 7,
	i32 ptrtoint (%B* getelementptr (%B, %B* null, i32 1) to i32),
	i8* getelementptr ([2 x i8],[2 x i8]* @str.B, i32 0, i32 0),
	%B* () * @B_new,
	%Object* (%B*) * bitcast (%Object* (%Object*) * @Object_abort to %Object* (%B*) *),
	%String* (%B*) * bitcast (%String* (%Object*) * @Object_type_name to %String* (%B*) *),
	%B* (%B*) * bitcast (%Object* (%Object*) * @Object_copy to %B* (%B*) *),
	i32 (%B*) * bitcast (i32 (%A*) * @A_f to i32 (%B*) *)
}

@str.C = internal constant [2 x i8] c"C\00"
%C = type {
	%C_vtable*
}

%C_vtable = type {
	i32,
	i32,
	i8*,
	%C* () *,
	%Object* (%C*) *,
	%String* (%C*) *,
	%C* (%C*) *,
	i32 (%C*) *,
	i32 (%C*) *
}

@C_vtable_prototype = constant %C_vtable {
	i32 8,
	i32 ptrtoint (%C* getelementptr (%C, %C* null, i32 1) to i32),
	i8* getelementptr ([2 x i8],[2 x i8]* @str.C, i32 0, i32 0),
	%C* () * @C_new,
	%Object* (%C*) * bitcast (%Object* (%Object*) * @Object_abort to %Object* (%C*) *),
	%String* (%C*) * bitcast (%String* (%Object*) * @Object_type_name to %String* (%C*) *),
	%C* (%C*) * bitcast (%Object* (%Object*) * @Object_copy to %C* (%C*) *),
	i32 (%C*) * bitcast (i32 (%A*) * @A_f to i32 (%C*) *),
	i32 (%C*) * @C_f
}

@str.1 = internal constant [14 x i8] c"<basic class>\00"
@String.1 = constant  %String {
	%String_vtable* @String_vtable_prototype,
	i8* getelementptr ([14 x i8],[14 x i8]* @str.1, i32 0, i32 0)
}

@str.0 = internal constant [15 x i8] c"dispatch5_o.cl\00"
@String.0 = constant  %String {
	%String_vtable* @String_vtable_prototype,
	i8* getelementptr ([15 x i8],[15 x i8]* @str.0, i32 0, i32 0)
}

define i32 @main() {
entry:
	%vtpm.0 = call %Main* @Main_new(  )
	%main.returnValue = call %Main*(%Main* ) @Main_main( %Main* %vtpm.0 )
	ret i32 0
}

define %Main* @Main_main(%Main* %self) {

entry:
	%vtpm.1 = alloca %Main*
	store %Main* %self, %Main** %vtpm.1
	%vtpm.2 = load %Main*, %Main** %vtpm.1
	%vtpm.3 = getelementptr %Main, %Main* %vtpm.2, i32 0, i32 3
	%vtpm.4 = load %A*, %A** %vtpm.3
	%vtpm.5 = icmp eq %A* %vtpm.4, null
	br i1 %vtpm.5, label %abort, label %tmp.0

tmp.0:
	%vtpm.6 = getelementptr %A, %A* %vtpm.4, i32 0, i32 0
	%vtpm.7 = load %A_vtable*, %A_vtable** %vtpm.6
	%vtpm.8 = getelementptr %A_vtable, %A_vtable* %vtpm.7, i32 0, i32 7
	%tmp.1 = load i32 (%A*) *, i32 (%A*) ** %vtpm.8
	%vtpm.9 = call i32(%A* ) %tmp.1( %A* %vtpm.4 )
	%vtpm.10 = load %Main*, %Main** %vtpm.1
	%vtpm.11 = icmp eq %Main* %vtpm.10, null
	br i1 %vtpm.11, label %abort, label %tmp.2

tmp.2:
	%vtpm.12 = getelementptr %Main, %Main* %vtpm.10, i32 0, i32 0
	%vtpm.13 = load %Main_vtable*, %Main_vtable** %vtpm.12
	%vtpm.14 = getelementptr %Main_vtable, %Main_vtable* %vtpm.13, i32 0, i32 8
	%tmp.3 = load %Main* (%Main*,i32) *, %Main* (%Main*,i32) ** %vtpm.14
	%vtpm.15 = call %Main*(%Main*, i32 ) %tmp.3( %Main* %vtpm.10, i32 %vtpm.9 )
	ret %Main* %vtpm.15

abort:
	call void @abort(  )
	unreachable
}

define %Main* @Main_new() {

entry:
	%vtpm.17 = getelementptr %Main_vtable, %Main_vtable* @Main_vtable_prototype, i32 0, i32 1
	%vtpm.18 = load i32, i32* %vtpm.17
	%vtpm.19 = call i8*(i32 ) @malloc( i32 %vtpm.18 )
	%vtpm.20 = bitcast i8* %vtpm.19 to %Main*
	%vtpm.21 = getelementptr %Main, %Main* %vtpm.20, i32 0, i32 0
	store %Main_vtable* @Main_vtable_prototype, %Main_vtable** %vtpm.21
	%vtpm.22 = alloca %Main*
	store %Main* %vtpm.20, %Main** %vtpm.22
	%vtpm.23 = call %A* @A_new(  )
	%vtpm.24 = load %Main*, %Main** %vtpm.22
	%vtpm.25 = getelementptr %Main, %Main* %vtpm.24, i32 0, i32 1
	store %A* %vtpm.23, %A** %vtpm.25
	%vtpm.26 = call %B* @B_new(  )
	%vtpm.27 = load %Main*, %Main** %vtpm.22
	%vtpm.28 = getelementptr %Main, %Main* %vtpm.27, i32 0, i32 2
	%vtpm.29 = bitcast %B* %vtpm.26 to %A*
	store %A* %vtpm.29, %A** %vtpm.28
	%vtpm.30 = call %C* @C_new(  )
	%vtpm.31 = load %Main*, %Main** %vtpm.22
	%vtpm.32 = getelementptr %Main, %Main* %vtpm.31, i32 0, i32 3
	%vtpm.33 = bitcast %C* %vtpm.30 to %A*
	store %A* %vtpm.33, %A** %vtpm.32
	%vtpm.34 = call %B* @B_new(  )
	%vtpm.35 = load %Main*, %Main** %vtpm.22
	%vtpm.36 = getelementptr %Main, %Main* %vtpm.35, i32 0, i32 4
	store %B* %vtpm.34, %B** %vtpm.36
	%vtpm.37 = call %C* @C_new(  )
	%vtpm.38 = load %Main*, %Main** %vtpm.22
	%vtpm.39 = getelementptr %Main, %Main* %vtpm.38, i32 0, i32 5
	store %C* %vtpm.37, %C** %vtpm.39
	ret %Main* %vtpm.20

abort:
	call void @abort(  )
	unreachable
}

define i32 @A_f(%A* %self) {

entry:
	%vtpm.41 = alloca %A*
	store %A* %self, %A** %vtpm.41
	ret i32 5

abort:
	call void @abort(  )
	unreachable
}

define %A* @A_new() {

entry:
	%vtpm.43 = getelementptr %A_vtable, %A_vtable* @A_vtable_prototype, i32 0, i32 1
	%vtpm.44 = load i32, i32* %vtpm.43
	%vtpm.45 = call i8*(i32 ) @malloc( i32 %vtpm.44 )
	%vtpm.46 = bitcast i8* %vtpm.45 to %A*
	%vtpm.47 = getelementptr %A, %A* %vtpm.46, i32 0, i32 0
	store %A_vtable* @A_vtable_prototype, %A_vtable** %vtpm.47
	%vtpm.48 = alloca %A*
	store %A* %vtpm.46, %A** %vtpm.48
	ret %A* %vtpm.46

abort:
	call void @abort(  )
	unreachable
}

define %B* @B_new() {

entry:
	%vtpm.50 = getelementptr %B_vtable, %B_vtable* @B_vtable_prototype, i32 0, i32 1
	%vtpm.51 = load i32, i32* %vtpm.50
	%vtpm.52 = call i8*(i32 ) @malloc( i32 %vtpm.51 )
	%vtpm.53 = bitcast i8* %vtpm.52 to %B*
	%vtpm.54 = getelementptr %B, %B* %vtpm.53, i32 0, i32 0
	store %B_vtable* @B_vtable_prototype, %B_vtable** %vtpm.54
	%vtpm.55 = alloca %B*
	store %B* %vtpm.53, %B** %vtpm.55
	ret %B* %vtpm.53

abort:
	call void @abort(  )
	unreachable
}

define i32 @C_f(%C* %self) {

entry:
	%vtpm.57 = alloca %C*
	store %C* %self, %C** %vtpm.57
	ret i32 6

abort:
	call void @abort(  )
	unreachable
}

define %C* @C_new() {

entry:
	%vtpm.59 = getelementptr %C_vtable, %C_vtable* @C_vtable_prototype, i32 0, i32 1
	%vtpm.60 = load i32, i32* %vtpm.59
	%vtpm.61 = call i8*(i32 ) @malloc( i32 %vtpm.60 )
	%vtpm.62 = bitcast i8* %vtpm.61 to %C*
	%vtpm.63 = getelementptr %C, %C* %vtpm.62, i32 0, i32 0
	store %C_vtable* @C_vtable_prototype, %C_vtable** %vtpm.63
	%vtpm.64 = alloca %C*
	store %C* %vtpm.62, %C** %vtpm.64
	ret %C* %vtpm.62

abort:
	call void @abort(  )
	unreachable
}

