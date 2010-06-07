#Makefile

CC = gcc

CFLAGS = -O3 -march=native -mtune=native -pipe -Wall -fomit-frame-pointer  

OBJECTS_ALL = \
	$(OBJECTS_PALINDROMO) \
	$(OBJECTS_COLA_ABS) \
	$(OBJECTS_PERROS) \
	$(OBJECTS_LISTA_EMP) \
	$(OBJECTS_ARBOLB) \
	$(OBJECTS_PERROSM)

XFILES= \
	./Palindromo \
	./Analisa \
	./ColaAbstracta \
	./Perros \
	./ListaEmp \
	./ArbolB \
	./PerrosM

#-----------------------------------------------------------> 
#-----------------------------------------------------------> 

OBJECTS_PALINDROMO = ./temporales/interfazPila.o
HEADERS_PALINDROMO = ./encabezados/interfazPila.h

OBJECTS_COLA_ABS = ./temporales/interfazCola.o ./temporales/imprimeTipos.o
HEADERS_COLA_ABS = ./encabezados/interfazCola.h ./encabezados/imprimeTipos.h

OBJECTS_PERROS = ./temporales/interfazPerros.o 
HEADERS_PERROS = ./encabezados/interfazPerros.h ./encabezados/DBPerros.h 

OBJECTS_LISTA_EMP = ./temporales/interfazListaEmp.o 
HEADERS_LISTA_EMP = ./encabezados/interfazListaEmp.h 

OBJECTS_ARBOLB = ./temporales/interfazArbolB.o 
HEADERS_ARBOLB = ./encabezados/interfazArbolB.h 

OBJECTS_PERROSM = ./temporales/interfazPerrosM.o 
HEADERS_PERROSM = ./encabezados/interfazPerrosM.h

#----------------------------------------------------------->

DEPENDENCES_ALL_PERROSM = \
	$(OBJECTS_PERROSM) $(HEADERS_PERROSM) \
	$(OBJECTS_PERROS) $(HEADERS_PERROS) \
	$(OBJECTS_ARBOLB) $(HEADERS_ARBOLB)

#----------------------------------------------------------->
#-----------------------------------------------------------> 

#----------------------------------------------------------->

all:
	@echo
	make Palindromo 
	@echo
	make Analisa
	@echo
	make ColaAbstracta
	@echo
	make Perros
	@echo
	make ListaEmp
	@echo
	make ArbolB
	@echo
	make PerrosM
	@echo

#----------------------------------------------------------->


#----------------------------------------------------------->
#----------------------------------------------------------->

PerrosM: ./practicas/practica6/PerrosM.c $(DEPENDENCES_ALL_PERROSM) ./encabezados/DBPerrosExtend.h
	$(CC) -o PerrosM $(CFLAGS) ./practicas/practica6/PerrosM.c $(OBJECTS_PERROS) $(OBJECTS_ARBOLB) $(OBJECTS_PERROSM)

./temporales/interfazPerrosM.o: ./bibliotecas/interfazPerrosM.c ./encabezados/interfazPerrosM.h  
	$(CC) -c $(CFLAGS) ./bibliotecas/interfazPerrosM.c
	mv ./interfazPerrosM.o ./temporales/

cleanPerrosM:
	rm -f $(OBJECTS_PERROSM) ./PerrosM

#----------------------------------------------------------->
#----------------------------------------------------------->

ArbolB: ./practicas/practica5/ArbolB.c $(OBJECTS_ARBOLB) $(HEADERS_ARBOLB)  
	$(CC) -o ArbolB $(CFLAGS) ./practicas/practica5/ArbolB.c $(OBJECTS_ARBOLB)
	
./temporales/interfazArbolB.o: ./bibliotecas/interfazArbolB.c ./encabezados/interfazArbolB.h  
	$(CC) -c $(CFLAGS) ./bibliotecas/interfazArbolB.c
	mv ./interfazArbolB.o ./temporales/

cleanArbolB:
	rm -f $(OBJECTS_ARBOLB) ./ArbolB

#----------------------------------------------------------->
#----------------------------------------------------------->

ListaEmp: ./practicas/ejemplos/ListaEmp.c $(OBJECTS_LISTA_EMP) $(HEADERS_LISTA_EMP)  
	$(CC) -o ListaEmp $(CFLAGS) ./practicas/ejemplos/ListaEmp.c $(OBJECTS_LISTA_EMP)
	
./temporales/interfazListaEmp.o: ./bibliotecas/interfazListaEmp.c ./encabezados/interfazListaEmp.h  
	$(CC) -c $(CFLAGS) ./bibliotecas/interfazListaEmp.c
	mv ./interfazListaEmp.o ./temporales/

cleanListaEmp:
	rm -f $(OBJECTS_LISTA_EMP) ./ListaEmp

#----------------------------------------------------------->
#----------------------------------------------------------->

Perros: ./practicas/practica4/Perros.c $(OBJECTS_PERROS) $(HEADERS_PERROS)  
	$(CC) -o Perros $(CFLAGS) ./practicas/practica4/Perros.c $(OBJECTS_PERROS)
	
./temporales/interfazPerros.o: ./bibliotecas/interfazPerros.c ./encabezados/interfazPerros.h  
	$(CC) -c $(CFLAGS) ./bibliotecas/interfazPerros.c
	mv ./interfazPerros.o ./temporales/

cleanPerros:
	rm -f $(OBJECTS_PERROS) ./Perros

#----------------------------------------------------------->
#----------------------------------------------------------->

ColaAbstracta: ./practicas/practica3/ColaAbstracta.c $(OBJECTS_COLA_ABS) $(HEADERS_COLA_ABS)  
	$(CC) -o ColaAbstracta $(CFLAGS) ./practicas/practica3/ColaAbstracta.c $(OBJECTS_COLA_ABS)
	
./temporales/interfazCola.o: ./bibliotecas/interfazCola.c ./encabezados/interfazCola.h  
	$(CC) -c $(CFLAGS) ./bibliotecas/interfazCola.c
	mv ./interfazCola.o ./temporales/

./temporales/imprimeTipos.o: ./bibliotecas/imprimeTipos.c
	$(CC) -c $(CFLAGS) ./bibliotecas/imprimeTipos.c
	mv ./imprimeTipos.o ./temporales/

cleanColaAbstracta:
	rm -f $(OBJECTS_COLA_ABS) ./ColaAbstracta

#----------------------------------------------------------->
#----------------------------------------------------------->

Analisa: ./practicas/practica2/Analisa.c $(OBJECTS_PALINDROMO) $(HEADERS_PALINDROMO)
	$(CC) -o Analisa $(CFLAGS) ./practicas/practica2/Analisa.c $(OBJECTS_PALINDROMO)

cleanAnalisa:
	rm -f $(OBJECTS_PALINDROMO) ./Analisa

#----------------------------------------------------------->
#----------------------------------------------------------->

Palindromo: ./practicas/practica1/Palindromo.c $(OBJECTS_PALINDROMO) $(HEADERS_PALINDROMO)
	$(CC) -o Palindromo $(CFLAGS) ./practicas/practica1/Palindromo.c $(OBJECTS_PALINDROMO)
	
./temporales/interfazPila.o: ./bibliotecas/interfazPila.c
	$(CC) -c $(CFLAGS) ./bibliotecas/interfazPila.c
	mv ./interfazPila.o ./temporales/

cleanPalindromo:
	rm -f $(OBJECTS_PALINDROMO) ./Palindromo 

#----------------------------------------------------------->
#----------------------------------------------------------->
cleanAll:

	@echo
	rm -f ./practicas/practica1/*~ ./practicas/practica2/*~ ./practicas/practica3/*~ ./practicas/practica4/*~
	rm -f ./practicas/practica5/*~ ./practicas/practica6/*~
	@echo
	rm -f ./practicas/ejemplos/*~
	@echo
	rm -f ./*~ ./encabezados/*~ ./bibliotecas/*~ ./practicas/*~ ./temporales/*~
	@echo
	rm -f $(XFILES)
	@echo
	rm -f $(OBJECTS_ALL) 
	@echo
#----------------------------------------------------------->
