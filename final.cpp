#include <iostream>
#include <cmath>
#include <string>
#include <stdlib.h>

//How to enter in the matricies
using namespace std;

bool isWhiteSpace(char ch)

{
        if (ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t')
        {
            return true;
        }
        return false;
}

//Define getInts
int getInts(string input, int tempNums[])
{
        int number;
        int i = 0;
            for (int j = 0; j < input.length(); j++)
            {
                string temp = "";
                while(!isWhiteSpace(input[j]))
                {
                    temp += input[j];
                    j++;
                }
                number = atoi(temp.c_str());
                tempNums[i] = number;
                i++;
            }
        return i;
}

//Multiply the matricies and give result
void matrixMult(int matrix1[][10], int matrix2[][10], int result[][10], int rows1, int rows2, int cols1, int cols2)
{
        for (int i = 0; i < rows1; i++)
        {
            for (int j = 0; j < cols2; j++)
            {
                result[i][j] = 0;
                for (int k = 0; k < rows2; k++)
                {
                    result[i][j] = result[i][j] + matrix1[i][k] * matrix2[k][j];                }
            }
        }

 cout << "The product is:" << endl;
        for (int m = 0; m < rows1; m++)
        {
            for (int l = 0; l < cols2; l++)
            {
                if(l == cols2-1)
                {
                    cout << result[m][l];
                }
                else
                {
                    cout << result[m][l] << " ";
  }
            }
            cout << endl;
        }
}

int main()
{
//Define possible digits
	string numbers = "-0123456789";
        string input = "0";

//First matrix
 int tempNums[10], matrix1[10][10], matrix2[10][10], result[10][10];
        cout << "Enter the first matrix:" << endl;
        int rows1 = 0;
        int nums1 = 0;
        int cols1;
        getline(cin, input);
        while (numbers.find(input[0]) != -1)
        {
            int nums1 = input.size();
            cols1 = getInts(input, tempNums);
            for(int i = 0; i < nums1; i++)
            {
                matrix1[rows1][i] = tempNums[i];
            }
            rows1++;
            getline(cin, input);
        }
//Second matrix
 	cout<< "Enter the transpose of the second matrix:" << endl;
        input = "0";
        int rows2 = 0;
        int nums2 = 0;
        int cols2;
        getline(cin, input);
        while (numbers.find(input[0]) != -1)
 	{
            int nums2 = input.size();
            cols2 = getInts(input, tempNums);
            for(int i = 0; i < nums2; i++)
            {
                matrix2[rows2][i] = tempNums[i];
            }
            rows2++;
            getline(cin, input);
        }
//Check to make sure matricies are compatible
 if (cols1 == rows2)
        {
            matrixMult(matrix1, matrix2, result, rows1, rows2, cols1, cols2);
        }
        else
 {
            cout << "The two matrices have incompatible dimensions." << endl;
        }
}

