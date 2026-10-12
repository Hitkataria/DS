#include<iostream>
using namespace std;

#define MAX 50      // maximum patients waiting
#define TMAX 100    // maximum patients kept in the treated record

struct patient
{
    int id;             // given automatically, smaller id means the patient came earlier
    char name[30];
    int age;
    int problem;        // problem number chosen from the list (1 to 9)
    int severity;       // 1 = Critical, 2 = Serious, 3 = Normal
};

struct patient queue[MAX];
int front=-1,rear=-1;
int next_id=101;        // id given to the next patient

struct patient treated[TMAX];
int tn=0;               // number of patients stored in the treated record
int total_treated=0;    // total patients treated so far

int full()
{
    if(front!=-1 && rear-front+1==MAX)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int empty()
{
    if(front==-1 || front>rear)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// reads a number and asks again until it is between low and high
int read_number(int low,int high)
{
    int x;
    cin>>x;
    while(x<low || x>high)
    {
        cout<<"Enter a number between "<<low<<" and "<<high<<": ";
        cin>>x;
    }
    return x;
}

void print_problem(int p) 
{
    switch(p)
    {
        case 1:
            cout<<"Heart attack / Chest pain";
            break;
        case 2:
            cout<<"Severe bleeding / Major accident";
            break;
        case 3:
            cout<<"Breathing difficulty";
            break;
        case 4:
            cout<<"Fracture / Deep wound";
            break;
        case 5:
            cout<<"High fever / Severe infection";
            break;
        case 6:
            cout<<"Severe pain";
            break;
        case 7:
            cout<<"Cold / Cough / Mild fever";
            break;
        case 8:
            cout<<"Checkup / Minor injury";
            break;
        case 9:
            cout<<"Other (not in list)";
            break;
    }
}

// problems 1-3 are Critical, 4-6 are Serious, 7-8 are Normal
int level(int p)
{
    if(p<=3)
        return 1;
    else if(p<=6)
        return 2;
    else
        return 3;
}

void print_severity(int sv) 
{
    if(sv==1)
        cout<<"Critical";
    else if(sv==2)
        cout<<"Serious";
    else
        cout<<"Normal";
}

// for "Other" the Nurse decides the priority, for the rest it comes from the list
int get_severity(int p)
{
    int sv;
    if(p==9)
    {
        cout<<"Problem is not in the list. Nurse, select priority (1.Critical 2.Serious 3.Normal): ";
        sv=read_number(1,3);
        return sv;
    }
    return level(p);
}

void show_problems() // shows the list of problems and their severity
{
    int i;
    cout<<"Medical Problems:"<<endl;
    for(i=1;i<=8;i++)
    {
        cout<<i<<". ";
        print_problem(i);
        cout<<" (";
        print_severity(level(i));
        cout<<")"<<endl;
    }
    cout<<"9. Other (not in list) (Nurse decides the priority)"<<endl;
}

void show_details(struct patient p) //Showing the next patient to be treated
{
    cout<<"ID: "<<p.id<<endl;
    cout<<"Name: "<<p.name<<endl;
    cout<<"Age: "<<p.age<<endl;
    cout<<"Problem: ";
    print_problem(p.problem);
    cout<<endl;
    cout<<"Severity: ";
    print_severity(p.severity);
    cout<<endl;
}

void show_row(int no,struct patient p) //Displaying all waiting patients in a list
{
    cout<<no<<"\t"<<p.id<<"\t"<<p.name<<"\t"<<p.age<<"\t";
    print_severity(p.severity);
    cout<<"\t";
    print_problem(p.problem);
    cout<<endl;
}

// returns 1 if patient a must be treated before patient b
int before(struct patient a,struct patient b) // checks if patient a has higher priority than patient b
{
    if(a.severity<b.severity)
    {
        return 1;
    }
    if(a.severity==b.severity && a.id<b.id) // smaller id means the patient came earlier, so higher priority
    {
        return 1;
    }
    return 0;
}

// moves all patients to the start of the array when space is free at the front
void shift_left()
{
    int i,j=0;
    for(i=front;i<=rear;i++)
    {
        queue[j]=queue[i];
        j++;
    }
    rear=rear-front;
    front=0;
}

// inserts the patient at the correct position, so the queue is always in order
void enqueue(struct patient p)
{
    int i,pos; //i for queue patient checking, pos for the position where the new patient should be inserted
    if(full())
    {
        cout<<"Queue Is Full"<<endl;
        return;
    }

    if(front==-1) // first patient
    {
        front=0;
        rear=-1;
    }

    if(rear==MAX-1) // if the rear is at the end of the array, shift all patients to the left to make space
    {
        shift_left();
    }

    pos=rear+1; // default position is at the end
    for(i=front;i<=rear;i++) // find the position where the new patient should be inserted
    {
        if(before(p,queue[i])) // if the new patient has higher priority
        {
            pos=i;
            break;
        }
    }

    for(i=rear;i>=pos;i--) // move all patients from pos to rear one position to the right to make space for the new patient
    {
        queue[i+1]=queue[i];
    }
    queue[pos]=p;
    rear++;
}

// the patient at the front is always the next one to be treated
struct patient dequeue()
{
    struct patient p;
    p=queue[front];
    front++;
    if(front>rear)
    {
        front=rear=-1;
    }
    return p;
}

// removes the patient at index pos and closes the gap
void remove_at(int pos)
{
    int i;
    for(i=pos;i<rear;i++)
    {
        queue[i]=queue[i+1];
    }
    rear--;
    if(rear<front)
    {
        front=rear=-1;
    }
}

int find_by_id(int id)
{
    int i;
    if(empty())
    {
        return -1;
    }
    for(i=front;i<=rear;i++)
    {
        if(queue[i].id==id)
        {
            return i;
        }
    }
    return -1;
}

int same_name(char a[],char b[]) // returns 1 if the two names are the same, 0 otherwise
{
    int i=0;
    while(a[i]!='\0' && b[i]!='\0') // check each character until the end of either string
    {
        if(a[i]!=b[i])
        {
            return 0;
        }
        i++;
    }
    if(a[i]=='\0' && b[i]=='\0') // both strings ended at the same time, so they are the same
        return 1;
    else
        return 0;
}

void register_patient() // registers a new patient and adds them to the queue
{
    struct patient p;

    if(full())
    {
        cout<<"Queue Is Full"<<endl;
        return;
    }

    p.id=next_id;
    cout<<"Enter Name: ";
    cin>>p.name;
    cout<<"Enter Age: ";
    p.age=read_number(0,120);
    show_problems();
    cout<<"Select problem number: ";
    p.problem=read_number(1,9);
    p.severity=get_severity(p.problem);

    enqueue(p);
    next_id++; // increment the next id for the next patient
    cout<<"Patient registered successfully. Patient ID is "<<p.id<<endl;
}

// keeps a record of every patient that has been called for treatment
void record_treated(struct patient p)
{
    total_treated++;
    if(tn<TMAX) 
    {
        treated[tn]=p;
        tn++;
    }
}

void call_next()
{
    struct patient p;
    if(empty())
    {
        cout<<"No patients are waiting"<<endl;
    }
    else
    {
        p=dequeue();
        cout<<"Now calling:"<<endl;
        show_details(p);
        record_treated(p); // record the patient in the treated list
    }
}

void peek()
{
    if(empty())
    {
        cout<<"No patients are waiting"<<endl;
    }
    else
    {
        cout<<"Next patient is:"<<endl;
        show_details(queue[front]);
    }
}

void display()
{
    int i,count=1;
    if(empty())
    {
        cout<<"No patients are waiting"<<endl;
        return;
    }

    cout<<"Patients in treatment order:"<<endl;
    cout<<"No.\tID\tName\tAge\tSeverity\tProblem"<<endl; 
    for(i=front;i<=rear;i++)
    {
        show_row(count,queue[i]); 
        count++;
    }
}

void update_problem()
{
    int id,pos,pr;
    struct patient p;
    if(empty())
    {
        cout<<"No patients are waiting"<<endl;
        return;
    }

    cout<<"Enter Patient ID: ";
    id=read_number(1,999999);
    pos=find_by_id(id);
    if(pos==-1)
    {
        cout<<"Patient not found"<<endl;
        return;
    }

    p=queue[pos];
    cout<<"Current problem: ";
    print_problem(p.problem);
    cout<<" (";
    print_severity(p.severity);
    cout<<")"<<endl;
    show_problems();
    cout<<"Select new problem number: ";
    pr=read_number(1,9);

    // remove the patient and insert again with the new problem, the id stays the same
    remove_at(pos);
    p.problem=pr;
    p.severity=get_severity(pr); 
    enqueue(p);
    cout<<"Problem updated"<<endl;
}

void cancel_patient()
{
    int id,pos;
    if(empty())
    {
        cout<<"No patients are waiting"<<endl;
        return;
    }

    cout<<"Enter Patient ID: ";
    id=read_number(1,999999);
    pos=find_by_id(id);
    if(pos==-1)
    {
        cout<<"Patient not found"<<endl;
        return;
    }

    remove_at(pos);
    cout<<"Patient removed from the queue"<<endl;
}

void search_patient()
{
    int ch,id,pos,i,found=0;
    char name[30];

    if(empty())
    {
        cout<<"No patients are waiting"<<endl;
        return;
    }

    cout<<"Search by 1.ID 2.Name: ";
    ch=read_number(1,2);
    if(ch==1)
    {
        cout<<"Enter Patient ID: ";
        id=read_number(1,999999);
        pos=find_by_id(id);
        if(pos==-1)
        {
            cout<<"Patient not found"<<endl;
        }
        else
        {
            show_details(queue[pos]);
        }
    }
    else
    {
        cout<<"Enter Name: ";
        cin>>name;
        for(i=front;i<=rear;i++)
        {
            if(same_name(queue[i].name,name))
            {
                show_details(queue[i]);
                cout<<endl;
                found=1;
            }
        }
        if(found==0)
        {
            cout<<"Patient not found"<<endl;
        }
    }
}

void show_treated()
{
    int i;
    if(total_treated==0)
    {
        cout<<"No patient has been treated yet"<<endl;
        return;
    }

    cout<<"Treated Patients (in the order they were called):"<<endl;
    cout<<"No.\tID\tName\tAge\tSeverity\tProblem"<<endl;
    for(i=0;i<tn;i++)
    {
        show_row(i+1,treated[i]);
    }
    cout<<"Total treated: "<<total_treated<<endl;
    if(total_treated>tn)
    {
        cout<<"(Only the first "<<TMAX<<" are kept in the record)"<<endl;
    }
}

int main()
{
    int h;
    while(1)
    {
        cout<<endl;
        cout<<"----- Hospital Patient Queue -----"<<endl;
        cout<<"1.Register Patient\n2.Call Next Patient\n3.Peek Next Patient\n4.Display Waiting Patients\n5.Update Medical Problem\n6.Cancel Patient\n7.Search Patient\n8.Treated Patients\n9.Exit"<<endl;
        cout<<"Enter your choice: ";
        h=read_number(1,9);

        switch(h)
        {
            case 1:
                register_patient();
                break;

            case 2:
                call_next();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                update_problem();
                break;

            case 6:
                cancel_patient();
                break;

            case 7:
                search_patient();
                break;

            case 8:
                show_treated();
                break;

            case 9:
                cout<<"You Successfully Exited the code..."<<endl;
                return 0;
        }
    }
}