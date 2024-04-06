# Noter til PrimeNumber opgaven

Opgave - Skriv de første 10.000 primtal i et C-program. Det er ikke tilladt at bruge chatGPT og Henrik forventer at man kan forklare det helt i dybden!

a whole number greater than 1 that cannot be exactly divided by any whole number other than itself and 1 (e.g. 2, 3, 5, 7, 11).

Funtioner skal være over main, de bliver ikke hoistet

Prøvede at bruge følgende [kilde](https://www.vedantu.com/maths/how-to-find-prime-numbers), men den havde forkert information

Primtal Nummer 10000; 104729 
Det tog 1.50, sekunder at regne de første 10.000 primtal ud! 


Tjek tid uden print med - mags@h5:~/H5-MAGS/CProgrammering/Primtal$ time ./PrimeNumbers >/dev/null

real    0m0.014s
user    0m0.013s
sys     0m0.000s

">" sender output ud til "skralespanen"

Metode 3 - ```i*i <= num``` eller Metode 2 ```i < num/2 ```  Metode 1 ``` i < num```

    Eksempel med num = 229

    Metode 1 rammer ved i = 228
    Metode 2 rammer ved 115 
    Metode 3 allerede ved 16. 
    Altså samme beregning med færre trin!

Hvad er primtal? Primtal er hvor følgende er sandt 

$$ \nexists (\, p = a * b), \, hvor \, p,a,b \in (\mathbb{N} \,| \, 0,1) \, og \, p = \mathbb{P} $$

p er et primtal og der findes altså ikke heltal hvor a * b giver tallet, derfor er det et primtal.

Ud fra formelen kan vi også konkludere at 

$$ a \ngtr \sqrt p \, | \, b > \sqrt p \,\, og \,\,  b \ngtr \sqrt 2 \, |\, a > \sqrt p $$



## Opgave fra Onsdag til Fredag

    [13:48] Henrik Thomsen
    BBB @ home
    TIlslut BBB til Internettet.
    
    Kopier og indsæt dette script i terminalen for at installerere udviklingsværktøjer: https://mars.merhot.dk/w/index.php/C_linux_development
    
    Overfør jeres primtals source kode til BBB og kompiler den der. 
    
    Find fx. 100000 primtal og tag tid på hvor lang tid programmet bruger på både BBB og min server. (For at få en fornemmelse at performance)
    
    Anvend time programmet for at tage tid på afviklingen. Fx - time ./primtal
    like 2
    C linux development - Teknologisk videncenter


Tid på BBB

    Primtal Nummer 9999; 104723 
    Primtal Nummer 10000; 104729 
    Det tog 0.449232999999999993434585121577, sekunder at regne de første 10.000 primtal ud!

Tid på HT-Server

    Primtal Nummer 9998; 104717 
    Primtal Nummer 9999; 104723 
    Primtal Nummer 10000; 104729 
    Det tog 0.895341000000000053482551720663, sekunder at regne de første 10.000 primtal ud! 

