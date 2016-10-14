#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>

using namespace std;

class WidgetReport
{

    
public:
    WidgetReport(ifstream& in);  // constructor
    void print();
    void printHeader();
    void printDetails();

private:
    ifstream& input;  // reference to the input stream
    string state;
    string plant;
    string dept;
    string empid;
    string count;
    string name;
    string fname;
    string lname;
};

WidgetReport::WidgetReport(ifstream& in):input(in){
}
void WidgetReport::print()
{
    printHeader();
    printDetails();
}

void WidgetReport::printHeader()
{
    string line;
    getline(input, line);
    stringstream temp;
    temp << line;
    temp >> state;
    temp >> plant;
    temp >> dept;
    temp >> empid;
    temp >> name;
    temp >> count;
    
    cout << state<<" "<<plant<<" "<<dept<<" "<<empid<<" "<< count<< " "<<name<<endl;
}

void WidgetReport::printDetails()
{
    int tstate=0, tplant=0, tdept=0;
    int scount=0, pcount=0, dcount=0;
    int gTotal=0;
    string line;
    stringstream temp;
    cout << endl;
    bool change=false;
    while(getline(input, line))
    {
        temp.clear();
        temp << line;
        temp >> state;
        temp >> plant;
        temp >> dept;
        temp >> empid;
        temp >> fname;
        temp >> lname;
        temp >> count;
        
        if ((tdept!=0)&&(tdept!=stoi(dept)))
        {   
            change=true;
            if (dcount!=0)
            {   cout<<endl;
                cout<<setw(28)<<dcount<<" TOTAL FOR DEPT"<<"  "<<tdept<<"  "<<"*"<<endl;
            }
            dcount=0;
        }
        if((tplant!=0)&&(tplant!=stoi(plant)))
        {
            change=true;
            if (dcount!=0)
            {   cout<<endl;
                cout<<setw(28)<<dcount<<" TOTAL FOR DEPT"<<"  "<<tdept<<"  "<<"*"<<endl;
            }
            cout<<setw(28)<<pcount<<" TOTAL FOR PLANT"<<" "<<tplant<<"  "<<"**"<<endl;
            
            dcount=0;
            pcount=0;
        }
        if((tstate!=0)&&(tstate!=stoi(state)))
        {  
            change=true;
            if (dcount!=0)
            {cout<<endl;
            cout<<setw(28)<<dcount<<" TOTAL FOR DEPT"<<"  "<<tdept<<"  "<<"*"<<endl;}
            if (pcount!=0)
            cout<<setw(27)<<pcount<<" TOTAL FOR PLANT"<<" "<<tplant<<"  "<<"**"<<endl;
            if (scount!=0)
            cout<<setw(28)<<scount<<" TOTAL FOR STATE"<<" "<<tstate<<"  "<<"***"<<endl;
           
            dcount=0;
            pcount=0;
            scount=0;
        }
        if (change==true)
        {
            cout<<endl;
            change=false;
            
        }
        cout <<setw(5)<<state<<" "<<setw(5)<<plant<<" "<<setw(4)<<dept<<" "<<setw(5)<<empid<<" "<<setw(5)<<count<<" "<<fname<< " "<<lname<<" "<<endl;
        scount+=stoi(count);
        pcount+=stoi(count);
        dcount+=stoi(count);
        gTotal +=stoi(count);
        tstate=stoi(state);
        tplant=stoi(plant);
        tdept=stoi(dept);
    
    }
    cout<<endl;
    cout<<setw(28)<<dcount<<" TOTAL FOR DEPT"<<setw(4)<<tdept<<setw(3)<<"*"<<endl;
    cout<<setw(28)<<pcount<<" TOTAL FOR PLANT"<<" "<<tplant<<setw(4)<<"**"<<endl;
    cout<<setw(28)<<scount<<" TOTAL FOR STATE"<<" "<<tstate<<setw(5)<<"***"<<endl;
    cout<<endl;
    cout<<setw(28)<< gTotal<<" GRAND TOTAL"<<setw(13)<<"****" <<endl;

}

const string INPUT_FILE_NAME = "widgets.txt";

int main()
{
    ifstream input;
    input.open(INPUT_FILE_NAME);
    if (input.fail())
    {
        cout << "Failed to open " << INPUT_FILE_NAME << endl;
        return -1;
    }

    // Generate and print the Widget Report.
    /***** Complete this main. *****/
    
    WidgetReport wr(input);
    wr.print();
   

    input.close();
    return 0;
}
