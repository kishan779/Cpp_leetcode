/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
	public:
		int guessNumber(int n) 
		{
			long l=1;   //low
			long h=n;   //high
			long mid;
			while(l<=h)
			{
				mid= (l+h)/2;
				if(guess(mid)==1)           //guess API
				{
					l=mid+1;
				}
				else if(guess(mid)==-1)         //guess API
				{
					h=mid-1;
				}
				else
				{
					return mid;
				}
			}
			return l;
		}
	}; 