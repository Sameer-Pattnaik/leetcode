class Solution {
public:

    int day_of_week(int y, int m, int d)
    {
        static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
        y -= m < 3;
        return (y + y/4 - y/100 + y/400 + t[m-1] + d) % 7;
    }
    string dayOfTheWeek(int day, int month, int year) {
        int sum=0;
        vector<string> str = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        sum = day_of_week(year, month, day);
        return str[sum];
    }
};