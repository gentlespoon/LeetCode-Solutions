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
