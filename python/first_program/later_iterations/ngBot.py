'''
ngBot.py - 6/1/2017
'''

import random as rng
import logging
import time

def main():
    # logger config
    logger = logging.getLogger('ngbot')
    logger.setLevel(logging.DEBUG)
    formatter = logging.Formatter('%(asctime)s:%(name)s:%(levelname)s:%(message)s')
    file_handler = logging.FileHandler('RAWngBotLogs.txt')
    file_handler.setFormatter(formatter)
    logger.addHandler(file_handler)

    i = 0
    generationNo = int(input("Enter a generation number: "))
    timeStart = time.time()
    while (i < generationNo):
        i += 1
        randomNum = rng.randint(1, 100)
        logger.info("Random Number:%s" % (randomNum))
        randomNumGuessed = False
        numOfGenerations = 0
        numOfGuesses = 0

        while not randomNumGuessed:
            guesserGuess = rng.randint(1, 100)
            logger.info("Guess input:%s" %(guesserGuess))
            print(guesserGuess)
            if(guesserGuess == randomNum):
                numOfGuesses += 1
                print("It took the mini bot %s guesses!" % (numOfGuesses))
                logger.info("Number of guesses:%s" % (numOfGuesses))
                randomNumGuessed = True
            elif(guesserGuess > randomNum):
                guesserGuess = rng.randint(1, guesserGuess)
                numOfGuesses += 1
            else:
                guesserGuess = rng.randint(guesserGuess, 100)
                numOfGuesses += 1
    print(time.time() - timeStart)
    logger.info("Duration:%s" % (time.time() - timeStart))

if __name__ == '__main__':
    main()
