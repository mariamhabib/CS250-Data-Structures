# CS 250 - Lab 0

## Stacks Introduction

---

## Introduction

Throughout this class, we will be learning to write and use common
data structures.

Even though in the work world, you may not be implementing these
from scratch very often, it is important to know their inner-workings
and understand them.

But before we get into the inner-workings, it might help to
actually *use* some of these data structures to see the functionality
they provide and how they work.

For this lab, we are going to use the **Stack** object from the C++
**Standard Template Library**.

This lab will step you through the basics to introduce you them.

### Turn-in

Upload your **.cpp**, **.hpp** (or **.h**) files.

Project files are not needed.

### Group Work Policy

* Group work and/or collaboration is allowed for this assignment.
* You are allowed to research on the internet.
* You are allowed to ask the instructor for help.
    * You can either ask to be helped one-on-one, or
    * Ask so that the entire class can hear, and also get help if they're stuck on the same thing.

---

## Reference

* [std::stack reference documentation](http://www.cplusplus.com/reference/stack/stack/) - cplusplus.com

This reference page contains a list of functions available to the 
**stack** object, as well as example code for using it.

---

# Main Program

## Starting Out

Start out your project with the following code:

    #include <stack> // Use the stack object
    #include <iostream> // Input and output to the console
    using namespace std;

    class Card
    {
        public:
        char suit;
        int rank;
    };

    int main()
    {
        stack<Card> deckOfCards;

        for ( int suit = 0; suit < 4; suit++ )
        {
            for ( int rank = 1; rank <= 13; rank++ )
            {
                Card newCard;

                if ( suit == 0 )        { newCard.suit = 'D'; }
                else if ( suit == 1 )   { newCard.suit = 'H'; }
                else if ( suit == 2 )   { newCard.suit = 'C'; }
                else if ( suit == 3 )   { newCard.suit = 'S'; }

                newCard.rank = rank;

                deckOfCards.push( newCard );
            }
        }
        cout << "There are " << deckOfCards.size() << " cards" << endl;

        // 1. Create stacks of cards for each player

        // 2. Distribute cards

        // 3. Display each person's hand
        
        return 0;
    }

This begins our program - it generates a deck of cards: 13 Hearts, 13 Diamonds, 13 Clubs, and 13 Spades.

Each suit has: A, 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, and K. (But we're just using integers intead.)

## Adding on...

The deck is not shuffled, but let's assume we have several players
and we're going to deal the cards out one-at-a-time to each person.

### 1. Create stacks of cards for each player.

Each player will essentially get their own **stack** of cards as well.
Declare these as variables, in the same way that the deck was declared:

    // a STACK of CARD objects, named deckOfCards
    stack<Card> deckOfCards;

Create four stacks: player1, player2, player3, and player4.

### 2. Distribute the cards

Next, we're going to deal cards out to each player until the deck is empty.

With a **stack** structure, you can **only get the top-most
item on the stack**, and cannot access any other items in the
structure.

Like with a deck of cards, you will deal each card, giving each
player whatever card is on the top of the deck.

Here is what you need...

#### top()

The [top()](http://www.cplusplus.com/reference/stack/stack/top/) function
of the **stack** object will allow you to get the top-most item.

Since we have a stack of cards, when we call top(), we will get
the top-most **Card** object.

To access any cards beneath the top card, we then have to **pop()**
the top card off the stack.

#### pop()

The [pop()](http://www.cplusplus.com/reference/stack/stack/pop/) function
of the stack object will remove the top-most item from the stack.

If you keep using pop() over and over, you will eventually get an
empty stack.

#### empty()

The [empty()](http://www.cplusplus.com/reference/stack/stack/empty/) function
will return either **true** or **false**.

It will return true if the stack is empty, and false if it is not empty.

#### Putting it together

Write the following logic in the code:

1. While the deck of cards is not empty...
    1. Deal to player 1
        1. Push the top card from **deckOfCards** to the **player1** stack.
        
        1. pop the top card off of the **deckOfCards** stack.
    
    1. Deal to player 2
        1. Push the top card from **deckOfCards** to the **player2** stack.
        
        1. pop the top card off of the **deckOfCards** stack.
    
    1. Deal to player 3
        1. Push the top card from **deckOfCards** to the **player3** stack.
        
        1. pop the top card off of the **deckOfCards** stack.
    
    1. Deal to player 4
        1. Push the top card from **deckOfCards** to the **player4** stack.
        
        1. pop the top card off of the **deckOfCards** stack.
    

### 3. Display each person's hand

If we were storing all our cards in an array, we could access any card at random:

    cout << deckOfCards[2].rank << endl;

But with a stack, **we can only access the top-most item**.

Since we cannot **randomly access** items in the stack, in order to display all the cards in
a player's possession, we have to go from the **top, down**, displaying the top, 
popping it off the stack, and continuing on until the stack is empty.

This also means that the **last item added to the stack** is the top-most item,
and will show up first.

Display each player's hand with this logic...

1. While (player)'s hand is not empty...
    
    1. Display the top card (suit and rank)
    
    1. Pop the top of the stack
    
Do this for each player.

---

# Sample Output

    There are 52 cards

    Player1's Deck
    [4-D]	[8-D]	[12-D]	[3-H]	[7-H]	[11-H]	[2-C]	[6-C]	[10-C]	[1-S]	[5-S]	[9-S]	[13-S]	

    Player2's Deck
    [3-D]	[7-D]	[11-D]	[2-H]	[6-H]	[10-H]	[1-C]	[5-C]	[9-C]	[13-C]	[4-S]	[8-S]	[12-S]	

    Player3's Deck
    [2-D]	[6-D]	[10-D]	[1-H]	[5-H]	[9-H]	[13-H]	[4-C]	[8-C]	[12-C]	[3-S]	[7-S]	[11-S]	

    Player4's Deck
    [1-D]	[5-D]	[9-D]	[13-D]	[4-H]	[8-H]	[12-H]	[3-C]	[7-C]	[11-C]	[2-S]	[6-S]	[10-S]	

