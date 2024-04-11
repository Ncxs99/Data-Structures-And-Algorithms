# include <iostream>
# include <map>
# include <algorithm>

using namespace std ;

// Class description:
// This C++ class aims to implement, from scratch, essential methods for arrays in modern programming languages. 
// Its primary objective is to delve deep into understanding how data structures and algorithms function in general.

class Array
{
    private :
    
    int *A ;
    int size ;    // total size of a table
    int length ;  // total number of elements in the table
    
    public :
    
    //Constructors
    Array(); // Default constructor
    Array(int sz); // Parametrized constructor
    Array(Array &arr); // Copy Constructor
    
    //Accessors and Mutators
    int getSize();   // Return the size of the Array
    int getLength(); // Return the length of the Array
    void setSize(int s); // Change the size of the Array
    void setLength(int l); // Change the length of the Array
    
    // Methods of our class
    void Create(int n); // Create an array
    void FillIn(int x); // Fill all the Array with values x
    void Append(int x); // Add an element at the end of the Array
    void Insert(int index, int x); // Insert an element at a given position in the Array
    void Delete(int index); // Delete an element at a given index in the Array
    int LinearSearch(int key); // LinearSearch of an element in the Array
    int ImprovedLinearSearch(int key); // ImprovedLinearSearch of an element in the Array
    int BinarySearch(int key); // Binary Search in of an element in the Array
    int RBinarySearch(int l, int h, int key); // Recursive Binary Search of an element in the Array
    int Get(int index); // Get an element from an index in the Array
    void Set(int index, int x); // Set an element wiht a particular index in the Array
    int max(); // Compute the maximum element of the Array
    int min(); // Compute the minimum element of the Array
    int sum(); // Compute the sum of all elements in the Array
    float Avg(); // Compute the average of all elements in the Array
    void Reverse(); // Reverse all elements in the Array
    void LeftShift(); // Shift all the elements of the Array from the left
    void RightShift(); // Shift all the elements of the Array from the right
    void LeftRotate(); // Rotate all the elements of the Array from the left
    void RightRotate(); // Rotate all the elements of the Array from the right
    bool IsSorted(); // Check whether our Array is sorted or not
    void InsertSort(int x); // Insert an element in a sorted Array
    void NegleftPosRight(); // Sort all negative numbers of the Array in the left, all positive numbers in the right
    unique_ptr<Array> Merge(Array *B); // Merge two sorted Arrays and returns a sorted Array
    unique_ptr<Array> Union(Array *B); // Compute the mathematical union of two Arrays
    unique_ptr<Array> Intersection(Array *B); // Compute the mathematical intersection of two Arrays
    unique_ptr<Array> Difference(Array *B); // Compute the mathematical difference of two Arrays
    int MissingElementSorted(); // Check whether an element is missing or not in a sorted Array and display it
    unique_ptr<Array> MissingMultipleSorted(); // Check for multiple missing elements in a sorted Array and display them
    unique_ptr<Array> MissingElementUnsorted(); // Find Multiple missing elements in an unsorted Array
    unique_ptr<Array> FindingDuplicateSorted(); // Find and return all Duplicate elements in a sorted Array
    map<int,int> CountDuplicateSorted(); // Count all Duplicate elements in a sorted Array
    map<int,int> FindCountDupliSorted(); // Find and Count all Duplicate elements in a sorted Array
    map<int,int> FindCountDupliUnsorted(); // Find and Count all Duplicate elements in an unsorted Array
    map<int,int> PairOfElementSumK(int k); // Find all pair of elements in the array whose the sum is equal to k
    map<int,int> PaiofElementSumkBis(int k); // Find all pair of elements in tha array whose the sum is equal to k using another method
    friend ostream & operator<<(ostream & out, Array & arr); // Operator overloading for cout function
    void Display(); // Display the array
    
    // Destructors
    ~Array();
};

Array::Array()
{
    size = 30 ; 
    length = 0 ;
    A = new int [size];
}


Array::Array(int sz)
{
    size = sz ;
    length = 0 ;
    A = new int [size];
}


Array::Array(Array & arr)
{
    size = arr.size;
    length = arr.length;
    A = arr.A ;
}


int Array::getSize()
{
    return size ;
}


int Array::getLength()
{
    return length ;
}


void Array::setSize(int s)
{
    size = s ;
}


void Array::setLength(int l)
{
    if(l>size)
    {
        cout<<"Array out of range !"<<endl;
        exit(0);
    }
    else
    {
        length = l ;
    }
}


void Array::Create(int n)
{
    setLength(n);
    for(int i=0;i<length;i++)
    {
        cout<<"Entrer un nombre:"<<endl;
        cin>>A[i];
    }
    
}


void Array::FillIn(int x)
{
    for(int i=0;i<length;i++)
    {
        A[i] = x ;
    }
}


void Array::Append(int x)
{
    A[length] = x ;
    length ++ ;
}


void Array::Insert(int index,int x)
{
    if(index <0 || index>length)
    {
        cout<<"Error ! Index out of range !"<<endl;
        exit(0);
    }
    else
    {
        for(int i=length;i>index;i--)
        {
            A[i] = A[i-1];
        }
        A[index] = x ;
        length ++ ; 
    }
}


void Array::Delete(int index)
{
    if(index < 0 || index>length)
    {
        cout<<"Error ! Index out or range !"<<endl;
        exit(0);
    }
    else
    {
        for(int i=index;i<length-1;i++)
        {
            A[i] = A[i+1];
        }
        length -- ;
    }
}


int Array::LinearSearch(int key)
{
    for(int i=0;i<length;i++)
    {
        if(key==A[i])
        {
            //cout<<"Element founded at index: "<<i<<endl;
            return i ;
        }
    }
    //cout<<"Element not founded in the array !"<<endl;
    return - 1 ;
}


int Array::ImprovedLinearSearch(int key)
{
    for(int i=0;i<length;i++)
    {
        if(key==A[i])
        {
            swap(A[0], A[i]);
            cout<<"Element founded at index "<<i<<" and swapped at the first index !"<<endl;
            return 0 ;
        }
    }
    cout<<"Element not founded in the array !"<<endl;
    return -1 ;
}


int Array::BinarySearch(int key)
{
    int middle,low=0,high=length-1;
    
    while(low<=high)
    {
        middle = (low + high) / 2 ;
        if(key==A[middle])
        {
            cout<<"Element founded at index "<<middle<<endl;
            return middle ;
            
        }
        else if(key<A[middle])
        {
            high = middle - 1 ;
        }
        else
        {
            low = middle + 1 ;
        }
    }
    cout<<"Element not founded !"<<endl;
    return - 1 ;
}


int Array::RBinarySearch(int l, int h, int key)
{
    int middle ;
    
    if(l<=h)
    {
        middle = (l+h) / 2 ;
        if(key==A[middle])
        {
            cout<<"Element founded at index "<<middle<<endl;
            return middle ;
        }
        else if(key<A[middle])
        {
            return RBinarySearch(l, middle-1, key);
        }
        else
        {
            return RBinarySearch(middle+1, h, key);
        }
    }
    cout<<"Element not founded !"<<endl;
    return -1 ;
}


int Array::Get(int index)
{
    if(index<0 || index>length)
    {
        cout<<"Error ! Array out of range !"<<endl;
        exit(0);
    }
    else
    {
        return A[index];
    }
}


void Array::Set(int index, int x)
{
    if(index<0 || index>length)
    {
        cout<<"Error ! Index out of range !"<<endl;
        exit(0);
    }
    else
    {
        A[index] = x ;
    }
}


ostream & operator<<(ostream & out, Array & arr)
{
    out<<"Table Displaying"<<endl;
    for(int i=0;i<arr.length;i++)
    {
        out<<arr.A[i]<<" ";
    }
    out<<endl;
    
    return out ;
}


void Array::Display()  // O(n)
{
    cout<<" Table Displaying "<<endl;
    for(int i=0;i<length;i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
}


int Array::max()
{
    int max = A[0];
    
    for(int i=1;i<length;i++)
    {
        if(A[i] > max)
        {
            max = A[i];
        }
    }
    
    return max ;
}


int Array::min()
{
    int minimum = A[0];
    for(int i=0;i<length;i++)
    {
        if(A[i]<minimum)
        {
            minimum = A[i];
        }
    }
    return minimum ;
}


int Array::sum()
{
    int total = 0 ;
    for(int i=0;i<length;i++)
    {
        total += A[i];
    }
    
    return total ;
}


float Array::Avg()
{
    int total = 0 ;
    for(int i=0;i<length;i++)
    {
        total += A[i];
    }
    
    return (float) total/length ;
}


void Array::Reverse()
{
    int i, j ;
    for(i=0,j=length-1;i<j;i++,j--)
    {
        swap(A[i], A[j]);
    }
    
}


void Array::LeftShift()
{
    for(int i=0;i<length-1;i++)
    {
        A[i] = A[i+1];
    }
    A[length-1]=0;
}


void Array::RightShift()
{
    for(int i=length-1;i>=1;i--)
    {
        A[i] = A[i-1] ;
    }
    A[0] = 0 ;
}


void Array::LeftRotate()
{
    int temp = A[0];
    for(int i=0;i<length-1;i++)
    {
        A[i] = A[i+1];
    }
    A[length-1] = temp ;
}


void Array::RightRotate()
{
    int temp = A[length-1];
    for(int i=length-1;i>=1;i--)
    {
        A[i] = A[i-1];
    }
    A[0] = temp ;
}


bool Array::IsSorted()
{
    for(int i=0;i<length-1;i++)
    {
        if(A[i]>A[i+1])
        {
            return false ;
        }
    }
    return true ;
}


void Array::InsertSort(int x)
{
    if(IsSorted())
    {
        int i = length - 1 ;
        while(A[i]>x)
        {
            A[i+1]=A[i];
            i--;
        }
        A[i+1]=x;
        length ++ ;
    }
    else
    {
        cout<<"Error ! Array non sorted ! Sort your array before continuing ! "<<endl;
        exit(0);
    }
}


void Array::NegleftPosRight()
{
    int i = 0, j= length - 1 ;
    
    while(i<j)
    {
        while(A[i]<0)
        {
            i++;
        }
        while(A[j]>=0)
        {
            j--;
        }
        if(i<j)
        {
            swap(A[i], A[j]);
        }
    }
}


unique_ptr<Array> Array::Merge(Array *B)
{
    if(IsSorted() && B->IsSorted())
    {
        int i,j,k;
        i=j=k=0;
        
        unique_ptr<Array> C (new Array(length + B->length));
        
        while(i<length && j<B->length)
        {
            if(A[i]<B->A[j])
            {
                C->A[k++] = A[i++];
            }
            else
            {
                C->A[k++] = B->A[j++];
            }
        }
        for(;i<length;i++)
        {
            C->A[k++] = A[i];
        }
        for(;j<B->length;j++)
        {
            C->A[k++] = B->A[j];
        }
        C->length = length + B->length;
        
        return C ;
        
    }
    else
    {
        cout<<"Error ! Arrays are not sorted ! "<<endl;
        exit(0);
    }
}


unique_ptr<Array> Array::Union(Array *B)
{
    int i,j,k;
    
    unique_ptr<Array> C(new Array(length + B->length));
    
    if(IsSorted() && B->IsSorted())
    {
        i=j=k=0;
        
        while(i<length && j<B->length)
        {
            if(A[i]<B->A[j])
            {
                C->A[k++] = A[i++];
            }
            else if(B->A[j]<A[i])
            {
                C->A[k++] = B->A[j++];
            }
            else
            {
                C->A[k++] = A[i++];
                j++ ;
            }
        }
        for(;i<length;i++)
        {
            C->A[k++] = A[i];
        }
        for(;j<B->length;j++)
        {
            C->A[k++] = B->A[j];
        }
        C->length = k;
        
        return C ;
 
    }
    else
    {
        for(i=0;i<length;i++)
        {
            C->A[i] = A[i];
        }
        k = length ;
        for(j=0;j<B->length;j++)
        {
            if(LinearSearch(B->A[j])==-1)
            {
                C->A[k] = B->A[j];
                k ++ ;
            }
        }
        C->length = k ;
        
        return C ;
    }
    
}


unique_ptr<Array> Array::Intersection(Array *B)
{
    int i,j,k=0;
    
    unique_ptr<Array> C (new Array(length + B->length));
    
    
    if(IsSorted() && B->IsSorted())
    {
        i=j=k=0;
        
        while(i<length && j<B->length)
        {
            if(A[i]<B->A[j])
            {
                i++ ;
            }
            else if(B->A[j]<A[i])
            {
                j++ ;
            }
            else if(A[i]==B->A[j])
            {
                C->A[k++] = A[i++];
                j++ ;
            }
        }
        C->length = k;
        
        return C ;
    }
    else
    {
        for(i=0;i<length;i++)
        {
            for(j=0;j<B->length;j++)
            {
                if(A[i]==B->A[j])
                {
                    C->A[k] = A[i];
                    k++;
                }
            }
        }
        C->length = k ;
        
        return C ;
        
    }
}


unique_ptr<Array> Array::Difference(Array *B)
{
    int i,j,k=0;
    
    unique_ptr<Array> C (new Array(length + B->length));
    
    
    if(IsSorted() && B->IsSorted())
    {
        i=j=k=0;
        
        while(i<length && j<B->length)
        {
            if(A[i]<B->A[j])
            {
                C->A[k++] = A[i++];
            }
            else if(B->A[j]<A[i])
            {
                j++;
            }
            else
            {
                i++;
                j++ ;
            }
        }
        for(;i<length;i++)
        {
            C->A[k++] = A[i];
        }
        C->length = k;
        
        return C ;
    }
    else
    {
        for(i=0;i<length;i++)
        {
            if(B->LinearSearch(A[i])==-1)
            {
                C->A[k] = A[i];
                k++ ;
            }
        }
        C->length = k ;
        
        return C ;
    }
}


int Array::MissingElementSorted()
{
    if(IsSorted())
    {
        int difference = A[0] - 0 ;
        for(int i=0;i<length;i++)
        {
            if(A[i]-i != difference)
            {
                return i + difference ;
 
            }
        }
    }
    
    cout<<"Array not sorted ! Sort your array before checking for missing element !"<<endl;
    return -9999;
}


unique_ptr<Array> Array::MissingMultipleSorted()
{
    if(IsSorted())
    {
        int difference = A[0] - 0 ;
        
        unique_ptr<Array> C(new Array(length));
        
        for(int i=0;i<length;i++)
        {
            if(A[i]-i != difference)
            {
                while(difference < A[i]-i)
                {
                    C->Append(i+difference);
                    difference ++ ;
                }
            }
        }
        
        return C ;
    }
    
    cout<<"Array not sorted ! Sort your array before checking for missing element !"<<endl;
    exit(0);
}


unique_ptr<Array> Array::MissingElementUnsorted()
{
    unique_ptr<Array> C (new Array(max()));
    C->setLength(C->getSize());
    unique_ptr<Array> D (new Array);
    
    for(int i=0;i<length;i++)
    {
        C->A[A[i]] ++ ;
    }
    
    for(int i=min();i<C->length;i++)
    {
        if(C->A[i] == 0)
        {
            D->Append(i);
        }
    }
    
    return D ;
}


unique_ptr<Array> Array::FindingDuplicateSorted()
{
    if(IsSorted())
    {
        int lastDuplicate = 0 ;
        
        unique_ptr<Array> C (new Array(length));
        
        for(int i=0;i<length;i++)
        {
            if(A[i]==A[i+1] && A[i] != lastDuplicate)
            {
                C->Append(A[i]);
                lastDuplicate = A[i];
            }
        }
        
        return C ;
    }
    else
    {
        cout<<"Error ! Array non sorted !"<<endl;
        exit(0);
    }
}


map<int,int> Array::CountDuplicateSorted()
{
    map<int,int> m ;
    for(int i=0;i<length-1;i++)
    {
        if(A[i]==A[i+1])
        {
            int j = i + 1 ;
            while(A[i]==A[j])
            {
                j ++ ;
            }
            m.insert(pair<int,int>(A[i],j-i));
            i = j - 1 ;
        }
    }
    
    return m ;
}


map<int,int> Array::FindCountDupliSorted()
{
    map<int,int> m;
    unique_ptr<Array> C (new Array(max()));
    C->setLength(C->getSize());
    
    for(int i=0; i<length; i++)
    {
        C->A[A[i]] ++ ;
    }
    for(int i=0;i<=C->length;i++)
    {
        if(C->A[i]>1)
        {
            m.insert(pair<int,int>(i,C->A[i]));
        }
    }
    
    return m ;
    
}


map<int,int> Array::FindCountDupliUnsorted()
{
    map<int,int> m ;
    
    m = FindCountDupliSorted();
    
    return m ;
}


map<int,int> Array::PairOfElementSumK(int k)
{
    map<int,int> m;
    for(int i=0;i<length-1;i++)
    {
        for(int j=i+1;j<length;j++)
        {
            if(A[i]+A[j]==k)
            {
                m.insert(pair<int,int>(A[i],A[j]));
            }
        }
    }
    
    return m ;
}



map<int,int> Array::PaiofElementSumkBis(int k)
{
    unique_ptr<Array> C (new Array(max()));
    C->setLength(C->getSize());
    map<int,int> m ;
    
    for(int i=0;i<length;i++)
    {
        if(C->A[k-A[i]] != 0)
        {
            m.insert(pair<int,int>(A[i],k-A[i]));
        }
        C->A[A[i]] ++ ;
    }
    
    return m ;
}



Array::~Array()
{
    delete []A;
    //cout<<"Array Destroyed !"<<endl;
}


int main()
{
    Array arr ; // Declaring the Array
    
    arr.Create(10); // Create and fill in the Array with 5 elements
    
    //arr.Append(6); // Add 6 at the end of the Array
    //arr.Append(7); // Add 7 at the end of the Array
    
    arr.Insert(0, 15); // Insert element 15 at index 0
    
    int a = arr.Get(4); // Get a particular value from the Array
    cout<<"The element in the position "<<4<<" is "<<a<<endl;
    
    int b = arr.max(); // Get maximum value
    cout<<"The maximum element in the Array is: "<<b<<endl;
    
    int c = arr.sum(); // Get total sum of elements in the Array
    cout<<"The total sum of elements in the table is: "<<c<<endl;
    
    int d = arr.min(); // Get minimum value in the Array
    cout<<"The minimum element in the Array is: "<<d<<endl;
    
    float e = arr.Avg(); // Get the average value in the Array
    cout<<"The average of all elements is: "<<e<<endl;
    
    //arr.Set(6, 9);  // Set a particular value in an Array in a particular index with another value
    
    arr.Delete(0); // Delete the element at index 0
    
    //cout<<arr.LinearSearch(4)<<endl; // Search element with a linearly algorithm
    //cout<<arr.ImprovedLinearSearch(4)<<endl; // Search element with improved linearly search algorithm
    
    cout<<arr.BinarySearch(4)<<endl; // Search an element with binary search algorithm
    
    int l=0, h = arr.getLength()-1; // Parameter of recursive binary search
    cout<<arr.RBinarySearch(l, h, 4)<<endl; // Search an element in Array with recursive binary algorithm
    
    //arr.Reverse(); // Reverse the Array
    //cout<<arr; // Display the reversed Array with cout method
    
    //arr.LeftShift(); // Shift the Array from the left
    //cout<<arr; Display the shifted from the left Array with cout method
    
    //arr.RightShift(); // Shift the Array from the right
    //cout<<arr; // Display the shifted from the right Array with cout method
    
    //arr.LeftRotate(); // Rotate the Array to the left
    //cout<<arr; //Display the rotated Array to the left with cout method
    
    //arr.RightRotate(); // Rotate the Array to the right
    //cout<<arr; //Display the rotated Array to the right with cout method
    

    //cout<<arr.IsSorted()<<endl;   //Check if the Array is sorted
    
    //arr.InsertSort(2); // Insert an element in a sorted Array
    //cout<<arr; //Display the sorted Array in which we include an element
    
    //arr.NegleftPosRight(); // All negative numbers in left, all positive numbers in right
    //cout<<arr; //Display the Array with all negative numbers in left and all positive numbers in right
    
    //Array arr2; // Declaring a second Array
    
    //arr2.Create(5);  // Create a second Array of size 5 !
    
    //unique_ptr<Array> merge ; // Pointer on our Array
    //merge = arr.Merge(&arr2); // Merge the first Array arr with the second Array arr2 -> store it in a pointer
    //merge->Display(); // Use our Pointer to Display the Array
    
    
    //unique_ptr<Array> Union ; // Pointer on our Array
    //Union = arr.Union(&arr2); // Union of the first Array arr with the second Array arr2 -> store it in a pointer
    //Union->Display(); // Use our Pointer to Display the Array
    
    
    //unique_ptr<Array> intersection; // Pointer on our Array
    //intersection = arr.Intersection(&arr2); // Intersection of the first Array arr with the second Array arr2
    //intersection->Display(); // Use our Pointer to Display() the Array

    
    //unique_ptr<Array> difference ; // Pointer on our Array
    //difference = arr.Difference(&arr2); // Difference of the first Array arr with the second Array arr2
    //difference->Display();
    
    //int f = arr.MissingElementSorted(); // Missing Element in a sorted Array
    //cout<<"The missing element in the Array is: "<<f<<endl;
    
    //unique_ptr<Array> multimiss; // Pointer on our Array
    //multimiss = arr.MissingMultipleSorted(); // Store all missing element in an Array
    //multimiss->Display(); // Display the Array
    
    //unique_ptr<Array> unsortedmiss ; // Pointer on our Array
    //unsortedmiss = arr.MissingElementUnsorted(); // Store all missing element in our Array
    //unsortedmiss->Display(); // Display the Array
    
    //unique_ptr<Array> findupli ; // Pointer on our Array
    //findupli = arr.FindingDuplicateSorted(); // Store all duplicate elements in our Array
    //findupli->Display(); // Display the Array
    
    //map<int,int> m ; // Declare an STL Map
    //m = arr.CountDuplicateSorted(); // Store all duplicate elements and their occurences in our Map
    //map<int,int>::iterator i; // Initialise an map iterator
    //for(i = m.begin();i!=m.end();i++)  // Loop through the Map
    //{
       // cout<<i->first<<" Appears "<<i->second<<" times "<<endl; // Display the all occurences
    //}
    
    //map<int,int> m ; // Declare an STL Map
    //m = arr.FindCountDupliSorted(); // Store all duplicate elements and their occurences in our Map
    //map<int,int>::iterator i; // Initialise an map iterator
    //for(i = m.begin();i!=m.end();i++)  // Loop through the Map
    //{
      //  cout<<i->first<<" Appears "<<i->second<<" times "<<endl; // Display the all occurences
    //}
    
    //map<int,int> m ; // Declare an STL Map
    //m = arr.FindCountDupliUnsorted(); // Store all duplicate elements and their occurences in our Map
    //map<int,int>::iterator i; // Initialise an map iterator
    //for(i = m.begin();i!=m.end();i++)  // Loop through the Map
    //{
      //  cout<<i->first<<" Appears "<<i->second<<" times "<<endl; // Display the all occurences
    //}
    
    //map<int,int> m ;// Declare an STL Map
    //int k = 10 ; // Sum we want all the pair of elements in our Array be equal to
    //m = arr.PairOfElementSumK(10); // Store all pair of elements
    //map<int,int>::iterator i; // Initialise an map iterator
    //for(i = m.begin();i!=m.end();i++)  // Loop through the Map
    //{
      //  cout<<i->first<<" + "<<i->second<<" = "<<k<<endl; // Display the all pairs
    //}
    
    map<int,int> m ;// Declare an STL Map
    int k = 10 ; // Sum we want all the pair of elements in our Array be equal to
    m = arr.PaiofElementSumkBis(10); // Store all pair of elements
    map<int,int>::iterator i; // Initialise an map iterator
    for(i = m.begin();i!=m.end();i++)  // Loop through the Map
    {
        cout<<i->first<<" + "<<i->second<<" = "<<k<<endl; // Display the all pairs
    }
    
    return 0 ;
}


