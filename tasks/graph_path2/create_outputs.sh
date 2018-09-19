for file in input/input*.txt
do
   ./main < $file > "output/output${file#input/input}"
done
