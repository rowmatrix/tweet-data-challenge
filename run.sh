#!/bin/bash

# compile words_tweeted.cpp and median_unique.cpp
g++ ./src/words_tweeted.cpp   -o ./src/words_tweeted 
g++ ./src/median_unique.cpp   -o ./src/median_unique

# execute both programs, output files will be found in tweet_output directory
./src/words_tweeted ./tweet_input/tweets.txt ./tweet_output/f1.txt
./src/median_unique ./tweet_input/tweets.txt ./tweet_output/f2.txt

# remove executables
rm ./src/words_tweeted ./src/median_unique