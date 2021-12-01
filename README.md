# blackjack
/Modified Nov 8 2021, Jacob Hanson
/modified Dec 1 2021, Jacob H


TODO :::::::::::::::::::::::::::::::::::
Everything needed to complete Black Jack

1. Betting - a way to bet fake money. Allow the player to choose their amount of money. Functions for the house to return money
based on the rules of Black Jack. Allow the player to keep or trash their money. 
2. Player Hits - while the player can pick up cards - check if they pass a point value of 21. That is an instant loss. 
3. Obv - Remove debug stats or create a second project to use as final.
4. OPTIONAL: Make a save file to save a players data so they may return to fight the house. 




//RULES OF BLACK JACK (DUE TO CHANGE)

(1) To start, deck needs to be shuffled
(2) House deals to itself one card face down, and one card to player face up
(3) House deals to itself one card face up and one card to player face up 
(4) Player chooses to "Hit" (another card) until they are satisfied with their hand, which at that time they will "Stand" (Receive no more cards)
(5) The dealer will flip its facedown card and add another card if the point value of their cards is lower than 17. After which they must stand if their point value is greater than 17. 
(6) If the player achieves a point value higher than 21, the player "Busts" or loses
(6.1) If the dealer busts, the player will win 




//Rules for BETS

A bet once paid and collected is never returned. Thus, one key advantage to the dealer is that the player goes first. If the player goes bust, they have already lost their wager, even if the dealer goes bust as well. If the dealer goes over 21, the dealer pays each player who has stood the amount of that player's bet (Receive an equal pay as your own bet). If the dealer stands at 21 or less, the dealer pays the bet of any player having a higher total (not exceeding 21) and collects the bet of any player having a lower total. If there is a stand-off (a player having the same total as the dealer), no chips are paid out or collected.
