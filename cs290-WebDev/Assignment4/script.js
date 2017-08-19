/************************************************************************************************
***Author:Ethan Dunham
***Date: 5/2/17
***Discription: This creates a table, arrow buttons, and a change cell color button. Allows the
***             user to select a cell of the table and change it to yellow.
*************************************************************************************************/

//square object keeps track of X and Y for location and holds functions to change color and current location.
var square = {
    X: "0", Y: "0",
    increaseY: function (event) {
        if (this.Y != 3)
            this.Y++;
        newTable.rows[this.X].cells[this.Y].style.border = "3px solid";
    }, increaseX: function (event) {
        if (this.X != 2)
            this.X++;
        newTable.rows[this.X].cells[this.Y].style.border = "3px solid";
    }, decreaseX: function (event) {
        if (this.X != 0)
            this.X--;
        newTable.rows[this.X].cells[this.Y].style.border = "3px solid";
    }, decreaseY: function (event) {
        if (this.Y != 0)
            this.Y--;
        newTable.rows[this.X].cells[this.Y].style.border = "3px solid";
    }, changeColor: function (event) {
        newTable.rows[this.X].cells[this.Y].style.backgroundColor = "yellow"
    }, changeDefault: function (event) {
        newTable.rows[this.X].cells[this.Y].style.border = "1px solid";
    }
}

var newTable = document.createElement("table");
for (var i = 0; i < 4; i++) {
    var newItem = document.createElement("th");
    newItem.textContent = "Header " + (i + 1);
    newTable.appendChild(newItem);
    newItem.style.border = "2px solid";
}
for (var i = 0; i < 3; i++) {
    var newRow = newTable.insertRow(i);
    for (var j = 0; j < 4; j++) {
        var cell1 = newRow.insertCell(j);
        cell1.style.border = "1px solid";
        cell1.textContent = (j + 1) + "," + (i + 1);
    }
}
newTable.style.border = "1px solid";
document.body.appendChild(newTable);

var upButton = document.createElement("button");
document.body.appendChild(upButton);
upButton.textContent = "Up";
var downButton = document.createElement("button");
document.body.appendChild(downButton);
downButton.textContent = "Down";
var leftButton = document.createElement("button");
document.body.appendChild(leftButton);
leftButton.textContent = "Left";
var rightButton = document.createElement("button");
document.body.appendChild(rightButton);
rightButton.textContent = "Right";
var markButton = document.createElement("button");
document.body.appendChild(markButton);
markButton.textContent = "Mark Cell";

newTable.rows[square.X].cells[square.Y].style.border = "3px solid";

markButton.addEventListener("click", function () { square.changeColor(); });

leftButton.addEventListener("click", function () { square.changeDefault(); });
leftButton.addEventListener("click", function () { square.decreaseY(); });

rightButton.addEventListener("click", function () { square.changeDefault(); });
rightButton.addEventListener("click", function () { square.increaseY(); });

upButton.addEventListener("click", function () { square.changeDefault(); });
upButton.addEventListener("click", function () { square.decreaseX(); });

downButton.addEventListener("click", function () { square.changeDefault(); });
downButton.addEventListener("click", function () { square.increaseX(); });




