var numArray = [4,7,23,47];
value = 4;

function searchArray (array, value) {
    let length = array.length;
    for(let i = 0; i < length; i++) {
        if(array[i] === value) {
            return i;
        }
    }
    return -1;
}

/* let output = searchArray(numArray, value);
if(output === -1) {
    console.log("The value " + value + " could not found in the array.");
} 
else {
    console.log("The value " + value + " found at index " + output);
} */


function displayArray (array) {
    let length = array.length;
    for(let i = 0; i < length; i++) {
        console.log("The " + (i + 1) + "th item is " + array[i]);
    }
}

//displayArray(numArray);


function insertArray(array, value, position) {
    let length = array.length;
    for(let i = length; i >= position; i--) { 
        array[i] = array[i-1]; //Shift elements down one by one starting from bottom  
    }
    array[position-1] = value; //Put the value into wanted position
}

/*insertArray(numArray,86,1);
displayArray(numArray);*/

function deleteArray(array, position) {
    let length = array.length;
    for(let i = position; i < length; i++){
        array[i-1] = array[i];
    }
    array[length-1] = 0;
}

/*displayArray(numArray);
deleteArray(numArray,1);
displayArray(numArray);*/


