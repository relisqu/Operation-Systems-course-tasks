if test ! -f numbersNR
then
    echo 0 > numbersNR
fi

if ln numbersNR numbers.lock
  then
  for i in 'seq 1 100':
  do
    n=$(tail -n  1 < numbers)
    expr $n + 1 >> numbers
  done    
  rm numbers.lock
fi
