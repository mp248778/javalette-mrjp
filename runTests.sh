echo "Good :"
for i in `ls examples/good/*.jl`
do
	echo $i
	./testJavalette < "$i" &> /dev/null
	if [ `echo $?` -eq 1 ]
	then
		echo "Blad w $i"
	fi
done

echo "Bad :"
for i in `ls examples/bad/*.jl`
do
	echo $i
	./testJavalette < "$i" &> /dev/null
	if [ `echo $?` -eq 0 ]
	then
		echo "Blad w $i"
	fi
done
