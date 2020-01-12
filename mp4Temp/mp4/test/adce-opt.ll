; ModuleID = '<stdin>'
target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

@.str = private unnamed_addr constant [9 x i8] c"b = %ld\0A\00", align 1

; Function Attrs: nounwind uwtable
define i32 @main() #0 {
  %A = alloca [100 x i64], align 16
  br label %1

; <label>:1                                       ; preds = %3, %0
  %i.0 = phi i64 [ 0, %0 ], [ %5, %3 ]
  %2 = icmp slt i64 %i.0, 100
  br i1 %2, label %3, label %6

; <label>:3                                       ; preds = %1
  %4 = getelementptr inbounds [100 x i64]* %A, i64 0, i64 %i.0
  store i64 %i.0, i64* %4, align 8
  %5 = add nsw i64 %i.0, 1
  br label %1

; <label>:6                                       ; preds = %1
  %7 = getelementptr inbounds [100 x i64]* %A, i64 0, i64 0
  %8 = load i64* %7, align 16
  br label %9

; <label>:9                                       ; preds = %18, %6
  %b.0 = phi i64 [ %8, %6 ], [ %b.1, %18 ]
  %i.1 = phi i64 [ 0, %6 ], [ %19, %18 ]
  %sum.0 = phi i64 [ 0, %6 ], [ %14, %18 ]
  %10 = icmp slt i64 %i.1, 100
  br i1 %10, label %11, label %20

; <label>:11                                      ; preds = %9
  %12 = getelementptr inbounds [100 x i64]* %A, i64 0, i64 %i.1
  %13 = load i64* %12, align 8
  %14 = add nsw i64 %13, %sum.0
  %15 = icmp slt i64 %14, %b.0
  br i1 %15, label %18, label %16

; <label>:16                                      ; preds = %11
  %17 = mul nsw i64 %14, %b.0
  br label %18

; <label>:18                                      ; preds = %16, %11
  %b.1 = phi i64 [ %17, %16 ], [ %b.0, %11 ]
  %19 = add nsw i64 %i.1, 1
  br label %9

; <label>:20                                      ; preds = %9
  %21 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([9 x i8]* @.str, i64 0, i64 0), i64 %b.0) #2
  ret i32 0
}

declare i32 @printf(i8*, ...) #1

attributes #0 = { nounwind uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #2 = { nounwind }

!llvm.ident = !{!0}

!0 = metadata !{metadata !"clang version 3.5.0 "}
