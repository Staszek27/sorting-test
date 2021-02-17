# What is it for?

It was created to test students' skills in sorting techniques. You need Mac/Linux OS to use this tool.

# How to use it?

1. Fill "lista_uczniow.txt" with names of your students.
2. Generate template by launching "generuj_template.py" script
3. Send that template to your pupils. 
4. Generate files for pupils by launching "generuj_pliki_dla_uczniów.sh"
5. Get filled functions from pupils.

| :mag_right: Students can test locally their solutions changing these lines in "kod.cpp":   |
|-------------------------------------------|
![image](https://i.imgur.com/RXgLme0.png)


6. Copy the content of the students's functions to the generated files.


7. Launch "generuj_rezultaty_uczniow.sh". It creates images folder with solutions.

![image](https://i.imgur.com/Itdqkwo.png)


# Options summary

Clear results and work files

```
$ ./czysc_wszystko.sh
``` 

Generate template for windows:

```
$ python3.9 generuj_template.py
``` 

Generate personal file for every student 

```
$ ./generuj_pliki_dla_uczniow.sh
```

Generate final results

```
$ ./generuj_rezultaty_uczniow.sh
```