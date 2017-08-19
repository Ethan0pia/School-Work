###########################################################################################################################
##Author: Ethan Dunham
##Date:7/28/17
##Assignment: Python project
##Discription: This program creates 3 files with random letters. Then it averages 2 random numbers.
###########################################################################################################################

#creates the random letters to choose from
#from https://stackoverflow.com/questions/2823316/generate-a-random-letter-in-python
import random
import string    

fileNames = ["File1.txt","File2.txt","File3.txt"]
#creates random letter lists
for x in range(0,3):
    fileLetters =[]
    for y in range(0,10):
        fileLetters.append(random.choice(string.ascii_lowercase))
    #prints letters
    #from https://stackoverflow.com/questions/27174180/printing-lists-in-python-without-spaces
    letters=''.join(str(i) for i in fileLetters)
    print(letters)
    #adds letters to file
    f= open(fileNames[x],"w+")
    for i in range(10):
        f.write(fileLetters[i])
    f.write('\n')
    f.close()

#Gets 2 random numbers (1 to 42) and finds the product of those numbers
num1 = random.randrange(1, 42)
print(num1)
num2 = random.randrange(1, 42)
print(num2)
print(num1*num2)