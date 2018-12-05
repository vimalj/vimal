#include <iostream>
#include <ctime>
using namespace std;
int i;
class TemperatureSensor
{
public:
       int Temp;
       void GetTemp()
        {   cout << "Get Temperature:" <<endl;
            cin >>Temp;
        }
        void ShowTemp()
        {
            cout <<"Show Temperature=" <<Temp<<endl;
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
            char *tm = ctime(&t);
            cout << "Timestamp: " <<tm;
        }
};


class IotDataQueue : public TemperatureSensor, public HumiditySensor, public Time
{
public:
TemperatureSensor t;
HumiditySensor h;
Time d;
void result()
    {

    cout<<" Get Sensor input = "<<i<<endl;
    t.GetTemp();
    h.GetHumid();
    d.Date();


    cout<<" ----------Here is Sensor Result----- "<<endl;
    cout<<"sensor:  "<<i<<"  result"<<endl;
    t.ShowTemp();
    h.ShowHumid();
    d.Date();
    }
};

class SensorController: public IotDataQueue
{
    public:

    virtual void sensors()
    {
    IotDataQueue q[i];
    for (i=1; i<=10; i++)
    {
    q[i].result();
    }
    }
};


class Person: public SensorController
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
    cout<<" "<<"----Welcome to access sensors----"<<Name<<endl;
    }
    sensors();
}
};

int main()
{
    Person p1;
    p1.person();
    return 0;
}
