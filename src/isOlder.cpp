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
#include<stdio.h>
int valid(char* dob)
{
	int val=0, day=0, mon=0, year=0;
	if ((*(dob + 0) <= '9') && (*(dob + 0) >= '0'))
	{
		int c = (int)*(dob + 0) * 10;
		day = day+(((int)(*(dob + 0))-48) * 10);
		if ((*(dob + 1) <= '9') && (*(dob + 1) >= '0')){
			day = day + ((int)(*(dob + 1))-48);
		}
	}
	if ((*(dob + 3) <= '9') && (*(dob + 3) >= '0'))
	{
		mon = mon+(((int)(*(dob + 3))-48) * 10);
		if ((*(dob + 4) <= '9') && (*(dob + 4) >= '0')){
			mon = mon +((int)(*(dob + 4))-48);
		}
		else{
			val = -1;
		}
	}
	if ((*(dob + 2) != '-') && (*(dob + 5) != '-')){
		val = -1;
	}
	if ((*(dob + 6) <= '9') && (*(dob + 6) >= '0')){
		year = year+(((int)(*(dob + 6))-48) * 1000);
		if ((*(dob + 7) <= '9') && (*(dob + 7) >= '0')){
			year = year + (((int)(*(dob + 7))-48) * 100);
			if ((*(dob + 8) <= '9') && (*(dob + 8) >= '0')){
				year = year + (((int)(*(dob + 8))-48) * 10);
				if ((*(dob + 9) <= '9') && (*(dob + 9) >= '0')){
					year = year + ((int)(*(dob + 9))-48);
				}
				else{
					val = -1;
				}
			}
			else{
				val = -1;
			}
		}
		else{
			val = -1;
		}
	}
	else{
		val = -1;
	}
	if (year % 4 == 0){
		if (mon == 2){
			if (day <= 29){
				val = 1;
			}
			else{
				val = -1;
			}
		}
		else{
			if (mon > 12){
				val = -1;
			}
			else{
				if (day > 31){
					val = -1;
				}
			}
		}
	}
	else
	{
		if (year > 0){
			if (mon < 12){
				if (mon == 2){
					if (day <= 28){
						val = 1;
					}
					else{
						val = -1;
					}
				}
			}
			else{
				val = -1;
			}
		}
		else{
			val = -1;
		}
	}
	return val;
}


int isOlder(char *dob1, char *dob2) {
	int res=0,i=0,temp=0,val1,val2;
	val1 = valid(dob1);
	val2 = valid(dob2);
	if ((val1 == -1) || (val2 == -1)){
		res = -1;
	}
	else
	{
		if (*(dob1 + 6) == *(dob2 + 6)){
			if (*(dob1 + 7) == *(dob2 + 7)){
				if (*(dob1 + 8) == *(dob2 + 8)){
					if (*(dob1 + 9) == *(dob2 + 9)){
						if (*(dob1 + 3) == *(dob2 + 3)){
							if (*(dob1 + 4) == *(dob2 + 4)){
								if (*(dob1 + 0) == *(dob2 + 0)){
									if (*(dob1 + 1) == *(dob2 + 1)){
										res = 0;
									}
									else{
										if (*(dob1 + 1) > *(dob2 + 1)){
											res = 2;
										}
										else{
											res = 1;
										}
									}
								}
								else{
									if (*(dob1 + 0) > *(dob2 + 0)){
										res = 2;
									}
									else{
										res = 1;
									}
								}
							}
							else{
								if (*(dob1 + 4) > *(dob2 + 4)){
									res = 2;
								}
								else{
									res = 1;
								}
							}
						}
						else{
							if (*(dob1 + 3) > *(dob2 + 3)){
								res = 2;
							}
							else{
								res = 1;
							}
						}
					}
					else{
						if (*(dob1 + 9) > *(dob2 + 9)){
							res = 2;
						}
						else{
							res = 1;
						}
					}
				}
				else{
					if (*(dob1 + 8) > *(dob2 + 8)){
						res = 2;
					}
					else{
						res = 1;
					}
				}
			}
			else{
				if (*(dob1 + 7) > *(dob2 + 7)){
					res = 2;
				}
				else{
					res = 1;
				}
			}
		}
		else{
			if (*(dob1 + 6) > *(dob2 + 6)){
				res = 2;
			}
			else{
				res = 1;
			}
		}
	}
	return res;
}
