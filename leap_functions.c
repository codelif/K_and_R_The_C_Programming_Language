#include <stdio.h>
static char daytab[2][13]= {
  {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
  {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};


int day_of_year(int year, int month, int day){
  int leap = year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);

  if (month > 12 || month < 1){
    printf("error: months should be between 1 and 12 (inclusive)\n");
    return -1;
  }else if (day < 1 || day > daytab[leap][month]){
    printf("error: days for month %d and year %d should be between 1 and %d (inclusive)\n", month, year, daytab[leap][month]);
    return -1;
  }


  for (int i = 1; i < month; i++){
    day += daytab[leap][i];
  }

  return day;
}


void month_day(int year, int yearday, int *pmonth, int *pday){
  int leap = year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
  
  if (yearday < 1 || yearday > (365 + leap)){
    printf("error: yeardays for year %d should be between 1 and %d (inclusive)\n", year, (365 + leap));
    return;
  }


  for (*pmonth = 1; yearday > daytab[leap][*pmonth]; (*pmonth)++){
    yearday -= daytab[leap][*pmonth];
  }
  *pday = yearday;
}

int main(){
  int a, b;
  day_of_year(1232, 15, 32);
  day_of_year(1995, 2, 30);
  day_of_year(2000, 2, 52);
  month_day(2004, 3123, &a, &b);
  month_day(2005, 3123, &a, &b);

}




