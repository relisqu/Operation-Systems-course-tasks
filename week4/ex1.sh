a=10
until [ $a -lt 0 ]
do
a=`expr $a - 1`
./ex1
done
