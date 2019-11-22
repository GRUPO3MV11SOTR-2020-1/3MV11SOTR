EXE := Test.exe
SRC := main.c funcion.c


default: $(EXE)
all:app

app:main.o exit.o archivo.o
	gcc -m32 $^ -o $@

main.o:main.c
	gcc -c $< -o $@

exit.o:exit.s
	as --32 $< -o $@

archivo.o:archivo.c
	gcc -c $<

$(EXE): $(SRC)
	gcc -DVERSION_JULIO $^ -o $@
clean:
	rm -vf main.o exit.o archivo.o app $(EXE)
