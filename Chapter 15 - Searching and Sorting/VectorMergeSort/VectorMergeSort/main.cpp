// VectorMergeSort.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>

using namespace std;

/**
Prints out the passed in Vector contents

Inputs:
vector values: the contents we wish to print

Returns:
None

Assumptions/Limitations:
None
*/

void printVector(vector<int> values) {
	cout << "the vector size is: " << values.size() << endl << '\t';
	for (int i = 0; i < values.size(); i++) {
		if (i == 0)
			cout << values[i];
		else
			cout << "," << values[i];
	}
	cout << endl << endl;
}
/**
Merge two sorted vectors and return one sorted vector (combining the two).

Inputs:
vector a: the first vector
vector b: the second vector

Returns:
vector c: a sorted vector combining the two inputs

Assumptions/Limitations:
The input vectors must be sorted prior to calling this routine.
*/
vector<int> merge_sorted(vector<int> a, vector<int> b){
	vector<int> mergedVectors;
	int aIndex=0, bIndex = 0;
	bool finished = false, aComplete = false, bComplete = false;
	//
	// while both vectors have data; i.e., we will exit loop if we have sequenced 
	// through one of the vectors.
	//
	while (!aComplete && !bComplete){
		//
		// compare the two vector entries offset by aIndex and bIndex
		// if aValue <= bValue then copy aValue to 'new vector'
		// otherwise copy bValue to 'new vector'
		//
		// NOTE: be sure to update indicies accordingly
		//
		if (a[aIndex] <= b[bIndex]){
			mergedVectors.push_back(a[aIndex]);
			aIndex++;
			if (aIndex >= a.size())
				aComplete = true;
		}
		else {
			mergedVectors.push_back(b[bIndex]);
			bIndex++;
			if (bIndex >= b.size())
				bComplete = true;
		}
	}
	//
	// when we exit loop, check to be sure we have copied ALL the 
	// elements of each vector
	//
	if (!aComplete) {
		for (int i = aIndex; i < a.size(); i++)
			mergedVectors.push_back(a[i]);
	}
	else {
		for (int i = bIndex; i < b.size(); i++)
			mergedVectors.push_back(b[i]);

	}
	return mergedVectors;
}

int main(int argc, char * argv[])
{
	const int MAXSIZE = 100;

	vector<int> valuesA, valuesB, valuesC;

	srand(time(0));
	//
	// set vectors to random values
	//
	for (int i = 0; i < MAXSIZE; i++) {
		valuesA.push_back(rand() % (MAXSIZE * 4 + 1));
		valuesB.push_back(rand() % (MAXSIZE * 4 + 1));
	}
	//
	// add a few extra values to b...
	//
	valuesB.push_back(2);
	valuesB.push_back(117);
	valuesB.push_back(50);
	cout << "the values in A BEFORE the sort are: " << endl;
	printVector(valuesA);
	cout << endl << endl << "the values in B BEFORE the sort are: " << endl;
	printVector(valuesB);
	//
	// sort the vectors
	//		sort is a built in function that is efficient
	//		you must include <algorithm>
	//
	sort(valuesA.begin(), valuesA.end());
	sort(valuesB.begin(), valuesB.end());
	cout << "the values in A After the sort are: " << endl;
	printVector(valuesA);
	cout << endl << endl << "the values in B After the sort are: " << endl;
	printVector(valuesB);
	//
	// merge the vectors into C - this creates a sorted list of integers of size ?
	//
	valuesC = merge_sorted(valuesA, valuesB);
	cout << endl << "the merged vectors are: " << endl;
	printVector(valuesC);

	return 0;
}

