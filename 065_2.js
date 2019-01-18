/**
 * @param {string} s
 * @return {boolean}
 */
 
var isNumber = function(s) {
    return !!s.match(/^\s*[+-]?(\d+\.\d+|\d+\.|\.\d+|\d+)(\e[+-]?\d+)?\s*$/);
};
