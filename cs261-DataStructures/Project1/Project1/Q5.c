/* CS261- Assignment 1 - Q.5*/
/* Name: Ethan Dunham
* Date: 4/12/17
 * Solution description: This converts string to sticky caps.
 */
 
#include <stdio.h>
#include <stdlib.h>

/*converts ch to upper case, assuming it is in lower case currently*/
char toUpperCase(char ch){
     return ch-'a'+'A';
}

/*converts ch to lower case, assuming it is in upper case currently*/
char toLowerCase(char ch){
     return ch-'A'+'a';
}

void sticky(char* word){
     /*Convert to sticky caps*/
	int x = 0;
	for (int i = 0; i < 499; i++)
	{
		if (x == 0)
		{
			if(word[i] > 'Z')
			{
				word[i] = toUpperCase(word[i]);
			}
			x = 1;
		}
		else
		{
			if(word[i] < 'a')
			{
				word[i] = toLowerCase(word[i]);
			}
			x = 0;
		}
	}
}

int main(){
    /*Read word from the keyboard using scanf*/
	char word[500];
	char *word1;
	word1 = word;
	scanf("%s", word1);
    /*Call sticky*/
	sticky(word1);
    /*Print the new word*/
	printf("%s", word1);
    return 0;
}
