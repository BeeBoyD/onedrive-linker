#include <cstdlib>
#include <iostream>
#include <string>

void print_usage(char* program_name) {
    std::cout << "\nUsage: " << program_name << " <path_to_onedrive_folder_including_directory_where_you_want_link> <path_to_folder_you_want_to_link>\n\n";
    std::cout << "Or: " << program_name << " /g" << " for guided mode \n\n";
    std::cout << "Or: " << program_name << " /?" << " for advanced help \n\n";
}

void print_advanced_usage(char* program_name)
{
    std::cout << "\nUsage: " << program_name << " <path_to_onedrive_folder_including_directory_where_you_want_link> <path_to_folder_you_want_to_link>\n\n";
    std::cout << "Or: " << program_name << " /g" << " for guided mode. " << "It will ask you the the path to the OneDrive folder including the directory inside OneDrive where you want to link and the path to the folder you want to link \n \n";
    std::cout << "Examples:  \n \n";
    std::cout << "Guided Mode: [first line] D:/OneDrive/BeeBoyD [second line] D:/BeeBoyD \n \n";
    std::cout << "Normal Mode: [first argument] D:/OneDrive/BeeBoyD [second argument] D:/BeeBoyD \n\n";
}

int main(int argc, char* argv[]) {
    std::cout << "\n===========================================\n";
    std::cout << "   Welcome to OneDrive Linker\n";
    std::cout << "   (Requires Administrator Permissions)\n";
    std::cout << "   Made by BeeBoyD\n";
    std::cout << "===========================================\n\n";

    if (argc == 2 && std::string(argv[1]) == "/?") {
        print_advanced_usage(argv[0]);
        return 0;
    }

    std::string onedrive_folder;
    std::string folder_to_link;

    if (argc == 2 && std::string(argv[1]) == "/g") {
        std::cout << "You have selected guided mode.\n";
        std::cout << "Enter the path to the OneDrive folder including the directory inside OneDrive where you want to link: ";
        std::getline(std::cin, onedrive_folder);
        std::cout << "Enter the path to the folder you want to link: ";
        std::getline(std::cin, folder_to_link);
    }
    else if (argc == 3) {
        onedrive_folder = argv[1];
        folder_to_link = argv[2];
    }
    else {
        print_usage(argv[0]);
        return 1;
    }

    std::string command = "mklink /D \"" + onedrive_folder + "\" \"" + folder_to_link + "\"";

    std::cout << "\nCreating link...\n";
    system(command.c_str());
    std::cout << "\nLink created successfully!\n";

    return 0;
}
