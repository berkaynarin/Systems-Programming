let numArray = [];
maxValue = 5; //Maximum size of the stack
let top = -1; //Identifies the index of the top of the stack. Starts from -1, because each push invoke will increase top by one.
let j = 1;            


function push(value) {
    if(numArray.length === maxValue) { //Actually arrays in JS can extend, but I try to implement real-world application of stacks.
        console.log("Cannot insert a new item to the list. The stack is full.")
    }
    else {
        top = top + 1;
        numArray[top] = value;
    }
}


function pop() {
    if(numArray.length === 0) { //Check if the stack is empty
        console.log("Cannot remove an element. The stack is empty.")
    }
    else {
        numArray[top] = null; //Assign null to the last element of the stack (i.e. remove element from the top of the stack)
        --top;
    }
}

function display() {
    if(numArray.length != 0) {
        for(let i = top; i >= 0; i--) {
            console.log(j + ". element: " + numArray[i]);
            j++;
        }
        return 1;
    }
    console.log("The stack is empty. Nothing to display.")
}

push(5);
push(13);
pop();
display();
