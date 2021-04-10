#include "Subject.h"

#pragma region Constructer


Subject::Subject()
{
	totalNumberOfTests = 0;
}


#pragma endregion


#pragma region Getters and Setters


int Subject::GetTotalNumberOfTests() const
{
	return totalNumberOfTests;
}


#pragma endregion



#pragma region Add and Delete Tests


// Adds 1 test to allTests map
// Test is initialized inside method
// Adds 1 to totalNumberOfTests
// Adds test to file
void Subject::AddTest(string _path_to_directory)
{
	Test t;

	t.FillTest();

    t.SaveTestToFile(_path_to_directory);
}


// Deletes 1 Test
// Name of test asked from user in method
// Subtracts 1 from totalNumberOfTests
void Subject::DeleteTest(string _path_to_directory)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 15);


        /* Get name of test to delete */
    string test_name;
    cout << "Enter file name:";
    SetConsoleTextAttribute(hConsole, 14);
    cin >> test_name;
    SetConsoleTextAttribute(hConsole, 15);

    _path_to_directory += "\\";
    _path_to_directory += test_name;

    try
    {
        if (remove(test_name.c_str()) != 0) throw "Unable to delete";
       
        SetConsoleTextAttribute(hConsole, 10);
        cout << "Test deleted" << endl;
        SetConsoleTextAttribute(hConsole, 15);

    }
    catch (const char* c)
    {
        SetConsoleTextAttribute(hConsole, 12);
        cout << "Error: " << c << ": " << test_name << endl;
        SetConsoleTextAttribute(hConsole, 15);
    }
}


#pragma endregion



void Subject::ShowAllTests(string _path)
{
    /*
    _path += "\\";


    path += mask;

    _finddata_t* fileinfo = new _finddata_t;
    long done = _findfirst(path.c_str(), fileinfo);
    int isReadable = done;
    int count = 0;

    while (isReadable != -1)
    {
        count++;
        char time[100];
        ctime_s(time, 100, &fileinfo->time_create);

        if (fileinfo->name != "." && fileinfo->name != "..")
            cout << count << " - " << fileinfo->name << "  " << time << endl;

        //cout << fileinfo->name << "\n";


        isReadable = _findnext(done, fileinfo);
    }

    cout << count << " files found" << endl;
    _findclose(done);
    delete fileinfo;
    */

}





/* Possible addition */

// Deletes all test in this subject
// Sets totalNumberNumberOfTests to 0
void Subject::DeleteAllTests(string _path_to_directory)
{
 
}
