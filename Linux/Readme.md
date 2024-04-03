# Noter til Linux

## Dag 1 - 02/04

cd -> Change dir

pwd -> Print working directory

ls -> List - List dir

cat -> Vis indhold i fil

grep -> Søge funktion lignende Regular-Expressions

heth:x:1000:1000:Henrik Thomsen:/home/heth:/bin/bash

Bliver opdelt med ":"

heth er brugernavnet - bliver kun brugt, når vi skal vise noget på skærmen

x er indikation på at der er et hashed+saltet password som vi ikke kan læse, af sikkerhedsmæssige årsage

1000 er bruger id (Int er hurtigere at arbejde med end strings)

1000 er en gruppe som personen er en del af - det kunne være salgsgruppen

Henrik Thomsen er det fulde navn af brugeren. Her kan man også indeholde andre informationer, såsom telefon og mail. Værdierne skal være kommaseperet

/home/heth home folderen for brugeren

/bin/bash er stien eller programmer som skal åbne ved opstart

'|'
pipe kommanden i Linux, Opdeller kommandoen i n kommandoer, vi binder altså flere kommandoer sammen i en sekvens.

BASH - Born Again SHell

cat /etc/passwd | grep heth | cut -d':' -f5 | cut -d"," -f1

Ny bruger

IP: 93.166.84.21
User: ny
Pw: Easter2024.

User: mags
Pw: *************************************

## Dag 2 - 02/04

bs -> Lommeregner, lave variabler | Basic Calculator

.$ - Common user

.# - Sudo (Brug den kun, når det er strengt nødvendigt)

Alle processer har 3 standarter, STDIN, STDOUT og STDERR | STD er standart

STDIN -> Tastatur

STDOUT og STDEER -> Skærm for brugeren

STDIN = 0, STDOUT = 1, STDERR = 2. 

Redirect: > omdiriger STDOUT - Skrive hvad der ellers ville komme over i VDV til en fil såsom regne.r

1> Redirect STDOUT 

2> Redirect STDERR

C er compiled sprog

Python er procedual

Tiobe Index - Mest populære programmeringssprog ud fra search engines

WC - Word Count

man --> Manual, fx man wc 

    NAME
        wc - print newline, word, and byte counts for each file

    SYNOPSIS
        wc [OPTION]... [FILE]...
        wc [OPTION]... --files0-from=F

    DESCRIPTION
        Print  newline,  word, and byte counts for each FILE, and a total line if more than one FILE is specified.  A
        word is a non-zero-length sequence of characters delimited by white space.

find . -name '*.c'

find . -name '*.c' | wc

find . -name '*.c' -exec cat {} \; | wc -l
Finder alle filer af typen C, åbner dem og tæller antal linjer. | er vigtig

gcc er gnu compiler - [link](https://gcc.gnu.org/)

"mags@h5:~/H5-MAGS/CProgrammering$ gcc hw.c -o hw"- laver en compilet C-binær fil, kaldet hw, som man kan køre med ./hw - den skal compileres før den kan køre på en windows eller embedded-enhed


