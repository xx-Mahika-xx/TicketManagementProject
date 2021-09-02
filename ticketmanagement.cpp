// HEADER FILES USED IN THE PROGRAM

#include <iostream>
#include<fstream>
#include<string.h>
#include<stdio.h>
#include<conio.h>
#include<iomanip>
#include<process.h>
#include<windows.h>

using namespace std;

COORD coord={0,0};
void gotoxy(int x,int y)
{
 coord.X=x;
 coord.Y=y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

// FUNCTIONS USED IN THE PROGRAM


void Add_Concerts();
void Display_All_Concerts();
void Display_particular_Concert();
void Modify_Concert_Details();
void Remove_Concert();
void Book_Concert_Ticket();


void intro();
void Admin_Menu_Concert();
void Admin_Menu();
int search_id(char n[]);
void User_Menu();

void Book_Sport_Ticket();
void Main_Menu();
void Admin_Menu_Sport();
void Admin_Menu_Movie();

void Book_Movie_Ticket();

// FILE OBJECTS

fstream fic,fib,ficesp,fis,ficsp;

// CLASS CONCERT

class CONCERTS
{
    char name_of_concert[100],
    venue[100],
    starting_time[10],
    concert_id[50];
    
    float concert_duration;
    
    float ticket_fee_gold,
             ticket_fee_silver,
             ticket_fee_regular;
    
    int  no_of_seats_gold_booked,
           no_of_seats_silver_booked,
           no_of_seats_regular_booked,
           total_no_of_seats_gold,
           total_no_of_seats_silver,
           total_no_of_seats_regular;
    
public:
    
    
    CONCERTS()
    {
        strcpy(concert_id,"NULL");
        strcpy(name_of_concert,"NULL");
        strcpy(venue,"NULL");
        strcpy(starting_time,"NULL");
        concert_duration=0;
        ticket_fee_gold=0;
        ticket_fee_silver=0;
        ticket_fee_regular=0;
        no_of_seats_gold_booked=0;
        no_of_seats_silver_booked=0;
        no_of_seats_regular_booked=0;
        total_no_of_seats_gold=0;
        total_no_of_seats_silver=0;
        total_no_of_seats_regular=0;
    }
    
    void getevent()
    {   cout<<"\n\n\n\n\n\n";
        cout<<"\tEnter the Concert Id\t\t\t\t:";
        gets(concert_id);
        cout<<"\tEnter the Name of the Concert\t\t\t:";
        gets(name_of_concert);
        cout<<"\tEnter the Venue\t\t\t\t\t:";
        gets(venue);
        cout<<"\tEnter the time of concert\t\t\t:";
        gets(starting_time);
        cout<<"\tEnter the total number of gold seats\t\t:";
        cin>>total_no_of_seats_gold;
        cout<<"\tEnter the total number of silver seats\t\t:";
        cin>>total_no_of_seats_silver;
        cout<<"\tEnter the total number of regular seats\t\t:";
        cin>>total_no_of_seats_regular;
        cout<<"\tEnter the number of gold seats booked\t\t:";
        cin>>no_of_seats_gold_booked;
        cout<<"\tEnter the number of silver seats booked\t\t:";
        cin>>no_of_seats_silver_booked;
        cout<<"\tEnter the number of regular seats booked\t:";
        cin>>no_of_seats_regular_booked;
        cout<<"\tEnter the cost of gold ticket seat\t\t:";
        cin>>ticket_fee_gold;
        cout<<"\tEnter the cost of silver ticket seat\t\t:";
        cin>>ticket_fee_silver;
        cout<<"\tEnter the cost of regular ticket seat\t\t:";
        cin>>ticket_fee_regular;
    }
    
    void putevent()
    {
        
        
        cout  <<"\n\t\tConcert Id\t\t\t:"            <<concert_id
              <<"\n\t\tConcert Name\t\t\t:"        <<name_of_concert
              <<"\n\t\tVenue\t\t\t\t:"            <<venue
              <<"\n\t\tTime of concert\t\t\t:"        <<starting_time
              <<"\n\t\tTotal number of gold seats\t:"    <<total_no_of_seats_gold
              <<"\n\t\tTotal number of silver seats\t:"    <<total_no_of_seats_silver
              <<"\n\t\tTotal number of regular seats\t:"    <<total_no_of_seats_regular
              <<"\n\t\tNumber of gold seats booked\t:"    <<no_of_seats_gold_booked
              <<"\n\t\tNumber of silver seats booked\t:"    <<no_of_seats_silver_booked
              <<"\n\t\tNumber of regular seats booked\t:"   <<no_of_seats_regular_booked
              <<"\n\t\tCost of gold ticket seat\t:"        <<ticket_fee_gold
              <<"\n\t\tCost of silver ticket seat\t:"        <<ticket_fee_silver
              <<"\n\t\tCost of regular ticket seat\t:"    <<ticket_fee_regular
        <<endl;
    }
    
    char *return_name()
    {
        return name_of_concert;
    }
    
    char *return_id()
    {
        return concert_id;
    }
    
    float return_ticket_fee_gold()
    {
        return ticket_fee_gold;
    }
    
    void modify_no_of_seats_gold_booked(int g)
    {
        no_of_seats_gold_booked = no_of_seats_gold_booked + g;
    }
    
    void modify_no_of_seats_silver_booked(int s)
    {
        no_of_seats_silver_booked = no_of_seats_silver_booked + s;
    }
    
    void modify_no_of_seats_regular_booked(int r)
    {
        no_of_seats_regular_booked = no_of_seats_regular_booked + r;
    }
    
    float return_ticket_fee_silver()
    {
        return ticket_fee_silver;
    }
    
    float return_ticket_fee_regular()
    {
        return ticket_fee_regular;
    }
    
    int return_no_of_seats_gold_booked()
    {
        return no_of_seats_gold_booked;
    }
    
    int return_no_of_seats_silver_booked()
    {
        return no_of_seats_silver_booked;
    }
    
    int return_no_of_seats_regular_booked()
    {
        return no_of_seats_regular_booked;
    }
    
    float return_total_no_of_seats_gold()
    {
        return total_no_of_seats_gold;
    }
    
    int return_total_no_of_seats_silver()
    {
        return total_no_of_seats_silver;
    }
    
    int return_total_no_of_seats_regular()
    {
        return total_no_of_seats_regular;
    }
    
    void display_id()
    {
        cout<<"\tConcert Id\t\t\t:"<<concert_id;
    }
    
    void get_id()
    {
        cout<<"\tConcert Id\t\t\t:";
        gets(concert_id);
    }
    
    void display_name()
    {
        cout<<"\tConcert Name\t\t\t\t:"<<name_of_concert;
    }
    
    void get_name()
    {
        cout<<"\tEnter the Name of the Concert\t\t:";
        gets(name_of_concert);
    }
    
    void display_venue()
    {
        cout<<"\tVenue\t\t\t\t:"<<venue;
    }
    
    void get_venue()
    {
        cout<<"\tVenue\t\t\t\t\t\t:";
        gets(venue);
    }
    
    void display_starting_time()
    {
        cout<<"\tTime of concert\t\t\t:"    <<starting_time;
    }
    
    void get_starting_time()
    {
        cout<<"\tTime of concert\t\t\t\t\t:";
        cin>>starting_time;
    }
    
    
    void display_ticket_fee_gold()
    {
        cout<<"\tCost of gold ticket seat\t:"<<ticket_fee_gold;
    }
    
    void get_ticket_fee_gold()
    {
        cout<<"\tCost of gold ticket seat\t\t:";
        cin>>ticket_fee_gold;
    }
    
    void display_ticket_fee_silver()
    {
        cout<<"\tCost of silver ticket seat\t:"<<ticket_fee_silver;
    }
    
    void get_ticket_fee_silver()
    {
        cout<<"\tCost of silver ticket seat\t\t:";
        cin>>ticket_fee_silver;
    }
    
    void display_ticket_fee_regular()
    {
        cout<<"\tCost of regular ticket seat\t:"<<ticket_fee_regular;
    }
    
    void get_ticket_fee_regular()
    {
        cout<<"\tCost of regular ticket seat\t\t:";
        cin>>ticket_fee_regular;
    }
    
    void get_no_of_seats_regular_booked()
    {
        cout<<"\tEnter the number of regular seats booked\t:";
        cin>>no_of_seats_regular_booked;
    }
    
    void get_no_of_seats_silver_booked()
    {
        cout<<"\tEnter the number of silver seats booked\t\t:";
        cin>>no_of_seats_silver_booked;
    }
    
    void get_no_of_seats_gold_booked()
    {
        cout<<"\tEnter the number of gold seats booked\t\t:";
        cin>>no_of_seats_gold_booked;
    }
    
    void get_total_no_of_seats_regular()
    {
        cout<<"\tEnter total number of regular seats\t\t:";
        cin>>total_no_of_seats_regular;
    }
    
    void get_total_no_of_seats_silver()
    {
        cout<<"\tEnter the total number of silver seats\t\t:";
        cin>>total_no_of_seats_silver;
    }
    
    void get_total_no_of_seats_gold()
    {
        cout<<"\tEnter the total number of gold seats\t\t:";
        cin>>total_no_of_seats_gold;
    }
    
    
    
}concert;

// FUNCTION TO ADD MORE CONCERTS TO THE FILE

void Add_Concerts()
{
    char o;
    system("cls");
    fic.open("concertbinary.dat",ios::app| ios::binary);
    do
    {
        system("cls");
        concert.getevent();
        fic.write((char*)&concert, sizeof(concert));
        cout<<"\n\n\n\n\n\t\t\t\t\t\tPress Any Key To Continue....";
        getch();
        system("cls");
        cout <<"\n\n\n\n\n\n\n\n\n"
        <<"\t\t**********************************************"
        <<"\n\t\t\t\t Record"
        <<" \n\t\t\t\t  Added "
        <<"\n\t\t\t\t Succesfully"
        <<"\n\t\t**********************************************"
        <<"\n\n\n\n\n\n\t\t\t\t\t\tPress Any Key To Continue....";
        getch();
        system("cls");
        cout     <<"\n\n\n\n\n\n\n\n\t\tDo you want to add any more records?(Y/N)";
        cin>>o;
    }while (o=='Y'||o=='y');
    fic.close();
}



// FUNCTION TO DISPLAY ALL THE CONCERTS IN THE FILE

void Display_All_Concerts()
{
    system("cls");
    int a=1;
    fic.open("concertbinary.dat",ios::in| ios::binary);
    while(fic.read((char*)&concert, sizeof(concert)))
    {
        if(strcmp(concert.return_name(),NULL)!=0)
        {
            cout<<"\n\n\n\n\n\t\t\t\tConcert  "<<a<<"\n\n";
            concert.putevent();
            a++;
        }
        
        cout<<"\n\n\n\n\n\t\t\t\t\t\tPress Any Key To Continue....";
        getch();
        system("cls");
        
    }
    fic.close();
}



// FUNCTION TO DISPLAY A PARTICULAR CONCERT FROM THE FILE

void Display_Particular_Concert()
{
    system("cls");
    char n[100],found='n';
    cout<<endl<<"\n\n\nEnter Name or the ID that should be Displayed:";
    gets(n);
    fic.open("concertbinary.dat",ios::in| ios::binary);
    while( fic.read((char*)&concert, sizeof(concert)))
    {
        if(strcmpi(n,concert.return_name())==0||strcmpi(n,concert.return_id())==0)
        {
            cout<<"\n\n";
            concert.putevent();
            found='y';
            break;
        }
    }
    if(found=='n')
        cout<<"Record not found";
    fic.close();
    getch();
}

// FUNCTION TO MODIFY A PARTICULAR CONCERT FROM THE FILE


void Modify_Concert_Details()
{
    char n[100],found,o,opt[10];
    int p,q,r;
    do
    {
        found='n';
        system("cls");
        cout<<"\n\n\n\n\n\nEnter Name or The Concert Id of the Concert whose details must be modified\n";
        gets(n);
        fic.open("concertbinary.dat",ios::in| ios::out|ios::binary);
        if(!fic)
        {
            cout<<"File not Found";
        }
        else
        {
            system("cls");
            while(fic.read((char*)&concert, sizeof(concert)))
            {
                if(strcmp(n,concert.return_name())==0||strcmp(n,concert.return_id())==0)
                {
                    fic.seekg(0,ios::cur);
                    cout    <<"\n\n\n\t\t\t**** Modifications Menu ****"
                    <<"\n\n\t\t|=======|=======================================|"
                    <<"\n\t\t|OPTION\t|\t\tMENU\t\t\t|"
                    <<"\n\t\t|=======|=======================================|"
                    <<"\n\t\t|   1   |\tName Of Concert\t\t\t|"
                    <<"\n\t\t|   2   |\tVenue\t\t\t\t|"
                    <<"\n\t\t|   3   |\tStarting Time\t\t\t|"
                    <<"\n\t\t|   4   |\tTotal No . of Gold Seats\t|"
                    <<"\n\t\t|   5   |\tTotal No . of Silver Seats\t|"
                    <<"\n\t\t|   6   |\tTotal No . of Regular Seats\t|"
                    <<"\n\t\t|   7   |\tNo . of Gold Seats Booked\t|"
                    <<"\n\t\t|   8   |\tNo . of Regular Seats Booked\t|"
                    <<"\n\t\t|   9   |\tNo . of Regular Seats Booked\t|"
                    <<"\n\t\t|   10  |\tCost of Gold Seats\t\t|"
                    <<"\n\t\t|   11  |\tCost of Silver Seats\t\t|"
                    <<"\n\t\t|   12  |\tCost of Regular Seats\t\t|"
                    <<"\n\t\t|   13  |\tEntire Record\t\t\t|"
                    <<"\n\t\t|   14  |\tGo to Previous Menu\t\t|"
                    <<"\n\t\t|   15  |\tExit from program\t\t|"
                    <<"\n\t\t|=======|=======================================|"
                    <<"\n\nEnter your Option : \t";
                    cin>>opt;
                    strcat(opt,",");
                    system("cls");
                    
                    cout<<"\n\n\n\t\t\t**** The Name And Id Of Concert:****"<<endl;
                    cout<<"\t";
                    concert.display_id();
                    cout<<endl;
                    cout<<"\t";
                    concert.display_name();
                    
                    cout<<"\n\n\t\t\t**** Enter Modifications ****"<<endl;
                    
                    for(int i=0; opt[i]!='\0'; i++)
                    {
                        if(opt[i+1]!=','  &&   ( strlen(opt)>1)   &&   opt[i]!=',')
                        {
                            if(opt[i]=='1'   &&  opt[i+1]=='0')
                                concert.get_ticket_fee_gold();
                            
                            else if(opt[i]=='1'   &&  opt[i+1]=='1')
                                concert.get_ticket_fee_silver();
                            
                            else if(opt[i]=='1'   &&  opt[i+1]=='2')
                                concert.get_ticket_fee_regular();
                            
                            else if(opt[i]=='1'   &&  opt[i+1]=='3')
                                concert.getevent();
                            
                            else if(opt[i]=='1'  &&  opt[i+1]=='4')
                                Main_Menu();
                            
                            else if(opt[i]=='1'  &&  opt[i+1]=='5')
                                exit(0);
                            i++;
                        }
                        
                        
                        else
                        {
                            switch(opt[i])
                            {
                                case '1':
                                    concert.get_name();
                                    break;
                                case '2':
                                    concert.get_venue();
                                    break;
                                case '3':
                                    concert.get_starting_time();
                                    break;
                                case '4':
                                    concert.get_total_no_of_seats_gold();
                                    break;
                                case '5':
                                    concert.get_total_no_of_seats_silver();
                                    break;
                                case '6':
                                    concert.get_total_no_of_seats_regular();
                                    break;
                                case '7':
                                    concert.get_no_of_seats_gold_booked();
                                    break;
                                case '8':
                                    concert.get_no_of_seats_silver_booked();
                                    break;
                                case '9':
                                    concert.get_no_of_seats_regular_booked();
                                    break;
                                    
                                case ',':
                                    break;
                                default:
                                    cout<<"Kindly Enter a valid option from \'1-11\'";
                                    
                            }
                        }
                    }
                    p=fic.tellg();
                    q=sizeof(concert);
                    r=p-q;
                    fic.seekp(r);
                    fic.write((char*)&concert, sizeof(concert));
                    found='y';
                    break;
                }
            }
            if(found=='y')
            {
                system("cls");
                cout<<"\n\n\n\n\t\t**** Concert Details After Modifications ****"<<endl;
                concert.putevent();
            }
            else
                cout<<"\n\n\n\n\t\t**********No such Concert exists *********";
            
            
        }
        fic.close();
        cout<<"\n\n\n\n\n\t\t\t\t\t\tPress Any Key To Continue....";
        getch();
        system("cls");
        cout<<"\n\n\nDo You Want to Modify more Concerts from the File?\t";
        cin>>o;
        
    }while(o=='y'||o=='Y');
}

// FUNCTION TO REMOVE A PARTICULAR CONCERT FROM THE FILE

void Remove_Concert()
{
    char name[100],found='n',o;
    do
    {
        found='n';
        system("cls");
        cout<<"\n\n\n\n\n\n\nEnter Name or the Concert Id of the band that should be Removed from the File\n\n :";
        gets(name);
        ofstream temp;
        temp.open("new.dat",ios::out|ios::binary);
        fic.open("concertbinary.dat",ios::in| ios::binary);
        
        while(fic.read((char*)&concert,sizeof(concert)))
        {
            if((strcmp(name,concert.return_name())==0) || (strcmpi(name,concert.return_id())==0))
            {
                system("cls");
                cout<<"\n\n\n\n\t\t********  Concert Removed From File  *******";
                found='y';
            }
            else
                temp.write((char*)&concert, sizeof(concert));
        }
        
        if(found=='n')
            cout<<"\n\n\n\n\t\t**********No such Concert exists in the File **********";
        temp.close();
        fic.close();
        remove("concertbinary.dat");
        rename("new.dat", "concertbinary.dat");
        cout<<"\n\n\nDo You Want to Remove more Concerts from the File?\t";
        cin>>o;
    }while(o=='y'||o=='Y');
}


//CLASS SPORT

class SPORTS
{
    char  type_of_sport[50],
          name_of_team1[50],
          name_of_team2[50],
          time_of_match[20],
          venue[100],
          match_id[50],
          match_name[100],
          series_name[100];
    
    float ticket_fee_gold,
          ticket_fee_silver,
          ticket_fee_regular;
    
public:
    int  no_of_seats_gold_booked,
         no_of_seats_silver_booked,
         no_of_seats_regular_booked,
         total_no_of_seats_gold,
         total_no_of_seats_silver,
         total_no_of_seats_regular;
    
    SPORTS()
    {
        strcpy(match_id,"NULL");
        strcpy(type_of_sport,"NULL");
        strcpy(name_of_team1,"NULL");
        strcpy(name_of_team2,"NULL");
        strcpy(venue,"NULL");
        strcpy(time_of_match,"NULL");
        strcpy(match_name,"NULL");
        strcpy(series_name,"NULL");
        ticket_fee_gold=0;
        ticket_fee_silver=0;
        ticket_fee_regular=0;
        no_of_seats_gold_booked=0;
        no_of_seats_silver_booked=0;
        no_of_seats_regular_booked=0;
        total_no_of_seats_gold=0;
        total_no_of_seats_silver=0;
        total_no_of_seats_regular=0;
    }
    
    void getevent()
    {   cout<<"\n\n\n\n";
        cout<<" Enter type of sport\t\t\t\t\t:";
        gets(type_of_sport);
        cout<<" Enter the Match Id\t\t\t\t\t:";
        gets(match_id);
        cout<<" Enter Name of Series\t\t\t\t\t:";
        gets(series_name);
        cout<<" Enter Name of Match (Quarter-final,Semi-final,Finals)\t:";
        gets(match_name);
        cout<<" Enter the Name of the Team I\t\t\t\t:";
        gets(name_of_team1);
        cout<<" Enter the Name of the Team II\t\t\t\t:";
        gets(name_of_team2);
        cout<<" Enter the Venue\t\t\t\t\t:";
        gets(venue);
        cout<<" Enter the time of match\t\t\t\t:";
        gets(time_of_match);
        cout<<" Enter the total number of gold seats\t\t\t:";
        cin>>total_no_of_seats_gold;
        cout<<" Enter the total number of silver seats\t\t\t:";
        cin>>total_no_of_seats_silver;
        cout<<" Enter the total number of regular seats\t\t:";
        cin>>total_no_of_seats_regular;
        cout<<" Enter the number of gold seats booked\t\t\t:";
        cin>>no_of_seats_gold_booked;
        cout<<" Enter the number of silver seats booked\t\t:";
        cin>>no_of_seats_silver_booked;
        cout<<" Enter the number of regular seats booked\t\t:";
        cin>>no_of_seats_regular_booked;
        cout<<" Enter the cost of gold ticket seat\t\t\t:";
        cin>>ticket_fee_gold;
        cout<<" Enter the cost of silver ticket seat\t\t\t:";
        cin>>ticket_fee_silver;
        cout<<" Enter the cost of regular ticket seat\t\t\t:";
        cin>>ticket_fee_regular;
    }
    
    void putevent()
    {
        
   cout <<"\n\t\tSport\t\t\t\t:"                <<type_of_sport
        <<"\n\t\tMatch Id\t\t\t:"                <<match_id
        <<"\n\t\tSeries Name\t\t\t:"            <<series_name
        <<"\n\t\tMatch Name\t\t\t:"            <<match_name
        <<"\n\t\tTeam I Name\t\t\t:"            <<name_of_team1
        <<"\n\t\tTeam II Name\t\t\t:"            <<name_of_team2
        <<"\n\t\tVenue\t\t\t\t:"                <<venue
        <<"\n\t\tTime of match\t\t\t:"            <<time_of_match
        <<"\n\t\tTotal number of gold seats\t:"        <<total_no_of_seats_gold
        <<"\n\t\tTotal number of silver seats\t:"        <<total_no_of_seats_silver
        <<"\n\t\tTotal number of regular seats\t:"        <<total_no_of_seats_regular
        <<"\n\t\tNumber of gold seats booked\t:"        <<no_of_seats_gold_booked
        <<"\n\t\tNumber of silver seats booked\t:"        <<no_of_seats_silver_booked
        <<"\n\t\tNumber of regular seats booked\t:"        <<no_of_seats_regular_booked
        <<"\n\t\tCost of gold ticket seat\t:"            <<ticket_fee_gold
        <<"\n\t\tCost of silver ticket seat\t:"            <<ticket_fee_silver
        <<"\n\t\tCost of regular ticket seat\t:"        <<ticket_fee_regular
        <<endl;
    }
    
    char *return_match_name()
    {
        return match_name;
    }
    char *return_type_of_sport()
    {
        return type_of_sport;
    }
    char *return_series_name()
    {
        return series_name;
    }
    char *return_id()
    {
        return match_id;
    }
    
    float return_ticket_fee_gold()
    {
        return ticket_fee_gold;
    }
    
    void modify_no_of_seats_gold_booked(int g)
    {
        no_of_seats_gold_booked=no_of_seats_gold_booked+g;
    }
    
    void modify_no_of_seats_silver_booked(int s)
    {
        no_of_seats_silver_booked=no_of_seats_silver_booked+s;
    }
    
    void modify_no_of_seats_regular_booked(int r)
    {
        no_of_seats_regular_booked=no_of_seats_regular_booked+r;
    }
    
    float return_ticket_fee_silver()
    {
        return ticket_fee_silver;
    }
    
    float return_ticket_fee_regular()
    {
        return ticket_fee_regular;
    }
    
    int return_no_of_seats_gold_booked()
    {
        return no_of_seats_gold_booked;
    }
    
    int return_no_of_seats_silver_booked()
    {
        return no_of_seats_silver_booked;
    }
    
    int return_no_of_seats_regular_booked()
    {
        return no_of_seats_regular_booked;
    }
    
    float return_total_no_of_seats_gold()
    {
        return total_no_of_seats_gold;
    }
    
    int return_total_no_of_seats_silver()
    {
        return total_no_of_seats_silver;
    }
    
    int return_total_no_of_seats_regular()
    {
        return total_no_of_seats_regular;
    }
    void display_id()
    {
        cout<<"\n\t\tMatch Id\t\t\t:"<<match_id;
    }
    
    void get_id()
    {
        cout<<"\n\t\tMatch Id\t\t\t:";
        gets(match_id);
    }
    
    void display_type_of_sport()
    {
        cout<<"\n\t\tSport\t\t\t\t:"<<type_of_sport;
    }
    
    void get_type_of_sport()
    {
        cout<<"\tEnter the Type of Sport\t\t\t:";
        gets(type_of_sport);
    }
    
    void display_series_name()
    {
        cout<<"\n\t\tSeries Name\t\t\t:"        <<series_name;
    }
    
    void get_series_name()
    {
        cout<<"\tEnter the Name of Series\t\t:";
        gets(series_name);
    }
    
    void display_match_name()
    {
        cout<<"\n\t\tMatch Name\t\t\t:"        <<match_name;
    }
    
    void get_match_name()
    {
        cout<<"\tEnter the Name of Match\t\t\t:";
        gets(match_name);
    }
    
    void display_name_of_team1()
    {
        cout<<"\n\t\tTeam I Name\t\t\t:"        <<name_of_team1;
    }
    
    void get_name_of_team1()
    {
        cout<<"\tEnter the Name of Team I\t\t:";
        gets(name_of_team1);
    }
    
    void display_name_of_team2()
    {
        cout<<"\n\t\tTeam II Name\t\t\t:"        <<name_of_team2;
    }
    
    void get_name_of_team2()
    {
        cout<<"\tEnter the Name of Team II\t\t:";
        gets(name_of_team2);
    }
    
    void display_venue()
    {
        cout<<"\tVenue\t\t\t\t:"        <<venue;
    }
    
    void get_venue()
    {
        cout<<"\tVenue\t\t\t\t\t:";
        gets(venue);
    }
    
    void display_starting_time()
    {
        cout<<"\tTime of match\t\t\t:"    <<time_of_match;
    }
    
    void get_starting_time()
    {
        cout<<"\tTime of match\t\t\t:";
        cin>>time_of_match;
    }
    
    
    void display_ticket_fee_gold()
    {
        cout<<"\tCost of gold ticket seat\t\t:"    <<ticket_fee_gold;
    }
    
    void get_ticket_fee_gold()
    {
        cout<<"\tCost of gold ticket seat\t\t:";
        cin>>ticket_fee_gold;
    }
    
    void display_ticket_fee_silver()
    {
        cout<<"\tCost of silver ticket seat\t\t:"    <<ticket_fee_silver;
    }
    
    void get_ticket_fee_silver()
    {
        cout<<"\tCost of silver ticket seat\t\t:";
        cin>>ticket_fee_silver;
    }
    
    void display_ticket_fee_regular()
    {
        cout<<"\tCost of regular ticket seat\t\t:"    <<ticket_fee_regular;
    }
    
    void get_ticket_fee_regular()
    {
        cout<<"\tCost of regular ticket seat\t\t:";
        cin>>ticket_fee_regular;
    }
    
    void get_total_no_of_seats_gold()
    {
        cout<<"\tEnter total number gold of seats\t:";
        cin>>total_no_of_seats_gold;
    }
    
    void get_total_no_of_seats_silver()
    {
        cout<<"\tEnter total number silver of seats\t:";
        cin>>total_no_of_seats_silver;
    }
    
    void get_total_no_of_seats_regular()
    {
        cout<<"\tEnter total number regular of seats\t:";
        cin>>total_no_of_seats_regular;
    }
    
    void get_no_of_seats_regular_booked()
    {
        cout<<"\tEnter the number of gold seats booked\t:";
        cin>>no_of_seats_regular_booked;
    }
    
    void get_no_of_seats_silver_booked()
    {
        cout<<"\tEnter the number of silver seats booked\t:";
        cin>>no_of_seats_silver_booked;
    }
    
    void get_no_of_seats_gold_booked()
    {
        cout<<"\tEnter the number of gold seats booked\t:";
        cin>>no_of_seats_gold_booked;
    }
    
}sport;


char o;

//FUNCTION TO ADD SPORTS TO THE FILE

void Add_Sports()
{
    system("cls");
    ficsp.open("sportsbinary.dat",ios::app| ios::binary);
    do
    {
        system("cls");
        sport.getevent();
        ficsp.write((char*)&sport, sizeof(sport));
        cout<<"\n\n\n\n\n\t\t\t\t\t\tPress Any Key To Continue....";
        getch();
        system("cls");
        cout    <<"\n\n\n\n\n\n\n\n\n"
        <<"\t\t**********************************************"
        <<"\n\t\t\t\t Record"
        <<" \n\t\t\t\t  Added "
        <<"\n\t\t\t\t Succesfully"
        <<"\n\t\t**********************************************"
        <<"\n\n\n\n\n\n\t\t\t\t\t\tPress Any Key To Continue....";
        getch();
        system("cls");
        cout     <<"\n\n\n\n\n\n\n\n\t\tDo you want to add any more records?(Y/N)";
        cin>>o;
    }while (o=='Y'||o=='y');
    ficsp.close();
}

//FUNCTION TO DISPLAY ALL THE SPORTS FROM THE FILE

void Display_All_Sports()
{
    system("cls");
    int a=1;
    ficsp.open("sportsbinary.dat",ios::in| ios::binary);
    while(ficsp.read((char*)&sport, sizeof(sport)))
    {
        if(strcmp(sport.return_match_name(),NULL)!=0)
        {
            cout<<"\n\n\n\n\n\t\t\t\tRecord  "<<a<<"\n\n";
            sport.putevent();
            a++;
        }
        
        cout<<"\n\n\n\t\t\t\t\t\tPress Any Key To Continue....";
        getch();
        system("cls");
        
    }
    ficsp.close();
}

//FUNCTION TO DISPLAY A PARTICULAR SPORT FROM THE FILE

void Display_Particular_Sport()
{
    system("cls");
    char n[50],m[50],found='n';
    cout<<endl<<"Enter Type of Sport or Match ID that is to be Displayed : ";
    gets(n);
    ficsp.open("sportsbinary.dat",ios::in| ios::binary);
    while( ficsp.read((char*)&sport, sizeof(sport)))
    {
        if(strcmp(n,sport.return_type_of_sport())==0)
        {
            cout<<"Enter the Name of the series that is to be Displayed : ";
            gets(m);
            break;
        }
    }
    ficsp.close();
    ficsp.open("sportsbinary.dat",ios::in| ios::binary);
 
    while( ficsp.read((char*)&sport, sizeof(sport)))
    {
 if(((strcmp(n,sport.return_type_of_sport())==0) && (strcmp(m,sport.return_series_name())==0)) || (strcmp(n,sport.return_id())==0))
        {
            cout<<"\n\n";
            sport.putevent();
            found='y';
            break;
        }
    }
    if(found=='n')
    {
        system("cls");
        cout<<"\n\n\n\n\n\n\n\n\t\t**********  No such Sport exists  *********";
    }
    ficsp.close();
    getch();
}

//FUNCTION TO MODIFY DETAILS OF A PARTICULAR SPORT FROM THE FILE

void Modify_Sport_Details()
{
    char n[50],m[50],found,o,opt[10];
    int p,q,r;
    do
    {
        found='n';
        system("cls");
        cout<<endl<<"\n\n\n\nEnter Type of Sport or Match ID that is to be Modified:";
        gets(n);
        ficsp.open("sportsbinary.dat",ios::in| ios::binary);
        while( ficsp.read((char*)&sport, sizeof(sport)))
        {
            if(strcmp(n,sport.return_type_of_sport())==0)
            {
                cout<<"Enter the Name of the series that is to be Modified";
                gets(m);
                break;
            }
        }

        ficsp.close();
        ficsp.open("sportsbinary.dat",ios::in| ios::out|ios::binary);
        system("cls");

        while(ficsp.read((char*)&sport, sizeof(sport)))
        {
            if(((strcmpi(n,sport.return_type_of_sport())==0) &&                (strcmpi(m,sport.return_series_name())==0))|| (strcmpi(n,sport.return_id())==0))
            {
                ficsp.seekg(0,ios::cur);
                cout    <<"\n\n\n\t\t**** Modifications Menu ****"
                <<"\n\n\t\t|=======|======================================|"
                <<"\n\t\t|OPTION\t|\t\tMENU\t\t\t|"
                <<"\n\t\t|=======|======================================|"
                <<"\n\t\t|   1   |\tSport\t\t\t\t|"
                <<"\n\t\t|   2   |\tName of Series\t\t\t|"
                <<"\n\t\t|   3   |\tName of Match\t\t\t|"
                <<"\n\t\t|   4   |\tName of Team I\t\t\t|"
                <<"\n\t\t|   5   |\tName of Team II\t\t\t|"
                <<"\n\t\t|   6   |\tVenue\t\t\t\t|"
                <<"\n\t\t|   7   |\tTime of Match\t\t\t|"
                <<"\n\t\t|   8   |\tNo . of Gold Seats\t\t|"
                <<"\n\t\t|   9   |\tNo . of Silver Seats\t\t|"
                <<"\n\t\t|   10  |\tNo . of Regular Seats\t\t|"
                <<"\n\t\t|   11  |\tNo . of Gold Seats Booked\t|"
                <<"\n\t\t|   12  |\tNo . of Silver Seats Booked\t|"
                <<"\n\t\t|   13  |\tNo . of Regular Seats Booked\t|"
                <<"\n\t\t|   14  |\tCost of Gold Seats\t\t|"
                <<"\n\t\t|   15  |\tCost of Silver Seats\t\t|"
                <<"\n\t\t|   16  |\tCost of Regular Seats\t\t|"
                <<"\n\t\t|   17  |\tEntire Record\t\t\t|"
                <<"\n\t\t|   18  |\tGo to Previous Menu\t\t|"
                <<"\n\t\t|   19  |\tExit from program\t\t|"
                <<"\n\t\t|=======|======================================|"
                <<"\n\n\t\tEnter your Option : \t";
                cin>>opt;
                strcat(opt,",");
                system("cls");
                cout<<"\n\n\n\t\t\t**** Type And Id Of Sport:****"<<endl;
                sport.display_id();
                sport.display_type_of_sport();
                
                cout<<"\n\n\t\t\t**** Enter Modifications ****"<<endl;
                
                for(int i=0;opt[i]!='\0';i++)
                {
                    
                    if(opt[i+1]!=','&&(strlen(opt)>1)&&opt[i]!=',')
                    {
                        if(opt[i]=='1'&&opt[i+1]=='0')
                            sport.get_total_no_of_seats_regular();
                        
                        else if(opt[i]=='1'&&opt[i+1]=='1')
                            sport.get_no_of_seats_gold_booked();
                        
                        else if(opt[i]=='1'&&opt[i+1]=='2')
                            sport.get_no_of_seats_silver_booked();
                        
                        else if(opt[i]=='1'&&opt[i+1]=='3')
                            sport.get_no_of_seats_regular_booked();
                        
                        else if(opt[i]=='1'&&opt[i+1]=='4')
                            sport.get_ticket_fee_gold();
                        
                        else if(opt[i]=='1'&&opt[i+1]=='5')
                            sport.get_ticket_fee_silver();
                        
                        else if(opt[i]=='1'&&opt[i+1]=='6')
                            sport.get_ticket_fee_regular();
                        
                        else if(opt[i]=='1'&&opt[i+1]=='7')
                            sport.getevent();
                        
                        else if(opt[i]=='1'&&opt[i+1]=='8')
                            break;
                        
                        else if(opt[i]=='1'&&opt[i+1]=='9')
                            exit(0);
                        
                        i++;
                    }
                    
                    else
                    {
                        switch(opt[i])
                        {
                            case '1':
                                sport.get_type_of_sport();
                                break;
                            case '2':
                                sport.get_series_name();
                                break;
                            case '3':
                                sport.get_match_name();
                                break;
                            case '4':
                                sport.get_name_of_team1();
                                break;
                            case '5':
                                sport.get_name_of_team2();
                                break;
                            case '6':
                                sport.get_venue();
                                break;
                            case '7':
                                sport.get_starting_time();
                                break;
                            case '8':
                                sport.get_total_no_of_seats_gold();
                                break;
                            case '9':
                                sport.get_total_no_of_seats_silver();
                                break;
                            case ',':
                                break;
                                
                            default:
                                cout<<"Kindly Enter a valid option from \'1-11\'";
                                
                        }
                    }
                }
                p=ficsp.tellg();
                q=sizeof(sport);
                r=p-q;
                ficsp.seekp(r);
                ficsp.write((char*)&sport, sizeof(sport));
                found='y';
                break;
            }
        }
        
        if(found=='y'&&(strcmp(opt,"15")!=0))
        {
            system("cls");
            cout<<"\n\n\t\t**** Sport Details After Modifications ****"<<"\n\n";
            sport.putevent();
        }
        
        else if(strcmp(opt,"15")!=0)
        {
            system("cls");
            cout<<"\n\n\n\n\n\n\n\n\t\t**********  No such Sport exists  *********";
        }
        
        ficsp.close();
        cout<<"\n\n\t\t\t\t\t\tPress Any Key To Continue....";
        getch();
        system("cls");
        cout<<"\n\n\nDo You Want to Modify more Sports from the file?\t";
        cin>>o;
        
    }while(o=='y'||o=='Y');
}

//FUNCTION TO REMOVE SPORTS FROM FILE

void Remove_Sport()
{
    char n[50],m[50],found='n',o;
    do
    {
        found='n';
        system("cls");
        cout<<endl<<"\n\n\n\tEnter Type of Sport or Match ID of the Sporth that is to be Removed : ";
        gets(n);
        ficsp.open("sportsbinary.dat",ios::in| ios::binary);
        while( ficsp.read((char*)&sport, sizeof(sport)))
        {
            if(strcmp(n,sport.return_type_of_sport())==0)
            {
                cout<<"\tEnter the Name of the series that is to be searched";
                gets(m);
                break;
            }
        }
        ficsp.close();
        ofstream temp;
        temp.open("new.dat",ios::out|ios::binary);
        ficsp.open("sportsbinary.dat",ios::in| ios::binary);
        while(ficsp.read((char*)&sport,sizeof(sport)))
        {
            if(((strcmpi(n,sport.return_type_of_sport())==0) && (strcmpi(m,sport.return_series_name())==0)) || (strcmpi(n,sport.return_id())==0))
            {
                system("cls");
                cout<<"\n\n\n\n\t\t********  Sport Removed From file  *******";
                found='y';
            }
            else
                temp.write((char*)&sport, sizeof(sport));
        }
        
        if(found=='n')
        {
            system("cls");
            cout<<"\n\n\n\n\n\n\n\n\t\t**********  No such Sport exists  *********";
        }
        temp.close();
        ficsp.close();
        remove("sportsbinary.dat");
        rename("new.dat", "sportsbinary.dat");
        cout<<"\n\n\n\n\n\t\t\t\t\t\tPress Any Key To Continue....";
        getch();
        system("cls");
        cout<<"\n\n\nDo You Want to Remove more Sports from the file?\t";
        cin>>o;
    }while(o=='y'||o=='Y');
}

void no_of_sports()
{
    int n = 0;
    ficsp.open("sportsbinary.dat",ios::in| ios::binary);
    while(ficsp.read((char*)&sport,sizeof(sport)))
    {
        n++;
    }
    ficsp.close();
}

void Display_Sport_name()
{
    
    int c=1;
    ficsp.open("sportsbinary.dat",ios::in| ios::binary);
    cout <<"\n\n\n\t\t\t**** Sports Menu ****"
    <<"\n\n\t\t\t|=======|===============================|"
    <<"\n\t\t\t|OPTION\t|\tNAME OF SPORT\t\t|"
    <<"\n\t\t\t|=======|===============================|";
    while(ficsp.read((char*)&sport, sizeof(sport)))
    {
        if(strcmp(sport.return_match_name(),NULL)!=0)
        {
            
            cout<<"\n\t\t\t|   c   |\t";
            sport.display_match_name();
            cout<<"\t\t\t|";
            
        }
        
        
    }
    cout <<"\n\t\t\t|   "<<++c<<"   |\tGo To Tickets Menu\t|"
    <<"\n\t\t\t|   "<<++c<<"   |\tGo To Main Menu\t|"
    <<"\n\t\t\t|   "<<++c<<"   |\tExit From Program\t|";
    cout<<"\n\t\t\t|=======|===============================|";
    ficsp.close();
}


//CLASS MOVIES


class MOVIES
{
    char name_of_movie[100],
         theatre_name[100],
         cinema_no[30],
         starting_time[10],
         movie_id[50],
         movie_duration[20],
         language[20];
    
    float ticket_fee;
    
    int  no_of_seats_booked,
         total_no_of_seats;
    
public:
    
    
    MOVIES()
    {
        strcpy(movie_id,"NULL");
        strcpy(name_of_movie,"NULL");
        strcpy(theatre_name,"NULL");
        strcpy(cinema_no,"NULL");
        strcpy(starting_time,"NULL");
        strcpy(movie_duration,"NULL");
        strcpy(language,"NULL");
        ticket_fee=0;
        no_of_seats_booked=0;
        total_no_of_seats=0;
    }
    
    void getmovie()
    {    cout<<"\n\n\n\n\n\n";
        cout<<"\tEnter the Movie Id\t\t\t:";
        gets(movie_id);
        cout<<"\tEnter the Name of the Movie\t\t:";
        gets(name_of_movie);
        cout<<"\tEnter Language of Movie\t\t\t:";
        gets(language);
        cout<<"\tEnter the Name of Theatre\t\t:";
        gets(theatre_name);
        cout<<"\tEnter the Cinema Number\t\t\t:";
        gets(cinema_no);
        cout<<"\tEnter the Starting time of movie\t:";
        gets(starting_time);
        cout<<"\tEnter Movie Duration\t\t\t:";
        gets(movie_duration);
        cout<<"\tEnter the Total Number of Seats\t\t:";
        cin>>total_no_of_seats;
        cout<<"\tEnter the Number of Seats Booked\t:";
        cin>>no_of_seats_booked;
        cout<<"\tEnter the Cost of Seat\t\t\t:";
        cin>>ticket_fee;
    }
    
    void putmovie()
    {
   cout <<"\n\t\t\tMovie Id\t\t:"        <<movie_id
        <<"\n\t\t\tMovie Name\t\t:"        <<name_of_movie
        <<"\n\t\t\tLanguage\t\t:"        <<language
        <<"\n\t\t\tTheatre Name\t\t:"        <<theatre_name
        <<"\n\t\t\tCinema Number\t\t:"        <<cinema_no
        <<"\n\t\t\tMovie Duration\t\t:"        <<movie_duration
        <<"\n\t\t\tTime of movie\t\t:"        <<starting_time
        <<"\n\t\t\tTotal number of seats\t:"    <<total_no_of_seats
        <<"\n\t\t\tNumber of seats booked\t:"   <<no_of_seats_booked
        <<"\n\t\t\tCost of ticket\t\t:"        <<ticket_fee
        <<endl;
    }
    
    char *return_name()
    {
        return name_of_movie;
    }
    
    char *return_id()
    {
        return movie_id;
    }
    
    char *return_language()
    {
        return language;
    }
    float return_ticket_fee()
    {
        return ticket_fee;
    }
    
    void modify_no_of_seats_booked(int g)
    {
        no_of_seats_booked=no_of_seats_booked+g;
    }
    
    int return_no_of_seats_booked()
    {
        return no_of_seats_booked;
    }
    
    float return_total_no_of_seats()
    {
        return total_no_of_seats;
    }
    
    void display_id()
    {
        cout<<"\tMovie Id\t\t\t:"        <<movie_id;
    }
    
    void get_id()
    {
        cout<<"\tMovie Id\t\t\t:";
        gets(movie_id);
    }
    
    void display_name()
    {
        cout<<"\tMovie Name\t\t\t:"        <<name_of_movie;
    }
    
    void get_name()
    {
        cout<<"\tName of the Movie\t\t:";
        gets(name_of_movie);
    }
    
    void display_theatre_name()
    {
        cout<<"\tTheatre Name\t\t\t:"        <<theatre_name;
    }
    
    void get_theatre_name()
    {
        cout<<"\tTheatre Name\t\t\t\t:";
        gets(theatre_name);
    }
    void display_cinema_no()
    {
        cout<<"\tCinema Number\t\t\t:"    <<cinema_no;
    }
    void get_cinema_no()
    {
        cout<<"\tCinema Number\t\t\t\t:";
        gets(cinema_no);
    }
    void display_starting_time()
    {
        cout<<"\tTime of movie\t\t\t:"    <<starting_time;
    }
    
    void get_starting_time()
    {
        cout<<"\tTime of movie\\tt\t\t:";
        cin>>starting_time;
    }
    void display_ticket_fee()
    {
        cout<<"\tCost of ticket\t:"    <<ticket_fee;
    }
    void display_movie_duration()
    {
        cout<<"\tDuration of Movie\t:"    <<movie_duration;
    }
    void get_movie_duration()
    {
        cout<<"\tDuration of Movie\t\t\t:";
        gets(movie_duration);
    }
    
    void get_movie_language()
    {
        cout<<"\tLanguage of Movie\t\t\t:";
        gets(language);
    }
    
    void get_ticket_fee()
    {
        cout<<"\tCost of ticket\t\t\t\t:";
        cin>>ticket_fee;
    }
    
    void get_no_of_seats_booked()
    {
        cout<<"\tEnter the number of seats booked\t:";
        cin>>no_of_seats_booked;
    }
    void display_no_of_seats_booked()
    {
        cout<<"\tThe number of seats booked\t\t:"<<    no_of_seats_booked;
    }
    void get_total_no_of_seats()
    {
        cout<<"\tEnter total number of seats\t\t:";
        cin>>total_no_of_seats;
    }
    void display_total_no_of_seats()
    {
        cout<<"\tTotal number of seats\t\t:"        <<        total_no_of_seats;
    }
    
}movie;

fstream fic1,fib1;


// FUNCTION TO ADD MOVIES TO THE FILE

void Add_Movies()
{
    char o;
    system("cls");
    fic1.open("moviebinary.dat",ios::app| ios::binary);
    do
    {
        system("cls");
        movie.getmovie();
        fic1.write((char*)&movie, sizeof(movie));
        cout<<"\n\n\n\n\n\t\t\t\t\t\tPress Any Key To Continue....";
        getch();
        system("cls");
        cout    <<"\n\n\n\n\n\n\n\n\n"
        <<"\t\t**********************************************"
        <<"\n\t\t\t\t Record"
        <<" \n\t\t\t\t  Added "
        <<"\n\t\t\t\t Succesfully"
        <<"\n\t\t**********************************************"
        <<"\n\n\n\n\n\n\t\t\t\t\t\tPress Any Key To Continue....";
        getch();
        system("cls");
        cout     <<"\n\n\n\n\n\n\n\n\t\tDo you want to add any more records?(Y/N)";
        cin>>o;
    }while (o=='Y'||o=='y');
    fic1.close();
}


// FUNCTION TO DISPLAY ALL THE MOVIES PRESENT IN THE FILE

void Display_All_Movies()
{
    system("cls");
    int a=1;
    fic1.open("moviebinary.dat",ios::in| ios::binary);
    while(fic1.read((char*)&movie, sizeof(movie)))
    {
        if(strcmp(movie.return_name(),NULL)!=0)
        {
            cout<<"\n\n\n\n\n\t\t\t\t\tMovie  "<<a<<"\n\n";
            movie.putmovie();
            a++;
        }
        
        cout<<"\n\n\n\n\n\t\t\t\t\t\tPress Any Key To Continue....";
        getch();
        system("cls");
        
    }
    fic1.close();
}

// FUNCTION TO DISPLAY A PARTICULAR MOVIE FROM THE FILE

void Display_Particular_Movie()
{
    system("cls");
    char n[100],found='n',m[100];
    cout<<endl<<"\n\n\nEnter Name of Movie or the ID of the Movie that should be searched:";
    gets(n);
    fic1.open("moviebinary.dat",ios::in| ios::binary);

    while( fic1.read((char*)&movie, sizeof(movie)))
    {
        if(strcmp(n,movie.return_name())==0)
        {
            cout<<"Enter the Language of the Movie that is to be displayed";
            gets(m);
            break;
        }
    }
    fic1.close();
    fic1.open("moviebinary.dat",ios::in| ios::binary);


    while( fic1.read((char*)&movie, sizeof(movie)))
    {
        if(((strcmp(n,movie.return_name())==0) && (strcmp(m,movie.return_language())==0)) || (strcmp(n,movie.return_id())==0))
        {
            cout<<"\n\n";
            movie.putmovie();
            found='y';
            break;
        }
    }
    if(found=='n')
    {
        system("cls");
        cout<<"\n\n\n\n\n\n\n\n\t\t**********  No such Movie exists  *********";
    }
    fic1.close();
    getch();
}

// FUNCTION TO MODIFY A PARTICULAR MOVIE FROM THE FILE

void Modify_Movie_Details()
{
    char n[100],found,o,opt[30],m[100];
    int p,q,r;
    do
    {
        found='n';
        system("cls");
        cout<<"\n\n\n\n\n\nEnter Name or The Movie Id of the Movie whose details must be modified: \n";
        gets(n);
        fic1.open("moviebinary.dat",ios::in| ios::binary);
        while( fic1.read((char*)&movie, sizeof(movie)))
        {
            if(strcmp(n,movie.return_name())==0)
            {
                cout<<"Enter the Language of the Movie that is to be displayed";
                gets(m);
                break;
            }
        }
        fic1.close();
        fic1.close();
        fic1.open("moviebinary.dat",ios::in| ios::out|ios::binary);
        system("cls");
        while(fic1.read((char*)&movie, sizeof(movie)))
        {
            if(((strcmp(n,movie.return_name())==0) && (strcmp(m,movie.return_language())==0)) || (strcmp(n,movie.return_id())==0))
            {
                fic1.seekg(0,ios::cur);
                cout    <<"\n\n\n\t\t\t**** Modifications Menu ****"
                <<"\n\n\t\t|=======|=======================================|"
                <<"\n\t\t|OPTION\t|\t\tMENU\t\t\t|"
                <<"\n\t\t|=======|=======================================|"
                <<"\n\t\t|   1   |\tName Of Movie\t\t\t|"
                <<"\n\t\t|   2   |\tLanguage Of Movie\t\t|"
                <<"\n\t\t|   3   |\tTheatre Name\t\t\t|"
                <<"\n\t\t|   4   |\tCinema Number\t\t\t|"
                <<"\n\t\t|   5   |\tStarting Time\t\t\t|"
                <<"\n\t\t|   6   |\tMovie Duration\t\t\t|"
                <<"\n\t\t|   7   |\tTotal No . of Seats\t\t|"
                <<"\n\t\t|   8   |\tNo . of Seats Booked\t\t|"
                <<"\n\t\t|   9   |\tCost of Ticket\t\t\t|"
                <<"\n\t\t|   10  |\tEntire Record\t\t\t|"
                <<"\n\t\t|   11  |\tExit from program\t\t|"
                <<"\n\t\t|=======|=======================================|"
                <<"\n\n\t\tEnter your Option : \t";
                gets(opt);
                strcat(opt,",");
                system("cls");
                cout<<"\n\n\n\t\t**** The Name And Id Of Movie:****"<<endl;
                cout<<"\t";
                movie.display_id();
                cout<<"\n\t";
                movie.display_name();
                
                cout<<"\n\n\t\t\t**** Enter Modifications ****"<<endl;
                
                for(int i=0;opt[i]!='\0';i++)
                {
                    if(opt[i+1]!=','&&(strlen(opt)>1)&&opt[i]!=',')
                    {
                        if(opt[i]=='1'&&opt[i+1]=='0')
                            movie.getmovie();
                        
                        else if(opt[i]=='1'&&opt[i+1]=='1')
                            exit(0);
                        i++;
                    }
                    
                    else
                    {
                        switch(opt[i])
                        {
                            case '1':
                                movie.get_name();
                                break;
                            case '2':
                                movie.get_movie_language();
                                break;
                            case '3':
                                movie.get_theatre_name();
                                break;
                            case '4':
                                movie.get_cinema_no();
                                break;
                            case '5':
                                movie.get_starting_time();
                                break;
                            case '6':
                                movie.get_movie_duration();
                                break;
                            case '7':
                                movie.get_total_no_of_seats();
                                break;
                            case '8':
                                movie.get_no_of_seats_booked();
                                break;
                            case '9':
                                movie.get_ticket_fee();
                                break;
                                
                            case ',':
                                break;
                            default:
                                cout<<"Kindly Enter a valid option from \'1-11\'";
                                
                        }
                    }
                }
                p=fic1.tellg();
                q=sizeof(movie);
                r=p-q;
                fic1.seekp(r);
                fic1.write((char*)&movie, sizeof(movie));
                found='y';
                break;
            }
        }
        if(found=='y')
        {
            system("cls");
            cout<<"\n\n\n\t\t**** Movie Details After Modifications ****"<<endl;
            movie.putmovie();
        }
        else
            cout<<"\n\n\n\n\t\t**********No such Movie exists *********";
        
        
        
        fic1.close();
        cout<<"\n\n\t\t\t\t\t\tPress Any Key To Continue....";
        getch();
        system("cls");
        cout<<"\n\n\nDo You Want to Modify more Movies from the File?\t";
        cin>>o;
        
    }while(o=='y'||o=='Y');
}

//FUNCTION TO REMOVE A PARTICULAR MOVIE FROM THE FILE

void Remove_Movie()
{
    char n[50],m[50],found='n',o;
    do
    {
        found='n',m[100];
        system("cls");
        cout<<endl<<"Enter Name of Movie or the ID of the Movie that is to be Deleted:";
        gets(n);
        fic1.open("moviebinary.dat",ios::in| ios::binary);
        while( fic1.read((char*)&movie, sizeof(movie)))
        {
            if(strcmp(n,movie.return_name())==0)
            {
                cout<<"Enter the Language of the Movie that is to be Deleted";
                gets(m);
                break;
            }
        }
        fic1.close();
        fic1.open("moviebinary.dat",ios::in| ios::binary);
        ofstream temp;
        temp.open("new.dat",ios::out|ios::binary);
        while(fic1.read((char*)&movie,sizeof(movie)))
        {
            
            if(((strcmp(n,movie.return_name())==0) && (strcmp(m,movie.return_language())==0)) || (strcmp(n,movie.return_id())==0))
            {
                system("cls");
                cout<<"\n\n\n\n\t\t********  Movie Removed From file  *******";
                found='y';
            }
            else
                temp.write((char*)&movie, sizeof(movie));
        }
        
        if(found=='n')
            cout<<"\n\n\n\n\t\t**********No such Movie exists in the file *********";
        temp.close();
        fic1.close();
        remove("moviebinary.dat");
        rename("new.dat", "moviebinary.dat");
        cout<<"\n\n\n\n\n\t\t\t\t\t\tPress Any Key To Continue....";
        getch();
        system("cls");
        cout<<"\n\n\nDo You Want to Remove more movie from the file?\t";
        cin>>o;
    }while(o=='y'||o=='Y');
}

// INTODUCTION FUNCTION

void intro()
{
    system("cls");
    gotoxy(30,10);
    cout<<"TICKET MANAGEMENT";
    gotoxy(32,14);
    cout<<"PROJECT";
    cout<<"\n\nMADE BY : \n\t\tMAHIKA KUSHWAHA "
    <<"\n\t\tNAMITHA MARIA JUSTINE"
    <<"\n\t\tSUCHITRA SUCHITRA";
    cout<<"\n\nSCHOOL : DPS - MODERN INDIAN SCHOOL";
    getch();
    
}

//MAIN FUNCTION

int main()
{
    intro();
    system("cls");
    Main_Menu();
}

//FUNCTION TO DISPLAY THE MAIN MENU

void Main_Menu()
{
    system("cls");
    char y,username[50],pass[50];
    do
    {
        system("cls");
        cout    <<"\n\n\n\n\n\n\t\t\t --------- MAIN  MENU ---------"
        <<"\n\n\t\t  |=======|==============================|"
        <<"\n\t\t  |OPTION |\t\tMENU\t\t |"
        <<"\n\t\t  |=======|==============================|"
        <<"\n\t\t  |   1   |\tAdmin\t\t\t |"
        <<"\n\t\t  |   2   |\tUser\t\t\t |"
        <<"\n\t\t  |   3   |\tExit From Program\t |"
        <<"\n\t\t  |=======|==============================|"
        <<"\n\n\t\t  Enter your choice :  ";
        
        cin    >>y;
        
        switch(y)
        {
            case '1':
                system("cls");
                cout<<"\n\n\n\n\n\n\n\n\n\t\t\tEnter username \t:";
                cin>>username;
                cout<<"\n\t\t\tEnter password \t:";
                int i;
                char a;
                for(i=0;;)
                {
                    a=getch();
                    if((a>='a'&&a<='z')||(a>='A'&&a<='Z')||(a>='0'&&a<='9'))
                    {
                        pass[i]=a;
                        ++i;
                        cout<<"*";
                    }
                    if(a=='\b'&&i>=1)
                    {
                        cout<<"\b\b";
                        --i;
                    }
                    if(a=='\r')
                    {
                        pass[i]='\0';
                        break;
                    }
                }
                
                if((strcmp(username,"ADMIN")==0)&&(strcmp(pass,"mahika")==0))
                    Admin_Menu();
                
                else
                {
                    system("cls");
                    cout    <<"\n\n\n\n\n\n\t\t\t********  ACCESS DENIED  ********"
                    <<"\n\t\t\tInvalid Username Or Password!!!"
                    <<"\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tPress Any Key To Continue....";
                    getch();
                    
                }
                break;
                
            case '2':
                system("cls");
                User_Menu();
                break;
                
            case '3':
                exit(0);
                break;
                
            default:
                cout<<"Kindly Enter A Valid Option";
        }
        
    }while(y!='3');
}

//FUNCTION TO DISPLAY THE ADMIN MENU

void Admin_Menu()
{
    int op;
    do
    {    system("cls");
        cout
        <<"\n\n\n\n\n\t\t\t**********  MENU **********"
        <<"\n\n\t\t|=======|===============================|"
        <<"\n\t\t|OPTION\t|\t\tMENU\t\t|"
        <<"\n\t\t|=======|===============================|"
        <<"\n\t\t|   1   |\tSports\t\t\t|"
        <<"\n\t\t|   2   |\tConcerts\t\t|"
        <<"\n\t\t|   3   |\tMovies\t\t\t|"
        <<"\n\t\t|   4   |\tGo To Main Menu\t\t|"
        <<"\n\t\t|   5   |\tExit From Program\t|"
        <<"\n\t\t|=======|===============================|"
        <<"\n\n\t\tEnter your choice :  ";
        cin>>op;
        
        switch(op)
        {
                
            case 1:
                Admin_Menu_Sport();
                break;
            case 2:
                Admin_Menu_Concert();
                break;
            case 3:
                Admin_Menu_Movie();
                break;
            case 4:
                Main_Menu();
                break;
            case 5:
                exit(0);
                break;
            default:
                cout<<"Kindly Enter a Valid option";
        }
    }while(op!=4);
    
}


void Admin_Menu_Concert()
{
    char x;
    int option;
    do
    {
        system("cls");
        
        cout    <<"\n\n\n\n\n\t\t|=======|===============================================|"
        <<"\n\t\t|OPTION\t|\t\tMENU\t\t\t\t|"
        <<"\n\t\t|=======|===============================================|"
        <<"\n\t\t|   1   |\tAdd New Concert\t\t\t\t|"
        <<"\n\t\t|   2   |\tDisplay Details of All Concerts\t\t|"
        <<"\n\t\t|   3   |\tDisplay Details of a Particular Concert |"
        <<"\n\t\t|   4   |\tModify Details Of a Particular Concert\t|"
        <<"\n\t\t|   5   |\tRemove  A Particular Concert\t\t|"
        <<"\n\t\t|   6   |\tGo to Admin Menu\t\t\t|"
        <<"\n\t\t|   7   |\tLog Out\t\t\t\t\t|"
        <<"\n\t\t|   8   |\tExit From Program\t\t\t|"
        <<"\n\t\t|=======|===============================================|"
        <<"\n\n\t\tEnter your Option :  ";
        cin>>option;
        switch(option)
        {
            case 1:
                Add_Concerts();
                break;
                
            case 2:
                Display_All_Concerts();
                break;
                
            case 3:
                Display_Particular_Concert();
                break;
                
            case 4:
                Modify_Concert_Details();
                break;
                
            case 5:
                Remove_Concert();
                break;
                
            case 6:
                Admin_Menu();
                break;
                
            case 7:
                system("cls");
                cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\tAre you sure you want to log out(Y/N)";
                cin>>x;
                if(x=='y'||x=='Y')
                    Main_Menu();
                
            case 8:
                exit(0);
                
            default:
                cout<<"Kindly Enter A Valid Choice";
                
        }
        system("cls");
        
    }while(option!=8);
}


void Admin_Menu_Sport()
{
    int option;
    char x;
    do
    {
        system("cls");
        
        cout    <<"\n\n\n\n\n\t\t|=======|===============================================|"
        <<"\n\t\t|OPTION\t|\t\tMENU\t\t\t\t|"
        <<"\n\t\t|=======|===============================================|"
        <<"\n\t\t|   1   |\tAdd New Sport\t\t\t\t|"
        <<"\n\t\t|   2   |\tDisplay Details of All Sports\t\t|"
        <<"\n\t\t|   3   |\tDisplay Details of a Particular Sport\t|"
        <<"\n\t\t|   4   |\tModify Details Of a Particular Sport\t|"
        <<"\n\t\t|   5   |\tRemove  A Particular Sport\t\t|"
        <<"\n\t\t|   6   |\tGo to Admin Menu\t\t\t|"
        <<"\n\t\t|   7   |\tLog Out\t\t\t\t\t|"
        <<"\n\t\t|   8   |\tExit From Program\t\t\t|"
        <<"\n\t\t|=======|===============================================|"
        <<"\n\n\t\tEnter your Option : \t";
        cin>>option;
        switch(option)
        {
            case 1:
                Add_Sports();
                break;
                
            case 2:
                Display_All_Sports();
                break;
                
            case 3:
                Display_Particular_Sport();
                break;
                
            case 4:
                Modify_Sport_Details();
                break;
                
            case 5:
                Remove_Sport();
                break;
                
            case 6:
                Admin_Menu();
                break;
                
            case 7:
                system("cls");
                cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\tAre you sure you want to log out(Y/N)";
                cin>>x;
                if(x=='y'||x=='Y')
                    Main_Menu();
                
            case 8:
                exit(0);
                break;
                
            default:
                cout<<"Kindly Enter A Valid Choice";
                
        }
        system("cls");
        
    }while(option!=8);
}

void Admin_Menu_Movie()
{
    char x;
    int option;
    do
    {
        system("cls");
        
        cout    <<"\n\n\n\n\n\t\t|=======|===============================================|"
        <<"\n\t\t|OPTION\t|\t\tMENU\t\t\t\t|"
        <<"\n\t\t|=======|===============================================|"
        <<"\n\t\t|   1   |\tAdd New Movie\t\t\t\t|"
        <<"\n\t\t|   2   |\tDisplay Details of All Movies\t\t|"
        <<"\n\t\t|   3   |\tDisplay Details of a Particular Movie\t|"
        <<"\n\t\t|   4   |\tModify Details Of a Particular Movie\t|"
        <<"\n\t\t|   5   |\tRemove  A Particular Movie\t\t|"
        <<"\n\t\t|   6   |\tGo to Admin Menu\t\t\t|"
        <<"\n\t\t|   7   |\tLog Out\t\t\t\t\t|"
        <<"\n\t\t|   8   |\tExit From Program\t\t\t|"
        <<"\n\t\t|=======|===============================================|"
        <<"\n\n\t\tEnter your Option :  ";
        cin>>option;
        switch(option)
        {
            case 1:
                Add_Movies();
                break;
                
            case 2:
                Display_All_Movies();
                break;
                
            case 3:
                Display_Particular_Movie();
                break;
                
            case 4:
                Modify_Movie_Details();
                break;
                
            case 5:
                Remove_Movie();
                break;
                
            case 6:
                Admin_Menu();
                break;
                
            case 7:
                system("cls");
                cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\tAre you sure you want to log out(Y/N)";
                cin>>x;
                if(x=='y'||x=='Y')
                    Main_Menu();
                
            case 8:
                exit(0);
                
            default:
                cout<<"Kindly Enter A Valid Choice";
                
        }
        system("cls");
        
    }while(option!=8);
}

//USER MENU

void User_Menu()
{
    int op;
    do
    {    system("cls");
        cout    <<"\n\n\n\n\t\t     ******* BOOK  TICKETS  NOW *******"
        <<"\n\t\t\t------- TICKET  MENU -------"
        <<"\n\n\t\t|=======|===============================|"
        <<"\n\t\t|OPTION |\t\tMENU\t\t|"
        <<"\n\t\t|=======|===============================|"
        <<"\n\t\t|   1   |\tSports\t\t\t|"
        <<"\n\t\t|   2   |\tConcerts\t\t|"
        <<"\n\t\t|   3   |\tMovies\t\t\t|"
        <<"\n\t\t|   4   |\tGo To Main Menu\t\t|"
        <<"\n\t\t|   5   |\tExit From Program\t|"
        <<"\n\t\t|=======|===============================|"
        <<"\n\n\t\tEnter your choice :  ";
        cin>>op;
        
        switch(op)
        {
                
            case 1:
                Book_Sport_Ticket();
                break;
            case 2:
                Book_Concert_Ticket();
                break;
            case 3:
                Book_Movie_Ticket();
                break;
            case 4:
                Main_Menu();
                break;
            case 5:
                exit(0);
                break;
            default:
                cout<<"Kindly Enter a Valid option";
        }
    }while(op!=4);
    
}

 void Book_Concert_Ticket()
{
    int p,noc=0,nos=0,ng=0,ns=0,nr=0,x;
    float price=0;
    char cname[50],v='y',d='n',d2='n',d3='n';
    
    int c=0;
    fic.open("concertbinary.dat",ios::in| ios::binary|ios::out);
    fic.seekg(0,ios::beg);
    
    while(v=='y'||'Y')
    {
        system("cls");
        
        c=0;
        cout    <<"\n\n\n\t\t\t\t******* Concerts Menu *******"
        <<"\n\n\t\t\t|=======|===============================|"
        <<"\n\t\t\t|OPTION\t|\tNAME OF CONCERT\t\t|"
        <<"\n\t\t\t|=======|===============================|";
        
        
        fib.open("concertbinary.dat",ios::in| ios::binary);
        fib.seekg(0);
        fib.seekp(0);
        
        while(fib.read((char*)&concert, sizeof(concert)))
        {
            if(strcmp(concert.return_name(),NULL)!=0)
            {
                c++;
                cout<<"\n\t\t\t|   "<<   c  << "   |\t";
                cout<<concert.return_name();
            }
            
        }
        
        fib.close();
        
        cout    <<"\n\t\t\t|   "<<c+1<<"   |\tGo To Tickets Menu\t|"
        <<"\n\t\t\t|   "<<c+2<<"   |\tGo To Main Menu\t\t|"
        <<"\n\t\t\t|   "<<c+3<<"   |\tExit From Program\t|"
        <<"\n\t\t\t|=======|===============================|";
        
        
        cout<<"\n\nEnter your choice : ";
        cin>>p;
        
        if((p-3)>c)
            cout<<"Enter a choice between 1 and "<<(noc+3);
        
        else if(p==c+1)
            
            User_Menu();
        else if(p==c+2)
            Main_Menu();
        
        else if(p==c+3)
            exit(0);
        
        else
        {
            system("cls");
            fic.seekg(((p-1)*sizeof(concert)));
            fic.read((char*)&concert,sizeof(concert));
            cout<<"\n\n\t\t\tDetails of Concert:"<<concert.return_name()<<"\n";
            concert.putevent();
            
            int lg=concert.return_total_no_of_seats_gold()-concert.return_no_of_seats_gold_booked();
            int ls= concert.return_total_no_of_seats_silver()- concert.return_no_of_seats_silver_booked();
            int lr=concert.return_total_no_of_seats_regular()- concert.return_no_of_seats_regular_booked();
            
            cout<<"\n\n\t\t\t\t\t\tPress Any Key To Continue....";
            getch();
            system("cls");
            
            cout    <<"\n\n\n\n\n\t\t\t\t*******PRICE  LIST *******\n"
            <<"\n\t|==========|============================|===============|"
            <<"\n\t|  OPTION  |\tNO OF SEATS AVAILABLE\t|\tPRICE\t|"
            <<"\n\t|==========|============================|===============|"
            <<"\n\t|   GOLD   |\t\t"<<lg<<"\t\t|\t"<<concert.return_ticket_fee_gold()<<"\t|"
            <<"\n\t|  SILVER  |\t\t"<<ls<<"\t\t|\t"<<concert.return_ticket_fee_silver()<<"\t|"
            <<"\n\t|  REGULAR |\t\t"<<lr<<"\t\t|\t"<<concert.return_ticket_fee_regular()<<"\t|"
            <<"\n\t|==========|============================|===============|"<<"\n";
            
            if(lg==0&&ls==0&&lr==0)
            {
                cout    <<"\n\n\n\n\n************* ALL SEATS ARE BOOKED*******************"
                <<"\n\n\n\n\n\t\t\t\t\t\tPress Any Key To Continue....";
                getch();
            }
            else
            {
                if((lg)!=0)
                {
                    do
                    {
                        cout<<"\n\tEnter No .Of Gold tickets to be booked:";
                        cin>>ng;
                        if(lg<ng)
                        {
                            cout<<"\n\tNo.of seats of be booked must be less than "<<lg<<"\n\tDo you    want to try again?\t";
                            cin>>d;
                            ng=0;
                        }
                    }while(d=='y'||d=='Y');

                }
                if((ls)!=0)
                {
                    do
                    {
                        d2='n';
                        cout<<"\n\tEnter No .Of Silver tickets to be booked:";
                        cin>>ns;
                        if(ls<ns)
                        {
                            cout<<"\n\tNo.of seats of be booked must be less than "<<ls<<"\n\tDo you want to try again?\t";
                            cin>>d2;
                            ns=0;
                        }
                    }while(d2=='y'||d2=='Y');
                }
                if((lr)!=0)
                {
                    do
                    {
                        d3='n';
                        cout<<"\n\tEnter No .Of Regular tickets to be booked:";
                        cin>>nr;
                        if(lr<nr)
                        {
                            cout<<"\n\tNo.of seats of be booked must be less than "<<lr<<"\n\tDo you want to try again?\t";
                            cin>>d3;
                            nr=0;
                        }
                    }while(d3=='y'||d3=='Y');
                }
                
                price = (ng*(concert.return_ticket_fee_gold()) + (ns*(concert.return_ticket_fee_silver())) + (nr*(concert.return_ticket_fee_regular())));
                
                cout<<"\n\n\n\n\n\t\t\t\t\t\tPress Any Key To Continue....";
                getch();
                system("cls");
                
       cout  <<"\n\n\n\n\n\t\t\t*******YOUR BOOKING*******"
                <<"\n\t\tConcert Name\t\t\t:"<<concert.return_name()
                <<"\n\t\tNo .Of Gold tickets Booked\t:"<<ng
                <<"\n\t\tNo .Of Silver tickets Booked\t:"<<ns
                <<"\n\t\tNo .Of Regular tickets Booked\t:"<<nr
                <<"\n\n\t\t\t******** Your Bill = Qr." <<price<<" ********"
                <<"\n\nDo you want to proceed with your booking?(Y/N)  ";
                cin    >>v;
                
                if((v=='Y')||(v=='y'))
                {
                    concert.modify_no_of_seats_gold_booked(ng);
                    concert.modify_no_of_seats_silver_booked(ns);
                    concert.modify_no_of_seats_regular_booked(nr);
                    x=fic.tellg();
                    fic.seekp(x-sizeof(concert),ios::beg);
                    fic.write((char*)&concert,sizeof(concert));
                    system("cls");
                    cout    <<"\n\n\n\n\n\n\n"
                    <<"\t\t************  Ticket Booked Succesfully  ************"
                    <<"\n\n\n\n\n\t\t\t\t\t\tPress Any Key To Continue....";
                    getch();
                    system("cls");
                    
                }
            }
        }
        c=0;
        
    }
    
    fic.close();
}

//FUNCTION TO BOOK SPORT TICKETS

void Book_Sport_Ticket()
{
    int p,noc=0,nos=0,ng=0,ns=0,nr=0,x;
    float price=0;
    char cname[50],v='y',d='n',d2='n',d3='n';
    
    int c=0;
    ficsp.open("sportsbinary.dat",ios::in| ios::binary|ios::out);
    ficsp.seekg(0,ios::beg);
    
    while(v=='y'||'Y')
    {
        system("cls");
        
        c=0;
        cout    <<"\n\n\n\t\t\t******* Sports Menu *******"
        <<"\n\n\t\t|=======|=======================================|"
        <<"\n\t\t|OPTION\t|\tNAME OF SPORT\t\t\t|"
        <<"\n\t\t|=======|=======================================|";
        
        
        fis.open("sportsbinary.dat",ios::in| ios::binary);
        fis.seekg(0);
        fis.seekp(0);
        
        while(fis.read((char*)&sport, sizeof(sport)))
        {
            if(strcmp(sport.return_match_name(),NULL)!=0)
            {
                c++;
                cout<<"\n\t\t|   "<<   c  << "   | \t";
                cout<<sport.return_type_of_sport()<<" - "<<sport.return_series_name();
            }
            
        }
        
        fis.close();
        
        cout    <<"\n\t\t|   "<<c+1<<"   |\tGo To Tickets Menu\t\t|"
        <<"\n\t\t|   "<<c+2<<"   |\tGo To Main Menu\t\t\t|"
        <<"\n\t\t|   "<<c+3<<"   |\tExit From Program\t\t|"
        <<"\n\t\t|=======|=======================================|";
        
        
        cout<<"\n\n\t\tEnter your choice : ";
        cin>>p;
        
        if((p-3)>c)
            cout<<"Enter a choice between 1 and "<<(noc+3);
        
        else if(p==c+1)
            
            User_Menu();
        else if(p==c+2)
            Main_Menu();
        
        else if(p==c+3)
            exit(0);
        
        else
        {
            system("cls");
            ficsp.seekg(((p-1)*sizeof(sport)));
            ficsp.read((char*)&sport,sizeof(sport));
            cout<<"\n\n\t\t\tDetails of Sport:"<<sport.return_match_name()<<"\n";
            sport.putevent();
            
            int lg=sport.return_total_no_of_seats_gold()- sport.return_no_of_seats_gold_booked();
            int ls= sport.return_total_no_of_seats_silver()- sport.return_no_of_seats_silver_booked();
            int lr=sport.return_total_no_of_seats_regular()- sport.return_no_of_seats_regular_booked();
            
            cout<<"\n\n\t\t\t\t\t\tPress Any Key To Continue....";
            getch();
            system("cls");
            
            cout    <<"\n\n\n\n\n\t\t\t*******PRICE  LIST *******\n"
            <<"\n\t|==========|============================|===============|"
            <<"\n\t|  OPTION  |\tNO OF SEATS AVAILABLE\t|\tPRICE\t|"
            <<"\n\t|==========|============================|===============|"
            <<"\n\t|   GOLD   |\t\t"<<lg<<"\t\t|\t"<<sport.return_ticket_fee_gold()<<"\t|"
            <<"\n\t|  SILVER  |\t\t"<<ls<<"\t\t|\t"<<sport.return_ticket_fee_silver()<<"\t|"
            <<"\n\t|  REGULAR |\t\t"<<lr<<"\t\t|\t"<<sport.return_ticket_fee_regular()<<"\t|"
            <<"\n\t|==========|============================|===============|"<<"\n";
            
            if(lg==0&&ls==0&&lr==0)
            {
                cout    <<"\n\n\n\n\n************* ALL SEATS ARE BOOKED*******************"
                <<"\n\n\n\n\n\t\t\t\t\t\tPress Any Key To Continue....";
                getch();
            }
            else
            {
                if((lg)!=0)
                {
                    do
                    {
                        cout<<"\n\tEnter No .Of Gold tickets to be booked:";
                        cin>>ng;
                        if(lg<ng)
                        {
                            cout<<"\n\tNo.of seats of be booked must be less than "<<lg<<"\n\tDo you want to try again?\t";
                            cin>>d;
                            ng=0;
                        }
                    }while(d=='y'||d=='Y');
                }
                
                if((ls)!=0)
                {
                    do
                    {
                        d2='n';
                        cout<<"\n\tEnter No .Of Silver tickets to be booked:";
                        cin>>ns;
                        if(ls<ns)
                        {
                            cout<<"\n\tNo.of seats of be booked must be less than "<<ls<<"\n\tDo you want to try again?\t";
                            cin>>d2;
                            ns=0;
                        }
                    }while(d2=='y'||d2=='Y');
                }
                if((lr)!=0)
                {
                    do
                    {
                        d3='n';
                        cout<<"\n\tEnter No .Of Regular tickets to be booked:";
                        cin>>nr;
                        if(lr<nr)
                        {
                            cout<<"\n\tNo.of seats of be booked must be less than "<<lr<<"\n\tDo you want to try again?\t";
                            cin>>d3;
                            nr=0;
                        }
                    }while(d3=='y'||d3=='Y');
                }
                
                price = (ng*(sport.return_ticket_fee_gold()) + (ns*(sport.return_ticket_fee_silver())) + (nr*(sport.return_ticket_fee_regular())));
                
                cout<<"\n\n\n\n\n\t\t\t\t\t\tPress Any Key To Continue....";
                getch();
                system("cls");
                
                cout    <<"\n\n\n\n\n\t\t\t*******YOUR BOOKING*******"
                <<"\n\t\tSport Name\t\t\t:"<<sport.return_match_name()
                <<"\n\t\tNo .Of Gold tickets Booked\t:"<<ng
                <<"\n\t\tNo .Of Silver tickets Booked\t:"<<ns
                <<"\n\t\tNo .Of Regular tickets Booked\t:"<<nr
                <<"\n\n\t\t\t******** Your Bill = Qr." <<price<<" ********"
                <<"\n\n\t\tDo you want to proceed with your booking?(Y/N)  ";
                cin    >>v;
                
                if((v=='Y')||(v=='y'))
                {
                    sport.modify_no_of_seats_gold_booked(ng);
                    sport.modify_no_of_seats_silver_booked(ns);
                    sport.modify_no_of_seats_regular_booked(nr);
                    x=ficsp.tellg();
                    ficsp.seekp(x-sizeof(sport),ios::beg);
                    ficsp.write((char*)&sport,sizeof(sport));
                    system("cls");
                    cout    <<"\n\n\n\n\n\n\n"
                    <<"\t\t************  Ticket Booked Succesfully  ************"
                    <<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tPress Any Key To Continue....";
                    getch();
                    system("cls");
                    
                }
            }
        }
        c=0;
        
    }
    
    ficsp.close();
}

void Book_Movie_Ticket()
{
    int p,noc=0,nos=0,n=0,x;
    float price=0;
    char cname[50],v='y',d='n';
    
    int c=0;
    fic.open("moviebinary.dat",ios::in| ios::binary|ios::out);
    fic.seekg(0,ios::beg);
    
    while(v=='y'||'Y')
    {
        system("cls");
        
        c=0;
        cout    <<"\n\n\n\t\t\t\t******* Movies Menu *******"
        <<"\n\n\t\t|=======|=======================================|"
        <<"\n\t\t|OPTION\t|\tNAME OF MOVIE-LANGUAGE\t\t|"
        <<"\n\t\t|=======|=======================================|";
        
        
        fib1.open("moviebinary.dat",ios::in| ios::binary);
        fib1.seekg(0);
        fib1.seekp(0);
        
        while(fib1.read((char*)&movie, sizeof(movie)))
        {
            if(strcmp(movie.return_name(),NULL)!=0)
            {
                c++;
                cout<<"\n\t\t|   "<<   c  << "   |\t";
                cout<<movie.return_name();
                cout<<"  -  "<<movie.return_language();
            }
            
        }
        
        fib1.close();
        
   cout <<"\n\t\t|   "<<c+1<<"   |\tGo To Tickets Menu\t\t|"
        <<"\n\t\t|   "<<c+2<<"   |\tGo To Main Menu\t\t\t|"
        <<"\n\t\t|   "<<c+3<<"   |\tExit From Program\t\t|"
        <<"\n\t\t|=======|=======================================|";
        
        
        cout<<"\n\nEnter your choice : ";
        cin>>p;
        
        if((p-3)>c)
            cout<<"Enter a choice between 1 and "<<(noc+3);
        
        else if(p==c+1)
            
            User_Menu();
        else if(p==c+2)
            Main_Menu();
        
        else if(p==c+3)
            exit(0);
        
        else
        {
            system("cls");
            fic.seekg(((p-1)*sizeof(movie)));
            fic.read((char*)&movie,sizeof(movie));
            cout<<"\n\n\t\t\tDetails of Movie:"<<movie.return_name();
            movie.putmovie();
            
            int g=movie.return_total_no_of_seats()- movie.return_no_of_seats_booked();
            
            cout<<"\n\n\t\t\t\t\t\tPress Any Key To Continue....";
            getch();
            system("cls");
            
       cout <<"\n\n\n\n\n\t\t\t\t*******PRICE  LIST *******\n"
            <<"\n\t\t|===============================|===============|"
            <<"\n\t\t| \tNO OF SEATS AVAILABLE\t|\tPRICE\t|"
            <<"\n\t\t|===============================|===============|"
            <<"\n\t\t|\t\t"<<g<<"\t\t|\t"<<movie.return_ticket_fee()<<"\t|"
            <<"\n\t\t|===============================|===============|"<<"\n";
            
            if(g==0)
            {
                cout    <<"\n\n\n\n\n*************** ALL SEATS ARE BOOKED*********************"
                <<"\n\n\n\n\n\t\t\t\t\t\tPress Any Key To Continue....";
                getch();
                system("cls");
            }
            
            else
            {
                do
                {
                    cout<<"\n\tEnter No .Of tickets to be booked:";
                    cin>>n;
                    if(g<n)
                    {
                        cout<<"\n\tNo.of seats of be booked must be less than "<<g<<"\n\tDo you want to try again?\t";
                        cin>>d;
                        n=0;
                    }
                }while(d=='y'||d=='Y');
                
                price = n*(movie.return_ticket_fee()) ;
                
                cout<<"\n\n\n\n\n\t\t\t\t\t\tPress Any Key To Continue....";
                getch();
                system("cls");
                
           cout <<"\n\n\n\n\n\t\t\t*******YOUR BOOKING*******"
                <<"\n\t\tMovie Name\t\t\t:"<<movie.return_name()
                <<"\n\t\tNo .Of tickets Booked\t\t:"<<n
                <<"\n\n\t\t******** Your Bill = Qr." <<price<<" ********"
                <<"\n\nDo you want to proceed with your booking?(Y/N)  ";
                cin    >>v;
                
                if((v=='Y')||(v=='y'))
                {
                    movie.modify_no_of_seats_booked(n);
                    x=fic.tellg();
                    fic.seekp(x-sizeof(movie),ios::beg);
                    fic.write((char*)&movie,sizeof(movie));
                    system("cls");
                    cout    <<"\n\n\n\n\n\n\n"
                    <<"\t\t************  Ticket Booked Succesfully  ************"
                    <<"\n\n\n\n\n\t\t\t\t\t\tPress Any Key To Continue....";
                    getch();
                    system("cls");
                    
                }
            }
        }
        c=0;
        
    }
    
    fic.close();
}