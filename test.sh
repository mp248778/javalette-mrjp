export PATH=$PATH:~/llvm/bin/
./testJavalette < tmp  | sed s/main[0-9]*/main/ > asd.ll
llvm-as -f asd.ll
llc -march=x86-64 asd.bc -f
g++ asd.s -ljavalette -L./stdlib
./a.out
