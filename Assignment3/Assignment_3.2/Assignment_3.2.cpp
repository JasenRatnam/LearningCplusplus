/*
 * Author: Jasen Ratnam 40094237
 * Date: 10/22/2018
 * Due: 10/26/2018
 * Assignment 3: User-Defined Functions/ Arrays
 * This program takes a text of maximum 100 words as input and returns:
 * The total number of words.
 * The number of punctuation points.
 * The number of words that start with a vowel.
 * The number of words that start with a consonant.
 */


#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
#include <cctype>
#include <sstream> 
#include <cstring> 

using namespace std;
 
/*
 * Function to make the words in the given vector go to lowercase.
 * returns vector with words in lower case.
 */
vector<string> getLowerWords(vector<string> words)
{
    vector<string> loweredWords;
    for(auto word : words)// go to lower case
    {
        string temp = word; // Copy word
        for(int i = 0; i < temp.size(); i++)
        {
            if(temp[i] >= 'A' && temp[i] <= 'Z') // If char is caps.
            {
                temp[i] = tolower(temp[i]); // lower it.
            }
        }
        loweredWords.push_back(temp); // save copy in new vector.
    }
    return loweredWords;
}

/*
 * Get the number of personal pronouns.
 */
int getNumbPron(vector<string> words)
{
    int numbPron = 0; // initialize counter.
    for(auto word : words) // Check ever word in vector
    {
        // if word is equivalent to a pronoun
        if(word == "i" || word == "you" || word == "he" || word == "she" 
           || word == "it" || word == "we" || word == "they" || word == "me" 
           || word == "him" || word == "her" || word == "us" || word == "them")
        {
            // increment.
            numbPron++;
            //cout << word;
        }
    }
    return numbPron;
}

/*
 * Get the number of words that start with a vowel.
 */
int getNumbVow(vector<string> words)
{
    // initialize counter.
    int numbVow = 0;
    
    // Check every word.
    for(auto word : words)
    {
        // if the first char of the word is a vowel
        if(word.at(0) == 'a' || word.at(0) == 'e' || word.at(0) == 'i' 
           || word.at(0) == 'o' || word.at(0) == 'u')
        {
            // increment
            numbVow++;
        }
    }
    return numbVow;
}

/*
 * Get the number of words that start with a consonant.
 */
int getNumbCons(vector<string> words)
{
    // initialize counter
    int numbCons = 0;
    // Check every word.
    for(auto word : words)
    {
        // if the first char is a consonant.
        if(word.at(0) == 'b' || word.at(0) == 'c' || word.at(0) == 'd' 
           || word.at(0) == 'f' || word.at(0) == 'g' || word.at(0) == 'h' 
           || word.at(0) == 'j' || word.at(0) == 'k' || word.at(0) == 'l' 
           || word.at(0) == 'm' || word.at(0) == 'n' || word.at(0) == 'p' 
           || word.at(0) == 'q' || word.at(0) == 'r' || word.at(0) == 's'
           || word.at(0) == 't' || word.at(0) == 'v' || word.at(0) == 'w' 
           || word.at(0) == 'x' || word.at(0) == 'y' || word.at(0) == 'z')
        {
            // increment
            numbCons++;
        }
    }
    return numbCons;
}

/*
 * Get the number of punctuation points in the text inputed.
 */
int getNumbPunct(string t)
{
    // initialize counter
    int numbPunct = 0;
    
    // check every char.
    for (int i = 0; i < t.size(); i++)
    { 
        // if char is a punctuation point
        if (t[i] == ',' || t[i] == '.' || t[i] == '!' || t[i] =='?' 
            || t[i] ==':' || t[i] ==';') 
        {
            // increment
            numbPunct++;  
        }
    }
    return numbPunct;
}

// Get the words from the string inputed
 vector<string> getWords(string t)
 {
     // remove all punctuation points.
    for (int i = 0; i < t.size(); i++)
    { 
        if (t[i] == ',' || t[i] == '.' || t[i] == '!' || t[i] =='?' 
            || t[i] ==':' || t[i] ==';') 
        {
            // replace punctuation points with " ".
            t[i] = ' '; 
        }
    }
    vector<string> words;
    vector<string> lowerWords;
    string word;
    
    // put the sentence into a stream
    istringstream instr(t);
    
    // the >> operator separates the stream at a whitespace
    while (instr >> word)
    {
        // add all words in a vector
        words.push_back(word);
    }
    
    // make the words to lower case.
    lowerWords = getLowerWords(words);
    
    return lowerWords; // return vector of words.
 }
 
 /*
  * Get the text input from th user in string format.
  */
 string getText()
 {
    char text[10000]; 
    
    // ask for input
    cout << "Please enter a text: ";
    // save all chars.
    cin.getline(text, 10000, '\n');      // Input goes into text
 
    // put chars in string
    string t(text);
    
    // return string.
    return t;
}

 /*
  * Function that displays information about the text inputed.
  */
 void displayInfo()
 {
     // get text.
    string t = getText();

    // get words.
    vector<string> lowerWords = getWords(t);
    
    // display all information.
    cout << "\nThe entered text has: \n"
            "1. " << lowerWords.size() << " number of words.\n"
            "2. " << getNumbPron(lowerWords) << " number of personal pronouns.\n"
            "3. " << getNumbPunct(t) << " number of punctuation points.\n"
            "4. " << getNumbVow(lowerWords) << " number of words that start with a vowel.\n"
            "5. " << getNumbCons(lowerWords) << " number of words that start with a consonant.\n";
    
 }
 
 // main function.
 // calls displayinfo fucntion
int main()
{
    // display info
    displayInfo();
    return 0;
}