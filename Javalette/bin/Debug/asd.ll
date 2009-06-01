; ModuleID = 'Javalette'

define i32 @lala6(i32 %x8) {
entry:
	%x81 = alloca i32		; <i32*> [#uses=4]
	store i32 %x8, i32* %x81
	%tmpvar = load i32* %x81		; <i32> [#uses=1]
	%tmpvar2 = alloca i32		; <i32*> [#uses=2]
	store i32 0, i32* %tmpvar2
	%tmpvar3 = load i32* %tmpvar2		; <i32> [#uses=1]
	%igetmp = icmp sgt i32 %tmpvar, %tmpvar3		; <i1> [#uses=1]
	br i1 %igetmp, label %true_body, label %false_body

true_body:		; preds = %entry
	%tmpvar4 = load i32* %x81		; <i32> [#uses=1]
	%tmpvar5 = load i32* %x81		; <i32> [#uses=1]
	%subtmp = sub i32 %tmpvar4, %tmpvar5		; <i32> [#uses=1]
	%0 = call i32 @lala6(i32 %subtmp)		; <i32> [#uses=1]
	ret i32 %0

false_body:		; preds = %entry
	%tmpvar6 = alloca i32		; <i32*> [#uses=2]
	store i32 10, i32* %tmpvar6
	%tmpvar7 = load i32* %tmpvar6		; <i32> [#uses=1]
	ret i32 %tmpvar7
}

define i32 @main() {
entry:
	%tmpvar = alloca i32		; <i32*> [#uses=2]
	store i32 3, i32* %tmpvar
	%tmpvar1 = load i32* %tmpvar		; <i32> [#uses=1]
	%i9 = alloca i32		; <i32*> [#uses=7]
	store i32 %tmpvar1, i32* %i9
	%tmpvar2 = alloca i32		; <i32*> [#uses=2]
	store i32 4, i32* %tmpvar2
	%tmpvar3 = load i32* %tmpvar2		; <i32> [#uses=1]
	store i32 %tmpvar3, i32* %i9
	%tmpvar4 = load i32* %i9		; <i32> [#uses=0]
	br label %cond

for:		; preds = %cond
	%tmpvar5 = alloca i32		; <i32*> [#uses=2]
	store i32 3, i32* %tmpvar5
	%tmpvar6 = load i32* %tmpvar5		; <i32> [#uses=1]
	%a10 = alloca i32		; <i32*> [#uses=1]
	store i32 %tmpvar6, i32* %a10
	br label %afterCompoundInstr

afterCompoundInstr:		; preds = %for
	%tmpvar7 = load i32* %i9		; <i32> [#uses=1]
	%tmpvar8 = add i32 %tmpvar7, 1		; <i32> [#uses=1]
	store i32 %tmpvar8, i32* %i9
	br label %cond

cond:		; preds = %afterCompoundInstr, %entry
	%tmpvar9 = load i32* %i9		; <i32> [#uses=1]
	%tmpvar10 = alloca i32		; <i32*> [#uses=2]
	store i32 4, i32* %tmpvar10
	%tmpvar11 = load i32* %tmpvar10		; <i32> [#uses=1]
	%0 = call i32 @lala6(i32 %tmpvar11)		; <i32> [#uses=1]
	%igetmp = icmp slt i32 %tmpvar9, %0		; <i1> [#uses=1]
	br i1 %igetmp, label %for, label %merge

merge:		; preds = %cond
	%tmpvar12 = load i32* %i9		; <i32> [#uses=1]
	ret i32 %tmpvar12
}
