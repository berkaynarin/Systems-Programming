let head = 0; // Identifies the index of start of the queue
let tail = 0; // Identifies the index of end of the queue
let numArray = [];
let maxValue = 5; //Maximum size of the queue

function enqueue(value) {
    if(tail + 1 > maxValue) { //Check if queue is full
        console.log("Cannot enqueue a new element. The queue is full.")
    }
    else {
        numArray[tail] = value; // Insert a new element to the end of the queue
        tail++;
    }
}

function dequeue() {
    if(tail < 1) { // Check if queue is empty
        console.log("Cannot dequeue an element. The queue is empty.")
    }
    else {
        for (let i = head; i < tail; i++) {
            numArray[i] = numArray[i+1]; //Shifting elements up starting from top
        }
        numArray[tail - 1] = null; //Deleting last element from the queue
        tail--;
    }
}

function display() {
    if(tail < 1) { // Check if queue is empty
        console.log("Cannot display the queue. The queue is empty.")
    }
    else {
        for (let i = head; i < tail; i++) {
            console.log((i+1) + ". element: " + numArray[i]);
        }
    }
}

enqueue(4);
enqueue(8);
enqueue(7);
enqueue(63);
enqueue(89);
dequeue();
enqueue(21);
enqueue(56); // Should show an error for this one 
display(); // Should display 8,7,63,89,21






