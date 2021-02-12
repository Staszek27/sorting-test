cat lista_uczniow.txt | while read line 
do
   cp kod.cpp $line.cpp
done