cat lista_uczniow.txt | while read line 
do
    rm -f $line.cpp
done
rm -rf images