#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
int LETTERS[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    //Print the winner
    if (score1 > score2)
        //if player1 wins
    {
        printf("Player 1 wins!");
    }
    else if (score2 > score1)
        //if player 2 wins
    {
        printf("Player 2 wins!");
    }
    else
        //if its a tie
    {
        printf("Tie!");
    }
}

int compute_score(string word)
//computes the score
{
    //declare variables
    int score = 0;
    int numb;
    //word length
    int n = strlen(word);

    //loops over all letters in the word
    for (int i = 0; i < n; i++)
    {
        //if its apart of the alphabet
        if (islower(word[i]) || isupper(word[i]))
        {
            //make all letters to lower
            numb = tolower(word[i]) - 97;
            //number of score
            numb = POINTS[numb];
        }
        else
            //if its a special character
        {
            numb = 0;
        }

        //add number to score
        score += numb;
    }

    return score;
}