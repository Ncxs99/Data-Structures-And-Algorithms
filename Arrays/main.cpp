# include <iostream>
# include <cmath>
# include <algorithm>

using namespace std ;

// Class description:
// This C++ class aims to implement, from scratch, essential methods for arrays in modern programming languages. Its primary objective is to delve deep into understanding how data structures and algorithms function in general.

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
    void Append(int x); // Add an element at the end of the Array
    void Insert(int index, int x); // Insert an element at a given position in the array
    void Delete(int index); // Delete an element at a given index in the array
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
    bool IsSorted(); // Check wether our Array is sorted or not
    void InsertSort(int x); // Insert an element in a sorted Array
    void NegleftPosRight(); // Sort all negative numbers of the Array in the left, all positive numbers in the right
    unique_ptr<Array> Merge(Array *B); // Merge two sorted Arrays and returns a sorted Array
    unique_ptr<Array> Union(Array *B); // Compute the mathematical union of two Arrays
    unique_ptr<Array> Intersection(Array *B); // Compute the mathematical intersection of two Arrays
    unique_ptr<Array> Difference(Array *B); // Compute the mathematical difference of two Arrays
    int MissingElementSorted(); // Check wether an element is missing or not in a sorted Array and display it
    unique_ptr<Array> MissingMultipleSorted(); // Check for multiple missing elements and display them
    friend ostream & operator<<(ostream&out, Array & arr); // Operator overloading for cout function
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


Array::~Array()
{
    delete []A;
    //cout<<"Array Destroyed !"<<endl;
}


int main()
{
    Array arr ; // Declaring the array
    
    arr.Create(5); // Create and fill in the array with 5 elements
    
    //arr.Append(6); // Add 6 at the end of the array
    //arr.Append(7); // Add 7 at the end of the array
    
    arr.Insert(0, 15); // Insert element 15 at index 0
    
    int a = arr.Get(4); // Get a particular value from the array
    cout<<"The element in the position "<<4<<" is "<<a<<endl;
    
    int b = arr.max(); // Get maximum value
    cout<<"The maximum element in the array is: "<<b<<endl;
    
    int c = arr.sum(); // Get total sum of elements in the array
    cout<<"The total sum of elements in the table is: "<<c<<endl;
    
    int d = arr.min(); // Get minimum value in the array
    cout<<"The minimum element in the array is: "<<d<<endl;
    
    float e = arr.Avg(); // Get the average value in the array
    cout<<"The average of all elements is: "<<e<<endl;
    
    //arr.Set(6, 9);  // Set a particular value in an array in a particular index with another value
    
    arr.Delete(0); // Delete the element at index 0
    
    //cout<<arr.LinearSearch(4)<<endl; // Search element with a linearly algorithm
    //cout<<arr.ImprovedLinearSearch(4)<<endl; // Search element with improved linearly search algorithm
    
    cout<<arr.BinarySearch(4)<<endl; // Search an element with binary search algorithm
    
    int l=0, h = arr.getLength()-1; // Parameter of recursive binary search
    cout<<arr.RBinarySearch(l, h, 4)<<endl; // Search an element in array with recursive binary algorithm
    
    //arr.Reverse(); // Reverse the array
    //cout<<arr; // Display the reversed array with cout method
    
    //arr.LeftShift(); // Shift the array from the left
    //cout<<arr; Display the shifted from the left array with cout method
    
    //arr.RightShift(); // Shift the array from the right
    //cout<<arr; // Display the shifted from the right array with cout method
    
    //arr.LeftRotate(); // Rotate the array to the left
    //cout<<arr; //Display the rotated array to the left with cout method
    
    //arr.RightRotate(); // Rotate the array to the right
    //cout<<arr; //Display the rotated array to the right with cout method
    

    //cout<<arr.IsSorted()<<endl;   //Check if the array is sorted
    
    //arr.InsertSort(2); // Insert an element in a sorted array
    //cout<<arr; //Display the sorted array in which we include an element
    
    //arr.NegleftPosRight(); // All negative numbers in left, all positive numbers in right
    //cout<<arr; //Display the array with all negative numbers in left and all positive numbers in right
    
    Array arr2; // Declaring a second Array
    
    arr2.Create(5);  // Create a second array of size 5 !
    
    //unique_ptr<Array> merge ; // Pointer on our Array
    //merge = arr.Merge(&arr2); // Merge the first array arr with the second array arr2 -> store it in a pointer
    //merge->Display(); // Use our Pointer to Display the array
    
    
    //unique_ptr<Array> Union ; // Pointer on our Array
    //Union = arr.Union(&arr2); // Union of the first array arr with the second array arr2 -> store it in a pointer
    //Union->Display(); // Use our Pointer to Display the array
    
    
    //unique_ptr<Array> intersection; // Pointer on our Array
    //intersection = arr.Intersection(&arr2); // Intersection of the first array arr with the second array arr2
    //intersection->Display(); // Use our Pointer to Display() the array

    
    //unique_ptr<Array> difference ; // Pointer on our Array
    //difference = arr.Difference(&arr2); // Difference of the first array arr with the second array arr2
    //difference->Display();
    
    int f = arr.MissingElementSorted(); // Missing Element in a sorted array
    cout<<"The missing element in the array is: "<<f<<endl;
    
    unique_ptr<Array> multimiss; // declare arr3 as a pointer to the array object
    multimiss = arr.MissingMultipleSorted(); // Store all missing element in an array
    multimiss->Display(); // Display the array
    
    return 0 ;
}


