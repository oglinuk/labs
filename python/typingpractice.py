'''
Practice your typing

    * Load a word list
    * Display the word list
'''
import random
import time

def shuffle(prWordList):
    aList = []
    for i in prWordList.split():
        aList.append(i)
    random.shuffle(aList)
    return aList

def loadWords(prPath):
    wordList = []
    with open(prPath, 'r') as fIN:
        wordList = fIN.read()
    return wordList.replace("\n", " ")

def main():
    wordsCorrect = 0
    totalWords = 0
    timeLimit = (time.time() + 60)
    words = loadWords('wordList.txt')

    while True:
        word = shuffle(words)
        print(word[0])
        currentWord = input()
        if currentWord == word[0]:
            wordsCorrect += 1
        totalWords += 1
        if time.time() >= timeLimit:
            break

    print('You got %s out of %s' % (wordsCorrect, totalWords))

if __name__ == '__main__':
    main()
