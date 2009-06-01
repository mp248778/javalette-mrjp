./Javalette < tmp  | sed s/main6/main/ > asd.ll
llvm-as -f asd.ll
llc -march=x86-64 asd.bc -f
gcc -g asd.s
./a.out
