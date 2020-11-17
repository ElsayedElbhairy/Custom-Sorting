// Author Name: Elsayed Elbhairy
// Creation Date: 11/17/2020


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <string>
#include <string>
using namespace std;


// Define the number os suits and cards
#define suites 4
#define cards  13  

void shuffle_cards(int deck[]);
void print_cards(int card);
void print_deck(int deck[], string user_input);
void sort_cards(int deck[]);




int main()
{
    int deck[suites*cards];
    string input;
    srand( time(NULL) );
    
    cout << "Shuffled Cards before sorting: " << endl;
    shuffle_cards(deck);
    print_deck(deck, "yes");

    cout << "\n\nPlease, type yes to sort the cards in ascending order and no for desending order:";
    cin >> input;
    cout << "\n\n";


    sort_cards(deck);
    print_deck(deck, "yes");
}
void shuffle_cards(int deck[])
{
    int card, choice;

    for(card = 0; card < (suites * cards); card++)
    {
        deck[card] = card;
    }
    
    for(card = (suites * cards)-1; card > 1; card--)
    {
        choice = rand() % card;

        swap(deck[card], deck[choice]);
    }
}

void print_cards(int card)
{
    // print card suits

    switch( card / cards )
    {
        case 0:
            cout << "Clubs ";
            break;
        case 1:
            cout << "Diamonds ";
            break;
        case 2:
            cout << "Hearts ";
            break;
        case 3:
            cout << "Spades ";
            break;
    }

    // print card values

    if( (card % cards) < 9 )
    {
        cout << (card % cards)+2;
    }
    else
    {
        switch( card % cards )
        {
            case 9:
                cout << "Jocker";
                break;
            case 10:
                cout << "Queen";
                break;
            case 11:
                cout << "King";
                break;
            case 12:
                cout <<"Ace";
                break;
        }
    }
}

void print_deck(int deck[], string user_input)
{
    int suite, card;
    if(user_input == "yes")
    {
        for(suite = 0; suite < suites; suite++)
        {
            for(card = 0; card < cards; card++)
            {
                print_cards( deck[suite*cards + card] );
                cout << "\n";
            }
            cout << "\n";
        }
    }
    // I was trying to implement the descending. It never stisfy this considion
    else if (user_input == "no")
    {
        for(suite = suites; suite > 0; suite--)
        {
            for(card = cards; card > 0; card--)
            {
                print_cards( deck[suite*cards + card] );
                cout << "\n";
            }
            cout << "\n";
        }        
    }

}

// Sort Cards using Selection Sort
void sort_cards(int deck[])
{
    int firstCard, card;

    for(firstCard = 0; firstCard < (cards * suites - 1); firstCard++)
    {
        for(card = firstCard+1; card < (cards * suites); card++)
        {
            if( deck[card] < deck[firstCard] )
            {
                swap(deck[card], deck[firstCard]);
            }
        }
    }
}

        