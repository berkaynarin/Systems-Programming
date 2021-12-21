let numArray = [];
maxValue = 5; //Maximum size of the stack
let top = -1; //Identifies the index of the top of the stack. Starts from -1, because each push invoke will increase top by one.
const prompt = require("prompt-sync")(); //To read input from console

function push(value) {
  if (numArray.length === maxValue) {
    //Actually arrays in JS can extend, but I try to implement real-world application of stacks.
    console.log("Cannot insert a new item to the list. The stack is full.");
  } else {
    top = top + 1;
    numArray[top] = value;
  }
}

function pop() {
  if (numArray.length === 0) {
    //Check if the stack is empty
    console.log("Cannot remove an element. The stack is empty.");
  } else {
    numArray[top] = null; //Assign null to the last element of the stack (i.e. remove element from the top of the stack)
    --top;
  }
}

function display() {
  let j = 1;
  if (numArray.length != 0) {
    for (let i = top; i >= 0; i--) {
      console.log(j + ". element: " + numArray[i]);
      j++;
    }
    return 1;
  }
  console.log("The stack is empty. Nothing to display.");
}

console.log("Stack implementation with JavaScript\n");

do {
  console.log(
    "\n 1.Push a new element \n 2.Pop an element \n 3.Display the stack \n 4.Exit the program\n\n"
  );
  var input = prompt("Please select one of the options below: ");
  switch (Number(input)) {
    case 1:
      let value = prompt("Please enter the value you want to push: ");
      push(Number(value)); //I cannot check here if the user is giving different types of elements
      //because prompt method always stores input as strings
      break;
    case 2:
      pop();
      break;
    case 3:
      display();
      break;
  }
} while (Number(input) != 4);
