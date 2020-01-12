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

@str.Foo = internal constant [4 x i8] c"Foo\00"
%Foo = type {
	%Foo_vtable*
}

%Foo_vtable = type {
	i32,
	i32,
	i8*,
	%Foo* () *,
	%Object* (%Foo*) *,
	%String* (%Foo*) *,
	%Foo* (%Foo*) *,
	%Object* (%Foo*) *
}

@Foo_vtable_prototype = constant %Foo_vtable {
	i32 5,
	i32 ptrtoint (%Foo* getelementptr (%Foo, %Foo* null, i32 1) to i32),
	i8* getelementptr ([4 x i8],[4 x i8]* @str.Foo, i32 0, i32 0),
	%Foo* () * @Foo_new,
	%Object* (%Foo*) * bitcast (%Object* (%Object*) * @Object_abort to %Object* (%Foo*) *),
	%String* (%Foo*) * bitcast (%String* (%Object*) * @Object_type_name to %String* (%Foo*) *),
	%Foo* (%Foo*) * bitcast (%Object* (%Object*) * @Object_copy to %Foo* (%Foo*) *),
	%Object* (%Foo*) * @Foo_f
}

@str.Main = internal constant [5 x i8] c"Main\00"
%Main = type {
	%Main_vtable*,
	%Foo*
}

%Main_vtable = type {
	i32,
	i32,
	i8*,
	%Main* () *,
	%Object* (%Main*) *,
	%String* (%Main*) *,
	%Main* (%Main*) *,
	%Object* (%Main*) *
}

@Main_vtable_prototype = constant %Main_vtable {
	i32 6,
	i32 ptrtoint (%Main* getelementptr (%Main, %Main* null, i32 1) to i32),
	i8* getelementptr ([5 x i8],[5 x i8]* @str.Main, i32 0, i32 0),
	%Main* () * @Main_new,
	%Object* (%Main*) * bitcast (%Object* (%Object*) * @Object_abort to %Object* (%Main*) *),
	%String* (%Main*) * bitcast (%String* (%Object*) * @Object_type_name to %String* (%Main*) *),
	%Main* (%Main*) * bitcast (%Object* (%Object*) * @Object_copy to %Main* (%Main*) *),
	%Object* (%Main*) * @Main_main
}

@str.2 = internal constant [14 x i8] c"<basic class>\00"
@String.2 = constant  %String {
	%String_vtable* @String_vtable_prototype,
	i8* getelementptr ([14 x i8],[14 x i8]* @str.2, i32 0, i32 0)
}

@str.1 = internal constant [15 x i8] c"Hi from Foo_f\0A\00"
@String.1 = constant  %String {
	%String_vtable* @String_vtable_prototype,
	i8* getelementptr ([15 x i8],[15 x i8]* @str.1, i32 0, i32 0)
}

@str.0 = internal constant [20 x i8] c"checkvoid_static.cl\00"
@String.0 = constant  %String {
	%String_vtable* @String_vtable_prototype,
	i8* getelementptr ([20 x i8],[20 x i8]* @str.0, i32 0, i32 0)
}

define i32 @main() {
entry:
	%vtpm.0 = call %Main* @Main_new(  )
	%main.returnValue = call %Object*(%Main* ) @Main_main( %Main* %vtpm.0 )
	ret i32 0
}

define %Object* @Foo_f(%Foo* %self) {

entry:
	%vtpm.1 = alloca %Foo*
	store %Foo* %self, %Foo** %vtpm.1
	%vtpm.2 = call %IO* @IO_new(  )
	%vtpm.3 = icmp eq %IO* %vtpm.2, null
	br i1 %vtpm.3, label %abort, label %tmp.0

tmp.0:
	%vtpm.4 = icmp eq %IO* %vtpm.2, null
	br i1 %vtpm.4, label %abort, label %tmp.1

tmp.1:
	%vtpm.5 = getelementptr %IO, %IO* %vtpm.2, i32 0, i32 0
	%vtpm.6 = load %IO_vtable*, %IO_vtable** %vtpm.5
	%vtpm.7 = getelementptr %IO_vtable, %IO_vtable* %vtpm.6, i32 0, i32 7
	%tmp.2 = load %IO* (%IO*,%String*) *, %IO* (%IO*,%String*) ** %vtpm.7
	%vtpm.8 = call %IO*(%IO*, %String* ) %tmp.2( %IO* %vtpm.2, %String* @String.1 )
	%vtpm.9 = bitcast %IO* %vtpm.8 to %Object*
	ret %Object* %vtpm.9

abort:
	call void @abort(  )
	unreachable
}

define %Foo* @Foo_new() {

entry:
	%vtpm.11 = getelementptr %Foo_vtable, %Foo_vtable* @Foo_vtable_prototype, i32 0, i32 1
	%vtpm.12 = load i32, i32* %vtpm.11
	%vtpm.13 = call i8*(i32 ) @malloc( i32 %vtpm.12 )
	%vtpm.14 = bitcast i8* %vtpm.13 to %Foo*
	%vtpm.15 = getelementptr %Foo, %Foo* %vtpm.14, i32 0, i32 0
	store %Foo_vtable* @Foo_vtable_prototype, %Foo_vtable** %vtpm.15
	%vtpm.16 = alloca %Foo*
	store %Foo* %vtpm.14, %Foo** %vtpm.16
	ret %Foo* %vtpm.14

abort:
	call void @abort(  )
	unreachable
}

define %Object* @Main_main(%Main* %self) {

entry:
	%vtpm.18 = alloca %Main*
	store %Main* %self, %Main** %vtpm.18
	%vtpm.19 = load %Main*, %Main** %vtpm.18
	%vtpm.20 = getelementptr %Main, %Main* %vtpm.19, i32 0, i32 1
	%vtpm.21 = load %Foo*, %Foo** %vtpm.20
	%vtpm.22 = icmp eq %Foo* %vtpm.21, null
	br i1 %vtpm.22, label %abort, label %tmp.0

tmp.0:
	%vtpm.23 = getelementptr %Foo_vtable, %Foo_vtable* @Foo_vtable_prototype, i32 0, i32 7
	%tmp.1 = load %Object* (%Foo*) *, %Object* (%Foo*) ** %vtpm.23
	%vtpm.24 = call %Object*(%Foo* ) %tmp.1( %Foo* %vtpm.21 )
	ret %Object* %vtpm.24

abort:
	call void @abort(  )
	unreachable
}

define %Main* @Main_new() {

entry:
	%vtpm.26 = getelementptr %Main_vtable, %Main_vtable* @Main_vtable_prototype, i32 0, i32 1
	%vtpm.27 = load i32, i32* %vtpm.26
	%vtpm.28 = call i8*(i32 ) @malloc( i32 %vtpm.27 )
	%vtpm.29 = bitcast i8* %vtpm.28 to %Main*
	%vtpm.30 = getelementptr %Main, %Main* %vtpm.29, i32 0, i32 0
	store %Main_vtable* @Main_vtable_prototype, %Main_vtable** %vtpm.30
	%vtpm.31 = alloca %Main*
	store %Main* %vtpm.29, %Main** %vtpm.31
	%vtpm.32 = load %Main*, %Main** %vtpm.31
	%vtpm.33 = getelementptr %Main, %Main* %vtpm.32, i32 0, i32 1
	store %Foo* null, %Foo** %vtpm.33
	ret %Main* %vtpm.29

abort:
	call void @abort(  )
	unreachable
}

