/*

Validate if a given string can be interpreted as a decimal number.
Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
" -90e3   " => true
" 1e" => false
"e3" => false
" 6e-1" => true
" 99e2.5 " => false
"53.5e93" => true
" --6 " => false
"-+3" => false
"95a54e53" => false

Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one. However, here is a list of characters that can be in a valid decimal number:
Numbers 0-9
Exponent - "e"
Positive/negative sign - "+"/"-"
Decimal point - "."

Of course, the context of these characters also matters in the input.

*/


// GentleSpoon me@gentlespoon.com
// Leetcode    Q065
// Start       2019-01-17-14-01-05
// Finish      2019-01-17-14-25-26

/**
 * @param {string} s
 * @return {boolean}
 */


// There are 4 valid character types:
//   digit([0-9]), exponent('e'), sign([+-]), point('.')
//   -1 : not allowed
//    0 : ok
//    1 : required

var initCharAllowance = {
    digit : 0,
    exp   : -1,
    sign  : 0,
    point : 0
};

var t = {
    invalid : 0,
    digit   : 1,
    exp     : 2,
    sign    : 3,
    point   : 4
};

var _typeOf = function(c) {
    if ('0123456789'.indexOf(c) !== -1) {
        // console.log('digit');
        return t.digit;
    } else if ('e'.indexOf(c) !== -1) {
        // console.log('exp');
        return t.exp;
    } else if ('+-'.indexOf(c) !== -1) {
        // console.log('sign');
        return t.sign;
    } else if ('.'.indexOf(c) !== -1) {
        // console.log('point');
        return t.point;
    } else {
        // console.log('invalid');
        return t.invalid;
    }
};


var isNumber = function(s) {
    
    s = s.trim();

    if (!s.length) {
        return 0;
    }
    
    var digits = 0; // 0 <  digits <  infinite
    var points = 0; // 0 <= points <= 1
    var signs  = 0; // 0 <= signs  <= 2
    var exps   = 0; // 0 <= exps   <= 1
    var canTerminate = 1;
    
    var nextChar = initCharAllowance;
    for (let c of s) {
        
        // console.log(c, nextChar);
        
        switch(_typeOf(c)) {
            case t.digit:
                if ( nextChar.digit === -1 ) {
                    return 0;
                }
                digits++;
                canTerminate = 1;
                nextChar = {
                    digit : 0,
                    exp   : 0,
                    sign  : -1,
                    point : nextChar.point
                };
                break;
            case t.exp:
                if (exps || !digits || nextChar.exp === -1) { // if exp already exists OR cannot be exp
                    return 0;
                }
                exps++;
                canTerminate = 0;
                nextChar = {
                    digit : 0,
                    exp   : -1,
                    sign  : 0,
                    point : -1
                };
                break;
            case t.sign:
                if (signs>1 || nextChar.sign === -1) { // if already max sign OR cannot be sign
                    return 0;
                }
                signs++;
                canTerminate = 0;
                nextChar = {
                    digit : 0,
                    exp   : -1,
                    sign  : -1,
                    point : 0
                };
                break;
            case t.point:
                if (points || nextChar.point === -1) { // if point already exists OR cannot be point
                    return 0;
                }
                points++;
                canTerminate = 1;
                nextChar = {
                    digit : 1,
                    exp   : 0,
                    sign  : -1,
                    point : -1
                };
                break;
            default:
                return 0;
        }
        
    }
    if (!digits) {
        return 0;
    }
    if (canTerminate) {
        return 1;
    }
    return 0;
};



isNumber('65.1e-6');
