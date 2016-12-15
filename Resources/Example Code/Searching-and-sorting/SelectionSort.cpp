#include <iostream>
using namespace std;

void DisplayArray( int* arr, int size )
{
    for ( int i = 0; i < size; i++ )
    {
        cout << i << " = " << arr[i] << endl;
    }
    cout << endl;
}

void SelectionSort( int* arr, int size )
{
    cout << "Before sort" << endl;
    DisplayArray( arr, size );
    int i;
    int j;

    int swapCount = 0;

    for ( j = 0; j < size - 1; j++ )
    {
        int iMin = j;
        for ( int i = j+1; i < size; i++ )
        {
            if ( arr[i] > arr[iMin] )
            {
                iMin = i;
            }
        }

        if ( iMin != j )
        {
            swapCount++;
            cout << "Swap #" << swapCount << endl;
            int temp = arr[j];
            arr[j] = arr[iMin];
            arr[iMin] = temp;

            cout << "Result" << endl;
            DisplayArray( arr, size );
        }
    }
}

int main()
{
    int nums[] = { 4, 15, 8, 3, 28, 21 };
    SelectionSort( nums, 6 );

    return 0;
}
