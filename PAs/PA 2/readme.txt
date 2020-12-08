CSCI 103 Twenty One Programming Assignment 

Name:

Email Address: 

NOTE: You can delete the questions, we only need your responses.

NOTE: It is helpful if you write at most 80 characters per line,
and avoid including special characters, so we can read your responses.

Please summarize the help you found useful for this assignment, which
may include office hours, discussion with peers, tutors, et cetera.
Saying "a CP on Tuesday" is ok if you don't remember their name.
If none, say "none".

:

================================ Questions ==================================

1. Did you use the 'suit', 'type' and 'value' arrays? What functions are easier
to implement when using these arrays? How do you use them?

:Yes, I used these arrays. These arrays were useful in the printCard, cardValue, 
and printHand functions because it let you easily access the properties associated
with each card. Dividing the card ID by 13 gets you the house and subtracting the 
house ID multiplied by 13 from the card ID got you the type of card it was.

2. Did you add any additional functions to your implementation? If so briefly
describe how the functions improved your solution.

:Yes, I have a function called setup() and it sets up the whole deck by populating
and shuffling it and dealing the first set of cards. It's useful to coserve space 
in the main() just so it doesn't get too hard to read. I also wrote gameScore()
to print out whether the Player Won, Lost, or Tied and the score of the game.

3. There are many ways to shuffle the deck of cards. The method used in our
implementation generates a permutaion of the cards to shuffle. For an array of
size N, how many swap (exchange) operations does this algorithm do? Does the
algorithm require any extra memory to generate a permutation?

: In the Fisher-Yates / Durstenfeld shuffle algorithm swaps cards N times.
Yes it requires a temporary holder integer for the swapping.

================================ Remarks ====================================

Filling in anything here is OPTIONAL.

Approximately how long did you spend on this assignment?

: Took me 3 days. I think maybe 7 hours total not sure.

Were there any specific problems you encountered? This is especially useful to
know if you turned it in incomplete.

:I think a lot of the issues I had were just about not understanding how the game itself works.
I've never played cards so the whole situation was slightly confusing.
For example I thought that the dealer was supposed to hit every time the player hits if the 
Dealer sum is under 17.

Do you have any other remarks?

:
