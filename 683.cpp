/*
There is a garden with N slots. In each slot, there is a flower. The N flowers will bloom one by one in N days. In each day, there will be exactly one flower blooming and it will be in the status of blooming since then.

Given an array flowers consists of number from 1 to N. Each number in the array represents the place where the flower will open in that day.

For example, flowers[i] = x means that the unique flower that blooms at day i will be at position x, where i and x will be in the range from 1 to N.

Also given an integer k, you need to output in which day there exists two flowers in the status of blooming, and also the number of flowers between them is k and these flowers are not blooming.

If there isn't such day, output -1.

Example 1:
Input: 
flowers: [1,3,2]
k: 1
Output: 2
Explanation: In the second day, the first and the third flower have become blooming.
Example 2:
Input: 
flowers: [1,2,3]
k: 1
Output: -1
Note:
The given array will be in the range [1, 20000].
 */

// GentleSpoon me@gentlespoon.com
// Leetcode    Q683
// Start       2017-11-16-14-15-10
// Finish      2017-11-16-14-35-52



class Solution {
public:


    int N;                                                                      // size of garden
    int needle_l;                                                               // needle_l is the needle for getting garden slot to the left
    int needle_c;                                                               // devide the garden to two parts by the newly bloomed slot
    int needle_r;                                                               // needle_r is the needle for getting garden slot to the right
    
    /**
     * Helper function for visualizing the garden and two needles
     * @param garden   garden vector
     * @param day      current day
     */
    void printStatus(vector<bool>& garden, int& day) {
        // cout << "[" << day << "]" << endl;
        for (auto f: garden)        cout << f;
        cout << endl;
        for (int i=0; i<N; i++) {
            if      (i==needle_l)   cout << 'l';
            else if (i==needle_r)   cout << 'r';
            else if (i==needle_c)   cout << 'c';
            else                    cout << ' ';
        }
        cout << endl;
    }
    


    int kEmptySlots(vector<int>& flowers, int k) {
        
        bool detail = 0;                                                        // Toggle this var to see how I solved the problem 
        
        N = flowers.size();                                                     // Get the size into N to avoid repeatedly calling
                                                                                //     flowers.size()
        
        bool found = false;                                                     // Boolean var that will be used to check if there
        // cout << "N:" << N << endl;                                           //     are bloomed flowers between two flowers
        
        if (k>=N) { return -1; }                                                // If the desired gap is larger than garden size
        
        vector<bool> garden(N);                                                 // Construct a garden with the same size
        
        
        for (int day=0; day<N; day++) {                                         // As day goes by...
            
            needle_c = flowers[day]-1;                                          // Get the actual index for blooming flowers in 
            // cout << "C:" << needle_c << endl;                                //     the garden
                       
            garden[needle_c] = 1;                                               // Bloom!
            
            needle_l = needle_c-k-1;                                            // The desired bloomed flower to the left
            needle_r = needle_c+k+1;                                            // The desired bloomed flower to the right
            
            if (detail) printStatus(garden, day);                               // Print verbose detail of analyzing




            if (needle_l >= 0) {                                                // If the needle is still in left boundary
                // cout << "L:" << needle_l << ':' << garden[needle_l] << endl;
                if (garden[needle_l]) {                                         // If this flower is bloomed
                    found = true;                                               // Assume we have found one
                    for (int i=needle_l+1; i<needle_c; i++) {                   // Check the flowers in between
                        // cout << (char)(garden[i]+'a');
                        if (garden[i]) {                                        // If any of the flowers in between bloomed
                            found = false;                                      // Ooops. This one doesn't count
                            if (detail) cout << "Bloomed flower in between, continue searching" << endl;
                            break;
                        }
                    }
                    if (found) {                                                // If no flowers in between bloomed
                        return day+1;                                           // Wow. Gotcha. Restore index to day.
                    }
                }
            }



            if (needle_r < N) {                                                 // Same as the section above
                // cout << "R:" << needle_r << ':' << garden[needle_r] << endl;
                if (garden[needle_r]) {
                    found = true;
                    for (int i=needle_r-1; i>needle_c; i--) {
                        // cout << (char)(garden[i]+'a');
                        if (garden[i]) {                                        
                            found = false;                                      
                            if (detail) cout << "Bloomed flower in between, continue searching" << endl;
                            break;
                        }
                    }
                    if (found) {                                                
                        return day+1;                                           
                    }
                }
            }



        }                                                                       // End "As day goes by"


        return -1;                                                              // If all the flowers are bloomed and we still
                                                                                //     did not find any solution
    }
};