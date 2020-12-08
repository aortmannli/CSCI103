CSCI 103 Programming Assignment 1, Hailstone

Name:Angel Li

Email Address: liangeli@usc.edu

NOTE: You can delete the questions, we only need your responses.

NOTE: It is helpful if you write at most 80 characters per line,
and avoid including special characters, so we can read your responses.

Please summarize the help you found useful for this assignment, which
may include office hours, discussion with peers, tutors, et cetera.
Saying "a CP on Tuesday" is ok if you don't remember their name.
If none, say "none".

: None

================================ Questions ==================================

1. Which kind of a loop did you use for the first program? Why?

:I used a while loop because we were essentionally just changing the number until it was equal to 1. It wouldn't make sense to use 
a for loop because we don't know the number of iterations, that's percisely what we were looking to find.

2a. Once you've completed the second program, run hailstats on the following
inputs, and record your results in the table below:

  input range  | minimum length | achieved by | maximum length | achieved by
-----------------------------------------------------------------------------
    50 100     |        6       |     64      |       118      |     97   
   100 200     |        7       |     128     |       124      |     171        
   200 400     |        8       |     256     |       143      |     327        

2b. What pattern do you think there is in the values achieving minimum length?
Can you explain why it holds?

:The minimum length is always achieved by the smallest power of 2 present in that range. Likely because
the number of steps is just the power of 2 it holds because you never have to take the
step for an odd number and you can just keep diving by 2.

3a. Let X be the smallest integer whose length is greater than 150.
By running your hailstats program several times on carefully chosen inputs,
determine what is the value of X.

X is : 703

3b. Explain, briefly, the way in which you used your hailstats program
(i.e., which inputs you gave it) to find this answer.

: Given the values in 2a, I understood that X would be greater than 400. So, 
I put in 400-800 and it showed that the length of 170 was achieved by 703. I then checked 400-702 
to see if ther might be a max in that range over 150 and there was not. Therefore, the first number 
with length greater than 150 would be 702 with length 170.

================================ Remarks ====================================

Filling in anything here is OPTIONAL.

Approximately how long did you spend on this assignment?

: Both hailstone assignments took me about 30 minutes in actual coding time (I think). Abundant commas took me 
several hours and Abundant was quick but only after I completed Lab 1. 

Were there any specific problems you encountered? This is especially useful to
know if you turned it in incomplete.

: The thing that was most problematic for me in Abundant Commas was the very thing
that the exercise was designed for: the usage of long longs. I also didn't realize that the
test cases were available on Piazza until quite late.

Do you have any other remarks? 

: The fact that test cases were available was really helpful.
I think what I have found most challenging is mentally converting from Java and Python
to C++ which is a natural hurdle to overcome. Unfortunately because of this I find it difficult 
to think of the possible bugs that come from my misunderstanding of types or ways to catch edge cases.
I found this particularly challenging at first with taking an input in Abundant. 