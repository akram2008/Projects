#include<bits/stdc++.h>
using namespace std;
class Notepad{
private:
    vector<string>lines;
    string fileName="";
public:
    void run(){
        int input;
        do
        {
            Menu();
            cin>>input;
            cin.ignore();
            switch (input)
            {
                case 1: newFile(); break;
                case 2: openFile(); break;
                case 3: saveFile(); break;
                case 4: saveFileAs(); break;
                case 5: editFile(); break;
                case 6: clearFile(); break;
                case 7: displayFile(); break;
            }
        } while (input);
    }
private: 
    void Menu(){
        cout << "\n=== Simple Notepad ===\n";
        cout << "1. New File\n";
        cout << "2. Open File\n";
        cout << "3. Save File\n";
        cout << "4. Save File As\n";
        cout << "5. Edit Text\n";
        cout << "6. Clear File\n";
        cout << "7. Display Text\n";
        cout << "0. Exit\n";
        cout << "Choice: ";
    }
    void newFile(){
        lines.clear();
        fileName="";
        cout<<"New file was created!"<<endl;
    }
    void openFile(){
        cout<<"Enter filename:";
        getline(cin, fileName);
        ifstream file(fileName);
        if(file.is_open()){
            lines.clear();
            string line;
            while(getline(file, line)){
                lines.push_back(line);
            }
            file.close();
            cout<<"File opened successfully"<<endl;
        }else{
            cout<<"Error trying to access the file💔"<<endl;
        }
    }
    void saveFileAs(){
        cout<<"Input file name:";
        cin>>fileName;
        fileName+=".txt";
        saveFile();
    }
    void saveFile(){
        if(fileName.empty()){
            cout<<"Input file name:";
            cin>>fileName;
            fileName+=".txt";
        }
        ofstream file(fileName);
        if(file.is_open()){
            for(string line:lines){
                file<<line<<endl;
            }
            file.close();
            cout<<"File Saved successfully"<<endl;
        }else{
            cout<<"Error creating a file with that name💔";
        }
    }
    void editFile(){
        cout<<"Enter text (type '$END' on a new line to finish editing)\n";
        for(string &line:lines){
            cout<<line<<endl;
        }
        string line;
        vector<string>temp;
        while(getline(cin,line)&&line!="$END"){
            temp.push_back(line);
        }
        temp.pop_back();
        lines=temp;
    }
    void clearFile(){
        lines.clear();
        cout<<"File cleared successfully!\n";
    }
    void displayFile(){
        cout<<"\n--- Contents ---\n";
        for(string &line:lines){
            cout<<line<<endl;
        }
        cout<<"\n--- END ---\n";
    }
};
int main(){
    Notepad note;
    note.run();
    return 0;
}
