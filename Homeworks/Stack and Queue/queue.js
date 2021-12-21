let head = 0; // Identifies the index of start of the queue
let tail = 0; // Identifies the index of end of the queue
let numArray = [];
let maxValue = 5; //Maximum size of the queue
const prompt = require("prompt-sync")(); //To read input from console

function enqueue(value) {
  if (tail + 1 > maxValue) {
    //Check if queue is full
    console.log("Cannot enqueue a new element. The queue is full.");
  } else {
    numArray[tail] = value; // Insert a new element to the end of the queue
    tail++;
  }
}

function dequeue() {
  if (tail < 1) {
    // Check if queue is empty
    console.log("Cannot dequeue an element. The queue is empty.");
  } else {
    for (let i = head; i < tail; i++) {
      numArray[i] = numArray[i + 1]; //Shifting elements up starting from top
    }
    numArray[tail - 1] = null; //Deleting last element from the queue
    tail--;
  }
}

function display() {
  if (tail < 1) {
    // Check if queue is empty
    console.log("Cannot display the queue. The queue is empty.");
  } else {
    for (let i = head; i < tail; i++) {
      console.log(i + 1 + ". element: " + numArray[i]);
    }
  }
}

console.log("Queue implementation with JavaScript\n");

do {
  console.log(
    "\n 1.Enqueue a new element \n 2.Dequeue an element \n 3.Display the queue \n 4.Exit the program\n\n"
  );
  var input = prompt("Please select one of the options below: ");
  switch (Number(input)) {
    case 1:
      let value = prompt("Please enter the value you want to enqueue: ");
      enqueue(Number(value)); //I cannot check here if the user is giving different types of elements
      //because prompt method always stores input as strings
      break;
    case 2:
      dequeue();
      break;
    case 3:
      display();
      break;
  }
} while (Number(input) != 4);
