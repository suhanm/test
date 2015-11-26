#define _CRT_SECURE_NO_WARNINGS

// The purpose of these ten functions is to solve a range of problems given certain
// parameters or initial conditions.
// Author : Suhan Muppavaram

#include <stdio.h>
#include <string.h>
#include "project.h"
void RotateCharacter(char *name);
void sortArray(int *values, int numValues);
void Reverse(int *values, int numValues);
void Swap(int *values, int i, int j);


// The purpose of this function is to find the middle value for any 3 numbers.
// Author : Suhan Muppavaram 
int MiddleOfThree(int a, int b, int c)
{
	int middle;

	// if c is to be the middle value, it must be smaller than a and greater than b
	// or vice versa. 
	if (((c > b) && (c < a)) || ((c<b) && (c>a))){
		middle = c;
	}
	// if b is to be the middle value, it must be smaller than c and greater than a
	// or vice versa.
	else if (((b > a) && (b < c)) || ((b<a) && (b>c))){
		middle = b;
	}
	// if a is to be the middle value, it must be smaller than b and greater than c
	// or vice versa.
	else if (((a > c) && (a < b)) || ((a<c) && (a>b))){
		middle = a;
	}

	// if 2 values are the same, the middle is either of those values.
	else if (a == b){
		middle = a;
	}

	else if (a == c){
		middle = c;
	}

	else middle = b;

	return middle;
}

// The purpose of this function is to determine the number of apple boxes
// to purchase so that each student receives atleast 1 apple, 2 on the last
// day of the week, based on how apples remain from the previous week and
// the amount of apples that are in a box. Taking into account of not over 
// purchasing, but still satisfying all the students.
// Author : Suhan Muppavaram
int AppleBoxesNeeded(int numStudents, int lastDayOfWeek, int remainingApples, int applesPerBox)
{
	int boxes;

	if (lastDayOfWeek == 1){

		//if there is an uneven distribution of apple boxes needing to be 
		//purchased, with the number of students(hence a remainder) 
		//i.e 5.5 boxes or 2.3 boxes, always round up, so that all students 
		//are satisfied.

		if ((((numStudents * 2) - remainingApples) % applesPerBox)){
			boxes = (((numStudents * 2) - remainingApples) / applesPerBox) + 1;
		}

		else{

			boxes = (((numStudents * 2) - remainingApples) / applesPerBox);
		}
		// Note also that if the number of apples remaining from last week
		// is enough to satisy students, we need not purchase any boxes.
		if (remainingApples >= numStudents * 2){
			boxes = 0;
		}

	}
	// Same idea, except when its not the last day of the week.

	else {

		if ((numStudents - remainingApples) % applesPerBox){
			boxes = ((numStudents - remainingApples) / applesPerBox) + 1;
		}

		else{
			boxes = ((numStudents - remainingApples) / applesPerBox);
		}
		if (remainingApples >= numStudents){
			boxes = 0;
		}

	}



	return boxes;
}

// The purpose of this function is take in a phrase and capitalise the 
// first character of all the words in that phrase.
// Author: Suhan Muppavaram
void Capitalise(char *phrase)
{
	int length;
	int i;

	length = strlen(phrase);

	// This will set the first character in the phrase from a lower case
	// to upper case if its a letter.

	if ((phrase[0] >= 97) && (phrase[0] <= 122)){
		phrase[0] = phrase[0] - 32;
	}

	// This will set the preceeding characters to a capital, if they are 
	// lower case and have a space to their left.
	for (i = 1; i <= length; i++){
		if ((phrase[i] >= 97) && (phrase[i] <= 122) && (phrase[i - 1] == 32)){
			phrase[i] = phrase[i] - 32;
		}
	}

}

// The purpose of this function is to find the position of the maximum number
// in a 2d array, assuming the dimensions of the matrix matches the inputs
// by the user.
// Author : Suhan Muppavaram
void PositionOfMaximum(int *values, int rows, int cols, int *row, int *col)
{
	int i, max, indexno;

	// Loops through 1-d array to find the max number and its INDEX
	// position.
	max = values[0];
	indexno = 0;
	for (i = 0; i < rows*cols; i++){
		if (values[i] > max){
			max = values[i];
			indexno = i;
		}

	}
	// Returns the row and column in which this maximum value is 
	// located.
	*row = indexno / cols;
	*col = indexno % cols;

}

// The purpose of this function is to rotate a word or sentence a 
// specific amount of times, and once the end character leaves the end
// of its sentence or word, it should rejoin on the left.
// Author : Suhan Muppavaram
void Rotate(char *word, int amount)
{
	int i;

	// Rotates word based on the amount the user inputs.

	for (i = 1; i <= amount; i++){
		RotateCharacter(word);
	}

}

//Task 5 Helper function
void RotateCharacter(char *name){
	int i;
	char a;
	char b;
	int length;

	length = strlen(name);

	// stores the first and last character of the string in a and b
	// respectively.

	a = name[0];
	b = name[length - 1];

	// makes the last element in array the value to its left, and
	// so on.

	for (i = length - 1; i > 1; i--){
		name[i] = name[i - 1];
	}

	// replaces the first and second elements with the original 
	// first and last elements.

	name[0] = b;
	name[1] = a;

}


// The purpose of this function is to find the DOUBLE median value of 
// any given array.
// Author: Suhan Muppavaram
int DoubleMedian(int *values, int numValues)
{
	int doublemedian;


	// sorts array to make it in an ascending order.

	sortArray(values, numValues);

	// if there is no remainder ( i.e an array with an even number
	// of elements) the following is implemented to give the double 
	// median.

	if (numValues % 2 == 0){

		doublemedian = values[numValues / 2] + values[(numValues / 2) - 1];
	}

	// otherwise if array is odd, than this is implemented. 

	else{
		doublemedian = 2 * values[((numValues - 1) / 2)];
	}

	return doublemedian;
}

//Task 6 Helper funtion
void sortArray(int *values, int numValues){
	int i;
	int j;
	int a;

	for (i = 0; i < numValues; i++)
	{
		for (j = i + 1; j < numValues; j++)
		{
			if (values[i] > values[j])
			{
				// if the 1st element is greater than the 2nd
				// it is stored in a, and the larger value is changed
				// to smaller value, and smaller value changed to larger
				// value. i.e swapped around.

				a = values[i];
				values[i] = values[j];
				values[j] = a;
			}
		}
	}
}


// The purpose of this function is to find the maximum approved area (
// i.e the total area of all the squares that do not overlap with each 
// other ) given a set (or array) of squares with varying postions and 
// sizes.
// Author: Suhan Muppavaram
int ApprovedArea(Square squares[MAX_ARRAY_SIZE], int numSquares)
{
	int i;
	int j;
	int area = 0;
	int topLeftrowi;
	int topLeftcoli;
	int bottomRightrowi;
	int bottomRightcoli;
	int topLeftrowj;
	int topLeftcolj;
	int bottomRightrowj;
	int bottomRightcolj;
	int count;


	// Both for loops initially calculate the coordinates of the 2 corners
	// of each square. 

	for (i = 0; i < numSquares; i++){
		topLeftrowi = squares[i].row - ((squares[i].size) / 2);
		topLeftcoli = squares[i].col - ((squares[i].size) / 2);
		bottomRightrowi = squares[i].row + ((squares[i].size) / 2);
		bottomRightcoli = squares[i].col + ((squares[i].size) / 2);

		count = 0; // Resets count to 0 after 2nd loop ends. 

		for (j = 0; j < numSquares; j++){

			topLeftrowj = squares[j].row - ((squares[j].size) / 2);
			topLeftcolj = squares[j].col - ((squares[j].size) / 2);
			bottomRightrowj = squares[j].row + ((squares[j].size) / 2);
			bottomRightcolj = squares[j].col + ((squares[j].size) / 2);

			// Preceeding condition checks if the squares overlap based on their corners.

			if ((topLeftrowi < bottomRightrowj) && (bottomRightrowi > topLeftrowj) &&
				(topLeftcoli < bottomRightcolj) && (bottomRightcoli > topLeftcolj)){
				count = count++; // if 2 squares overlap count gets 1
				if (i == j) {
					// if the 2 squares are the same, count looses 1 as they are the same square 
					// and they dont count as overlap, (practically speaking).   
					count = count - 1;
				}
			}

		}
		// if count remains 0 after checking all squares, calculate area of that square
		// and add to area of the previous area.
		if (count == 0){
			area = area + squares[i].size * squares[i].size;
		}

	}

	return area;

}

// The purpose of this function is to add 2 arbitrarily large numbers
// together.
// Author: Suhan Muppavaram
void Add(char *input1, char *input2, char *sum)
{
	int inumberOne[1000] = { 0 };
	int inumberTwo[1000] = { 0 };
	int iSum[1000] = { 0 };
	int i;
	int lengthone;
	int lengthtwo;
	int looplength;

	lengthone = strlen(input1);
	lengthtwo = strlen(input2);

	// Runs this if string of numbers are same length
	if (lengthone == lengthtwo){
		lengthone = strlen(input1) + 1;
		lengthtwo = strlen(input2) + 1;

		looplength = lengthone;

		lengthone--;
		lengthtwo--;

		// converts the string of numbers into an array of numbers
		for (i = 0; i < lengthone; i++){
			inumberOne[i] = input1[i] - 48;
		}

		for (i = 0; i < lengthtwo; i++){
			inumberTwo[i] = input2[i] - 48;
		}

		// reverses both the arrays

		Reverse(inumberOne, lengthone);
		Reverse(inumberTwo, lengthtwo);

		// performs the typical addition of large numbers, however
		// from right to left.
		for (i = 0; i < 1000; i++){
			iSum[i] = inumberOne[i] + inumberTwo[i] + iSum[i];
			if (iSum[i] > 9){
				iSum[i] = iSum[i] - 10;
				iSum[i + 1] = iSum[i + 1] + 1;
			}
		}

		// reverses back the sum array.

		Reverse(iSum, looplength);

		// checks if there is a 0 in the first row first coulmn, 
		// if there is, it shifts entire array to left.

		if (iSum[0] == 0){
			for (i = 0; i < looplength; i++){
				iSum[i] = iSum[i + 1];
			}
			looplength--;
		}

		// converts back into a string array
		for (i = 0; i < looplength; i++){
			sum[i] = (char)iSum[i] + 48;
		}

		// sets the null chracter at the end of the string
		sum[looplength] = 0;

	}
	// if the numbers are not the same string length, run this.
	else {

		// lengths need to increased by one for the carry

		lengthone = strlen(input1) + 1;
		lengthtwo = strlen(input2) + 1;


		// finds the loop length and then subtracts 1 from lengths 

		if (lengthone > lengthtwo){
			looplength = lengthone;
		}
		else{
			looplength = lengthtwo;
		}

		if (input1[0] + input2[0] > 9){
			lengthone = lengthone - 1;
			lengthtwo = lengthtwo - 1;
		}

		// converts to int arrays
		for (i = 0; i < lengthone; i++){
			inumberOne[i] = input1[i] - 48;
		}

		for (i = 0; i < lengthtwo; i++){
			inumberTwo[i] = input2[i] - 48;
		}

		// Reverses largest array if one array only has 1 element.

		if (lengthone == 1){
			Reverse(inumberTwo, lengthtwo);
		}
		else if (lengthtwo == 1){
			Reverse(inumberOne, lengthone);
		}
		else if (lengthone == lengthtwo){

		}

		else {
			Reverse(inumberTwo, lengthtwo);
			Reverse(inumberOne, lengthone);
		}


		// adds individual elements of array
		for (i = 0; i < 1000; i++){
			iSum[i] = inumberOne[i] + inumberTwo[i] + iSum[i];
			if (iSum[i] > 9){
				iSum[i] = iSum[i] - 10;
				iSum[i + 1] = iSum[i + 1] + 1;
			}

		}

		// Reverses back the sum array
		Reverse(iSum, looplength);

		// again checks if 0 is in first postion
		if (iSum[0] == 0){
			for (i = 0; i < looplength; i++){
				iSum[i] = iSum[i + 1];
			}
			looplength--;
		}
		// converts back to string 
		for (i = 0; i < looplength; i++){
			sum[i] = (char)iSum[i] + 48;
		}
		// sets the null character at the end of the string
		sum[looplength] = 0;
	}

}
// Task 8 Helper funtions 
void Reverse(int *values, int numValues)
{
	// switches the order of an array by a number of values

	int i = 0;
	while (i < numValues / 2) {
		Swap(values, i, numValues - 1 - i);
		i++;
	}
}
void Swap(int *values, int i, int j)
{
	// essentially justs switches 2 elements in the array

	int temp = values[i];
	values[i] = values[j];
	values[j] = temp;
}



// Your comment must go here
int MostPopular(char wordList[MAX_ARRAY_SIZE][MAX_WORD_SIZE], int numWords, char *result)
{
	return 0;
}

// Your comment must go here
double WeightDifference(double *passengers, int numPassengers)
{
	return 0.0;
}


