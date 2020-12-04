#include <bits/stdc++.h>
using namespace std;

#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define endl "\n"
#define ll long long
#define pii pair<int, int>
#define all(x) begin(x), end(x)
#define loop(i, n) for (int i = 0; i < n; i++)
#define rep(i, a, b, c) for (int i = a; i < b; i += c)
#define brep(i, a, b, c) for (int i = a; i > b; i -= c)
#define tc(t) \
    int t;    \
    cin >> t; \
    while (t--)
#define sz(v) int((v).size())
#define pb push_back

int DaysInMonth(int month, int year)
{
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
    {
        return 31;
    }
    if (month == 2)
    {
        if (year % 4 == 0)
        {
            return 29;
        }
        return 28;
    }
    return 30;
}



int diffLessThanEqualToOne(int year1, int month1, int day1, int year2, int month2, int day2)
{
    int days = 0;
    if (month2 <= month1)
    {
        for (int month = month1; month <= 12; month++)
        {
            days += DaysInMonth(month, year1);
        }
        days -= (DaysInMonth(month1, year1) - day1);
        int month = 1;
        while (month != month2)
        {
            days += DaysInMonth(month, year2);
            month++;
        }
        days += day2 - 1;
    }

    else
    {
        int month = month1;
        while (month != month2)
        {
            days += DaysInMonth(month, year1);
            month++;
        }
        days -= (DaysInMonth(month1, year1) - day1);
        days += day2 - 1;
    }
    return days;
}

int DayInBetween(int year1, int month1, int day1, int year2, int month2, int day2)
{
    int days = 0;

    if (year2 - year1 <= 1)
    {
        return diffLessThanEqualToOne(year1, month1, day1, year2, month2, day2);
        // case1 when month2 is less than month1. Get month1 till end of year and then add the rest till month1
    }
    else
    {
        for (int yr = year1; yr < year2; yr++)
        {
            days += (yr % 4 == 0 ? 366 : 365);
        }
        days += diffLessThanEqualToOne(year2 - 1, month1, day1, year2, month2, day2);
    }
    return days;
}

int main()
{
    cout << DayInBetween(2018, 5, 16, 2022, 7, 5) << endl;
    return 0;
}
