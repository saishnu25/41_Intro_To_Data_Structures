/**
 *
 *  CSCI 41 - Intro to Data Structures (Lab 3)
 *  Done By: Saishnu Ramesh Kumar (300758706)
 *  
 */

#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include <vector>

using namespace std;

//Invitee Class
class Invitee{

    private:
        string email;

    public:
        //Constructor
        Invitee(string mail){
        
            if (verify_email(mail)){
                email = mail; //If email is valid
            }

            else{
                cout << "\nThis email: " << mail << " is invalid!\n"<<endl; //If email is invalid                 
            }
        }

    //Function to check if the email is valid
    bool verify_email(string email){

        //If the length of email is less than 3 or first letter is not a letter
        if (email.length() < 3 || !isalpha(email.at(0)))
        {
            return false;
        }

        int i = 1;

        //If remaining mail contains some characters that are not allowed
        while (email.at(i) != '@') 
        {
            if (!isalnum(email.at(i)))
            {
                return false; 
            }
            i++;
        }

        string last = email.substr(i);
        //If the email address @ is not equal to "@csufresno.edu"
        if (last.compare("@csufresno.edu") != 0)
        {
            return false;
        }
        return true; //Otherwise it will return true
    }

    //Setter function for mail
    void setEmail(string mail)
    {
        email = mail;
    }

    //Getter function for mail
    string getEmail()
    {
        return email;
    }

}; //End of Invitee Class

//Time Class
class Time{

    private:
        int hour;
        int minute;

    public:
        Time(){
    
        }

    //Constructor
    Time(int hr, int min){
        hour = hr;
        minute = min;
    }

    //Hour setter function
    void setHour(int hr){
        hour = hr;
    }

    //Hour getter function
    int getHour(){
        return hour;
    }

    //Minute setter function
    void setMinute(int min){
        minute = min;
    }

    //Minute getter function
    int getMinute(){
        return minute;
    }

}; //End of Time Class

//Date Class
class Date{

    private:
        int month;
        int day;
        int year;

    public:
        Date(){
    
        }

    //Constructor
    Date(int d, int m, int y){
        day = d;
        month = m;
        year = y;
    }

    //Day setter function
    void setDay(int d){
        day = d;
    }

    //Day getter function
    int getDay(){
        return day;
    }

    //Month setter function
    void setMonth(int m){
        month = m;
    }

    //Month getter function
    int getMonth(){
        return month;
    }

    //Year setter function
    void setYear(int y){
        year = y;
    }

    //Year getter function
    int getYear(){
        return year;
    }

}; //End of Date Class

//Event Class
class Event{

    private:
        string title;
        Date date;
        Time start;
        Time end;
        int duration;
        vector<Invitee> invitees;

    public:
        //Constructor
        Event(string t, Date d, Time st, int dur){
            
            title = t;
            date = d;
            start = st;
            end = endTime(st, dur);
            duration = dur;
        }

    //Function to set end time of a given event's start time and duration
    Time endTime(Time st, int dur){

        int minute = st.getMinute() + dur;
        //Retrieve end hour
        int hour = (st.getHour() + minute / 60) % 24;
        //Retrieve end minute
        minute = minute % 60;
        //End time object
        Time endT(hour, minute);
        return endT;
    }

    //Adding an invitee to invitees list
    void addInvitee(Invitee I){

        invitees.push_back(I);
    }

    //Prints an event information
    void print_event_info(){

        cout << "Course: " << getCourse() << endl;
        Date d = getDate();
        cout << "Date: " << d.getDay() << "/" << d.getMonth() << "/" << d.getYear() << endl;
        Time st = getStart();
        cout << "Start Time: " << st.getHour() << ":" << st.getMinute() << endl;
        Time en = getEnd();
        cout << "End Time: " << en.getHour() << ":" << en.getMinute() << endl;
        cout << "Duration: " << getDuration() << endl;
        cout << "Number of Invitees: " << invitees.size() << endl;
    }

    //Course setter function
    void setCourse(string t){
        title = t;
    }

    //Course getter function
    string getCourse(){
        return title;
    }

    //Date setter function
    void setDate(Date d){
        date = d;
    }

    //Date getter function
    Date getDate(){
        return date;
    }

    //Start time setter function
    void setStart(Time st){
        start = st;
    }

    //Start time getter function
    Time getStart(){
        return start;
    }

    //End time setter function
    void setEnd(Time endT){
        end = endT;
    }

    //End time getter function
    Time getEnd(){
        return end;
    }

    //Duration setter method
    void setDuration(int dur){
        duration = dur;
    }

    //Duration getter method
    int getDuration(){
        return duration;
    }

}; //End of Event Class

//Calendar Class
class Calendar{

    private:
        vector<Event> events;

    public:
        Calendar(){
        
        }

    //Constructor
    Calendar(vector<Event> events_vec){

        events = events_vec;
    }

    //Adding an event to the event list
    void addEvent(Event event){

        events.push_back(event);
    }

    //Deleting an event from the event list
    void dropEvent(string course){

        for (int i = 0; i < events.size(); i++){

            if (course.compare(events.at(i).getCourse()) == 0){

                cout << "Event " << events.at(i).getCourse() << " has been dropped!\n"<<endl;
                events.erase(events.begin() + i);
                return;
            }
        }

        cout << "No event has been found!\n"<< endl;
    }

    //Searches all events of a specific month and outputs the information
    void searchEvent(int month){

        cout << "The events for month " << month << " are: \n"
             << endl;
        for (int i = 0; i < events.size(); i++){
            if (events.at(i).getDate().getMonth() == month){
                events.at(i).print_event_info();
                cout << endl;
            }
        }
    }
}; //End of Calendar Class

//Main Function
int main()
{

    Calendar call;

    // Defining 4 events
    Event event1("ENGL 1 - English 1", Date(2, 4, 2021), Time(10, 30), 50);
    Event event2("CSCI 20 - C++ Programming", Date(25, 4, 2021), Time(1, 45), 75);
    Event event3("CSCI 71 - Python Programming", Date(10, 6, 2021), Time(12, 00), 50);
    Event event4("BUSI 45 - Microeconomics", Date(30, 11, 2021), Time(8, 00), 60);
    Event event5("MATH 60 - Calculus 2", Date(27, 4, 2021), Time(9, 00), 60);

    // Defining 4 Invitees
    Invitee student1("Alex123@csufresno.edu");
    Invitee student2("Joe27@csufresno.edu");
    Invitee student3("Emily_O@csufresno.edu");
    Invitee student4("Jade88@csufresno.edu");
    Invitee student5("5Peter@csufresno.edu");

    // Adding Invitees student1, student2, student3 to Event event1
    event1.addInvitee(student1);
    event1.addInvitee(student2);
    event1.addInvitee(student3);

    // Adding Invitees student1, student2, student3, student4, student5 to Event event2
    event2.addInvitee(student1);
    event2.addInvitee(student2);
    event2.addInvitee(student3);
    event2.addInvitee(student4);
    event2.addInvitee(student5);

    // Adding Invitees student3, student4 to Event event3
    event3.addInvitee(student3);
    event3.addInvitee(student4);

    // Adding Invitees student4 to Event event4
    event4.addInvitee(student4);

    //Adding Invitees student1, student2, student4, student5 to Event event5
    event5.addInvitee(student1);
    event5.addInvitee(student2);
    event5.addInvitee(student4);
    event5.addInvitee(student5);

    // Adding events event1, event2, event3, event4 to Calender
    call.addEvent(event1);
    call.addEvent(event2);
    call.addEvent(event3);
    call.addEvent(event4);
    call.addEvent(event5);

    // Search and print info of events in 4th month (April)
    call.searchEvent(4);

    // Delete an event event1
    call.dropEvent(event1.getCourse());
    call.dropEvent(event4.getCourse());

    // Search and print info of events in 4th month again after update
    int i = 1;

    if(i == 1){
    cout<<"** Notice: Events have been updated **\n "<<endl;
    call.searchEvent(4);
    }

    return 0;
} //End of Main Function