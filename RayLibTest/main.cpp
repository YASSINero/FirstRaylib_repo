#include <iostream>
#include <fstream>
#include <memory>
#include <string>


void startrec() {
    std::ofstream recover("recov.cfun");
    std::string rec = "TRUE";
    //lock();
    if (recover.is_open()) {
        std::cout << "\n--- Initiated Password Recovery ---\n" << std::endl;
        std::cout << "/// RESTARTING PROGRAM ///\n";
        recover << rec;
        recover.close();
        system("attrib +h recov.cfun");
        // restarts program
        //system("start ziplock.exe");
        exit(0);
    }
}

// removes recovery mode
void removerec() {
    system("del /f /s /q recov.cfun");
    //unlock();
}
// password recovery
int recoverpassword() {
    // setting defaults
    int cmd;

    // quick explanation
    std::cout << "Welcome To The --- PASSWORD RECOVERY --- Terminal\n" << std::endl;
    std::cout << "Here is where you can recover your password, or choose to reset the program" << std::endl;
    std::cout << "By resetting the program you lose all of the stored files and all saved passwords are reset" << std::endl;
    std::cout << "Below are a list of options you can use to recover your password\n\n" << std::endl;

    std::cout << "1: Enter your password\n2: Enter a file name\n3: Reset Program\n:: ";
    std::cin >> cmd;

    if (cmd == 1) {
        std::string pwd;
        std::cout << "Enter your password:: ";
        pwd = "1234abc";// getpass();
        if (pwd == "1234abc") {
            removerec();
            std::cout << "\nPassword is correct! All files and settings have been saved.\nPress 'ENTER' to continue.";
            std::cin.ignore();
            //system("start ziplock.exe");
            exit(0);

        }

    }
}

int main()
{
    system("attrib -h -s -r hidden0rnot.cfwg");
    system("Icacls hidden0rnot.cfwg /grant Amass:f");

    std::fstream file_new("hidden0rnot.cfwg", std::ios_base::out | std::ios_base::trunc);

    if(file_new.is_open())
    {
        file_new << "HELLO WORLD\n";
        file_new << "%HIDEME%";

        file_new.close();
    }else return 1;

    file_new.open("hidden0rnot.cfwg", std::ios_base::in);
    std::string fileBuff;

    while(!std::getline(file_new, fileBuff).eof())
    {
        //fileBuff holds the last line string which contains the flag
    }
        file_new.close();

    std::cout << fileBuff << '\n';

    size_t flagInd_end = fileBuff.find_last_of('%'),
        flagInd_start = fileBuff.find_last_of('%', flagInd_end - 1);
    
    if(fileBuff.substr(flagInd_start+1, flagInd_end - flagInd_start - 1)._Equal("HIDEME"))
    {
        system("attrib +h +s +r hidden0rnot.cfwg");
    }



    return 0;
}
