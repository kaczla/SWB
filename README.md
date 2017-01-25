# SWB
##### Systemy wbudowane

Opis:
Wyświetla listę plików ze ścieżki, która została podana przy arguemntu **-p ścieżka** (w przypadku braku arguemntu zostanie ustawiona aktualna ścieżka).

1) Zbudować przy pomocy polecenie **make**
2) Uruchomić poleceniem **./run -p ścieżka**

Przykładowe uruchomomienie: **./run -p /home**

**Budowanie dla Raspberry Pi**
1) Zmienić ścieżkę do GCC dla Raspberry PI w pliku **makefile.mk**\*
2) Zbudować przy pomocy polecenie **make arm** (w przypaku wcześniejszego budowania poleceniem **make** należy wyczyścić poleceniem **make clean**)

\*pobranie narzędzi dla Raspberry PI do katalogu **/tmp**:
1) cd /tmp
2) git clone https://github.com/raspberrypi/tools.git --depth=1
