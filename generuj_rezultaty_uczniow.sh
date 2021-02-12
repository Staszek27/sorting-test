
cat lista_uczniow.txt | while read line 
do
   make $line
   mkdir results
   rm -f results/$line.txt
   for sort_name in selection_sort insertion_sort bubble_sort quick_sort
    do
    for i in {1..10}
    do
        j=$(($i * 1000))
        echo $line $j $sort_name
        echo $j $sort_name >> results/$line.txt
        ./$line $j $sort_name >> results/$line.txt
    done
   done
   rm -f $line
done

python3 check_results.py
rm -rf results
