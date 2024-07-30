#include "IsValidFormat.h"

bool isValidTime(String^ str_time)
{
	Regex^ timeRE = gcnew Regex("(0?\\d|1\\d|2[0-3])([:.,\\-]|\\s+)(0\\d|[1-5]\\d)");;
	return timeRE->IsMatch(str_time);
}

bool isValidSP()
{
	//TODO
	return false;
}
