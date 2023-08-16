#/bin/bash
rojo='\033[31m'
verde='\033[32m'
naranja='\033[33m'
pred='\033[39m'

num1=1
num2=1
errors_100=0
errors_500=0
MEDIA_100=0
MEDIA_500=0

OS=$(uname -s)

# Check OS
if [[ "$OS" == "Linux" ]]; then
    # Linux
	COMMAND=./checker_linux
else
    # MacOS
    COMMAND=./checker_Mac
fi
#COMMAND=./checker
echo "####---------------------------------------------####"
echo "Inicio test" #> yes
echo "####---------------------------------------------####"

echo "####---------------------------------------------####"
echo "Inicio test 500 números" #>> yes
echo "####---------------------------------------------####"
while [ $num2 -le 5 ];
do
	ARG=$(seq -500 500 | sort -R | tail -n 500 | tr '\n' ' ')
	echo $ARG #>> yes
	echo "---------------------------------------------"
	echo "Nº órdenes: "
	COUNT=$(./push_swap $ARG | wc -l)
	if [ $COUNT -le 5500 ];
	then
		printf "$verde"
		echo $COUNT #>>yes
	else
		printf "$rojo"
		echo $COUNT #>>yes
		errors_500=$((errors_500+1))
	fi
	printf "$pred"
	echo "---------------------------------------------"
	echo "---------------------------------------------"
	echo "Resultado checker: "
	./push_swap $ARG | $COMMAND $ARG
	echo "---------------------------------------------"
	MEDIA_500=$(($MEDIA_500+$COUNT))
	num2=$(($num2+1))
done

echo "####---------------------------------------------####"
echo "Inicio test 100 números" #>> yes
echo "####---------------------------------------------####"
while [ $num1 -le 5 ];
do
	ARG=$(seq -1000 1000 | sort -R | tail -n 100 | tr '\n' ' ')
	echo $ARG #>> yes
	echo "---------------------------------------------"
	echo "Nº órdenes: "
	COUNT=$(./push_swap $ARG | wc -l)
	if [ $COUNT -le 700 ];
	then
		printf "$verde"
		echo $COUNT #>>yes
	else
		print "$rojo"
		echo $COUNT #>>yes
		errors_100=$((errors_100+1))
	fi
	printf "$pred"
	echo "---------------------------------------------"
	echo "---------------------------------------------"
	echo "Resultado checker: "
	./push_swap $ARG | $COMMAND $ARG
	echo "---------------------------------------------"
	MEDIA_100=$(($MEDIA_100+$COUNT))
	num1=$(($num1+1))
done

echo "####---------------------------------------------####"
echo "Inicio test erróneos" #>> yes
echo "####---------------------------------------------####"
ARG="1 a 3"
echo $ARG
echo "---------------------------------------------"
echo "Nº órdenes: "
COUNT=$(./push_swap $ARG | wc -l)
echo $COUNT
echo "---------------------------------------------"
echo "---------------------------------------------"
echo "Resultado checker: "
./push_swap $ARG | $COMMAND $ARG
echo "---------------------------------------------"
ARG=""
echo $ARG
echo "---------------------------------------------"
echo "Nº órdenes: "
COUNT=$(./push_swap $ARG | wc -l)
echo $COUNT
echo "---------------------------------------------"
echo "---------------------------------------------"
echo "Resultado checker: "
./push_swap $ARG | $COMMAND $ARG
echo "---------------------------------------------"
ARG="1 dos 2"
echo $ARG
echo "---------------------------------------------"
echo "Nº órdenes: "
COUNT=$(./push_swap $ARG | wc -l)
echo $COUNT
echo "---------------------------------------------"
echo "---------------------------------------------"
echo "Resultado checker: "
./push_swap $ARG | $COMMAND $ARG
echo "---------------------------------------------"
ARG="1 7 2 9 2 3 12"
echo $ARG
echo "---------------------------------------------"
echo "Nº órdenes: "
COUNT=$(./push_swap $ARG | wc -l)
echo $COUNT
echo "---------------------------------------------"
echo "---------------------------------------------"
echo "Resultado checker: "
./push_swap $ARG | $COMMAND $ARG
echo "---------------------------------------------"
echo "####---------------------------------------------####"
echo "Inicio test tres números" #>> yes
echo "####---------------------------------------------####"
ARG="1 2 3"
echo $ARG
echo "---------------------------------------------"
echo "Nº órdenes: "
COUNT=$(./push_swap $ARG | wc -l)
echo $COUNT
echo "---------------------------------------------"
echo "---------------------------------------------"
echo "Resultado checker: "
./push_swap $ARG | $COMMAND $ARG
echo "---------------------------------------------"
ARG="1 3 2"
echo $ARG
echo "---------------------------------------------"
echo "Nº órdenes: "
COUNT=$(./push_swap $ARG | wc -l)
echo $COUNT
echo "---------------------------------------------"
echo "---------------------------------------------"
echo "Resultado checker: "
./push_swap $ARG | $COMMAND $ARG
echo "---------------------------------------------"
ARG="2 1 3"
echo $ARG
echo "---------------------------------------------"
echo "Nº órdenes: "
COUNT=$(./push_swap $ARG | wc -l)
echo $COUNT
echo "---------------------------------------------"
echo "---------------------------------------------"
echo "Resultado checker: "
./push_swap $ARG | $COMMAND $ARG
echo "---------------------------------------------"
ARG="2 3 1"
echo $ARG
echo "---------------------------------------------"
echo "Nº órdenes: "
COUNT=$(./push_swap $ARG | wc -l)
echo $COUNT
echo "---------------------------------------------"
echo "---------------------------------------------"
echo "Resultado checker: "
./push_swap $ARG | $COMMAND $ARG
echo "---------------------------------------------"
ARG="3 2 1"
echo $ARG
echo "---------------------------------------------"
echo "Nº órdenes: "
COUNT=$(./push_swap $ARG | wc -l)
echo $COUNT
echo "---------------------------------------------"
echo "---------------------------------------------"
echo "Resultado checker: "
./push_swap $ARG | $COMMAND $ARG
echo "---------------------------------------------"
ARG="3 1 2"
echo $ARG
echo "---------------------------------------------"
	echo "Nº órdenes: "
COUNT=$(./push_swap $ARG | wc -l)
echo $COUNT
echo "---------------------------------------------"
echo "---------------------------------------------"
	echo "Resultado checker: "
./push_swap $ARG | $COMMAND $ARG
echo "---------------------------------------------"
echo "####---------------------------------------------####"
echo "Inicio test cinco números" #>> yes
echo "####---------------------------------------------####"
ARG="1 2 3 4 5"
echo $ARG
echo "---------------------------------------------"
echo "Nº órdenes: "
COUNT=$(./push_swap $ARG | wc -l)
echo $COUNT
echo "---------------------------------------------"
echo "---------------------------------------------"
echo "Resultado checker: "
./push_swap $ARG | $COMMAND $ARG
echo "---------------------------------------------"
ARG="5 4 3 2 1"
echo $ARG
echo "---------------------------------------------"
echo "Nº órdenes: "
COUNT=$(./push_swap $ARG | wc -l)
echo $COUNT
echo "---------------------------------------------"
echo "---------------------------------------------"
echo "Resultado checker: "
./push_swap $ARG | $COMMAND $ARG
echo "---------------------------------------------"
ARG="1 4 3 5 2"
echo $ARG
echo "---------------------------------------------"
echo "Nº órdenes: "
COUNT=$(./push_swap $ARG | wc -l)
echo $COUNT
echo "---------------------------------------------"
echo "---------------------------------------------"
echo "Resultado checker: "
./push_swap $ARG | $COMMAND $ARG
echo "---------------------------------------------"

echo "####---------------------------------------------####"
echo "Inicio otros tests" #>> yes
echo "####---------------------------------------------####"
ARG="1"
echo $ARG
echo "---------------------------------------------"
echo "Nº órdenes: "
COUNT=$(./push_swap $ARG | wc -l)
echo $COUNT
echo "---------------------------------------------"
echo "---------------------------------------------"
echo "Resultado checker: "
./push_swap $ARG | $COMMAND $ARG
echo "---------------------------------------------"
ARG=""
echo $ARG
echo "---------------------------------------------"
echo "Nº órdenes: "
COUNT=$(./push_swap $ARG | wc -l)
echo $COUNT
echo "---------------------------------------------"
echo "---------------------------------------------"
echo "Resultado checker: "
./push_swap $ARG | $COMMAND $ARG
echo "---------------------------------------------"
ARG="1 ' '"
echo $ARG
echo "---------------------------------------------"
echo "Nº órdenes: "
COUNT=$(./push_swap $ARG | wc -l)
echo $COUNT
echo "---------------------------------------------"
echo "---------------------------------------------"
echo "Resultado checker: "
./push_swap $ARG | $COMMAND $ARG
echo "---------------------------------------------"

MEDIA_100=$(($MEDIA_100/$((num1-1))))
MEDIA_500=$(($MEDIA_500/$((num2-1))))
if [ $MEDIA_100 -le 700 ]
then
		printf "$verde"
else
		printf "$rojo"
fi
echo "Media 100: $MEDIA_100" # >> yes
if [ $MEDIA_500 -le 5500 ]
then
		printf "$verde"
else
		printf "$rojo"
fi
echo "Media 500: $MEDIA_500" # >> yes
perc=$((100*$errors_100/$((num1-1))))
if [ $perc -le 10 ]
then
		printf "$verde"
elif [ $perc -le 25 ]
then
		printf "$naranja"
else
		printf "$rojo"
fi
echo "Errores en $((num1-1)) listas de 100 números: $errors_100 ($perc %)"
perc=$((100*$errors_500/$((num2-1))))
if [ $perc -le 10 ]
then
		printf "$verde"
elif [ $perc -le 25 ]
then
		printf "$naranja"
else
		printf "$rojo"
fi
echo "Errores en $((num2-1)) listas de 500 números: $errors_500 ($perc %)"
printf "$pred"
