/**
 * Duilio Lucio
 * 10/06/2024
 */

#include <iostream> // input and output streams
#include <fstream> // file handling
#include <unordered_map> //stores word frequencies efficiently
#include <string> // handles words as strings
#include <algorithm> // transform, sort and remove_if functions
#include <vector> // stores and sorts word-frequency pairs
#include <cctype> // character classification functions (ispunct and tolower)

/**
 * Converts string to lowercase:
 * 1. loop through each character in the string
 * 1a. using std::transform which applies tolower to every character in str
 * 1b. modifying all characters to lowercase, modifying str directly
 */
void toLowerCase(std::string &str) {
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
}

/**
 * Removes punctuation from a string:
 * 1. using std::remove_if which goes through each character in str and removes if it meets the condition
 * 2. the condition being if 'c' is punctuation ('ispunct(c)' is true)
 * 3. modifying 'str' to have only alphanumeric characters and spaces
 */
void removePunctuation(std::string &str) {
    str.erase(std::remove_if(str.begin(), str.end(), [](char c) { return std::ispunct(c); }), str.end());
}

/**
 * Count word frequencies and displays the top 20 most frequent words:
 * 1. check filename 
 * 2. open file for reading
 * 3. create unordered_map to store word counts
 * 4. read every word from the file
 * 5. prepare sorting by transferring map data into a vector
 * 6. sort vector by frequency in descending order
 * 7. print top 20 words and their frequencies
 */
int main(int argc, char *argv[]) {
    // 1
    if (argc != 2) {
        // if no filename argument is provided then print usage message and exit 
        std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
        return 1;
    }

    // 2
    std::ifstream file(argv[1]); // opens file in reading mode
    if (!file.is_open()) { // checks if file can be opened
        std::cerr << "Error: File could not open" << argv[1] << std::endl;
        return 1; // exit w/ error if file can't open
    }

    // 3
    std::unordered_map<std::string, int> wordCount; // map to store every unique word and their frequencies
    std::string word; // variable that stores every word as we read

    // 4
    while (file >> word) {
        // remove punctuation and convert to lowercase
        removePunctuation(word); //removes punctuation
        toLowerCase(word); // convert to lowercase

        // Check if word is not empy after process
        if (!word.empty()) {
            // increment word's frequency into the map
            wordCount[word]++; // if word exits in wordCount, increace by 1. If not then its added with initial frequency of 1
        }
    }

    // close after every word is processed
    file.close();

    //5
    std::vector<std::pair<std::string, int> > wordList(wordCount.begin(), wordCount.end());
    // wordList is a vector of pairs, where each pair has their word and frequency
    // wordCount.begin() & wordCount.end() are the start and end of wordCount
    // contructs wordList w/ every single key-value from the wordCount

    //6 
    std::sort(wordList.begin(), wordList.end(), [](const std::pair<std::string, int> &a, const std::pair<std::string, int> &b) {return a.second > b.second; });
    // std::sort will sort wordList into places

    //7
    int count = 0;
    for (const std::pair<std::string, int> &entry : wordList) {
        if (count++ == 20) break;
        std::cout << entry.first << " " << entry.second << std::endl;
        // stop printing after 20 words
        // entry.first is the word and entry.second is the frequency
        // looping through each word and frequency printing them on a new line
    }
    return 0;
}