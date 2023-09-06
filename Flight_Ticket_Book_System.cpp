#include <iostream>
#include <fstream>
#include <conio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

using namespace std;

#define pnr "NALS0"
void New(int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "\n";
    }
}
void tab(int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "\t";
    }
}
void sTation()
{
    char arr[] = "BHUBANESWAR CHENNAI DELHI MUMBAI HYDERABAD SURAT BANGALORE PUNE KOLKATA GOA";
    New(5);
    for (int i = 0; i < sizeof(arr); i++)
    {
        cout << arr[i] << ends;
        _sleep(10);
    }
    New(3);
}
class Flight
{
private:
protected:
    string from, to, temp, temp2, temp3, choose;

    struct booking
    {
        string full_name;
        int age;
        string gender;
        string adress;
        string aadhar;
        string pan_card;
        string mob;
        string date;
        string class_type;
        string p;
    } bk;

    fstream f, tf, bf, bf2, pf, ptemp, log;

public:
    void search()
    {
        system("cls");
        sTation();
        f.open("flight.txt");
        tf.open("temp.txt", ios::out);

        cout << "\t\t\tFrom : ";
        cin.ignore();
        getline(cin, from);

        cout << "\t\t\t To :";
        getline(cin, to);
        int n = 1;
        while (!f.eof())
        {
            f >> temp;
            if (temp == from)
            {
                f >> temp;
                if (temp == to)
                {
                    getline(f, temp);
                    cout << "\n\t\t\t" << n << " " << from << " " << to << temp << endl;
                    tf << "\t" << n << " " << from << " " << to << temp << endl;
                    n++;
                }
            }
        }
        tf.close();
        f.close();

        tf.open("temp.txt");
        bf.open("book.txt", ios::app);
        cout << "\t\t\tEnter choose : ";
        getline(cin, choose);
        while (!tf.eof())
        {
            tf >> temp2;
            if (temp2 == choose)
            {
                getline(tf, temp2);
                cout << "\n\n\t\t\t" << choose << temp2 << endl;
                temp3 = temp2;
            }
        }

        tf.close();
    }
};

// Flght booking
class Booking : public Flight
{
    int c;
    int N;

public:
    void pnr_generater()
    {
        bf2.open("book.txt", ios::in);
        string str;
        c = 0;
        while (bf2.peek() != EOF)
        {
            getline(bf2, str);
            ++c;
        }

        bf2.close();
    }
    void book()
    {

        search(); // Call Search function
        pnr_generater();
        system("cls");
        cout << "\t\t\tEnter your full name : ";
        getline(cin, bk.full_name);

        cout << "\t\t\tEnter your age : ";
        cin >> bk.age;

        while (1)
        {
            char ch;
            cout << "\t\t\tEnter your gender ( M / F / O ) : ";
            cin >> ch;
            switch (ch)
            {
            case 'M':
                bk.gender = "Male";
                goto end;
                break;
            case 'F':
                bk.gender = "Female";
                goto end;
                break;
            case 'O':
                bk.gender = "Other";
                goto end;
                break;
            default:
                cout << "\t\t\t:( Enter Given charecter :(" << endl;
                break;
            }
        }
    end:
        cout << "\t\t\tEnter your full adress: ";
        cin.ignore();
        getline(cin, bk.adress);

        cout << "\t\t\tEnter your Aadhar No. : ";
        getline(cin, bk.aadhar);

        cout << "\t\t\tEnter your Pan No. : ";
        getline(cin, bk.pan_card);

        cout << "\t\t\tEnter your 10 digit mobile number : ";
        getline(cin, bk.mob);

        cout << "\n\t\t\tEnter Your regerbation date ( Travel date ) : ";

        getline(cin, bk.date);

        while (1)
        {
            cout << "\n\t\t\t-->For Bussness class press 1"
                 << "\n\t\t\t-->For General class press 2"
                 << "\n\t\t\tEnter your calss :";
            int num;
            cin >> num;
            switch (num)
            {
            case 1:
                bk.class_type = "Business Rs.9500 ";
                goto out;
                break;
            case 2:
                bk.class_type = "General Rs.6700";
                goto out;
            default:
                cout << "\t\t\t:( Enter Given charecter :(" << endl;
                break;
            }
        }
    out:
        bf << c << "\t"
           << pnr << c << "\t"
           << temp3 << "\t"
           << bk.full_name << " \t"
           << bk.age << " \t"
           << bk.gender << "\t"
           << bk.adress << " \t"
           << bk.aadhar << " \t"
           << bk.pan_card << "\t"
           << bk.mob << "\t"
           << bk.date << "\t" << bk.class_type << endl;
        cout << "Your PNR_No. : " << pnr << c << endl;
        getch();
        bf.close();
    }
};
// Print and Search Ticket
class print_ticket : public Booking
{
    string line;
    string temp_pnr;

public:
    void search_pnr()
    {

        cout << "Enter your PNR number : ";
        cin >> temp_pnr;

        pf.open("book.txt", ios::in);
        while (!pf.eof())
        {
            pf >> line;
            if (line == temp_pnr)
            {
                getline(pf, line);
                cout << endl
                     << temp_pnr << " \t" << line << endl;
                getch();
            }
        }
        pf.close();
    }
};
// ticket update and cancel
class Ticket_update : public print_ticket
{
    string line;
    string temp_pnr;
    int f, f2;

public:
    void ticketCancel()
    {
        f2 = 0;
        system("cls");
        pf.open("book.txt", ios::in);
        ptemp.open("Temp_book.txt", ios::out);
        // pf.open("book)
        cout << "Enter your PNR number : ";
        cin >> temp_pnr;

        if (pf.is_open())
        {
            while (!pf.eof())
            {
                getline(pf, line);
                if ((f = line.find(temp_pnr, 0)) != string::npos)
                {

                    f2 = 1;
                }
                else
                {
                    ptemp << line << endl;
                }
            }
        }
        if (f2 == 1)
        {
            system("cls");
            New(4);
            tab(5);
            cout << "Ticket Cancle Successfully...";
            getch();
        }
        else
        {
            system("cls");
            New(4);
            tab(5);
            cout << "Ticket Can't Found...";
            getch();
        }
        ptemp.close();
        pf.close();
        remove("book.txt");
        rename("Temp_book.txt", "book.txt");
    }
};

//  Main
class Main : virtual public Ticket_update
{
public:
    void Main2()
    {
        system("cls");
        while (1)
        {
            int ch;
            system("cls");
            char flight[] = "FLIGHT TICKET SYSTEM....";

            New(6);
            tab(8);
            for (int i = 0; i < sizeof(flight); i++)
            {
                _sleep(30);
                cout << flight[i];
            }
            cout << "\n\n\t\t\t1.Search Flight" << endl;
            cout << "\n\t\t\t2.Book Flight" << endl;
            cout << "\n\t\t\t3.Search Flight Ticket & Details " << endl;
            cout << "\n\t\t\t4.Flight Ticket Cancel" << endl;
            cout << "\n\t\t\t5.Close Program" << endl;
            cout << "\n\n\t\t\t\tEnter any One ... : ";
            cin >> ch;
            switch (ch)
            {
            case 1:
                search();
                break;
            case 2:
                book();
                break;
            case 3:
                search_pnr();
                break;
            case 4:
                ticketCancel();
                Main2();
                break;
            case 5:
                char d[30] = "Thank You...";
                char d2[50] = "For visiting our side..........";
                system("cls");
                New(15);
                tab(6);
                for (int i = 0; i < strlen(d); i++)
                {
                    _sleep(50);
                    cout << d[i];
                }
                New(2);
                tab(5);
                for (int i = 0; i < strlen(d2); i++)
                {
                    _sleep(50);
                    cout << d2[i];
                }
                New(10);
                exit(1);
                break;
            }
        }
    }
};
int main()
{
    char flight[] = "FLIGHT TICKET SYSTEM....";
    New(6);
    tab(8);
    cout << "Enter any key for start..." << endl;
    getch();
    system("cls");

    New(6);
    tab(8);
    for (int i = 0; i < sizeof(flight); i++)
    {
        _sleep(30);
        cout << flight[i];
    }
    getch();

    Main a;
    a.Main2();
    return 0;
}