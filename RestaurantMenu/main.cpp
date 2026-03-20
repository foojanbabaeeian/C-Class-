#include <iomanip>
#include <fstream>
#include <string>
#include <iostream>
#include "food.h"

using namespace std;
void food::show()
{
	cout<<"\n\n\n\n\tfood INFORMATION\n";
	cout<<"\t------------------------------------\n";
    cout<<"\n\tfood-name: "<<name<<"\n";
	cout<<"\n\tfood-price: "<<price<<"\n";
	cout<<"\n\tquantity of food: "<<quantity<<"\n";
	cout<<"\n\tingredients: "<<ingredients<<"\n";
	cout<<"\n\tcalorie of food: "<<calories<<"\n";
	cout<<"\n\tWeek day of order: "<<day<<"\n";
	cout<<"\n\tTime of food's arrival:  "<<time<<"\n";
	cout<<"\n\t------------------------------------\n\t";
}

void food::add() {
    food c;

    fstream fp("foods.dat", ios::out | ios::in | ios::binary);
    if (!fp) {
        ofstream fp1("foods.dat", ios::out | ios::binary);
        fp1.close();
    }

    ifstream inj("j.txt", ios::in);
    if (!inj) {
        ofstream outj("j.txt", ios::out);
        int tempJ = 0;
        outj << tempJ;
        outj.close();
    }

    system("cls");
    cout << "\n\n\n\n\tADD food\n";
    cout << "\t----------------------------------\n";
    cout << "\n\tEnter food-name: ";
    cin >> c.name;
    cout << "\n\tEnter food-price: ";
    cin >> c.price;
    cout << "\n\tEnter quantity of food (1, 2, 3 Or 4?) : ";
    cin >> c.quantity;
    cout << "\n\tEnter ingredients of food: ";
    cin >> c.ingredients;
    cout << "\n\tEnter calories of food: ";
    cin >> c.calories;
    cout << "\n\tEnter week day of order (Sun, Mon, Tue, Wed, Thu, Fri or Sat?) : ";
    cin >> c.day;
    cout << "\n\tEnter time of food's preparation (by minute) : ";
    cin >> c.time;
    cout << "\n\tEnter number of class: ";

    system("cls");
    cout << "\n\n\n\n\tRecord has been created successfully!";
    c.show();

    ifstream inj1("j.txt", ios::in);
    inj1 >> j;

    c.j = j;
    j++;

    ofstream outj1("j.txt", ios::out);
    outj1 << j;

    fstream fp1("foods.dat", ios::out | ios::in | ios::binary);
    fp1.seekp(sizeof(food) * (c.j), ios::beg);
    fp1.write((char *) &c, sizeof(food));
    fp1.close();
}

    void food::search() {
        system("cls");
        int temp = 0;
        food c;

        cout << "\n\n\n\n\tEnter food-number to find: ";
        string tempFoodName;
        cin >> tempFoodName;

        fstream fp("foods.dat", ios::out | ios::in | ios::binary);
        fp.read((char *) &c, sizeof(food));
        while (fp && !fp.eof()) //while (fp is created) && (it's not end of fp)
        {
            if (tempFoodName == c.name) {
                c.show();

                temp++;
            }

            fp.read((char *) &c, sizeof(food));
        }

        if (temp == 0) { cout << "\n\tThere is no food with this number!\n\t"; }
    }

void food::displayAll()
{
	system("cls");
	cout<<"\n  name      price   quantity   ingredients     calories     day      time     remain-capacity  class-num";
	cout<<"================================================================================";
	
	food c;
	

	fstream fp("foods.dat" , ios::out|ios::in|ios::binary);
	fp.read( (char *)&c , sizeof(food) );
	while( fp && !fp.eof() ) //while (fp is created) && (it's not end of fp)
	{

			cout<<left<<setw(8)<<c.name;
			cout<<setw(10)<<c.price;
			cout<<setw(6)<<c.quantity;
			cout<<setw(12)<<c.ingredients;
			cout<<setw(6)<<c.day;
			cout<<setw(18)<<c.time;

			cout<<"\n--------------------------------------------------------------------------------";


		fp.read( (char *)&c , sizeof(food) ); //read next from file
	}

}


void person::show()
{
	cout<<"\n\n\n\n\tperson INFORMATION\n";
	cout<<"\t------------------------------------\n";
	cout<<"\n\tperson-number: "<<num<<endl;
	cout<<"\n\tFirst-name: "<<firstName<<endl;
	cout<<"\n\tLast-name: "<<lastName<<endl;
	cout<<"\n\tpayments: "<<payments<<endl;
	cout<<"\n\tTaken-foods: "<<foodTaken<<endl;
	cout<<"\n\tId: "<<Id<<endl;
	cout<<"\n\t------------------------------------\n\t";
}
void person::add()
{
	person s;
	
	fstream fp("persons.dat" , ios::out|ios::in|ios::binary);
	if(!fp) //create file if it's not created before
	{
		ofstream fp1("persons.dat" , ios::out|ios::binary);
		fp1.close();
	}

	ifstream ini("i.txt" , ios::in);
	if(!ini) //create file if it's not created before
	{
		ofstream outi("i.txt" , ios::out);
		long tempI=0;
		outi<<tempI;
		outi.close();
	}


	system("cls");
	cout<<"\n\n\n\n\tADD person\n";
	cout<<"\t----------------------------------\n";
	cout<<"\n\tEnter person-number: ";
	cin>>s.num;
	cout<<"\n\tEnter first-name: ";
	cin>>s.firstName;
	cout<<"\n\tEnter last-name: ";
	cin>>s.lastName;
	cout<<"\n\tEnter phone number: ";
	cin>>s.Id;
	s.foodTaken=0;

	

	system("cls");
	cout<<"\n\n\n\n\tRecord has been created successfully!";
	s.show();;

	ifstream ini1("i.txt" , ios::in); 
	ini1>>i;

	s.i=i;
	i++;

	ofstream outi1("i.txt" , ios::out);
	outi1<<i;


	fstream fp1("persons.dat" , ios::out|ios::in|ios::binary);
	fp1.seekp( sizeof(person)*(s.i) , ios::beg);
	fp1.write( (char *)&s , sizeof(person) );
	fp1.close();
}

void person::search()
{
	system("cls");
	int temp=0;
	person s;

	cout<<"\n\n\n\n\tEnter person-number to find: ";
	long tempPersonNum; cin>>tempPersonNum;

	fstream fp("persons.dat" , ios::out|ios::in|ios::binary);
	fp.read( (char *)&s , sizeof(person) );
	while( fp && !fp.eof() ) //while (fp is created) && (it's not end of fp)
	{
		if ( tempPersonNum == s.num )
		{



				s.show();
				temp++; 

		}

		fp.read( (char *)&s , sizeof(person) );
	}

	if ( temp == 0 ) { cout<<"\n\tThere is no person with this number!\n\t"; };
}

void person::displayAll()
{
	system("cls");
	cout<<"\n  number    first-name  last-name    payments  taken-foods \n";
	cout<<"  =============================================================================\n";
	
	person s;
	
	//read all records from file
	fstream fp("persons.dat" , ios::out|ios::in|ios::binary);
	fp.read( (char *)&s , sizeof(person) );
	while( fp && !fp.eof() ) //while (fp is created) && (it's not end of fp)
	{

			cout<<"  "<<left<<setw(10)<<s.num;
			cout<<setw(12)<<s.firstName;
			cout<<setw(14)<<s.lastName;
			cout<<setw(14)<<s.payments;
			cout<<setw(15)<<s.foodTaken;
			cout<<"\n  -----------------------------------------------------------------------------\n";

		fp.read( (char *)&s , sizeof(person) ); //read next from file
	}

	cout<<"  ";;
}

class selectfood
{
	person per;
	food foods;
	int  k;
public:
	void add();
	void Delete();
	void reportBypersonNum();
	void reportByFoodName();
	friend class food;
	friend class person;
};

void selectfood::add()
{
	system("cls");
	int sTemp=0;
	person s;

	cout<<"\n\n\n\n\tEnter person-number to add Select-food: ";
	long tempPersonNum; cin>>tempPersonNum;

	fstream fp("persons.dat" , ios::out|ios::in|ios::binary);
	fp.read( (char *)&s , sizeof(person) );
	while( fp && !fp.eof() ) //while (fp is created) && (it's not end of fp)
	{
		if ( tempPersonNum == s.num )
		{
					s.show();;

					int cTemp=0;
					food c;

					cout<<"\n\n\n\n\tEnter food-number to select: ";
					string tempFoodName; cin>>tempFoodName;

					fstream fp1("foods.dat" , ios::out|ios::in|ios::binary);
					fp1.read( (char *)&c , sizeof(food) );
					while( fp1 && !fp1.eof() ) //while (fp1 is created) && (it's not end of fp1)
					{
						if ( tempFoodName == c.name )
						{
										c.show();;

							            ////////////////////////////////////////////////////////////////////
							            //-----save person new informations-----
							            fstream fp5("persons.dat" , ios::out|ios::in|ios::binary);
							            fp5.seekp( sizeof(person)*(s.i) , ios::beg);
							            fp5.write( (char *)&s , sizeof(person) );
							            fp5.close();


							            //-----save food new informations-----
							            fstream fp6("foods.dat" , ios::out|ios::in|ios::binary);
							            fp6.seekp( sizeof(food)*(c.j) , ios::beg);
							            fp6.write( (char *)&c , sizeof(food) );
							            fp6.close();

							            selectfood select;
							            select.per=s;  //step1
							            select.foods=c; //step2

							            ifstream ink("k.txt" , ios::in);
							            if(!ink) //create file if it's not created before
										{
											ofstream outk("k.txt" , ios::out);
								            int tempK=0;
								            outk<<tempK;
								            outk.close();
										}

										ifstream ink1("k.txt" , ios::in); 
							            ink1>>k;
				
							            select.k=k; //step4
							            k++;

							            ofstream outk1("k.txt" , ios::out);
							            outk1<<k;
							            outk1.close();
							
							            fstream fp3("selectfoods.dat" , ios::out|ios::in|ios::binary);
							            if(!fp3) //create file if it's not created before
							            {
											ofstream fp4("selectfoods.dat" , ios::out|ios::binary);
								            fp4.close();
										}

							            fstream fp2("selectfoods.dat" , ios::out|ios::in|ios::binary);
							            fp2.seekp( sizeof(selectfood)*(select.k) , ios::beg);
							            fp2.write( (char *)&select , sizeof(selectfood) );
							            fp2.close();
				
							            cout<<"\n\tSelect-food is succsessfully done!\n\t";;
							            ////////////////////////////////////////////////////////////////////
										
										cTemp++;
						}
						fp1.read( (char *)&c , sizeof(food) );
					}

					if ( cTemp == 0 ) { cout<<"\n\tThere is no food with this number!\n\t";; }


                }
				else { cout<<"\n\n\tThis person can't select any more foods!\n\tTo add more foods, you must first delete some old foods!\n\t ";; }

				sTemp++;


		fp.read( (char *)&s , sizeof(person) );
    }

	if ( sTemp == 0 ) { cout<<"\n\tThere is no person with this number!\n\t";; }
}

void selectfood::reportBypersonNum() {
    system("cls");
    int sTemp = 0;
    person s;

    cout << "\n\n\n\n\tEnter person-number to report: ";
    long tempperNum;
    cin >> tempperNum;

    fstream fp("persons.dat", ios::out | ios::in | ios::binary);
    fp.read((char *) &s, sizeof(person));
    while (fp && !fp.eof())
    {
        if (tempperNum == s.num) {


            cout << "\n\n\n\n\tperson INFORMATION\n";
            cout << "\t------------------------------------\n";
            cout << "\n\tperson-number: " << s.num << endl;
            cout << "\n\tFirst-name: " << s.firstName << endl;
            cout << "\n\tLast-name: " << s.lastName << endl;
            cout << "\n\tpayments: " << s.payments << endl;
            cout << "\n\tTaken-foods: " << s.foodTaken << endl;
            cout << "\n\tId: " << s.Id << endl;
            cout << "\n\t------------------------------------\n\t";
            cout << "\nnumber  first-name      lastname    payments      takenFoods    Id";
            cout << "================================================================================";

            sTemp++;
        }

        //read next from file
        fp.read((char *) &s, sizeof(person));
    } //end while

    if (sTemp == 0) { cout << "\n\tThere is no person with this number!\n\t"; }


    int selectTemp = 0;
    selectfood select;

    fstream fp1("selectfoods.dat", ios::out | ios::in | ios::binary);
    fp1.read((char *) &select, sizeof(selectfood));
    while (fp1 && !fp1.eof()) //while (fp1 is created) && (it's not end of fp1)
    {
        if (tempperNum == select.per.num) {


            cout << setw(10) << select.foods.name;
            cout << left << setw(8) << select.foods.price;
            cout << setw(6) << select.foods.quantity;
            cout << setw(12) << select.foods.ingredients;
            cout << setw(6) << select.foods.day;
            cout << setw(6) << select.foods.calories;
            cout << setw(18) << select.foods.time;


            cout << "\n--------------------------------------------------------------------------------";

            selectTemp++;


            fp1.read((char *) &select, sizeof(selectfood));
        } //end while
        ;
        if (selectTemp == 0) {
            cout << "\n\tThere is no food for this person!\n\t";;
        }
    }

    }
    void selectfood::reportByFoodName() {
        system("cls");
        int cTemp = 0;
        food c;

        cout << "\n\n\n\n\tEnter food-name to report: ";
        string tempFoodName;
        cin >> tempFoodName;

        fstream fp("foods.dat", ios::out | ios::in | ios::binary);
        fp.read((char *) &c, sizeof(food));
        while (fp && !fp.eof()) //while (fp is created) && (it's not end of fp)
        {
            if (tempFoodName == c.name) {
                //----------display food----------
                cout << "\n\n\n\n\tfood INFORMATION\n";
                cout << "\t------------------------------------\n";
                cout << "\n\tfood-name: " << c.name << "\n";
                cout << "\n\tfood-price: " << c.price << "\n";
                cout << "\n\tquantity of food: " << c.quantity << "\n";
                cout << "\n\tingredients: " << c.ingredients << "\n";
                cout << "\n\tcalorie of food: " << c.calories << "\n";
                cout << "\n\tWeek day of order: " << c.day << "\n";
                cout << "\n\tTime of food's arrival:  " << c.time << "\n";
                cout << "\n\t------------------------------------\n\t";
                cout << "\n\t------------------------------------\n\n\n";
                cout << "\n  number    first-name  last-name     last-average  food-limit\n";
                cout << "  ==============================================================\n";

                cTemp++;

                fp.read((char *) &c, sizeof(food));
            } //end while

            if (cTemp == 0) { cout << "\n\tThere is no food with this number!\n\t"; }


            int selectTemp = 0;
            selectfood select;

            fstream fp1("selectfoods.dat", ios::out | ios::in | ios::binary);
            fp1.read((char *) &select, sizeof(selectfood));
            while (fp1 && !fp1.eof()) {
                if (tempFoodName == select.foods.name) {
                    cout << "  " << left << setw(10) << select.per.num;
                    cout << setw(12) << select.per.firstName;
                    cout << setw(14) << select.per.lastName;
                    cout << setw(14) << select.per.Id;
                    cout << setw(14) << select.per.payments;
                    cout << select.per.foodTaken;
                    cout << "\n  --------------------------------------------------------------\n";

                    selectTemp++;


                    fp1.read((char *) &select, sizeof(selectfood));
                };
                if (selectTemp == 0) {
                    cout << "\n\tThere is no person for this food!\n\t";;
                }
            }

        }
    }
        void selectfood::Delete() {
            system("cls");
            cout << "\n\n\n\n\tEnter person-number to delete its select-food: ";
            long tempperNum;
            cin >> tempperNum;
            cout << "\n\n\tEnter number of select-food you want to delete: ";
            string tempFoodName;
            cin >> tempFoodName;

            int selectTemp = 0;
            selectfood select;

            fstream fp("selectfoods.dat", ios::out | ios::in | ios::binary);
            fp.read((char *) &select, sizeof(selectfood));
            while (fp && !fp.eof()) //while (fp is created) && (it's not end of fp)
            {
                if (tempperNum == select.per.num) {
                    if (tempFoodName == select.foods.name) {


                        fstream fp1("selectfoods.dat", ios::out | ios::in | ios::binary);
                        fp1.seekp(sizeof(selectfood) * (select.k), ios::beg);
                        fp1.write((char *) &select, sizeof(selectfood));
                        fp1.close();

                        cout << "\n\n\n\tSelect-food is succsessfully deleted!\n\t";;

                        selectTemp++;

                    }
                }
            }

            fp.read((char *) &select, sizeof(selectfood));
            if (selectTemp == 0) {
                cout << "\n\n\n\tThere is no select-food for this person!\n\t";;
            }

            food c;

            fstream fp2("foods.dat", ios::out | ios::in | ios::binary);
            fp2.read((char *) &c, sizeof(food));
            while (fp2 && !fp2.eof()) {
                if (tempFoodName == c.name) {


                    fstream fp3("foods.dat", ios::out | ios::in | ios::binary);
                    fp3.seekp(sizeof(food) * (c.j), ios::beg);
                    fp3.write((char *) &c, sizeof(food));
                    fp3.close();

                }

                fp2.read((char *) &c, sizeof(food));
            }
            person s;

            fstream fp4("persons.dat", ios::out | ios::in | ios::binary);
            fp4.read((char *) &s, sizeof(person));
            while (fp4 && !fp4.eof()) {
                if (tempperNum == s.num) {
                    if (s.foodTaken != 0) {

                        food c1;

                        fstream fp5("foods.dat", ios::out | ios::in | ios::binary);
                        fp5.read((char *) &c1, sizeof(food));
                        while (fp5 && !fp5.eof()) {
                            if (tempFoodName == c1.name) {


                                fstream fp6("persons.dat", ios::out | ios::in | ios::binary);
                                fp6.seekp(sizeof(person) * (s.i), ios::beg);
                                fp6.write((char *) &s, sizeof(person));
                                fp6.close();

                            }
                        }


                        fp5.read((char *) &c1, sizeof(food));
                    }

                }
                fp4.read((char *) &s, sizeof(person));
            }

        }
        void food::Delete() {
            system("cls");

            int temp = 0;
            food c;

            cout << "\n\n\n\n\tEnter food-number to delete: ";
            string tempFoodName;
            cin >> tempFoodName;

            fstream fp("foods.dat", ios::out | ios::in | ios::binary);
            fp.read((char *) &c, sizeof(food));
            while (fp && !fp.eof()) {
                if (tempFoodName == c.name) {

                    c.show();


                    fstream fp1("foods.dat", ios::out | ios::in | ios::binary);
                    fp1.seekp(sizeof(food) * (c.j), ios::beg);
                    fp1.write((char *) &c, sizeof(food));
                    fp1.close();

                    temp++;
                    cout << "\n\tThe food has been successfully deleted!\n\t";
                }
            }


            fp.read((char *) &c, sizeof(food));

            if (temp == 0) { cout << "\n\tThere is no food with this number!\n\t"; };


            selectfood select;

            fstream fp2("selectfoods.dat", ios::out | ios::in | ios::binary);
            fp2.read((char *) &select, sizeof(selectfood));
            while (fp2 && !fp2.eof()) {
                if (tempFoodName == select.foods.name) {

                    fstream fp3("selectfoods.dat", ios::out | ios::in | ios::binary);
                    fp3.seekp(sizeof(selectfood) * (select.k), ios::beg);
                    fp3.write((char *) &select, sizeof(selectfood));
                    fp3.close();

                    person s;
                    fstream fp4("persons.dat", ios::out | ios::in | ios::binary);
                    fp4.read((char *) &s, sizeof(person));
                    while (fp4 && !fp4.eof()) {
                        if (select.per.num == s.num) {

                            fstream fp5("persons.dat", ios::out | ios::in | ios::binary);
                            fp5.seekp(sizeof(person) * (s.i), ios::beg);
                            fp5.write((char *) &s, sizeof(person));
                            fp5.close();

                        }
                    }

                    fp4.read((char *) &s, sizeof(person));
                }

            }

            fp2.read((char *) &select, sizeof(selectfood));

        }

        void person::Delete() {
            system("cls");

            int temp = 0;
            person s;

            cout << "\n\n\n\n\tEnter person-number to delete: ";
            long tempperNum;
            cin >> tempperNum;

            fstream fp("persons.dat", ios::out | ios::in | ios::binary);
            fp.read((char *) &s, sizeof(person));
            while (fp && !fp.eof()) {
                if (tempperNum == s.num) {


                    s.show();

                    fstream fp1("persons.dat", ios::out | ios::in | ios::binary);
                    fp1.seekp(sizeof(person) * (s.i), ios::beg);
                    fp1.write((char *) &s, sizeof(person));
                    fp1.close();

                    temp++;
                    cout << "\n\tThe person has been successfully deleted!\n\t";
                }
            }

            fp.read((char *) &s, sizeof(person));


            if (temp == 0) { cout << "\n\tThere is no person with this number!\n\t"; };

            selectfood select;

            fstream fp2("selectfoods.dat", ios::out | ios::in | ios::binary);
            fp2.read((char *) &select, sizeof(selectfood));
            while (fp2 && !fp2.eof()) {
                if (tempperNum == select.per.num) {

                    fstream fp3("selectfoods.dat", ios::out | ios::in | ios::binary);
                    fp3.seekp(sizeof(selectfood) * (select.k), ios::beg);
                    fp3.write((char *) &select, sizeof(selectfood));
                    fp3.close();

                    food c;
                    fstream fp4("foods.dat", ios::out | ios::in | ios::binary);
                    fp4.read((char *) &c, sizeof(food));
                    while (fp4 && !fp4.eof())

                        if (select.foods.name == c.name) {


                            fstream fp5("foods.dat", ios::out | ios::in | ios::binary);
                            fp5.seekp(sizeof(food) * (c.j), ios::beg);
                            fp5.write((char *) &c, sizeof(food));
                            fp5.close();

                        }
                fp4.read((char *) &s, sizeof(person));
            }
        }

            fp2.read((char *) &select, sizeof(selectfood));
}

int main()
{
	system("cls");
	cout<<"\n\n\n\n\t                 WELCOME TO SELECT-food SYSTEM!\n\n\t\n\t";;
	system("cls");
	person s;
	food c;
	selectfood select;
	int back=1;
	while (back != 0)
	{
		system("cls");
		cout<<"\n\n\t                        MAIN MENU\n";
		cout<<"\t--------------------------------------------------------\n\n";
		cout<<"\t1.Add person                   5.Add food\n";
		cout<<"\t2.Delete person                6.Delete food\n";
		cout<<"\t3.Search person                7.Search food\n";
		cout<<"\t4.Display all persons          8.Display all foods\n\n\n";
	
		cout<<"\t                 9.Add Select-food\n";
		cout<<"\t                10.Delete Select-food\n\n";

		cout<<"\t                11.Report persons of a food\n";
		cout<<"\t                12.Report foods of a person\n";
		
		cout<<"\n\t                13.Exit\n\n";
		cout<<"\t---------------------------------------------------------\n";
		cout<<"\t                Enter a number (1-13) : ";
		int n; cin>>n;

		switch (n)
		{
		case 1: s.add(); break;
		case 2: s.Delete(); break;
		case 3: s.search(); break;
		case 4: s.displayAll(); break;

		case 5: c.add(); break;
		case 6: c.Delete(); break;
		case 7: c.search(); break;
		case 8: c.displayAll(); break;

		case 9: select.add(); break;
		case 10: select.Delete(); break;
		case 11: select.reportByFoodName(); break;
		case 12: select.reportBypersonNum(); break;

		case 13: back=0; break;
		default: system("cls"); cout<<"\n\n\n\n\tError!\n\tEnter any key to back...\n\t";
		}
	}
}
