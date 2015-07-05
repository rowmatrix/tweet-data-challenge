/************************* 
* Program that calculates the median number of unique words per tweet.
* @author: Ibar Romay
* @github: rowmatrix
* @email:  romayibar@gmail.com
***********************/
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


/********************************
*makeIndex: function to count each unique word
*Since tweets.txt provides each tweet on a separate line the following approach is taken:
*Each tweet will be seen as a vector of strings (each word is a string)
*The txt file can be seen as a vector of lines/tweets,
*Therefore the words can be iterated through a vector of a vector of strings. 
*Returns a vector of maps, where each map is a word count for each tweet.
********************************/
vector< map<string,int> > makeIndex(vector< vector<string> >& tweets) 
{ 
    vector< map<string,int> > index; 
    vector< vector<string> >::iterator it; 
     
    // iterator over all tweets 
    for(it = tweets.begin(); it != tweets.end(); ++it) { 

        vector<string>::iterator jt; 
        map<string,int> tempMap;
        
        // then iterate over all words 
        for(jt = it->begin(); jt != it->end(); ++jt) {  
            
            // insert it if not already there and set count to 0 or 1 
            if( tempMap.find(*jt) == tempMap.end()) { 
                tempMap.insert(make_pair(*jt, 0) ); // or set count to 1 
            } 
            // Increment count if it's not there or if they insert w/ 0 cnt 
            tempMap[ *jt ]++; 
        } 
 
        index.push_back(tempMap); // add word map of a single tweet to vector
    } 

    return index;
}


/****************
*parse: function to parse tweets.txt and populate vector<vector<string>> tweets
****************/
void parse(string filename, vector< vector<string> >& tweets)
{
    ifstream ifile(filename.c_str());
    if( ifile.fail() ) {
        cerr << filename << " cannot be opened." << endl;
        return;
    }

    string tweet;
    
    // get whole line of text
    while( getline(ifile,tweet) ) {
        
        vector<string> temp; // temporary vector to add to tweets
        stringstream ss(tweet);

        string word;
        // parse out words from tweet
        while( ss >> word ) {
            temp.push_back(word); // place words in inner vector
        }

        // Now add vector of words to tweets
        tweets.push_back(temp);
    }

    ifile.close();
}


/****************
*median: function to calculate the median of a vector of elements
****************/
double calcMedian(vector<int> v)
{
    double median;
    size_t size = v.size();

    sort(v.begin(), v.end());

    if (size  % 2 == 0) {
        median = (v[size / 2 - 1] + v[size / 2]) / 2.0;
    }
    else {
        median = v[size / 2];
    }

    return median;
}


/****************
*writeFile: function to calculate median number of unique words and generate output file
****************/
void writeFile(string filename, vector< map<string,int> >& tweetWordMap)
{
    ofstream ofile(filename.c_str());
    vector< map<string,int> >::iterator it;
    vector<int> medians;
 
    // iterate over all tweet word maps
    for(it = tweetWordMap.begin(); it != tweetWordMap.end(); ++it) {
        int unique = 0; // number of unique words per tweet 

        // iterate over each word in a tweet
        map<string,int>::iterator mt;
        for(mt = it->begin(); mt != it->end(); ++mt) {

            // check for unique words and update number of unique words
            if(mt->second == 1) unique++;
        }

        // add number of unique words to vector and output median to file
        medians.push_back(unique);
        ofile << calcMedian(medians) << endl;
    }

    ofile.close();
}



/**************** 
*main function 
****************/
int main(int argc, char* argv[]) 
{
    if(argc < 3) {
        cerr << "Usage: ./words_tweeted in_filename out_filename" << endl;
        return 1;
    }

    vector< vector<string> > tweets;                     // structure of tweets
    parse(argv[1],tweets);                               // parse input file
    vector< map<string,int> > tweetWordMap = makeIndex(tweets);    // vector of wordMaps
    writeFile(argv[2],tweetWordMap);                     // write output file

    return 0;
}