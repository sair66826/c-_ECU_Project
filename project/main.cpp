 #include<memory>
 #include<ctime>
 #include<iostream>
 #include"ecu_communication.h"
#include<limits>
 using namespace std;

int main(){
     srand(time(nullptr));

    unique_ptr<ecu_communication> current_arch = nullptr;

    while(true){

        cout << "\n=================================\n";
        cout << VIOLET<<"        MAIN SYSTEM MENU\n"<<RESET;
        cout << "=================================\n";
        cout << "1) Create New Architecture\n";
        cout << "2) Copy Existing Architecture\n";
        cout << "3) Exit\n"<<endl;
        cout << BLUE<<"Select option: "<<RESET;

        int ch;
        cin >> ch;

        switch(ch){

        // CREATE NEW
        case 1:
        {
            current_arch = make_unique<ecu_communication>();
            break;
        }
        // COPY EXISTING
        case 2:
        {
            if(!current_arch){                                       
                cout <<RED<< "No architecture exists to copy.\n"<<RESET;
                break;
            }

            ecu_communication copied(*current_arch);  //we are not copying unique_ptr copying only object point to it so no error
            break;
        }
        // EXIT
        case 3:
            return 0;

        default:
            cout <<RED<< "Invalid choice.\n"<<RESET;
        }
    }

    return 0;
}
