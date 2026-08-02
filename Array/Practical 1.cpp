#include <iostream>
using namespace std;

int main()
{
    int arr[100], n, choice, pos, value, i;
    int found;

    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter the elements: ";
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    do
    {
        cout << "\n----- MENU -----";
        cout << "\n1. Traversal";
        cout << "\n2. Insertion";
        cout << "\n3. Deletion";
        cout << "\n4. Search";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Array Elements: ";
            for (i = 0; i < n; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
            break;

        case 2:
            cout << "Enter position (1 to " << n + 1 << "): ";
            cin >> pos;
            cout << "Enter value to insert: ";
            cin >> value;

            if (pos < 1 || pos > n + 1)
            {
                cout << "Invalid Position!" << endl;
            }
            else
            {
                for (i = n; i >= pos; i--)
                {
                    arr[i] = arr[i - 1];
                }
                arr[pos - 1] = value;
                n++;
                cout << "Element inserted successfully." << endl;
            }
            break;

        case 3:
            cout << "Enter position to delete (1 to " << n << "): ";
            cin >> pos;

            if (pos < 1 || pos > n)
            {
                cout << "Invalid Position!" << endl;
            }
            else
            {
                for (i = pos - 1; i < n - 1; i++)
                {
                    arr[i] = arr[i + 1];
                }
                n--;
                cout << "Element deleted successfully." << endl;
            }
            break;

        case 4:
            cout << "Enter element to search: ";
            cin >> value;
            found = 0;

            for (i = 0; i < n; i++)
            {
                if (arr[i] == value)
                {
                    cout << "Element found at position " << i + 1 << endl;
                    found = 1;
                    break;
                }
            }

            if (!found)
            {
                cout << "Element not found." << endl;
            }
            break;

        case 5:
            cout << "Exiting program..." << endl;
            break;

        default:
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 5);

    return 0;
}
