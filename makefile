compile = all cleanall

all: bison.tab.c lex.yy.c
	g++ -c bison.tab.c
	g++ -c lex.yy.c
	g++ -o all bison.tab.c lex.yy.c 

lex.yy.c: flex.l
	flex flex.l

bison.tab.c: bison.y
	bison -d -o bison.tab.c bison.y

clean:
	rm -f *.c *.h

cleanall: clean
	rm -f bison flex
