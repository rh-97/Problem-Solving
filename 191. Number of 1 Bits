

/* Problem description

    Write a function that takes an unsigned integer and returns the number of '1' bits it has (also known as the Hamming weight).

    Note:

    Note that in some languages such as Java, there is no unsigned integer type. In this case, the input will be given as a signed integer type. 
    It should not affect your implementation, as the integer's internal binary representation is the same, whether it is signed or unsigned.
    In Java, the compiler represents the signed integers using 2's complement notation. Therefore, in Example 3 above, the input represents the signed integer. -3.
    Follow up: If this function is called many times, how would you optimize it?


    Example 1:
    Input: n = 00000000000000000000000000001011
    Output: 3
    Explanation: The input binary string 00000000000000000000000000001011 has a total of three '1' bits.
    
    Example 2:
    Input: n = 00000000000000000000000010000000
    Output: 1
    Explanation: The input binary string 00000000000000000000000010000000 has a total of one '1' bit.
    
    Example 3:
    Input: n = 11111111111111111111111111111101
    Output: 31
    Explanation: The input binary string 11111111111111111111111111111101 has a total of thirty one '1' bits.

*/

    // Solution
    //O(1)
    class Solution {
    public:
        int hammingWeight(uint32_t n) {
            int count = 0;
            while (n) {
                ++count;
                n &= (n - 1);
            }
            return count;
        }
    };
    
/* Explanation

We can make the previous algorithm simpler and a little faster. Instead of checking every bit of the number, 
we repeatedly flip the least-significant 11-bit of the number to 00, and add 11 to the sum. As soon as the number becomes 00, 
we know that it does not have any more 11-bits, and we return the sum.

The key idea here is to realize that for any number n, doing a bit-wise AND of n and n - 1 flips the least-significant 11-bit in nn to 00. 
Why? Consider the binary representations of nn and n - 1.
In the binary representation, the least significant 11-bit in nn always corresponds to a 00-bit in n - 1n−1. Therefore, anding the two numbers n and 
n - 1 always flips the least significant 11-bit in nn to 00, and keeps all other bits the same.
*/
