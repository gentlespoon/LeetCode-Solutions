/*
TinyURL is a URL shortening service where you enter a URL such as https://leetcode.com/problems/design-tinyurl and it returns a short URL such as http://tinyurl.com/4e9iAk.

Design the encode and decode methods for the TinyURL service. There is no restriction on how your encode/decode algorithm should work. You just need to ensure that a URL can be encoded to a tiny URL and the tiny URL can be decoded to the original URL.
 */



// GentleSpoon me@gentlespoon.com
// Leetcode    Q535
// Start       2018-01-02-23-01-51
// Finish      2018-01-02-23-14-03



class Solution {
public:
    unordered_map<string, string> database;
    string dict = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    int dictSize = dict.length();
    
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string shortUrl = "";
        do {
            for(int i=0; i<6; i++) {
                shortUrl += rand() % dictSize;
            }
        } while (database[shortUrl] != "");
        database[shortUrl] = longUrl;
        return shortUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return database[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));