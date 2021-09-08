import random
import os
import time

wrong = 0
correct = 0
dictionary = []
usedWords = []
enteredWords = []
length = 0

def setDictionary():
    file =  open("wordList.txt")
    for x in file:
        dictionary.append(x.replace("\n", ""))

def getDictionary():
    return dictionary

def getWord():
    global usedWords
    #generates a random word from the dictionary list between 0 and the length of the list
    word = (dictionary[random.randint(0,len(dictionary)-1)])
    usedWords.append(word)
    return word

def ranLength(): 
    global length
    length = random.randint(20,100)

def addInput (s):
    global enteredWords
    s = s.rstrip()
    s = s.lstrip()
    enteredWords.append(s)

def check(): 
    global wrong,correct
    n=0
    while True:
        a = enteredWords[n]
        b = usedWords[n]
        #if length of b > length of a, then the extra characters in b are incorrect characters
        if len(a) > len(b):
            l = list(a)
            for w in range (1,len(a)-len(b)+1):
                wrong +=1
                del(l[-w])
            a = "".join(l)
        #check characters between a and b        
        for x in range(len(a)):
            if a[x] != b[x]:
                wrong += 1
            else:
                correct += 1
        if n == len(usedWords)-1:
            break
        else:
            n+=1           

def getWrong():
    return wrong

def getRight():
    return correct

def setLength(a):
    global length
    length = a

def getLength():
    return (length)

def checkTime(a,b):
    return(b-a)

def accuracy():
    return (correct)/(wrong+correct)*100

def WPM(sec):
    a = (length/sec)*60
    #round to nearest whole WPM
    b = int(a+0.5)
    return b

if __name__ == "__main__":
    setDictionary()
    a =""
    b=""
    startTime = 0.0
    endTime = 0.0
    timeDiff = 0.0

    print("Typing Test in Python by Justin Chow and Mike Kim")
    print("Created on July 30, 2021")
    print("Simply type the word on the screen and press enter when finished.")

    while True:
        while a.isdigit() == False:
            a = str(input("How many words? Enter -1 to get a random number of words to type: "))
            if a.isdigit() == True:
                if int(a) < -1:
                    print("Error, you must enter a number greater than -1")
                else:
                    setLength(int(a))
                    break
            elif int(a) == -1:
                    ranLength()
                    print("There will be "+ str(getLength())+ " words!")
                    break

        print("The test will begin when you press any key!")
        os.system("pause")

        startTime = time.monotonic()
        for x in range(getLength()):
            print(getWord())
            b = input("")
            addInput(b)
        endTime = time.monotonic()
        check()

        timeDiff = checkTime(startTime,endTime)

        print("WRONG: "+ str(getWrong())+ " RIGHT: "+ str(getRight()))
        print("ACCURACY: "+ str(accuracy())+ "% WPM: "+str(WPM(timeDiff)))
        break

        




    
