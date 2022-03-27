# password-cracker
Three files are given – training-passwd.txt, training-shadow.txt and top250.txt. The program combines the contents of training-passwd.txt and training-shadow.txt and recover as many passwords as possible using dictionary of words commonly used in passwords which is given in top250.txt.

For this, two programs are written namely unshadow.c and guessword.c. When we execute the programs, first the training-passwd.txt and training-shadow.txt are combined and saved to file named passwordfile.txt and then the hash corresponding to users in passwordfiles.txt is compared with the hash of passwords provided in top250.txt and matching pairs are printed and saved in allcrackpasswd.txt. A file passhash.txt is also generated which contain the md5 hash of the plain text in top250.txt.

### **Compiling the programs:**

The above two programs can be compiled using make

    $make
This will run:
  
    $gcc unshadow.c -o unshadow
    $gcc md5crack.c -o md5crack -lcrypt

### **Executing the programs:**
To execute the programs, we can use make runall
    
    $make runall
This will run:
    
    $./unshadow training-shadow.txt training-passwd.txt
    $./md5crack top250.txt passwordfile.txt
