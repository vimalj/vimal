#include <iostream>
#include <ctime>
using namespace std;


class SensorStates
{
  class State *current;
  public:
    SensorStates();
    void setCurrent(State *s)
    {
        current = s;
    }
    void sensing();
    void idle();
    void processing();
};

class State
{
  public:
    virtual void sensing(SensorStates *m)
    {
        cout << "   already SENSING\n";
    }
    virtual void idle(SensorStates *m)
    {
        cout << "   already IDLE\n";
    }
    virtual void processing(SensorStates *m)
    {
        cout << "PROCESSING\n";
    }
};

void SensorStates::sensing()
{
  current->sensing(this);
}

void SensorStates::idle()
{
  current->idle(this);
}

void SensorStates::processing()
{
  current->processing(this);
}


class SENSING: public State
{
  public:
    SENSING()
    {
        cout << "   SENSING-ctor ";
    };
    ~SENSING()
    {
        cout << "   dtor-SENSING\n";
    };
    void idle(SensorStates *m);
};

class PROCESSING: public State
{
  public:
    PROCESSING()
    {
        cout << "   PROCESSING-ctor ";
    };
    ~PROCESSING()
    {
        cout << "   dtor-PROCESSING\n";
    };
    void idle(SensorStates *m);
};

class IDLE: public State
{
  public:
    IDLE()
    {
        cout << "   IDLE-ctor ";
    };
    ~IDLE()
    {
        cout << "   dtor-IDLE\n";
    };
    void sensing(SensorStates *m)
    {
        cout << "   going from IDLE to SENSING";
        m->setCurrent(new SENSING());
        delete this;
    }

     void processing(SensorStates *m)
    {
        cout << "   going from IDLE to processing";
        m->setCurrent(new PROCESSING());
        delete this;
    }
};

void SENSING::idle(SensorStates *m)
{
  cout << "   going from SENSING to IDLE";
  m->setCurrent(new IDLE());
  delete this;
}


void PROCESSING::idle(SensorStates *m)
{
  cout << "   going from PROCESSING to IDLE";
  m->setCurrent(new IDLE());
  delete this;
}

SensorStates::SensorStates()
{
  current = new IDLE();
  cout << '\n';
}


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
  void(SensorStates:: *ptrs[])() =
  {
    SensorStates::idle, SensorStates::sensing, SensorStates::processing
  };
  SensorStates fsm;
  int num;
while(1)
  {
    cout << "Enter 0 for idle/1 for sensing/2 for processing: ";
    cin >> num;
    (fsm.*ptrs[num])();

    if(num==2)
    {
    Person p1;
    p1.person();
    return 0;
    }
  }
}



