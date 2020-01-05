//Vincent Perez
//CODE EMULATES MOVIE SCHEDULING


#include <iostream>
using namespace std;

enum Genre { ACTION, COMEDY, DRAMA, ROMANCE, THRILLER };

class Time 
{ 
public:
    int h;
    int m;
};

class Movie 
{ 
public: 
    string title;
    Genre genre;     // only one genre per movie
    int duration;    // in minutes
};

class TimeSlot
{ 
public: 
    Movie movie;     // what movie
    Time startTime;  // when it starts
};

//return number of minutes from 0:00 AM until time
int minutesSinceMidnight(Time time)
{
    //hours multiplied by 60 to give minutes plus the minutes
    int minutes = (time.h * 60) + time.m;
    return minutes;
}

//shows how many minutes separate the two moments
int minutesUntil(Time earlier, Time later)
{
    //turns earleir time into minutes
    int firstsm = minutesSinceMidnight(earlier);
    //turns later time into minutes
    int secondsm = minutesSinceMidnight(later);
    //subtracts them
    int minutesboth = secondsm - firstsm;
    return minutesboth;
}

//adds minutes to time given
Time addMinutes(Time time0, int min)
{
    Time newTime;
    //turns time given into minutes, and adds minutes
    //that are gonna be added
    int timemin = minutesSinceMidnight(time0) + min;
    //turns amount of total minutes into hours
    int timeh = timemin/60;
    //remainder turns into minutes
    int timem = timemin%60;
    //puts values into newtime
    newTime = {timeh,timem};
    //returns newtime
    return newTime;
}

//prints out the movie
void printMovie(Movie mv)
{
    string g;
    switch (mv.genre) {
        case ACTION   : g = "ACTION"; break;
        case COMEDY   : g = "COMEDY"; break;
        case DRAMA    : g = "DRAMA";  break;
        case ROMANCE  : g = "ROMANCE"; break;
        case THRILLER : g = "THRILLER"; break;
    }
    cout << mv.title << " " << g << " (" << mv.duration << " min)";
}

//to determine the ending time of a movie
Time TSEndingTime(TimeSlot ts)
{
    //adds movie duration to start time
    Time s = addMinutes(ts.startTime, ts.movie.duration);
    return s;
}

//prints out the movie, what time the movie starts, genre, and time it ends
void printTimeSlot(TimeSlot ts)
{
    Time endtime = TSEndingTime(ts);
    printMovie(ts.movie);
    cout<<" [starts at "<<ts.startTime.h<<":"<<ts.startTime.m<<", ends by "<<endtime.h<<":"<<endtime.m<<"]"<<endl;
}

TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie)
{
    TimeSlot next;
    Time newtime = TSEndingTime(ts);
    next = {nextMovie, newtime};
    return next;
}

bool timeOverlap(TimeSlot ts1, TimeSlot ts2)
{
    bool test;
    int mov1 = minutesSinceMidnight(ts1.startTime);
    int mov2 = minutesSinceMidnight(ts2.startTime);
    //if the movies time plus duration is greater than movie
    //2 time then it ends after movie 2 starts, overlap
    if (mov2>mov1)
        {
            if (mov1 + ts1.movie.duration > mov2)
            {
                test = true;
            }
            else
            {
                test = false;
            }
        }
    else
        {
            if (mov2 + ts2.movie.duration > mov1)
            {
                test = true;
            }
            else
            {
                test = false;
            }
        }
    return test;
}

int main()
{
    Movie movie1 = {"Back to the Future", COMEDY, 180};
    Movie movie2 = {"Black Panther", ACTION, 134};
    Movie movie3 = {"Joker", DRAMA, 63};
    Movie movie4 = {"Midsommar", DRAMA, 147};

    TimeSlot morning = {movie1, {10, 30}};  
    TimeSlot afternoon = {movie3, {8,30}};
    /*printTimeSlot(morning);
    printTimeSlot(daytime);
    printTimeSlot(evening);
    printTimeSlot(afternoon);
    printTimeSlot(idk);*/
    TimeSlot next = scheduleAfter(morning,movie4);
    bool ok = timeOverlap(morning,afternoon);
    if (ok == true)
        {
            cout<<"overlap"<<endl<<endl;
        }
    else
        {
            cout<<"no overlap"<<endl;
        }
        
}
