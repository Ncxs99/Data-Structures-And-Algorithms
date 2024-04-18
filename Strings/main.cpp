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
    
    char * C ; // Pointer of type char
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
    void Reverse(); // Reverse a string
    void Compare(String *D); // Compare two Strings
    bool IsPalindrome(); // Check whether a String is a Palindrome or not
    map<char,int> FindCountDuplicates(); // Find & count duplicates in the String
    bool AraAnagram(String *D); // Check whether two Strings are Anagram or not
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


void String::Reverse()
{
    int i, j ;
    
    for(j=0;C[j]!='\0';j++)
    {
    }
    j -= 1 ;
    for(i=0;i<j;i++,j--)
    {
        swap(C[i], C[j]);
    }
}


void String::Compare(String * D)
{
    int i, j ;
    
    for(i=0,j=0;(C[i]!='\0' && D->C[j]!='\0');i++,j++)
    {
        if(C[i] != D->C[j])
        {
            break ;
        }
    }
    if(C[i]==D->C[j])
    {
        cout<<"Equal"<<endl;
    }
    else if(C[i]<D->C[j])
    {
        cout<<"Smaller"<<endl;
    }
    else
    {
        cout<<"Greater"<<endl;
    }
}


bool String::IsPalindrome()
{
    int i,j ;
    
    for(j=0;C[j]!='\0';j++)
    {
    }
    j -= 1 ;
    for(i=0;i<j;i++,j--)
    {
        if(C[i]!=C[j])
        {
            return false ;
        }
    }
    return true ;
}


map<char,int> String::FindCountDuplicates()
{
    map<char,int> m;
    int H[26], i;
    
    for(i=0;i<26;i++)
    {
        H[i] = 0 ;
    }
    
    for(i=0;C[i]!='\0';i++)
    {
        H[C[i]-97] ++ ;
    }
    for(i=0;i<26;i++)
    {
        if(H[i]>1)
        {
            m.insert(pair<char,int>(i+97,H[i]));
        }
    }
    
    return m ;
}


bool String::AraAnagram(String *D)
{
    int i, H[26]={0};
    
    for(i=0;C[i]!='\0';i++)
    {
        if(C[i]>=65 && C[i]<=90)
        {
            C[i] += 32 ;
        }
    }
    
    for(i=0;D->C[i]!='\0';i++)
    {
        if(D->C[i]>=65 && D->C[i]<=90)
        {
            D->C[i] += 32 ;
        }
    }
    
    for(i=0;C[i]!='\0';i++)
    {
        H[C[i]-97] ++ ;
    }
    
    for(i=0;D->C[i]!='\0';i++)
    {
        H[C[i]-97] -- ;
        if(H[C[i]-97]<0)
        {
            return false ;
        }
    }
    
    return true ;
}



String::~String()
{
    delete [] C;
    //cout<<"String Destroyed !"<<endl;
}


int main()
{
    String s, d; // Create two strings objects
    
    s.Create(); // Create and fill our String
    
    d.Create(); // Create and fill our String
    
    int l = s.Length(); // Returns the length of the String
    cout<<"The length of the String is: "<<l<<endl; // Display the length of the String
    
    //s.ChangeCase(); // Change the case of the String
    //cout<<s<<endl; // Display the String with the cout function
    
    //s.NVowelsConsonents(); // Count the number of vowels and consonents in the String
    
    //s.CountWords(); // Count the number of words, each separated by a space in a String
    
    //s.Reverse(); // Reverse a String
    //cout<<s<<endl; // Display the reversed String with the cout function
    
    //s.Compare(&d); // Compare Strings s & d and tell which is greater, smaller or if they're equal
    
    //int isPalindromic = s.IsPalindrome(); // Store the boolean value of whether the String is Palindr. or not
    //if(isPalindromic)
    //{
       // cout<<"The String is a Palindrome"<<endl; // Display that the String is a Palindrome
    //}
    //else
    //{
      //  cout<<"The String is not a Palindrome"<<endl; // Display that the String is not a Palindrome
    //}
    
    //map<char,int> m; // Declare an STL Map
    //m = s.FindCountDuplicates(); // Store our result in an STL Map
    //map<char,int>::iterator i; // Declaration of an Map iterator
    //for(i=m.begin();i!=m.end();i++) // Loop through our Map
    //{
      //  cout<<i->first<<" appears "<<i->second<<" times "<<endl; // Display element in our Map
    //}
    
    int isAnagram = s.AraAnagram(&d); // Store the boolean value of whether the Strings are Anagrams or not
    if(isAnagram)
    {
        cout<<"The two Strings are Anagrams"<<endl; // Display that the two Strings are Anagrams
    }
    else
    {
        cout<<"The two Strings are not Anagrams"<<endl; // Display the two Strings are not Anagrams
    }
    
    
    //cout<<s<<endl; // Display the String s with the cout function
    
   // cout<<d<<endl; // Display the String d with the cout function
    
    return 0 ;
}
