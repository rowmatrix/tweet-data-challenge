#Tweet Data Engineering Challenge
- ```words_tweeted.cpp``` calculates the number of times a word has been tweeted
- ```median_unique.cpp``` calculates the median number of unique words per tweet (running median)

### Todo

- Refactor and organize code
- Optimize run time by creating specific data structures/classes
- Add test cases

### How to run

- Clone git repository onto local machine
- On command line/prompt/terminal type and run 

```bash 
bash run.sh
```

- Check results in ```tweet_output/``` folder.
- ```f1.txt``` stores number of times a word has been tweeted
- ```f2.txt``` stores median number of unique words per tweet
- ```tweets.txt``` sample input file with three tweets

### Example:

Our example ```tweets.txt``` contains three tweets:

```
is #bigdata finally the answer to end poverty? @lavanyarathnam http://ow.ly/o8gt3 #analytics

interview: xia wang, astrazeneca on #bigdata and the promise of effective healthcare #kdn http://ow.ly/ot2uj

big data is not just for big business. on how #bigdata is being deployed for small businesses: http://bddy.me/1bzukb3 @cxotodayalerts #smb
```

After running ```bash run.sh``` in the terminal we should two files in ```tweet_output```. 
```f1.txt``` should contain:

```
#analytics                      1
#bigdata                        3
#kdn                            1
#smb                            1
@cxotodayalerts                 1
@lavanyarathnam                 1
and                             1
answer                          1
astrazeneca                     1
being                           1
big                             2
business.                       1
businesses:                     1
data                            1
deployed                        1
effective                       1
end                             1
finally                         1
for                             2
healthcare                      1
how                             1
http://bddy.me/1bzukb3          1
http://ow.ly/o8gt3              1
http://ow.ly/ot2uj              1
interview:                      1
is                              3
just                            1
not                             1
of                              1
on                              2
poverty?                        1
promise                         1
small                           1
the                             2
to                              1
wang,                           1
xia                             1
```

Urls and hashtags are consider words as well. 
And ```f2.txt``` contains a new running median on each line:

```
11
12.5
14
```

The first line is 11 because there are exactly 11 unique words in the first tweet.
The second line is 12.5 because the first tweet contains 11 unique words and the second tweet contains 14 unique words. Thus, (11 + 14) / 2 = 12.5.
The last tweet contains 17 unique words. Therefore, (11 + 14 + 17) / 3 = 14. 