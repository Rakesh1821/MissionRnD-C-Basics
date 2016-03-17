/*
 if OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/

int isOlder(char *dob1, char *dob2) {
	char d1[5],d2[5], m1[5], m2[5], y1[5], y2[5];
	int i, j, k, p = 0, l1 = 0, l2 = 0, dt1, dt2, mon1, mon2, yr1, yr2;

	for (i = 0; dob1[i] != '\0'; i++)
		l1++;

	for (i = 0; dob2[i] != '\0'; i++)
		l2++;

	if (l1 != 10 || l2 != 10)
		return -1;

	for (i = 0; dob1[i] != '-'; i++)
	{
		d1[i] = dob1[i];
		d2[i] = dob2[i];
	}
	d1[i] = '\0';
	d2[i] = '\0';
	dt1 = (10 * (d1[0] - 48)) + (d1[1] - 48);
	dt2 = (10 * (d2[0] - 48)) + (d2[1] - 48);
	i++;
	for (j = i; dob1[j] != '-'; j++)
	{
		m1[p] = dob1[j];
		m2[p] = dob2[j];
		p++;
	}
	m1[p] = '\0';
	m2[p] = '\0';
	mon1 = (10 * (m1[0] - 48)) + (m1[1] - 48);
	mon2 = (10 * (m2[0] - 48)) + (m2[1] - 48);
	j++;
	p = 0;
	for (k = j; k<l1; k++)
	{
		y1[p] = dob1[k];
		y2[p] = dob2[k];
		p++;
	}
	y1[p] = '\0';
	y2[p] = '\0';
	yr1 = (1000 * (y1[0] - 48)) + (100 * (y1[1] - 48)) + (10 * (y1[2] - 48)) + (y1[3] - 48);
	yr2 = (1000 * (y2[0] - 48)) + (100 * (y2[1] - 48)) + (10 * (y2[2] - 48)) + (y2[3] - 48);

	if (((yr1 % 4 != 0) && (mon1 == 2) && (dt1 > 28)) || ((yr2 % 4 != 0) && (mon2 == 2) && (dt2 > 28)))
		return -1;
	if (dt1>31 || dt2>31 || mon1>12 || mon2>12 || (mon1 == 2 && dt1>29) || (mon2 == 2 && dt2>29))
		return -1;



	if (yr1 > yr2)
		return 2;
	else if (yr1 < yr2)
		return 1;
	else if (yr1 == yr2)
	{
		if (mon1>mon2)
			return 2;
		else if (mon1 < mon2)
			return 1;
		else if (mon1 == mon2)
		{
			if (dt1>dt2)
				return 2;
			else if (dt1 < dt2)
				return 1;
			else if (dt1 == dt2)
				return 0;
			else
				return -1;
		}
		else
			return -1;
	}
	else
		return -1;
}




