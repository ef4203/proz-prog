#
# Das erste Makefile
# ------------------
#
# Ein Makefile ist eine Art "Kochbuch" mit Rezepten fuer den Zusammenbau
# eines Programms. Hier in der Vorlesung mit der Dateiendung ".exe"
# (EXEcutable = ausfuehrbar) gekennzeichnet.
#
# Definiert wird ein Rezept "all" zum Erstellen von der ausfuehrbaren
# Datei "blatt01_2.exe" aus der Quelldatei "blatt01_2.c", wenn in der
# Kommandozeile der Befehl
#
#   "make" bzw. "mingw32-make" unter Windows
#
# eingegeben wird. Was die einzelnen Parameter hinter "gcc" bedeuten,
# entnehmen Sie den folgenden Links:
#
#   -std=c99
#   https://gcc.gnu.org/onlinedocs/gcc/C-Dialect-Options.html
#
#   -pedantic -Wall -Wextra
#   https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html
#
#   -o
#   https://gcc.gnu.org/onlinedocs/gcc/Overall-Options.html
#
#
# ACHTUNG: Vor "gcc" muss ein TAB-Zeichen stehen. Leerzeichen reichen nicht.
#          Mehr Informationen unter:
#
#   https://www.gnu.org/software/make/manual/make.html#Rule-Introduction
#

all:
	clang -std=c99 -pedantic -Wall -Wextra -o blatt01_1.exe blatt01_1.c
	./blatt01_1.exe
	clang -std=c99 -pedantic -Wall -Wextra -o blatt01_3.exe blatt01_3.c
	./blatt01_3.exe
