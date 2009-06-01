export PATH=$PATH:~/llvm/bin/
./Javalette < tmp  | sed s/main[0-9]*/main/ > asd.ll
llvm-as -f asd.ll
llc -march=x86-64 asd.bc -f
gcc -g asd.s
./a.out
echo $?
