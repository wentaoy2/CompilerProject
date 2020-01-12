; ModuleID = '<stdin>'
target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

%struct._IO_FILE = type { i32, i8*, i8*, i8*, i8*, i8*, i8*, i8*, i8*, i8*, i8*, i8*, %struct._IO_marker*, %struct._IO_FILE*, i32, i32, i64, i16, i8, [1 x i8], i8*, i64, i8*, i8*, i8*, i8*, i64, i32, [20 x i8] }
%struct._IO_marker = type { %struct._IO_marker*, %struct._IO_FILE*, i32 }
%struct.twoInt = type { i32, i32 }

@stderr = external global %struct._IO_FILE*
@.str = private unnamed_addr constant [21 x i8] c"USAGE: licm a b c d\0A\00", align 1
@i2 = common global %struct.twoInt zeroinitializer, align 4
@.str1 = private unnamed_addr constant [22 x i8] c"%d %d %d %d %d %d %d\0A\00", align 1

; Function Attrs: nounwind uwtable
define i32 @main(i32 %argc, i8** %argv) #0 {
  %1 = icmp slt i32 %argc, 5
  br i1 %1, label %2, label %5

; <label>:2                                       ; preds = %0
  %3 = load %struct._IO_FILE** @stderr, align 8
  %4 = call i64 @fwrite(i8* getelementptr inbounds ([21 x i8]* @.str, i64 0, i64 0), i64 20, i64 1, %struct._IO_FILE* %3) #5
  call void @exit(i32 1) #6
  unreachable

; <label>:5                                       ; preds = %0
  %6 = getelementptr inbounds i8** %argv, i64 1
  %7 = load i8** %6, align 8
  %8 = call i32 @atoi(i8* %7) #7
  %9 = getelementptr inbounds i8** %argv, i64 2
  %10 = load i8** %9, align 8
  %11 = call i32 @atoi(i8* %10) #7
  %12 = getelementptr inbounds i8** %argv, i64 3
  %13 = load i8** %12, align 8
  %14 = call i32 @atoi(i8* %13) #7
  %15 = getelementptr inbounds i8** %argv, i64 4
  %16 = load i8** %15, align 8
  %17 = call i32 @atoi(i8* %16) #7
  store i32 %8, i32* getelementptr inbounds (%struct.twoInt* @i2, i64 0, i32 0), align 4
  store i32 %11, i32* getelementptr inbounds (%struct.twoInt* @i2, i64 0, i32 1), align 4
  br label %18

; <label>:18                                      ; preds = %39, %5
  %d.0 = phi i32 [ %17, %5 ], [ %d.1, %39 ]
  %a.0 = phi i32 [ %8, %5 ], [ %a.1, %39 ]
  %x.0 = phi i32 [ undef, %5 ], [ %x.1, %39 ]
  %j.0 = phi i32 [ 0, %5 ], [ %40, %39 ]
  %19 = icmp slt i32 %j.0, %11
  br i1 %19, label %20, label %41

; <label>:20                                      ; preds = %18
  br label %21

; <label>:21                                      ; preds = %34, %20
  %d.1 = phi i32 [ %d.0, %20 ], [ %d.2, %34 ]
  %a.1 = phi i32 [ %a.0, %20 ], [ %35, %34 ]
  %x.1 = phi i32 [ %x.0, %20 ], [ %29, %34 ]
  %i.0 = phi i32 [ 0, %20 ], [ %36, %34 ]
  %22 = icmp slt i32 %i.0, %14
  br i1 %22, label %23, label %37

; <label>:23                                      ; preds = %21
  %24 = sdiv i32 %14, %11
  %25 = mul nsw i32 %11, %j.0
  %26 = add nsw i32 %24, %25
  %27 = mul nsw i32 %11, %j.0
  %28 = load i32* getelementptr inbounds (%struct.twoInt* @i2, i64 0, i32 0), align 4
  %29 = add nsw i32 %27, %28
  %30 = icmp eq i32 %j.0, %i.0
  br i1 %30, label %31, label %33

; <label>:31                                      ; preds = %23
  %32 = mul nsw i32 %26, %14
  br label %33

; <label>:33                                      ; preds = %31, %23
  %d.2 = phi i32 [ %32, %31 ], [ %d.1, %23 ]
  br label %34

; <label>:34                                      ; preds = %33
  %35 = sub nsw i32 %26, %14
  %36 = add nsw i32 %i.0, 1
  br label %21

; <label>:37                                      ; preds = %21
  %38 = add nsw i32 %11, %14
  store i32 %38, i32* getelementptr inbounds (%struct.twoInt* @i2, i64 0, i32 1), align 4
  br label %39

; <label>:39                                      ; preds = %37
  %40 = add nsw i32 %j.0, 1
  br label %18

; <label>:41                                      ; preds = %18
  %42 = load i32* getelementptr inbounds (%struct.twoInt* @i2, i64 0, i32 0), align 4
  %43 = load i32* getelementptr inbounds (%struct.twoInt* @i2, i64 0, i32 1), align 4
  %44 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([22 x i8]* @.str1, i64 0, i64 0), i32 %a.0, i32 %11, i32 %14, i32 %d.0, i32 %x.0, i32 %42, i32 %43) #4
  ret i32 0
}

declare i32 @fprintf(%struct._IO_FILE*, i8*, ...) #1

; Function Attrs: noreturn nounwind
declare void @exit(i32) #2

; Function Attrs: nounwind readonly
declare i32 @atoi(i8*) #3

declare i32 @printf(i8*, ...) #1

; Function Attrs: nounwind
declare i64 @fwrite(i8* nocapture, i64, i64, %struct._IO_FILE* nocapture) #4

attributes #0 = { nounwind uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #2 = { noreturn nounwind "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #3 = { nounwind readonly "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #4 = { nounwind }
attributes #5 = { cold }
attributes #6 = { noreturn nounwind }
attributes #7 = { nounwind readonly }

!llvm.ident = !{!0}

!0 = metadata !{metadata !"clang version 3.5.0 "}
