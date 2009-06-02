export PATH=$PATH:~/llvm/bin/
echo "Good :"
for i in `ls examples/extensions/for/*.jl`
do
	echo $i
	./testJavalette < "$i" | sed s/main[0-9]*/main/ > asd.ll
	llvm-as -f asd.ll 
	llc -march=x86-64 asd.bc -f
	g++ asd.s -ljavalette -L./stdlib
	./a.out 
	if [ `echo $?` -eq 1 ]
	then
		echo "Blad w $i"
	fi
done

#echo "Bad :"
#for i in `ls examples/bad/*.jl`
##do
#	echo $i
#	./testJavalette < "$i" &> /dev/null
#	if [ `echo $?` -eq 0 ]
#	then
#		echo "Blad w $i"
#	fi
#done
