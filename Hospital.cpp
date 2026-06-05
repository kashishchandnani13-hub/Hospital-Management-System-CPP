#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Patient
{
    public:
    string name , dept , gender;
    int age , id;
    
    void input(){
        cout<<"Enter Patient ID : ";
        cin>>id;
        cin.ignore();
        cout<<"Enter Patient name : ";
        getline(cin , name);
        cout<<"Enter Age : ";
        cin>>age;
        cin.ignore();
        cout<<"Enter Gender : ";
        getline(cin , gender);
        cout<<"Enter department to consult (e.g., Cardiology, Neurology, Orthopedics, Pediatrics, General Medicine, Surgery, Emergency) : ";
        getline(cin , dept);
    }

    void display() const{
        cout<<"Patient's details :-";
        cout<<"\nID: "<<id;
        cout<<"\nName: "<<name;
        cout<<"\nAge: "<<age;
        cout<<"\nGender: "<<gender;
        cout<<"\nDepartment: "<<dept<<endl;
    }
};

class Hospital_Management
{
    vector<Patient> patients;

    public:
        void addPatient(){
            Patient p;
            p.input();
            patients.push_back(p);
            cout<<"Patient added successfully!\n";
        }

        void viewPatient() const{
            if(patients.empty()){
                cout<<"No patient records found!!\n";
                return;
            }
            for(const auto& p : patients){
                cout<<"----------\n";
                p.display();
            }
        }

        void searchPatient() const{
            int id;
            cout<<"Enter patient's ID to search : ";
            cin >> id;
            for(const auto& p : patients){
                if(p.id == id){
                    cout<<"Patient found...\n";
                    p.display();
                    return;
                }
            }
            cout<<"Patient not found !!!\n";
        }

        void deletePatient(){
            int id;
            cout<<"Enter patient's ID to delete : ";
            cin >> id;
            for (int i = 0; i < patients.size(); i++) {
                if (patients[i].id == id) {
                    patients.erase(patients.begin() + i);
                    cout << "Patient record deleted successfully!!\n";
                    return;
                }
            }
            cout << "Patient not found !!!\n";
        }

        void showMenu() const{
            cout<< "=====HOSPITAL MANAGEMENT SYSTEM=====\n";
            cout<<"1. Add patient\n";
            cout<<"2. View patient\n";
            cout<<"3. Search patient\n";
            cout<<"4. Delete patient\n";
            cout<<"5. Exit\n";
            cout<<"Enter your choice : ";
        }

        void run(){
            int choice;

            do{
                showMenu();
                cin>>choice;
                switch (choice)
                {
                    case 1:
                        addPatient();
                        break;

                    case 2:
                        viewPatient();
                        break;

                    case 3:
                        searchPatient();
                        break;

                    case 4 :
                        deletePatient();
                        break;

                    case 5 :
                        cout<<"Exiting the systm....THANK YOU !!!\n";
                        break;
                    
                    default:
                        cout<<"Invalid choice !! Please try again...\n";
                        break;
                }
            }while(choice != 5);
        }
};

int main() {
    Hospital_Management hm;
    hm.run();
    return 0;
}