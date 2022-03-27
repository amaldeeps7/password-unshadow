#make file - this is a comment section
 
all: unshadow.c guessword.c
	gcc unshadow.c -o unshadow
	gcc guessword.c -o guessword -lcrypt
	
runall: unshadow guessword
	./unshadow training-shadow.txt training-passwd.txt
	./guessword top250.txt passwordfile.txt

clean:
	rm -f *.o unshadow md5crack