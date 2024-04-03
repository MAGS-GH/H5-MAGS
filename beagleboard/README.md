# BBB - BeagleBoardBlack

Enheden indeholder følgende:

    ARM CPU 32Bit, ofte brugt i Android

    512 MB ram

    4 GB flash - Debian OS, næst nyeste

    SD kort - 8GB udleveret, kan opgraderes

Documentation kan findes på [beagleboard.org](https://www.beagleboard.org/learn) & https://mars.merhot.dk/w/index.php/Beaglebone_Black 

Flash process - installere næst nyeste debian version

    1. Vi bruger det 8GB, sd-kort og lægger det et sted, hvor det ikke bliver væk. (ikke i enheden)

    2. Vi booter enheden ved at sætte den til strøm og internet. Tjek de blå lysdioder indtil de blinker. 

    3. Der burde være 4 filer ved opstart

    4. PuTTy speed 115200 - Serial port, med PORT fra enhedshåndtering COM9 (Måske)

    5. Vi burde se BeagleBone login: 

    username:password is [debian:temppwd]

    6. Herefter skulle vi gerne være common user - debian@BeagleBone

df -h -> h betyder humanReadable, df er diskfree se hvor meget plads der er brugt

/ er root stien, hvor linus er med filer og processer

/dev - device, hardware som filer

ls -l /dev/mmc* - Ser alle mmc filer

Vi sætter vores SD-kort i mens den kører

Vi skriver ls -l /dev/mmc* igen og burde se flere filer

mmcblk0 er vores SD-kort og hvis den er brugt kan vi se flere under det såsom p1 - partion 1

Vi går ind på mars.merhot.dk - [BBB-Flashing](https://mars.merhot.dk/w/index.php/Beaglebone_Black/Flashing)

Ved opstart af BBB er det vigtigt at du

    1. Ikke placerer boardet på ledende materiale (Metal fx)
    
    2. Tilslutter det serielle kabel - (Sort ledning skal vende op imod ethernet stikket)
    Se billede herunder
    
    3. Åbner terminalemulator for eksempel putty eller mobaXterm
        1. Find COM port nummeret og sæt baudRate til 115200

    5. Boot fra den indbyggede flash. (microSD kort ikke indsat)

    5. Login
    
    6. sudo bash
    
    7. Indsæt microSD kort
    
    8. Check at filen /dev/mmcblk0 eksisterer (Undgå at lave en fil)

    9. wget --no-check-certificate -qO- https://mars.merhot.dk/data/bbb/bone-debian-10.3-iot-armhf-2020-04-06-4gb.img.xz | xzcat | dd bs=10M of=/dev/mmcblk0 status=progress
    
    10. shutdown -r 0
    
    11. login
    
    12. df -h (Check at det er /dev/mmcblk0p1 der er under /)
    
    13. kør /opt/scripts/tools/grow_partition.sh

    14. shutdown -r 0

    15. check med df -h at ”/” har cirka 8 GB

    16. Install debian C linux development tools


Brug "ip a" for at se om man har fået tildelt en ip-addresse og om der er internet

Vi kan pinge 8.8.8.8 for at se om vi har internet - hvis der er forbindelse bliver den ved, brugt control+c for at stoppe den 

Vi kan tage IP-addressen fra "ip a" og SSH til maskinen hvis vi vil

