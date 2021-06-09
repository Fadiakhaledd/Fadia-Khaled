/*
 Fadia Khaled Abd El-Hady - 20200371
 Habiba Yasser Saied - 20200147
 */

#include <iostream>

using namespace std;

double Rejected, Total; // two global values to be incremented while each fees calculation


    // Function [1]: A function to know how many days were spent and checks its validation
    int Spentdays ()
    {
        int days;
        cin >> days;
        while (days < 1)
            {
                cout << "Error! Please enter how many days were spent on the trip again: ";
                cin >> days;
        } // End of while loop

     return days;
    } // End of function [1]


     // Function [2]: A Function to take time of departing and checks its validity
    int DepartTime()
    {
        int depart;
        cin >> depart;
        while (depart > 23 || depart < 0)
            {
                cout << "Error! Please enter the departing time again: ";
                cin >> depart;
            } // End of while loop
        return depart;
    } // End of function [2]


    // Function [3]: A function to take time of arrival and checks its validity
    int ArriveTime ()
    {
        int arrive;
        cin >> arrive;
        while (arrive > 23 || arrive < 0)
        {
            cout << "Error! Please enter the arrival time again: ";
            cin >> arrive;
        } // End of while loop
        return arrive;

    } // End of function [3]


    // Function [4]: A function used if the user has traveled by plane to take the tickets cost
    void Plane ()
    {
        double cost;
        cout << "Enter how much did the plane tickets cost: ";
        cin >> cost;

        Total += cost; // Adding the plane tickets cost to the total expenses (Total) that has been declared as a global variable

    } // End of function [4]


    // Function [5]: a function used to calculate the parking fees in cases of Rented/Own car
     void ParkingFees(int &days)
     {
        double Parking;
        for (int i = 1; i <= days; i++)
        {
                cout << "Enter how much did parking cost in day [" << i << "]: ";
                cin >> Parking;

                while (Parking <= 0)
                 {
                     cout << "Error! Please enter a positive value for the money payed: ";
                     cin >> Parking;
                 } // End of while loop

                Total += Parking;
                if  (Parking > 25){
                    Rejected += Parking - 25;
                } // End of if statement
        } // End of for loop

     } // End of function [5]


    // Function [6]: a function used if the user has rented a car
    void RentedCar ()
    {
        double RCar;
        cout << "Enter how much have you payed for the rented car: ";
        cin >> RCar;

        while (RCar <= 0)
        {
            cout << "Error! Please enter a positive value for the money payed: ";
            cin >> RCar;
        } // end of while loop

        Total += RCar;
    } // End of function [6]


     // Function [7]: a function used if the user has used his own car to calculate the refund
     void OwnCar ()
     {
         double distance;
         cout << "Enter the distance you have traveled in km: ";
                 cin >> distance;

                 while (distance <= 0)
                 {
                     cout << "Error! Please enter a positive value for the distance: ";
                     cin >> distance;
                 } // end of while loop

        Total += distance*0.775;
     } // End of function [7]


     // Function [8]: a function used if the employee has taken a taxi
     void Taxis (int &days)
     {
         double TaxisMoney;
         int numberofTaxis;
         cout << "Enter how many days have you took a taxis: ";
         cin >> numberofTaxis;

         for (int i = 1; i <= numberofTaxis; i++)
            {
                cout << "Enter how much did you pay for taxi [" << i << "]: ";
                cin >> TaxisMoney;

                while (TaxisMoney <= 0)
                 {
                     cout << "Error! Please enter a positive value for the money payed: ";
                     cin >> TaxisMoney;
                 } // End of while loop

                Total += TaxisMoney;
                if  (TaxisMoney > 100 )
                    Rejected += TaxisMoney - 100;
            } // End of for loop

    } // End of Function [8]


    // Function [9]: a function used if the employee has attended any conference or seminar
    void conference()
    {
        int NOCS; // Number of conference or seminar
        double CSfees; // Conference or seminar fees
        cout << "Enter how many conferences and seminars have you attended: ";
        cin >> NOCS;

        while (NOCS <= 0)
            {
                cout << "Error! Please enter a positive value: ";
                cin >> NOCS;

            } // End of while loop

        for (int i=1; i <= NOCS; i++)
        {
            cout << "Enter the fees of conference or seminar [" << i << "]: ";
            cin >> CSfees;
            while (CSfees <= 0)
                {
                     cout << "Error! Please enter a positive value for the money payed: ";
                     cin >> CSfees;

            } // End of while loop

            Total += CSfees;
        } // End of for loop

    } // End of function [9]


    // Function [10]: a function to calculate the accommodation rejected/refund fees
    void accommodation (int days)
    {
        int Acost; // accommodation cost
        int Adays = days; // number of accommodation days are equal to the spent days

        for (int i = 1; i <= Adays; i++)
        {
            cout << "Enter the accommodation of day [" << i << "] cost: ";
            cin >> Acost;

            while (Acost <= 0)
                {
                    cout << "Error! Please enter a positive value for the money payed: ";
                    cin >> Acost;
                    } // End of while loop

            Total += Acost;
            if (Acost > 500)
                {
                    Rejected += Acost - 500;
                    }// End of if statement
        } // End of for loop

    } // End of function [10]



    // The next 5 functions are used to calculate the cost of meals

    int Breakfast, Lunch, Dinner;
    // Three global values to be used in the functions that calculate meals costs

    // Function [11]: a function to calculate the missed meals of the first day according to departing time
    void FirstDay (int departing, int days)
    {
        // As each day has a breakfast, lunch and dinner. so the number of meals is equal to number of spent days
        Breakfast = days;
        Lunch = days;
        Dinner = days;

        // from 12 am of the first day till before 8 am of the first day the 3 meals are allowed and nothing is missed

         /* First condition: If the employee departed from 8 am till before 12 pm
            the breakfast would not be available anymore, but the lunch and the
            dinner are still allowed */

         if (departing >= 8 && departing < 12)
         {
             Breakfast -= 1; // first breakfast is missed, (days-1) breakfasts are left
         }

         /* Second condition: If the employee departed from 12 pm till before 6 pm (18 at 24-hours format)
            the breakfast and lunch would not be available anymore, but the dinner is still allowed */
         else if (departing >= 12 && departing < 18)
         {
             Breakfast -= 1; // first breakfast is missed, (days-1) breakfasts are left
             Lunch -= 1; // first lunch is missed, (days-1) lunches are left
         }

         /* Third condition: If the employee departed from 6 pm (18 at 24-hours format) till
         11 pm (23 at 24-hours format) the breakfast, lunch and dinner would not be available anymore */
         else if (departing >= 18 && departing <= 23 )
         {
             Breakfast -= 1; // first breakfast is missed, (days-1) breakfasts are left
             Lunch -= 1; // first lunch is missed, (days-1) lunches are left
             Dinner -= 1; // first dinner is missed, (days-1) dinners are left
         }
         // after 12 am till before 8 am it is considered as the second spent day.

    } // End of Function [11]


    // Function [12]: a function to calculate the missed meals of the last day according to arrival time
    void Lastday(int arrival)
    {

        /* First condition: if the employee arrived from 12 am (0 at 24-hours format)
         till 9 am the breakfast, lunch, and dinner would not be allowed */
         if (arrival > 0 && arrival <= 9)
         {
             Breakfast -= 1;
             Lunch -=1;
             Dinner -= 1;
         }

        /* Second condition: if the employee arrived from 9 am till 1 pm (13 at 24-hours format)
           the lunch and dinner would not be allowed, but he will take his breakfast for the last day */
           if (arrival > 9 && arrival <= 13)
           {
               Lunch -= 1;
               Dinner -=1;
           }

        /* Third condition: if the employee arrived from 1 pm (13 at 24-hours format) till
           7 pm (19 at 24-hours format) only the dinner would not be allowed and he will take
           the breakfast and lunch for the last day */
           if (arrival > 13 && arrival <= 19)
           {
               Dinner -= 1;
           }

       // after 7 pm (19 at 24-hours format) till 11 pm (23 at 24-hours format) the 3 meals would be allowed

    } // End of Function [12]


    // Function [13]: a function that calculates breakfast rejected/total costs for each breakfast meal
    void BreakfastCost ()
    {
        int Bcost;

        for (int i=1; i <= Breakfast; i++)
        {
            cout << "Enter breakfast [" << i << "] cost: ";
            cin >> Bcost;

            Total += Bcost;

            while (Bcost <= 0)
            {
                cout << "Error! Please enter a positive value for the money payed: ";
                cin >> Bcost;
            } // End of while loop

            if (Bcost > 40)
                {
                Rejected += Bcost - 40;
                }

        } // End of for loop

    } // End of Function [13]


    // Function [14]: a function that calculates lunch rejected/total costs for each lunch meal
    void LunchCost ()
    {
        int Lcost;

        for (int i=1; i <= Lunch; i++)
        {
            cout << "Enter lunch [" << i << "] cost: ";
            cin >> Lcost;

            while (Lcost <= 0)
            {
                cout << "Error! Please enter a positive value for the money payed: ";
                cin >> Lcost;
            } // End of while loop

            if (Lcost > 60)
                {
                Rejected += Lcost - 60;
                }

            Total += Lcost;
            } // End of for loop

    } // End of Function [14]


    // Function [15]: a function that calculates dinner rejected/total costs for dinner meal
    void DinnerCost ()
    {
        int Dcost;
        for (int i=1; i <= Dinner; i++)
        {
            cout << "Enter dinner [" << i << "] cost: ";
            cin >> Dcost;

            while (Dcost <= 0)
            {
                cout << "Error! Please enter a positive value for the money payed: ";
                cin >> Dcost;
            } // End of while loop

            if (Dcost > 80)
            {
                Rejected += Dcost - 80;
            }

            Total += Dcost;
            } // End of for loop

    } // End of Function [15]


int main()
{
    cout << "How many days were spent on the trip? ";
    int days = Spentdays();

    cout << "\nEnter the departing time in 24-format: ";
    int Depart = DepartTime();

    cout << "Enter the arrival time in 24-format: ";
    int Arrive = ArriveTime();

    //   ______________________ Transportation fees ______________________

    /* The program at this part is supposed to ask the user every time if he used a specific
      transportation or not. If he answered "yes" (Y || y) other details would be asked such as
      the tickets cost, Rented car payment, Benzene cost for his own car, Parking fees, Taxis fees
       and for each one a function was created. If he answered "no (N || n)" this transportation
       details would be skipped and the following one would be checked */

    char ans; // a character used for yes or no questions

    // 1- Checking if the employee traveled by plane
    cout << "\nHave you traveled by plane (Y/N)? ";
    cin >> ans;

    while (ans != 'Y' && ans != 'y' && ans != 'n' && ans != 'N')
    {
        cout << "Error! Invalid answer, please enter (Y/N): ";
        cin >> ans;
    } // While loop

    if (ans == 'Y' || ans == 'y')
        Plane();


    // 2- Checking if the employee used a rented car
    cout << "\nHave you rented a car (Y/N)? ";
    cin >> ans;

    while (ans != 'Y' && ans != 'y' && ans != 'n' && ans != 'N')
    {
        cout << "Error! Invalid answer, please enter (Y/N): ";
        cin >> ans;
    } // While loop

    if (ans == 'Y' || ans == 'y'){
        RentedCar();
        ParkingFees(days);
        } // If statement


    // 3- Checking if the employee used his own car
     cout << "\nHave you used your own car (Y/N)?  ";
     cin >> ans;

    while (ans != 'Y' && ans != 'y' && ans != 'n' && ans != 'N')
        {
            cout << "Error! Invalid answer, please enter (Y/N): ";
            cin >> ans;
        } // While loop

    if (ans == 'Y' || ans == 'y')
        {
        OwnCar();
        ParkingFees(days);
        } // If condition


    // 4- Checking if the employee used a Taxi
    cout << "\nHave you used any taxis (Y/N)? ";
    cin >> ans;

    while (ans != 'Y' && ans != 'y' && ans != 'n' && ans != 'N')
        {
            cout << "Error! Invalid answer, please enter (Y/N): ";
            cin >> ans;
          } // While loop

    if (ans == 'Y' || ans == 'y')
        Taxis(days);

    //  ______________________ End of Transportation fees ______________________


    // Entry fees to any conference or seminar
    cout << "\nHave you attended any conference or seminar (Y/N)? ";
    cin >> ans;
    while (ans != 'Y' && ans != 'y' && ans != 'n' && ans != 'N')
    {
        cout << "Error! Invalid answer, please enter (Y/N): ";
        cin >> ans;
    } // While loop

    if (ans == 'Y' || ans == 'y')
        conference();

    // Entry of Accommodation fees
    cout << endl;
    accommodation(days);

    //____________________The Cost of each meal ____________________

    FirstDay(Depart, days);
    Lastday(Arrive);
    cout << endl;
    BreakfastCost();
    cout << endl;
    LunchCost();
    cout << endl;
    DinnerCost();

    // Displaying the final results
    cout << "\nTotal expenses: " << Total << " EGP" << endl;
    cout << "Rejected expenses: " << Rejected << " EGP" << endl;
    cout << "Refund: " << Total - Rejected << " EGP" << endl;

    return 0;
}
