/***********************************************************************************************************
**Author: Ethan Dunham
**Date: 5/12/17
** Prog Name: BlackJack
**Description: This program uses the Deck of Cards API to play Blackjack.
***********************************************************************************************************/

//variables
var deckID;
var pCards = [];
var numPCards;
var dCards = [];
var numDCards;
var pTurn = true;
var pTotal = 0;
var dTotal = 0;
var pHasAce = false;
var dHasAce = false;
var score = 0;
var winState = true;
var first = true;

//create divs for images
var dDiv = document.createElement("div");
document.getElementById('dealer').appendChild(dDiv);
var pDiv = document.createElement("div");
document.getElementById('player').appendChild(pDiv);

//place current score of 0 on page
document.getElementById('score').textContent = score;

//adds image
function addimg(cards, num, div) {
    //creates new img
    var card = document.createElement("img");
    card.src = cards[num].image;
    //adds it to the correct div
    div.appendChild(card);
}

//calculates hand value
function calculate(card, currentTotal, player) {
    //if card is not a number card or 10
    if (card.value[0] > "9" || card.value[0] < "2") {
        //if card is an ace
        if (card.value[0] == "A") {
            //ace is worth 11 if score is less than 11
            if (currentTotal < 11) {
                currentTotal += 11;
                //set ace to true in case of future bust depending on player
                if (player) {
                    pHasAce = true;
                }
                else {
                    dHasAce = true;
                }
            }
                //set ace to 1 if it would cause player to bust
            else
                currentTotal += 1;
        }
            //if not an ace, add 10 to player score
        else
            currentTotal += 10;
    }
    else {
        //divide card.Value[0] by 1 to force it to become an int
        var val = card.value[0] / 1;
        //add that into the the score
        currentTotal += val;
    }
    return currentTotal;
}

//Updates win fields
//takes in 0, 1, or another number
function win(state) {

    //player won
    if (state == 1) {
        document.getElementById('pwin').textContent = "You Won!";
        document.getElementById('dwin').textContent = "The Dealer Lost!";
        score++;
        winState = true;
        document.getElementById('score').textContent = score;
    }

        //dealer won
    else if (state == 0) {
        document.getElementById('pwin').textContent = "You Lost :(";
        document.getElementById('dwin').textContent = "The Dealer Won!";
        winState = true;
        score--;
        document.getElementById('score').textContent = score;
    }

        //tie
    else {
        document.getElementById('pwin').textContent = "Push";
        document.getElementById('dwin').textContent = "Push";
        winState = true;
    }

}

//initialized deck
createNew();

//create new decks
function createNew() {
    var req = new XMLHttpRequest();
    //all calls are not asynchronous because one cannot play blackjack without cards
    //shuffle = shuffled deck
    //deck_count=7 means 7 decks shuffled together
    req.open("GET", "https://deckofcardsapi.com/api/deck/new/shuffle/?deck_count=7", false);
    req.send(null);
    var deckInfo = JSON.parse(req.responseText);
    
    //save the deck ID to access the already created decks
    deckID = deckInfo.deck_id;
}


//deals a new hand when finished with old hand
document.getElementById('deal').addEventListener('click', function (event) { deal(); });

//draw 4 cards
function deal() {
    //new round if last is completed
    if (winState) {
        //if this is not the first round, reset variables.
        if (!first)
        {
            reset();
        }
        winState = false;
        first = false;
        //draws the initial cards
        //draw means draw
        //count=4 means drawing 4
        var req2 = new XMLHttpRequest();
        req2.open("GET", "https://deckofcardsapi.com/api/deck/" + deckID + "/draw/?count=4", false);
        req2.send(null);

        //set cards to be JSON of returned message
        var cards = JSON.parse(req2.responseText);

        //if deck is almost gone by checking remaining card field
        if (cards.remaining < 20) {
            //reshuffles the deck by calling /shuffle/
            var req4 = new XMLHttpRequest();
            req4.open("GET", "https://deckofcardsapi.com/api/deck/" + deckID + "/shuffle/", false);
            req4.send(null);
        }

        //deal to player first
        pCards.push(cards.cards[0]);

        //add image of card to div
        addimg(pCards, 0, pDiv);

        //deal the 3rd card to player
        pCards.push(cards.cards[2]);

        //add image
        addimg(pCards, 1, pDiv);

        //keep track of cards
        numPCards = 2;

        //calculates current score
        pTotal = calculate(pCards[0], pTotal, pTurn);
        pTotal = calculate(pCards[1], pTotal, pTurn);

        //blackjack
        if (pTotal == 21) {
            pTotal = "Blackjack!"
        }

        //displays current score on page
        document.getElementById('ptotal').textContent = pTotal;

        //deals second card to dealer
        dCards.push(cards.cards[1]);

        //displays face down card
        var card = document.createElement("img");
        card.src = "back.png";// citation http://www.jimknapp.com/Cards/Bicycle_files/image002.jpg
        dDiv.appendChild(card);

        //deals 4th card to dealer
        dCards.push(cards.cards[3]);

        //displays face up card
        addimg(dCards, 1, dDiv);

        //num of cards
        numDCards = 2;

        //get dealer's score only using second card
        dTotal = calculate(dCards[1], dTotal, false);
        //display second card value for dealer's score
        document.getElementById('dtotal').textContent = dTotal;

        //checks against player Blackjack
        if(dTotal<10 && pTotal=="Blackjack!")
        {
            win(1);
        }
        else if(dTotal>9 && pTotal=="Blackjack!"){
            pTurn=false;
            stand();
        }
    }
}

//draws a card and adds it to player total
document.getElementById('hit').addEventListener('click', function (event) { draw(); });

//draws a card
function draw() {
    if (!winState) {
        //draw another card using draw/count=1
        var req3 = new XMLHttpRequest();
        req3.open("GET", "https://deckofcardsapi.com/api/deck/" + deckID + "/draw/?count=1", false);
        req3.send(null);
        var card = JSON.parse(req3.responseText);

        //if player's turn
        if (pTurn) {
            //add card to hand
            pCards.push(card.cards[0]);
            //increase player's cards
            numPCards++;

            //add the new card image to the div
            addimg(pCards, numPCards-1, pDiv);

            //calculate new score of player
            pTotal = calculate(pCards[numPCards - 1], pTotal, pTurn);

            //check to see if has ace or bust
            if (pTotal > 21) {
                if (pHasAce) {
                    //change ace to a 1 and remove hasAce
                    pTotal -= 10;
                    pHasAce = false;
                }
                //if no ace, they bust
                if (pTotal > 21) {
                    cont = false;
                    pTotal = "Bust!";
                    //player lost, locks buttons except deal
                    win(0);
                }
            }
        }
        else {
            dCards.push(card.cards[0]);
            numDCards++;

            addimg(dCards, numDCards - 1, dDiv);

            dTotal = calculate(dCards[numDCards - 1], dTotal, pTurn);

            if (dTotal > 21) {
                if (dHasAce) {
                    dTotal -= 10;
                    dHasAce = false;
                }
                if (dTotal > 21) {
                    cont = false;
                    dTotal = "Bust!";
                    //player won, locks buttons except deal
                    win(1);
                }
            }
        }
        //display the updated score
        document.getElementById('ptotal').textContent = pTotal;
        document.getElementById('dtotal').textContent = dTotal;
    }
}


//locks the player's score and cards and lets the dealer play
document.getElementById('stand').addEventListener('click', function (event) { stand(); });

//locks player's score and cards and lets computer play
function stand() {
    if (!winState) {
        //switches to computer turn
        pTurn = false;

        //calculates total with face down card
        dTotal = calculate(dCards[0], dTotal, pTurn);

        //switches face down image to actual card image
        dDiv.childNodes[0].src = dCards[0].image;

        //dealer bacljack
        if (dTotal == 21) {
            dTotal = "Blackjack!";
            if (pTotal != "Blackjack!") {
                win(0);
            }
            else {
                win(2);
            }
        }
        //sets updated dealer total
        document.getElementById('dtotal').textContent = dTotal;

        //player blackjack
        if (pTotal == "Blackjack!" && dTotal != "Blackjack!") {
            win(1);
        }

        //draw until over 16
        while (dTotal < 17) {
            draw();
        }

        //compare
        if(pTotal>dTotal && !winState)
        {
            //player wins
            win(1);
        }
        else if (pTotal < dTotal && !winState) {
            //dealer wins
            win(0);
        }
        else if(!winState){
            //tie/push
            win(2);
        }
    }
}

//resets variables
function reset() {
    //remove old cards
    while (dDiv.firstChild) {
        dDiv.removeChild(dDiv.firstChild);
    }
    while (pDiv.firstChild) {
        pDiv.removeChild(pDiv.firstChild);
    }

    //remove win display
    document.getElementById('pwin').textContent = '';
    document.getElementById('dwin').textContent = '';

    //reset needed variables back to default
    pCards.length = pTotal = dTotal = dCards.length = 0;
    pTurn = true;
    winState = pHasAce = dHasAce = false;


}