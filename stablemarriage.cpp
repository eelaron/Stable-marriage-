#include<iostream>
using namespace std;

bool ok(int q[], int c) { // Finish this code
	static int mp[3][3] = { { 0,2,1 },  	 // Man#0's preferences
							{ 0,2,1 },		// Man#1's preferences
							{ 1,2,0 } };	// Man#2's preferences
						
	static int wp[3][3] = { { 2,1,0 },		// Woman#0's preferences
							{ 0,1,2 },		// Woman#1's preferences
							{ 2,0,1 } };	 // Woman#2's preferences

	for (int i=0; i<c; i++){
	if (q[i] == q[c]) return false; //This is simple row test to make sure wives are not married to two husbands.
		if (mp[i][q[i]] > mp[c][q[c]] && wp[q[c]][c] > wp[q[c]][i] || mp[c][q[c]] > mp[c][q[i]] && wp[q[c]][c] > wp[q[i]][c]) return false;
		/*	The crux of the Stable Marriage program. Here we first check that the previous man likes his wifre more than the man after's wife.
			Woman's preference of the current husband is then compared to that of the husband prior. Both statements have to execute true. 
			The second part of the boolean after the 'or' statement checks that the current husband likes his wife more than the previous husband's wife. 
			It also checks that the current woman like her current husband more than the previous wife's husband. Both statements have to execute true.
			Either statements on both sides of the 'or' function have to execute false inorder for this whole statement to return false...
			the logic being, both parties need to exchange mutal feelings in order to establish a stable marriage. 
		*/
	}
	return true;
	}
	

	/*Similar to 1D Queens, use a loop to check the array.
	  Inside the loop we chould check for 3 conditions
	  First condition checks is the same women is married to two different man *hint we need to check if two things are equal*
	  Second condition checks if (Man#i) and (Man#c's wife) both like each other more than their own spouse
	  Third condition checks if (Man#c) and (Man#i's wife) both like each other more than their own spouse

	  mp[i][j] tells you how much Man#i likes Woman#j. (0 = favorite; 2 = least favorite) 
	  wp[i][j] tells you how much Woman#i likes Man#j.

	  mp[i][q[i]] tells you how much Man#i likes his own wife. 
	  mp[i][q[c]] tells you how much Man#i likes Man#c's wife. 
	  wp[q[i]][i] tells you how much Man#i's wife likes Man#i. 
	  wp[q[i]][c] tells you how much Man#i's wife likes Man#c. 
	  If mp[i][q[c]] < mp[i][q[i]], it means that Man#i likes Man#c's wife more than his own wife
	*/

	//if we pass the loops are passes, return true


void print(int q[]) {
	static int solution = 0;
	cout << "Solution #" << ++solution << ":\nMan\tWoman\n";
	for( int i=0; i<3; i++)
	cout << i << "\t" << q[i] << endl;
	
	
	//print function first prints the position of the men then tabs to print the woman's preference. 
}


int main() {
	int q[3] = {0};  
	int c = 0; 
	q[c] = 0;
   

	while (c >= 0) { 
    c++; 
    if ( c == 3 ) {
          print(q);
          c--;
    }
    else q[c] = -1;
      while (c >= 0) {
        
        q[c]++; 
        if ( q[c] == 3 ) c--;
        else if ( ok(q, c) == true ) break; 
         
      }
}
   
	/*The main function is exactly the same as 1D Queens. EXCEPT the array size is different
		First columns are incemented then rows incremented by one. each row is checked using the ok funtion to determine if a stable match has been made. 
		When stable match is determine, the column is then incramented agin to determine if the next stable marriage can occur, if not, backtacking is used.
	*/
	return 0;
}
