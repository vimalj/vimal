#include <iostream>
#include <ctime>
#include<cmath>
using namespace std;

class TemperatureSensor
{
     public:
       int Temp;

       void GetTemp()
        {
            cout << "Get Temperature:" <<endl;
            cin >> Temp;
        }
        void ShowTemp()
        {

            cout << "Show Temperature=" << Temp<<endl;
        }
};

class HumiditySensor
{
    public:
    int Humid;
       void GetHumid()
        {

            cout << "Get Humidity:" <<endl;
            cin >> Humid;
        }
        void ShowHumid()
        {
            cout << "Show Humidity=" << Humid<<endl;
        }
};

class Time
{
    public:
    void Date()
        {
            time_t t = time(NULL);
            tm* tPtr = localtime(&t);
            cout << " Current Date: " <<(tPtr->tm_mday)<<"/"<< (tPtr->tm_mon)+1 <<"/"<< (tPtr->tm_year)+1900<< endl;
            cout << " Current Time: " << (tPtr->tm_hour)<<":"<< (tPtr->tm_min)<<":"<< (tPtr->tm_sec) << endl;
            cout << endl;
        }
};


class IotDataQueue : public TemperatureSensor, public HumiditySensor, public Time
{
public:
void result()
{
    cout<<" Get Data from Sensor = "<<endl;
    TemperatureSensor t;
    t.GetTemp();

    HumiditySensor h;
    h.GetHumid();

    Time d;
    d.Date();

    cout<<"********** Here is Sensor Result *********"<<endl;
    d.Date();
    t.ShowTemp();
    h.ShowHumid();
    }
};

class sensor: public IotDataQueue
{
    public:
    void sensors()
    {
    IotDataQueue q1;
    q1.result();
    }
};


class Person: public sensor
{
    public:
    void person()
    {
    string Name;
    string Pass;
    cout<<"Enter Your Name = ";
    cin>>Name;
    cout<<"Enter Password = ";
    cin>>Pass;
    {
    cout<<Name<<"----Welcome to access sensors!----";
    }
    sensor s1;
    s1.sensors();
    }
};

int main()
{
    Person p1;
    p1.person();
    return 0;
}
