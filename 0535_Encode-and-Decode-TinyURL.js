/*
TinyURL is a URL shortening service where you enter a URL such as https://leetcode.com/problems/design-tinyurl and it returns a short URL such as http://tinyurl.com/4e9iAk.

Design the encode and decode methods for the TinyURL service. There is no restriction on how your encode/decode algorithm should work. You just need to ensure that a URL can be encoded to a tiny URL and the tiny URL can be decoded to the original URL.
 */



// GentleSpoon me@gentlespoon.com
// Leetcode    Q535
// Start       2019-02-21-08-42-29
// Finish      2019-02-21-08-47-36

/*
Runtime: 84 ms, faster than 57.80% of JavaScript online submissions for Encode and Decode TinyURL.
Memory Usage: 33.6 MB, less than 100% of JavaScript online submissions for Encode and Decode TinyURL.
*/

/**
 * Encodes a URL to a shortened URL.
 *
 * @param {string} longUrl
 * @return {string}
 */
var map = new Map();

var encode = function(longUrl) {
  var text = "";
  var possible = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
  for (var i = 0; i < 5; i++)
    text += possible.charAt(Math.floor(Math.random() * possible.length));
  map.set(text, longUrl);
  return text;
};

/**
 * Decodes a shortened URL to its original URL.
 *
 * @param {string} shortUrl
 * @return {string}
 */
var decode = function(shortUrl) {
    if (map.has(shortUrl)) {
      return  map.get(shortUrl);
    }
    return '';
};

/**
 * Your functions will be called as such:
 * decode(encode(url));
 */