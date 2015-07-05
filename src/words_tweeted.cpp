/************************* 
* Program that calculates the total number of times each word has been tweeted.
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

using namespace std;


/********************************
*makeIndex: function to count each unique word
*Since tweets.txt provides each tweet on a separate line the following approach is taken:
*Each tweet will be seen as a vector of strings (each word is a string)
*The txt file can be seen as a vector of lines/tweets,
*Therefore the words can be iterated through a vector of a vector of strings. 
*Returns a map of strings with their corresponding count (int) that can be neatly outputed to f1.txt.
********************************/
map<string,int> makeIndex(vector< vector<string> >& tweets) 
{ 
    map<string, int> index; 
    vector<vector<string> >::iterator it; 
     
    // iterator over all tweets 
    for(it = tweets.begin(); it != tweets.end(); ++it) { 

        vector<string>::iterator jt; 
        
        // then iterate over all words 
        for(jt = it->begin(); jt != it->end(); ++jt) {  
           
            // insert it if not already there and set count to 0 or 1 
            if( index.find(*jt) == index.end()) { 
                index.insert(make_pair(*jt, 0) ); // or set count to 1 
            } 
            // Increment count if it's not there or if they insert w/ 0 cnt 
            index[ *jt ]++;
        } 
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
*writeFile: function to generate output file
****************/
void writeFile(string filename, map<string,int>& wordMap)
{
    ofstream ofile(filename.c_str());
    map<string,int>::iterator it;

    // iterate over map and output to file 
    for(it = wordMap.begin(); it != wordMap.end(); ++it) {
        ofile << setw(28) << left << it->first << "\t" << it->second << endl;
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

    vector< vector<string> > tweets;                // structure of tweets
    parse(argv[1],tweets);                          // parse input file
    map<string,int> wordMap = makeIndex(tweets);    // generate map of words and their count
    writeFile(argv[2],wordMap);                     // write output file

    return 0;
}
