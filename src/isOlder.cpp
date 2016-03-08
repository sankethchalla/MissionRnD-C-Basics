/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/
#include<ctype.h>
bool check(char dob1[], char dob2[])
{
	for (int i = 6; i <= 9; i++)
	{
		if (isdigit(dob1[i]) && isdigit(dob2[i]))
		{
		}
		else
			return false;
	}
	return true;

}
int noOfDays(int m, int y)
{
	if (m == 2)
	{
		return (((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0)) ? 29 : 28;
	}
	else
	{
		if ((0<m) && (m <= 7))//January-July
			return (m % 2 == 1) ? 31 : 30;
		else//August-December
			return (m % 2 == 1) ? 30 : 31;
	}
}
int isOlder(char *dob1, char *dob2) {

	int d1 = dob1[1] - '0' + (10 * (dob1[0] - '0'));
	int d2 = dob2[1] - '0' + (10 * (dob2[0] - '0'));
	int m1 = dob1[4] - '0' + (10 * (dob1[3] - '0'));
	int m2 = dob2[4] - '0' + (10 * (dob2[3] - '0'));
	if (check(dob1, dob2))
	{
	}
	else
		return -1;
	int y1 = (dob1[9] - '0') + (10 * (dob1[8] - '0')) + (100 * (dob1[7] - '0')) + (1000 * (dob1[6] - '0'));
	int y2 = (dob2[9] - '0') + (10 * (dob2[8] - '0')) + (100 * (dob2[7] - '0')) + (1000 * (dob2[6] - '0'));
	if ((0<d1) && (d1 <= noOfDays(m1, y1)) && (0<d2) && (d2 <= noOfDays(m2, y2)) && (0<m1) && (m1 <= 12) && (0<m2) && (m2 <= 12))
		//Checks if the entered date is a valid one or not
	{
		if (d1 == d2&&m1 == m2&&y1 == y2)
			//If the dates entered are same
			return 0;
		else
			return (y1 <= y2) && (m1 <= m2) && (d1 <= d2) ? 1 : 2;
	}
	else
		return -1;

	return 0;
}
