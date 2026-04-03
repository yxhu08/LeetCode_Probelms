bool isPowerOfTwo(int n) {
    /*Simple Intuition (Super Easy Version)

👉 Power of 2 means:

“Only ONE switch is ON”

👉 (n - 1):

“Turns that switch OFF and everything else ON”

👉 AND operation:

“Checks if any common ON switches exist”

👉 If result = 0:

“No common ON switches → valid power of 2 ✅”*/
return n>0 && ((n&(n-1))==0);
    
}