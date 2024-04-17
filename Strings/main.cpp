# include <iostream>
# include <map>
# include <algorithm>

using namespace std ;

// Class description :
// This String class implements from scratch some simple strings functions. 
// The main goal is to see how some classical and important algorithms of strings are currently implemented in modern programming languages


class String
{
    private :
    
    char * C ; // Pointeur of type Characters
    int capacity ; // Capacity of the String
    
    public :
    
    // Constructors
    String(); // Default constructor
    String(int c); // Parametrized Constructor
    String(String & s); // Copy Constructor
    
    // Accessors & Mutators
    int getCapacity(); // Get the capacity of the characters array
    void setCapacity(int c); // Define the capacity of the characters array
    
    //Functions
    void Create();  // Create the String
    void Display(); // Display the String
    int Length(); // Return the length of a String
    void ChangeCase(); // Change the case of each letter of a String
    void NVowelsConsonents(); //Count the number of vowels and consonents in a String
    void CountWords(); // Count number of words, each separated by a space in a String
    friend ostream & operator<<(ostream & out, String & s); // Display a String Object with the cout function
    
    // Destructors
    ~String(); // Destructor of our class
};


String::String()
{
    capacity = 100 ;
    C = new char [capacity];
}


String::String(int c)
{
    if(c > 0)
    {
        capacity = c ;
        C = new char [capacity];
    }
    else
    {
        cout<<"Error ! The capacity of a String cannot be negative !"<<endl;
        exit(0);
    }
}


String::String(String & s)
{
    C = s.C ;
    capacity = s.capacity ; 
}


int String::getCapacity()
{
    return capacity ;
}


void String::setCapacity(int c)
{
    if(c > 0)
    {
        capacity = c ;
    }
    else
    {
        cout<<"Error ! The capacity of a String cannot be negative !"<<endl;
        exit(0);
    }
}


void String::Create()
{
    cout<<"Enter a sentence !"<<endl;
    cin.getline(C,capacity);
}


void String::Display()
{
    cout<<C<<endl;
}


int String::Length()
{
    int i , count = 0 ;
    for(i=0; C[i] != '\0'; i++)
    {
        count ++ ;
    }
    
    return count ;
}


void String::ChangeCase()
{
    int i;
    for(i=0;C[i]!='\0';i++)
    {
        if(C[i]>=65 && C[i]<=90)
        {
            C[i] += 32 ;
        }
        else if(C[i]>=97 && C[i]<=122)
        {
            C[i] -= 32 ;
        }
    }
}


void String::NVowelsConsonents()
{
    int i , ccount = 0, vcount = 0 ;
    
    for(i=0;C[i]!='\0';i++)
    {
        if(C[i]=='a'|| C[i]=='e' || C[i]=='i' || C[i]=='o' || C[i]=='u' || C[i]=='A' || C[i]=='E'
           || C[i]=='I' || C[i]=='O' || C[i]=='U')
        {
            vcount ++ ;
        }
        else if ((C[i]>=65 && C[i]<=90) || (C[i]>=97 && C[i]<=122))
        {
            ccount ++ ;
        }
    }
    
    cout<<"There are: "<<vcount<<" vowels "<<endl;
    cout<<"There are: "<<ccount<<" consonents "<<endl;
}


void String::CountWords()
{
    int i, word = 1 ;
    
    for(i=0;C[i]!='\0';i++)
    {
        if(C[i]==' ' && C[i-1]!=' ')
        {
            word ++ ;
        }
    }
    
    cout<<"There are: "<<word<<" words in the String"<<endl;
}


ostream & operator<<(ostream & out, String & s)
{
    out<<s.C<<endl;
    
    return out ;
}


String::~String()
{
    delete [] C;
    //cout<<"String Destroyed !"<<endl;
}


int main()
{
    String s;
    
    s.Create(); // Create our String
    
    //s.Display(); // Display our String
    
    int l = s.Length(); // Returns the length of the String
    cout<<"The length of the String is: "<<l<<endl; // Display the length of the String
    
    s.ChangeCase(); // Change the case of the String
    
    s.NVowelsConsonents(); // Count the number of vowels and consonents in the String
    
    s.CountWords(); // Count the number of words, each separated by a space in a String
    
    cout<<s<<endl; // Display a String object with the cout function
    
    return 0 ;
}
