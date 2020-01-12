; ModuleID = '<stdin>'
target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

@.str = private unnamed_addr constant [9 x i8] c"b = %ld\0A\00", align 1

; Function Attrs: nounwind uwtable
define i32 @main() #0 {
  %A = alloca [100 x i64], align 16
  br label %1

; <label>:1                                       ; preds = %5, %0
  %i.0 = phi i64 [ 0, %0 ], [ %6, %5 ]
  %2 = icmp slt i64 %i.0, 100
  br i1 %2, label %3, label %7

; <label>:3                                       ; preds = %1
  %4 = getelementptr inbounds [100 x i64]* %A, i64 0, i64 %i.0
  store i64 %i.0, i64* %4, align 8
  br label %5

; <label>:5                                       ; preds = %3
  %6 = add nsw i64 %i.0, 1
  br label %1

; <label>:7                                       ; preds = %1
  %8 = getelementptr inbounds [100 x i64]* %A, i64 0, i64 0
  %9 = load i64* %8, align 16
  br label %10

; <label>:10                                      ; preds = %22, %7
  %b.0 = phi i64 [ %9, %7 ], [ %b.1, %22 ]
  %a.0 = phi i64 [ %9, %7 ], [ %a.1, %22 ]
  %i.1 = phi i64 [ 0, %7 ], [ %23, %22 ]
  %sum.0 = phi i64 [ 0, %7 ], [ %15, %22 ]
  %11 = icmp slt i64 %i.1, 100
  br i1 %11, label %12, label %24

; <label>:12                                      ; preds = %10
  %13 = getelementptr inbounds [100 x i64]* %A, i64 0, i64 %i.1
  %14 = load i64* %13, align 8
  %15 = add nsw i64 %sum.0, %14
  %16 = icmp slt i64 %15, %b.0
  br i1 %16, label %17, label %19

; <label>:17                                      ; preds = %12
  %18 = mul nsw i64 %a.0, %15
  br label %21

; <label>:19                                      ; preds = %12
  %20 = mul nsw i64 %b.0, %15
  br label %21

; <label>:21                                      ; preds = %19, %17
  %b.1 = phi i64 [ %b.0, %17 ], [ %20, %19 ]
  %a.1 = phi i64 [ %18, %17 ], [ %a.0, %19 ]
  br label %22

; <label>:22                                      ; preds = %21
  %23 = add nsw i64 %i.1, 1
  br label %10

; <label>:24                                      ; preds = %10
  %25 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([9 x i8]* @.str, i64 0, i64 0), i64 %b.0) #2
  ret i32 0
}

declare i32 @printf(i8*, ...) #1

attributes #0 = { nounwind uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #2 = { nounwind }

!llvm.ident = !{!0}

!0 = metadata !{metadata !"clang version 3.5.0 "}
